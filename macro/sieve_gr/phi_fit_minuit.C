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
void read_phi(void);
void read_data(TString input);


int phi_fit_minuit(){
  
  const int n_prm=10;


  read_phi();  
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
  vstart[0]=4.4628;
  vstart[1]=-2.51173;
  

  //step width
  double step[n_prm];
  for(int i=0;i<n_prm;i++){
    step[i] = 0.0000001;
  }

  //set limit of prm
  //ierflg=0 if no problems, >0 if MNPARM unable to implement definition
  for(int i=0;i<n_prm;i++){
    min->mnparm(i, Form("p%d",i), vstart[i], step[i], 0, 0, ierflg);
  }
  
  
  double arglist[20];
  
  //1σを与えるカイ2乗値の増分を設定
  arglist[0] = 3.53;//1パラメータ:1.0, 2パラメータ:2.30
  //arglist[0] = 100.0;//1パラメータ:1.0, 2パラメータ:2.30
  min->mnexcm("SET ERR", arglist, 1, ierflg);


  arglist[0] = 1000;
  arglist[1] = 1;
  min->mnexcm("MIGRAD", arglist, 2, ierflg);
  
  
  TString oname="macro/sieve_gr/gr_phi_calib.dat"; 
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
  
  TH1F *hist = new TH1F("hist","hist",100,-10,10);
  TH2F *hx = new TH2F("hx","hist",1200,-600,600,100,-10,10);
  TH2F *ha = new TH2F("ha","hist",200,-100,100,100,-10,10);
  TH2F *hy = new TH2F("hy","hist",200,-50,50,100,-10,10);
  TH2F *hb = new TH2F("hb","hist",200,-50,50,100,-10,10);
  int loop =  delta.size();
  for(int i=0;i<loop;i++){

    double yc = y[i];
    double func1 = par[0]+par[1]*yc+par[2]*a[i]+par[3]*x[1];
    double func2 = par[4]*yc*a[i]+par[5]*yc*x[i]+par[6]*x[i]*a[i];
    double func3 = par[7]*yc*a[i]*x[i];
    double func4 = par[8]*b[i]+par[9]*b[i]*x[i];
    //double func4 = par[8]*b[i]+par[9]*b[i]*a[i]+par[10]*b[i]*x[i]+par[11]*yc*b[i];
    //double func5 = par[12]*pow(yc,2.0)+par[13]*pow(yc,3.0);

    double err=func1+func2+func3+func4-phi[i];
    hist->Fill(err);
    hx->Fill(x[i],err);
    ha->Fill(a[i],err);
    hy->Fill(y[i],err);
    hb->Fill(b[i],err);
  }
  
  hist->Draw();
  
  delete min;
  
  return 0;
}  



void chi2(Int_t &npar,Double_t *gin,Double_t &f,Double_t *par,Int_t iflag){
  int loop =  delta.size();
  
  double chisq = 0;

  for(int i=0; i<loop; i++){
    
    double yc=y[i];
    double func1 = par[0]+par[1]*yc+par[2]*a[i]+par[3]*x[1];
    double func2 = par[4]*yc*a[i]+par[5]*yc*x[i]+par[6]*x[i]*a[i];
    double func3 = par[7]*yc*a[i]*x[i];
    double func4 = par[8]*b[i]+par[9]*b[i]*x[i];
    //double func4 = par[8]*b[i]+par[9]*b[i]*a[i]+par[10]*b[i]*x[i]+par[11]*yc*b[i];
    //double func5 = par[12]*pow(yc,2.0)+par[13]*pow(yc,3.0);


    chisq += pow(phi[i]-func1-func2-func3-func4,2.0);

  }
  
  f = chisq;
}

void read_phi(void){
  TString input="macro/sieve_gr/gr_phi_calib.dat";
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
    double fY=val[8];;
    double fB=val[10];
    double func1 = fp[0]+fp[1]*fY+fp[2]*fA+fp[3]*fX;
    double func2 = fp[4]*fY*fA+fp[5]*fY*fX+fp[6]*fX*fA;
    double func3 = fp[7]*fY*fA*fX;
    double func4 = fp[8]*fB+fp[9]*fB*fX;

    if(abs(func1+func2+func3+func4-val[3])<2.0){
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


