{

  tree->SetAlias("rf1","fmod(tref_las.fTiming-rf1.fTiming+710,142)");
  tree->SetAlias("rf2","fmod(tref_las.fTiming-rf2.fTiming+710,142)");
  tree->SetAlias("rf3","fmod(tref_las.fTiming-rf3.fTiming+710,142)");

  double TMin=36;
  double TMax=41;

  double QMin=300;
  double QMax=1200;

  TCut cut_t=Form("abs(fmod(tref_las.fTiming-rf1.fTiming+710,142)-%e)<%e",
		  0.5*(TMin+TMax),0.5*(TMax-TMin));
  TCut cut_q=Form("abs(pla_las_vme_3.fCharge-%e)<%e",
		  0.5*(QMin+QMax),0.5*(QMax-QMin));
  TCut pid=cut_t && cut_q;

}
