{

  double qmin=250.;
  double qmax=2000.;
  double tmin=30.;
  double tmax=50.;
  double tc_center=905.;
  double tc_center_acc=835.;
  
  
  TCut coin = "trig_coin.fID[0]==0";
  TCut gr = "abs(pla_gr_vme_1.fCharge-600)<300";
  TCut las = Form("abs(pla_las_vme_3.fCharge-%e)<%e && abs(fmod(tref_las.fTiming-rf2.fTiming+710.,71.)-%e)<%e",0.5*(qmax+qmin),0.5*(qmax-qmin),0.5*(tmax+tmin),0.5*(tmax-tmin));
  TCut tc = Form("abs(tref_las.fTiming-tref_grtrig.fTiming-%e)<20",tc_center);
  TCut tc_acc = Form("abs(tref_las.fTiming-tref_grtrig.fTiming-%e)<20",tc_center_acc);  
  TCut las2="@pla_las_vme_4.GetEntriesFast()>0 || @pla_las_vme_5.GetEntriesFast()>0 || @pla_las_vme_6.GetEntriesFast()>0";

    TCut pveto="@pla_las_vme_4.GetEntriesFast()==0 &&  @pla_las_vme_5.GetEntriesFast()==0 && @pla_las_vme_6.GetEntriesFast()==0";
  tree->SetAlias("dt","tref_las.fTiming-tref_grtrig.fTiming");
  
}
