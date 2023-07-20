void chk_true_rf3(Double_t qmin, Double_t qmax, Double_t tmin, Double_t tmax){
  
  TCut las_rf=Form("abs(fmod(tref_las.fTiming-rf3.fTiming,71.0)-%e)<%e",0.5*(tmin+tmax),0.5*(tmax-tmin));
  TCut las_q=Form("abs(pla_las_vme_3.fCharge-%e)<%e",0.5*(qmin+qmax),0.5*(qmax-qmin));
  TCut gr_q="abs(pla_gr_vme_1.fCharge-600)<300";
  TCut coin="trig_coin[0].fID==0";
  tree->SetAlias("dt","tref_las.fTiming-tref_grtrig.fTiming");
  tree->Draw("dt>>h_tc3",las_rf && las_q && gr_q && coin,"");
  
  
}
