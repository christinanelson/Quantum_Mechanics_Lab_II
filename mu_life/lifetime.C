#include "TH1F.h"
#include "TCanvas.h"
#include "TFile.h"
#include "TTreeReader.h"
#include "TTreeReaderValue.h"

class TVirtualPad;


void lifetime() {

  TCanvas * c1 = new TCanvas("c1", "pulseA",1300,1400,2000,1300);
  
  // Create a histogram for the values we read.                                        
  TH1F *myHist = new TH1F("#mu^{-} #rightarrow e^{-} + #bar{#nu}_{e} + #nu_{#mu}",
			  "#mu^{-} lifetime spectra", 64, -5, 25);

  TFile *mu4 = TFile::Open("mu_021317_1232.root");

  if (!mu4 || mu4->IsZombie()) {
    return;
  }

  TTreeReader myReader("T", mu4);
  TTreeReaderValue<Int_t> mypulseAmplitude(myReader, "pulseAmplitude");
  const int nBins = 2049;
  Int_t count = 0;
  Int_t i = 0;
  while (myReader.Next()) {
    count ++;
    Double_t data[nBins]={static_cast<Double_t>(*mypulseAmplitude)};
    //myHist->Fill(count, data[i]);
    myHist->Fill((count*0.01087)-0.1955, data[i]/4);
  }

  //for(int i=0; i < myHist->GetNbinsX(); i++){
  //Float_t err = myHist->GetBinContent(i);
  //myHist->SetBinError(i, myHist->GetBinError(i)/2);
    //myHist->SetBinError(i, sqrt(err));
  //}

  gStyle->SetOptStat(000);
  myHist->Draw();
  myHist->Fit("expo");

  myHist->GetYaxis()->SetTitle("Counts");
  myHist->GetXaxis()->SetTitle("#mu s");

  c1->SetLogy();
  //c1->SaveAs("mu_chexp.eps");
}



