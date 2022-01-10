/*
* ============================================================================
*  Name     : CGraphDrawAppUi from GraphDrawAppUi.h
*  Part of  : GraphDraw
*  Created  : 3/7/2003 by Makidis Michael
*  Description:
*     Declares UI class for application.
*  Copyright: Makidis Michael 2003-2004
* ============================================================================
*/

#ifndef GRAPHDRAWAPPUI_H
#define GRAPHDRAWAPPUI_H

// INCLUDES
#include <eikapp.h>
#include <eikdoc.h>
#include <e32std.h>
#include <coeccntx.h>
#include <aknviewappui.h>
#include <akntabgrp.h>
#include <aknnavide.h>

// FORWARD DECLARATIONS
class CGraphDrawContainer;
class CGraphDrawDocument;
class CGraphDrawView2;


// CONSTANTS
//const ?type ?constant_var = ?constant;


// CLASS DECLARATION

/**
* Application UI class.
* Provides support for the following features:
* - EIKON control architecture
* - view architecture
* - status pane
* 
*/
class CGraphDrawAppUi : public CAknViewAppUi
    {
    public: // // Constructors and destructor

		CGraphDrawAppUi (CGraphDrawDocument* aDocument);

        /**
        * EPOC default constructor.
        */      
        void ConstructL();

        /**
        * Destructor.
        */      
        ~CGraphDrawAppUi();
        
    public: // New functions

    public: // Functions from base classes
	    

    private:
        // From MEikMenuObserver
        void DynInitMenuPaneL(TInt aResourceId,CEikMenuPane* aMenuPane);

    private:
        /**
        * From CEikAppUi, takes care of command handling.
        * @param aCommand command to be handled
        */
        void HandleCommandL(TInt aCommand);

        /**
        * From CEikAppUi, handles key events.
        * @param aKeyEvent Event to handled.
        * @param aType Type of the key event. 
        * @return Response code (EKeyWasConsumed, EKeyWasNotConsumed). 
        */
        virtual TKeyResponse HandleKeyEventL(
            const TKeyEvent& aKeyEvent,TEventCode aType);

    private: //Data
        CAknNavigationControlContainer* iNaviPane;
        CAknTabGroup*                   iTabGroup;
        CAknNavigationDecorator*        iDecoratedTabGroup;

		/*! @var iDocument The current document */
		CGraphDrawDocument* iDocument;

		CGraphDrawView2* iView2;
    };

#endif

// End of File
