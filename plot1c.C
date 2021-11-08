#include <TH1D.h>
#include <TTree.h>
#include <TLegend.h>
#include <TCanvas.h>

void plot1c() {
    auto c1 = new TCanvas();

    auto hist = new TH1D("hist", "; N", 11, -0.5,10.5);
    auto hist2 = new TH1D("hist2", "; N", 11, -0.5,10.5);
    hist->SetLineColor(2);
    hist2->SetFillStyle(0);
    hist->SetStats(0);
    hist2->SetStats(0);
    auto t = new TTree();
    t->ReadFile("histpoi.txt", "N/I:counts/I:poi/F");
    t->Draw("N >>hist", "counts", "HIST");
    t->Draw("N >>hist2", "poi", "HIST SAME");
    
   auto legend = new TLegend(0.7,0.7,0.9,0.9);
   legend->AddEntry(hist,"Data","l");
   legend->AddEntry(hist2,"Prediction","l");
   legend->Draw();
   
   c1->SaveAs("1c.pdf");
}