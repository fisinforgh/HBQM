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

#ifndef SEHBQM_H
#define SEHBQM_H

#include <TQObject.h>
#include <RQ_OBJECT.h>

class TGMainFrame;
class TGCompositeFrame;
class TGTab;
class TGHorizontalFrame;
class TGVerticalFrame;
class TGGroupFrame;
class TGNumberEntry;
class TGLabel;
class TRootEmbeddedCanvas;
class TCanvas;
class TGVertical3DLine;
class TGTextButton;
class TPaveText;
class TImage;
class TGLayoutHints;

class HydrogenSimulatorGUI {
  RQ_OBJECT("HydrogenSimulatorGUI")
  private:
  TGMainFrame         *fMainFrame;

  
 // GUI elements for the Home tab

  TGLayoutHints* ExpandHome;
  TRootEmbeddedCanvas* EmbeddedHome;
  TCanvas* homeCanvas;
  TImage *coverImage;
  
 // GUI elements for the Bohr model tab
  
  TGCompositeFrame *fCentralFrame;
  TGTab *fTab;
  TGCompositeFrame *fHomeFrame;
  TGCompositeFrame *fBohrFrame;
  TGHorizontalFrame *fHorizontalFrameBohrContainer;
  TGVerticalFrame *fVerticalFrameBohrUser;
  TGGroupFrame *fGroupFrameBohrUserButtons;
  TGNumberEntry *fNumberEntryBohrEnergyButton;
  TGLabel *fLabelBohrEnergyText;
  TGGroupFrame *fGroupFrameBohrUserText;
  TRootEmbeddedCanvas *CanvasBohrText;
  TCanvas *bohrTextCanvas;
  TPaveText* bohrTextBox;
  TGVerticalFrame *fVerticalFrameBohrSimulation;
  TRootEmbeddedCanvas *fRootEmbeddedCanvasBohr;
  Int_t wfRootEmbeddedCanvasBohr;
  TCanvas *fcanvasBohr;
  TGHorizontalFrame *fHorizontalFrameBohrOptions;
  TGTextButton *fTextButtonBohrPlay;
  TGVertical3DLine *fVertical3DLineBohrOptions;
  TGTextButton *fTextButtonBohrExit;

 // GUI elements for the Quantum model tab
  
  TGCompositeFrame *fCompositeQuantumFrame;
  TGVerticalFrame *fVerticalFrameQuantumContainer;
  TGVerticalFrame *fVerticalFrameQuantumUser;
  TGGroupFrame *fGroupFrameQuantumUserButtons;
  TGLabel *fLabelQuantumEnergyUserText;
  TGLabel *fLabelQuantumOrbitalUserText;
  TGLabel *fLabelQuantumMagneticUserText;
  TGNumberEntry *fNumberEntryQuantumEnergyButton;
  TGNumberEntry *fNumberEntryQuantumOrbitalButton;
  TGNumberEntry *fNumberEntryQuantumMagneticButton;
  TGGroupFrame *fGroupFrameQuantumUserText;
  TRootEmbeddedCanvas * CanvasQuantumText;
  TCanvas *quantumTextCanvas;
  TPaveText* quantumTextBox;
  TGVerticalFrame *fVerticalFrameQuantumSimulation;
  TRootEmbeddedCanvas *fRootEmbeddedCanvasQuantum;
  Int_t wfRootEmbeddedCanvasQuantum;
  TCanvas *fcanvasQuantum;
  TGHorizontalFrame *fHorizontalFrameQuantumOptions;
  TGVertical3DLine *fVertical3DLineQuantumOptionsLine;
  TGTextButton *fTextButtonQuantumPlayButton;
  TGTextButton *fTextButtonQuantumExitButton;

// GUI elements for the Models tab, which includes both the Bohr and Quantum models.
  
   TGCompositeFrame *fModelsFrame;
   TGHorizontalFrame *fHorizontalFrameModelsUser;
   TGLabel *fLabelModelsEnergyTextButton;
   TGNumberEntry *fNumberEntryModelsEnergyUserButton;
   TGLabel *fLabelModelsOrbitalTextButton;
   TGNumberEntry *fNumberEntryModelsOrbitalUserButton;
   TGLabel *fLabelModelsMagneticTextButton;
   TGNumberEntry *fNumberEntryModelsMagneticUserButton;
   TGHorizontalFrame *fHorizontalFrameModelsContainer;
   TGVerticalFrame *fVerticalFrameModelsBohrSimulation;
   TRootEmbeddedCanvas *BohrCanvasSimulation;
   TGVerticalFrame *fVerticalFrameModelsQuantumSimulation;
   TRootEmbeddedCanvas *QuantumCanvasSimulation;
   TGHorizontalFrame *fHorizontalFrameModelsOptions;
   TGTextButton *fTextButtonModelsPlayButton;
   TGTextButton *fTextButtonModelsExitButton;
  
public:
  HydrogenSimulatorGUI();
  virtual ~HydrogenSimulatorGUI();

  void OnNChangedQuantum();
  void OnLChangedQuantum();
  void OnNChangedModels();
  void OnLChangedModels();
  void DoDrawBohr();
  void DoDrawQuantum();
  void DoDrawQuantumModels();
  void DoDrawBohrModels();
  void DoExit();
};

#endif
