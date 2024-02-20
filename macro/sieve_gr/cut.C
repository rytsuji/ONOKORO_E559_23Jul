class prm{
public:

  Double_t a_min;
  Double_t a_max;
  Double_t x_min;
  Double_t x_max;
};

TCut pid_proton;
TCut xcut;

prm read_conf(TString conf);

void cut(TString conf){

  prm par=read_conf(conf);
  pid_proton = "abs(pla_gr_vme_1.fCharge-600)<300";
  xcut=Form("abs(vdc_gr_m.fX-%e)<%e",0.5*(par.x_max+par.x_min),0.5*abs(par.x_max-par.x_min));
  
}

prm read_conf(TString conf){
  
  prm par;
  TString  cfgname ="macro/sieve_gr/conf/"+conf+".conf";

  std::ifstream infile((std::string) cfgname);
  std::string iline;
  getline(infile,iline); //skip header
  getline(infile,iline);
  std::string str[5];
  std::istringstream iss(iline);
  iss >> str[0] >> str[1] >> str[2] >> str[3] >> str[4];
  
  par.x_min = std::stod(str[1]);
  par.x_max = std::stod(str[2]);
  par.a_min = std::stod(str[3]);
  par.a_max = std::stod(str[4]);
  
  return par;  
}
