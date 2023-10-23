Double_t getX(Double_t x,Double_t a,Double_t b,Double_t z){


  TVector3 vec(a,b,1);
  vec.RotateX(-45.0*TMath::DegToRad());
  vec.RotateY(-45.0*TMath::DegToRad());
  vec.RotateZ(-45.0*TMath::DegToRad());

  return x + z*vec.X()/vec.Z();
 
}
