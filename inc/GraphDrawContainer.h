/*
* ============================================================================
*  Name     : CGraphDrawContainer from GraphDrawContainer.h
*  Part of  : GraphDraw
*  Created  : 3/7/2003 by Makidis Michael
*  Description:
*     Declares container control for application.
*  Copyright: Makidis Michael 2003-2004
* ============================================================================
*/

#ifndef GRAPHDRAWCONTAINER_H
#define GRAPHDRAWCONTAINER_H

// INCLUDES
#include "GraphDrawDocument.h"
#include "GraphDrawView.h"
#include <coecntrl.h>

// CLASS DECLARATION

/**
*  CGraphDrawContainer  container control class.
*  
*/
class CGraphDrawContainer : public CCoeControl, MCoeControlObserver
    {
    public: // Constructors and destructor

		CGraphDrawContainer(CGraphDrawDocument* aDocument, CGraphDrawView *aView);
        
        /**
        * EPOC default constructor.
        * @param aRect Frame rectangle for container.
        */
        void ConstructL(const TRect& aRect);

        /**
        * Destructor.
        */
        ~CGraphDrawContainer();

    public: // New functions

    public: // Functions from base classes
		/**
        * From CoeControl, OfferKeyEventL.
        * Handles the key-events.
        * @return If key-event is consumed, EKeyWasConsumed. Else
        * EKeyWasNotConsumed.
        * @param aKeyEvent Key event.
        * @param aType Type of key event(EEventKey, EEventKeyUp or
        * EEventKeyDown).
        */
        TKeyResponse OfferKeyEventL(
            const TKeyEvent& aKeyEvent,
            TEventCode aType );

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

	public:
		TBool iMoving;
		TBool iZooming;
        
    private: //data

		/*! @var iDocument The current document */
		CGraphDrawDocument* iDocument;

		CGraphDrawView *iView;

		TBuf<15> iMovingText;
		TBuf<15> iZoomingText;
    };

#endif

// End of File
