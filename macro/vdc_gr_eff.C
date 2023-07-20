void vdc_gr_eff(){

  Int_t min_clst_size=3;

  
  Double_t eff_vdc_gr_x1=1.0-(Double_t)tree->GetEntries("@vdc_gr_x1.GetEntriesFast()==0")/tree->GetEntries("");
  Double_t eff_vdc_gr_x2=1.0-(Double_t)tree->GetEntries("@vdc_gr_x2.GetEntriesFast()==0")/tree->GetEntries("");
  Double_t eff_vdc_gr_u1=1.0-(Double_t)tree->GetEntries("@vdc_gr_u1.GetEntriesFast()==0")/tree->GetEntries("");
  Double_t eff_vdc_gr_u2=1.0-(Double_t)tree->GetEntries("@vdc_gr_u2.GetEntriesFast()==0")/tree->GetEntries("");

  Double_t eff_vdc_gr_x1_clst=(Double_t)tree->GetEntries(Form("vdc_gr_clust_x1.GetClustnum()>=%d",min_clst_size))/tree->GetEntries("");
  Double_t eff_vdc_gr_x2_clst=(Double_t)tree->GetEntries(Form("vdc_gr_clust_x2.GetClustnum()>=%d",min_clst_size))/tree->GetEntries("");
  Double_t eff_vdc_gr_u1_clst=(Double_t)tree->GetEntries(Form("vdc_gr_clust_u1.GetClustnum()>=%d",min_clst_size))/tree->GetEntries("");
  Double_t eff_vdc_gr_u2_clst=(Double_t)tree->GetEntries(Form("vdc_gr_clust_u2.GetClustnum()>=%d",min_clst_size))/tree->GetEntries("");
  

  
  
  std::cout << "GR VDC efficiency" << std::endl;
  std::cout << "X1 : " <<  eff_vdc_gr_x1 << std::endl;
  std::cout << "X2 : " <<  eff_vdc_gr_x2 << std::endl;
  std::cout << "U1 : " <<  eff_vdc_gr_u1 << std::endl;
  std::cout << "U2 : " <<  eff_vdc_gr_u2 << std::endl;

  std::cout << "X1 clst : " <<  eff_vdc_gr_x1_clst << std::endl;
  std::cout << "X2 clst : " <<  eff_vdc_gr_x2_clst << std::endl;
  std::cout << "U1 clst : " <<  eff_vdc_gr_u1_clst << std::endl;
  std::cout << "U2 clst : " <<  eff_vdc_gr_u2_clst << std::endl;
}
