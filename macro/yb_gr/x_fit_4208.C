{
  //use 4208

  TCanvas *c1=new TCanvas("c1","c1",800,600);
  
  TH1F *hx= new TH1F("hx","hx",600,-600,600);


  TString fname = "macro/yb_gr/x_4208.dat";
  ofstream ofile((std::string) fname);
  /*header*/
  ofile << "#x fit :  mean, mean err, sigma, sigma err [mm]" << std::endl;
  
  TCut pid_proton="abs(pla_gr_vme_1.fCharge-600)<300";
  TCut acut="abs(vdc_gr_m.fA*1000)<1.0";
  tree->Draw("vdc_gr_m.fX>>hx",pid_proton && acut,"colz");
  
  
  TF1 *f[3];
  //Double_t x_min[4]={-300,-80,-40,240};
  //Double_t x_max[4]={-240,-40,0,255}
  Double_t x_min[3]={-300,-80,240};
  Double_t x_max[3]={-240,-40,255};
  
  for(int i=0;i<3;i++){
    f[i] = new TF1(Form("f[%d]",i),"gaus",-600,600);
    hx->Fit(Form("f[%d]",i),"","",x_min[i],x_max[i]);
    ofile << f[i]->GetParameter(1) << " " << f[i]->GetParError(1) << " " << f[i]->GetParameter(2) << " " << f[i]->GetParError(2) << std::endl;
  }

  ofile.close();
  
  TH1F *h= new TH1F("h","Maylar elastic: GR x_fp",400,-400,400);
  h->SetXTitle("x_{fp} (mm)");
  tree->Draw("vdc_gr_m.fX>>h",pid_proton && acut,"");
  for(int i=0;i<3;i++) f[i]->Draw("same");
  
  c1->SaveAs("figs/output_macro/yb_gr/x_4208.pdf");
  c1->SaveAs("figs/output_macro/yb_gr/x_4208.png");
}
