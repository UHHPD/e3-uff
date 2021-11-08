#include <TCanvas.h>
#include <TTree.h>
#include <TAxis.h>
#include <TH2.h>

void plot2b() {
    auto c1 = new TCanvas();
    auto t = new TTree();
    t->ReadFile("likelihood.txt", "mu/D:L/D");
    t->Draw("L:mu", "", "L");
    auto g = (TH2 *) gPad->GetPrimitive("htemp");
    g->SetTitle(";#mu;L(#mu)");
    g->GetYaxis()->SetTitleOffset(0.5);
    
    c1->SaveAs("2b.pdf");
}