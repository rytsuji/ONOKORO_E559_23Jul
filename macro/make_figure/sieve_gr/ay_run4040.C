{

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
  TH2F *ht = new TH2F("ht","",200,-60,60,120,-30,30);
  ht->SetXTitle("#theta_{fp} (mrad)");
  ht->SetYTitle("y_{fp} (mm)");

  ht->SetTitleOffset(1.5,"xy");
  ht->SetTitleSize(0.04,"xy");
  ht->SetLabelOffset(0.02,"xy");
  ht->SetLabelSize(0.04,"xy");
  
  //Plot
  TCut pid_proton="abs(pla_gr_vme_1.fCharge-600)<300";
  TCut xcut="abs(vdc_gr_m.fX)<150";
  //tree->Draw("vdc_gr_m.fY:vdc_gr_m.fA*1000>>ht",pid_proton && xcut,"colz");
  tree->Draw("vdc_gr_m.fY:vdc_gr_m.fA*1000>>ht",pid_proton && xcut,"colz");


  c1->SaveAs("figs/output_macro/sieve_gr/ay_run4040.pdf");
  c1->SaveAs("figs/output_macro/sieve_gr/ay_run4040.png");

}



  
