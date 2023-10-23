std::vector<double> data[5];

void chi2(Int_t &npar, Double_t *gin, Double_t &f, Double_t *par, Int_t iflag){
  int loop =  data[0].size();
  double chisq = 0;
  for(int i=0; i<loop; i++){
    double func = 0;
    func = par[0]+par[1]*data[0][i]+par[2]*data[1][i]+par[3]*data[2][i];
    chisq += pow(data[3][i]-func,2.0);
  }
  
  f = chisq;
}

  
int theta_fit_minuit(){

  /*---------data read-----------*/
  std::string fname ="/home/tsuji/work/art_analysis/e559_23jul/macro/sieve_slit_gr/4040/merged.dat" ;
  std::ifstream infile(fname);
  std::string iline;
  while(getline(infile,iline)){
    std::istringstream line(iline);
    std::string str[8];
    line >> str[0] >> str[1] >> str[2] >> str[3] >> str[4] >> str[5] >> str[6] >> str[7] ;
    data[0].push_back(std::stod(str[4])); //a
    data[1].push_back(std::stod(str[2])); //x
    data[2].push_back(std::stod(str[6])); //y
    data[3].push_back(std::stod(str[0])); //theta
    data[4].push_back(std::stod(str[1])); //phi
  }
  
  
  //TMinuitクラスをインスタンス化
  TMinuit *min = new TMinuit(4);//TMinuit(n) n:パラメータ数
  min->SetPrintLevel(1);
  min->SetFCN(chi2);//最小化する関数をchi2に設定する
  int ierflg = 0;//関数の実行結果を教えてくれる変数(0=通常通りの動作)
  
  //メンバ関数mnparmを用いてパラメータの初期化・微分ステップの設定を行う
  //初期値を設定
  double vstart[4];
  vstart[0] = -2.0;
  vstart[1] = 0.3;
  vstart[2] = 0.0;
  vstart[3] = 0.0;
  
  //ステップ幅
  double step[4];
  step[0] = 0.01;
  step[1] = 0.01;
  step[2] = 0.001;
  step[3] = 0.001;
  
  //引数 : パラメータ番号, パラメータ名, 初期値, ステップ, パラメータの上限, 同下限
  //ierflg=0 if no problems, >0 if MNPARM unable to implement definition
  min->mnparm(0, "p0", vstart[0], step[0], 0, 0, ierflg);
  min->mnparm(1, "p1", vstart[1], step[1], 0, 0, ierflg);
  min->mnparm(2, "p2", vstart[2], step[2], 0, 0, ierflg);
  min->mnparm(3, "p3", vstart[3], step[3], 0, 0, ierflg);
  
  

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
  double par0, par1, par2, par3;
  double par0_err, par1_err, par2_err, par3_err;
  
  min->GetParameter(0,par0,par0_err);
  min->GetParameter(1,par1,par1_err);
  min->GetParameter(2,par2,par2_err);
  min->GetParameter(3,par3,par3_err);
  
  cout<<"**************************************"<<endl;
  cout<<"p0: "<< par0 <<" +/- "<< par0_err <<endl;
  cout<<"p1: "<< par1 <<" +/- "<< par1_err <<endl;
  cout<<"p2: "<< par2 <<" +/- "<< par2_err <<endl;
  cout<<"p3: "<< par3 <<" +/- "<< par3_err <<endl;
  
  
  delete min;
  
  return 0;
}  



