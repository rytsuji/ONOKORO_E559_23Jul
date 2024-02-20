{
  //4058 Li(p,pd)

  gROOT->ProcessLine(".x macro/gr_calib.C");
  
  au = 931.49410242; //from AME2020
   
  Double_t E_in=227.8;
  Double_t Sx=1.474;
  
  Double_t p0_gr=604.878;
  Double_t mp=1.007276466588*au;

  Double_t p0_las=427.987;
  Double_t md=2.014101777842*au;
  
  TCut gr_theta="abs(theta_gr)<0.75 && abs(phi_gr)<2.0";

  tree->SetAlias("delta_gr","vdc_gr_m.fX/(sqrt(2.0)*15451.)");
  tree->SetAlias("E_gr",Form("sqrt(pow(%e*(1-delta_gr),2.0)+pow(%e,2.0))-%e",p0_gr,mp,mp));
  tree->SetAlias("E_las",Form("%e-%e-E_gr",E_in,Sx));
  tree->SetAlias("delta_las",Form("(sqrt(E_las*E_las+2*E_las*%e)-%e)/%e",md,p0_las,p0_las));

  TH2F *h = new TH2F("h","",1000,-700,600,1000,-0.1,0.1);
  tree->Draw("delta_las:vdc_gr_m.fX>>h","","colz");
  TF1 *f = new TF1("f","pol2",-1000,1000);
  h->Fit("f");
  
  //tree->SetAlias("delta_las_m","0.000531034+0.000157822*vdc_las_m.fX-1.40948e-08*pow(vdc_las_m.fX,2.0)");

  double p[3];
  for(int i=0;i<3;i++){
    p[i]=f->GetParameter(i);
  }

  TH2F *hd = new TH2F("hd","",1000,-700,600,2000,-0.01,0.05);
  tree->Draw(Form("delta_las-(%e+%e*vdc_las_m.fX+%e*pow(vdc_las_m.fX,2.0)):vdc_las_m.fX>>hd",
		  p[0],p[1],p[2]));
  hd->Fit("f");  
  double q[3];
  for(int i=0;i<3;i++){
    q[i]=f->GetParameter(i);
  }

	      

  TH1F *hc = new TH1F("hc","",100,-0.01,0.01);
  tree->Draw(Form("delta_las-(%e+%e*vdc_las_m.fX+%e*pow(vdc_las_m.fX,2.0))>>hc",
		  p[0]+q[0],p[1]+q[1],p[2]+q[2]));
  
  TF1 *g = new TF1("g","gaus",-0.05,0.05);
  hc->Fit("g");
  double offset=g->GetParameter(1);
  

  tree->SetAlias("delta_las_m",
		 Form("%e+%e*vdc_las_m.fX+%e*pow(vdc_las_m.fX,2.0)",
		      p[0]+q[0]+offset,p[1]+q[1],p[2]+q[2]));
  
  tree->SetAlias("E_las_m",
		 Form("sqrt(pow(%e*(1+delta_las_m),2.0)+pow(%e,2.0))-%e",
		      p0_las,md,md));
  
  tree->SetAlias("Sx",
		 Form("%e-E_gr-E_las_m",
		      E_in));

  TH1F *h1 = new TH1F("h1","",1000,0,100);
  tree->Draw("Sx>>h1");
  h1->Fit("gaus","","",0,5);
  
  std::cout << "prm0   " << p[0]+q[0]+offset << std::endl;
  std::cout << "prm1   " << p[1]+q[1] << std::endl;
  std::cout << "prm2   " << p[2]+q[2] << std::endl;


  

 }
