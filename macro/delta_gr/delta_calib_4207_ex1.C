/* fit for 12C ex1 (E=4.439 MeV) */
double elastic(double theta,int target,double Q){

  theta = theta*TMath::DegToRad();

  double E_beam=230.0;
  double au=931.478;
  double m[4]={1.007825*au,12.0*au,15.99491461957*au,39.962590863*au}; //p,12C,16O,40Ca                                                                       

  double beta = sqrt(E_beam*(E_beam+2.0*m[0]))/(E_beam+m[0]+m[target]);
  double g = 1.0/sqrt(1.0-beta*beta);
  
  double E_cm = sqrt( pow(m[0]+m[target]+E_beam,2.0) - E_beam*(E_beam+2.0*m[0]))-Q;
  double p_cm=0.5*sqrt((E_cm+m[0]+m[target])*(E_cm-m[0]+m[target])*(E_cm+m[0]-m[target])*(E_cm-m[0]-m[target]))/E_cm;
  double Ep_cm=0.5*(E_cm+(m[0]*m[0]-m[target]*m[target])/E_cm);
  
  double a=p_cm*p_cm*(g*g-1+pow(sin(theta),-2.0));
  double b=2*g*g*beta*Ep_cm*p_cm;
  double c=pow(g*beta*Ep_cm,2.0)+p_cm*p_cm*(1-pow(sin(theta),-2.0));
  double cos_cm=0.5*(-b+sqrt(b*b-4*a*c))/a;
  
  double p_lab=sqrt(pow(g*beta*Ep_cm+g*p_cm*cos_cm,2.0)+p_cm*p_cm*(1-cos_cm*cos_cm));
  
  //return sqrt(m[0]*m[0]+p_lab*p_lab)-m[0];
  return p_lab;



}

void delta_calib_4207_ex1(){  

  TFile *_file0 = TFile::Open("output/run4206.root");
  
  //file io
  TString dir = "/home/tsuji/work/art_analysis/e559_23jul/macro/delta_gr/dat/";
  TString iname = "/home/tsuji/work/art_analysis/e559_23jul/macro/delta_gr/fig/4207_C_ex1";
  TString oname = dir + "4207_C_ex1";
  TString fname = oname + ".dat";
  std::cout << fname << std::endl;
  ofstream ofile((std::string) fname);

  gROOT->ProcessLine(".x macro/gr_calib.C");

  Double_t p0=680.632;
  
  TH1F *hx[9];
  TH2F  *ha[9];
  TH2F  *hae[9];
  Double_t x[9];
  Double_t ac[9];
  Double_t th[9];
  Double_t delta[9];
  
  TCanvas *c1 = new TCanvas("c1","c1",1200,800);
  TCanvas *c2 = new TCanvas("c2","c2",1200,800);
  TCanvas *c3 = new TCanvas("c3","c3",1200,800);
  c1->Divide(2,5);
  c2->Divide(2,5);
  c3->Divide(2,5);
  
  
  for(int i=0;i<9;i++){
   
    Double_t theta=-0.8+0.2 * ((Double_t) i);
    TCut theta_cut=Form("abs(theta_gr-%e)<0.05",theta);

    hx[i] = new TH1F(Form("hx[%d]",i),Form("hx[%d]",i),1000,-1000,1000);
    TF1 *f = new TF1("f","gaus",-1000,1000);
    c1->cd();
    c1->cd(i+1);   
    tree->Draw(Form("vdc_gr_m.fX>>hx[%d]",i),theta_cut,"");
    hx[i]->Fit("f","","",220,270);    
    Double_t xc=f->GetParameter(1);
    Double_t xs=f->GetParameter(2);
    
    
    //ha[i]=new TH1F(Form("ha[%d]",i),Form("ha[%d]",i),5000,-1000,1000);
    ha[i]=new TH2F(Form("ha[%d]",i),Form("ha[%d]",i),50,theta-0.05,theta+0.05,1000,-100,100);
    TCut xcut=Form("abs(vdc_gr_m.fX-%e)<%e",xc,xs*3.0);
    //tree->Draw(Form("vdc_gr_m.fA*1000>>ha[%d]",i),xcut && theta_cut,"");
    c2->cd();
    c2->cd(i+1);   
    tree->Draw(Form("vdc_gr_m.fA*1000:theta_gr>>ha[%d]",i),xcut,"colz");
    TF1 *g = new TF1("g","pol1",-10,10);
    ha[i]->Fit("g");
    Double_t a=g->GetParameter(0);
    Double_t b=g->GetParameter(1);

    hae[i]=new TH2F(Form("hae[%d]",i),Form("hae[%d]",i),50,theta-0.05,theta+0.05,(int) 10*abs(b)*0.1+30,a+b*(theta-0.05)-1.5,a+b*(theta+0.05)+1.5);
    c3->cd();
    c3->cd(i+1);
    tree->Draw(Form("vdc_gr_m.fA*1000:theta_gr>>hae[%d]",i),xcut,"colz");
    hae[i]->Fit("g");
    a=g->GetParameter(0);
    b=g->GetParameter(1);
    
    x[i]=xc;
    ac[i]=a+b*theta;
    delta[i]=(elastic(33.3+theta,1,4.439)-p0)/p0;
    th[i]=theta;

  }

  for(int i=0;i<9;i++){
    ofile << x[i] <<" "<< ac[i] <<" "<< delta[i] <<" "<< th[i] << " 1 4.439"<<std::endl;
  }
  
  c1->cd();
  gStyle->SetStatFontSize(0.02);
  c1->SaveAs(iname + "_x.png");

  c2->cd();
  gStyle->SetStatFontSize(0.02);
  c1->SaveAs(iname + "_a.png");

  c3->cd();
  gStyle->SetStatFontSize(0.02);
  c3->SaveAs(iname + "_ae.png");

  ofile.close();
}
