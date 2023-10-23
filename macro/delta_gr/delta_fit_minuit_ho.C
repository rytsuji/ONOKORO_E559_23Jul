std::vector<double> data[4];


void chi2(Int_t &npar, Double_t *gin, Double_t &f, Double_t *par, Int_t iflag){
  int loop =  data[0].size();
  double chisq = 0;
  for(int i=0; i<loop; i++){
    double func = 0;
    for(int n=0;n<5;n++){
      for(int m=0;m<5;m++){
	func += par[5*n+m]*pow(data[0][i],n)*pow(data[1][i],m);
      }
    }
    
    /*
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
    */
    //double val1 = a[0]+a[1]*data[0][i]+a[2]*data[1][i];
    //if(abs(data[4][i]-val1)<0.5){
    chisq += pow(data[2][i]-func,2.0);
    // }
    
  }
  f = chisq;
}

  
int delta_fit_minuit_ho(){
  
  /*---------data read-----------*/
  std::string fname ="/home/tsuji/work/art_analysis/e559_23jul/macro/delta_gr/merged.dat";
  std::ifstream infile(fname);
  std::string iline;
  while(getline(infile,iline)){
    std::istringstream line(iline);
    std::string str[4];
    line >> str[0] >> str[1] >> str[2] >> str[3];
    data[0].push_back(std::stod(str[0])); //x
    data[1].push_back(std::stod(str[1])); //a
    data[2].push_back(std::stod(str[2])); //delta
    data[3].push_back(std::stod(str[3])); //theta
  }
  
  
  //TMinuitクラスをインスタンス化
  TMinuit *min = new TMinuit(25);//TMinuit(n) n:パラメータ数
  min->SetPrintLevel(1);
  min->SetFCN(chi2);//最小化する関数をchi2に設定する
  int ierflg = 0;//関数の実行結果を教えてくれる変数(0=通常通りの動作)
  
  //メンバ関数mnparmを用いてパラメータの初期化・微分ステップの設定を行う
  //初期値を設定
  double vstart[25];
  for(int i=0;i<25;i++){
    vstart[i] = 0.0;
  }

  vstart[0]=-0.0058425;
  vstart[1]=3.58724e-05 ;
  vstart[2]=-6.73091e-08;
  vstart[3]=-3.4591e-09 ;
  vstart[4]=-2.37443e-11;
  vstart[5]=4.11251e-05;
  vstart[6]=1.14233e-07;
  vstart[7]=2.33539e-09;
  
  //ステップ幅
  double step[25];
  for(int i=0;i<25;i++){
    step[i] = 0.001;
  }
  
  //引数 : パラメータ番号, パラメータ名, 初期値, ステップ, パラメータの上限, 同下限
  //ierflg=0 if no problems, >0 if MNPARM unable to implement definition
  for(int i=0;i<25;i++){
    min->mnparm(i, Form("p%d",i), vstart[i], step[i], 0, 0, ierflg);
  }
  
  

  //最小化に必要な設定は、メンバ関数mnexcmを通して行う
  //mnexcmの引数 ： コマンド名、引数が入った配列、配列内の値の数、ierflg
  
  double arglist[20];//mnexcmのための引数を入れておく配列(適当に10個分用意)
  
  //1σを与えるカイ2乗値の増分を設定
  arglist[0] = 3.53;//1パラメータ:1.0, 2パラメータ:2.30
  min->mnexcm("SET ERR", arglist, 1, ierflg);

  //最小化アルゴリズムをMIGRAD(DFP法)に設定し、実行
  arglist[0] = 1000;//引数1:maxcalls
  arglist[1] = 1;//引数2:tolerance
  min->mnexcm("MIGRAD", arglist, 2, ierflg);
  
  
  //fit結果を入れておくための変数
  TString oname="/home/tsuji/work/art_analysis/e559_23jul/macro/delta_gr/gr_delta_calib.dat"; 
  ofstream ofile((std::string) oname);
  
  double par[25];
  double par_err[25];

  cout<<"**************************************"<<endl;
  for(int i=0;i<25;i++){
    min->GetParameter(i,par[i],par_err[i]);
    cout<<"p" << i << ": "<< par[i] <<" +/- "<< par_err[i] <<endl;
    ofile << par[i] << " " << par_err[i] << std::endl;
  }
  ofile.close();


  TH1F *hist = new TH1F("hist","hist",500,-0.01,0.01);
  TH2F *ht = new TH2F("ht","ht",100,-100,100,500,-0.01,0.01);
  TH2F *hx = new TH2F("hx","hx",600,-600,600,500,-0.01,0.01);
  TH2F *ha = new TH2F("ha","ha",100,-100,100,500,-0.01,0.01);
  TH2F *hd = new TH2F("hd","hd",100,-100,-3,3,-0.01,0.01);
  
  int loop =  data[0].size();
  for(int i=0;i<loop;i++){
    
    Double_t val=0;
    
    for(int n=0;n<5;n++){
      for(int m=0;m<5;m++){
	val += par[5*n+m]*pow(data[0][i],n)*pow(data[1][i],m);
      }
    }
    hist->Fill(data[2][i]-val);
    ht->Fill(data[3][i],data[2][i]-val);
    hx->Fill(data[0][i],data[2][i]-val);
    ha->Fill(data[1][i],data[2][i]-val);
    hd->Fill(data[2][i],data[2][i]-val); 
  }

  hist->Draw();
  
  delete min;
  
  return 0;
}  



