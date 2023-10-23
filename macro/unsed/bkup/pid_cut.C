{
  TCut pid_gr="abs(pla_gr_vme_1.fCharge-650)<250";
  TCut coin="trig_coin[0].fID==0";
  tree->SetAlias("dt","tref_las.fTiming-tref_grtrig.fTiming"); 
}
