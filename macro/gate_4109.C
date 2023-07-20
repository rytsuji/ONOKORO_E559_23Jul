{
  //(p,pd) run4102 use rf1


  double qmin=200.;
  double qmax=1500.;
  double tmin=0.;
  double tmax=20.;
  double tc_center=850.;
  double tc_center_acc=770.;
  
  
  TCut coin = "trig_coin.fID[0]==0";
  TCut gr = "abs(pla_gr_vme_1.fCharge-600)<300";
  TCut las = Form("abs(pla_las_vme_3.fCharge-%e)<%e && abs(fmod(tref_las.fTiming-rf1.fTiming+710.,71.)-%e)<%e",0.5*(qmax+qmin),0.5*(qmax-qmin),0.5*(tmax+tmin),0.5*(tmax-tmin));
  TCut tc = Form("abs(tref_las.fTiming-tref_grtrig.fTiming-%e)<20",tc_center);
  TCut tc_acc = Form("abs(tref_las.fTiming-tref_grtrig.fTiming-%e)<20",tc_center_acc);  


  tree->SetAlias("dt","tref_las.fTiming-tref_grtrig.fTiming");
  
}
