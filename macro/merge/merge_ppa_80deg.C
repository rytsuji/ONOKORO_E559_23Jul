{
  const int n_file=5;
  double scale=-1.0/3.0;
  TFile *file[n_file];
  TDirectoryFile* dir[n_file];
  TH1F* ht[n_file];
  TH1F* ha[n_file];
  TH2F* h_sx_xgr[n_file];
  TString file_root[n_file]={"run4171.hist.root","run4172.hist.root","run4173.hist.root","run4174.hist.root","run4175.hist.root"};
  TString dir_root="output/phys/";
  
  
  for(int i=0;i<n_file;i++){
    //file[i] = TFile::Open(Form("%s%s",dir_root ,file_root[i]));
    file[i] = TFile::Open(dir_root+file_root[i]);
    dir[i] = (TDirectoryFile*)file[i]->Get("phys");
    ht[i] = (TH1F*)dir[i]->Get("sx_tc");
    ha[i] = (TH1F*)dir[i]->Get("sx_ac");
    h_sx_xgr[i] = (TH2F*)dir[i]->Get("sx_xgr");
  }
  
  int nBin=ht[0]->GetXaxis()->GetNbins();
  int xMin=ht[0]->GetXaxis()->GetXmin();
  int xMax=ht[0]->GetXaxis()->GetXmax();
  int GRxBin=h_sx_xgr[0]->GetXaxis()->GetNbins();
  int GRxMin=h_sx_xgr[0]->GetXaxis()->GetXmin();
  int GRxMax=h_sx_xgr[0]->GetXaxis()->GetXmax();
  int SXyBin=h_sx_xgr[0]->GetYaxis()->GetNbins();
  int SXyMin=h_sx_xgr[0]->GetYaxis()->GetXmin();
  int SXyMax=h_sx_xgr[0]->GetYaxis()->GetXmax();

  TH1F *sx_tc=new TH1F("sx_tc", "true coin",nBin,xMin,xMax);
  TH1F *sx_ac=new TH1F("sx_ac", "accidental coin",nBin,xMin,xMax);
  TH1F *sx=new TH1F("sx", "sx",nBin,xMin,xMax);
  TH2F *sx_xgr=new TH2F("sx_xgr", "X GR vs SX",GRxBin,GRxMin,GRxMax,SXyBin,SXyMin,SXyMax);
  
  for(int i=0;i<n_file;i++){
    sx_tc->Add(ht[i],1.0);
    sx_ac->Add(ha[i],1.0);
    sx_xgr->Add(h_sx_xgr[i],1.0);   
  }

  sx->Add(sx_tc,1.0);
  sx->Add(sx_ac,scale);
  
}
