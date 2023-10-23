{

  TChain *tree= new TChain("tree", "");

  tree->Add("output/run4171.root");
  tree->Add("output/run4172.root");
  tree->Add("output/run4173.root");
  tree->Add("output/run4174.root");
  tree->Add("output/run4175.root");

  TFile *chain = new TFile("output/Ca_ppa_merge.root","RECREATE");
  tree->Write();
  chain->Close();
  
}
