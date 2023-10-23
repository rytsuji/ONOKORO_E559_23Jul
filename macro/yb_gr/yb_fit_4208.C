{
  //use run4208

  TString fname= "macro/yb_gr/yb_4208.dat";
  ofstream ofile((std::string) fname);
  
  TString filename="macro/yb_gr/x_4208.dat";
  std::ifstream ifile((std::string) filename);
  std::string iline;
  getline(ifile,iline); //skip the first line
  
  TCanvas *c1=new TCanvas("c1","c1",800,800);
  TCanvas *c2=new TCanvas("c2","c2",800,800);
  TCanvas *c3=new TCanvas("c3","c3",800,800);
  c1->Divide(2,2);
  c2->Divide(2,2);
  c3->Divide(2,2);
  TH2F *h[4];
  TH2F *hc[4];
  
  int i=0;
  while(getline(ifile,iline)){
    std::istringstream line(iline);
    std::string str[4];
    
    line >> str[0] >> str[1] >> str[2] >> str[3];

    Double_t mean=std::stod(str[0]);
    Double_t mean_err=std::stod(str[1]);
    Double_t sigma=std::stod(str[2]);

    TCut pid_p="abs(pla_gr_vme_1.fCharge-600)<300";
    TCut acut="abs(vdc_gr_m.fA*1000)<1.0";
    TCut xcut=Form("abs(vdc_gr_m.fX-%e)<%e",mean,1.0*sigma);

    c1->cd();
    c1->cd(i+1);
    gPad->SetLeftMargin(0.15);
    h[i]=new TH2F(Form("h[%d]",i),Form("Ca(p,p) GR Y vs B @X=%e (mm), |fA|< 1.0 (mrad)",mean),200,-50,50,200,-50,50);
    hc[i]=new TH2F(Form("hc[%d]",i),"hist",200,-50,50,200,-50,50);

    
    h[i]->SetXTitle("Y_{fp} (mm)");
    h[i]->SetYTitle("#phi_{fp} (mrad)");
    h[i]->SetLabelOffset(0.01,"y");

    tree->Draw(Form("vdc_gr_m.fB*1000:vdc_gr_m.fY>>h[%d]",i),pid_p && xcut && acut,"colz");
    
    TF1 *f =new TF1("f","pol1",-30,25);
    h[i]->Fit("f","","",-2,20);
    Double_t p0=f->GetParameter(0);
    Double_t p1=f->GetParameter(1);
    
    TCut center = Form("abs(vdc_gr_m.fB*1000-%e*vdc_gr_m.fY-%e)<10",p1,p0);

    c2->cd();
    c2->cd(i+1);
    
    tree->Draw(Form("vdc_gr_m.fB*1000:vdc_gr_m.fY>>hc[%d]",i),pid_p && xcut && acut && center,"colz");
    hc[i]->Fit("f","","",-2,20);
    
    ofile << mean << " " << mean_err << " " << -1/p1 << " " << f->GetParError(1)/(p1*p1) << " " <<  f->GetParError(0)/p1 << " " << std::endl;


    c3->cd();
    c3->cd(i+1);    
    gPad->SetLeftMargin(0.15);

    gStyle->SetOptStat(0);
    gStyle->SetOptFit(1);
    h[i]->Draw("colz");
    f->Draw("same");
     
    i++;
    
  }
  c3->SaveAs("figs/output_macro/yb_gr/yb_fit_4208.pdf");
  c3->SaveAs("figs/output_macro/yb_gr/yb_fit_4208.png");
  ofile.close();
}
