#include <TCanvas.h>
#include <TTree.h>
#include <TAxis.h>
#include <TH2.h>

void plot2c() {
    auto c1 = new TCanvas();
    auto t = new TTree();
    t->ReadFile("nll.txt", "mu/D:L/D");
    t->Draw("L:mu", "", "L");
    auto g = (TH2 *) gPad->GetPrimitive("htemp");
    //g->SetTitle(";#mu");
    g->SetTitle("-2 ln L;#mu;");
    g->GetYaxis()->SetTitleOffset(0.5);
    
    
    c1->SaveAs("2c.pdf");
}