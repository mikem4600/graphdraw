/*
* ============================================================================
*  Name     : CGraphDrawView2 from GraphDrawView2.h
*  Part of  : GraphDraw
*  Created  : 3/7/2003 by Makidis Michael
*  Description:
*     Declares view for application.
*  Copyright: Makidis Michael 2003-2004
* ============================================================================
*/

#ifndef GRAPHDRAWVIEW2_H
#define GRAPHDRAWVIEW2_H

// INCLUDES
#include "graphdraw.hrh"
#include <aknview.h>

// CONSTANTS
// UID of view
const TUid KView2Id = {2};

// FORWARD DECLARATIONS
class CGraphDrawContainer2;
class CGraphDrawDocument;
class CGraphDrawListbox;


// CLASS DECLARATION

/**
*  CGraphDrawView2 view class.
* 
*/
class CGraphDrawView2 : public CAknView
    {
    public: // Constructors and destructor

	    CGraphDrawView2(CGraphDrawDocument* aDocument);

        /**
        * EPOC default constructor.
        */
        void ConstructL();

        /**
        * Destructor.
        */
        ~CGraphDrawView2();

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

		void CreateListBoxL(TInt aResourceId);

	protected:
	    TBool parseInt(TInt& anInt, TBuf<8>& aBuf);
		void DisplayMessageL(TBuf<ERRORMESSAGEMAXLENGTH>& message);

	public:
		void ValidateDataL(TBool& funcError, TBuf<ERRORMESSAGEMAXLENGTH>& errorMessage);
		TBool iValidate;

    private: // Data
        CGraphDrawContainer2* iContainer;

		/*! @var iDocument The current document */
		CGraphDrawDocument* iDocument;

		CGraphDrawListbox* iListBox;
		
    };

#endif

// End of File
