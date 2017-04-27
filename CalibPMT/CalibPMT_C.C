void CalibPMT_C() {

   TCanvas *c1 = new TCanvas("c1","Calibration", 200, 38, 700, 500);

   c1->SetGrid();  
   c1->GetFrame()->SetFillColor(21);
   c1->GetFrame()->SetBorderSize(12);

   //HV_C --> Varying starting at 1500 V (top scintillator)
   //HV_D --> Keeping constant at 1500 V  (btm)





   const Int_t n = 10;

                    
   // Voltage Supplied to PMT
   Float_t x[n]  = {1165., 1222., 1341., 1427., 1450., 1522., 1630., 1725., 1824., 1850.};

   // Voltage in mV of PMT amplitude
   Float_t y[n]  = {35., 70., 103., 127., 125., 101., 123., 115., 127., 125.};



   Float_t ex[n] = {0., 0., 0., 0., 0., 0., 0., 0., 0., 0.};

   // Error taken as 3%
   Float_t ey[n] = {5.9, 8.3, 10., 10., 11., 10., 11.,11., 11.18};

   
   TGraphErrors *gr = new TGraphErrors(n,x,y,ex,ey);
   //gr->Fit("expo");

   gr->SetTitle("HV_B:PMT_C (PMT_D const))");

   gr->GetXaxis()->SetTitle("V");
   gr->GetYaxis()->SetTitle("Counts");
   gr->SetMarkerColor(4);
   gr->Draw("AP");
   gr->SetMarkerStyle(21);


   //c1->SetLogy();
   c1->Update();
   //c1->SaveAs("PMT_Calib_HV_C_1.eps");
   c1->SaveAs("PMT_Calib_PMT_C_HV_B_1450V.jpg");
}
