//#define GATE





std::vector<double> fp;

std::vector<double> delta;
std::vector<double> theta;
std::vector<double> phi;
std::vector<double> x;
std::vector<double> a;
std::vector<double> y;
std::vector<double> b;



void chi2(Int_t &npar,Double_t *gin,Double_t &f,Double_t *par,Int_t iflag);
double elastic_pd(double Theta,double Phi,double delta_scale);
void read_prm(void);
void read_data(TString input);


int delta_fit_minuit(){
  
  const int n_prm=8;
  read_prm();
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
  
  vstart[1]=-1.0/(15451.0*sqrt(2.0));
  
  //step width
  double step[n_prm];
  for(int i=0;i<n_prm;i++){
    step[i] = 0.0000000001;
  }

  //set limit of prm
  //ierflg=0 if no problems, >0 if MNPARM unable to implement definition
  for(int i=0;i<n_prm;i++){
    min->mnparm(i, Form("p%d",i), vstart[i], step[i], 0, 0, ierflg);
  }
  min->FixParameter(4);
  
  
  double arglist[10];
  


  //1σを与えるカイ2乗値の増分を設定
  arglist[0] = 3.53; //1パラメータ:1.0, 2パラメータ:2.30
  min->mnexcm("SET ERR", arglist, 1, ierflg);
  arglist[0] = 1000;
  arglist[1] = 1;
  min->mnexcm("MIGRAD", arglist, 2, ierflg);
  
  
  TString oname="macro/sieve_gr/gr_delta_calib.dat"; 
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
  
  TH1F *hist = new TH1F("hist","hist",1000,-0.1,0.1);
  TH2F *ha = new TH2F("ha","ha",1000,-20,20,1000,-0.1,0.1);
  TH2F *hx = new TH2F("hx","hx",1200,-600.,600.1,1000,-0.1,0.1);
  TH2F *hd = new TH2F("hd","hd",1000,-0.1,0.1,1000,-0.1,0.1);
  TH2F *hxd = new TH2F("hxd","hxd",1200,-600.,600.,1000,-0.1,0.1);
  TH2F *hxa = new TH2F("hxa","hxa",1000,-100,100,1200,-600.,600.);

  int loop =  delta.size();  
  for(int i=0;i<loop;i++){
    //Double_t func = par[0] + par[1]*theta[i] + par[2]*delta[i];
    Double_t func = 0;
    
    func = par[0] + par[1]*x[i] + par[2]*a[i] + par[3]*x[i]*x[i]+par[4]*x[i]*a[i]+par[5]*a[i]*a[i] +par[6]*sqrt(fabs(x[i])) + par[7]*x[i]*a[i]*a[i];
    
    hist->Fill(delta[i]-func);
    ha->Fill(a[i],delta[i]-func);
    hx->Fill(x[i],delta[i]-func);
    hd->Fill(delta[i],delta[i]-func);
    hxd->Fill(x[i]+delta[i]/(4.59569e-05),delta[i]);
    hxa->Fill(a[i],x[i]+delta[i]/(4.59569e-05)); 
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
    func = par[0] + par[1]*x[i] + par[2]*a[i] + par[3]*x[i]*x[i]+par[4]*x[i]*a[i]+par[5]*a[i]*a[i] +par[6]*sqrt(fabs(x[i])) + par[7]*x[i]*a[i]*a[i];
    //func = par[0] + par[1]*delta[i]+par[2]*theta[i]+par[3]*delta[i]*theta[i]+par[4]*delta[i]*delta[i];
    //func = par[0]+par[1]*x[i]+par[2]*a[i];
    
    chisq += pow(delta[i]-func,2.0);
  }
  
  f = chisq;
}

void read_prm(void){
  TString input="macro/sieve_gr/gr_delta_calib.dat";
  std::ifstream infile((std::string) input);
  std::string iline;
  while(getline(infile,iline)){
    std::istringstream iss(iline);
    std::string str;
    iss >> str;
    fp.push_back(std::stod(str));
  }
}

double elastic_pd(double Theta,double Phi,double delta_scale){
      
  double E_beam=227.8;
  double au = 931.478;
  double m[2] = {1.00782503223*au,2.01410177812*au};  
  double theta =atan(sqrt(pow(tan(TMath::DegToRad()*28.0+Theta/1000.0),2.0)+pow(tan(Phi/1000.0),2.0)));
  
  double beta = sqrt(E_beam*(E_beam+2.0*m[0]))/(E_beam+m[0]+m[1]);
  double g = 1.0/sqrt(1.0-beta*beta);

  double E_cm = sqrt( pow(m[0]+m[1]+E_beam,2.0) - E_beam*(E_beam+2.0*m[0]) );
  double p_cm=0.5*sqrt((E_cm+m[0]+m[1])*(E_cm-m[0]+m[1])*(E_cm+m[0]-m[1])*(E_cm-m[0]-m[1]))/E_cm;
  double Ep_cm=0.5*(E_cm+(m[0]*m[0]-m[1]*m[1])/E_cm);


  double a=p_cm*p_cm*(g*g-1+pow(sin(theta),-2.0));
  double b=2*g*g*beta*Ep_cm*p_cm;
  double c=pow(g*beta*Ep_cm,2.0)+p_cm*p_cm*(1-pow(sin(theta),-2.0));

  double cos_cm=0.5*(-b+sqrt(b*b-4*a*c))/a;

  double p_lab=sqrt(pow(g*beta*Ep_cm+g*p_cm*cos_cm,2.0)+p_cm*p_cm*(1-cos_cm*cos_cm));
  std::cout << sqrt(p_lab*p_lab +m[0]*m[0]) -m[0] << std::endl;

  return (p_lab-643.681*(1+delta_scale))/643.681*(1+delta_scale);

  
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
    double fTheta=;
    double fPhi=;
    double fDelta=;
    double fX=val[4];
    double fA=val[6];
    double fY=val[8];
    double fB=val[10];

    double func = 0;
    func =fp[0] + fp[1]*fX + fp[1]*fA + fp[3]*fX*fX+fp[4]*fX*fA+fp[5]*fA*fA;
    

    if(abs(func-val[2])<1.0){
      delta.push_back(elastic_pd(val[2],val[3],val[1]));
      theta.push_back(val[2]);
      phi.push_back(val[3]);

      x.push_back(val[4]);
      a.push_back(val[6]);
      y.push_back(val[8]);
      b.push_back(val[10]);
      
    }
#else
    delta.push_back(elastic_pd(val[2],val[3],val[1]));
     theta.push_back(val[2]);
     phi.push_back(val[3]);
     
     x.push_back(val[4]);
     a.push_back(val[6]);
     y.push_back(val[8]);
     b.push_back(val[10]);
#endif
  }

}
