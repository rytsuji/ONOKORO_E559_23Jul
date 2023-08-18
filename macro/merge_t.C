{

  TChain *tree= new TChain("tree", "");

  tree->Add("output/run4118.root");
  tree->Add("output/run4119.root");
  tree->Add("output/run4120.root");
  tree->Add("output/run4121.root");


  TFile *chain = new TFile("output/Ca_ppt_merge.root","RECREATE");
  tree->Write();
  chain->Close();
  
}
