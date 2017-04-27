void counter_sep() {

   TCanvas *c1 = new TCanvas("c1","muon flux as a function of counter separation distance", 200, 38, 700, 500);

   c1->SetGrid();  
   c1->GetFrame()->SetFillColor(21);
   c1->GetFrame()->SetBorderSize(12);

   const Int_t n = 5;

   //Float_t x[n]  = {15.3, 23., 30., 37.8, 48., 73.3}; 
   Float_t x[n]  = {15.3, 23., 37.8, 48., 73.3}; 
  
   //Float_t y[n] = {11.8050, 15.1141, 21.3019, 17.5437, 24.8041, 20.9331};
   //Float_t y[n] = {15.1141, 21.3019, 17.5437, 24.8041, 20.9331};
   //Float_t y[n] = {0.01815, 0.0232, 0.03276, 0.02698, 0.03815, 0.03219};
   Float_t y[n] = {0.01815, 0.0232, 0.02698, 0.03815, 0.03219};

   Float_t ex[n] = {0., 0., 0., 0., 0.};

   //Float_t ey[n] = {0.7922, 1.3115, 1.5578, 1.6210, 2.1048, 2.3126 };
   //Float_t ey[n] = {1.3115, 1.5578, 1.6210, 2.1048, 2.3126 };
   //Float_t ey[n] = {0.00122, 0.00212, 0.00240, 0.00250, 0.00324, 0.00356};
   Float_t ey[n] = {0.00122, 0.00212, 0.00250, 0.00324, 0.00356};
   
   TGraphErrors *gr = new TGraphErrors(n,x,y,ex,ey);
   gr->SetTitle("#mu^{-} flux per solid angle vs. counter separation distance");
   gr->GetYaxis()->SetTitle("#Phi_{#mu^{-}} /  #Omega");
   gr->GetXaxis()->SetTitle("#Delta r (cm)");
   gr->SetMinimum(0.);
   gr->SetMaximum(0.06);
   //gr->SetMarkerColor(kBlue);
   gr->GetYaxis()->SetTitleOffset(1.2);
   gStyle->SetOptStat(0000);
   gStyle->SetOptFit(1);
   gr->Fit("pol0");
   gr->Draw("AP*");


   c1->Update();
   c1->SaveAs("flux_omega.eps");
}
