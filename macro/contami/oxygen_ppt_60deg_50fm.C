{
  double ratio = 0.428;
  double BC_mylar=164006.2;
  double BC_carbon=160961.4;
  double scale=-1.0/9.0;

  TFile *file_mylar = TFile::Open("output/phys/run4203.hist.root");
  TDirectoryFile* dir_mylar = (TDirectoryFile*)file_mylar->Get("phys");
  TH1F* ht_mylar=(TH1F*)dir_mylar->Get("sx_tc");
  TH1F* ha_mylar=(TH1F*)dir_mylar->Get("sx_ac");

  
  TFile *file_carbon = TFile::Open("output/phys/run4204.hist.root");
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
  sx_oxygen->Add(sx_carbon,-ratio * BC_mylar/BC_carbon);   
  sx_carbon->Scale(ratio * BC_mylar/BC_carbon);  
  
}
