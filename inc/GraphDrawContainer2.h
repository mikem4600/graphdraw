/*
* ============================================================================
*  Name     : CGraphDrawContainer2 from GraphDrawContainer2.h
*  Part of  : GraphDraw
*  Created  : 3/7/2003 by Makidis Michael
*  Description:
*     Declares container control for application.
*  Copyright: Makidis Michael 2003-2004
* ============================================================================
*/

#ifndef GRAPHDRAWCONTAINER2_H
#define GRAPHDRAWCONTAINER2_H

// INCLUDES
#include "GraphDrawView2.h"
#include <coecntrl.h>
 
// FORWARD DECLARATIONS
class CGraphDrawDocument;

// CLASS DECLARATION

/**
*  CGraphDrawContainer2  container control class.
*  
*/
class CGraphDrawContainer2 : public CCoeControl, MCoeControlObserver
    {
    public: // Constructors and destructor
        
        /**
        * EPOC default constructor.
        * @param aRect Frame rectangle for container.
        */
        void ConstructL(const TRect& aRect, CGraphDrawView2* aView);

        /**
        * Destructor.
        */
        ~CGraphDrawContainer2();

    public: // New functions

    public: // Functions from base classes
	    CGraphDrawContainer2(CGraphDrawDocument* aDocument);

    private: // Functions from base classes

       /**
        * From CoeControl,SizeChanged.
        */
        void SizeChanged();

       /**
        * From CoeControl,CountComponentControls.
        */
        TInt CountComponentControls() const;

       /**
        * From CCoeControl,ComponentControl.
        */
        CCoeControl* ComponentControl(TInt aIndex) const;

       /**
        * From CCoeControl,Draw.
        */
        void Draw(const TRect& aRect) const;

       /**
        * From ?base_class ?member_description
        */
        // event handling section
        // e.g Listbox events
        void HandleControlEventL(CCoeControl* aControl,TCoeEvent aEventType);
        
    private: //data
        
        /*CEikLabel* iLabel;          // example label
        CEikLabel* iToDoLabel;      // example label*/
		
		/*! @var iDocument The current document */
		CGraphDrawDocument* iDocument;
		CGraphDrawView2* iView;
    };

#endif

// End of File
