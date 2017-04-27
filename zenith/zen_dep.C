#include <TH1F.h>
#include <TF1.h>
#include <TMath.h>
#include <TGraph.h>

Double_t cos_squared_fit(Double_t *x, Double_t *par){
  Double_t var = par[0];
  //return (par[0]*(cos(TMath::Pi()*x[0]/180. - par[1]) * (cos(TMath::Pi()*x[0]/180. - par[1]) )) +par[2]);
  return (par[0]*(cos(TMath::Pi()*x[0]/180.)*(cos(TMath::Pi()*x[0]/180.) )) + par[1]);
}

void zen_dep() {

   TCanvas *c1 = new TCanvas("c1","Zenith mu ang dep", 200, 38, 700, 500);
   c1->SetGrid();  
   c1->GetFrame()->SetFillColor(21);
   c1->GetFrame()->SetBorderSize(12);

   const Int_t n = 5;
   // Angle
   Float_t x[n]  = {9., 27., 45., 63., 81.};
   // Rate counts/sec
   Float_t y[n]  = {0.123, 0.1058, 0.075278, 0.03722, 0.01759};
   Float_t ex[n] = {0.1, 0.1, 0.1, 0.1, 0.1};
   Float_t ey[n] = {0.0058597, 0.00542, 0.004572, 0.0032156, 0.001805};

   TGraphErrors *gr = new TGraphErrors(n,x,y,ex,ey);
   TF1 *f1 = new TF1("f1", cos_squared_fit, 0., 90., 2);
   //f1->SetParameter(1, 0.124);
   //f1->SetParameter(2, 0.1155);
   //f1->SetParLimits(1, 0.1, 0.13);
   //f1->SetParLimits(2, 0.1, 0.2);
   gr->Fit("f1");
   gStyle->SetOptStat(0000);
   gStyle->SetOptFit(1);

   gr->SetTitle("Zenith angle dependence on #mu^{-} rate");
   gr->GetXaxis()->SetTitle("#theta, degrees");
   gr->GetYaxis()->SetTitle("Counts / s");
   gr->GetYaxis()->SetTitleOffset(1.2);
   gr->SetMarkerColor(4);
   gr->Draw("AP");
   gr->SetMarkerStyle(21);

   c1->Update();
   c1->SaveAs("zenith.eps");

}
