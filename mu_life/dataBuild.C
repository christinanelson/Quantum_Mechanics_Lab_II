//Physics 481L 
//February 10, 2017

TFile *dataBuild(Int_t print=1, Int_t get=0) {

   Int_t pulseAmplitude;

   //Txt file from data taken is SOLyama2.txt
   // reads in txt file and changes it to a root file.
   TString filename = "mu_021317_1232.root";
   TString dir = gSystem->UnixPathName(__FILE__);
   dir.ReplaceAll("dataBuild.C","");
   dir.ReplaceAll("/./","/");
   FILE *fp = fopen(Form("%smu_021317_1232.txt",dir.Data()),"r");

   TFile *hfile = 0;
   if (get) {
      // if the argument get =1 return the file "data.root"
      // if the file does not exist, it is created
      if (!gSystem->AccessPathName(dir+"mu_021317_1232.root",kFileExists)) {
         hfile = TFile::Open(dir+"mu_021317_1232.root"); //in $root/lab2_vc
         if (hfile) return hfile;
      }
      //otherwise try $PWD/data.root
      if (!gSystem->AccessPathName("mu_021317_1232.root",kFileExists)) {
         hfile = TFile::Open("mu_021317_1232.root"); //in current dir
         if (hfile) return hfile;
      }
   }
   //no data.root file found. Must generate it !
   //generate data.root in $root/lab2_vc if we have write access
   if (gSystem->AccessPathName(".",kWritePermission)) {
      printf("you must run the script in a directory with write access\n");
      return 0;
   }
   hfile = TFile::Open(filename,"RECREATE");
   TTree *tree = new TTree("T","Spectroscopy : Data");
   tree->Branch("pulseAmplitude",&pulseAmplitude,"pulseAmplitude/I");
 
   char line[12];
   while (fgets(line,12,fp)) {
     sscanf(&line[0],"%d",&pulseAmplitude);
      tree->Fill();
   }
   tree->StartViewer();

   if (print) tree->Print();
   tree->Write();

   fclose(fp);
   delete hfile;
   if (get) {
      //we come here when the script is executed outside $root/lab2_vc
      hfile = TFile::Open(filename);
      return hfile;
   }
   return 0;
}
