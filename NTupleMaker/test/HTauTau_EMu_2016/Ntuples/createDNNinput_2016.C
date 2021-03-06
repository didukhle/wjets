#include <iostream>
#include <map>

#include "TString.h"
#include "TFile.h"
#include "TTree.h"
#include "TH1.h"

double luminosity = 35866;

double getNEventsProcessed(TString filename)
{
  TFile * file = new TFile(filename);
  TH1D * histWeightsH = (TH1D*)file->Get("histWeightsH");
  double nevents = histWeightsH->GetSumOfWeights();
  file -> Close();
  delete file;
  return nevents;
}

void createDNNinput_2016(TString inputDir="/nfs/dust/cms/user/mameyer/SM_HiggsTauTau/CMSSW_8_0_29/src/DesyTauAnalyses/NTupleMaker/test/HTauTau_EMu_2016/NTuples"){

  // Define the subsamples that belong to a certain proccess
  vector<TString> MuonEG_Run2016  = { "MuonEG_Run2016B" , "MuonEG_Run2016C" , "MuonEG_Run2016D" , "MuonEG_Run2016E" , "MuonEG_Run2016F" , "MuonEG_Run2016G" , "MuonEG_Run2016H" };
  vector<TString> DYJets          = { "DY1JetsToLL_M-50" , "DY2JetsToLL_M-50" , "DY3JetsToLL_M-50" , "DY4JetsToLL_M-50" , "DYJetsToLL_M-50" , "DYJetsToLL_M-10to50" /*, "EWKZ2Jets_ZToLL_M-50"*/ };
  vector<TString> WJets           = { "W1JetsToLNu" , "W2JetsToLNu" , "W3JetsToLNu" , "W4JetsToLNu" , "WJetsToLNu" , "WGToLNuG" , "WGstarToLNuEE" , "WGstarToLNuMuMu" /*, "EWKWPlus2Jets_WToLNu" , "EWKWMinus2Jets_WToLNu"*/ };
  vector<TString> TTbar           = { "TTbar" };
  vector<TString> SingleTop       = { "ST_t-channel_antitop" , "ST_t-channel_top" , "ST_tW_antitop" , "ST_tW_antitop" };
  vector<TString> Diboson         = { "VVTo2L2Nu" , "WZJToLLLNu" , "WZTo1L1Nu2Q" , "WZTo1L3Nu" , "WZTo2L2Q" , "ZZTo2L2Q" , "ZZTo4L" , "WWToLNuQQ" };
  vector<TString> GluGluHToTauTau = { "GluGluHToTauTau_M125" };
  vector<TString> VBFHToTauTau    = { "VBFHToTauTau_M125" };

  // Mapping of subsamples to output root-file
  TString version = "v1";
  TString channel = "em";
  map< TString , vector<TString> > samples_map = {
    { "MuonEG_Run2016_dnn_" + channel + "_" + version , MuonEG_Run2016 },
    { "DYJets_dnn_" + channel + "_" +version          , DYJets  },
    { "WJets_dnn_" + channel + "_" +version           , WJets  },
    { "TTbar_dnn_" + channel + "_" +version           , TTbar },
    { "SingleTop_dnn_" + channel + "_" +version       , SingleTop },
    { "Diboson_dnn_" + channel + "_" +version         , Diboson },
    { "ggH_dnn_" + channel + "_" +version             , GluGluHToTauTau  },
    { "VBFH_dnn_" + channel + "_" +version            , VBFHToTauTau  }
  };

  // Cross-section map (taken from AN2016_355_v10 with minor unrelevant deviations - everything was checked)
  map<TString, double> xsec_map = {
    { "DYJetsToLL_M-10to50"      , 18610 },
    { "DYJetsToLL_M-50"          , 5765 },
    { "DY1JetsToLL_M-50"         , 1.164*1012.5 },
    { "DY2JetsToLL_M-50"         , 1.164*332.8 },
    { "DY3JetsToLL_M-50"         , 1.164*101.8 },
    { "DY4JetsToLL_M-50"         , 1.164*54.8 },
    { "WJetsToLNu"               , 61526.7 },
    { "W1JetsToLNu"              , 1.221*9644.5 },
    { "W2JetsToLNu"              , 1.221*3144.5 },
    { "W3JetsToLNu"              , 1.221*954.8 },
    { "W4JetsToLNu"              , 1.221*485.6 },
    { "TTbar"                    , 831.76 },
    { "ST_t-channel_antitop"     , 80.95 },
    { "ST_t-channel_top"         , 136.02 },
    { "ST_tW_antitop"            , 35.6 },
    { "ST_tW_top"                , 35.6 },
    { "VVTo2L2Nu"                , 11.95 },
    { "WWToLNuQQ"                , 49.997 },
    { "WZTo2L2Q"                 , 5.595 },
    { "WZTo1L1Nu2Q"              , 10.71 },
    { "WZTo1L3Nu"                , 3.05 },
    { "WZJToLLLNu"               , 5.26 },
    { "ZZTo4L"                   , 1.212 },
    { "ZZTo2L2Q"                 , 3.22 },
    { "WGToLNuG"                 , 489.0 },
    { "WGstarToLNuMuMu"          , 2.793 },
    { "WGstarToLNuEE"            , 3.526 },
    { "EWKWPlus2Jets_WToLNu"     , 25.62 },
    { "EWKWMinus2Jets_WToLNu"    , 20.20 },
    { "EWKZ2Jets_ZToLL_M-50"     , 3.987 },
    { "GluGluHToTauTau_M125"     , 48.58*0.0627 },
    { "VBFHToTauTau_M125"        , 3.782*0.0627 }
  };

  // Needed for stitching
  double xsecWIncl      = xsec_map["WJetsToLNu"];
  double xsecW1Jets     = xsec_map["W1JetsToLNu"];
  double xsecW2Jets     = xsec_map["W2JetsToLNu"];
  double xsecW3Jets     = xsec_map["W3JetsToLNu"];
  double xsecW4Jets     = xsec_map["W4JetsToLNu"];
  double xsecDYIncl     = xsec_map["DYJetsToLL_M-50"];
  double xsecDY1Jets    = xsec_map["DY1JetsToLL_M-50"];
  double xsecDY2Jets    = xsec_map["DY2JetsToLL_M-50"];
  double xsecDY3Jets    = xsec_map["DY3JetsToLL_M-50"];
  double xsecDY4Jets    = xsec_map["DY4JetsToLL_M-50"];
  double neventsWIncl   = getNEventsProcessed(inputDir+"/WJetsToLNu.root");
  double neventsW1Jets  = getNEventsProcessed(inputDir+"/W1JetsToLNu.root");
  double neventsW2Jets  = getNEventsProcessed(inputDir+"/W2JetsToLNu.root");
  double neventsW3Jets  = getNEventsProcessed(inputDir+"/W3JetsToLNu.root");
  double neventsW4Jets  = getNEventsProcessed(inputDir+"/W4JetsToLNu.root");
  double neventsDYIncl  = getNEventsProcessed(inputDir+"/DYJetsToLL_M-50.root");
  double neventsDY1Jets = getNEventsProcessed(inputDir+"/DY1JetsToLL_M-50.root");
  double neventsDY2Jets = getNEventsProcessed(inputDir+"/DY2JetsToLL_M-50.root");
  double neventsDY3Jets = getNEventsProcessed(inputDir+"/DY3JetsToLL_M-50.root");
  double neventsDY4Jets = getNEventsProcessed(inputDir+"/DY4JetsToLL_M-50.root");
  
  // Loop over all samples
  for (auto const& sample : samples_map){

    cout << endl << sample.first << "  :  " << endl ;

    TFile *outFile = new TFile(sample.first + ".root","RECREATE");
    TTree *outTree = new TTree("TauCheck", "tree created as DNN input");
    bool firstTree = true;

    for(auto const& subsample: sample.second) {

      cout << "  - " << subsample << endl;

      TFile *inFile  = new TFile( inputDir + "/" + subsample + ".root" ,"READ");
      TTree *inTree  = (TTree*) inFile -> Get("TauCheck");
      double nevents = getNEventsProcessed( inputDir + "/" + subsample + ".root" );

      // SetBranchAddress for variables that need are needed for preselection or stitching
      unsigned int npartons;
      float iso_1;
      float iso_2;
      bool extraelec_veto;
      bool extramuon_veto;
      float pt_1;
      float pt_2;
      bool metFilters;
      bool trg_muonelectron;
      inTree->SetBranchAddress("npartons",&npartons);
      inTree->SetBranchAddress("iso_1",&iso_1);
      inTree->SetBranchAddress("iso_2",&iso_2);
      inTree->SetBranchAddress("extraelec_veto",&extraelec_veto);
      inTree->SetBranchAddress("extramuon_veto",&extramuon_veto);
      inTree->SetBranchAddress("pt_1",&pt_1);
      inTree->SetBranchAddress("pt_2",&pt_2);
      inTree->SetBranchAddress("metFilters",&metFilters);
      inTree->SetBranchAddress("trg_muonelectron",&trg_muonelectron);

      // Create a branch for lumi_xsec_weight
      outFile->cd();
      float lumi_xsec_weight;
      if(firstTree){
	outTree    = inTree->CloneTree(0);
	TBranch *w = outTree->Branch("lumi_xsec_weight", &lumi_xsec_weight, "lumi_xsec_weight/F");
	firstTree  = false;
      }
      outTree->SetBranchAddress("lumi_xsec_weight",&lumi_xsec_weight);

      for (int i=0; i<inTree->GetEntries(); i++) {
	inTree->GetEntry(i);

	// Add here preselection if necessary
	if( iso_1 > 0.15 )              continue;
	if( iso_2 > 0.2)                continue;
	if( extraelec_veto > 0.5)       continue;
	if( extramuon_veto > 0.5)       continue;
	if( TMath::Max(pt_1,pt_2) < 24) continue;
	if( metFilters < 0.5 )          continue;
	if( trg_muonelectron < 0.5 )    continue;

	// lumi-xsec-weight added
	if( xsec_map.find(subsample) == xsec_map.end() && !sample.first.Contains("MuonEG")){
	  cout << endl << endl << "Sample " << subsample << " is missing in xsec_map. Exit code." << endl << endl ;
	  exit(-1);
	}
	lumi_xsec_weight = xsec_map[subsample]*luminosity/nevents;
	
	// Stitching only for wjets MC in n-jet binned samples in npartons
	if( sample.first.Contains("WJets") ){
	  if(npartons == 1)      lumi_xsec_weight = luminosity / ( neventsW1Jets/xsecW1Jets + neventsWIncl/xsecWIncl );
	  else if(npartons == 2) lumi_xsec_weight = luminosity / ( neventsW2Jets/xsecW2Jets + neventsWIncl/xsecWIncl );
	  else if(npartons == 3) lumi_xsec_weight = luminosity / ( neventsW3Jets/xsecW3Jets + neventsWIncl/xsecWIncl );
	  else if(npartons == 4) lumi_xsec_weight = luminosity / ( neventsW4Jets/xsecW4Jets + neventsWIncl/xsecWIncl );
	  else                   lumi_xsec_weight = luminosity / ( neventsWIncl/xsecWIncl );
	}
	else if( sample.first.Contains("DYJets") ){
	  if(npartons == 1)      lumi_xsec_weight = luminosity / ( neventsDY1Jets/xsecDY1Jets + neventsDYIncl/xsecDYIncl );
	  else if(npartons == 2) lumi_xsec_weight = luminosity / ( neventsDY2Jets/xsecDY2Jets + neventsDYIncl/xsecDYIncl );
	  else if(npartons == 3) lumi_xsec_weight = luminosity / ( neventsDY3Jets/xsecDY3Jets + neventsDYIncl/xsecDYIncl );
	  else if(npartons == 4) lumi_xsec_weight = luminosity / ( neventsDY4Jets/xsecDY4Jets + neventsDYIncl/xsecDYIncl );
	  else                   lumi_xsec_weight = luminosity / ( neventsDYIncl/xsecDYIncl );
	}

	if( sample.first.Contains("MuonEG")) lumi_xsec_weight = 1.;

	outTree->Fill();
      }

      outTree->AutoSave();

    }
  }
  cout << endl; 
}
