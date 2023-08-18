{

  

  Double_t a_min=33.;
  Double_t a_max=50.;
  
  TCut acut=Form("abs(vdc_gr_m.fA*1000-%e)<%e",(a_min+a_max)/2.,abs(a_max-a_min)/2.);


  //x fitting
  tree->Draw("vdc_gr_m.fX>>hx3(400,-200,200)",acut,"");
  TF1 *g1=new TF1("g1","gaus+[3]+[4]*x",-1000,1000);
  Double_t xc=hx3->GetXaxis()->GetBinCenter((hx3->GetMaximumBin()));
  Double_t x_bc_max= hx3->GetBinContent(hx3->GetMaximumBin());
  g1->SetParameters(x_bc_max,xc,10,0,0);
  TCanvas *c1=new TCanvas("c1","c1",512,512);
  c1->cd();
  hx3->Fit("g1","","",xc-30,xc+50);

  // a fitting
  xc=g1->GetParameter(1);
  Double_t xsigma=g1->GetParameter(2);
  TCut xcut=Form("abs(vdc_gr_m.fX-%e)<%e",xc,3*xsigma);  
  TCanvas *c2=new TCanvas("c2","c2",512,512);
  c2->cd();
  tree->Draw("vdc_gr_m.fA*1000>>ha3(200,-100,100)",xcut,"");
  Double_t ac=ha3->GetXaxis()->GetBinCenter((ha3->GetMaximumBin()));
  Double_t a_bc_max= ha3->GetBinContent(hx3->GetMaximumBin());
  g1->SetParameters(a_bc_max,ac,10,0);
  ha3->Fit("g1","","",ac-5,ac+20);

  //y fitting
    TF1 *f0 = new TF1("f0","([0]/sqrt(2.*TMath::Pi()*[2]*[2]))*exp(-0.5*pow((x-[1])/[2],2))",-50,50);
  TF1 *f1 = new TF1("f1","([0]/sqrt(2.*TMath::Pi()*[2]*[2]))*exp(-0.5*pow((x-[1])/[2],2))",-50,50);
  TF1 *f2 = new TF1("f2","([0]/sqrt(2.*TMath::Pi()*[2]*[2]))*exp(-0.5*pow((x-[1])/[2],2))",-50,50);
  TF1 *f3 = new TF1("f3","([0]/sqrt(2.*TMath::Pi()*[2]*[2]))*exp(-0.5*pow((x-[1])/[2],2))",-50,50);
  //TF1 *f4 = new TF1("f4","([0]/sqrt(2.*TMath::Pi()*[2]*[2]))*exp(-0.5*pow((x-[1])/[2],2))",-50,50);
  //TF1 *g5 = new TF1("g5","f0+f1+f2+f3+f4+[15]+[16]*x+[17]*x*x",-50,50);
  TF1 *g4 = new TF1("g4","f0+f1+f2+f3+[12]+[13]*x+[14]*x*x",-50,50);


  Double_t ysigma=2.0;
  Double_t yc[4]={-7.5, -2.5, 5.0, 12.5};
  Double_t yh[4]={1000.,1000.,1000., 1000.};
  
  for(int i=0;i<4;i++){
    g4->SetParameter(3*i,yh[i]);
    g4->SetParameter(3*i+1,yc[i]);
    g4->SetParameter(3*i+2,ysigma);
    
  }
  
  g4->SetParameter(12,0);
  g4->SetParameter(13,0);
  g4->SetParameter(14,0);
  
  TCanvas *c3=new TCanvas("c3","c3",512,512);
  c3->cd();
  tree->Draw("vdc_gr_m.fY>>hy(300,-50,100)",acut && xcut,"");  
  hy->Fit("g4","","",-15,30);  



  
  




  
}
