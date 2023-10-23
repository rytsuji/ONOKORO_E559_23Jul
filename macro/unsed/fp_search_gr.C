{

  const Int_t n = 20;
  Double_t x[n] = {0}, y[n] = {0};
  TH1F *h0[n];
  TH1F *h1[n];
  
  Double_t a_min=-3.;
  Double_t a_max=15.;
  TCut acut0=Form("abs(vdc_gr_m.fA*1000-%e)<%e",(a_min+a_max)/2.,abs(a_max-a_min)/2.);
  a_min=-20.;
  a_max=-2.;
  TCut acut1=Form("abs(vdc_gr_m.fA*1000-%e)<%e",(a_min+a_max)/2.,abs(a_max-a_min)/2.);

  
  for (Int_t i=0;i<n;++i) {

    Double_t z=-1000.-i*100.;
    h0[i]=new TH1F(Form("h0[%d]",i),Form("h0[%d]",i),400,-200,200);
    tree->Draw(Form("vdc_gr_m.GetX(%e)>>h0[%d]",z,i),acut0,"");
    Double_t xc0=h0[i]->GetXaxis()->GetBinCenter((h0[i]->GetMaximumBin()));
    Double_t hmax0= h0[i]->GetBinContent(h0[i]->GetMaximumBin());
    TF1 *g1=new TF1("g1","gaus+[3]+[4]*x",-1000,1000);
    g1->SetParameters(hmax0,xc0,10,0);
    h0[i]->Fit("g1","","",xc0-50,xc0+50);
    Double_t m0=g1->GetParameter(1);
    Double_t s0=g1->GetParameter(2);

    h1[i]=new TH1F(Form("h1[%d]",i),Form("h1[%d]",i),400,-200,200);
    tree->Draw(Form("vdc_gr_m.GetX(%e)>>h1[%d]",(Double_t) 1500-100*i,i),acut1,"");
    Double_t xc1=h1[i]->GetXaxis()->GetBinCenter((h1[i]->GetMaximumBin()));
    Double_t hmax1= h1[i]->GetBinContent(h1[i]->GetMaximumBin());
    //TF1 *g1=new TF1("g1","gaus+[3]+[4]*x",-1000,1000);
    g1->SetParameters(hmax1,xc1,10,0);
    h1[i]->Fit("g1","","",xc1-50,xc1+50);
    Double_t m1=g1->GetParameter(1);
    Double_t s1=g1->GetParameter(2);
   
    x[i] = z;
    y[i] = (m1-m0)/(abs(s1)+abs(s0));
  }
  
  TGraph *gr = new TGraph(n,x,y);
  gr -> SetMarkerStyle(4); 
  gr -> SetMarkerColor(4);  
  gr -> SetMarkerSize(0.5); 
  gr->Draw("AP");
    
}
