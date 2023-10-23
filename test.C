int hoge(double a);

double test(){
  double a=0.0;
  hoge(a);
  return a;
}

int hoge(double a){
  a=TMath::Pi();
  return 0;
}
