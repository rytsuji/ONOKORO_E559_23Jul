{
  gROOT->ProcessLine(".x macro/gr_calib.C");
  
  TF1 *f0 = new TF1("f0","([0]/sqrt(2.*TMath::Pi()*[2]*[2]))*exp(-0.5*pow((x-[1])/[2],2))",-50,50);
  TF1 *f1 = new TF1("f1","([0]/sqrt(2.*TMath::Pi()*[2]*[2]))*exp(-0.5*pow((x-[1])/[2],2))",-50,50);
  TF1 *f2 = new TF1("f2","([0]/sqrt(2.*TMath::Pi()*[2]*[2]))*exp(-0.5*pow((x-[1])/[2],2))",-50,50);
  TF1 *f3 = new TF1("f3","([0]/sqrt(2.*TMath::Pi()*[2]*[2]))*exp(-0.5*pow((x-[1])/[2],2))",-50,50);
  TF1 *f4 = new TF1("f4","([0]/sqrt(2.*TMath::Pi()*[2]*[2]))*exp(-0.5*pow((x-[1])/[2],2))",-50,50);
  TF1 *g5 = new TF1("g5","f0+f1+f2+f3+f4+[15]+[16]*x+[17]*x*x",-50,50);

  //TCut cut="abs(vdc_gr_m.fX)<150 && abs(vdc_gr_m.fY-5)<25";
  //TCut phicut="abs(phi_gr/1000*TMath::RadToDeg())<0.5";
  TCut phicut="abs(phi_gr)<1.5";

  //tree->Draw("phi_gr/1000*TMath::RadToDeg()>>h_phi(800,-4,4)",cut,"");
  TH1F *h_theta=new TH1F("h_theta","theta GR (deg)",800,-4,4);
  tree->Draw("theta_gr>>h_theta",phicut,"");
  Double_t dtheta=7.55/1000*TMath::RadToDeg();
  Double_t thc[5]={-2.0*dtheta,-1.0*dtheta,0.0,1.0*dtheta,2.0*dtheta};
  Double_t thh[5]={2000.,2000.,2000.,2000.,2000.}; 
  Double_t thsigma=0.1;
  
  for(int i=0;i<5;i++){
    g5->SetParameter(3*i,thh[i]);
    g5->SetParameter(3*i+1,thc[i]);
    g5->SetParameter(3*i+2,thsigma);
  }

  g5->SetParameter(15,0);
  g5->SetParameter(16,0);
  g5->SetParameter(17,0);


  h_theta->Fit("g5","","",-2,2);

  for(int i=0;i<5;i++){
    std::cout << "peak: " << g5->GetParameter(3*i+1) << "  eroor: " << g5->GetParameter(3*i+1)-(7.55/1000*TMath::RadToDeg()*((double)i-2.0)) << std::endl;;
  }
  
}
