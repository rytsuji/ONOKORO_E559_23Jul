{
  
  TCut cut ="abs(pla_gr_vme_1.fCharge-600)<300 && abs(vdc_gr_m.fA*1000)<0.5 && abs(phi_gr)<1";
  
  tree->SetAlias("delta","-vdc_gr_m.fX/(sqrt(2)*15451)");
  
}
