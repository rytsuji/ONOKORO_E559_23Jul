double elastic(double theta,int target,double Q,double E_beam){

  theta = theta*TMath::DegToRad();
  
  //double E_beam=229.127;
  double au=931.478;
  double m[5]={1.00782503223*au,2.01410177812*au,12.0*au,15.99491461957*au,39.962590863*au}; //p,12C,16O,40Ca

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

  //return sqrt(m[0]*m[0]+p_lab*p_lab)-m[0];
  return 100.0*(p_lab-643.681)/643.681;
  
  
 
}
