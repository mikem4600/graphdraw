/*
* ============================================================================
*  Name     : CGraphDrawView3 from GraphDrawView3.h
*  Part of  : GraphDraw
*  Created  : 3/7/2003 by Makidis Michael
*  Description:
*     Declares view for application.
*  Copyright: Makidis Michael 2003-2004
* ============================================================================
*/

#ifndef GRAPHDRAWVIEW3_H
#define GRAPHDRAWVIEW3_H

// INCLUDES
#include <aknview.h>


// CONSTANTS
// UID of view
const TUid KView3Id = {3};

// FORWARD DECLARATIONS
class CGraphDrawContainer3;
class CGraphDrawDocument;


// CLASS DECLARATION

/**
*  CGraphDrawView3 view class.
* 
*/
class CGraphDrawView3 : public CAknView
    {
    public: // Constructors and destructor

	    CGraphDrawView3(CGraphDrawDocument* aDocument);

        /**
        * EPOC default constructor.
        */
        void ConstructL();

        /**
        * Destructor.
        */
        ~CGraphDrawView3();

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
        CGraphDrawContainer3* iContainer;

		/*! @var iDocument The current document */
		CGraphDrawDocument* iDocument;
    };

#endif

// End of File
