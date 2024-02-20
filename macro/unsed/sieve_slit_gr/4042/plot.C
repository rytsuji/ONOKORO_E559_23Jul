{

  std::vector<double> data[5];
  
  std::string fname ="/home/tsuji/work/art_analysis/e559_23jul/macro/sieve_slit_gr/4040/merged.dat" ;
  std::ifstream infile(fname);
  std::string iline;
  while(getline(infile,iline)){
    std::istringstream line(iline);
    std::string str[8];
    line >> str[0] >> str[1] >> str[2] >> str[3] >> str[4] >> str[5] >> str[6] >> str[7] ;
    data[0].push_back(std::stod(str[2]));
    data[1].push_back(std::stod(str[4]));
    data[2].push_back(std::stod(str[6]));
    data[3].push_back(std::stod(str[0]));
    data[4].push_back(std::stod(str[1]));
  }

  //const int n =  data[0].size(); 
  n=15;
  double x[15];
  double y[15];

  
  for(int i=0; i < n; i++){    
    x[i] = data[1].at(i);
    y[i] = data[2].at(i);
  }
  

  TGraph *g1 = new TGraph(n,x,y);
  g1->SetTitle("Graph title;X title;Y title");
  g1->Draw("*");  
}

  
  
  

