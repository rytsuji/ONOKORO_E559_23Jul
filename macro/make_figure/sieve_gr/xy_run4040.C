{
  //Set Alias
  gROOT->LoadMacro("macro/yb_gr/setalias.C");

  //Make Canvas
  TCanvas *c1 = new TCanvas("c1", "c1",800,600);

  Int_t fontid=132;
  Int_t italic=12; 
  gStyle->SetStatFont(fontid); 
  gStyle->SetLabelFont(fontid,"XYZ"); 
  gStyle->SetLabelFont(fontid,""); 
  gStyle->SetTitleFont(fontid,"XYZ"); 
  gStyle->SetTitleFont(fontid,""); 
  gStyle->SetTextFont(fontid); 
  gStyle->SetLegendFont(fontid);

  gStyle->SetOptStat(0);

  c1->cd();
  gPad->SetBottomMargin(0.15);
  gPad->SetLeftMargin(0.15);
  gPad->SetRightMargin(0.15);

  //Set logz
  //gPad->SetLogz(1);

  //Def Histgram
  TH2F *h_xy = new TH2F("h_xy","",200,-200,200,120,-30,30);
  h_xy->SetXTitle("x_{fp} (mm)");
  h_xy->SetYTitle("y_{fp}^{corrected} (mm)");

  h_xy->SetTitleOffset(1.5,"xy");
  h_xy->SetTitleSize(0.04,"xy");
  h_xy->SetLabelOffset(0.02,"xy");
  h_xy->SetLabelSize(0.04,"xy");
  
  //Plot
  TCut pid_proton="abs(pla_gr_vme_1.fCharge-600)<300";
  //tree->Draw("vdc_gr_m.fY:vdc_gr_m.fX>>h_xy",pid_proton,"colz");
  tree->Draw("gr.fYc:vdc_gr_m.fX>>h_xy",pid_proton,"colz");


  c1->SaveAs("figs/output_macro/sieve_gr/xy_run4040.pdf");
  c1->SaveAs("figs/output_macro/sieve_gr/xy_run4040.png");

}



  
