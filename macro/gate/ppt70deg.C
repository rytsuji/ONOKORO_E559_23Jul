{
  TCut RF="abs(fmod(tref_las.fTiming-rf2.fTiming+710.0,71.0)-35.0)<15.0";
  tree->SetAlias("x","pla_las_vme_3.GetTDiff()");
  tree->SetAlias("q1","pla_las_vme_3.fCharge");
  tree->SetAlias("q2","pla_las_vme_5.fCharge");
  tree->SetAlias("tot","(vdc_las_clust_x1.fCharge+vdc_las_clust_x2.fCharge+vdc_las_clust_u1.fCharge+vdc_las_clust_u2.fCharge)/4.0");
  

  tree->Draw("q1:x>>hqx(60,-50,10,500,0,4000)",RF,"colz");
  tree->Draw("q1:q2>>hqq(1000,0,4000,1000,0,4000)",RF,"colz");
  tree->Draw("tot:q1>>htq(1000,0,4000,2500,0,10000)",RF,"colz");
}
