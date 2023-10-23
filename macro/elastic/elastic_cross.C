double elastic(double E_beam,double theta,int target,double Q){

  theta = theta*TMath::DegToRad();
  
  double au=931.478;
  double m[4]={1.007825*au,12.0*au,15.99491461957*au,39.962590863*au}; //p,12C,16O,40Ca

  double beta = sqrt(E_beam*(E_beam+2.0*m[0]))/(E_beam+m[0]+m[target]);
  double g = 1.0/sqrt(1.0-beta*beta);

  double E_cm = sqrt( pow(m[0]+m[target]+E_beam,2.0) - E_beam*(E_beam+2.0*m[0]) )-Q;
  double p_cm=0.5*sqrt((E_cm+m[0]+m[target])*(E_cm-m[0]+m[target])*(E_cm+m[0]-m[target])*(E_cm-m[0]-m[target]))/E_cm;
  double Ep_cm=0.5*(E_cm+(m[0]*m[0]-m[target]*m[target])/E_cm);
  
  
  double a=p_cm*p_cm*(g*g-1+pow(sin(theta),-2.0));
  double b=2*g*g*beta*Ep_cm*p_cm;
  double c=pow(g*beta*Ep_cm,2.0)+p_cm*p_cm*(1-pow(sin(theta),-2.0));
  
  double cos_cm=0.5*(-b+sqrt(b*b-4*a*c))/a;
  
  double p_lab=sqrt(pow(g*beta*Ep_cm+g*p_cm*cos_cm,2.0)+p_cm*p_cm*(1-cos_cm*cos_cm));

  return sqrt(m[0]*m[0]+p_lab*p_lab)-m[0];
  
}

void elastic_cross(void){
  double Q1=0;
  double Q2=3.3526;
  int t1=2;
  int t2=3;
  double theta_ini=33.0;

  double E_min=220;
  double E_max=230;

  TString fname = "elastic_cross.dat"; 
  ofstream ofile((std::string) fname);
  
  int N=1000;
  for(int n=0;n<N;n++){
    double E=E_max=E_max-(double)(E_max-E_min)/N;
    double theta=theta_ini;
    while(abs(elastic(E,theta,t1,Q1)-elastic(E,theta,t2,Q2))>0.01){
      double f=elastic(E,theta,t1,Q1)-elastic(E,theta,t2,Q2);
      double dtheta=0.001;
      double df=(elastic(E,theta+dtheta,t1,Q1)-elastic(E,theta+dtheta,t2,Q2))-(elastic(E,theta,t1,Q1)-elastic(E,theta,t2,Q2));
      theta=theta-f/(df/dtheta);
    }
    
    ofile << theta << " " << E << std::endl;

  }
  ofile.close();
}
