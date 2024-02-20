{

  double qmin=300.;
  double qmax=2000.;
  double tmin=45.;
  double tmax=65.;
  double tc_center=845.;
  double tc_center_acc=775.;
  
  
  TCut coin = "trig_coin.fID[0]==0";
  TCut gr = "abs(pla_gr_vme_1.fCharge-600)<300";
  TCut las = Form("abs(pla_las_vme_3.fCharge-%e)<%e && abs(fmod(tref_las.fTiming-rf2.fTiming+710.,71.)-%e)<%e",0.5*(qmax+qmin),0.5*(qmax-qmin),0.5*(tmax+tmin),0.5*(tmax-tmin));
  TCut tc = Form("abs(tref_las.fTiming-tref_grtrig.fTiming-%e)<20",tc_center);
  TCut tc_acc = Form("abs(tref_las.fTiming-tref_grtrig.fTiming-%e)<20",tc_center_acc);  
  TCut cut = coin && gr && las && tc;
  TCut cut_acc = coin && gr && las && tc_acc;

  
  tree->SetAlias("dt","tref_las.fTiming-tref_grtrig.fTiming");
  double Eb=227.8;
  double mp=938.7668154;
  double md=1876.091703;
  double PGR=563.697;
  double PLAS=423.762;
  
  tree->SetAlias("Sx",Form("%e-sqrt( pow(%e*(1+delta),2.0)+pow(%e,2.0) )-sqrt(pow(%e*(1+delta_las),2.0)+pow(%e,2.0))+%e+%e",Eb,PGR,mp,PLAS,md,mp,md));
}
