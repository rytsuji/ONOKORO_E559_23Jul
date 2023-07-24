using art::TVDCTrackingSortProcessor;

ClassImp(TVDCTrackingSortProcessor)

TVDCTrackingSortProcessor::TVDCTrackingSortProcessor() : fOutput(NULL)
{


  RegisterInputCollection("InputCollection1",
			  "input collection1"
			  fNameInput1, "vdc_clust_x1",
			  &fInput1, TClonesArray::Class_Name(),
			  art::TVDCCluster::Class_Name());

  RegisterInputCollection("InputCollection2",
			  "input collection2"
			  fNameInput1, "vdc_clust_x2",
			  &fInput1, TClonesArray::Class_Name(),
			  art::TVDCCluster::Class_Name());

    RegisterInputCollection("InputCollection3",
			  "input collection3"
			  fNameInput1, "vdc_clust_u1",
			  &fInput1, TClonesArray::Class_Name(),
			  art::TVDCCluster::Class_Name());

  RegisterInputCollection("InputCollection4",
			  "input collection4"
			  fNameInput1, "vdc_clust_u2",
			  &fInput1, TClonesArray::Class_Name(),
			  art::TVDCCluster::Class_Name());

    RegisterInputCollection("InputCollection5",
			  "input collection5"
			  fNameInput1, "vdc_clust_v1",
			  &fInput1, TClonesArray::Class_Name(),
			  art::TVDCCluster::Class_Name());

  RegisterInputCollection("InputCollection6",
			  "input collection6"
			  fNameInput1, "vdc_clust_v2",
			  &fInput1, TClonesArray::Class_Name(),
			  art::TVDCCluster::Class_Name());

    

  
  RegisterInputCollection("InputCollection7",
			  "input collection7"
			  fNameInput1, "vdc_xxuuvv",
			  &fInput1, TClonesArray::Class_Name(),
			  art::TMWDCTrackingResult::Class_Name());

  RegisterInputCollection("InputCollection8",
			  "input collection8"
			  fNameInput1, "vdc_uuvv",
			  &fInput1, TClonesArray::Class_Name(),
			  art::TMWDCTrackingResult::Class_Name());

    RegisterInputCollection("InputCollection9",
			  "input collection9"
			  fNameInput1, "vdc_xxvv",
			  &fInput1, TClonesArray::Class_Name(),
			  art::TMWDCTrackingResult::Class_Name());

    RegisterInputCollection("InputCollection10",
			    "input collection10"
			    fNameInput1, "vdc_xxuu",
			    &fInput1, TClonesArray::Class_Name(),
			    art::TMWDCTrackingResult::Class_Name());
}

TVDCTrackingSortProcessor::~TVDCTrackingSortProcessor()
{
  delete fOutput;
}

void TVDCTrackingSortProcessor::Init(TEventCollection *col)
{
  
}

void TVDCTrackingSortProcessor::Process()
{
  fOutput->Clear("C");
  
  TVDCluster* clust_x1 = <TSiPlaneData*> ((*fInput1)->At(0));   
  
  


}
					 






