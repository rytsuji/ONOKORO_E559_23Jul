{
  const int n_file=3;
  double scale=-1.0/9.0;
  TFile *file[n_file];
  TDirectoryFile* dir[n_file];
  TH1F* ht[n_file];
  TH1F* ha[n_file];
  //TString file_root[n_file]={"run4131.hist.root","run4132.hist.root","run4139.hist.root","run4140.hist.root","run4141.hist.root"};
  TString file_root[n_file]={"run4139.hist.root","run4140.hist.root","run4141.hist.root"};
  TString dir_root="output/phys/";
  
  
  for(int i=0;i<n_file;i++){
    //file[i] = TFile::Open(Form("%s%s",dir_root ,file_root[i]));
    file[i] = TFile::Open(dir_root+file_root[i]);
    dir[i] = (TDirectoryFile*)file[i]->Get("phys");
    ht[i] = (TH1F*)dir[i]->Get("sx_tc");
    ha[i] = (TH1F*)dir[i]->Get("sx_ac");
  }
  
  int nBin=ht[0]->GetXaxis()->GetNbins();
  int xMin=ht[0]->GetXaxis()->GetXmin();
  int xMax=ht[0]->GetXaxis()->GetXmax();
  TH1F *sx_tc=new TH1F("sx_tc", "true coin",nBin,xMin,xMax);
  TH1F *sx_ac=new TH1F("sx_ac", "accidental coin",nBin,xMin,xMax);
  TH1F *sx=new TH1F("sx", "sx",nBin,xMin,xMax);  
  for(int i=0;i<n_file;i++){
    sx_tc->Add(ht[i],1.0);
    sx_ac->Add(ha[i],1.0);
  }

  sx->Add(sx_tc,1.0);
  sx->Add(sx_ac,scale);
}
