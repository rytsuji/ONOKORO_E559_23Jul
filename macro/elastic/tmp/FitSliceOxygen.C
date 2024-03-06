{
  gROOT->ProcessLine(".x macro/gr_calib.C");
  //gROOT->LoadMacro("macro/gr_calib.C"); 

  //run4206
  TCut cut="abs(pla_gr_vme_1.fCharge-600)<300";
  TH2F* h_xa= new TH2F("h_xa","",100,0.0025,0.0055,100,-1.2,1.2);
  tree->Draw("theta_gr:delta>>h_xa",cut,"colz");
  TF1 *f= new TF1("f","pol5",-10,10);
  h_xa->FitSlicesX();
  h_xa_1->Fit("f","","",-0.9,0.9);
  
  const int n_prm=6;
  
  double prm[n_prm];
  for(int i=0;i<n_prm;i++){
    prm[i]=f->GetParameter(i);
  }


  tree->SetAlias("fc",
		 Form("%e+(%e)*pow(theta_gr,1.0)+(%e)*pow(theta_gr,2.0)+(%e)*pow(theta_gr,3.0)+(%e)*pow(theta_gr,4.0)+(%e)*pow(theta_gr,5.0)",prm[0],prm[1],prm[2],prm[3],prm[4],prm[5]));
  
  TCut locus="abs(delta-fc)<0.001";  
  TH2F* h_ax_cut= new TH2F("h_ax_cut","",100,-1.2,1.2,100,0.0025,0.0055);
  tree->Draw("delta:theta_gr>>h_ax_cut",locus && cut,"colz");
  h_ax_cut->Fit("f","","",-1,1);

  for(int i=0;i<n_prm;i++){
    prm[i]=f->GetParameter(i);
  }
  
  tree->SetAlias("fci",
		 Form("%e+(%e)*pow(theta_gr,1.0)+(%e)*pow(theta_gr,2.0)+(%e)*pow(theta_gr,3.0)+(%e)*pow(theta_gr,4.0)+(%e)*pow(theta_gr,5.0)",prm[0],prm[1],prm[2],prm[3],prm[4],prm[5]));

  

  
  tree->Draw("delta-fci>>h(100,-0.005,0.005)",cut && "abs(theta_gr)<0.5","");
  
}


