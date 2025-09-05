/*
##############################################################################
#                                                                             #
# NOTICE OF COPYRIGHT                                                         #
#                                                                             #                                                                    
# Copyright (C) 2025                                                          #
#                                                                             #
# Authors:								      #
#   [1] Juan Pablo Sánchez Trujillo*					      #
#   [2] Julian Andrés Salamanca Bernal**				      #
#   [3] Diego Julián Rodríguez-Patarroyo***                		      #
#                                                                             #
#   [1] jpsanchezt@udistrital.edu.co (Licenciado Universidad Distrital)       #
#   [2] jasalamanca@udistrital.edu.co (Profesor Universidad Distrital)        #
#   [3] djrodriguezp@udistrital.edu.co (Profesor Universidad Distrital)	      #
#									      #
#  *,** Grupo de Física e Informática (FISINFOR)		              #
#  *** Grupo de Laboratorio de Fuentes Alternas de Energía (LIFAE)	      #
#  *,**,*** Universidad Distrital Francisco José de Caldas (Bogotá, Colombia) #	
#                                                                             #
# Web page:								      #
#   https://github.com/fisinforgh/HBQM                                        #
#                                                                             #
# This program is free software; you can redistribute it and/or modify        #
# it under the terms of the GNU General Public License as published by        #
# the Free Software Foundation; either version 2 of the License, or           #
# (at your option) any later version.                                         #
#                                                                             #
# This program is distributed in the hope that it will be useful,             #
# but WITHOUT ANY WARRANTY; without even the implied warranty of              #
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the               #
# GNU General Public License for more details:                                #
#                                                                             #
#               http://www.gnu.org/copyleft/gpl.html                          #
#                                                                             #
###############################################################################
*/
#ifndef BOHRTIMER_H
#define BOHRTIMER_H

#include <TTimer.h>
#include <TEllipse.h>
#include <TCanvas.h>
#include <TMath.h>
#include <TGraph.h>

namespace BohrSim {

/*
 * This library is designed to manage the animation for both the "Bohr Atom" and "Models" tabs,
 * handling the shared electron motion logic and ensuring smooth and synchronized visualizations
 * across both sections of the GUI.
 */

  
inline TEllipse* electron = nullptr;
inline TCanvas* canvas = nullptr;
inline TGraph* trayectoriaVerde = nullptr;

inline double angle = 0;     // Current angular position of the electron
inline double r1 = 0.1;      // Base radius for animations
inline double omega1 = 0.6;  // Base angular velocity
inline double r = 0;         // Current orbit radius
inline double omega = 0;     // Current angular velocity
inline int n;                // Principal quantum number


// Amplitude of the oscillation applied to the electron's orbit
inline double A = 0.015;

// --- Custom timer class for handling periodic animation updates ---

class BohrTimer : public TTimer {
public:
    Bool_t Notify() override;
};
  
// Global instance of the custom timer
  
inline BohrTimer* timer = nullptr;

// Updates the position of the electron based on the current angle, radius, and oscillation.
  
inline void updateElectron() {
    if (!electron || !canvas) return;

    double alpha = n * angle;
    double r_wavy = r + A * TMath::Sin(alpha);

    double x = r_wavy * TMath::Cos(angle);
    double y = r_wavy * TMath::Sin(angle);

    electron->SetX1(0.5 + x);
    electron->SetY1(0.5 + y);

    canvas->Modified();
    canvas->Update();
    angle += omega;

    if (timer)
        timer->Start(50, kTRUE); // Restart timer for the next frame
}
  
inline Bool_t BohrTimer::Notify() {
    updateElectron();
    return kTRUE;
}

} // namespace BohrSim

#endif
