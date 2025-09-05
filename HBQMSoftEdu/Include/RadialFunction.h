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
#ifndef RADIALFUNCTION_H
#define RADIALFUNCTION_H

/* 
 * This header defines functions to compute the radial probability density 
 * of the hydrogen atom for visualization in an x-y plane using the quantum model.
 */


#include <cmath>
#include "TMath.h"
#include <Riostream.h>
#include "Math/IFunction.h"
#include "Math/SpecFuncMathCore.h"
#include <vector>

namespace QuantumSim {
  
// Global constant: Bohr radius in Ångströms
 constexpr double a_0 = 0.529;

// Number of radial points for plotting resolution
 constexpr int points_r = 2000;


 /*Computes the normalization coefficient for the hydrogen atom's radial wavefunction 
  * n Principal quantum number.
  * l Orbital angular momentum quantum number.
  * Normalization coefficient as a double.*/
  
 inline double Coefficient(int n, int l) {
   return std::sqrt((8.0 / (std::pow(n, 3) * std::pow(a_0, 3))) * 
    (TMath::Factorial(n - l - 1) / (2.0 * n * TMath::Factorial(n + l))));
  
    }

    inline std::vector<double> RadialFunction(int n, int l) {
    std::vector<double> density(points_r);
  
    for (int i = 0; i <= points_r; i++) {
        double r = i * 0.05;  // Step size in Ångströms
        double x = 2.0 * r / (n * a_0);
        
        // Compute associated Laguerre polynomial using ROOT's math library
        double laguerre = std::assoc_laguerre(n - l - 1, 2 * l + 1, x);
	
        double radial = Coefficient(n, l) * std::pow(2.0 * r / (n * a_0), l) * std::exp(-r / (n * a_0)) * laguerre;
	density[i] = (std::pow(radial, 2)) * (std::pow(r, 2));
    }

    return density;
 }

}
#endif
