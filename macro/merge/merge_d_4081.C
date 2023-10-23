{

  TChain *tree= new TChain("tree", "");

  tree->Add("output/run4081.root");
  tree->Add("output/run4082.root");
  tree->Add("output/run4083.root");
  tree->Add("output/run4084.root");
  tree->Add("output/run4085.root");

  TFile *chain = new TFile("output/Ca_ppd_merge.root","RECREATE");
  tree->Write();
  chain->Close();
  
}
