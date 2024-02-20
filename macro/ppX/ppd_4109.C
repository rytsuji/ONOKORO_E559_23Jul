{
  //4109

  
  gROOT->ProcessLine(".x macro/gr_calib.C");

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


  TCut gr_theta="abs(theta_gr)<1.1 && abs(phi_gr)<1.7";

  TCut cut_true = coin && gr && las &&  gr_theta && tc;
  TCut cut_acc = coin && gr && las && gr_theta && tc_acc;


  au = 931.49410242; //from AME2020
   
  Double_t E_in=227.8;
  Double_t mp=1.007276466588*au;
  Double_t md=2.014101777842*au;
  Double_t mt=0;
  Double_t ma=0;
  Double_t p0_gr=563.679;
  Double_t p0_las=424.782;
  Double_t M=md;
  
  //Double_t prm[3]={0.0118286,0.000153374,4.60079e-09};
  Double_t prm[3]={0,1.0/(2000*sqrt(2.0)),0};
  
  tree->SetAlias("dt","tref_las.fTiming-tref_grtrig.fTiming");
 
  tree->SetAlias("delta_gr","vdc_gr_m.fX/(sqrt(2.0)*15451.)");
  tree->SetAlias("delta_las",
                 Form("%e+%e*vdc_las_m.fX+%e*pow(vdc_las_m.fX,2.0)",
                      prm[0],prm[1],prm[2]));
  tree->SetAlias("E_gr",Form("sqrt(pow(%e*(1-delta_gr),2.0)+pow(%e,2.0))-%e",p0_gr,mp,mp));
  tree->SetAlias("E_las",Form("sqrt(pow(%e*(1+delta_las),2.0)+pow(%e,2.0))-%e",p0_las,M,M));
  tree->SetAlias("Sx",Form("%e-E_gr-E_las",E_in));
}
