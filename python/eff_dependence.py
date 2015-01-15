from ROOT import *
# import AtlasStyle
import os,array,sys
from rebinTools import *
# from rootpy.interactive import wait

ROOT.gStyle.SetOptStat(0)
ROOT.gStyle.SetOptTitle(0)
# ROOT.gStyle.SetPaintTextFormat(".0f");

varbins = {
  "pt":[10., 20., 30., 40., 50.,70., 90., 120., 150., 200., 300.],
  "ht":[0., 50.,100.,250., 500., 750., 1000., 1250.,1500., 1750.,2000.,2500.],
  "njets":[1],
  "mj":[0.,50.,100.,200.,300.,400., 500., 600., 700., 800.,1000., 1200.,1400.]
}

samples = ["T1tttt1500", "T1tttt1500_fake", "ttbar", "ttbar_fake"]

for sample in samples:
  fmc = TFile("isolation_"+sample+".root","READ")
  can = TCanvas()
  pad = TPad("pad"," ",0.,0.,1.,1.)
  pad.SetFillColor(0)
  pad.SetLeftMargin(0.12)
  pad.SetRightMargin(0.05)
  pad.SetBottomMargin(0.15)
  pad.Draw()

  for var in varbins.keys():
    for channel in ['el','mu']:

      #------- LEGEND ---------
      legX, legY = 0.6, 0.85
      if ("fake" in sample): 
        legX, legY = 0.15, 0.85 
      # if (channel=='mu'):
      #   legX, legY = 0.15, 0.85 
      legW, legH = 0.3, 0.07*2.
      leg = TLegend(legX, legY-legH, legX+legW, legY);
      leg.SetTextSize(0.048); 
      leg.SetFillColor(0); 
      leg.SetFillStyle(0); 
      leg.SetBorderSize(0);
      leg.SetTextFont(42);

      h_eff = []
      for j,iso in enumerate(['reliso','miniso']):

        h_num = rebin1D(fmc.Get("h_"+var+"_"+iso+"_"+channel).Clone(), varbins[var])
        h_denom = rebin1D(fmc.Get("h_"+var+"_none_"+channel).Clone(), varbins[var])
        totaldenom = h_denom.Integral()
        h_num.SetDirectory(0)
        h_denom.SetDirectory(0)

        pad.cd()
        h_eff.append(TGraphAsymmErrors())
        h_eff[j].BayesDivide(h_num,h_denom)
        lowedge = 0.
        if ("fake" in sample): 
          h_eff[j].GetYaxis().SetRangeUser(lowedge,1.1)
        else: 
          lowedge = 0.5
          h_eff[j].GetYaxis().SetRangeUser(lowedge,1.2)
        if (iso=="reliso"):
          h_eff[j].SetMarkerStyle(20)
          h_eff[j].SetMarkerColor(kRed)
          h_eff[j].SetMarkerSize(1.2)
          h_eff[j].SetLineColor(kRed)
          h_eff[j].SetLineWidth(2)
          h_eff[j].GetXaxis().SetLabelSize(0.06)
          h_eff[j].GetXaxis().SetTitleSize(0.06)
          h_eff[j].GetXaxis().SetTitleOffset(1.05)
          h_eff[j].GetYaxis().SetLabelSize(0.06)
          h_eff[j].GetYaxis().SetTitleSize(0.06)
          h_eff[j].GetYaxis().SetTitleOffset(1.)
          h_eff[j].GetXaxis().SetTitle(h_denom.GetXaxis().GetTitle())
          h_eff[j].GetYaxis().SetTitle("Prompt lepton efficiency")
          if ("fake" in sample):  h_eff[j].GetYaxis().SetTitle("Non-prompt lepton efficiency")

          h_eff[j].Draw("ape")
        else: 
          h_eff[j].SetMarkerStyle(24)
          h_eff[j].SetMarkerColor(kBlack)
          h_eff[j].SetMarkerSize(1.2)
          h_eff[j].SetLineColor(kBlack)
          h_eff[j].SetLineWidth(2)
          h_eff[j].Draw("pe same")

        h_denom.SetLineColor(kGray)
        h_denom.SetLineStyle(2)
        h_denom.SetLineWidth(1)
        h_denom.SetFillStyle(3444)
        h_denom.SetFillColor(kGray)
        smoothBinning(h_denom)
        h_denom.Scale(1./h_denom.Integral())

        for i in range(0,h_denom.GetNbinsX()): h_denom.SetBinContent(i+1, h_denom.GetBinContent(i+1)+lowedge)
        h_denom.Draw("histsame")
        # h_eff[0].Draw("pe same")
        # h_eff[1].Draw("pe same")

      leghead = ""
      if ("ttbar" in sample): leghead = "t#bar{t}"
      elif ("T1tttt1500" in sample): leghead = "SUSY T1tttt"
      leghead = leghead + ", {:.0f}".format(totaldenom)

      leg.SetHeader(leghead)
      leg.AddEntry(h_eff[0], "standard isolation", "LP")
      leg.AddEntry(h_eff[1], "mini-isolation", "LP")

      pad.cd()
      leg.Draw()


      can.Print("eff_"+var+"_"+sample+"_"+channel+".pdf")

  fmc.Close()

