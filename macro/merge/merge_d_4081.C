{

  TChain *tree= new TChain("tree", "");

  tree->Add("output/phys/run4081.root");
  tree->Add("output/phys/run4082.root");
  tree->Add("output/phys/run4083.root");
  tree->Add("output/phys/run4084.root");
  tree->Add("output/phys/run4085.root");

  TFile *chain = new TFile("output/phys/Ca_ppd_75_merge.root","RECREATE");
  tree->Write();
  chain->Close();
  
}
