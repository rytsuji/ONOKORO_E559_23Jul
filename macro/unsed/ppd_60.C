{
  int n_bin=500;
  gROOT->ProcessLine(".x macro/setalias.C");
  tree->SetAlias("sx","20.358396+1.5482865*169.7*4.55144e-05*(grx-lasx*1.50094)");


  double t_tc=845;
  double t_ac=775;
  
  TH1F *ht= new TH1F("ht","ht",n_bin,0,50);
  TH1F *hf = new TH1F("hf","h",n_bin,0,50);
  tree->Draw("sx>>ht",Form("abs(dt-%e)<20",t_tc),"");
  tree->Draw("sx>>hf",Form("abs(dt-%e)<20",t_ac),"");

  ht->Add(hf,-1);
  gROOT->ProcessLine("zone");
  ht->Draw();
}
