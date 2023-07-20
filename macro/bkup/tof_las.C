void tof_las(Double_t offset){
  
  tree->SetAlias("tof_las",Form("fmod(tref_las.fTiming-rf1.fTiming+%e,71.0)",offset));
  tree->SetAlias("tof_las_2",Form("fmod(tref_las.fTiming-rf1.fTiming+%e,142.0)",offset));

}
