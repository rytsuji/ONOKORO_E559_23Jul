{

  double TC_Min=800;
  double TC_Max=840;
  double TMin=370;
  double TMax=1280;
  double EB=227.8;
  double MP=938.7;
  double MX=1876.09;
  double BGR=575.995;
  double BLAS= 987.891;
  int Sxbin=250;

  TH1F *sx_tc=new TH1F("sx_tc","Sx with true coin",Sxbin,0,50);
  TH1F *sx_ac=new TH1F("sx_ac","Sx with accidental coin",Sxbin,0,50);
  
  TCut tc=Form("abs(tref_las.fTiming-tref_grtrig.fTiming-%e)<%e && abs(vdc_gr_m.fX)<500",(TC_Min+TC_Max)/2,abs(TC_Max-TC_Min)/2.0);
  TCut ac=Form("abs(tref_las.fTiming-tref_grtrig.fTiming-%e)>%e && abs(tref_las.fTiming-tref_grtrig.fTiming-%e)<%e && abs(vdc_gr_m.fX)<500",
	       (TC_Min+TC_Max)/2,abs(TC_Max-TC_Min)/2.0,(TMin+TMax)/2,abs(TMax-TMin)/2.0);
  TString sx=Form("%e+%e+%e-sqrt(pow(%e,2.0)+pow(0.3*3.0*%e*(1-vdc_gr_m.fX*4.5764467e-05),2.0))-sqrt(pow(%e,2.0)+pow(0.3*1.75*%e*(1+vdc_las_fp.fX*1.85e-04),2.0))",EB,MP,MX,MP,BGR,MX,BLAS);
  
  tree->Draw(sx+">>sx_tc",tc,"");
  tree->Draw(sx+">>sx_ac",ac,"");
  
}
