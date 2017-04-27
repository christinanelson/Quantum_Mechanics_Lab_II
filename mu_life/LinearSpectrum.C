#include "TH1F.h"
#include "TCanvas.h"
#include "TFile.h"
#include "TTreeReader.h"
#include "TTreeReaderValue.h"

class TVirtualPad;

void LinearSpectrum() {

  TCanvas * c1 = new TCanvas("c1", "pulseA",1300,1400,2000,1300);
  
  // Create a histogram for the values we read.                                        
  TH1F *myHist = new TH1F("#mu^{-} #rightarrow e^{-} + #bar{#nu}_{e} + #nu_{#mu}",
  			  "#mu^{-} lifetime spectra", 33, 0, 25);


  //TH1F *myHist = new TH1F("#mu^{-} #rightarrow e^{-} + #bar{#nu}_{e} + #nu_{#mu}",
  //			  "#mu^{-} lifetime spectra", 31, 0, 25);
  //TH1F *myHist = new TH1F("#mu^{-} #rightarrow e^{-} + #bar{#nu}_{e} + #nu_{#mu}",
			  //			  "#mu^{-} lifetime spectra", 81, 0, 30);
  //
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
    Double_t data[nBins]={static_cast<Double_t>(*mypulseAmplitude)/2};
    //myHist->Fill(count, data[i]);
    myHist->Fill((count*0.01087)-0.1955, data[i]);
  }

  //for(int i=0; i < myHist->GetNbinsX(); i++){
  //Float_t err = myHist->GetBinContent(i);
  //myHist->SetBinError(i, myHist->GetBinError(i)/2);
    //myHist->SetBinError(i, sqrt(err));
  //}

  TF1 *fit = new TF1("fit", "exp([0]+[1]*x)+[2]", 0, 25);
  //TF1 *ref = new TF1("ref", "exp(5.382+0.4551599204*x)+0.3745"));
  /*gStyle->SetOptStat();
  myHist->Draw();
  c1->Update();
  TPaveStats *ps = (TPaveStats*)c1->GetPrimitive("stats");
  TList *listOfLines = ps->GetListOfLines();
  //TText *tconst = ps->GetLineWidth("RMS");
  //listOfLines->Remove(tconst);
  TLatex *mulife = new TLatex(0, 0, "Test = 10");
  mulife->SetTextFont(42);
  mulife->SetTextSize(0.04);
  mulife->SetTextColor(kRed);
  listOfLines->Add(mulife);
  //myHist->SetStats(0);
  c1->Modified();
  */

  gStyle->SetOptFit(1);
  gStyle->SetOptStat(0000);
  myHist->Draw();

  //myHist->GetXaxis()->SetRangeUser(0, 24);
  //myHist->Fit("expo");
  myHist->Fit("fit");
  myHist->GetYaxis()->SetTitle("Counts");
  myHist->GetXaxis()->SetTitle("#mu s");

  c1->SetLogy();
  c1->SaveAs("mu_lifetime_final.eps");
  
}



