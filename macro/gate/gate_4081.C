{

  double qmin=300.;
  double qmax=1000.;
  double tmin=32.;
  double tmax=45.;
  double tc_center=820.;
  double tc_center_acc=750.;
  
  
  TCut coin = "trig_coin.fID[0]==0";
  TCut gr = "abs(pla_gr_vme_1.fCharge-600)<300";
  TCut las = Form("abs(pla_las_vme_3.fCharge-%e)<%e && abs(fmod(tref_las.fTiming-rf2.fTiming+710.,71.)-%e)<%e",0.5*(qmax+qmin),0.5*(qmax-qmin),0.5*(tmax+tmin),0.5*(tmax-tmin));
  TCut tc = Form("abs(tref_las.fTiming-tref_grtrig.fTiming-%e)<20",tc_center);
  TCut tc_acc = Form("abs(tref_las.fTiming-tref_grtrig.fTiming-%e)<20",tc_center_acc);  


  tree->SetAlias("dt","tref_las.fTiming-tref_grtrig.fTiming");
  
}
