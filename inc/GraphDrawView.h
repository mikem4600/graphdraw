/*
* ============================================================================
*  Name     : CGraphDrawView from GraphDrawView.h
*  Part of  : GraphDraw
*  Created  : 3/7/2003 by Makidis Michael
*  Description:
*     Declares view for application.
*  Copyright: Makidis Michael 2003-2004
* ============================================================================
*/

#ifndef GRAPHDRAWVIEW_H
#define GRAPHDRAWVIEW_H

// INCLUDES
#include <aknview.h>


// CONSTANTS
// UID of view
const TUid KViewId = {1};

// FORWARD DECLARATIONS
class CGraphDrawContainer;
class CGraphDrawDocument;

// CLASS DECLARATION

/**
*  CGraphDrawView view class.
* 
*/
class CGraphDrawView : public CAknView
    {
    public: // Constructors and destructor

		CGraphDrawView(CGraphDrawDocument* aDocument);

        /**
        * EPOC default constructor.
        */
        void ConstructL();

        /**
        * Destructor.
        */
        ~CGraphDrawView();

    public: // Functions from base classes
	    
        /**
        * From ?base_class ?member_description
        */
        TUid Id() const;

        /**
        * From ?base_class ?member_description
        */
        void HandleCommandL(TInt aCommand);

        /**
        * From ?base_class ?member_description
        */
        void HandleClientRectChange();

    private:

        /**
        * From AknView, ?member_description
        */
        void DoActivateL(const TVwsViewId& aPrevViewId,TUid aCustomMessageId,
            const TDesC8& aCustomMessage);

        /**
        * From AknView, ?member_description
        */
        void DoDeactivate();

    private: // Data
        CGraphDrawContainer* iContainer;

		/*! @var iDocument The current document */
		CGraphDrawDocument* iDocument;
    };

#endif

// End of File
