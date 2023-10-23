class prm{
public:
  Double_t delta;

  Double_t a_min;
  Double_t a_max;
  Double_t x_min;
  Double_t x_max;

  Double_t y_min;
  Double_t y_max;
  Double_t y_height;
  Double_t y_sigma;
  std::vector<Double_t> y;
  std::vector<int> ID;

};

prm read_conf(TString conf);

void fit(TString conf){

  /* load macro */
  gROOT->LoadMacro("macro/yb_gr/setalias.C");
  
  /* input prm */
  prm par = read_conf(conf);
  
  Double_t x_min = par.x_min;
  Double_t x_max = par.x_max;
  Double_t a_min = par.a_min;
  Double_t a_max = par.a_max;
  Double_t y_min = -50.0;
  Double_t y_max = 50.0;
  Double_t b_min = -50.0;
  Double_t b_max = 50.0;

  int n_y =par.y.size();
  
  /* output && variable */
  TString  fname ="macro/sieve_gr/dat/"+conf+".dat";
  TString  dir_figs="figs/output_macro/sieve_gr/fit/"+conf;
  ofstream ofile((std::string) fname);

  Double_t x_fp[5];
  Double_t x_fp_err[5];
  Double_t a_fp[5];
  Double_t a_fp_err[5];
  Double_t y_fp[5];
  Double_t y_fp_err[5];
  Double_t b_fp[5];
  Double_t b_fp_err[5];

  Double_t x_fp_sigma[5];
  Double_t a_fp_sigma[5];
  Double_t y_fp_sigma[5];
  Double_t b_fp_sigma[5];

  Double_t theta[5];
  Double_t phi[5];
  
  Double_t dtheta=7.55;
  Double_t dphi=20.13;

  
  // func def //
  TF1 *f0 = new TF1("f0","([0]/sqrt(2.*TMath::Pi()*[2]*[2]))*exp(-0.5*pow((x-[1])/[2],2))",-50,50);
  TF1 *f1 = new TF1("f1","([0]/sqrt(2.*TMath::Pi()*[2]*[2]))*exp(-0.5*pow((x-[1])/[2],2))",-50,50);
  TF1 *f2 = new TF1("f2","([0]/sqrt(2.*TMath::Pi()*[2]*[2]))*exp(-0.5*pow((x-[1])/[2],2))",-50,50);
  TF1 *f3 = new TF1("f3","([0]/sqrt(2.*TMath::Pi()*[2]*[2]))*exp(-0.5*pow((x-[1])/[2],2))",-50,50);
  TF1 *f4 = new TF1("f4","([0]/sqrt(2.*TMath::Pi()*[2]*[2]))*exp(-0.5*pow((x-[1])/[2],2))",-50,50);

  TF1 *g1= new TF1("g1","gaus+[3]",-600,600);
  
  TF1 *g[5];
  g[0]= new TF1("g[0]","f0+[3]+[4]*x+[5]*x*x",-50,50);
  g[1]= new TF1("g[1]","f0+f1+[6]+[7]*x+[8]*x*x",-50,50);
  g[2]= new TF1("g[2]","f0+f1+f2+[9]+[10]*x+[11]*x*x",-50,50);
  g[3]= new TF1("g[3]","f0+f1+f2+f3+[12]+[13]*x+[14]*x*x",-50,50);
  g[4]= new TF1("g[4]","f0+f1+f2+f3+f4+[15]+[16]*x+[17]*x*x",-50,50);

  // def canvas //
  TCanvas *c1=new TCanvas("c1","c1",800,600);
  
  TCanvas *c2=new TCanvas("c2","c2",1200,800);
  TCanvas *c3=new TCanvas("c3","c3",1200,800);
  TCanvas *c4=new TCanvas("c4","c4",1200,800);
  c2->Divide(2,3);
  c3->Divide(2,3);
  c4->Divide(2,3);  
  
    
  // hist def //
  Int_t x_bin=(Int_t) abs(x_max-x_min)/2;
  Int_t a_bin=(Int_t) 2*abs(a_max-a_min);
  Int_t b_bin=(Int_t) 2*abs(b_max-b_min);
  
  TH1F *hx[5];
  TH1F *ha[5];
  TH1F *hy;
  TH1F *hb[5];
  for(int i=0;i<5;i++){
    hx[i]=new TH1F(Form("hx[%d]",i),"hx",x_bin,x_min,x_max);
    ha[i]=new TH1F(Form("ha[%d]",i),"ha",a_bin,a_min,a_max);
    hb[i]=new TH1F(Form("hb[%d]",i),"hb",200,-100,100);
  } 
  hy=new TH1F("hy","hy",200,-50,50);
  
  //  cut def //
  TCut acut = Form("abs(vdc_gr_m.fA*1000-%e)<%e",0.5*(a_max+a_min),0.5*abs(a_max-a_min));
  TCut xcut = Form("abs(vdc_gr_m.fX-%e)<%e",0.5*(x_max+x_min),0.5*abs(x_max-x_min));
  TCut pid_proton = "abs(pla_gr_vme_1.fCharge-600)<300";
  
  // y fitting //
  std::cout << "---------------- y fitting ---------------" << std::endl; 
  c1->cd();
  gStyle->SetStatH(0.05);
  gStyle->SetStatW(0.15);
  gStyle->SetOptFit(1100);

  tree->Draw("gr.fYc>>hy",pid_proton && xcut && acut,"");
  for(int i=0; i<n_y; i++){
    g[n_y-1]->SetParameter(3*i,par.y_height);
    g[n_y-1]->SetParameter(3*i+1,par.y[i]);
    g[n_y-1]->SetParameter(3*i+2,par.y_sigma);
    g[n_y-1]->SetParLimits(3*i+2,0.0,10.0);
  }
  g[n_y-1]->SetParameter(3*n_y+0,0.0);
  g[n_y-1]->SetParameter(3*n_y+1,0.0);
  g[n_y-1]->SetParameter(3*n_y+2,0.0);
  
  hy->Fit(Form("g[%d]",n_y-1),"","",par.y_min,par.y_max);
  
  for(int i=0; i<n_y; i++){
    y_fp[i] = g[n_y-1]->GetParameter(3*i+1);
    y_fp_err[i]= g[n_y-1]->GetParError(3*i+1);
    y_fp_sigma[i]= g[n_y-1]->GetParameter(3*i+2);
  }
  
  // x_fitting //
  std::cout << "---------------- x fitting ---------------" << std::endl; 
  c2->cd();
  
  for(int i=0; i<n_y; i++){
    c2->cd(i+1);
    
    TCut ycut = Form("abs(gr.fYc-%e)<%e",y_fp[i],1.0*y_fp_sigma[i]);
    tree->Draw(Form("vdc_gr_m.fX>>hx[%d]",i),pid_proton && acut && ycut,"");
    
    Double_t x_mean=hx[i]->GetXaxis()->GetBinCenter((hx[i]->GetMaximumBin())); 
    Double_t x_height= hx[i]->GetBinContent(hx[i]->GetMaximumBin());
    g1->SetParameters(x_height,x_mean,10.0,0.0);
    
    hx[i]->Fit("g1","","",x_mean-20.0,x_mean+20.0);
    
    x_fp[i] = g1->GetParameter(1);
    x_fp_err[i] = g1->GetParError(1);
    x_fp_sigma[i] = g1->GetParameter(2);
  }

  // a fitting //
  std::cout << "---------------- a fitting ---------------" << std::endl; 
  c3->cd();
  
  for(int i=0; i<n_y; i++){
    c3->cd(i+1);
    
    TCut ycut = Form("abs(gr.fYc-%e)<%e",y_fp[i],1.0*y_fp_sigma[i]);
    TCut cut=Form("abs(vdc_gr_m.fX-%e)<%e",x_fp[i],1.0*x_fp_sigma[i]);
    
    tree->Draw(Form("vdc_gr_m.fA*1000>>ha[%d]",i),pid_proton && cut && ycut,"");
    Double_t a_mean=ha[i]->GetXaxis()->GetBinCenter((ha[i]->GetMaximumBin())); 
    Double_t a_height= ha[i]->GetBinContent(ha[i]->GetMaximumBin());
    g1->SetParameters(a_height,a_mean,5.,0.);
    
    ha[i]->Fit("g1","","",a_mean-5.0,a_mean+5.0);
    
    a_fp[i] = g1->GetParameter(1);
    a_fp_err[i] = g1->GetParError(1);
    a_fp_sigma[i] = g1->GetParameter(2);
  }
  
  // b fitting //
  std::cout << "---------------- b fitting ---------------" << std::endl; 
  c4->cd();
  
  for(int i=0; i<n_y; i++){
    c4->cd(i+1);
    TCut ycut = Form("abs(gr.fYc-%e)<%e",y_fp[i],1.0*y_fp_sigma[i]);
    TCut cut=Form("abs(vdc_gr_m.fX-%e)<%e && abs(vdc_gr_m.fA*1000-%e)<%e",x_fp[i],3.0*x_fp_sigma[i],a_fp[i],3.0*a_fp_sigma[i]);

    tree->Draw(Form("vdc_gr_m.fB*1000>>hb[%d]",i),pid_proton && cut && ycut,"");
    Double_t b_mean=hb[i]->GetXaxis()->GetBinCenter((hb[i]->GetMaximumBin())); 
    Double_t b_height= hb[i]->GetBinContent(hb[i]->GetMaximumBin());
    g1->SetParameters(b_height,b_mean,5.,0.);
    
    hb[i]->Fit("g1","","",b_mean-5.0,b_mean+5.0);
    
    b_fp[i] = g1->GetParameter(1);
    b_fp_err[i] = g1->GetParError(1);
    b_fp_sigma[i] = g1->GetParameter(2);

  }

  //  theta and phi //
  for(int i=0;i<n_y;i++){
    theta[i] = (Double_t) -1.0*dtheta*( ( (int) (par.ID[i]/5) )-2 );
    phi[i] = (Double_t) dphi*( ( (int) par.ID[i]%5) - 3 );
  }
  
  
  
  
  for(int i=0;i<n_y;i++){
    ofile << par.ID[i] << " " << par.delta/100.0 << " " << theta[i] << " " <<  phi[i] << " ";
    ofile << x_fp[i] << " " << x_fp_err[i] << " ";
    ofile << a_fp[i] << " " << a_fp_err[i] << " ";
    ofile << y_fp[i] << " " << y_fp_err[i] << " ";
    ofile << b_fp[i] << " " << b_fp_err[i] << " ";
    ofile << std::endl;
  }

  ofile.close();

}

prm read_conf(TString conf){

  prm par;

  TString  cfgname ="macro/sieve_gr/conf/"+conf+".conf";

  std::ifstream infile((std::string) cfgname);
  std::string iline;
  getline(infile,iline); //skip header                                                                                                                       
  getline(infile,iline);
  std::istringstream iss(iline);
  std::string str[5];
  iss >> str[0] >> str[1] >> str[2] >> str[3] >> str[4];

  par.delta = std::stod(str[0]);
  par.x_min = std::stod(str[1]);
  par.x_max = std::stod(str[2]);
  par.a_min = std::stod(str[3]);
  par.a_max = std::stod(str[4]);

  getline(infile,iline); //skip header
  getline(infile,iline);
  stringstream ss(iline);
  std::string str_y;
  std::vector <Double_t> val;
  while(getline(ss, str_y, ' ')){
    val.push_back(std::stod(str_y));
  }

  par.y_min=val[0];
  par.y_max=val[1];
  par.y_height=val[2];
  par.y_sigma=val[3];

  for(int i=0;i<val.size()-4;i++){
    par.y.push_back(val[i+4]);
  }

  
  ss.str(""); //clear buff
  ss.clear(stringstream::goodbit); //clear buff
  getline(infile,iline); //skip header
  getline(infile,iline);
  ss.str(iline);
  std::string str_id;
  while(getline(ss, str_id, ' ')){
    par.ID.push_back(std::stoi(str_id));
  }
  
  return par;
}

