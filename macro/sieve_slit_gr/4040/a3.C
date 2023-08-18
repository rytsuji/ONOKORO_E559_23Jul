{



  
  TString  dir ="/home/tsuji/work/art_analysis/e559_23jul/macro/sieve_slit_gr/4040/result/a3/";  

  Double_t a_min=-3.;
  Double_t a_max=15.;
  
  Double_t x_min=-3.;
  Double_t x_max=15.;
  
  TCut acut=Form("abs(vdc_gr_m.fA*1000-%e)<%e",(a_min+a_max)/2.,abs(a_max-a_min)/2.);


  //x fitting
  tree->Draw("vdc_gr_m.fX>>hx3(400,-200,200)",acut,"");
  TF1 *g1=new TF1("g1","gaus+[3]+[4]*x",-1000,1000);
  Double_t xc=hx3->GetXaxis()->GetBinCenter((hx3->GetMaximumBin()));
  Double_t x_bc_max= hx3->GetBinContent(hx3->GetMaximumBin());
  g1->SetParameters(x_bc_max,xc,10,0);
  TCanvas *c1=new TCanvas("c1","c1",512,512);
  c1->cd();
  hx3->Fit("g1","","",xc-50,xc+50);
  

  // a fitting
  xc=g1->GetParameter(1);
  Double_t xsigma=g1->GetParameter(2);
  TCut xcut=Form("abs(vdc_gr_m.fX-%e)<%e",xc,3*xsigma);  

  TCanvas *c2=new TCanvas("c2","c2",512,512);
  c2->cd();
  tree->Draw("vdc_gr_m.fA*1000>>ha3(200,-100,100)",xcut,"");
  Double_t ac=ha3->GetXaxis()->GetBinCenter((ha3->GetMaximumBin()));
  Double_t a_bc_max= ha3->GetBinContent(hx3->GetMaximumBin());
  g1->SetParameters(a_bc_max,ac,10,0);
  ha3->Fit("g1","","",ac-10,ac+10);
  //y fitting
  TF1 *f0 = new TF1("f0","([0]/sqrt(2.*TMath::Pi()*[2]*[2]))*exp(-0.5*pow((x-[1])/[2],2))",-50,50);
  TF1 *f1 = new TF1("f1","([0]/sqrt(2.*TMath::Pi()*[2]*[2]))*exp(-0.5*pow((x-[1])/[2],2))",-50,50);
  TF1 *f2 = new TF1("f2","([0]/sqrt(2.*TMath::Pi()*[2]*[2]))*exp(-0.5*pow((x-[1])/[2],2))",-50,50);
  TF1 *f3 = new TF1("f3","([0]/sqrt(2.*TMath::Pi()*[2]*[2]))*exp(-0.5*pow((x-[1])/[2],2))",-50,50);
  TF1 *f4 = new TF1("f4","([0]/sqrt(2.*TMath::Pi()*[2]*[2]))*exp(-0.5*pow((x-[1])/[2],2))",-50,50);
  TF1 *g5 = new TF1("g5","f0+f1+f2+f3+f4+[15]+[16]*x+[17]*x*x",-50,50);


  Double_t ysigma=2.0;
  Double_t yc[5]={-7.5, -2.5, 5.0, 12.5, 17.5};
  Double_t yh[5]={1000.,1000.,2500., 1000.,1000.};
  
  for(int i=0;i<5;i++){
    g5->SetParameter(3*i,yh[i]);
    g5->SetParameter(3*i+1,yc[i]);
    g5->SetParameter(3*i+2,ysigma);
    
  }
  
  g5->SetParameter(15,0);
  g5->SetParameter(16,0);
  g5->SetParameter(17,0);
  
  TCanvas *c3=new TCanvas("c3","c3",512,512);
  c3->cd();
  //gStyle->SetStatH(3);
  tree->Draw("vdc_gr_m.fY>>hy(300,-50,100)",acut && xcut,"");  
  hy->Fit("g5","","",-15,30);

  
  TCanvas *c4=new TCanvas("c4","c4",1200,800);
  TCanvas *c5=new TCanvas("c5","c5",1200,800);
  c4->Divide(2,3);
  c5->Divide(2,3);


  TH1F *hX[5];
  TH1F *hA[5];
  
  for(int i=0;i<5;i++){
    c4->cd();
    c4->cd(i+1);
    Double_t y_center = g5->GetParameter(3*i+1);
    Double_t y_sigma  = g5->GetParameter(3*i+2);    
    hX[i]=new TH1F(Form("hX[%d]",i),Form("hX[%d]",i),200,-200,200);
    tree->Draw(Form("vdc_gr_m.fX>>hX[%d]",i),Form("abs(vdc_gr_m.fY-%e)<%e",y_center,2*y_sigma) && acut,"");
    xc=hX[i]->GetXaxis()->GetBinCenter((hX[i]->GetMaximumBin())); 
    x_bc_max= hX[i]->GetBinContent(hX[i]->GetMaximumBin());
    g1->SetParameters(x_bc_max,xc,10.,0.,0.);
    hX[i]->Fit("g1","","",xc-20,xc+20);

    c5->cd();
    c5->cd(i+1);
    hA[i]=new TH1F(Form("hA[%d]",i),Form("hA[%d]",i),200,-100,100);
    tree->Draw(Form("vdc_gr_m.fA*1000>>hA[%d]",i),Form("abs(vdc_gr_m.fY-%e)<%e",y_center,y_sigma) && xcut,"");
    ac=hA[i]->GetXaxis()->GetBinCenter((hA[i]->GetMaximumBin())); 
    a_bc_max= hA[i]->GetBinContent(hA[i]->GetMaximumBin());
    g1->SetParameters(a_bc_max,ac,10.,0.,0.);
    hA[i]->Fit("g1","","",ac-5,ac+5);
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


  
}

