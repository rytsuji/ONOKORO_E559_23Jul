{
  //(p,pd) run4102 use rf1


  double qmin=200.;
  double qmax=700.;
  double tmin=46.;
  double tmax=60.;
  double tc_center=865.;
  double tc_center_acc=790.;


  //(p,pt) kf=-50MeV use rf2
  /*
  double qmin=500.;
  double qmax=1000.;
  double tmin=45.;
  double tmax=60.;
  double tc_center=875.;
  double tc_center_acc=765.;
  */

  /*(p,pd) in kf=-150 MeV (p,pt) use rf1
  double qmin=250.;
  double qmax=800.;
  double tmin=25.;
  double tmax=45.;
  double tc_center=835.;
  double tc_center_acc=765.;
  */

  //(p,pd) theta_cm=80deg : use rf1
  /*
  double qmin=200.;
  double qmax=1000.;
  double tmin=15.;
  double tmax=30.;
  double tc_center=810.;
  double tc_center_acc=765.;
  */
  
  //(p,pd) theta_cm=90deg : use rf1
  /*
  double qmin=200.;
  double qmax=700.;
  double tmin=12.;
  double tmax=22.;
  double tc_center=795.;
  double tc_center_acc=765.;
  */
  
  
  TCut coin = "trig_coin.fID[0]==0";
  TCut gr = "abs(pla_gr_vme_1.fCharge-600)<300";
  TCut las = Form("abs(pla_las_vme_3.fCharge-%e)<%e && abs(fmod(tref_las.fTiming-rf1.fTiming+710.,71.)-%e)<%e",0.5*(qmax+qmin),0.5*(qmax-qmin),0.5*(tmax+tmin),0.5*(tmax-tmin));
  
  TCut tc = Form("abs(tref_las.fTiming-tref_grtrig.fTiming-%e)<20",tc_center);
  TCut tc_acc = Form("abs(tref_las.fTiming-tref_grtrig.fTiming-%e)<20",tc_center_acc);  
}
