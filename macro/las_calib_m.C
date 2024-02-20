{

  Double_t las_tilted=0.066561773; //(rad)
  Double_t fp=-60.0*TMath::DegToRad(); //(rad)
  Double_t x0 = -5.4296484;
  Double_t z0 =  100.36299;

  tree->SetAlias("lasa_raw",Form("(vdc_las_m.fA*%e-1*%e)/(vdc_las_m.fA*%e+1*%e)",cos(fp),sin(fp),sin(fp),cos(fp)));
  tree->SetAlias("lasb_raw",Form("(vdc_las_m.fB)/(vdc_las_m.fA*%e+1*%e)",sin(fp),cos(fp)));
  
  tree->SetAlias("lasz",Form("(%e*(vdc_las_m.fX-%e)+%e)/(1-%e*lasa_raw)",tan(las_tilted),x0,z0,tan(las_tilted)));
  tree->SetAlias("lasx",Form("(vdc_las_m.fX+lasz*lasa_raw-%e)*%e-(lasz-%e)*%e",x0,cos(-las_tilted),z0,sin(-las_tilted)));
  tree->SetAlias("lasy","vdc_las_m.fY+lasz*lasb_raw");
  //las_tilted=0;
  tree->SetAlias("lasa",Form("(lasa_raw*%e-1*%e)/(lasa_raw*%e+1*%e)",cos(-las_tilted-fp),sin(-las_tilted-fp),sin(-las_tilted-fp),cos(-las_tilted-fp)));
  tree->SetAlias("lasb",Form("(lasb_raw)/(lasa_rawx*%e+1*%e)",sin(-las_tilted-fp),cos(-las_tilted-fp)));

  //double las_xmat[4][3][1][1];
  //las_xmat[0][0][0][0]=0.22806E-01;
  //las_xmat[1][0][0][0]=0.23392E-03;

  tree->SetAlias("delta_las","lasx*0.23392E-03+0.22806E-01");
  
  

}
