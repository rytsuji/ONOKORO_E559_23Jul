{

  TChain *tree= new TChain("tree", "");

  tree->Add("output/run4043.root");
  tree->Add("output/run4044.root");

  TFile *chain = new TFile("output/run4043-4044.root","RECREATE");
  tree->Write();
  chain->Close();
  
}
