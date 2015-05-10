from ROOT import *
import os,array,sys
from rebin_tools import *
# from rootpy.interactive import wait

ROOT.gStyle.SetOptStat(0)
ROOT.gStyle.SetOptTitle(0)
# ROOT.gStyle.SetPaintTextFormat(".0f");

varbins = {
    "pt":[10., 20., 30., 40., 50.,70., 90., 120., 150., 200., 300.],
    "ht":[0., 50.,100.,250., 500., 750., 1000., 1250.,1500., 1750.,2000.,2500.],
    "njets":[1],
    "mj":[0.,50.,100.,200.,300.,400., 500., 600., 700., 800.,1000., 1200.,1400.],
    "met":[0.,100.,200.,300.,400., 500., 600., 700., 800.,1000., 1200.,1400.,1600.],
    "pv":[10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,45]
}

samples = []
samples.append("ttbar")
#samples.append("wjets")
samples.append("T1tttt1500")

isotypes = {} 

legend_order = []
legend_order.append('miniso_tr10')
legend_order.append('miniso_tr10_r03_vvl')
#legend_order.append('reliso_trig')
legend_order.append('miniso_tr10_r03_04')
legend_order.append('reliso')

leptons = ['electron', 'muon']

can = TCanvas("can","",1000,600)
pad = TPad("pad"," ",0.,0.,1.,1.)
for sample in samples:
  if not os.path.exists("isolation_"+sample+".root"): 
    print "File for sample ",sample," not found. Skip."
    continue
  fmc = TFile("isolation_"+sample+".root","READ")

  for mode in ["","_fake"]:
    pad.SetFillColor(0)
    pad.SetLeftMargin(0.12)
    pad.SetRightMargin(0.05)
    pad.SetBottomMargin(0.15)
    pad.Draw()

    for var in varbins.keys():
      for channel in ['el','mu']:
        if (channel == 'el'):
          isotypes['reliso'] = ("I(R=0.3) < 0.16/0.21 [Veto WP]", 20, kRed, 1.2)
          isotypes['miniso_tr10'] = ("I(mini) < 0.1", 24, kBlack)
          #isotypes['miniso_tr10_r03_vvl'] = ("I(R=0.3) < 1.5, I(mini) < 0.1 [VVVL trig.]", 25, kGreen+3)
          #isotypes['reliso_trig'] = ("I_{ R=0.2} < 0.8, I_{ R=0.3} < 0.22/0.25", 25, kGreen+3)
          #isotypes['miniso_tr10_r03_04'] = ("I(R=0.3) < 0.4, I(mini) < 0.1 [Std trig.]", 25, kBlue)
        else:
          isotypes['reliso'] = ("I(R=0.4) < 0.2 [Loose WP]", 20, kRed, 1.2)
          isotypes['miniso_tr10'] = ("I(mini) < 0.2", 24, kBlack)
          #isotypes['miniso_tr10_r03_vvl'] = ("I(R=0.3) < 1.0, I(mini) < 0.2 [VVVL trig.]", 25, kGreen+3)
          #isotypes['reliso_trig'] = ("I_{ R=0.2} < 0.8, I_{ R=0.3} < 0.22/0.25", 25, kGreen+3)
          #isotypes['miniso_tr10_r03_04'] = ("I(R=0.3) < 0.4, I(mini) < 0.2 [Std trig.]", 25, kBlue)



        #------- LEGEND ---------
        legX, legY = 0.4, 0.89
        if ("fake" in mode): 
          legX, legY = 0.15, 0.88
        # if (channel=='mu'):
        #   legX, legY = 0.15, 0.85 
        legW, legH = 0.2, 0.065*(len(legend_order)+1)
        leg = TLegend(legX, legY-legH, legX+legW, legY);
        leg.SetTextSize(0.053); 
        leg.SetFillColor(0); 
        leg.SetFillStyle(0); 
        leg.SetBorderSize(0);
        leg.SetTextFont(42);
        leghead = ""
        if ("ttbar" in sample): leghead = "#font[62]{t#bar{t}}"
        elif ("T1tttt1500" in sample): leghead = "#font[62]{T1tttt(1500,100)}"
        # leghead = leghead + ", {:.0f}".format(totaldenom)
        # leghead = leghead + ", {:.0f}".format(totalnum)

        leg.SetHeader(leghead)

        h_eff = {}
        for j,iso in enumerate(isotypes.keys()):
          print var, channel, iso, mode
          h_num = rebin1D(fmc.Get("h_"+var+"_"+iso+mode+"_"+channel).Clone(), varbins[var])
          h_denom = rebin1D(fmc.Get("h_"+var+"_none"+mode+"_"+channel).Clone(), varbins[var])
          totaldenom = h_denom.Integral()
          totalnum = h_num.Integral()
          h_num.SetDirectory(0)
          h_denom.SetDirectory(0)

          pad.cd()
          h_eff[iso] = TGraphAsymmErrors()
          h_eff[iso].BayesDivide(h_num,h_denom)
          lowedge = 0.
          if ("fake" in mode): 
            h_eff[iso].GetYaxis().SetRangeUser(lowedge,1.1)
          else: 
            lowedge = 0.5
            h_eff[iso].GetYaxis().SetRangeUser(lowedge,1.25)

          h_eff[iso].SetMarkerStyle(isotypes[iso][1])
          h_eff[iso].SetMarkerColor(isotypes[iso][2])
          h_eff[iso].SetMarkerSize(1.2)
          h_eff[iso].SetLineColor(isotypes[iso][2])
          h_eff[iso].SetLineWidth(2)

          if (j==0):
            h_eff[iso].GetXaxis().SetLabelSize(0.06)
            h_eff[iso].GetXaxis().SetTitleSize(0.06)
            h_eff[iso].GetXaxis().SetTitleOffset(1.05)
            h_eff[iso].GetYaxis().SetLabelSize(0.06)
            h_eff[iso].GetYaxis().SetTitleSize(0.06)
            h_eff[iso].GetYaxis().SetTitleOffset(1.)
            h_eff[iso].GetXaxis().SetTitle(h_denom.GetXaxis().GetTitle())
            title = "Prompt electron efficiency"
            if ("fake" in mode): title = title.replace('Prompt', 'Non-prompt')
            if ("mu" in channel): title = title.replace('electron', 'muon')
            h_eff[iso].GetYaxis().SetTitle(title)
            h_eff[iso].SetMaximum(1.4)
            h_eff[iso].Draw("ape")
          else: 
            h_eff[iso].Draw("pe same")

          h_denom.SetLineColor(kGray)
          h_denom.SetLineStyle(2)
          h_denom.SetLineWidth(1)
          h_denom.SetFillStyle(3444)
          h_denom.SetFillColor(kGray)
          smoothBinning(h_denom)
          h_denom.Scale(1./h_denom.Integral())

          for i in range(0,h_denom.GetNbinsX()): h_denom.SetBinContent(i+1, h_denom.GetBinContent(i+1)+lowedge)
          h_denom.Draw("histsame")

        
        for iso in legend_order:
          if (iso in isotypes.keys()):
            leg.AddEntry(h_eff[iso], isotypes[iso][0], "LP")

        pad.cd()
        leg.Draw()


        can.Print("eff_"+var+"_"+sample+mode+"_"+channel+".pdf")

  fmc.Close()

