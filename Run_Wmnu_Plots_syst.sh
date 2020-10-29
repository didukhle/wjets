#root -l -b -q 'PlotMyWithSyst.C("mu_eta[0]","RunF","eta",true,false)'
#root -l -b -q 'PlotMyWithSyst.C("mu_pt[0]","RunF","mu_pt [GeV]",true,false)'
#root -l -b -q 'PlotMyWithSyst.C("mu_relIso[0]","RunF","relIso",true,false)'
#root -l -b -q 'PlotMyWithSyst.C("el_eta[0]","RunF","eta",true,false)'
#root -l -b -q 'PlotMyWithSyst.C("el_pt[0]","RunF","el_pt [GeV]",true,false)'
#root -l -b -q 'PlotMyWithSyst.C("el_relIso[0]","RunF","relIso",true,false)'


root -l -b -q 'PlotMyWithSyst.C("met_pt","RunF","p^{miss}_{T} [GeV]",true)'
root -l -b -q 'PlotMyWithSyst.C("PFmet_pt","RunF","p^{miss}_{T} [GeV]",true)'
root -l -b -q 'PlotMyWithSyst.C("puppi_pt","RunF","Puppi p^{miss}_{T} [GeV]",true)'
root -l -b -q 'PlotMyWithSyst.C("met_pt_smeared","RunF","#slash{E}_{T} smeared  [GeV]",true)'
root -l -b -q 'PlotMyWithSyst.C("MT","RunF","M_{T} [GeV]",true)'
root -l -b -q 'PlotMyWithSyst.C("MT_PF","RunF","M_{T} [GeV]",true)'
root -l -b -q 'PlotMyWithSyst.C("MTpuppi","RunF","Puppi M_{T} [GeV]",true)'
root -l -b -q 'PlotMyWithSyst.C("MT_smeared","RunF","M_{T} smeared [GeV]",true)'

root -l -b -q 'PlotMyWithSyst.C("Utr","RunF","Utr [GeV]",true)'
root -l -b -q 'PlotMyWithSyst.C("Utr_puppi","RunF","Utr_puppi [GeV]",true)'
root -l -b -q 'PlotMyWithSyst.C("Utr_smeared","RunF","Utr_smeared [GeV]",true)'

root -l -b -q 'PlotMyWithSyst.C("Ut","RunF","Ut [GeV]",true)'
root -l -b -q 'PlotMyWithSyst.C("Ut_puppi","RunF","Ut_puppi [GeV]",true)'
root -l -b -q 'PlotMyWithSyst.C("Ut_smeared","RunF","Ut_smeared [GeV]",true)'
root -l -b -q 'PlotMyWithSyst.C("Ucol","RunF","Ucol [GeV]",true)'
root -l -b -q 'PlotMyWithSyst.C("Ucol_puppi","RunF","Ucol_puppi [GeV]",true)'
root -l -b -q 'PlotMyWithSyst.C("Ucol_smeared","RunF","Ucol_smeared [GeV]",true)'


root -l -b -q 'PlotMyWithSyst.C("met_pt","RunF","p^{miss}_{T} [GeV]",false)'
root -l -b -q 'PlotMyWithSyst.C("PFmet_pt","RunF","p^{miss}_{T} [GeV]",false)'
root -l -b -q 'PlotMyWithSyst.C("puppi_pt","RunF","Puppi p^{miss}_{T} [GeV]",false)'
root -l -b -q 'PlotMyWithSyst.C("met_pt_smeared","RunF","#slash{E}_{T} smeared  [GeV]",false)'
root -l -b -q 'PlotMyWithSyst.C("MT","RunF","M_{T} [GeV]",false)'
root -l -b -q 'PlotMyWithSyst.C("MT_PF","RunF","PF M_{T} [GeV]",false)'
root -l -b -q 'PlotMyWithSyst.C("MTpuppi","RunF","Puppi M_{T} [GeV]",false)'
root -l -b -q 'PlotMyWithSyst.C("MT_smeared","RunF","M_{T} smeared [GeV]",false)'

root -l -b -q 'PlotMyWithSyst.C("Utr","RunF","Utr [GeV]",false)'
root -l -b -q 'PlotMyWithSyst.C("Utr_puppi","RunF","Utr_puppi [GeV]",false)'
root -l -b -q 'PlotMyWithSyst.C("Utr_smeared","RunF","Utr_smeared [GeV]",false)'

root -l -b -q 'PlotMyWithSyst.C("Ut","RunF","Ut [GeV]",false)'
root -l -b -q 'PlotMyWithSyst.C("Ut_puppi","RunF","Ut_puppi [GeV]",false)'
root -l -b -q 'PlotMyWithSyst.C("Ut_smeared","RunF","Ut_smeared [GeV]",false)'
root -l -b -q 'PlotMyWithSyst.C("Ucol","RunF","Ucol [GeV]",false)'
root -l -b -q 'PlotMyWithSyst.C("Ucol_puppi","RunF","Ucol_puppi [GeV]",false)'
root -l -b -q 'PlotMyWithSyst.C("Ucol_smeared","RunF","Ucol_smeared [GeV]",false)'