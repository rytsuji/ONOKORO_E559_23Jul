{

  Double_t las_tilted=0.066561773; //(rad)
  Double_t fp=-60.0*TMath::DegToRad(); //(rad)
  Double_t x0 = -5.4296484;
  Double_t z0 =  100.36299;
  tree->SetAlias("lasz",Form("(%e*(vdc_las.fX-%e)+%e)/(1-%e*vdc_las.fA)",tan(las_tilted),x0,z0,tan(las_tilted)));
  tree->SetAlias("lasx",Form("(vdc_las.GetX(lasz)-%e)*%e-(lasz-%e)*%e",x0,cos(-las_tilted),z0,sin(-las_tilted)));
  tree->SetAlias("lasy","vdc_las.GetY(lasz)");
  //las_tilted=0;
  tree->SetAlias("lasa",Form("(vdc_las.fA*%e-1*%e)/(vdc_las.fA*%e+1*%e)",cos(-las_tilted-fp),sin(-las_tilted-fp),sin(-las_tilted-fp),cos(-las_tilted-fp)));
  tree->SetAlias("lasb",Form("(vdc_las.fB)/(vdc_las.fA*%e+1*%e)",sin(-las_tilted-fp),cos(-las_tilted-fp)));

  //double las_xmat[4][3][1][1];
  //las_xmat[0][0][0][0]=0.22806E-01;
  //las_xmat[1][0][0][0]=0.23392E-03;

  tree->SetAlias("delta_las","lasx*0.23392E-03+0.22806E-01");
  
  

}
