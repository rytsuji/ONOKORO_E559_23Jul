{
  double ratio_c = 0.428;
  double ratio_o = 0.285;
  double BC_mylar=592462.*0.2;
  double BC_carbon=560170.*0.2;
  double BC_ca=0.2*(1223671.+1182752.+1117217.+960030.+761696.+322288.);
  double scale=-1.0/12.0;
  
  TFile *file_mylar = TFile::Open("output/phys/run4126.hist.root");
  TDirectoryFile* dir_mylar = (TDirectoryFile*)file_mylar->Get("phys");
  TH1F* ht_mylar=(TH1F*)dir_mylar->Get("sx_tc");
  TH1F* ha_mylar=(TH1F*)dir_mylar->Get("sx_ac");

  
  TFile *file_carbon = TFile::Open("output/phys/run4125.hist.root");
  TDirectoryFile* dir_carbon = (TDirectoryFile*)file_carbon->Get("phys");
  TH1F* ht_carbon=(TH1F*)dir_carbon->Get("sx_tc");
  TH1F* ha_carbon=(TH1F*)dir_carbon->Get("sx_ac");



  
  int nBin=ht_mylar->GetXaxis()->GetNbins();
  int xMin=ht_mylar->GetXaxis()->GetXmin();
  int xMax=ht_mylar->GetXaxis()->GetXmax();

  TH1F *sx_mylar=new TH1F("sx_mylar", "",nBin,xMin,xMax);  
  sx_mylar->Add(ht_mylar,1.0);
  sx_mylar->Add(ha_mylar,scale);
  
  TH1F *sx_tc_carbon=new TH1F("sx_tc_carbon", "",nBin,xMin,xMax);
  TH1F *sx_ac_carbon=new TH1F("sx_ac_carbon", "",nBin,xMin,xMax);
  TH1F *sx_carbon=new TH1F("sx_carbon", "",nBin,xMin,xMax);  
  sx_carbon->Add(ht_carbon,1.0);
  sx_carbon->Add(ha_carbon,scale);

  
  TH1F *sx_oxygen=new TH1F("sx_oxygen", "",nBin,xMin,xMax);  
  sx_oxygen->Add(sx_mylar,1.0);
  sx_oxygen->Add(sx_carbon,-ratio_c * BC_mylar/BC_carbon);   
  sx_carbon->Scale(ratio_c * BC_mylar/BC_carbon);  


  const int n_file=6;
  TFile *file[n_file];
  TDirectoryFile* dir[n_file];
  TH1F* ht[n_file];
  TH1F* ha[n_file];
  //TString file_root[n_file]={"run4131.hist.root","run4132.hist.root","run4139.hist.root","run4140.hist.root","run4141.hist.root"};                          
  TString file_root[n_file]={"run4118.hist.root",
			     "run4119.hist.root",
			     "run4120.hist.root",
			     "run4121.hist.root",
			     "run4122.hist.root",
			     "run4123.hist.root"};

  TString dir_root="output/phys/";
  
  for(int i=0;i<n_file;i++){
    //file[i] = TFile::Open(Form("%s%s",dir_root ,file_root[i]));                                                                                             
    file[i] = TFile::Open(dir_root+file_root[i]);
    dir[i] = (TDirectoryFile*)file[i]->Get("phys");
    ht[i] = (TH1F*)dir[i]->Get("sx_tc");
    ha[i] = (TH1F*)dir[i]->Get("sx_ac");
  }


  //int nBin=ht[0]->GetXaxis()->GetNbins();
  //int xMin=ht[0]->GetXaxis()->GetXmin();
  //int xMax=ht[0]->GetXaxis()->GetXmax();
  TH1F *sx_tc=new TH1F("sx_tc", "true coin",nBin,xMin,xMax);
  TH1F *sx_ac=new TH1F("sx_ac", "accidental coin",nBin,xMin,xMax);
  TH1F *sx_cao=new TH1F("sx_cao", "sx_cao",nBin,xMin,xMax);
  for(int i=0;i<n_file;i++){
    sx_tc->Add(ht[i],1.0);
    sx_ac->Add(ha[i],1.0);
  }

  sx_cao->Add(sx_tc,1.0);
  sx_cao->Add(sx_ac,scale);

  TH1F *sx_ca=new TH1F("sx", "sx",nBin,xMin,xMax);
  sx_ca->Add(sx_cao,1.0);
  sx_ca->Add(sx_oxygen,-ratio_o * BC_ca/BC_mylar);   
  sx_oxygen->Scale(ratio_o * BC_ca/BC_mylar);  
   
  
}
