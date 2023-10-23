{

  std::vector<Double_t> a;
  std::string fname1 ="/home/tsuji/work/art_analysis/e559_23jul/macro/sieve_slit_gr/gr_theta_calib.dat" ;
  std::ifstream infile1(fname1);
  std::string iline1;
  while(getline(infile1,iline1)){
    std::istringstream line(iline1);
    std::string str[2];
    line >> str[0] >>str[1];
    a.push_back(std::stod(str[0]));
  }

  while(a.size()<11){
    a.push_back(0);
  }
  
  std::vector<Double_t> b;
  std::string fname2 ="/home/tsuji/work/art_analysis/e559_23jul/macro/sieve_slit_gr/gr_phi_calib.dat";
  std::ifstream infile2(fname2);
  std::string iline2;
  while(getline(infile2,iline2)){
    std::istringstream line(iline2);
    std::string str[2];
    line >> str[0] >>str[1];
    b.push_back(std::stod(str[0]));
  }

  while(b.size()<20){
    b.push_back(0);
  }
  
  tree->SetAlias("grx","vdc_gr_m.GetX(-1000)");
  tree->SetAlias("gry","vdc_gr_m.GetY(-1000)");
  tree->SetAlias("gra","vdc_gr_m.fA*1000");
  tree->SetAlias("grb","vdc_gr_m.fB*1000");
  TString theta_gr=Form("-(%e+%e*gra+%e*grx+%e*pow(grx,2.0)+%e*pow(gry,2.0)+%e*pow(grx,3.0))/1000.0*TMath::RadToDeg()",a[0],a[1],a[2],a[3],a[4],a[5]);

  TString phi_gr=Form("(%e + %e*gra + %e*grx + %e*gry + %e*pow(gra,2.0) + %e*pow(grx,2.0) + %e*pow(gry,2.0) + %e*gra*grx + %e*grx*gry + %e*gry*gra + %e*pow(grx,3.0))/1000.0*TMath::RadToDeg()",b[0],b[1],b[2],b[3],b[4],b[5],b[6],b[7],b[8],b[9],b[10]);
  tree->SetAlias("theta_gr",theta_gr);
  tree->SetAlias("phi_gr",phi_gr);




 
  //tree->SetAlias("phi_gr",Form("%e+%e*vdc_gr_m.fA*1000+%e*vdc_gr_m.fX+%e*vdc_gr_m.fY+%e*vdc_gr_m.fA*1000*vdc_gr_m.fX+%e*vdc_gr_m.fX*vdc_gr_m.fY+%e*vdc_gr_m.fA*1000*vdc_gr_m.fY+%e*vdc_gr_m.fA*1000*vdc_gr_m.fX*vdc_gr_m.fY",b0,b1,b2,b3,b4,b5,b6,b7));

}



