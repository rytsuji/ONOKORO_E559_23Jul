#define GATE

std::vector<double> fp;

std::vector<double> delta;
std::vector<double> theta;
std::vector<double> phi;
std::vector<double> x;
std::vector<double> a;
std::vector<double> y;
std::vector<double> b;



void chi2(Int_t &npar,Double_t *gin,Double_t &f,Double_t *par,Int_t iflag);
void read_theta(void);
void read_data(TString input);


int theta_fit_minuit(){
  
  const int n_prm=10;
  read_theta();
  read_data("macro/sieve_gr/sieve_gr_fit.dat");

  TMinuit *min = new TMinuit(n_prm);// set number of parameters
  min->SetPrintLevel(1);
  min->SetFCN(chi2);
  int ierflg = 0;
  
  //Intialize of parameters
  double vstart[n_prm];
  for(int i=0;i<n_prm;i++){
    vstart[i] = 0.0;
  }
  vstart[0] = 2.77926;
  vstart[1] = 0.0206896;
  vstart[2] = -0.382283;

  //step width
  double step[n_prm];
  for(int i=0;i<n_prm;i++){
    step[i] = 0.001;
  }

  //set limit of prm
  //ierflg=0 if no problems, >0 if MNPARM unable to implement definition
  for(int i=0;i<n_prm;i++){
    min->mnparm(i, Form("p%d",i), vstart[i], step[i], 0, 0, ierflg);
  }
  
  
  double arglist[10];
  
  //1σを与えるカイ2乗値の増分を設定
  arglist[0] = 3.53;//1パラメータ:1.0, 2パラメータ:2.30
  min->mnexcm("SET ERR", arglist, 1, ierflg);


  arglist[0] = 1000;
  arglist[1] = 1;
  min->mnexcm("MIGRAD", arglist, 2, ierflg);
  
  
  TString oname="macro/sieve_gr/gr_theta_calib.dat"; 
  ofstream ofile((std::string) oname);
  
  double par[n_prm];
  double par_err[n_prm];

  cout<<"**************************************"<<endl;
  for(int i=0;i<n_prm;i++){
    min->GetParameter(i,par[i],par_err[i]);
    cout<<"p" << i << ": "<< par[i] <<" +/- "<< par_err[i] <<endl;
    ofile << par[i] << " " << par_err[i] << std::endl;
  }
  ofile.close();
  
  TH1F *hist = new TH1F("hist","hist",200,-5,5);
  TH2F *hx = new TH2F("hx","hx",1000,-500,500,200,-5,5);
  TH2F *ha = new TH2F("ha","ha",1000,-500,500,200,-5,5);
  TH2F *hy = new TH2F("hy","hy",1000,-500,500,200,-5,5);
  TH2F *hb = new TH2F("hb","hb",1000,-500,500,200,-5,5);
  int loop =  delta.size();
  for(int i=0;i<loop;i++){
    //Double_t func = par[0]+par[1]*x[i]+par[2]*a[i]+par[3]*y[i];
    Double_t func = par[0]+par[1]*x[i]+par[2]*a[i];
    func += par[3]*x[i]*x[i]+par[4]*x[i]*a[i]+par[5]*a[i]*a[i];
    func += par[6]*y[i]*y[i]+par[7]*y[i]*b[i]+par[8]*b[i]*b[i];
    func += par[9]*pow(x[i],3);
    hist->Fill(func-theta[i]);
    hx->Fill(x[i],func-theta[i]);
    ha->Fill(a[i],func-theta[i]);
    hy->Fill(y[i],func-theta[i]);
    hb->Fill(b[i],func-theta[i]); 
  }
  
  hist->Draw();
  
  delete min;
  
  return 0;
}  



void chi2(Int_t &npar,Double_t *gin,Double_t &f,Double_t *par,Int_t iflag){
  int loop =  delta.size();
  
  double chisq = 0;

  for(int i=0; i<loop; i++){
    double func = 0;
    func = par[0]+par[1]*x[i]+par[2]*a[i];
    func += par[3]*x[i]*x[i]+par[4]*x[i]*a[i]+par[5]*a[i]*a[i];
    func += par[6]*y[i]*y[i]+par[7]*y[i]*b[i]+par[8]*b[i]*b[i];
    func += par[9]*pow(x[i],3);
    chisq += pow(theta[i]-func,2.0);
  }
  
  f = chisq;
}

void read_theta(void){
  TString input="macro/sieve_gr/gr_theta_calib.dat";
  std::ifstream infile((std::string) input);
  std::string iline;
  while(getline(infile,iline)){
    std::istringstream iss(iline);
    std::string str;
    iss >> str;
    fp.push_back(std::stod(str));
  }
}
   

void read_data(TString input){

  std::ifstream infile((std::string) input);
  std::string iline;
  getline(infile,iline); //skip heade

  while(getline(infile,iline)){

    std::string str;
    std::vector<double> val;
    stringstream ss(iline);
    while(getline(ss, str, ' ')){
      val.push_back(std::stod(str));    
    }
#ifdef GATE
    double fX=val[4];
    double fA=val[6];
    double fY=val[8];
    double fB=val[10];
    double func= fp[0]+fp[1]*fX+fp[2]*fA;
    func += fp[3]*fX*fX+fp[4]*fX*fA+fp[5]*fA*fA;
    func += fp[6]*fY*fY+fp[7]*fY*fB+fp[8]*fB*fB;
    func += fp[9]*pow(fX,3);

    

    if(abs(func-val[2])<1.0){
      delta.push_back(val[1]);
      theta.push_back(val[2]);
      phi.push_back(val[3]);
      
      x.push_back(val[4]);
      a.push_back(val[6]);
      y.push_back(val[8]);
      b.push_back(val[10]);
    }
#else
     delta.push_back(val[1]);
     theta.push_back(val[2]);
     phi.push_back(val[3]);
     
     x.push_back(val[4]);
     a.push_back(val[6]);
     y.push_back(val[8]);
     b.push_back(val[10]);
#endif
  }

}
