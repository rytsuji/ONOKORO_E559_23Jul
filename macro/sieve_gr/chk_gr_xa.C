{
  gROOT->LoadMacro("macro/yb_gr/setalias.C");
  TCut pid = "abs(pla_gr_vme_1.fCharge-600)<300";
 
  tree->Draw("vdc_gr_m.fA*1000:vdc_gr_m.fX>>h_ay(1200,-600,600,400,-100,100)",pid,"colz");
}
