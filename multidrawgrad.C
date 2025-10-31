/// \file
/// \ingroup tutorial_gl
/// This macro extends the original example by introducing **multiple**
/// linear gradient fills for overlaying histograms.  
/// It is particularly suited for spectral or energy–spectrum visualization,
/// where distinct gradient palettes can highlight overlapping distributions.  
///
/// Inspired by the original ROOT OpenGL gradient tutorial by Timur Pocheptsov.
///
/// \macro_image(nobatch)
/// \macro_code
///
/// \author  Zhihao Song
 
//Includes for ACLiC (cling does not need them).
#include "TColorGradient.h"
#include "TCanvas.h"
#include "TColor.h"
#include "TStyle.h"
#include "TError.h"
#include "TH1F.h"
 
//Aux. functions for tutorials/gl.
#include "customcolorgl.h"
 
//______________________________________________________________________
void multidrawgrad()
{
   // Allocate custom color indices.
   Color_t ids[10] = {};
   if (ROOT::GLTutorials::FindFreeCustomColorIndices(ids) < 8) {
      ::Error("grad", "failed to create enough custom colors");
      return;
   }

   gStyle->SetCanvasPreferGL(kTRUE);
   TCanvas * const cnv = new TCanvas("c", "two gradients overlay", 50, 50, 1200, 900);
   if (!cnv->UseGL()) {
      ::Error("grad", "This macro requires OpenGL on the canvas");
      delete cnv;
      return;
   }

   typedef TColorGradient::Point Point;

   // 1
   const Color_t grad1 = ids[0];
   // 1
   const Color_t grad2 = ids[1];

   // 1
   {
      
      new TColor(ids[2], 1.00, 0.95, 0.20, "g1_yellow", 0.60);
      new TColor(ids[3], 1.00, 0.60, 0.00, "g1_orange", 0.60);
      new TColor(ids[4], 0.90, 0.15, 0.10, "g1_red"   , 0.60);

      const Double_t loc[3] = {0.0, 0.5, 1.0};
      const Color_t  node[3]= {ids[2], ids[3], ids[4]};

      TLinearGradient * const g1 = new TLinearGradient(grad1, 3, loc, node);
      g1->SetStartEnd(Point(0., 0.), Point(0., 1.)); 
   }

   // 2
   {
      new TColor(ids[5], 0.20, 0.40, 1.00, "g2_blue" , 0.60);
      new TColor(ids[6], 0.10, 0.80, 0.85, "g2_cyan" , 0.60);
      new TColor(ids[7], 0.10, 0.75, 0.25, "g2_green", 0.60);

      const Double_t loc[3] = {0.0, 0.5, 1.0};
      const Color_t  node[3]= {ids[5], ids[6], ids[7]};

      TLinearGradient * const g2 = new TLinearGradient(grad2, 3, loc, node);
      g2->SetStartEnd(Point(0., 0.), Point(0., 1.)); 
   }

   // hist1
   TH1F * const h1 = new TH1F("h1", "Two histograms with per-object gradients;X;Counts", 40, -3.5, 3.5);
   h1->SetFillColor(grad1);
   h1->SetLineColor(kBlack);
   h1->SetLineWidth(1);
   h1->FillRandom("gaus", 120000);

   // hist2
   TH1F * const h2 = new TH1F("h2", "h2", 40, -3.5, 3.5);
   h2->SetFillColor(grad2);
   h2->SetLineColor(kBlack);
   h2->SetLineWidth(1);
   h2->FillRandom("gaus", 100000);

   
   h1->Draw();
   
   h2->Draw("SAME");

   // Legend
   TLegend *leg = new TLegend(0.65, 0.55, 0.85, 0.7);
   leg->AddEntry(h1, "Histogram 1 ", "f");
   leg->AddEntry(h2, "Histogram 2 ", "f");
   leg->SetBorderSize(0);
   leg->SetFillStyle(0);
   leg->Draw();

cnv->cd();
cnv->Modified();
cnv->Update();
gSystem->ProcessEvents(); 


}
