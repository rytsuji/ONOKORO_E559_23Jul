{

  tree->SetAlias("dt","tref_las.fTiming-tref_grtrig.fTiming");
  tree->SetAlias("lasx","vdc_las_m1.fX");
  tree->SetAlias("grx","vdc_gr_m.fX");
  tree->SetAlias("Egr","0.95808311*pow(1+vdc_gr_m.fX*(-4.85547e-05),2.0)");
  tree->SetAlias("Elas","0.95808311*pow(1+(vdc_las_m1.fX+2.26955e+02)*2.5032215e-04,2.0)");
 
}














