/*/////////////////////////////////////////////////////////////////////////////////
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
#ifndef BOHRDRAWER_H
#define BOHRDRAWER_H

#include "BohrTimer.h"
#include <TPaveText.h>
#include <vector>

namespace BohrSim {

// Purpose: 
// This library is responsible for rendering the animation frames 
// defined in BohrTimer.h for the "Bohr Atom" and "Models" tabs.

  
inline TEllipse* nucleus = nullptr;
inline TEllipse* orbits[8] = {nullptr};
inline TPaveText* infoBox = nullptr;

// --- Draws the wavy green trajectory of the electron ---
  
inline void DrawGreenTrajectory() {
    int numPoints = 200;
    TGraph* GreenTrajectory = new TGraph();

    for (int i = 0; i < numPoints; ++i) {
        double angle = 2 * TMath::Pi() * i / numPoints;
        double alpha = 2 * TMath::Pi() * n * i / numPoints;
        double r_disturbed = r + A * TMath::Sin(alpha);
        double x = 0.5 + r_disturbed * TMath::Cos(angle);
        double y = 0.5 + r_disturbed * TMath::Sin(angle);
        GreenTrajectory->SetPoint(i, x, y);
    }

    // Close the trajectory
    
    double r_disturbed0 = r + A * TMath::Sin(0);
    GreenTrajectory->SetPoint(numPoints, 0.5 + r_disturbed0, 0.5);
    GreenTrajectory->SetLineColor(kViolet + 5);
    GreenTrajectory->SetLineWidth(4);
    GreenTrajectory->SetLineStyle(1);

    GreenTrajectory->Draw("L same");
}

// Displays quantum parameters for the current orbit ---
  
inline void ShowQuantumInfo() {
    double r_n = 0.529 * n * n;   // Orbit radius in angstroms
    double v_n = 2.18e6 / n;      // Electron velocity in m/s
    double E_n = -13.6 / (n * n); // Energy in eV

    infoBox = new TPaveText(0.65, 0.7, 0.95, 0.9, "NDC");
    infoBox->SetFillColor(0);
    infoBox->AddText(Form("n = %d", n));
    infoBox->AddText(Form("r_{n} = %.3f [#AA]", r_n));
    infoBox->AddText(Form("v_{n} = %.2e [m/s]", v_n));
    infoBox->AddText(Form("E_{n} = %.2f [eV]", E_n));
    infoBox->Draw();
}

  inline void DrawBohrModel(TCanvas* canvasIn, int nValue, bool showText = true) {
    canvas = canvasIn;

    // Clamp the principal quantum number between 1 and 8
    n = (nValue < 1) ? 1 : (nValue > 8 ? 8 : nValue);
    canvas->Clear();
    canvas->Range(0, 0, 1, 1);
    angle = 0;

    // Adjust radius and angular speed based on n
    r = r1 * (1 + 0.3 * (n - 1));
    omega = omega1 / (1 + 0.3 * (n - 1));

    nucleus = new TEllipse(0.5, 0.5, 0.05, 0.05);
    nucleus->SetFillColor(kRed);
    nucleus->Draw();
    for (int i = 0; i < n; ++i) {
        double r_i = r1 * (1 + 0.3 * i);
        orbits[i] = new TEllipse(0.5, 0.5, r_i, r_i);
        orbits[i]->SetLineColor(kCyan + 2);
        orbits[i]->SetFillStyle(0);
        orbits[i]->Draw();
    }
    electron = new TEllipse(0.5 + r, 0.5, 0.02, 0.02);
    electron->SetFillColor(kBlack);
    electron->Draw();

    DrawGreenTrajectory();
    
    // Display quantum info if enabled

   // Display quantum info if enabled (Tab: Bohr Atom)
    
    if (showText) {
        ShowQuantumInfo();
    }
    
    if (!timer)
        timer = new BohrTimer();
    timer->Start(50, kTRUE);

    canvas->Update();
}

} // namespace BohrSim

#endif
