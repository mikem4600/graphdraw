/*
* ============================================================================
*  Name     : GraphDrawListBox from GraphDrawListBox.h
*  Part of  : GraphDraw
*  Created  : 3/7/2003 by Makidis Michael
*  Description:
*     Declares listbox for application.
*  Copyright: Makidis Michael 2003-2004
* ============================================================================
*/

#ifndef GRAPHDRAWLISTBOX_H
#define GRAPHDRAWLISTBOX_H

// INCLUDES
#include "GraphDraw.hrh"
#include <AknSettingItemList.h>

// FORWARD DECLARATIONS
class CGraphDrawView2;

// CLASS DECLARATION

/**
* CGraphDrawContainer  container control class.
*/
class CGraphDrawListbox : public CAknSettingItemList 
    {
    public:
        CAknSettingItem* CreateSettingItemL( TInt aSettingId );

		TBuf<EDWINMAXLENGTH> iFuncF;
		TBuf<EDWINMAXLENGTH> iFuncG;
		TBuf<EDWINMAXLENGTH> iFuncH;
		TBuf<EDWINMAXLENGTH> iFuncT;
		TBuf<8> iZoom;
		TBuf<8> iX;
		TBuf<8> iY;
        
    private:
        TKeyResponse OfferKeyEventL(
            const TKeyEvent& aKeyEvent, TEventCode aType );
        void SizeChanged();

    };


#endif

// End of File
