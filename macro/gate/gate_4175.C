{

  double qmin=300.;
  double qmax=1200.;
  double tmin=40.;
  double tmax=65.;
  double tc_center=880.;
  double tc_center_acc=815.;
  
  
  TCut coin = "trig_coin.fID[0]==0";
  TCut gr = "abs(pla_gr_vme_1.fCharge-600)<300";
  TCut las = Form("abs(pla_las_vme_3.fCharge-%e)<%e && abs(fmod(tref_las.fTiming-rf2.fTiming+710.,71.)-%e)<%e",0.5*(qmax+qmin),0.5*(qmax-qmin),0.5*(tmax+tmin),0.5*(tmax-tmin));
  TCut tc = Form("abs(tref_las.fTiming-tref_grtrig.fTiming-%e)<20",tc_center);
  TCut tc_acc = Form("abs(tref_las.fTiming-tref_grtrig.fTiming-%e)<20",tc_center_acc);  
  TCut pveto="@pla_las_vme_4.GetEntriesFast()==0 && @pla_las_vme_5.GetEntriesFast()==0 &&@pla_las_vme_6.GetEntriesFast()==0";

  tree->SetAlias("dt","tref_las.fTiming-tref_grtrig.fTiming");
  tree->SetAlias("dt1","pla_las_vme_3.fTiming-pla_gr_vme_1.fTiming");  
  
}
