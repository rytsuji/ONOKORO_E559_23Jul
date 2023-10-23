{
  int n_bin=500;
  gROOT->ProcessLine(".x macro/setalias.C");
  tree->SetAlias("sx","20.358396+1.5482865*169.7*4.55144e-05*(grx-lasx*1.50094)");
  
  //gROOT->ProcessLine("TFile *_file0 = TFile::Open("output/run4109.root")");
  TFile *_file0 = TFile::Open("output/run4109.root");
  

  TH1F *ht_C = new TH1F("ht_C","ht_C",n_bin,0,50);
  TH1F *hf_C = new TH1F("hf_C","hf_C",n_bin,0,50);
  tree->Draw("sx>>hf_C","abs(dt-775)<20","");
  tree->Draw("sx>>ht_C","abs(dt-845)<20","");
 
   
}
