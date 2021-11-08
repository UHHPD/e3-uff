#include <TCanvas.h>
#include <TTree.h>
#include <TAxis.h>
#include <TH2F.h>
#include <TLine.h>

void plot2d() {
    auto c1 = new TCanvas();
    auto t = new TTree();
    t->ReadFile("deltanll.txt", "mu/D:L/D");
    t->Draw("L:mu", "L<2", "L");
    auto g = (TH2F *) gPad->GetPrimitive("htemp");
    //g->SetTitle(";#mu");
    g->SetTitle("-2 #Delta ln L;#mu;");
    g->GetYaxis()->SetTitleOffset(0.5);
    g->GetMinimum();
    
    c1->SaveAs("2c.pdf");
}