{
  Double_t RUN_LAS_YG=0.0;
  
  Double_t a[3]={1.61034e-02+1.09e-03,-4.17069e-01,2.36614e-05};
  Double_t b[4]={-9.65234e-03-1.07086e-03*RUN_LAS_YG+2.15e-04*RUN_LAS_YG,4.17063e+00,-1.99037e-03,6.16186e-06+6.17463e-07*RUN_LAS_YG};
  
  tree->SetAlias("grx","vdc_gr_m.GetX(0)");
  tree->SetAlias("gry","vdc_gr_m.GetY(0)");
  tree->SetAlias("gra","vdc_gr_m.fA*1000");
  tree->SetAlias("grb","vdc_gr_m.fB*1000");
  TString theta_gr=Form("(%e+%e*gra+%e*grx)/1000.0*TMath::RadToDeg()",a[0],a[1],a[2]);
  TString phi_gr=Form("(%e+%e*grb+%e*gry+%e*grx)/1000.0*TMath::RadToDeg()",b[0],b[1],b[2],b[3]);
  
  //TString phi_gr=Form("(%e + %e + %e*grb + %e*gry + %e*gry*grb + %e*gra + %e*gra*grb + %e*gra*gry + %e*gra*gry*grb + %e*grx + %e*grx + %e*grx*grb + %e*grx*gry + %e*grx*gry*grb + %e*)/1000.0*TMath::RadToDeg()",b[0],b[1],b[2],b[3],b[4],b[5],b[6],b[7],b[8],b[9],b[10]);
  tree->SetAlias("theta_gr",theta_gr);
  tree->SetAlias("phi_gr",phi_gr);
  
  
  
  
 
  //tree->SetAlias("phi_gr",Form("%e+%e*vdc_gr_m.fA*1000+%e*vdc_gr_m.fX+%e*vdc_gr_m.fY+%e*vdc_gr_m.fA*1000*vdc_gr_m.fX+%e*vdc_gr_m.fX*vdc_gr_m.fY+%e*vdc_gr_m.fA*1000*vdc_gr_m.fY+%e*vdc_gr_m.fA*1000*vdc_gr_m.fX*vdc_gr_m.fY",b0,b1,b2,b3,b4,b5,b6,b7));

}



