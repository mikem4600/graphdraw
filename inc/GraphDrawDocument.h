/*
* ============================================================================
*  Name     : CGraphDrawDocument from GraphDrawDocument.h
*  Part of  : GraphDraw
*  Created  : 3/7/2003 by Makidis Michael
*  Description:
*     Declares document for application.
*  Copyright: Makidis Michael 2003-2004
* ============================================================================
*/

#ifndef GRAPHDRAWDOCUMENT_H
#define GRAPHDRAWDOCUMENT_H

// INCLUDES
#include "GraphDrawList.h"
#include "GraphDraw.hrh"
#include <akndoc.h>
#include <e32math.h>   // for math support
   
// CONSTANTS

// FORWARD DECLARATIONS
class  CEikAppUi;

// CLASS DECLARATION

/**
*  CGraphDrawDocument application class.
*/
class CGraphDrawDocument : public CAknDocument
    {
    public: // Constructors and destructor
        /**
        * Two-phased constructor.
        */
        static CGraphDrawDocument* NewL(CEikApplication& aApp);

        /**
        * Destructor.
        */
        virtual ~CGraphDrawDocument();

    public: // New functions
	    TInt GetYL(TReal aX, TInt& aY, TUint aFuncId);
		TBool SetFunctionL(TBuf<EDWINMAXLENGTH>& aBuf, TUint aFuncId);
		TBuf<EDWINMAXLENGTH> Function(TUint aFuncId)
			{return iFunction[aFuncId];}
		void ClearFunction(TUint aFuncId);

		TBool IsNumber(TChar aChar);
		TInt toInt(TChar aChar);

    protected:  // New functions
		TBool IsFunction(TChar aChar);
		TInt Priority(TChar aChar);
		TBool IsOperator(TChar aChar);

    protected:  // Functions from base classes

    private:

        /**
        * EPOC default constructor.
        */
        CGraphDrawDocument(CEikApplication& aApp);
		const TReal iPi;
		const TReal iE;
        void ConstructL();

    private:

        /**
        * From CEikDocument, create CGraphDrawAppUi "App UI" object.
        */
        CEikAppUi* CreateAppUiL();

	protected:
		TBuf<EDWINMAXLENGTH> iFunction[FUNCTIONS];
		CStack* iEpith[FUNCTIONS];

	public:		
		TPoint iCenter;
		TUint iZoom;
		TBool iCenterSet;
    };

#endif

// End of File

