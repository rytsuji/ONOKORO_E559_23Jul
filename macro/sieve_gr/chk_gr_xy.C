{
  gROOT->LoadMacro("macro/yb_gr/setalias.C");
  TCut pid="abs(pla_gr_vme_1.fCharge-600)<300";
  tree->Draw("gr.fYc:vdc_gr_m.fX>>h_xy(1200,-600,600,200,-50,50)",pid,"colz");
}
