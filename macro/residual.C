{
  TF1 *g1 = new TF1("g1","([0]/sqrt(2.*TMath::Pi()*[2]*[2]))*exp(-0.5*pow((x-[1])/[2],2))",-600,600);
  g1->SetParameter(0,1000);
  g1->FixParameter(1,0);
  g1->SetParameter(2,4);
  // gROOT->ProcessLine("cd");
  //gROOT->ProcessLine("cd 19");
  //gROOT->ProcessLine("ht 6");
  //gROOT->ProcessLine("ssr->Fit(\"g1\")");

  //std::cout << "residual :" << g1->GetParameter(2) << std::endl;;

}
