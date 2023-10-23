Double_t getY(Double_t y,Double_t a,Double_t b,Double_t z){


  TVector3 vec(a,b,1);
  vec.RotateX(-45.0*TMath::DegToRad());
  vec.RotateY(-45.0*TMath::DegToRad());
  vec.RotateZ(-45.0*TMath::DegToRad());

  return y + z*vec.Y()/vec.Z();
 
}
