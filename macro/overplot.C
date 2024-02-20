{

  
  TFile *file0 = TFile::Open("output/run4207.root"); //1つ目のfileを開く
  TH1F *h1=new TH1F("h1","",1200,-600,600); //1つ目のhistを定義
  h1->SetLineColor(kBlue); //histの色を青に
  tree->Draw("vdc_gr_m.fX>>h1","",""); //Draw
  h1->Scale(0.5); //histを0.5倍に

  TFile *file1 = TFile::Open("output/run4208.root"); //2つ目のfileを開く
  TH1F *h2=new TH1F("h2","",1200,-600,600);//2つ目のhistを定義
  h2->SetLineColor(kRed);//histの色を赤に
  tree->Draw("vdc_gr_m.fX>>h2","",""); //Draw
  h2->Scale(0.8); //histを0.8倍に
  
  TCanvas *c1=new TCanvas("c1","");
  h1->Draw(); //Canvas cvにh1を描く
  h2->Draw("same") //Canvas cvにh2を重ね描き


}
