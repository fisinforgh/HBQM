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
#ifndef PHIFUNCTION_H
#define PHIFUNCTION_H

  /* 
 * This library computes spherical harmonics to be represented in three dimensions 
 * using rectangular coordinates (x, y, z). 
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
using namespace QuantumSim;

namespace QuantumSim {

 // Resolution of the angular grid for theta and phi in the plot
 constexpr int num_points = 200;


   /* Computes the normalization coefficient for spherical harmonics 
             in the hydrogen atom model.  */
  
 inline double CoefficientP(int l, int m) {
   return std::sqrt(((2.0 * l + 1.0) / (4.0 * Pi)) *
		    (TMath::Factorial(l - std::abs(m)) / TMath::Factorial(l + std::abs(m))));
                                                                                    
}

 inline std::vector<std::vector<double>> PhiFunction(int l, int m) {
    std::vector<std::vector<double>> densityP(num_points, std::vector<double>(num_points));

    double theta_min = 0.0, theta_max = Pi; // θ from 0 to π
    double phi_min = 0.0, phi_max = 2 * Pi; // φ from 0 to 2π

    for (int i = 0; i < num_points; i++) {
        double theta = theta_min + i * (theta_max - theta_min) / (num_points - 1);
        double x = std::cos(theta);

        // Evaluate the associated Legendre polynomial P_l^m(x)
        double angular;
        if (m >= 0) {
            angular = CoefficientP(l, m) * std::assoc_legendre(l, m, x);
        } else {
	  angular = CoefficientP(l, m) * std::assoc_legendre(l, std::abs(m), x) * std::pow(-1, std::abs(m));// // When m is negative.
        }

        for (int j = 0; j < num_points; j++) {
            double phi = phi_min + j * (phi_max - phi_min) / (num_points - 1);
            double phi_factor = std::cos(m * phi);
            densityP[i][j] = std::pow(angular * phi_factor, 2); 
        }
    }

    return densityP;
 }
}
#endif
