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
#ifndef ANGULARFUNCTION_H
#define ANGULARFUNCTION_H

/* 
 * This library computes the spherical harmonic component 
 * that depends solely on the polar angle θ (theta), 
 * allowing it to be visualized in a polar plot.
 */

#include <cmath>
#include "TMath.h"
#include <Riostream.h>
#include "Math/IFunction.h"
#include "Math/SpecFuncMathCore.h"
#include <vector>
#include "PiConstant.h"
#include <TLine.h>
#include <TGraphPolar.h>
#include <TH3.h>
#include <TStyle.h>


using QuantumSim::Pi;

namespace QuantumSim {

 // Number of sampling points for the polar plot
 constexpr int num_points_theta = 200;  

  /*Computes the normalization coefficient for the spherical harmonics 
          of the hydrogen atom, based on the quantum numbers l and m.*/
  
 inline double CoefficientA(int l, int m) {
   return std::sqrt(((2.0 * l + 1.0) / (4.0 * Pi)) *
		    (TMath::Factorial(l - std::abs(m)) / TMath::Factorial(l + std::abs(m))));										  
}

 inline std::vector<double> AngularFunction(int l, int m) {
   std::vector<double> densityA(num_points_theta);

   // Define θ range from 0 to 2π for polar plots
    double theta_min = 0.0;
    double theta_max = 2 * Pi;

    for (int i = 0; i <= num_points_theta; i++) {
        double theta = theta_min + i * (theta_max - theta_min) / (num_points_theta - 1);
        double x = std::cos(theta);

        // Evaluate the associated Legendre polynomial P_l^m(x)
	
        double angular;
        if (m >= 0) {
            angular = CoefficientA(l, m) * std::assoc_legendre(l, m, x);
        } else {
	  
	  // For negative m, use absolute value and phase factor (-1)^|m|
	  angular = CoefficientA(l, m) * std::assoc_legendre(l, abs(m), x) * TMath::Power(-1, std::abs(m)); 
        }

        densityA[i] = std::pow(angular, 2);
    }
    return densityA;
 }
}
#endif
