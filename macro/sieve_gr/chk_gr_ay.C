void chk_gr_ay(Double_t x_min, Double_t x_max){
  gROOT->LoadMacro("macro/yb_gr/setalias.C");
  TCut pid = "abs(pla_gr_vme_1.fCharge-600)<300";
  TCut xcut = Form("abs(vdc_gr_m.fX-%e)<%e",0.5*(x_max+x_min),0.5*abs(x_max-x_min));
  tree->Draw("gr.fYc:vdc_gr_m.fA*1000>>h_ay(400,-100,100,200,-50,50)",pid && xcut,"colz");
}
