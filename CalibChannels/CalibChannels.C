//Maestro channel calibration

void CalibChannels() {

   TCanvas *c1 = new TCanvas("c1","Calibration", 200, 38, 700, 500);

   c1->SetGrid();  
   c1->GetFrame()->SetFillColor(21);
   c1->GetFrame()->SetBorderSize(12);

   const Int_t n = 10;

   //y = 0.0109548x -0.263439
   //y = 0.0109548x

   // Time in microsec
   Float_t y[n]  = {0., 0.5, 1., 2., 3., 5., 7., 9., 10., 12.};
                    
   // Channels
   Float_t x[n]  = {0., 55., 102., 204., 299., 516., 676., 859., 948., 1076.};
  
   TGraph *gr  = new TGraph (n, x, y);

   gr->SetTitle("Channel marker calibration");

   gr->GetXaxis()->SetTitle("Channel");

   gr->GetYaxis()->SetTitle("#mu s");
   gStyle->SetOptFit(1);
   gr->SetMarkerColor(4);
   gr->Fit("pol1");
   gr->Draw("AP");
   gr->SetMarkerStyle(21);

   c1->Update();
   c1->SaveAs("chCalib.eps");
   c1->SaveAs("chCalib.png");
}
