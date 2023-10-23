std::vector<Double_t> prm;

double delta(double fX,double fA){
  double val=0;
  for(int n=0;n<3;n++){
    for(int m=0;m<3;m++){
      val += prm[5*n+m]*pow(fX,n)*pow(fA,m);
    }
  }
  return val;
}


void gr_delta_calib(void){



  
  std::string fname1 ="/home/tsuji/work/art_analysis/e559_23jul/macro/delta_gr/gr_delta_calib.dat" ;
  std::ifstream infile1(fname1);
  std::string iline1;

  while(getline(infile1,iline1)){
    std::istringstream line(iline1);
    std::string str[2];
    line >> str[0] >>str[1];
    prm.push_back(std::stod(str[0]));
  }
 
  tree->SetAlias("delta_gr","delta(vdc_gr_m.fX,vdc_gr_m.fA*1000)");
  
}



