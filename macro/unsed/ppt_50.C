{
  int n_bin=250;
  gROOT->ProcessLine(".x macro/setalias.C");
  tree->SetAlias("sx","26.260688+1.7371306*169.75*4.55144e-05*(grx-lasx*0.87099)");


  double t_tc=905;
  double t_ac=835;
  
  TH1F *ht= new TH1F("ht","ht",n_bin,0,50);
  TH1F *hf = new TH1F("hf","hf",n_bin,0,50);
  tree->Draw("sx>>hf","abs(dt-835)<20","");
  tree->Draw("sx>>ht","abs(dt-905)<20","");

  ht->Add(hf,-1);
  
  gROOT->ProcessLine("zone");
  ht->Draw();
}
