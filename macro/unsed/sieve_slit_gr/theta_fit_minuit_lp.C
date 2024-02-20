std::vector<double> data[6];

void chi2(Int_t &npar, Double_t *gin, Double_t &f, Double_t *par, Int_t iflag){
  int loop =  data[0].size();
  double chisq = 0;
  for(int i=0; i<loop; i++){
    double func1 = 0;
    double func2 = 0;
    double func3 = 0;
    func1 = par[0]+par[1]*data[0][i]+par[2]*data[1][i];   
    //func2 = par[4]+par[1]*pow(data[0][i],2)+par[5]*pow(data[1][i],2)+par[6]*pow(data[2][i],2);
    //func3 = par[7]*data[0][i]*data[1][i]+par[8]*data[1][i]*data[2][i]+par[8]*data[2][i]*data[0][i];
    std::vector<Double_t> a;
    std::string fname1 ="/home/tsuji/work/art_analysis/e559_23jul/macro/sieve_slit_gr/gr_theta_calib.dat" ;
    std::ifstream infile1(fname1);
    std::string iline1;
    while(getline(infile1,iline1)){
      std::istringstream line(iline1);
      std::string str[2];
      line >> str[0] >>str[1];
      a.push_back(std::stod(str[0]));
    }

    double val1 = a[0]+a[1]*data[0][i]+a[2]*data[1][i];
    //if(abs(data[4][i]-val1)<0.5){
    chisq += pow(data[4][i]-func1-func2-func3,2.0);
    // }
  }
  f = chisq;
}

  
int theta_fit_minuit_lp(){
  
  /*---------data read-----------*/
  std::string fname ="/home/tsuji/work/art_analysis/e559_23jul/macro/sieve_slit_gr/merged.dat" ;
  std::ifstream infile(fname);
  std::string iline;
  while(getline(infile,iline)){
    std::istringstream line(iline);
    std::string str[10];
    line >> str[0] >> str[1] >> str[2] >> str[3] >> str[4] >> str[5] >> str[6] >> str[7] >> str[8] >> str[9] ;
    data[0].push_back(std::stod(str[4])); //a
    data[1].push_back(std::stod(str[2])); //x
    data[2].push_back(std::stod(str[6])); //y
    data[3].push_back(std::stod(str[8])); //b
    data[4].push_back(std::stod(str[0])); //theta
    data[5].push_back(std::stod(str[1])); //phi
  }
  
  
  //TMinuitクラスをインスタンス化
  TMinuit *min = new TMinuit(3);//TMinuit(n) n:パラメータ数
  min->SetPrintLevel(1);
  min->SetFCN(chi2);//最小化する関数をchi2に設定する
  int ierflg = 0;//関数の実行結果を教えてくれる変数(0=通常通りの動作)
  
  //メンバ関数mnparmを用いてパラメータの初期化・微分ステップの設定を行う
  //初期値を設定
  double vstart[3];
  for(int i=0;i<3;i++){
    vstart[i] = 0.0;
  }

  vstart[0]=0.362231;
  vstart[1]=-0.0207291;
  vstart[2]=-2.82044;

  
  //ステップ幅
  double step[3];
  for(int i=0;i<3;i++){
    step[i] = 0.001;
  }
  
  //引数 : パラメータ番号, パラメータ名, 初期値, ステップ, パラメータの上限, 同下限
  //ierflg=0 if no problems, >0 if MNPARM unable to implement definition
  for(int i=0;i<3;i++){
    min->mnparm(i, Form("p%d",i), vstart[i], step[i], 0, 0, ierflg);
  }
  
  

  //最小化に必要な設定は、メンバ関数mnexcmを通して行う
  //mnexcmの引数 ： コマンド名、引数が入った配列、配列内の値の数、ierflg
  
  double arglist[10];//mnexcmのための引数を入れておく配列(適当に10個分用意)
  
  //1σを与えるカイ2乗値の増分を設定
  arglist[0] = 3.53;//1パラメータ:1.0, 2パラメータ:2.30
  min->mnexcm("SET ERR", arglist, 1, ierflg);

  //最小化アルゴリズムをMIGRAD(DFP法)に設定し、実行
  arglist[0] = 1000;//引数1:maxcalls
  arglist[1] = 1;//引数2:tolerance
  min->mnexcm("MIGRAD", arglist, 2, ierflg);
  
  
  //fit結果を入れておくための変数
  TString oname="/home/tsuji/work/art_analysis/e559_23jul/macro/sieve_slit_gr/gr_theta_calib.dat"; 
  ofstream ofile((std::string) oname);
  
  double par[3];
  double par_err[3];

  cout<<"**************************************"<<endl;
  for(int i=0;i<3;i++){
    min->GetParameter(i,par[i],par_err[i]);
    cout<<"p" << i << ": "<< par[i] <<" +/- "<< par_err[i] <<endl;
    ofile << par[i] << " " << par_err[i] << std::endl;
  }
  ofile.close();


  TH1F *hist = new TH1F("hist","hist",500,-10,10);
  TH2F *ht = new TH2F("ht","ht",100,-100,100,500,-10,10);
  TH2F *hx = new TH2F("hx","hx",600,-600,600,500,-10,10);
  TH2F *hy = new TH2F("hy","hy",100,-100,100,500,-10,10);
  TH2F *ha = new TH2F("ha","ha",100,-100,100,500,-10,10);
  TH2F *hb = new TH2F("hb","hb",100,-100,100,500,-10,10);
  
  int loop =  data[0].size();
  for(int i=0;i<loop;i++){
    
    Double_t val1 = par[0]+par[1]*data[0][i]+par[2]*data[1][i];
    // Double_t val2 = par[4]+par[1]*pow(data[0][i],2)+par[5]*pow(data[1][i],2)+par[6]*pow(data[2][i],2);
    //Double_t val3 = par[7]*data[0][i]*data[1][i]+par[8]*data[1][i]*data[2][i]+par[8]*data[2][i]*data[0][i]; 
    //hist->Fill(val1+val2+val3-data[3][i]);
    hist->Fill(data[4][i]-val1);
    ht->Fill(data[4][i],data[4][i]-val1);
    hx->Fill(data[1][i],data[4][i]-val1);
    hy->Fill(data[2][i],data[4][i]-val1);
    ha->Fill(data[0][i],data[4][i]-val1); 
    hb->Fill(data[3][i],data[4][i]-val1); 
  }

  hist->Draw();
  
  delete min;
  
  return 0;
}  



