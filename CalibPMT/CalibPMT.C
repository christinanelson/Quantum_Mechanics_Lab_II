void CalibPMT() {

   TCanvas *c1 = new TCanvas("c1","Calibration", 200, 38, 700, 500);

   c1->SetGrid();  
   c1->GetFrame()->SetFillColor(21);
   c1->GetFrame()->SetBorderSize(12);

   //HV_C --> Varying starting at 1500 V (top scintillator)
   //HV_D --> Keeping constant at 1500 V  (btm)





   const Int_t n = 9;

   // Voltage in mV of PMT amplitude
   Float_t y[n]  = {5., 26., 41., 64., 143., 180., 248., 237., 224};

                    
   // Voltage Supplied to PMT
   Float_t x[n]  = {1400., 1500., 1550., 1600., 1650., 1700., 1750., 1800., 1900.};

   Float_t ex[n] = {0., 0., 0., 0., 0., 0., 0., 0., 0.};

   // Error taken as 3%
   Float_t ey[n] = {2., 5., 6., 8., 12., 13., 15., 15., 15.};

   
   TGraphErrors *gr = new TGraphErrors(n,x,y,ex,ey);
   //gr->Fit("expo");

   gr->SetTitle("PMT_D (HV_B_gold))");

   gr->GetXaxis()->SetTitle("V");
   gr->GetYaxis()->SetTitle("Counts");
   gr->SetMarkerColor(4);
   gr->Draw("AP");
   gr->SetMarkerStyle(21);


   //c1->SetLogy();
   c1->Update();
   //c1->SaveAs("PMT_Calib_HV_C_1.eps");
   //c1->SaveAs("PMT_Calib_HV_C_1750.jpg");
}
