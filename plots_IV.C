//C, C++
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <math.h>

#include <time.h>

using namespace std;

Double_t max_range_gr(TGraphErrors *gr);
void get_ration(TGraphErrors *gr_r, TGraphErrors *gr, TGraphErrors *gr_n);
Double_t get_volt_err(Double_t Voltage);
Double_t get_curr_err(Double_t Current);
Int_t plots_IV_25um_wores_ch01_K2400(TString SiPM_name);
Int_t plots_IV_30um_wores_ch01_K2400(TString SiPM_name);
Int_t plots_IV_generic(TString SiPM_name,
		       TString gr_hist_name_01, TString gr_hist_name_02, TString gr_hist_name_03, TString gr_hist_name_04, TString gr_hist_name_05,
		       TString gr_hist_name_06, TString gr_hist_name_07, TString gr_hist_name_08, TString gr_hist_name_09, TString gr_hist_name_10);
Double_t get_r_error(TGraphErrors *gr_r, Double_t vval);


Int_t plots_IV(){
  //plots_IV_25um_wores_ch01_K2400("IV_PCB1_S3_25um_wores_ch01_K2400_n1");
  //plots_IV_30um_wores_ch01_K2400("IV_PCB1_S3_30um_wores_ch01_K2400_n1");
  //plots_IV_generic("IV_PCB1_S3_35um_wores_ch01_K6487_n1",
  //		   "gr_G0_IV_PCB1_S3_35um_wores_ch01_K6487_n1","gr_G1_IV_PCB1_S3_35um_wores_ch01_K6487_n1","gr_G2_IV_PCB1_S3_35um_wores_ch01_K6487_n1",
  //		   "gr_G3_IV_PCB1_S3_35um_wores_ch01_K6487_n1","gr_G5_IV_PCB1_S3_35um_wores_ch01_K6487_n1","gr_G5_IV_PCB1_S3_35um_wores_ch01_K6487_n1",
  //		   "gr_G7_IV_PCB1_S3_35um_wores_ch01_K6487_n1","gr_G10_IV_PCB1_S3_35um_wores_ch01_K6487_n1","gr_G20_IV_PCB1_S3_35um_wores_ch01_K6487_n1",
  //		   "gr_G30_IV_PCB1_S3_35um_wores_ch01_K6487_n1");
  //plots_IV_generic("IV_PCB1_S3_50um_wores_ch01_K2400_n1",
  //		   "gr_G0_IV_PCB1_S3_50um_wores_ch01_K2400_n1",
  //		   "gr_G1_IV_PCB1_S3_50um_wores_ch01_K2400_n1",
  //		   "gr_G2_IV_PCB1_S3_50um_wores_ch01_K2400_n1",
  //		   "gr_G3_IV_PCB1_S3_50um_wores_ch01_K2400_n1",
  //		   "gr_G5_IV_PCB1_S3_50um_wores_ch01_K2400_n1",
  //		   "gr_G5_IV_PCB1_S3_50um_wores_ch01_K2400_n1",
  //		   "gr_G7_IV_PCB1_S3_50um_wores_ch01_K2400_n1",
  //		   "gr_G10_IV_PCB1_S3_50um_wores_ch01_K2400_n1",
  //		   "gr_G20_IV_PCB1_S3_50um_wores_ch01_K2400_n1",
  //		   "gr_G30_IV_PCB1_S3_50um_wores_ch01_K2400_n1");
  //plots_IV_generic("IV_PCB2_S4_25um_res_ch01_K2400_n1",
  //		   "gr_G0_IV_PCB2_S4_25um_res_ch01_K2400_n1",
  //		   "gr_G1_IV_PCB2_S4_25um_res_ch01_K2400_n1",
  //		   "gr_G2_IV_PCB2_S4_25um_res_ch01_K2400_n1",
  //		   "gr_G3_IV_PCB2_S4_25um_res_ch01_K2400_n1",
  //		   "gr_G5_IV_PCB2_S4_25um_res_ch01_K2400_n1",
  //		   "gr_G5_IV_PCB2_S4_25um_res_ch01_K2400_n1",
  //		   "gr_G7_IV_PCB2_S4_25um_res_ch01_K2400_n1",
  //		   "gr_G10_IV_PCB2_S4_25um_res_ch01_K2400_n1",
  //		   "gr_G20_IV_PCB2_S4_25um_res_ch01_K2400_n1",
  //		   "gr_G20_IV_PCB2_S4_25um_res_ch01_K2400_n1");
  //plots_IV_generic("IV_PCB2_S4_30um_res_ch01_K6487_n1",
  //		   "gr_G0_IV_PCB2_S4_30um_res_ch01_K6487_n1",
  //		   "gr_G1_IV_PCB2_S4_30um_res_ch01_K6487_n1",
  //		   "gr_G2_IV_PCB2_S4_30um_res_ch01_K6487_n1",
  //		   "gr_G3_IV_PCB2_S4_30um_res_ch01_K6487_n1",
  //		   "gr_G5_IV_PCB2_S4_30um_res_ch01_K6487_n1",
  //		   "gr_G5_IV_PCB2_S4_30um_res_ch01_K6487_n1",
  //		   "gr_G7_IV_PCB2_S4_30um_res_ch01_K6487_n1",
  //		   "gr_G10_IV_PCB2_S4_30um_res_ch01_K6487_n1",
  //		   "gr_G20_IV_PCB2_S4_30um_res_ch01_K6487_n1",
  //		   "gr_G20_IV_PCB2_S4_30um_res_ch01_K6487_n1");
  //plots_IV_generic("IV_PCB2_S4_35um_res_ch01_K2400_n1",
  //		   "gr_G0_IV_PCB2_S4_35um_res_ch01_K2400_n1",
  //		   "gr_G1_IV_PCB2_S4_35um_res_ch01_K2400_n1",
  //		   "gr_G2_IV_PCB2_S4_35um_res_ch01_K2400_n1",
  //		   "gr_G3_IV_PCB2_S4_35um_res_ch01_K2400_n1",
  //		   "gr_G5_IV_PCB2_S4_35um_res_ch01_K2400_n1",
  //		   "gr_G5_IV_PCB2_S4_35um_res_ch01_K2400_n1",
  //		   "gr_G7_IV_PCB2_S4_35um_res_ch01_K2400_n1",
  //		   "gr_G10_IV_PCB2_S4_35um_res_ch01_K2400_n1",
  //		   "gr_G20_IV_PCB2_S4_35um_res_ch01_K2400_n1",
  //		   "gr_G20_IV_PCB2_S4_35um_res_ch01_K2400_n1");
  //plots_IV_generic("IV_PCB2_S4_50um_res_ch01_K6487_n1",
  //		   "gr_G0_IV_PCB2_S4_50um_res_ch01_K6487_n1",
  //		   "gr_G1_IV_PCB2_S4_50um_res_ch01_K6487_n1",
  //		   "gr_G2_IV_PCB2_S4_50um_res_ch01_K6487_n1",
  //		   "gr_G3_IV_PCB2_S4_50um_res_ch01_K6487_n1",
  //		   "gr_G5_IV_PCB2_S4_50um_res_ch01_K6487_n1",
  //		   "gr_G5_IV_PCB2_S4_50um_res_ch01_K6487_n1",
  //		   "gr_G7_IV_PCB2_S4_50um_res_ch01_K6487_n1",
  //		   "gr_G10_IV_PCB2_S4_50um_res_ch01_K6487_n1",
  //		   "gr_G20_IV_PCB2_S4_50um_res_ch01_K6487_n1",
  //		   "gr_G20_IV_PCB2_S4_50um_res_ch01_K6487_n1");
  //plots_IV_generic("IV_PCB1_S1_40um_wores_ch01_K6487_n1",
  //		   "gr_G0_IV_PCB1_S1_40um_wores_ch01_K6487_n1",
  //		   "gr_G1_IV_PCB1_S1_40um_wores_ch01_K6487_n1",
  //		   "gr_G2_IV_PCB1_S1_40um_wores_ch01_K6487_n1",
  //		   "gr_G3_IV_PCB1_S1_40um_wores_ch01_K6487_n1",
  //		   "gr_G5_IV_PCB1_S1_40um_wores_ch01_K6487_n1",
  //		   "gr_G5_IV_PCB1_S1_40um_wores_ch01_K6487_n1",
  //		   "gr_G7_IV_PCB1_S1_40um_wores_ch01_K6487_n1",
  //		   "gr_G10_IV_PCB1_S1_40um_wores_ch01_K6487_n1",
  //		   "gr_G20_IV_PCB1_S1_40um_wores_ch01_K6487_n1",
  //		   "gr_G30_IV_PCB1_S1_40um_wores_ch01_K6487_n1");
  //plots_IV_generic("IV_PCB1_S2_40um_res_ch01_K6487_n2",
  //		   "gr_G0_IV_PCB1_S2_40um_res_ch01_K6487_n2",
  //		   "gr_G1_IV_PCB1_S2_40um_res_ch01_K6487_n2",
  //		   "gr_G2_IV_PCB1_S2_40um_res_ch01_K6487_n2",
  //		   "gr_G3_IV_PCB1_S2_40um_res_ch01_K6487_n2",
  //		   "gr_G5_IV_PCB1_S2_40um_res_ch01_K6487_n2",
  //		   "gr_G5_IV_PCB1_S2_40um_res_ch01_K6487_n2",
  //		   "gr_G7_IV_PCB1_S2_40um_res_ch01_K6487_n2",
  //		   "gr_G10_IV_PCB1_S2_40um_res_ch01_K6487_n2",
  //		   "gr_G20_IV_PCB1_S2_40um_res_ch01_K6487_n2",
  //		   "gr_G30_IV_PCB1_S2_40um_res_ch01_K6487_n2");
  //plots_IV_generic("IV_PCB3_S5_40um_wores_ch28_K6487_n1",
  //		   "gr_G0_IV_PCB3_S5_40um_wores_ch28_K6487_n1",
  //		   "gr_G1_IV_PCB3_S5_40um_wores_ch28_K6487_n1",
  //		   "gr_G2_IV_PCB3_S5_40um_wores_ch28_K6487_n1",
  //		   "gr_G3_IV_PCB3_S5_40um_wores_ch28_K6487_n1",
  //		   "gr_G5_IV_PCB3_S5_40um_wores_ch28_K6487_n1",
  //		   "gr_G5_IV_PCB3_S5_40um_wores_ch28_K6487_n1",
  //		   "gr_G7_IV_PCB3_S5_40um_wores_ch28_K6487_n1",
  //		   "gr_G10_IV_PCB3_S5_40um_wores_ch28_K6487_n1",
  //		   "gr_G10_IV_PCB3_S5_40um_wores_ch28_K6487_n1",
  //		   "gr_G10_IV_PCB3_S5_40um_wores_ch28_K6487_n1");
  plots_IV_generic("IV_PCB4_S6_40um_res_ch28_K6487_n1",
  		   "gr_G0_IV_PCB4_S6_40um_res_ch28_K6487_n1",
  		   "gr_G1_IV_PCB4_S6_40um_res_ch28_K6487_n1",
  		   "gr_G2_IV_PCB4_S6_40um_res_ch28_K6487_n1",
  		   "gr_G3_IV_PCB4_S6_40um_res_ch28_K6487_n1",
  		   "gr_G5_IV_PCB4_S6_40um_res_ch28_K6487_n1",
  		   "gr_G5_IV_PCB4_S6_40um_res_ch28_K6487_n1",
  		   "gr_G7_IV_PCB4_S6_40um_res_ch28_K6487_n1",
  		   "gr_G10_IV_PCB4_S6_40um_res_ch28_K6487_n1",
  		   "gr_G10_IV_PCB4_S6_40um_res_ch28_K6487_n1",
  		   "gr_G10_IV_PCB4_S6_40um_res_ch28_K6487_n1");
  return 0;
}

Int_t plots_IV_generic(TString SiPM_name,
		       TString gr_hist_name_01, TString gr_hist_name_02, TString gr_hist_name_03, TString gr_hist_name_04, TString gr_hist_name_05,
		       TString gr_hist_name_06, TString gr_hist_name_07, TString gr_hist_name_08, TString gr_hist_name_09, TString gr_hist_name_10){
  //
  TString fileN01 = "../data/IrradiationTests/01_0_Gy/hist.root";
  TString fileN02 = "../data/IrradiationTests/02_1_Gy/hist.root";
  TString fileN03 = "../data/IrradiationTests/03_2_Gy/hist.root";
  TString fileN04 = "../data/IrradiationTests/04_3_Gy/hist.root";
  TString fileN05 = "../data/IrradiationTests/05_5_Gy/hist.root";
  TString fileN06 = "../data/IrradiationTests/06_5_Gy_ND/hist.root";
  TString fileN07 = "../data/IrradiationTests/07_7_Gy/hist.root";
  TString fileN08 = "../data/IrradiationTests/08_10_Gy/hist.root";
  TString fileN09 = "../data/IrradiationTests/09_20_Gy/hist.root";
  TString fileN10 = "../data/IrradiationTests/10_30_Gy/hist.root";
  //
  TFile *f01 = new TFile(fileN01.Data());
  TFile *f02 = new TFile(fileN02.Data());
  TFile *f03 = new TFile(fileN03.Data());
  TFile *f04 = new TFile(fileN04.Data());
  TFile *f05 = new TFile(fileN05.Data());
  TFile *f06 = new TFile(fileN06.Data());
  TFile *f07 = new TFile(fileN07.Data());
  TFile *f08 = new TFile(fileN08.Data());
  TFile *f09 = new TFile(fileN09.Data());
  TFile *f10 = new TFile(fileN10.Data());
  //
  TString name_gr = "";
  //
  TGraphErrors *gr_01 = (TGraphErrors*)f01->Get(gr_hist_name_01.Data());
  TGraphErrors *gr_02 = (TGraphErrors*)f02->Get(gr_hist_name_02.Data());
  TGraphErrors *gr_03 = (TGraphErrors*)f03->Get(gr_hist_name_03.Data());
  TGraphErrors *gr_04 = (TGraphErrors*)f04->Get(gr_hist_name_04.Data());
  TGraphErrors *gr_05 = (TGraphErrors*)f05->Get(gr_hist_name_05.Data());
  TGraphErrors *gr_06 = (TGraphErrors*)f06->Get(gr_hist_name_06.Data());
  TGraphErrors *gr_07 = (TGraphErrors*)f07->Get(gr_hist_name_07.Data());
  TGraphErrors *gr_08 = (TGraphErrors*)f08->Get(gr_hist_name_08.Data());
  //TGraphErrors *gr_09 = (TGraphErrors*)f09->Get(gr_hist_name_09.Data());
  //TGraphErrors *gr_10 = (TGraphErrors*)f10->Get(gr_hist_name_10.Data());
  //
  gr_01->SetMarkerStyle(1);
  gr_02->SetMarkerStyle(1);
  gr_03->SetMarkerStyle(1);
  gr_04->SetMarkerStyle(1);
  gr_05->SetMarkerStyle(1);
  gr_06->SetMarkerStyle(1);
  gr_07->SetMarkerStyle(20);
  gr_08->SetMarkerStyle(20);
  //gr_09->SetMarkerStyle(20);
  //gr_10->SetMarkerStyle(20);
  //
  gr_01->SetMarkerColor(kBlack);
  gr_02->SetMarkerColor(kRed);
  gr_03->SetMarkerColor(kBlue+2);
  gr_04->SetMarkerColor(kMagenta+2);
  gr_05->SetMarkerColor(kGreen+2);
  gr_06->SetMarkerColor(kGreen);
  gr_07->SetMarkerColor(kBlack);
  gr_08->SetMarkerColor(kRed);
  //gr_09->SetMarkerColor(kBlue+2);
  //gr_10->SetMarkerColor(kMagenta+2);
  //
  gr_01->SetLineColor(kBlack);
  gr_02->SetLineColor(kRed);
  gr_03->SetLineColor(kBlue+2);
  gr_04->SetLineColor(kMagenta+2);
  gr_05->SetLineColor(kGreen+2);
  gr_06->SetLineColor(kGreen);
  gr_07->SetLineColor(kBlack);
  gr_08->SetLineColor(kRed);
  //gr_09->SetLineColor(kBlue+2);
  //gr_10->SetLineColor(kMagenta+2);
  //
  gr_01->SetLineWidth(2);
  gr_02->SetLineWidth(2);
  gr_03->SetLineWidth(2);
  gr_04->SetLineWidth(2);
  gr_05->SetLineWidth(2);
  gr_06->SetLineWidth(2);
  gr_07->SetLineWidth(2);
  gr_08->SetLineWidth(2);
  //gr_09->SetLineWidth(2);
  //gr_10->SetLineWidth(2);
  //
  gStyle->SetPalette(1);
  gStyle->SetFrameBorderMode(0);
  gROOT->ForceStyle();
  gStyle->SetOptStat(kFALSE);
  //
  TCanvas *c1 = new TCanvas("c1","c1",10,10,1200,1000);
  c1->Divide(1,2);
  //
  c1->cd(1);
  //
  gPad->SetRightMargin(0.01);
  gPad->SetLeftMargin(0.08);
  gPad->SetTopMargin(0.02);
  gPad->SetBottomMargin(0.08);
  //
  //
  gPad->SetGridx();
  gPad->SetGridy();
  gPad->SetLogy();
  //
  TMultiGraph *mg = new TMultiGraph();
  mg->Add(gr_01);
  mg->Add(gr_02);
  mg->Add(gr_03);
  mg->Add(gr_04);
  mg->Add(gr_05);
  mg->Add(gr_06);
  mg->Add(gr_07);
  mg->Add(gr_08);
  //mg->Add(gr_09);
  //mg->Add(gr_10);
  mg->GetXaxis()->SetRangeUser(32.0,60.0);
  //mg->GetYaxis()->SetRangeUser(-0.2,6.0);
  mg->SetMinimum(1.0e-10);
  mg->SetMaximum(1.0e-2);
  mg->Draw("APL");
  mg->GetXaxis()->SetTitle("V_{bias}, V");
  mg->GetYaxis()->SetTitle("Current, A");
  TLegend *leg01 = new TLegend(0.9,0.1,0.98,0.4,"","brNDC");
  leg01->AddEntry(gr_01, " 0 Gy", "pl");
  leg01->AddEntry(gr_02, " 1 Gy", "pl");
  leg01->AddEntry(gr_03, " 2 Gy", "pl");
  leg01->AddEntry(gr_04, " 3 Gy", "pl");
  leg01->AddEntry(gr_05, " 5 Gy", "pl");
  leg01->AddEntry(gr_07, " 7 Gy", "pl");
  leg01->AddEntry(gr_08, "10 Gy", "pl");
  //leg01->AddEntry(gr_09, "20 Gy", "pl");
  //leg01->AddEntry(gr_10, "30 Gy", "pl");
  leg01->Draw();
  //
  //
  c1->cd(2);
  gPad->SetRightMargin(0.01);
  gPad->SetLeftMargin(0.08);
  gPad->SetTopMargin(0.02);
  gPad->SetBottomMargin(0.08);
  //
  //
  gPad->SetGridx();
  gPad->SetGridy();
  gPad->SetLogy();
  //
  TGraphErrors *gr_r_01 = new TGraphErrors(); gr_r_01->SetNameTitle("gr_r_01","gr_r_01");
  TGraphErrors *gr_r_02 = new TGraphErrors(); gr_r_02->SetNameTitle("gr_r_02","gr_r_02");
  TGraphErrors *gr_r_03 = new TGraphErrors(); gr_r_03->SetNameTitle("gr_r_03","gr_r_03");
  TGraphErrors *gr_r_04 = new TGraphErrors(); gr_r_04->SetNameTitle("gr_r_04","gr_r_04");
  TGraphErrors *gr_r_05 = new TGraphErrors(); gr_r_05->SetNameTitle("gr_r_05","gr_r_05");
  TGraphErrors *gr_r_06 = new TGraphErrors(); gr_r_06->SetNameTitle("gr_r_06","gr_r_06");
  TGraphErrors *gr_r_07 = new TGraphErrors(); gr_r_07->SetNameTitle("gr_r_07","gr_r_07");
  TGraphErrors *gr_r_08 = new TGraphErrors(); gr_r_08->SetNameTitle("gr_r_08","gr_r_08");
  //TGraphErrors *gr_r_09 = new TGraphErrors(); gr_r_09->SetNameTitle("gr_r_09","gr_r_09");
  //TGraphErrors *gr_r_10 = new TGraphErrors(); gr_r_10->SetNameTitle("gr_r_10","gr_r_10");
  get_ration(gr_r_01, gr_01, gr_01);
  get_ration(gr_r_02, gr_02, gr_01);
  get_ration(gr_r_03, gr_03, gr_01);
  get_ration(gr_r_04, gr_04, gr_01);
  get_ration(gr_r_05, gr_05, gr_01);
  get_ration(gr_r_06, gr_06, gr_01);
  get_ration(gr_r_07, gr_07, gr_01);
  get_ration(gr_r_08, gr_08, gr_01);
  //get_ration(gr_r_09, gr_09, gr_01);
  //get_ration(gr_r_10, gr_10, gr_01);
  //
  gr_r_01->SetMarkerStyle(1);
  gr_r_02->SetMarkerStyle(1);
  gr_r_03->SetMarkerStyle(1);
  gr_r_04->SetMarkerStyle(1);
  gr_r_05->SetMarkerStyle(1);
  gr_r_06->SetMarkerStyle(1);
  gr_r_07->SetMarkerStyle(20);
  gr_r_08->SetMarkerStyle(20);
  //gr_r_09->SetMarkerStyle(20);
  //gr_r_10->SetMarkerStyle(20);
  //
  gr_r_01->SetMarkerColor(kBlack);
  gr_r_02->SetMarkerColor(kRed);
  gr_r_03->SetMarkerColor(kBlue+2);
  gr_r_04->SetMarkerColor(kMagenta+2);
  gr_r_05->SetMarkerColor(kGreen+2);
  gr_r_06->SetMarkerColor(kGreen);
  gr_r_07->SetMarkerColor(kBlack);
  gr_r_08->SetMarkerColor(kRed);
  //gr_r_09->SetMarkerColor(kBlue+2);
  //gr_r_10->SetMarkerColor(kMagenta+2);
  //
  gr_r_01->SetLineColor(kBlack);
  gr_r_02->SetLineColor(kRed);
  gr_r_03->SetLineColor(kBlue+2);
  gr_r_04->SetLineColor(kMagenta+2);
  gr_r_05->SetLineColor(kGreen+2);
  gr_r_06->SetLineColor(kGreen);
  gr_r_07->SetLineColor(kBlack);
  gr_r_08->SetLineColor(kRed);
  //gr_r_09->SetLineColor(kBlue+2);
  //gr_r_10->SetLineColor(kMagenta+2);
  //
  gr_r_01->SetLineWidth(2);
  gr_r_02->SetLineWidth(2);
  gr_r_03->SetLineWidth(2);
  gr_r_04->SetLineWidth(2);
  gr_r_05->SetLineWidth(2);
  gr_r_06->SetLineWidth(2);
  gr_r_07->SetLineWidth(2);
  gr_r_08->SetLineWidth(2);
  //gr_r_09->SetLineWidth(2);
  //gr_r_10->SetLineWidth(2);
  //
  TMultiGraph *mg02 = new TMultiGraph();
  mg02->Add(gr_r_01);
  mg02->Add(gr_r_02);
  mg02->Add(gr_r_03);
  mg02->Add(gr_r_04);
  mg02->Add(gr_r_05);
  mg02->Add(gr_r_07);
  mg02->Add(gr_r_08);
  //mg02->Add(gr_r_09);
  //mg02->Add(gr_r_10);
  mg02->GetXaxis()->SetRangeUser(32.0,60.0);
  //mg->GetYaxis()->SetRangeUser(-0.2,6.0);
  mg02->SetMinimum(5.0e-1);
  mg02->SetMaximum(4.0e+3);
  mg02->Draw("APL");
  mg02->GetXaxis()->SetTitle("V_{bias}, V");
  mg02->GetYaxis()->SetTitle("Ratio");
  //
  leg01->Draw();
  //
  TCanvas *c0 = new TCanvas("c0","c0",10,10,1200,1000);
  c0->SetRightMargin(0.0);
  c0->SetLeftMargin(0.0);
  c0->SetTopMargin(0.0);
  c0->SetBottomMargin(0.0);
  TH2D *h2 = new TH2D("","",100,0,1,100,0,1);
  //h2->Draw();
  TText *t = new TText(.5,.8,SiPM_name.Data());
  t->SetTextAlign(22);
  //t->SetTextColor(kRed+2);
  t->SetTextFont(43);
  t->SetTextSize(40);
  //t->SetTextAngle(45);
  t->Draw();
  TText *t2 = new TText(.5,.7,"Temperature: 22.0 - 25.0");
  t2->SetTextAlign(22);
  t2->SetTextFont(43);
  t2->SetTextSize(40);
  t2->Draw("same");
  //
  TText *t3 = new TText(.5,.6,"Data: 01.03.2023-02.03.2023");
  t3->SetTextAlign(22);
  t3->SetTextFont(43);
  t3->SetTextSize(40);
  t3->Draw("same");
  //
  TCanvas *c2 = new TCanvas("c2","c2",10,10,1200,1000);
  c2->SetRightMargin(0.01);
  c2->SetLeftMargin(0.12);
  c2->SetTopMargin(0.02);
  c2->SetBottomMargin(0.08);
  //
  gPad->SetGridx();
  gPad->SetGridy();
  //   
  TGraphErrors *gr_I_vs_gy = new TGraphErrors(); gr_I_vs_gy->SetNameTitle("gr_I_vs_gy","gr_I_vs_gy");
  gr_I_vs_gy->SetPoint( 0,  0.0, gr_r_01->Eval(37.0)); gr_I_vs_gy->SetPointError( 0,  0.01, get_r_error(gr_r_01, 37));
  gr_I_vs_gy->SetPoint( 1,  1.0, gr_r_02->Eval(37.0)); gr_I_vs_gy->SetPointError( 1,  0.01, get_r_error(gr_r_02, 37));
  gr_I_vs_gy->SetPoint( 2,  2.0, gr_r_03->Eval(37.0)); gr_I_vs_gy->SetPointError( 2,  0.01, get_r_error(gr_r_03, 37));
  gr_I_vs_gy->SetPoint( 3,  3.0, gr_r_04->Eval(37.0)); gr_I_vs_gy->SetPointError( 3,  0.01, get_r_error(gr_r_04, 37));
  gr_I_vs_gy->SetPoint( 4,  5.0, gr_r_05->Eval(37.0)); gr_I_vs_gy->SetPointError( 4,  0.01, get_r_error(gr_r_05, 37));
  gr_I_vs_gy->SetPoint( 5,  7.0, gr_r_07->Eval(37.0)); gr_I_vs_gy->SetPointError( 5,  0.01, get_r_error(gr_r_07, 37));
  gr_I_vs_gy->SetPoint( 6, 10.0, gr_r_08->Eval(37.0)); gr_I_vs_gy->SetPointError( 6,  0.01, get_r_error(gr_r_08, 37));
  //gr_I_vs_gy->SetPoint( 7, 20.0, gr_r_09->Eval(37.0)); gr_I_vs_gy->SetPointError( 7,  0.01, get_r_error(gr_r_09, 37));
  //gr_I_vs_gy->SetPoint( 8, 30.0, gr_r_10->Eval(37.0)); gr_I_vs_gy->SetPointError( 8,  0.01, get_r_error(gr_r_10, 37));
  //
  gr_I_vs_gy->SetNameTitle("","");
  gr_I_vs_gy->SetMarkerStyle(1);
  gr_I_vs_gy->SetMarkerColor(kBlack);
  gr_I_vs_gy->SetLineWidth(2.0);
  //
  gr_I_vs_gy->Draw("APL");
  gr_I_vs_gy->GetYaxis()->SetTitle("Normalised current");
  gr_I_vs_gy->GetXaxis()->SetTitle("Dose, Gy");
  //
  TString pdf_out_01 = SiPM_name; pdf_out_01 += "_01.pdf";
  TString pdf_out_02 = SiPM_name; pdf_out_02 += "_02.pdf";
  TString pdf_out_03 = SiPM_name; pdf_out_03 += "_03.pdf"; 
  //
  c0->SaveAs(pdf_out_01.Data());
  c1->SaveAs(pdf_out_02.Data());
  c2->SaveAs(pdf_out_03.Data());
  //
  TString outputRootFile = "hist_";
  outputRootFile += SiPM_name;
  outputRootFile += ".root";
  //
  TFile* rootFile = new TFile(outputRootFile.Data(), "RECREATE", " Histograms", 1);
  rootFile->cd();
  if (rootFile->IsZombie()){
    std::cout<<"  ERROR ---> file "<<outputRootFile.Data()<<" is zombi"<<std::endl;
    assert(0);
  }
  c0->Write();
  c1->Write();
  c2->Write();
  //
  gr_I_vs_gy->Write();
  //
  return 0;
}

Int_t plots_IV_25um_wores_ch01_K2400(TString SiPM_name){
  //
  TString fileN01 = "../data/IrradiationTests/01_0_Gy/hist.root";
  TString fileN02 = "../data/IrradiationTests/02_1_Gy/hist.root";
  TString fileN03 = "../data/IrradiationTests/03_2_Gy/hist.root";
  TString fileN04 = "../data/IrradiationTests/04_3_Gy/hist.root";
  TString fileN05 = "../data/IrradiationTests/05_5_Gy/hist.root";
  TString fileN06 = "../data/IrradiationTests/06_5_Gy_ND/hist.root";
  TString fileN07 = "../data/IrradiationTests/07_7_Gy/hist.root";
  TString fileN08 = "../data/IrradiationTests/08_10_Gy/hist.root";
  TString fileN09 = "../data/IrradiationTests/09_20_Gy/hist.root";
  TString fileN10 = "../data/IrradiationTests/10_30_Gy/hist.root";
  //
  TFile *f01 = new TFile(fileN01.Data());
  TFile *f02 = new TFile(fileN02.Data());
  TFile *f03 = new TFile(fileN03.Data());
  TFile *f04 = new TFile(fileN04.Data());
  TFile *f05 = new TFile(fileN05.Data());
  TFile *f06 = new TFile(fileN06.Data());
  TFile *f07 = new TFile(fileN07.Data());
  TFile *f08 = new TFile(fileN08.Data());
  TFile *f09 = new TFile(fileN09.Data());
  TFile *f10 = new TFile(fileN10.Data());
  //
  TString name_gr = "";
  //
  TGraphErrors *gr_01 = (TGraphErrors*)f01->Get("gr_G0_IV_PCB1_S3_25um_wores_ch01_K2400_n1");
  TGraphErrors *gr_02 = (TGraphErrors*)f02->Get("gr_G1_IV_PCB1_S3_25um_wores_ch01_K2400_n1");
  TGraphErrors *gr_03 = (TGraphErrors*)f03->Get("gr_G2_IV_PCB1_S3_25um_wores_ch01_K2400_n1");
  TGraphErrors *gr_04 = (TGraphErrors*)f04->Get("gr_G3_IV_PCB1_S3_25um_wores_ch01_K2400_n1");
  TGraphErrors *gr_05 = (TGraphErrors*)f05->Get("gr_G5_IV_PCB1_S3_25um_wores_ch01_K2400_n1");
  TGraphErrors *gr_06 = (TGraphErrors*)f06->Get("gr_G5_IV_PCB1_S3_25um_wores_ch01_K2400_n1");
  TGraphErrors *gr_07 = (TGraphErrors*)f07->Get("gr_G7_IV_PCB1_S3_25um_wores_ch01_K2400_n1");
  TGraphErrors *gr_08 = (TGraphErrors*)f08->Get("gr_G10_IV_PCB1_S3_25um_wores_ch01_K2400_n1");
  TGraphErrors *gr_09 = (TGraphErrors*)f09->Get("gr_G20_IV_PCB1_S3_25um_wores_ch01_K2400_n1");
  TGraphErrors *gr_10 = (TGraphErrors*)f10->Get("gr_G30_IV_PCB1_S3_25um_wores_ch01_K2400_n1");
  //
  gr_01->SetMarkerStyle(1);
  gr_02->SetMarkerStyle(1);
  gr_03->SetMarkerStyle(1);
  gr_04->SetMarkerStyle(1);
  gr_05->SetMarkerStyle(1);
  gr_06->SetMarkerStyle(1);
  gr_07->SetMarkerStyle(20);
  gr_08->SetMarkerStyle(20);
  gr_09->SetMarkerStyle(20);
  gr_10->SetMarkerStyle(20);
  //
  gr_01->SetMarkerColor(kBlack);
  gr_02->SetMarkerColor(kRed);
  gr_03->SetMarkerColor(kBlue+2);
  gr_04->SetMarkerColor(kMagenta+2);
  gr_05->SetMarkerColor(kGreen+2);
  gr_06->SetMarkerColor(kGreen);
  gr_07->SetMarkerColor(kBlack);
  gr_08->SetMarkerColor(kRed);
  gr_09->SetMarkerColor(kBlue+2);
  gr_10->SetMarkerColor(kMagenta+2);
  //
  gr_01->SetLineColor(kBlack);
  gr_02->SetLineColor(kRed);
  gr_03->SetLineColor(kBlue+2);
  gr_04->SetLineColor(kMagenta+2);
  gr_05->SetLineColor(kGreen+2);
  gr_06->SetLineColor(kGreen);
  gr_07->SetLineColor(kBlack);
  gr_08->SetLineColor(kRed);
  gr_09->SetLineColor(kBlue+2);
  gr_10->SetLineColor(kMagenta+2);
  //
  gr_01->SetLineWidth(2);
  gr_02->SetLineWidth(2);
  gr_03->SetLineWidth(2);
  gr_04->SetLineWidth(2);
  gr_05->SetLineWidth(2);
  gr_06->SetLineWidth(2);
  gr_07->SetLineWidth(2);
  gr_08->SetLineWidth(2);
  gr_09->SetLineWidth(2);
  gr_10->SetLineWidth(2);
  //
  gStyle->SetPalette(1);
  gStyle->SetFrameBorderMode(0);
  gROOT->ForceStyle();
  gStyle->SetOptStat(kFALSE);
  //
  TCanvas *c1 = new TCanvas("c1","c1",10,10,1200,1000);
  c1->Divide(1,2);
  //
  c1->cd(1);
  //
  gPad->SetRightMargin(0.01);
  gPad->SetLeftMargin(0.08);
  gPad->SetTopMargin(0.02);
  gPad->SetBottomMargin(0.08);
  //
  //
  gPad->SetGridx();
  gPad->SetGridy();
  gPad->SetLogy();
  //
  TMultiGraph *mg = new TMultiGraph();
  mg->Add(gr_01);
  mg->Add(gr_02);
  mg->Add(gr_03);
  mg->Add(gr_04);
  mg->Add(gr_05);
  //mg->Add(gr_06);
  mg->Add(gr_07);
  mg->Add(gr_08);
  mg->Add(gr_09);
  mg->Add(gr_10);
  mg->GetXaxis()->SetRangeUser(32.0,60.0);
  //mg->GetYaxis()->SetRangeUser(-0.2,6.0);
  mg->SetMinimum(1.0e-10);
  mg->SetMaximum(1.0e-3);
  mg->Draw("APL");
  mg->GetXaxis()->SetTitle("V_{bias}, V");
  mg->GetYaxis()->SetTitle("Current, A");
  TLegend *leg01 = new TLegend(0.9,0.1,0.98,0.4,"","brNDC");
  leg01->AddEntry(gr_01, " 0 Gy", "pl");
  leg01->AddEntry(gr_02, " 1 Gy", "pl");
  leg01->AddEntry(gr_03, " 2 Gy", "pl");
  leg01->AddEntry(gr_04, " 3 Gy", "pl");
  leg01->AddEntry(gr_05, " 5 Gy", "pl");
  leg01->AddEntry(gr_07, " 7 Gy", "pl");
  leg01->AddEntry(gr_08, "10 Gy", "pl");
  leg01->AddEntry(gr_09, "20 Gy", "pl");
  leg01->AddEntry(gr_10, "30 Gy", "pl");
  leg01->Draw();
  //
  //
  c1->cd(2);
  gPad->SetRightMargin(0.01);
  gPad->SetLeftMargin(0.08);
  gPad->SetTopMargin(0.02);
  gPad->SetBottomMargin(0.08);
  //
  //
  gPad->SetGridx();
  gPad->SetGridy();
  gPad->SetLogy();
  //
  TGraphErrors *gr_r_01 = new TGraphErrors(); gr_r_01->SetNameTitle("gr_r_01","gr_r_01");
  TGraphErrors *gr_r_02 = new TGraphErrors(); gr_r_02->SetNameTitle("gr_r_02","gr_r_02");
  TGraphErrors *gr_r_03 = new TGraphErrors(); gr_r_03->SetNameTitle("gr_r_03","gr_r_03");
  TGraphErrors *gr_r_04 = new TGraphErrors(); gr_r_04->SetNameTitle("gr_r_04","gr_r_04");
  TGraphErrors *gr_r_05 = new TGraphErrors(); gr_r_05->SetNameTitle("gr_r_05","gr_r_05");
  TGraphErrors *gr_r_06 = new TGraphErrors(); gr_r_06->SetNameTitle("gr_r_06","gr_r_06");
  TGraphErrors *gr_r_07 = new TGraphErrors(); gr_r_07->SetNameTitle("gr_r_07","gr_r_07");
  TGraphErrors *gr_r_08 = new TGraphErrors(); gr_r_08->SetNameTitle("gr_r_08","gr_r_08");
  TGraphErrors *gr_r_09 = new TGraphErrors(); gr_r_09->SetNameTitle("gr_r_09","gr_r_09");
  TGraphErrors *gr_r_10 = new TGraphErrors(); gr_r_10->SetNameTitle("gr_r_10","gr_r_10");
  get_ration(gr_r_01, gr_01, gr_01);
  get_ration(gr_r_02, gr_02, gr_01);
  get_ration(gr_r_03, gr_03, gr_01);
  get_ration(gr_r_04, gr_04, gr_01);
  get_ration(gr_r_05, gr_05, gr_01);
  get_ration(gr_r_06, gr_06, gr_01);
  get_ration(gr_r_07, gr_07, gr_01);
  get_ration(gr_r_08, gr_08, gr_01);
  get_ration(gr_r_09, gr_09, gr_01);
  get_ration(gr_r_10, gr_10, gr_01);
  //
  gr_r_01->SetMarkerStyle(1);
  gr_r_02->SetMarkerStyle(1);
  gr_r_03->SetMarkerStyle(1);
  gr_r_04->SetMarkerStyle(1);
  gr_r_05->SetMarkerStyle(1);
  gr_r_06->SetMarkerStyle(1);
  gr_r_07->SetMarkerStyle(20);
  gr_r_08->SetMarkerStyle(20);
  gr_r_09->SetMarkerStyle(20);
  gr_r_10->SetMarkerStyle(20);
  //
  gr_r_01->SetMarkerColor(kBlack);
  gr_r_02->SetMarkerColor(kRed);
  gr_r_03->SetMarkerColor(kBlue+2);
  gr_r_04->SetMarkerColor(kMagenta+2);
  gr_r_05->SetMarkerColor(kGreen+2);
  gr_r_06->SetMarkerColor(kGreen);
  gr_r_07->SetMarkerColor(kBlack);
  gr_r_08->SetMarkerColor(kRed);
  gr_r_09->SetMarkerColor(kBlue+2);
  gr_r_10->SetMarkerColor(kMagenta+2);
  //
  gr_r_01->SetLineColor(kBlack);
  gr_r_02->SetLineColor(kRed);
  gr_r_03->SetLineColor(kBlue+2);
  gr_r_04->SetLineColor(kMagenta+2);
  gr_r_05->SetLineColor(kGreen+2);
  gr_r_06->SetLineColor(kGreen);
  gr_r_07->SetLineColor(kBlack);
  gr_r_08->SetLineColor(kRed);
  gr_r_09->SetLineColor(kBlue+2);
  gr_r_10->SetLineColor(kMagenta+2);
  //
  gr_r_01->SetLineWidth(2);
  gr_r_02->SetLineWidth(2);
  gr_r_03->SetLineWidth(2);
  gr_r_04->SetLineWidth(2);
  gr_r_05->SetLineWidth(2);
  gr_r_06->SetLineWidth(2);
  gr_r_07->SetLineWidth(2);
  gr_r_08->SetLineWidth(2);
  gr_r_09->SetLineWidth(2);
  gr_r_10->SetLineWidth(2);
  //
  TMultiGraph *mg02 = new TMultiGraph();
  mg02->Add(gr_r_01);
  mg02->Add(gr_r_02);
  mg02->Add(gr_r_03);
  mg02->Add(gr_r_04);
  mg02->Add(gr_r_05);
  mg02->Add(gr_r_07);
  mg02->Add(gr_r_08);
  mg02->Add(gr_r_09);
  mg02->Add(gr_r_10);
  mg02->GetXaxis()->SetRangeUser(32.0,60.0);
  //mg->GetYaxis()->SetRangeUser(-0.2,6.0);
  mg02->SetMinimum(5.0e-1);
  mg02->SetMaximum(1.0e+5);
  mg02->Draw("APL");
  mg02->GetXaxis()->SetTitle("V_{bias}, V");
  mg02->GetYaxis()->SetTitle("Ratio");
  //
  leg01->Draw();
  //
  TCanvas *c0 = new TCanvas("c0","c0",10,10,1200,1000);
  c0->SetRightMargin(0.0);
  c0->SetLeftMargin(0.0);
  c0->SetTopMargin(0.0);
  c0->SetBottomMargin(0.0);
  TH2D *h2 = new TH2D("","",100,0,1,100,0,1);
  //h2->Draw();
  TText *t = new TText(.5,.8,SiPM_name.Data());
  t->SetTextAlign(22);
  //t->SetTextColor(kRed+2);
  t->SetTextFont(43);
  t->SetTextSize(40);
  //t->SetTextAngle(45);
  t->Draw();
  TText *t2 = new TText(.5,.7,"Temperature: 22.0 - 25.0");
  t2->SetTextAlign(22);
  t2->SetTextFont(43);
  t2->SetTextSize(40);
  t2->Draw("same");
  //
  TText *t3 = new TText(.5,.6,"Data: 01.03.2023-02.03.2023");
  t3->SetTextAlign(22);
  t3->SetTextFont(43);
  t3->SetTextSize(40);
  t3->Draw("same");
  //
  TCanvas *c2 = new TCanvas("c2","c2",10,10,1200,1000);
  c2->SetRightMargin(0.01);
  c2->SetLeftMargin(0.12);
  c2->SetTopMargin(0.02);
  c2->SetBottomMargin(0.08);
  //
  gPad->SetGridx();
  gPad->SetGridy();
  //   
  TGraphErrors *gr_I_vs_gy = new TGraphErrors(); gr_I_vs_gy->SetNameTitle("gr_I_vs_gy","gr_I_vs_gy");
  gr_I_vs_gy->SetPoint( 0,  0.0, gr_r_01->Eval(42.0)); gr_I_vs_gy->SetPointError( 0,  0.01, get_r_error(gr_r_01, 42));
  gr_I_vs_gy->SetPoint( 1,  1.0, gr_r_02->Eval(42.0)); gr_I_vs_gy->SetPointError( 1,  0.01, get_r_error(gr_r_02, 42));
  gr_I_vs_gy->SetPoint( 2,  2.0, gr_r_03->Eval(42.0)); gr_I_vs_gy->SetPointError( 2,  0.01, get_r_error(gr_r_03, 42));
  gr_I_vs_gy->SetPoint( 3,  3.0, gr_r_04->Eval(42.0)); gr_I_vs_gy->SetPointError( 3,  0.01, get_r_error(gr_r_04, 42));
  gr_I_vs_gy->SetPoint( 4,  5.0, gr_r_05->Eval(42.0)); gr_I_vs_gy->SetPointError( 4,  0.01, get_r_error(gr_r_05, 42));
  gr_I_vs_gy->SetPoint( 5,  7.0, gr_r_07->Eval(42.0)); gr_I_vs_gy->SetPointError( 5,  0.01, get_r_error(gr_r_07, 42));
  gr_I_vs_gy->SetPoint( 6, 10.0, gr_r_08->Eval(42.0)); gr_I_vs_gy->SetPointError( 6,  0.01, get_r_error(gr_r_08, 42));
  gr_I_vs_gy->SetPoint( 7, 20.0, gr_r_09->Eval(42.0)); gr_I_vs_gy->SetPointError( 7,  0.01, get_r_error(gr_r_09, 42));
  gr_I_vs_gy->SetPoint( 8, 30.0, gr_r_10->Eval(42.0)); gr_I_vs_gy->SetPointError( 8,  0.01, get_r_error(gr_r_10, 42));
  //
  gr_I_vs_gy->SetNameTitle("","");
  gr_I_vs_gy->SetMarkerStyle(1);
  gr_I_vs_gy->SetMarkerColor(kBlack);
  gr_I_vs_gy->SetLineWidth(2.0);
  //
  gr_I_vs_gy->Draw("APL");
  gr_I_vs_gy->GetYaxis()->SetTitle("Normalised current");
  gr_I_vs_gy->GetXaxis()->SetTitle("Dose, Gy");
  //
  TString pdf_out_01 = SiPM_name; pdf_out_01 += "_01.pdf";
  TString pdf_out_02 = SiPM_name; pdf_out_02 += "_02.pdf";
  TString pdf_out_03 = SiPM_name; pdf_out_03 += "_03.pdf"; 
  //
  c0->SaveAs(pdf_out_01.Data());
  c1->SaveAs(pdf_out_02.Data());
  c2->SaveAs(pdf_out_03.Data());
  //
  TString outputRootFile = "hist_";
  outputRootFile += SiPM_name;
  outputRootFile += ".root";
  //
  TFile* rootFile = new TFile(outputRootFile.Data(), "RECREATE", " Histograms", 1);
  rootFile->cd();
  if (rootFile->IsZombie()){
    std::cout<<"  ERROR ---> file "<<outputRootFile.Data()<<" is zombi"<<std::endl;
    assert(0);
  }
  c0->Write();
  c1->Write();
  c2->Write();
  //
  gr_I_vs_gy->Write();
  //
  return 0;
}

Int_t plots_IV_30um_wores_ch01_K2400(TString SiPM_name){
  //
  TString fileN01 = "../data/IrradiationTests/01_0_Gy/hist.root";
  TString fileN02 = "../data/IrradiationTests/02_1_Gy/hist.root";
  TString fileN03 = "../data/IrradiationTests/03_2_Gy/hist.root";
  TString fileN04 = "../data/IrradiationTests/04_3_Gy/hist.root";
  TString fileN05 = "../data/IrradiationTests/05_5_Gy/hist.root";
  TString fileN06 = "../data/IrradiationTests/06_5_Gy_ND/hist.root";
  TString fileN07 = "../data/IrradiationTests/07_7_Gy/hist.root";
  TString fileN08 = "../data/IrradiationTests/08_10_Gy/hist.root";
  TString fileN09 = "../data/IrradiationTests/09_20_Gy/hist.root";
  TString fileN10 = "../data/IrradiationTests/10_30_Gy/hist.root";
  //
  TFile *f01 = new TFile(fileN01.Data());
  TFile *f02 = new TFile(fileN02.Data());
  TFile *f03 = new TFile(fileN03.Data());
  TFile *f04 = new TFile(fileN04.Data());
  TFile *f05 = new TFile(fileN05.Data());
  TFile *f06 = new TFile(fileN06.Data());
  TFile *f07 = new TFile(fileN07.Data());
  TFile *f08 = new TFile(fileN08.Data());
  TFile *f09 = new TFile(fileN09.Data());
  TFile *f10 = new TFile(fileN10.Data());
  //
  TString name_gr = "";
  //
  TGraphErrors *gr_01 = (TGraphErrors*)f01->Get("gr_G0_IV_PCB1_S3_30um_wores_ch01_K2400_n1");
  TGraphErrors *gr_02 = (TGraphErrors*)f02->Get("gr_G1_IV_PCB1_S3_30um_wores_ch01_K2400_n1");
  TGraphErrors *gr_03 = (TGraphErrors*)f03->Get("gr_G2_IV_PCB1_S3_30um_wores_ch01_K2400_n1");
  TGraphErrors *gr_04 = (TGraphErrors*)f04->Get("gr_G3_IV_PCB1_S3_30um_wores_ch01_K2400_n1");
  TGraphErrors *gr_05 = (TGraphErrors*)f05->Get("gr_G5_IV_PCB1_S3_30um_wores_ch01_K2400_n1");
  TGraphErrors *gr_06 = (TGraphErrors*)f06->Get("gr_G5_IV_PCB1_S3_30um_wores_ch01_K2400_n1");
  TGraphErrors *gr_07 = (TGraphErrors*)f07->Get("gr_G7_IV_PCB1_S3_30um_wores_ch01_K2400_n1");
  TGraphErrors *gr_08 = (TGraphErrors*)f08->Get("gr_G10_IV_PCB1_S3_30um_wores_ch01_K2400_n1");
  TGraphErrors *gr_09 = (TGraphErrors*)f09->Get("gr_G20_IV_PCB1_S3_30um_wores_ch01_K2400_n1");
  TGraphErrors *gr_10 = (TGraphErrors*)f10->Get("gr_G30_IV_PCB1_S3_30um_wores_ch01_K2400_n1");
  //
  gr_01->SetMarkerStyle(1);
  gr_02->SetMarkerStyle(1);
  gr_03->SetMarkerStyle(1);
  gr_04->SetMarkerStyle(1);
  gr_05->SetMarkerStyle(1);
  gr_06->SetMarkerStyle(1);
  gr_07->SetMarkerStyle(20);
  gr_08->SetMarkerStyle(20);
  gr_09->SetMarkerStyle(20);
  gr_10->SetMarkerStyle(20);
  //
  gr_01->SetMarkerColor(kBlack);
  gr_02->SetMarkerColor(kRed);
  gr_03->SetMarkerColor(kBlue+2);
  gr_04->SetMarkerColor(kMagenta+2);
  gr_05->SetMarkerColor(kGreen+2);
  gr_06->SetMarkerColor(kGreen);
  gr_07->SetMarkerColor(kBlack);
  gr_08->SetMarkerColor(kRed);
  gr_09->SetMarkerColor(kBlue+2);
  gr_10->SetMarkerColor(kMagenta+2);
  //
  gr_01->SetLineColor(kBlack);
  gr_02->SetLineColor(kRed);
  gr_03->SetLineColor(kBlue+2);
  gr_04->SetLineColor(kMagenta+2);
  gr_05->SetLineColor(kGreen+2);
  gr_06->SetLineColor(kGreen);
  gr_07->SetLineColor(kBlack);
  gr_08->SetLineColor(kRed);
  gr_09->SetLineColor(kBlue+2);
  gr_10->SetLineColor(kMagenta+2);
  //
  gr_01->SetLineWidth(2);
  gr_02->SetLineWidth(2);
  gr_03->SetLineWidth(2);
  gr_04->SetLineWidth(2);
  gr_05->SetLineWidth(2);
  gr_06->SetLineWidth(2);
  gr_07->SetLineWidth(2);
  gr_08->SetLineWidth(2);
  gr_09->SetLineWidth(2);
  gr_10->SetLineWidth(2);
  //
  gStyle->SetPalette(1);
  gStyle->SetFrameBorderMode(0);
  gROOT->ForceStyle();
  gStyle->SetOptStat(kFALSE);
  //
  TCanvas *c1 = new TCanvas("c1","c1",10,10,1200,1000);
  c1->Divide(1,2);
  //
  c1->cd(1);
  //
  gPad->SetRightMargin(0.01);
  gPad->SetLeftMargin(0.08);
  gPad->SetTopMargin(0.02);
  gPad->SetBottomMargin(0.08);
  //
  //
  gPad->SetGridx();
  gPad->SetGridy();
  gPad->SetLogy();
  //
  TMultiGraph *mg = new TMultiGraph();
  mg->Add(gr_01);
  mg->Add(gr_02);
  mg->Add(gr_03);
  mg->Add(gr_04);
  mg->Add(gr_05);
  //mg->Add(gr_06);
  mg->Add(gr_07);
  mg->Add(gr_08);
  mg->Add(gr_09);
  mg->Add(gr_10);
  mg->GetXaxis()->SetRangeUser(32.0,60.0);
  //mg->GetYaxis()->SetRangeUser(-0.2,6.0);
  mg->SetMinimum(1.0e-10);
  mg->SetMaximum(1.0e-3);
  mg->Draw("APL");
  mg->GetXaxis()->SetTitle("V_{bias}, V");
  mg->GetYaxis()->SetTitle("Current, A");
  TLegend *leg01 = new TLegend(0.9,0.1,0.98,0.4,"","brNDC");
  leg01->AddEntry(gr_01, " 0 Gy", "pl");
  leg01->AddEntry(gr_02, " 1 Gy", "pl");
  leg01->AddEntry(gr_03, " 2 Gy", "pl");
  leg01->AddEntry(gr_04, " 3 Gy", "pl");
  leg01->AddEntry(gr_05, " 5 Gy", "pl");
  leg01->AddEntry(gr_07, " 7 Gy", "pl");
  leg01->AddEntry(gr_08, "10 Gy", "pl");
  leg01->AddEntry(gr_09, "20 Gy", "pl");
  leg01->AddEntry(gr_10, "30 Gy", "pl");
  leg01->Draw();
  //
  //
  c1->cd(2);
  gPad->SetRightMargin(0.01);
  gPad->SetLeftMargin(0.08);
  gPad->SetTopMargin(0.02);
  gPad->SetBottomMargin(0.08);
  //
  //
  gPad->SetGridx();
  gPad->SetGridy();
  gPad->SetLogy();
  //
  TGraphErrors *gr_r_01 = new TGraphErrors(); gr_r_01->SetNameTitle("gr_r_01","gr_r_01");
  TGraphErrors *gr_r_02 = new TGraphErrors(); gr_r_02->SetNameTitle("gr_r_02","gr_r_02");
  TGraphErrors *gr_r_03 = new TGraphErrors(); gr_r_03->SetNameTitle("gr_r_03","gr_r_03");
  TGraphErrors *gr_r_04 = new TGraphErrors(); gr_r_04->SetNameTitle("gr_r_04","gr_r_04");
  TGraphErrors *gr_r_05 = new TGraphErrors(); gr_r_05->SetNameTitle("gr_r_05","gr_r_05");
  TGraphErrors *gr_r_06 = new TGraphErrors(); gr_r_06->SetNameTitle("gr_r_06","gr_r_06");
  TGraphErrors *gr_r_07 = new TGraphErrors(); gr_r_07->SetNameTitle("gr_r_07","gr_r_07");
  TGraphErrors *gr_r_08 = new TGraphErrors(); gr_r_08->SetNameTitle("gr_r_08","gr_r_08");
  TGraphErrors *gr_r_09 = new TGraphErrors(); gr_r_09->SetNameTitle("gr_r_09","gr_r_09");
  TGraphErrors *gr_r_10 = new TGraphErrors(); gr_r_10->SetNameTitle("gr_r_10","gr_r_10");
  get_ration(gr_r_01, gr_01, gr_01);
  get_ration(gr_r_02, gr_02, gr_01);
  get_ration(gr_r_03, gr_03, gr_01);
  get_ration(gr_r_04, gr_04, gr_01);
  get_ration(gr_r_05, gr_05, gr_01);
  get_ration(gr_r_06, gr_06, gr_01);
  get_ration(gr_r_07, gr_07, gr_01);
  get_ration(gr_r_08, gr_08, gr_01);
  get_ration(gr_r_09, gr_09, gr_01);
  get_ration(gr_r_10, gr_10, gr_01);
  //
  gr_r_01->SetMarkerStyle(1);
  gr_r_02->SetMarkerStyle(1);
  gr_r_03->SetMarkerStyle(1);
  gr_r_04->SetMarkerStyle(1);
  gr_r_05->SetMarkerStyle(1);
  gr_r_06->SetMarkerStyle(1);
  gr_r_07->SetMarkerStyle(20);
  gr_r_08->SetMarkerStyle(20);
  gr_r_09->SetMarkerStyle(20);
  gr_r_10->SetMarkerStyle(20);
  //
  gr_r_01->SetMarkerColor(kBlack);
  gr_r_02->SetMarkerColor(kRed);
  gr_r_03->SetMarkerColor(kBlue+2);
  gr_r_04->SetMarkerColor(kMagenta+2);
  gr_r_05->SetMarkerColor(kGreen+2);
  gr_r_06->SetMarkerColor(kGreen);
  gr_r_07->SetMarkerColor(kBlack);
  gr_r_08->SetMarkerColor(kRed);
  gr_r_09->SetMarkerColor(kBlue+2);
  gr_r_10->SetMarkerColor(kMagenta+2);
  //
  gr_r_01->SetLineColor(kBlack);
  gr_r_02->SetLineColor(kRed);
  gr_r_03->SetLineColor(kBlue+2);
  gr_r_04->SetLineColor(kMagenta+2);
  gr_r_05->SetLineColor(kGreen+2);
  gr_r_06->SetLineColor(kGreen);
  gr_r_07->SetLineColor(kBlack);
  gr_r_08->SetLineColor(kRed);
  gr_r_09->SetLineColor(kBlue+2);
  gr_r_10->SetLineColor(kMagenta+2);
  //
  gr_r_01->SetLineWidth(2);
  gr_r_02->SetLineWidth(2);
  gr_r_03->SetLineWidth(2);
  gr_r_04->SetLineWidth(2);
  gr_r_05->SetLineWidth(2);
  gr_r_06->SetLineWidth(2);
  gr_r_07->SetLineWidth(2);
  gr_r_08->SetLineWidth(2);
  gr_r_09->SetLineWidth(2);
  gr_r_10->SetLineWidth(2);
  //
  TMultiGraph *mg02 = new TMultiGraph();
  mg02->Add(gr_r_01);
  mg02->Add(gr_r_02);
  mg02->Add(gr_r_03);
  mg02->Add(gr_r_04);
  mg02->Add(gr_r_05);
  mg02->Add(gr_r_07);
  mg02->Add(gr_r_08);
  mg02->Add(gr_r_09);
  mg02->Add(gr_r_10);
  mg02->GetXaxis()->SetRangeUser(32.0,60.0);
  //mg->GetYaxis()->SetRangeUser(-0.2,6.0);
  mg02->SetMinimum(5.0e-1);
  mg02->SetMaximum(1.0e+5);
  mg02->Draw("APL");
  mg02->GetXaxis()->SetTitle("V_{bias}, V");
  mg02->GetYaxis()->SetTitle("Ratio");
  //
  leg01->Draw();
  //
  TCanvas *c0 = new TCanvas("c0","c0",10,10,1200,1000);
  c0->SetRightMargin(0.0);
  c0->SetLeftMargin(0.0);
  c0->SetTopMargin(0.0);
  c0->SetBottomMargin(0.0);
  TH2D *h2 = new TH2D("","",100,0,1,100,0,1);
  //h2->Draw();
  TText *t = new TText(.5,.8,SiPM_name.Data());
  t->SetTextAlign(22);
  //t->SetTextColor(kRed+2);
  t->SetTextFont(43);
  t->SetTextSize(40);
  //t->SetTextAngle(45);
  t->Draw();
  TText *t2 = new TText(.5,.7,"Temperature: 22.0 - 25.0");
  t2->SetTextAlign(22);
  t2->SetTextFont(43);
  t2->SetTextSize(40);
  t2->Draw("same");
  //
  TText *t3 = new TText(.5,.6,"Data: 01.03.2023-02.03.2023");
  t3->SetTextAlign(22);
  t3->SetTextFont(43);
  t3->SetTextSize(40);
  t3->Draw("same");
  //
  TCanvas *c2 = new TCanvas("c2","c2",10,10,1200,1000);
  c2->SetRightMargin(0.01);
  c2->SetLeftMargin(0.12);
  c2->SetTopMargin(0.02);
  c2->SetBottomMargin(0.08);
  //
  gPad->SetGridx();
  gPad->SetGridy();
  //   
  TGraphErrors *gr_I_vs_gy = new TGraphErrors(); gr_I_vs_gy->SetNameTitle("gr_I_vs_gy","gr_I_vs_gy");
  gr_I_vs_gy->SetPoint( 0,  0.0, gr_r_01->Eval(42.0)); gr_I_vs_gy->SetPointError( 0,  0.01, get_r_error(gr_r_01, 42));
  gr_I_vs_gy->SetPoint( 1,  1.0, gr_r_02->Eval(42.0)); gr_I_vs_gy->SetPointError( 1,  0.01, get_r_error(gr_r_02, 42));
  gr_I_vs_gy->SetPoint( 2,  2.0, gr_r_03->Eval(42.0)); gr_I_vs_gy->SetPointError( 2,  0.01, get_r_error(gr_r_03, 42));
  gr_I_vs_gy->SetPoint( 3,  3.0, gr_r_04->Eval(42.0)); gr_I_vs_gy->SetPointError( 3,  0.01, get_r_error(gr_r_04, 42));
  gr_I_vs_gy->SetPoint( 4,  5.0, gr_r_05->Eval(42.0)); gr_I_vs_gy->SetPointError( 4,  0.01, get_r_error(gr_r_05, 42));
  gr_I_vs_gy->SetPoint( 5,  7.0, gr_r_07->Eval(42.0)); gr_I_vs_gy->SetPointError( 5,  0.01, get_r_error(gr_r_07, 42));
  gr_I_vs_gy->SetPoint( 6, 10.0, gr_r_08->Eval(42.0)); gr_I_vs_gy->SetPointError( 6,  0.01, get_r_error(gr_r_08, 42));
  gr_I_vs_gy->SetPoint( 7, 20.0, gr_r_09->Eval(42.0)); gr_I_vs_gy->SetPointError( 7,  0.01, get_r_error(gr_r_09, 42));
  gr_I_vs_gy->SetPoint( 8, 30.0, gr_r_10->Eval(42.0)); gr_I_vs_gy->SetPointError( 8,  0.01, get_r_error(gr_r_10, 42));
  //
  gr_I_vs_gy->SetNameTitle("","");
  gr_I_vs_gy->SetMarkerStyle(1);
  gr_I_vs_gy->SetMarkerColor(kBlack);
  gr_I_vs_gy->SetLineWidth(2.0);
  //
  gr_I_vs_gy->Draw("APL");
  gr_I_vs_gy->GetYaxis()->SetTitle("Normalised current");
  gr_I_vs_gy->GetXaxis()->SetTitle("Dose, Gy");
  //
  TString pdf_out_01 = SiPM_name; pdf_out_01 += "_01.pdf";
  TString pdf_out_02 = SiPM_name; pdf_out_02 += "_02.pdf";
  TString pdf_out_03 = SiPM_name; pdf_out_03 += "_03.pdf"; 
  //
  c0->SaveAs(pdf_out_01.Data());
  c1->SaveAs(pdf_out_02.Data());
  c2->SaveAs(pdf_out_03.Data());
  //
  TString outputRootFile = "hist_";
  outputRootFile += SiPM_name;
  outputRootFile += ".root";
  //
  TFile* rootFile = new TFile(outputRootFile.Data(), "RECREATE", " Histograms", 1);
  rootFile->cd();
  if (rootFile->IsZombie()){
    std::cout<<"  ERROR ---> file "<<outputRootFile.Data()<<" is zombi"<<std::endl;
    assert(0);
  }
  c0->Write();
  c1->Write();
  c2->Write();
  //
  gr_I_vs_gy->Write();
  //
  return 0;
}

void get_ration(TGraphErrors *gr_r, TGraphErrors *gr, TGraphErrors *gr_n){
  Int_t n = gr->GetN();
  Int_t nr = 0;
  Double_t v, c, cn, r;
  Double_t v_err, c_err, cn_err, r_err;
  Double_t vmax_norm = max_range_gr(gr_n);
  for(Int_t i = 0;i<n;i++){
    gr->GetPoint(i,v,c);
    if(vmax_norm>=v){
      cn = gr_n->Eval(v);
      v_err = get_volt_err(v);
      c_err = get_curr_err(c);
      cn_err = get_curr_err(cn);
      if(cn>0.0 && c>0.0){
	r = c/cn;
	r_err = r*TMath::Sqrt(c_err/c*c_err/c + cn_err/cn*cn_err/cn);
	gr_r->SetPoint( nr, v, r);
	gr_r->SetPointError( nr, v_err, r_err);
	nr++;
      }
    }
  }
}

Double_t max_range_gr(TGraphErrors *gr){
  Int_t n = gr->GetN();
  Double_t v, c;
  Double_t v_max = -999.0;
  for(Int_t i = 0;i<n;i++){
    gr->GetPoint(i,v,c);
    if(v_max<v)
      v_max = v;
  }
  return v_max;
}

Double_t get_volt_err(Double_t Voltage){
  return 0.01;
}

Double_t get_curr_err(Double_t Current){
  return Current/10.0 + 1.0e-9;
}

Double_t get_r_error(TGraphErrors *gr_r, Double_t vval){
  Int_t n = gr_r->GetN();
  Double_t dV = 1.0;
  Double_t v, r;
  Double_t r_err;
  for(Int_t i = 0; i<n;i++){
    gr_r->GetPoint(i,v,r);
    r_err = gr_r->GetErrorY(i);
    if((v-dV <= vval) && (v+dV >= vval)){
      return r_err;
    }
  }
  return 0.0;
}
