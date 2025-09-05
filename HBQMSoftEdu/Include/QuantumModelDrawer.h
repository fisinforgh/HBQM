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
#ifndef QUANTUMMODELDRAWER_H
#define QUANTUMMODELDRAWER_H

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




/*
 * This library is designed to generate the quantum simulation for the "models" tab of the Hydrogen atom GUI.
 * Pointer to the ROOT TCanvas where the model will be drawn.
*/

inline void QuantumModelDrawer(int n, int l, int m, TCanvas* canvas) {
  
    gSystem->Load("libMathMore");

    std::vector<double> density  = RadialFunction(n, l);
    std::vector<double> densityA = AngularFunction(l, m);
    std::vector<std::vector<double>> angular = PhiFunction(l, m);

    canvas->Clear();
    canvas->cd(3);

    TH3D* qhist = new TH3D("psy", "",
                          50, -35, 35, 50, -35, 35, 50, -35, 35);
    qhist->SetBit(kCanDelete); 
    canvas->GetListOfPrimitives()->Add(qhist); 

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
                qhist->Fill(x, y, z, density_val);
            }
        }
    }

    /*The names qhist and "psy" were added to distinguish the objects created from 
     those in SchrodingerDrawer.h
      and to avoid potential memory leaks.*/
    
    qhist->GetXaxis()->SetTitle("Position X[#AA]");
    qhist->GetYaxis()->SetTitle("Position Y[#AA]");
    qhist->GetZaxis()->SetTitle("Position Z[#AA]");
    qhist->GetXaxis()->SetTitleOffset(2.0);
    qhist->GetYaxis()->SetTitleOffset(2.0);
    qhist->GetZaxis()->SetTitleOffset(1.5);
    qhist->SetFillColor(kBlue);
    qhist->SetLineColor(kBlue);

    qhist->Draw("SURF");
    gStyle->SetOptStat(0);
    canvas->Update();
}

#endif
