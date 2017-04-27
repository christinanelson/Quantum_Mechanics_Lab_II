#include <iostream>
#include <fstream>

void PulseHeightCounts()

{

  TFile *f = new TFile("mu_021017_1253.root");
  TH1F *h1p = (TH1F*) f->Get("h1") ;
  std::string name0 = "h";
  std::string next0;

  Int_t bins = h1p->GetSize();
  //  cout << bins;

  for (int i = 2; i < 101; i++){
    next0 = name0 + std::to_string(i);
    const char * c0 = next0.c_str();
    TH1F *hp = (TH1F*) f->Get(c0);
    //h1p->Add(hp);
  }

  ofstream myfile;
  myfile.open("countPulseHeight.txt");
  //myfile << "TS ns nserr\n";

  /*TH1F *hnorm = new TH1F("PMT ZQ2736", "PMT ZQ2736", 504, -0.0000001, 0.0000001);*/
  for(Int_t  j=1; j<502; j++)
    {
      Float_t y = h1p->GetBinContent(j);
      cout<<y;
      cout<<"\n";
      myfile<<y<<"\n";
      //Double_t x = h1p->GetXaxis()->GetBinCenter(j);
      //   Float_t x = h1p->GetYaxis()->GetBinCenter(j);                                  
      //Float_t ySet = y + 0.03;
      //hnorm->SetBinContent(j, ySet);
    }

  myfile.close();
  //  Float_t min = hnorm->GetMinimum();

  
}
