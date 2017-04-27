void CalibPMT_HVD() {

   TCanvas *c1 = new TCanvas("c1","Calibration", 200, 38, 700, 500);

   c1->SetGrid();  
   c1->GetFrame()->SetFillColor(21);
   c1->GetFrame()->SetBorderSize(12);

   //HV_D --> Varying starting at 1500 V (btm scintillator)
   //HV_C --> Keeping constant at 17500 V  (toop)





   const Int_t n = 6;

   // Voltage in mV of PMT amplitude
   Float_t y[n]  = {135., 191., 241., 211., 208., 225.};

                    
   // Voltage Supplied to PMT
   Float_t x[n]  = {1400., 1500., 1550., 1600., 1700., 1800.};

   Float_t ex[n] = {0., 0., 0., 0., 0., 0.};

   // Error taken as 3%
   Float_t ey[n] = {11., 14., 15., 14., 14., 15.};

   
   TGraphErrors *gr = new TGraphErrors(n,x,y,ex,ey);
   //gr->Fit("expo");

   gr->SetTitle("HV_D plateau search (HV_C const.(1750 V))");

   gr->GetXaxis()->SetTitle("V");
   gr->GetYaxis()->SetTitle("Counts");
   gr->SetMarkerColor(4);
   gr->Draw("AP");
   gr->SetMarkerStyle(21);


   //c1->SetLogy();
   c1->Update();
   //c1->SaveAs("PMT_Calib_HV_C_1.eps");
   c1->SaveAs("PMT_Calib_HV_D_1550.jpg");
}
