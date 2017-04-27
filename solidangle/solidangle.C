void solidangle()
{


  TCanvas *c1 = new TCanvas("c1", "MTpin", 200, 10, 700, 500);
  c1->SetGrid();
  const Int_t n = 1;
  Float_t x[n] = {-1.};
  Float_t y[n] = {-1.};
  /*g1->SetMarkerStyle(23);
  g1->SetLineWidth(2);
  g1->SetLineColor(kBlue-3);
  g1->SetMarkerColor(kBlue-3);

  g2->SetMarkerStyle(8);
  g2->SetLineWidth(2);
  g2->SetLineColor(kGreen-2);
  g2->SetMarkerColor(kGreen-2);

  g1->GetYaxis()->SetTitle("chirp");
  g1->GetXaxis()->SetTitle("iteration, time");
  g1->SetTitle("Sonar data");
  g1->Draw("AP");
  g2->Draw("P");
*/

  TF1 *fa3 = new TF1("fa1", "(4*(acos((-25.5*25.5/4)/(x*x+25.5*25.5/4)))-2*pi)/(2*pi)", 0,  100);
  fa3->SetLineColor(kBlue);
  fa3->GetXaxis()->SetTitle("x");
  fa3->GetYaxis()->SetTitle("f(x)");
  fa3->SetTitle("Solid angle correction");
  fa3->Draw();

  TF1 *fa4 = new TF1("fa1", "(4*(acos((-25.5*25.5/4)/( (x/(10.5/(25.5+1)))* (x/(10.5/(25.5+1))) +25.5*25.5/4)))-2*pi)/(2*pi)", 0,  100);
  fa4->SetLineColor(kRed);
  //fa4->SetTitle("solid angle")
  fa4->Draw("same");
  
  double solid_angle1 = fa4->Eval(15.3);
  double solid_angle2 = fa4->Eval(23.0);
  double solid_angle3 = fa4->Eval(30.0);
  double solid_angle4 = fa4->Eval(37.8);
  double solid_angle5 = fa4->Eval(48.0);
  double solid_angle6 = fa4->Eval(73.3);

  cout << "solid angle 15.3 cm " << solid_angle1 << endl;
  cout << "solid angle 23.0 cm " << solid_angle2 << endl;
  cout << "solid angle 30.0 cm " << solid_angle3 << endl;
  cout << "solid angle 37.8 cm " << solid_angle4 << endl;
  cout << "solid angle 48.0 cm " << solid_angle5 << endl;
  cout << "solid angle 73.3 cm " << solid_angle6 << endl;

  //g1->SetLineWidth(2);
  //g1->GetXaxis()->SetRangeUser(-.000000125, .00000085);
  //g1->GetXaxis()->SetTitle("s");
  //g1->GetYaxis()->SetTitle("V");
 
  TLegend* l = new TLegend(.75,0.75,0.95,0.9);
  l->AddEntry(fa3, "measured", "l");
  l->AddEntry(fa4, "correction", "l");
  l->SetTextSize(0.035);
  l->Draw();

  c1->Update();
  c1->SetTitle("solid angle");
  c1->SaveAs("solid.eps");

  }
