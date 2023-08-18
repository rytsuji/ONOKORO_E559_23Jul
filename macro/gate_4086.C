{

  double qmin=400.;
  double qmax=2000.;
  double tmin=15.;
  double tmax=35.;
  double tc_center=860.;
  double tc_center_acc=785.;
  
  
  TCut coin = "trig_coin.fID[0]==0";
  TCut gr = "abs(pla_gr_vme_1.fCharge-600)<300";
  TCut las = Form("abs(pla_las_vme_3.fCharge-%e)<%e && abs(fmod(tref_las.fTiming-rf1.fTiming+710.,71.)-%e)<%e",0.5*(qmax+qmin),0.5*(qmax-qmin),0.5*(tmax+tmin),0.5*(tmax-tmin));
  TCut tc = Form("abs(tref_las.fTiming-tref_grtrig.fTiming-%e)<20",tc_center);
  TCut tc_acc = Form("abs(tref_las.fTiming-tref_grtrig.fTiming-%e)<20",tc_center_acc);  


  tree->SetAlias("dt","tref_las.fTiming-tref_grtrig.fTiming");
  
}
