std::vector<double> a;
std::vector<double> b; 

void read_theta(void);
void read_phi(void);
double theta(double fX,double fA,double fY,double fB);
double phi(double fX,double fA,double fY,double fB);


void gr_ang(void){

  read_theta();
  read_phi();

  gROOT->LoadMacro("macro/yb_gr/setalias.C");

  Double_t r2d=TMath::RadToDeg()/1000.0;
  tree->SetAlias("theta_gr","theta(vdc_gr_m.GetX(-1000),vdc_gr_m.fA*1000,vdc_gr_m.GetY(-1000),vdc_gr_m.fB*1000)");
  tree->SetAlias("phi_gr","phi(vdc_gr_m.GetX(-1000),vdc_gr_m.fA*1000,vdc_gr_m.GetY(-1000),vdc_gr_m.fB*1000)");

}

void read_theta(void){
  TString input="macro/sieve_slit_gr/gr_theta_calib.dat";
  std::ifstream infile((std::string) input);
  std::string iline;
  while(getline(infile,iline)){
    std::istringstream iss(iline);
    std::string str;
    iss >> str;
    a.push_back(std::stod(str));
  }
}

void read_phi(void){
  TString input="macro/sieve_slit_gr/gr_phi_calib.dat";
  std::ifstream infile((std::string) input);
  std::string iline;
  while(getline(infile,iline)){
    std::istringstream iss(iline);
    std::string str;
    iss >> str;
    b.push_back(std::stod(str));
  }
}


double theta(double fX,double fA,double fY,double fB){
  double func1=a[0]+a[1]*fA+a[2]*fX;
  double func2=a[3]*fX*fX+a[4]*fY*fY;
  double func3=a[5]*pow(fX,3.0);

  return func1+func2+func3;
    
  ///return a[0]+a[1]*fX+a[2]*fA+a[3]*fY+a[4]*fB;
}

double phi(double fX,double fA,double fY,double fB){

  double func1=b[0]+b[1]*fA+b[2]*fX+b[3]*fY+b[4]*fB;
  double func2=b[4]*pow(fA,2.0)+b[6]*pow(fX,2.0)+b[7]*pow(fY,2.0)+b[8]*pow(fB,2.0);
  double func3=b[9]*fA*fX+b[10]*fX*fY+b[11]*fY*fA+b[12]*fA*fB+b[13]*fX*fB+b[14]*fY*fB;
  double func4=b[15]*pow(fX,3.0)+b[16]*pow(fX,4.0)+b[17]+pow(fX,5.0);
  /*
    double yc = fYc+b[0]*fB+b[1]*fX*fB;
    double func1 = b[2]+b[3]*fYc+b[4]*fA+b[5]*fX;
    double func2 = b[6]*fYc*fA+b[7]*fYc*fX+b[8]*fX*fA;
    double func3 = b[9]*fYc*fA*fX;
  */
  
  //double func1 = b[0]+b[1]*fY+b[2]*fA+b[3]*fX;
  //double func2 = b[4]*fY*fA+b[5]*fY*fX+b[6]*fX*fA;
  //double func3 = b[7]*fY*fA*fX;
  //double func4 = b[8]*fB+b[9]*fB*fX;
  //double func4 = b[8]*fB+b[9]*fB*fA+b[10]*fB*fX+b[11]*fY*fB;
  //double func5 = b[12]*pow(fY,2.0)+b[13]*pow(fY,3.0);

  return func1+func2+func3+func4;
  
}



