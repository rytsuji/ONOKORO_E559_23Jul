{

  TChain *tree= new TChain("tree", "");

  tree->Add("output/run4045.root");
  tree->Add("output/run4046.root");

  TFile *chain = new TFile("output/run4045-4046.root","RECREATE");
  tree->Write();
  chain->Close();
  
}
