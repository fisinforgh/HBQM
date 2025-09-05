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

#ifndef ROOT_TGDockableFrame
#include "TGDockableFrame.h"
#endif
#ifndef ROOT_TGMdiDecorFrame
#include "TGMdiDecorFrame.h"
#endif
#ifndef ROOT_TG3DLine
#include "TG3DLine.h"
#endif
#ifndef ROOT_TGMdiFrame
#include "TGMdiFrame.h"
#endif
#ifndef ROOT_TGMdiMainFrame
#include "TGMdiMainFrame.h"
#endif
#ifndef ROOT_TGMdiMenu
#include "TGMdiMenu.h"
#endif
#ifndef ROOT_TGListBox
#include "TGListBox.h"
#endif
#ifndef ROOT_TGNumberEntry
#include "TGNumberEntry.h"
#endif
#ifndef ROOT_TGScrollBar
#include "TGScrollBar.h"
#endif
#ifndef ROOT_TGComboBox
#include "TGComboBox.h"
#endif
#ifndef ROOT_TGuiBldHintsEditor
#include "TGuiBldHintsEditor.h"
#endif
#ifndef ROOT_TRootBrowser
#include "TRootBrowser.h"
#endif
#ifndef ROOT_TGuiBldNameFrame
#include "TGuiBldNameFrame.h"
#endif
#ifndef ROOT_TGFrame
#include "TGFrame.h"
#endif
#ifndef ROOT_TGMenu
#include "TGMenu.h"
#endif
#ifndef ROOT_TGFileDialog
#include "TGFileDialog.h"
#endif
#ifndef ROOT_TGShutter
#include "TGShutter.h"
#endif
#ifndef ROOT_TGButtonGroup
#include "TGButtonGroup.h"
#endif
#ifndef ROOT_TGCommandPlugin
#include "TGCommandPlugin.h"
#endif
#ifndef ROOT_TGCanvas
#include "TGCanvas.h"
#endif
#ifndef ROOT_TGFSContainer
#include "TGFSContainer.h"
#endif
#ifndef ROOT_TGuiBldEditor
#include "TGuiBldEditor.h"
#endif
#ifndef ROOT_TGColorSelect
#include "TGColorSelect.h"
#endif
#ifndef ROOT_TGTextEdit
#include "TGTextEdit.h"
#endif
#ifndef ROOT_TGButton
#include "TGButton.h"
#endif
#ifndef ROOT_TRootContextMenu
#include "TRootContextMenu.h"
#endif
#ifndef ROOT_TGFSComboBox
#include "TGFSComboBox.h"
#endif
#ifndef ROOT_TGLabel
#include "TGLabel.h"
#endif
#ifndef ROOT_TGView
#include "TGView.h"
#endif
#ifndef ROOT_TGMsgBox
#include "TGMsgBox.h"
#endif
#ifndef ROOT_TRootGuiBuilder
#include "TRootGuiBuilder.h"
#endif
#ifndef ROOT_TGFileBrowser
#include "TGFileBrowser.h"
#endif
#ifndef ROOT_TGTab
#include "TGTab.h"
#endif
#ifndef ROOT_TGListView
#include "TGListView.h"
#endif
#ifndef ROOT_TGSplitter
#include "TGSplitter.h"
#endif
#ifndef ROOT_TGTextEditor
#include "TGTextEditor.h"
#endif
#ifndef ROOT_TRootCanvas
#include "TRootCanvas.h"
#endif
#ifndef ROOT_TGStatusBar
#include "TGStatusBar.h"
#endif
#ifndef ROOT_TGListTree
#include "TGListTree.h"
#endif
#ifndef ROOT_TGuiBldGeometryFrame
#include "TGuiBldGeometryFrame.h"
#endif
#ifndef ROOT_TGToolTip
#include "TGToolTip.h"
#endif
#ifndef ROOT_TGToolBar
#include "TGToolBar.h"
#endif
#ifndef ROOT_TRootEmbeddedCanvas
#include "TRootEmbeddedCanvas.h"
#endif
#ifndef ROOT_TCanvas
#include "TCanvas.h"
#endif
#ifndef ROOT_TGuiBldDragManager
#include "TGuiBldDragManager.h"
#endif
#ifndef ROOT_TGHtmlBrowser
#include "TGHtmlBrowser.h"
#endif

#include <TApplication.h>
#include "Riostream.h"
#include "SEHBQM.h"
#include <cmath>
#include <iomanip>
#include "TCanvas.h"
#include "TGraph.h"
#include "TAxis.h"
#include "TMath.h"
#include <Riostream.h>
#include "TLegend.h"
#include "TLegendEntry.h"
#include "TF1.h"
#include <TImage.h>
#include "Include/PiConstant.h"
#include "TSystem.h"
#include "Include/BohrTimer.h"
#include "Include/BohrDrawer.h"
#include "Math/SpecFuncMathCore.h"
#include "Include/RadialFunction.h"
#include "Include/AngularFunction.h"
#include "Include/PhiFunction.h"
#include "Include/SchrodingerDrawer.h"
#include "Include/QuantumModelDrawer.h"

HydrogenSimulatorGUI::HydrogenSimulatorGUI(){

   gSystem->Load("libMathMore");
  
   fMainFrame = new TGMainFrame(gClient->GetRoot(), 10, 10, kMainFrame | kVerticalFrame);
   fMainFrame->SetName("fMainFrame");
   fCentralFrame = new TGCompositeFrame(fMainFrame, 1452, 902, kVerticalFrame);
   fCentralFrame->SetName("fCentralFrame");
   fCentralFrame->SetLayoutManager(new TGVerticalLayout(fCentralFrame));

   fTab = new TGTab(fCentralFrame, 1440, 888);

   // Construction and configuration of the Home in the GUI
   
   fHomeFrame = fTab->AddTab("Home");
   fHomeFrame->SetLayoutManager(new TGVerticalLayout(fHomeFrame));
   
   ExpandHome = new TGLayoutHints(kLHintsExpandX | kLHintsExpandY);
   EmbeddedHome = new TRootEmbeddedCanvas("HomeCanvas", fHomeFrame, 800, 600);
   fHomeFrame->AddFrame( EmbeddedHome, ExpandHome);
   
   // Draw the image inside the canvas
   homeCanvas =  EmbeddedHome->GetCanvas();
   coverImage = TImage::Open("Icons/home.png");

    if (coverImage) {
    coverImage->Draw("xxx");   // xxx = auto scale
    homeCanvas->Update();
    }

 
   // Construction and configuration of the Bohr model tab in the GUI
   
   fBohrFrame = fTab->AddTab("Bohr Model");
   fBohrFrame->SetLayoutManager(new TGVerticalLayout(fBohrFrame));
   fHorizontalFrameBohrContainer = new TGHorizontalFrame(fBohrFrame, 1432, 848, kHorizontalFrame);

   fVerticalFrameBohrUser = new TGVerticalFrame(fHorizontalFrameBohrContainer, 256, 800, kVerticalFrame);
   fVerticalFrameBohrUser->SetLayoutManager(new TGVerticalLayout(fVerticalFrameBohrUser));
   fGroupFrameBohrUserButtons = new TGGroupFrame(fVerticalFrameBohrUser, "Controls");
   fGroupFrameBohrUserButtons->SetLayoutManager(new TGVerticalLayout(fGroupFrameBohrUserButtons));
   fLabelBohrEnergyText = new TGLabel(fGroupFrameBohrUserButtons, "Energy Level (n): ");
   fGroupFrameBohrUserButtons->AddFrame(fLabelBohrEnergyText, new TGLayoutHints(kLHintsLeft | kLHintsTop, 5, 5, 5, 5));
   fNumberEntryBohrEnergyButton = new TGNumberEntry(fGroupFrameBohrUserButtons, (Double_t)1, 19, -1, (TGNumberFormat::EStyle)5);
   fNumberEntryBohrEnergyButton->SetLimits(TGNumberFormat::kNELLimitMinMax, 1, 8);
   fGroupFrameBohrUserButtons->AddFrame(fNumberEntryBohrEnergyButton, new TGLayoutHints(kLHintsLeft | kLHintsTop, 5, 5, 5, 5));
   fVerticalFrameBohrUser->AddFrame(fGroupFrameBohrUserButtons, new TGLayoutHints(kLHintsExpandX, 5, 5, 5, 5)); 
   fGroupFrameBohrUserText = new TGGroupFrame(fVerticalFrameBohrUser, "Considerations:");
   fGroupFrameBohrUserText->SetLayoutManager(new TGVerticalLayout(fGroupFrameBohrUserText));
   fVerticalFrameBohrUser->AddFrame(fGroupFrameBohrUserText, new TGLayoutHints(kLHintsExpandX | kLHintsExpandY, 5, 5, 5, 5));
   CanvasBohrText = new TRootEmbeddedCanvas("CanvasBohrText", fGroupFrameBohrUserText, 400, 300);
   fGroupFrameBohrUserText->AddFrame(CanvasBohrText, new TGLayoutHints(kLHintsExpandX | kLHintsExpandY, 2, 2, 2, 2));
   bohrTextCanvas = CanvasBohrText->GetCanvas();
   bohrTextBox = new TPaveText(0.0, 0.0, 1.0, 1.0, "NDC");
   bohrTextBox->SetTextAlign(10); // izquierda, centrado verticalmente
   bohrTextBox->SetTextFont(42);
   bohrTextBox->SetTextColor(0);
   bohrTextBox->SetTextSize(0.04);
   //bohrTextBox->SetFillColor(kTeal -7);
   bohrTextBox->SetFillColor(kRed -6);
   bohrTextBox->AddText("#font[69]{In this model, the electron moves in circular orbits}");
   bohrTextBox->AddText("#font[69]{around the nucleus, like a planet around the Sun,}");
   bohrTextBox->AddText("#font[69]{but with the difference that it is at the atomic scale,}");
   bohrTextBox->AddText("#font[69]{with only certain energies and orbits allowed.}");
   bohrTextBox->AddText("#font[69]{The nucleus (orange sphere) remains at rest, while}");
   bohrTextBox->AddText("#font[69]{the electron (black sphere) follows its average path}");
   bohrTextBox->AddText("#font[69]{(cyan line).}");
   bohrTextBox->AddText("#font[69]{The purple wavy line represents the de Broglie}");
   bohrTextBox->AddText("#font[69]{wavelength: the circumference of the orbit}");
   bohrTextBox->AddText("#font[69]{must be an integer multiple of it.}");
   bohrTextBox->AddText("#font[69]{This wave-particle duality links classical motion}");
   bohrTextBox->AddText("#font[69]{with quantum mechanics, bridging the two theories.}");
   bohrTextBox->AddText("#font[69]{By changing the quantum number n, the simulation}");
   bohrTextBox->AddText("#font[69]{calculates the orbit radius, angular velocity,}");
   bohrTextBox->AddText("#font[69]{and energy, showing how these quantities}");
   bohrTextBox->AddText("#font[69]{are related to the electron's energy level.}");
   bohrTextBox->Draw();
   bohrTextCanvas->Modified();
   bohrTextCanvas->Update();
   fHorizontalFrameBohrContainer->AddFrame(fVerticalFrameBohrUser, new TGLayoutHints(kLHintsLeft | kLHintsExpandY, 5, 5, 5, 5));

   fVerticalFrameBohrSimulation = new TGVerticalFrame(fHorizontalFrameBohrContainer, 1084, 796, kVerticalFrame);
   fVerticalFrameBohrSimulation->SetLayoutManager(new TGVerticalLayout(fVerticalFrameBohrSimulation));
   fRootEmbeddedCanvasBohr = new TRootEmbeddedCanvas(0, fVerticalFrameBohrSimulation, 1080, 680, kRaisedFrame);
   wfRootEmbeddedCanvasBohr = fRootEmbeddedCanvasBohr->GetCanvasWindowId();
   fcanvasBohr = new TCanvas("fcanvasBohr", 10, 10, wfRootEmbeddedCanvasBohr);
   fRootEmbeddedCanvasBohr->AdoptCanvas(fcanvasBohr);
   fVerticalFrameBohrSimulation->AddFrame(fRootEmbeddedCanvasBohr, new TGLayoutHints(kLHintsExpandX | kLHintsExpandY, 5, 5, 5, 5));
   fHorizontalFrameBohrOptions = new TGHorizontalFrame(fVerticalFrameBohrSimulation, 1080, 108, kHorizontalFrame| kRaisedFrame);
   fTextButtonBohrPlay = new TGTextButton(fHorizontalFrameBohrOptions, "Pla&y");   
   fTextButtonBohrPlay->Connect("Clicked()", "HydrogenSimulatorGUI", this, "DoDrawBohr()");
   fHorizontalFrameBohrOptions->AddFrame(fTextButtonBohrPlay, new TGLayoutHints(kLHintsCenterX | kLHintsCenterY, 20, 20, 10, 10));
   fVertical3DLineBohrOptions = new TGVertical3DLine(fHorizontalFrameBohrOptions, 8, 102);
   fHorizontalFrameBohrOptions->AddFrame(fVertical3DLineBohrOptions, new TGLayoutHints(kLHintsCenterY));
   fTextButtonBohrExit = new TGTextButton(fHorizontalFrameBohrOptions, "Exi&t");
   fTextButtonBohrExit->Connect("Clicked()", "HydrogenSimulatorGUI", this, "DoExit()");
   fHorizontalFrameBohrOptions->AddFrame(fTextButtonBohrExit, new TGLayoutHints(kLHintsCenterX | kLHintsCenterY, 20, 20, 10, 10));
   fVerticalFrameBohrSimulation->AddFrame(fHorizontalFrameBohrOptions, new TGLayoutHints(kLHintsExpandX, 5, 5, 5, 5));
   fHorizontalFrameBohrContainer->AddFrame(fVerticalFrameBohrSimulation, new TGLayoutHints(kLHintsExpandX | kLHintsExpandY, 5, 5, 5, 5));
   fBohrFrame->AddFrame(fHorizontalFrameBohrContainer, new TGLayoutHints(kLHintsExpandX | kLHintsExpandY));
   

   // Construction and configuration of the Quantum model tab in the GUI
   
   fCompositeQuantumFrame = fTab->AddTab("Quantum Model");
   fCompositeQuantumFrame->SetLayoutManager(new TGVerticalLayout(fCompositeQuantumFrame));
   fVerticalFrameQuantumContainer = new TGVerticalFrame(fCompositeQuantumFrame, 1424, 864, kVerticalFrame);
   fVerticalFrameQuantumContainer->SetLayoutManager(new TGHorizontalLayout(fVerticalFrameQuantumContainer)); // divide izquierda y derecha

   fVerticalFrameQuantumUser = new TGVerticalFrame(fVerticalFrameQuantumContainer, 300, 864, kVerticalFrame | kRaisedFrame);
   fVerticalFrameQuantumUser->SetLayoutManager(new TGVerticalLayout(fVerticalFrameQuantumUser));
   fGroupFrameQuantumUserButtons = new TGGroupFrame(fVerticalFrameQuantumUser, "Controls");
   fGroupFrameQuantumUserButtons->SetLayoutManager(new TGVerticalLayout(fGroupFrameQuantumUserButtons));
   fLabelQuantumEnergyUserText = new TGLabel(fGroupFrameQuantumUserButtons, "Energy Level (n):");
   fGroupFrameQuantumUserButtons->AddFrame(fLabelQuantumEnergyUserText, new TGLayoutHints(kLHintsLeft | kLHintsTop, 5, 5, 5, 5));
   fNumberEntryQuantumEnergyButton = new TGNumberEntry(fGroupFrameQuantumUserButtons, 1.0, 19, -1, TGNumberFormat::kNESInteger);
   fNumberEntryQuantumEnergyButton->SetLimits(TGNumberFormat::kNELLimitMinMax, 1, 8);
   fGroupFrameQuantumUserButtons->AddFrame(fNumberEntryQuantumEnergyButton, new TGLayoutHints(kLHintsLeft | kLHintsTop, 5, 5, 5, 5));
   fLabelQuantumOrbitalUserText = new TGLabel(fGroupFrameQuantumUserButtons, "Orbital Angular Momentum (l):");
   fGroupFrameQuantumUserButtons->AddFrame(fLabelQuantumOrbitalUserText, new TGLayoutHints(kLHintsLeft | kLHintsTop, 5, 5, 5, 5));
   fNumberEntryQuantumOrbitalButton = new TGNumberEntry(fGroupFrameQuantumUserButtons, 1.0, 19, -1, TGNumberFormat::kNESInteger);
   fGroupFrameQuantumUserButtons->AddFrame(fNumberEntryQuantumOrbitalButton, new TGLayoutHints(kLHintsLeft | kLHintsTop, 5, 5, 5, 5));
   fLabelQuantumMagneticUserText = new TGLabel(fGroupFrameQuantumUserButtons, "Magnetic Quantum Number (m):");
   fGroupFrameQuantumUserButtons->AddFrame(fLabelQuantumMagneticUserText, new TGLayoutHints(kLHintsLeft | kLHintsTop, 5, 5, 5, 5));
   fNumberEntryQuantumMagneticButton = new TGNumberEntry(fGroupFrameQuantumUserButtons, 0.0, 19, -1, TGNumberFormat::kNESInteger);
   fGroupFrameQuantumUserButtons->AddFrame(fNumberEntryQuantumMagneticButton, new TGLayoutHints(kLHintsLeft | kLHintsTop, 5, 5, 5, 5));
   fVerticalFrameQuantumUser->AddFrame(fGroupFrameQuantumUserButtons, new TGLayoutHints(kLHintsExpandX, 5, 5, 5, 5));
   fGroupFrameQuantumUserText = new TGGroupFrame(fVerticalFrameQuantumUser, "Considerations:");
   fGroupFrameQuantumUserText->SetLayoutManager(new TGVerticalLayout(fGroupFrameQuantumUserText));
   fVerticalFrameQuantumUser->AddFrame(fGroupFrameQuantumUserText, new TGLayoutHints(kLHintsExpandX | kLHintsExpandY, 5, 5, 5, 5));
   CanvasQuantumText = new TRootEmbeddedCanvas("CanvasQuantumText", fGroupFrameQuantumUserText, 400, 300);
   fGroupFrameQuantumUserText->AddFrame(CanvasQuantumText, new TGLayoutHints(kLHintsExpandX | kLHintsExpandY, 2, 2, 2, 2));
   quantumTextCanvas = CanvasQuantumText->GetCanvas();
   quantumTextBox = new TPaveText(0.0, 0.0, 1.0, 1.0, "NDC");
   quantumTextBox->SetTextAlign(10);
   quantumTextBox->SetTextFont(42);
   quantumTextBox->SetTextColor(0);
   quantumTextBox->SetTextSize(0.04);
   quantumTextBox->SetFillColor(kBlue-6); 
   quantumTextBox->AddText("#bf{The quantum model of the hydrogen atom describes}");
   quantumTextBox->AddText("#bf{the electron using wavefunctions #psi(r,#theta,#phi),}");
   quantumTextBox->AddText("#bf{where the probability density is given by |#psi|^{2}.}");
   quantumTextBox->AddText("#bf{This tab displays:}");
   quantumTextBox->AddText("#bf{Radial probability density (top left): likelihood of}");
   quantumTextBox->AddText("#bf{finding the electron at distance r from the nucleus.}");
   quantumTextBox->AddText("#bf{Angular probability density (top right): shows}");
   quantumTextBox->AddText("#bf{how this probability varies as a function of the}");
   quantumTextBox->AddText("#bf{polar angle #theta.}");
   quantumTextBox->AddText("#bf{3D probability density - point cloud (bottom right):}");
   quantumTextBox->AddText("#bf{set of probable points representing the electron’s}");
   quantumTextBox->AddText("#bf{localization around the nucleus.}");
   quantumTextBox->AddText("#bf{3D probability density - solid surface (bottom left):}");
   quantumTextBox->AddText("#bf{volumetric representation suggesting the orbital}");
   quantumTextBox->AddText("#bf{shape.}");
   quantumTextBox->AddText("#bf{Changing the quantum numbers updates the graphs,}");
   quantumTextBox->AddText("#bf{revealing how the spatial probability patterns evolve.}");
   quantumTextBox->Draw();
   quantumTextCanvas->Modified();
   quantumTextCanvas->Update();
   fNumberEntryQuantumOrbitalButton->SetState(kFALSE);
   fNumberEntryQuantumOrbitalButton->SetNumber(0);
   fNumberEntryQuantumMagneticButton->SetState(kFALSE);
   fNumberEntryQuantumMagneticButton->SetNumber(0);
   fNumberEntryQuantumEnergyButton->Connect("ValueSet(Long_t)", "HydrogenSimulatorGUI", this, "OnNChangedQuantum()");
   fNumberEntryQuantumOrbitalButton->Connect("ValueSet(Long_t)", "HydrogenSimulatorGUI", this, "OnLChangedQuantum()");
   fVerticalFrameQuantumContainer->AddFrame(fVerticalFrameQuantumUser, new TGLayoutHints(kLHintsExpandY, 5, 5, 5, 5));
   
   fVerticalFrameQuantumSimulation = new TGVerticalFrame(fVerticalFrameQuantumContainer, 1084, 796, kVerticalFrame);
   fVerticalFrameQuantumSimulation->SetLayoutManager(new TGVerticalLayout(fVerticalFrameQuantumSimulation));
   fRootEmbeddedCanvasQuantum = new TRootEmbeddedCanvas(0, fVerticalFrameQuantumSimulation, 1084, 796, kRaisedFrame);
   wfRootEmbeddedCanvasQuantum = fRootEmbeddedCanvasQuantum->GetCanvasWindowId();
   fcanvasQuantum = new TCanvas("fcanvasQuantum", 10, 10, wfRootEmbeddedCanvasQuantum);
   fRootEmbeddedCanvasQuantum->AdoptCanvas(fcanvasQuantum);
   fVerticalFrameQuantumSimulation->AddFrame(fRootEmbeddedCanvasQuantum, new TGLayoutHints(kLHintsExpandX | kLHintsExpandY, 5, 5, 5, 5));
   fHorizontalFrameQuantumOptions = new TGHorizontalFrame(fVerticalFrameQuantumSimulation, 1080, 108, kHorizontalFrame| kRaisedFrame);
   fTextButtonQuantumPlayButton = new TGTextButton(fHorizontalFrameQuantumOptions, "Pla&y");
   fTextButtonQuantumPlayButton->Connect("Clicked()", "HydrogenSimulatorGUI", this, "DoDrawQuantum()");
   fHorizontalFrameQuantumOptions->AddFrame(fTextButtonQuantumPlayButton, new TGLayoutHints(kLHintsCenterX | kLHintsCenterY, 20, 20, 10, 10));
   fVertical3DLineQuantumOptionsLine = new TGVertical3DLine(fHorizontalFrameQuantumOptions, 8, 102);
   fHorizontalFrameQuantumOptions->AddFrame(fVertical3DLineQuantumOptionsLine, new TGLayoutHints(kLHintsCenterY));
   fTextButtonQuantumExitButton = new TGTextButton(fHorizontalFrameQuantumOptions, "Exi&t");
   fTextButtonQuantumExitButton->Connect("Clicked()", "HydrogenSimulatorGUI", this, "DoExit()");
   fHorizontalFrameQuantumOptions->AddFrame(fTextButtonQuantumExitButton, new TGLayoutHints(kLHintsCenterX | kLHintsCenterY, 20, 20, 10, 10));
   fVerticalFrameQuantumSimulation->AddFrame(fHorizontalFrameQuantumOptions, new TGLayoutHints(kLHintsExpandX, 5, 5, 5, 5));
   fVerticalFrameQuantumContainer->AddFrame(fVerticalFrameQuantumSimulation, new TGLayoutHints(kLHintsExpandX | kLHintsExpandY, 5, 5, 5, 5));
   fCompositeQuantumFrame->AddFrame(fVerticalFrameQuantumContainer, new TGLayoutHints(kLHintsExpandX | kLHintsExpandY));
    

   // Construction and configuration of the Models tab, including both the Bohr and Quantum models.

   fModelsFrame = fTab->AddTab("Both Models");
   fModelsFrame->SetLayoutManager(new TGVerticalLayout(fModelsFrame));

   fHorizontalFrameModelsUser = new TGHorizontalFrame(fModelsFrame, 0, 0, kRaisedFrame);
   fLabelModelsEnergyTextButton = new TGLabel(fHorizontalFrameModelsUser, "Energy Level (n):");
   fHorizontalFrameModelsUser->AddFrame(fLabelModelsEnergyTextButton, new TGLayoutHints(kLHintsCenterY | kLHintsLeft, 5, 5, 5, 5));
   fNumberEntryModelsEnergyUserButton = new TGNumberEntry(fHorizontalFrameModelsUser, 0, 6, -1, TGNumberFormat::kNESInteger);
   fNumberEntryModelsEnergyUserButton->SetLimits(TGNumberFormat::kNELLimitMinMax, 1, 8);
   fHorizontalFrameModelsUser->AddFrame(fNumberEntryModelsEnergyUserButton, new TGLayoutHints(kLHintsCenterY, 5, 15, 5, 5));
   fHorizontalFrameModelsUser->AddFrame(new TGVertical3DLine(fHorizontalFrameModelsUser), new TGLayoutHints(kLHintsExpandY));
   fLabelModelsOrbitalTextButton = new TGLabel(fHorizontalFrameModelsUser, "Orbital Angular Momentum (l):");
   fHorizontalFrameModelsUser->AddFrame(fLabelModelsOrbitalTextButton, new TGLayoutHints(kLHintsCenterY, 5, 5, 5, 5));
   fNumberEntryModelsOrbitalUserButton = new TGNumberEntry(fHorizontalFrameModelsUser, 0, 6, -1, TGNumberFormat::kNESInteger);
   fHorizontalFrameModelsUser->AddFrame(fNumberEntryModelsOrbitalUserButton, new TGLayoutHints(kLHintsCenterY, 5, 15, 5, 5));
   fHorizontalFrameModelsUser->AddFrame(new TGVertical3DLine(fHorizontalFrameModelsUser), new TGLayoutHints(kLHintsExpandY));
   fLabelModelsMagneticTextButton = new TGLabel(fHorizontalFrameModelsUser, "Magnetic Quantum Number (m):");
   fHorizontalFrameModelsUser->AddFrame(fLabelModelsMagneticTextButton, new TGLayoutHints(kLHintsCenterY, 5, 5, 5, 5));
   fNumberEntryModelsMagneticUserButton = new TGNumberEntry(fHorizontalFrameModelsUser, 0, 6, -1, TGNumberFormat::kNESInteger);
   fHorizontalFrameModelsUser->AddFrame(fNumberEntryModelsMagneticUserButton, new TGLayoutHints(kLHintsCenterY, 5, 5, 5, 5));
   fModelsFrame->AddFrame(fHorizontalFrameModelsUser, new TGLayoutHints(kLHintsExpandX));
   fNumberEntryModelsOrbitalUserButton->SetState(kFALSE);
   fNumberEntryModelsMagneticUserButton->SetNumber(0);
   fNumberEntryModelsMagneticUserButton->SetState(kFALSE);
   fNumberEntryModelsMagneticUserButton->SetNumber(0);
   fNumberEntryModelsEnergyUserButton->Connect("ValueSet(Long_t)", "HydrogenSimulatorGUI", this, "OnNChangedModels()");
   fNumberEntryModelsOrbitalUserButton->Connect("ValueSet(Long_t)", "HydrogenSimulatorGUI", this, "OnLChangedModels()");

   fHorizontalFrameModelsContainer = new TGHorizontalFrame(fModelsFrame);
   fVerticalFrameModelsBohrSimulation = new TGVerticalFrame(fHorizontalFrameModelsContainer, 0, 0, kRaisedFrame);
   BohrCanvasSimulation = new TRootEmbeddedCanvas("BohrCanvas", fVerticalFrameModelsBohrSimulation, 400, 300);
   fVerticalFrameModelsBohrSimulation->AddFrame(BohrCanvasSimulation, new TGLayoutHints(kLHintsExpandX | kLHintsExpandY));
   fVerticalFrameModelsBohrSimulation->AddFrame(new TGLabel(fVerticalFrameModelsBohrSimulation, "Bohr Model"), new TGLayoutHints(kLHintsCenterX, 5, 5, 5, 5));
   fVerticalFrameModelsQuantumSimulation = new TGVerticalFrame(fHorizontalFrameModelsContainer, 0, 0, kRaisedFrame);
   QuantumCanvasSimulation = new TRootEmbeddedCanvas("QuantumCanvas", fVerticalFrameModelsQuantumSimulation, 400, 300);
   fVerticalFrameModelsQuantumSimulation->AddFrame(QuantumCanvasSimulation, new TGLayoutHints(kLHintsExpandX | kLHintsExpandY));
   fVerticalFrameModelsQuantumSimulation->AddFrame(new TGLabel(fVerticalFrameModelsQuantumSimulation, "Quantum Model"), new TGLayoutHints(kLHintsCenterX, 5, 5, 5, 5));
   fHorizontalFrameModelsContainer->AddFrame(fVerticalFrameModelsBohrSimulation, new TGLayoutHints(kLHintsExpandX | kLHintsExpandY, 5, 5, 5, 5));
   fHorizontalFrameModelsContainer->AddFrame(new TGLabel(fHorizontalFrameModelsContainer, "VS"), new TGLayoutHints(kLHintsCenterY, 10, 10, 0, 0));
   fHorizontalFrameModelsContainer->AddFrame(fVerticalFrameModelsQuantumSimulation, new TGLayoutHints(kLHintsExpandX | kLHintsExpandY, 5, 5, 5, 5));
   fModelsFrame->AddFrame(fHorizontalFrameModelsContainer, new TGLayoutHints(kLHintsExpandX | kLHintsExpandY));
   fHorizontalFrameModelsOptions = new TGHorizontalFrame(fModelsFrame, 0, 0, kRaisedFrame);
   fTextButtonModelsPlayButton = new TGTextButton(fHorizontalFrameModelsOptions, "&Play");
   fTextButtonModelsPlayButton->Connect("Clicked()", "HydrogenSimulatorGUI", this, "DoDrawBohrModels()");
   fTextButtonModelsPlayButton->Connect("Clicked()", "HydrogenSimulatorGUI", this, "DoDrawQuantumModels()");
   fTextButtonModelsExitButton = new TGTextButton(fHorizontalFrameModelsOptions, "E&xit");
   fTextButtonModelsExitButton->Connect("Clicked()", "HydrogenSimulatorGUI", this, "DoExit()");
   fHorizontalFrameModelsOptions->AddFrame(fTextButtonModelsPlayButton, new TGLayoutHints(kLHintsExpandX | kLHintsCenterY, 10, 10, 10, 10));
   fHorizontalFrameModelsOptions->AddFrame(fTextButtonModelsExitButton, new TGLayoutHints(kLHintsExpandX | kLHintsCenterY, 10, 10, 10, 10));
   fModelsFrame->AddFrame(fHorizontalFrameModelsOptions, new TGLayoutHints(kLHintsExpandX));
 
   fTab->SetTab(0);
   fTab->Resize(fTab->GetDefaultSize());
   fCentralFrame->AddFrame(fTab, new TGLayoutHints(kLHintsExpandX | kLHintsExpandY, 5, 5, 5, 5));
   fMainFrame->AddFrame(fCentralFrame, new TGLayoutHints(kLHintsExpandX | kLHintsExpandY));
   fMainFrame->SetMWMHints(kMWMDecorAll,
                           kMWMFuncAll,
                           kMWMInputModeless);
   fMainFrame->MapSubwindows();
   fMainFrame->Resize(fMainFrame->GetDefaultSize());
   fMainFrame->MapWindow();
   fMainFrame->Resize(1445, 882);
   fMainFrame->Connect("CloseWindow()", "HydrogenSimulatorGUI", this, "DoExit()");
}

void HydrogenSimulatorGUI::OnNChangedQuantum() {
  
    // Retrieve the current principal quantum number (n) from the energy level number entry widget
    int n = (int)fNumberEntryQuantumEnergyButton->GetNumber();

    if (n >= 1) {
        // Enable the orbital quantum number (l) input field
        // and set its valid range from 0 to n - 1, according to quantum mechanics rules
        fNumberEntryQuantumOrbitalButton->SetState(kTRUE);
        fNumberEntryQuantumOrbitalButton->SetLimits(TGNumberFormat::kNELLimitMinMax, 0, n - 1);

        // Reset l to a valid default value (0)
        fNumberEntryQuantumOrbitalButton->SetNumber(0);

        // Disable the magnetic quantum number (m) input field
        // and reset its value to 0, awaiting a valid l selection
        fNumberEntryQuantumMagneticButton->SetState(kFALSE);
        fNumberEntryQuantumMagneticButton->SetNumber(0);
    }
}

//----------------------------------------------------

void HydrogenSimulatorGUI::OnLChangedQuantum() {
  
   // Retrieve the orbital quantum number (l)
   int l = (int)fNumberEntryQuantumOrbitalButton->GetNumber();

   // Enable m input and set valid range: -l ≤ m ≤ l
   fNumberEntryQuantumMagneticButton->SetState(kTRUE);
   fNumberEntryQuantumMagneticButton->SetLimits(TGNumberFormat::kNELLimitMinMax, -l, l);

   // Ensure m is within the new valid range
   int m = (int)fNumberEntryQuantumMagneticButton->GetNumber();
   if (m < -l || m > l) {
       fNumberEntryQuantumMagneticButton->SetNumber(0);
    }
}

//---------------------------

void HydrogenSimulatorGUI::OnNChangedModels(){

  int n = (int)fNumberEntryModelsEnergyUserButton->GetNumber();

    if (n >= 1) {
        // Enable l input and set valid range: 0 ≤ l ≤ n - 1
        fNumberEntryModelsOrbitalUserButton->SetState(kTRUE);
        fNumberEntryModelsOrbitalUserButton->SetLimits(TGNumberFormat::kNELLimitMinMax, 0, n - 1);

        // Reset l to default
        fNumberEntryModelsOrbitalUserButton->SetNumber(0);

        // Disable m input until l is valid
        fNumberEntryModelsMagneticUserButton->SetState(kFALSE);
        fNumberEntryModelsMagneticUserButton->SetNumber(0);
    }
}

void HydrogenSimulatorGUI::OnLChangedModels() {
  
  int l = (int)fNumberEntryModelsOrbitalUserButton->GetNumber();

    
  // Enable m input and set valid range: -l ≤ m ≤ l
  fNumberEntryModelsMagneticUserButton->SetState(kTRUE);
  fNumberEntryModelsMagneticUserButton->SetLimits(TGNumberFormat::kNELLimitMinMax, -l, l);

  // Ensure m is valid
  int m = (int)fNumberEntryModelsMagneticUserButton->GetNumber();
  if (m < -l || m > l) {
      fNumberEntryModelsMagneticUserButton->SetNumber(0);
    }
}


//---------------------------------
//Draws the Bohr model in the Bohr tab.

void HydrogenSimulatorGUI::DoDrawBohr() {
  
  int n = fNumberEntryBohrEnergyButton->GetIntNumber();
  TCanvas* canvas = fRootEmbeddedCanvasBohr->GetCanvas();
  BohrSim::DrawBohrModel(canvas, n);
}
//---------------------------------
//Draws the quantum mechanical model in the Quantum tab.

void HydrogenSimulatorGUI::DoDrawQuantum() {
  
  int n = fNumberEntryQuantumEnergyButton->GetNumber();
  int l = fNumberEntryQuantumOrbitalButton->GetNumber();
  int m = fNumberEntryQuantumMagneticButton->GetNumber();
  TCanvas* canvas = fRootEmbeddedCanvasQuantum->GetCanvas();
  canvas->cd();
  canvas->Clear();                 // Clear the canvas before drawing
  canvas->GetListOfPrimitives()->Delete();
  
  // --- Display a "please wait" message ---
  // TPaveText is used here to show a temporary message on the canvas
  // This informs the user that the program is processing and prevents the GUI
  // from appearing frozen while the 3D quantum model is being generated.
  TPaveText* runningText = new TPaveText(0.3, 0.45, 0.7, 0.55, "NDC");
  runningText->AddText("PLEASE WAIT WHILE LOADING...");
  runningText->SetTextColor(kBlue);
  runningText->SetFillColor(0);
  canvas->cd();
  runningText->Draw();
  canvas->Update();// Process GUI events so the message is rendered immediately

  // --- Draw the quantum model ---
  // Clear the canvas again to remove the temporary message
  canvas->Clear();
  canvas->GetListOfPrimitives()->Delete();
  SchrodingerDrawer(n, l, m, canvas);
  canvas->Update();
  }   

//------------------------------------
//Draws the Bohr model without text labels in the "Models" tab.

void HydrogenSimulatorGUI::DoDrawBohrModels() {
  
  int n = fNumberEntryModelsEnergyUserButton->GetIntNumber();
  TCanvas* canvas = BohrCanvasSimulation->GetCanvas();
  BohrSim::DrawBohrModel(canvas, n, false); // Force showText = false
}


//------------------------------------
//Draws the Quantum model in the "Models" tab.

void HydrogenSimulatorGUI::DoDrawQuantumModels() {
  
  int n = fNumberEntryModelsEnergyUserButton->GetNumber();
  int l = fNumberEntryModelsOrbitalUserButton->GetNumber();
  int m = fNumberEntryModelsMagneticUserButton->GetNumber();    
  TCanvas* canvas = QuantumCanvasSimulation->GetCanvas();
  canvas->cd();
  canvas->Clear();                
  canvas->GetListOfPrimitives()->Delete();

  // Similar to the DoDrawQuantum signal function
  TPaveText* runningText = new TPaveText(0.3, 0.45, 0.7, 0.55, "NDC");
  runningText->AddText("PLEASE WAIT WHILE LOADING...");
  runningText->SetTextColor(kBlue);
  runningText->SetFillColor(0);
  canvas->cd();
  runningText->Draw();
  canvas->Update();
  gSystem->ProcessEvents();

  canvas->Clear();
  canvas->GetListOfPrimitives()->Delete();
  QuantumModelDrawer(n, l, m, canvas);
  canvas->Update();
  }

//--------------------------------
//Closes the application.

void HydrogenSimulatorGUI::DoExit() {

   gApplication->Terminate(0);
}

HydrogenSimulatorGUI::~HydrogenSimulatorGUI() {
    delete fMainFrame;
}
 
void HydrogenAtom() {
    new HydrogenSimulatorGUI();
}

int main(int argc, char **argv) {
    TApplication theApp("HydrogenApp", &argc, argv);
    HydrogenAtom();
    theApp.Run();
    return 0;
    }
