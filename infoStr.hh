#ifndef infoStr_hh
#define infoStr_hh

//root
#include "TROOT.h"

//C, C++
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <assert.h>
#include <vector>
#include <iomanip>

struct infoStr {
  //filename doseapprox type PCBID sampleID cells w_wo_res chID KID sampleID2 temperature date time irradiationtime dose_in_H2O fluence flux radsession
  //G0_IV_PCB1_S3_30um_wores_K6487.txt      0 IV PCB1 S3 30um wores ch01 K6487 n1 22.0 01.03.2023 15:00 68 1 -999.0 -999.0 0
  std::vector<TString> filename;
  std::vector<Double_t> doseapprox;
  std::vector<TString> type;
  std::vector<TString> PCBID;
  std::vector<TString> sampleID;
  std::vector<TString> cells;
  std::vector<TString> w_wo_res;
  std::vector<TString> chID;
  std::vector<TString> KID;
  std::vector<TString> sampleID2;
  std::vector<Double_t> temperature;
  std::vector<TString> date;
  std::vector<TString> time;
  std::vector<Double_t> irradiationtime;
  std::vector<Double_t> dose_in_H2O;
  std::vector<Double_t> fluence;
  std::vector<Double_t> flux;
  std::vector<Double_t> radsession;
  //
  std::vector<TString> gr_name_title;
  std::vector<TString> filename_full;
  //
  infoStr(){
  }
  void printInfo(){
    std::cout<<"-----------------------------------------------------------------------------------------------------------------------------------------------------------"<<std::endl;
    std::cout<<"filename doseapprox type PCBID sampleID cells w_wo_res chID KID sampleID2 temperature date time irradiationtime dose_in_H2O fluence flux radsession"<<std::endl;
    for(unsigned int i = 0;i<filename.size();i++){
      std::cout<<std::setw(50)<<filename.at(i)
	       <<std::setw(5)<<doseapprox.at(i)
	       <<std::setw(5)<<type.at(i)
	       <<std::setw(5)<<PCBID.at(i)
	       <<std::setw(5)<<sampleID.at(i)
	       <<std::setw(5)<<cells.at(i)
	       <<std::setw(10)<<w_wo_res.at(i)
	       <<std::setw(5)<<chID.at(i)
	       <<std::setw(10)<<KID.at(i)
	       <<std::setw(5)<<sampleID2.at(i)
	       <<std::setw(5)<<temperature.at(i)
	       <<std::setw(10)<<date.at(i)
	       <<std::setw(10)<<time.at(i)
	       <<std::setw(5)<<irradiationtime.at(i)
	       <<std::setw(5)<<dose_in_H2O.at(i)
	       <<std::setw(5)<<fluence.at(i)
	       <<std::setw(5)<<flux.at(i)
	       <<std::setw(5)<<radsession.at(i)<<std::endl;
      //std::cout<<std::setw(50)<<gr_name_title.at(i)<<std::endl;
    }
    std::cout<<"-----------------------------------------------------------------------------------------------------------------------------------------------------------"<<std::endl;
  }  
  void readFromFile(TString name){
    //
    std::string mot;
    //
    TString filename_v;
    Double_t doseapprox_v;
    TString type_v;
    TString PCBID_v;
    TString sampleID_v;
    TString cells_v;
    TString w_wo_res_v;
    TString chID_v;
    TString KID_v;
    TString sampleID2_v;
    Double_t temperature_v;
    TString date_v;
    TString time_v;
    Double_t irradiationtime_v;
    Double_t dose_in_H2O_v;
    Double_t fluence_v;
    Double_t flux_v;
    Double_t radsession_v;
    //
    TString gr_name_title_v;
    //
    std::ifstream confFile(name.Data());
    //
    if (confFile.is_open()) {
      for(Int_t i = 0; i<18 ;i++)
	confFile>>mot;
      while(confFile>>
	    filename_v>>
	    doseapprox_v>>
	    type_v>>
	    PCBID_v>>
	    sampleID_v>>
	    cells_v>>
	    w_wo_res_v>>
	    chID_v>>
	    KID_v>>
	    sampleID2_v>>
	    temperature_v>>
	    date_v>>
	    time_v>>
	    irradiationtime_v>>
	    dose_in_H2O_v>>
	    fluence_v>>
	    flux_v>>
	    radsession_v){
	filename.push_back(filename_v);
	doseapprox.push_back(doseapprox_v);
	type.push_back(type_v);
	PCBID.push_back(PCBID_v);
	sampleID.push_back(sampleID_v);
	cells.push_back(cells_v);
	w_wo_res.push_back(w_wo_res_v);
	chID.push_back(chID_v);
	KID.push_back(KID_v);
	sampleID2.push_back(sampleID2_v);
	temperature.push_back(temperature_v);
	date.push_back(date_v);
	time.push_back(time_v);
	irradiationtime.push_back(irradiationtime_v);
	dose_in_H2O.push_back(dose_in_H2O_v);
	fluence.push_back(fluence_v);
	flux.push_back(flux_v);
	radsession.push_back(radsession_v);
	//
	gr_name_title_v = "gr_G";
	gr_name_title_v += doseapprox_v; gr_name_title_v += "_";
	gr_name_title_v += type_v; gr_name_title_v += "_";
	gr_name_title_v += PCBID_v; gr_name_title_v += "_";
	gr_name_title_v += sampleID_v; gr_name_title_v += "_";
	gr_name_title_v += cells_v; gr_name_title_v += "_";
	gr_name_title_v += w_wo_res_v; gr_name_title_v += "_";
	gr_name_title_v += chID_v; gr_name_title_v += "_";
	gr_name_title_v += KID_v; gr_name_title_v += "_";
	gr_name_title_v += sampleID2_v;
	//
	gr_name_title.push_back(gr_name_title_v);
      }
      confFile.close();
    }
    else {
      std::cout << "Unable to open file"<<std::endl; 
      assert(0);
    }
  }
};

#endif
