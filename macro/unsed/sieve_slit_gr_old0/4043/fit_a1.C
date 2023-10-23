void fit_a1(int i_a=1){
  
  /*----------file io------------*/
  TString run="4043";
  TString A=Form("a%d",i_a);
  TString  dir ="/home/tsuji/work/art_analysis/e559_23jul/macro/sieve_slit_gr/" + run + "/" + A + "/";
  
  TString cfgname= dir + "cfg.dat";
  std::ifstream infile((std::string) cfgname);
  std::string iline;
  getline(infile,iline);
  std::istringstream line(iline);
  std::string str[4];
  line >> str[0] >> str[1] >> str[2] >> str[3];
  Double_t x_min = std::stod(str[0]);
  Double_t x_max = std::stod(str[1]);
  Double_t acut_min= std::stod(str[2]);
  Double_t acut_max = std::stod(str[3]);

  
  TString oname= dir + "fit_" + A + ".dat"; 
  ofstream ofile((std::string) oname);
  Double_t y_fp[5];
  Double_t y_fp_e[5];
  Double_t x_fp[5];
  Double_t x_fp_e[5];
  Double_t a_fp[5];
  Double_t a_fp_e[5];

  

  Double_t dtheta=7.55;
  Double_t dphi=20.13;
  

  
  Double_t a_min=-100;
  Double_t a_max=100;
  
  

  Int_t x_bin=(Int_t) abs(x_max-x_min);
  Int_t a_bin=(Int_t) abs(a_max-a_min);
  
  TCut acut=Form("abs(vdc_gr_m.fA*1000-%e)<%e",(acut_min+acut_max)/2.,abs(acut_max-acut_min)/2.);


  TF1 *g1=new TF1("g1","gaus+[3]",-1000,1000);
  
  //x fitting
  TCanvas *c1=new TCanvas("c1","c1",512,512);
  c1->cd();
  TH1F *hX=new TH1F("hX","hX",x_bin,x_min,x_max);
  tree->Draw("vdc_gr_m.fX>>hX",acut,"");
  Double_t xc=hX->GetXaxis()->GetBinCenter((hX->GetMaximumBin()));
  Double_t xh= hX->GetBinContent(hX->GetMaximumBin());
  g1->SetParameters(xh,xc,10,0);
  hX->Fit("g1","","",xc-50,xc+50);

  // a fitting
  xc=g1->GetParameter(1);
  Double_t xsigma=g1->GetParameter(2);
  TCut xcut=Form("abs(vdc_gr_m.fX-%e)<%e",xc,3*xsigma);  
  TCanvas *c2=new TCanvas("c2","c2",512,512);
  c2->cd();
  TH1F *hA=new TH1F("hA","hA",a_bin,a_min,a_max);
  tree->Draw("vdc_gr_m.fA*1000>>hA",xcut,"");
  Double_t ac=hA->GetXaxis()->GetBinCenter((hA->GetMaximumBin()));
  Double_t ah= hA->GetBinContent(hA->GetMaximumBin());
  g1->SetParameters(ah,ac,10,0);
  hA->Fit("g1","","",ac-10,ac+10);
  
  //y fitting
  TF1 *f0 = new TF1("f0","([0]/sqrt(2.*TMath::Pi()*[2]*[2]))*exp(-0.5*pow((x-[1])/[2],2))",-50,50);
  TF1 *f1 = new TF1("f1","([0]/sqrt(2.*TMath::Pi()*[2]*[2]))*exp(-0.5*pow((x-[1])/[2],2))",-50,50);
  TF1 *f2 = new TF1("f2","([0]/sqrt(2.*TMath::Pi()*[2]*[2]))*exp(-0.5*pow((x-[1])/[2],2))",-50,50);
  TF1 *f3 = new TF1("f3","([0]/sqrt(2.*TMath::Pi()*[2]*[2]))*exp(-0.5*pow((x-[1])/[2],2))",-50,50);
  TF1 *g4 = new TF1("g4","f0+f1+f2+f3+[12]+[13]*x+[14]*x*x",-50,50);


  Double_t ysigma=2.0;
  //Double_t yc[5]={-10, -2.5, 5.0, 10, 15}; //for 4040 a5
  Double_t yc[4]={-8.1, 0.5, 9.0, 16.29}; //for 4040 a1-a4
  Double_t yh[4]={1000.,1000.,2500., 1000.};

  
  for(int i=0;i<4;i++){
    g4->SetParameter(3*i,yh[i]);
    g4->SetParameter(3*i+1,yc[i]);
    g4->SetParameter(3*i+2,ysigma);
    
  }
  
  g4->SetParameter(15,0);
  g4->SetParameter(16,0);
  g4->SetParameter(17,0);
  
  TCanvas *c3=new TCanvas("c3","c3",512,512);
  c3->cd();
  //gStyle->SetStatH(3);
  TH1F *hy=new TH1F("hy","hy",600,-50,100);
  tree->Draw("vdc_gr_m.fY>>hy",acut && xcut,"");  
  hy->Fit("g4","","",-15,30);

  
  TCanvas *c4=new TCanvas("c4","c4",1200,800);
  TCanvas *c5=new TCanvas("c5","c5",1200,800);
  c4->Divide(2,3);
  c5->Divide(2,3);


  TH1F *hx[4];
  TH1F *ha[4];
  
  for(int i=0;i<4;i++){
    c4->cd();
    c4->cd(i+1);
    Double_t yc = g4->GetParameter(3*i+1);
    Double_t y_sigma  = g4->GetParameter(3*i+2);

    y_fp[i]=yc;
    y_fp_e[i]= g4->GetParError(3*i+1);

    hx[i]=new TH1F(Form("hx[%d]",i),Form("hx[%d]",i),x_bin,x_min,x_max);
    tree->Draw(Form("vdc_gr_m.fX>>hx[%d]",i),Form("abs(vdc_gr_m.fY-%e)<%e",yc,2*y_sigma) && acut,"");
    xc=hx[i]->GetXaxis()->GetBinCenter((hx[i]->GetMaximumBin())); 
    xh= hx[i]->GetBinContent(hx[i]->GetMaximumBin());
    g1->SetParameters(xh,xc,10.,0.);
    hx[i]->Fit("g1","","",xc-20,xc+20);
    x_fp[i] = g1->GetParameter(1);
    x_fp_e[i] = g1->GetParError(1);
    
    
    c5->cd();
    c5->cd(i+1);
    ha[i]=new TH1F(Form("ha[%d]",i),Form("ha[%d]",i),a_bin,a_min,a_max);
    tree->Draw(Form("vdc_gr_m.fA*1000>>ha[%d]",i),Form("abs(vdc_gr_m.fY-%e)<%e",yc,y_sigma) && xcut,"");
    ac=ha[i]->GetXaxis()->GetBinCenter((ha[i]->GetMaximumBin())); 
    ah= ha[i]->GetBinContent(ha[i]->GetMaximumBin());
    g1->SetParameters(ah,ac,5.,0.);
    ha[i]->Fit("g1","","",ac-5,ac+5);
    a_fp[i] = g1->GetParameter(1);
    a_fp_e[i] = g1->GetParError(1);
  }

  c1->cd();
  gStyle->SetStatFontSize(0.04);
  c1->SaveAs(dir+"x0.png");
  c2->cd();
  gStyle->SetStatFontSize(0.04);
  c2->SaveAs(dir+"a0.png");
  c3->cd();
  gStyle->SetStatFontSize(0.02);
  c3->SaveAs(dir+"Y.png");
  c4->cd();
  gStyle->SetStatFontSize(0.04);
  c4->SaveAs(dir+"X.png");
  c5->cd();
  gStyle->SetStatFontSize(0.04);
  c5->SaveAs(dir+"A.png");

  for(int i=0;i<4;i++){
    ofile << dtheta*((double) -i_a+3) << " " << dphi*((double)i-2)<< " " << x_fp[i] << " " << x_fp_e[i] << " " << a_fp[i] << " " << a_fp_e[i] << " " << y_fp[i] << " " << y_fp_e[i] << endl;
  }

  ofile.close();
  
}

