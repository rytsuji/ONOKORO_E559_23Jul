void vdc_las_eff(Double_t qmin, Double_t qmax, Double_t tmin, Double_t tmax){


  Double_t tmin_vdc=-1590;
  Double_t tmax_vdc=-1300;
  tree->SetAlias("tof_las",Form("fmod(tref_las.fTiming-rf1.fTiming,71.0)"));
  TCut pid=Form("pla_las_vme_3.fCharge > %e &&  pla_las_vme_3.fCharge < %e && tof_las > %e  && tof_las <%e && @pla_las_vme_5.GetEntriesFast()==0",qmin,qmax,tmin,tmax);
  
  
  Double_t eff_vdc_las_x1=(Double_t)tree->GetEntries(Form("vdc_las_x1.fTiming>%e && vdc_las_x1.fTiming<%e",tmin_vdc,tmax_vdc) && pid)/tree->GetEntries(pid);
  Double_t eff_vdc_las_x2=(Double_t)tree->GetEntries(Form("vdc_las_x2.fTiming>%e && vdc_las_x2.fTiming<%e",tmin_vdc,tmax_vdc) && pid)/tree->GetEntries(pid);
  Double_t eff_vdc_las_u1=(Double_t)tree->GetEntries(Form("vdc_las_u1.fTiming>%e && vdc_las_u2.fTiming<%e",tmin_vdc,tmax_vdc) && pid)/tree->GetEntries(pid);
  Double_t eff_vdc_las_u2=(Double_t)tree->GetEntries(Form("vdc_las_u2.fTiming>%e && vdc_las_u2.fTiming<%e",tmin_vdc,tmax_vdc) && pid)/tree->GetEntries(pid);
  Double_t eff_vdc_las_v1=(Double_t)tree->GetEntries(Form("vdc_las_v1.fTiming>%e && vdc_las_v1.fTiming<%e",tmin_vdc,tmax_vdc) && pid)/tree->GetEntries(pid);
  Double_t eff_vdc_las_v2=(Double_t)tree->GetEntries(Form("vdc_las_v2.fTiming>%e && vdc_las_v2.fTiming<%e",tmin_vdc,tmax_vdc) && pid)/tree->GetEntries(pid);
  
  Double_t eff_vdc_las_x1_clst=(Double_t)tree->GetEntries("vdc_las_clust_x1.GetClustnum()>=3" && pid)/tree->GetEntries(pid);
  Double_t eff_vdc_las_x2_clst=(Double_t)tree->GetEntries("vdc_las_clust_x2.GetClustnum()>=3" && pid)/tree->GetEntries(pid);
  Double_t eff_vdc_las_u1_clst=(Double_t)tree->GetEntries("vdc_las_clust_u1.GetClustnum()>=3" && pid)/tree->GetEntries(pid);
  Double_t eff_vdc_las_u2_clst=(Double_t)tree->GetEntries("vdc_las_clust_u2.GetClustnum()>=3" && pid)/tree->GetEntries(pid);
  Double_t eff_vdc_las_v1_clst=(Double_t)tree->GetEntries("vdc_las_clust_v1.GetClustnum()>=3" && pid)/tree->GetEntries(pid);
  Double_t eff_vdc_las_v2_clst=(Double_t)tree->GetEntries("vdc_las_clust_v2.GetClustnum()>=3" && pid)/tree->GetEntries(pid);
  
  
  std::cout << "LAS VDC efficiency" << std::endl;
  std::cout << "X1 : " <<  eff_vdc_las_x1  << std::endl;
  std::cout << "X2 : " <<  eff_vdc_las_x2  << std::endl;
  std::cout << "U1 : " <<  eff_vdc_las_u1  << std::endl;
  std::cout << "U2 : " <<  eff_vdc_las_u2  << std::endl;
  std::cout << "V1 : " <<  eff_vdc_las_v1  << std::endl;
  std::cout << "V2 : " <<  eff_vdc_las_v2  << std::endl;
  //std::cout << "tot : " <<  eff_vdc_las_tot  << std::endl;

  std::cout << "X1 clst : " <<  eff_vdc_las_x1_clst  << std::endl;
  std::cout << "X2 clst : " <<  eff_vdc_las_x2_clst  << std::endl;
  std::cout << "U1 clst : " <<  eff_vdc_las_u1_clst  << std::endl;
  std::cout << "U2 clst : " <<  eff_vdc_las_u2_clst  << std::endl;
  std::cout << "V1 clst : " <<  eff_vdc_las_v1_clst  << std::endl;
  std::cout << "V2 clst : " <<  eff_vdc_las_v2_clst  << std::endl;
}
