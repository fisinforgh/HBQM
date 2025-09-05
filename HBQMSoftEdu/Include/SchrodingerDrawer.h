/*
/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
// NOTICE OF COPYRIGHT                                                         //
//                                                                             //
// Copyright (C) 2025                                                          //
//                                                                             //
// Authors:					                               //
//   [1] Juan Pablo Sánchez Trujillo*			                       //
//   [2] Julian Andrés Salamanca Bernal**                                      //
//   [3] Diego Julián Rodríguez-Patarroyo***		                       //         			           
//                                                                             //
//   [1] jpsanchezt@udistrital.edu.co (Licenciado Universidad Distrital)       //
//   [2] jasalamanca@udistrital.edu.co (Profesor Universidad Distrital)        //
//   [3] djrodriguezp@udistrital.edu.co (Profesor Universidad Distrital)       //
//									       //
//  *,** Grupo de Física e Informática (FISINFOR)		               //
//  *** Grupo de Laboratorio de Fuentes Alternas de Energía (LIFAE)	       //
//  *,**,*** Universidad Distrital Francisco José de Caldas (Bogotá, Colombia) //	
//                                                                             //
// Web page:								       //
//   https://github.com/fisinforgh/HBQM                                        //
//                                                                             //
// This program is free software; you can redistribute it and/or modify        //
// it under the terms of the GNU General Public License as published by        //
// the Free Software Foundation; either version 2 of the License, or           //
// (at your option) any later version.                                         //
//                                                                             //
// This program is distributed in the hope that it will be useful,             //
// but WITHOUT ANY WARRANTY; without even the implied warranty of              //
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the               //
// GNU General Public License for more details:                                //
//                                                                             //
//               http://www.gnu.org/copyleft/gpl.html                          //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////
*/
#ifndef SCHRODINGERDRAWER_H
#define SCHRODINGERDRAWER_H

#include <cmath>
#include <iomanip>
#include "TCanvas.h"
#include "TGraph.h"
#include "TAxis.h"
#include "TMath.h"
#include "TROOT.h"
#include "PhiFunction.h"
#include <Riostream.h>
#include "TLegend.h"
#include "TLegendEntry.h"
#include "TF1.h"
#include "RadialFunction.h"
#include "AngularFunction.h"
#include "TSystem.h"




// ============================================================================
// Purpose:
// This header defines the SchrodingerDrawer function, which generates two distinct
// 3D visualizations of the quantum-mechanical representation of the hydrogen atom.
// These visualizations are displayed in the "Quantum Atom" tab of the application's
// graphical interface. The output includes:
//   1. A 3D solid surface representation of the probability density.
//   2. A 3D point distribution representation, emphasizing the probabilistic
//      nature of the wave function.
// Additionally, the function generates 2D plots for radial and angular probability
// distributions to complement the 3D view.
// ============================================================================


inline void SchrodingerDrawer(int n, int l, int m, TCanvas* canvas) {
  
  gSystem->Load("libMathMore"); // Load ROOT's MathMore library for extended math functions.
    
    std::vector<double> density = RadialFunction(n, l);
    std::vector<double> densityA = AngularFunction(l, m);
    std::vector<std::vector<double>> angular = PhiFunction(l, m);
    
      // Prepare canvas layout.
      canvas->Clear();
      canvas->Divide(2, 2);
    //------------------------------------------------------
    // Crosshair reference lines in the canvas.
      
    TLine *line1 = new TLine(0.5, 0.0, 0.5, 1.0);
    TLine *line2 = new TLine(0.0, 0.5, 1.0, 0.5);
    line1->SetBit(kCanDelete);
    line2->SetBit(kCanDelete);
    line1->SetLineWidth(2); line1->SetLineColor(kBlack);
    line2->SetLineWidth(2); line2->SetLineColor(kBlack);
    canvas->cd(); line1->Draw(); line2->Draw();

    // ------------------------------------------------------------------------
    // Radial probability density plot.

    TGraph *graph = new TGraph(density.size());
    graph->SetBit(kCanDelete);
    for (size_t i = 0; i < density.size(); i++) {
        double r = i * 0.05;  //Step size in Ångstroms
        graph->SetPoint(i, r * 1e-10, density[i]); // Convert to meters
    }
    canvas->cd(1);
    graph->SetTitle("Radial Probability Density");
    graph->GetXaxis()->SetTitle("r [m]");
    graph->GetYaxis()->SetTitle("Radial Probability Density (|#psi(r)|^{2})");
    graph->SetLineColor(kBlue);
    graph->Draw("AL");
    graph->SetEditable(kFALSE);

    // ------------------------------------------------------------------------
    // Angular probability density plot.
    
    TGraphPolar *graph2 = new TGraphPolar();
     graph2->SetBit(kCanDelete);
    // Llenar gráfico angular
    for (size_t j = 0; j < densityA.size(); j++) {
        double theta = j * (2.0 * Pi / densityA.size());  
        double r = densityA[j];  
        graph2->SetPoint(j, theta, r);
    }
    canvas->cd(2);
    graph2->SetLineWidth(2);
    graph2->SetLineColor(kRed);
    graph2->Draw("AL");
   
    TPaveText *titleBox = new TPaveText(0.65, 0.88, 0.98, 0.95, "NDC");
    titleBox->SetBit(kCanDelete);
    titleBox->AddText("Angular Probability Density");
    titleBox->AddText("(|#psi(#theta)|^{2})");
    titleBox->SetFillColor(0); 
    titleBox->SetTextSize(0);  
    titleBox->SetBorderSize(1);
    titleBox->SetTextAlign(22);
    titleBox->Draw();

    // ------------------------------------------------------------------------
    // 3D solid probability density representation.
    
    TH3D *hist = new TH3D("psi", "Probability Density", 50, -35, 35, 50, -35, 35, 50, -35, 35);
    hist->SetBit(kCanDelete);
    int points_r = density.size();
    int num_points = densityA.size();
    for (int i = 0; i < points_r; i++) {
        double r = i * 0.05;
        for (int j = 0; j < num_points; j++) {
	  double theta = j * (Pi / (num_points - 1));
            for (int k = 0; k < num_points; k++) {
	      double phi = k * (2 * Pi / (num_points - 1));
                double x = r * sin(theta) * cos(phi);
                double y = r * sin(theta) * sin(phi);
                double z = r * cos(theta);
                double density_val = density[i] * angular[j][k];
                hist->Fill(x, y, z, density_val);
            } 
        }
    }
    canvas->cd(3);
    hist->SetTitle("3D Probability Density (Solid Surface)");
    hist->GetXaxis()->SetTitle("Position X[#AA]");
    hist->GetYaxis()->SetTitle("Position Y[#AA]");
    hist->GetZaxis()->SetTitle("Position Z[#AA]");
    hist->GetXaxis()->SetTitleOffset(2.0);
    hist->GetYaxis()->SetTitleOffset(2.0);
    hist->GetZaxis()->SetTitleOffset(1.5);
    hist->SetFillColor(kBlue);
    hist->SetFillColor(kBlue);  
    hist->Draw("ISO SURF2");

    // ------------------------------------------------------------------------
    // 3D point distribution representation.
    
    canvas->cd(4);
    TH3D *hist1 = (TH3D*)hist->Clone("Qhist1");
    hist1->SetBit(kCanDelete);
    hist1->SetTitle("3D Probability Density (Point Cloud)");
    hist1->GetXaxis()->SetTitle("Position X[#AA]");
    hist1->GetYaxis()->SetTitle("Position Y[#AA]");
    hist1->GetZaxis()->SetTitle("Position Z[#AA]");
    hist1->GetXaxis()->SetTitleOffset(2.0);
    hist1->GetYaxis()->SetTitleOffset(2.0);
    hist1->GetZaxis()->SetTitleOffset(1.5);
    gStyle->SetOptStat(0);
    hist1->Draw("SURF2");

    // Final update of the canvas to render all plots.
    
    canvas->Update();
}

#endif
