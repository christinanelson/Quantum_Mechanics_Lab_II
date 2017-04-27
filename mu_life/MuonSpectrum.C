#include "TH1F.h"
#include "TCanvas.h"
#include "TFile.h"
#include "TTreeReader.h"
#include "TTreeReaderValue.h"

class TVirtualPad;

void MuonSpectrum() {

  TCanvas * c1 = new TCanvas("c1", "pulseA",1300,1400,2000,1300);
  Int_t var = 2047;
  // Create a variable histogram for the values we read.                            
  TH1F *myHist = new TH1F("#mu^{-} #rightarrow e^{-} + #bar{#nu}_{e} + #nu_{#mu}",
			  "#mu^{-} lifetime spectra", var, 0, 3000);

  TFile *mu4 = TFile::Open("mu_021317_1232.root");
  if (!mu4 || mu4->IsZombie()) {
    return;
  }

  TTreeReader myReader("T", mu4);
  TTreeReaderValue<Int_t> mypulseAmplitude(myReader, "pulseAmplitude");
  const int nBins = 2049;
  Int_t count = 0;
  Int_t i = 0;
  while (myReader.Next() ) {
    count ++;
    Double_t data[nBins]={static_cast<Double_t>(*mypulseAmplitude)};
    myHist->Fill(count, data[i]);
  }
  Double_t xbins[2049];
  Int_t k = 0;
  TAxis *axis = myHist->GetXaxis();
  for (Int_t i=1; i<2048; i++)
    {
      Int_t y = (Int_t)myHist->GetBinContent(i);
      if(y<0) continue;
      Double_t dx = axis->GetBinWidth(i)/y;
      Double_t xmin = axis->GetBinLowEdge(i);
      for(Int_t j = 0; j < y; j++)
	{
	  xbins[k] = xmin + j*dx;
	  k++;
	}
	}
  xbins[k] = axis->GetXmax();

  //rebin, keeping 1/4 of the bins
  Double_t xrebin[512];
  Int_t kk = 0; 
  for(Int_t j = 0; j < k; j +=4)
    {
      xrebin[kk] = xbins[j];
      k++;;
    }
  xrebin[kk] = xbins[k];

  myHist->Rebin(kk, "hrebin", xrebin);  
  myHist->Draw();
  myHist->Fit("expo");
  myHist->GetYaxis()->SetTitle("Counts");
  myHist->GetXaxis()->SetTitle("Channel");
  c1->SetLogy();
  //c1->SaveAs("mu_chexp.eps");

}



