{





  tree->SetAlias("las_x1.IsUsed","vdc_las_m.GetNPlaneValid()&0x01");
  tree->SetAlias("las_u1.IsUsed","(vdc_las_m.GetNPlaneValid()>>1)&0x01");
  tree->SetAlias("las_v1.IsUsed","(vdc_las_m.GetNPlaneValid()>>2)&0x01");
  tree->SetAlias("las_x2.IsUsed","(vdc_las_m.GetNPlaneValid()>>3)&0x01");
  tree->SetAlias("las_u2.IsUsed","(vdc_las_m.GetNPlaneValid()>>4)&0x01");
  tree->SetAlias("las_v2.IsUsed","(vdc_las_m.GetNPlaneValid()>>5)&0x01");
  //tree->Setalias("vdc_las_u2.UsedPlanennum","(vdc_las_m.GetNPlaneValid()>>4)&0x01");












}
