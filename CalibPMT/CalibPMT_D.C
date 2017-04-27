void CalibPMT_D() {

   TCanvas *c1 = new TCanvas("c1","Calibration", 200, 38, 700, 500);

   c1->SetGrid();  
   c1->GetFrame()->SetFillColor(21);
   c1->GetFrame()->SetBorderSize(12);

   //HV_C --> Varying starting at 1500 V (top scintillator)
   //HV_D --> Keeping constant at 1500 V  (btm)





   const Int_t n = 8;

                    
   // Voltage Supplied to PMT
   Float_t x[n]  = {1300., 1400., 1500., 1550., 1600., 1700., 1800., 1900.};

   // Voltage in mV of PMT amplitude
   Float_t y[n]  = {9., 29., 113., 132., 149., 155., 182., 198.};



   Float_t ex[n] = {0., 0., 0., 0., 0., 0., 0., 0.};

   // Error taken as 3%
   Float_t ey[n] = {3., 5.38, 10.63, 12.2, 12., 12.44, 13.49, 14.07};

   
   TGraphErrors *gr = new TGraphErrors(n,x,y,ex,ey);
   //gr->Fit("expo");

   gr->SetTitle("HV_E:PMT_D (PMT_C const))");

   gr->GetXaxis()->SetTitle("V");
   gr->GetYaxis()->SetTitle("Counts");
   gr->SetMarkerColor(4);
   gr->Draw("AP");
   gr->SetMarkerStyle(21);


   //c1->SetLogy();
   c1->Update();
   //c1->SaveAs("PMT_Calib_HV_C_1.eps");
   c1->SaveAs("PMT_Calib_PMT_D_HV_E_1600V.jpg");
}
