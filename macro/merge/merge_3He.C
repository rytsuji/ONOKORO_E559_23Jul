{

  TChain *tree= new TChain("tree", "");

  tree->Add("output/run4191.root");
  tree->Add("output/run4192.root");
  tree->Add("output/run4193.root");
  tree->Add("output/run4194.root");
  tree->Add("output/run4195.root");
  tree->Add("output/run4196.root");

  TFile *chain = new TFile("output/Ca_pph_merge.root","RECREATE");
  tree->Write();
  chain->Close();
  
}
