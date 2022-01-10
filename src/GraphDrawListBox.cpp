/*
* ============================================================================
*  Name     : GraphDrawListBox from GraphDrawListBox.h
*  Part of  : GraphDraw
*  Created  : 3/7/2003 by Makidis Michael
*  Copyright: Makidis Michael 2003-2004
* ============================================================================
*/

// INCLUDE FILES
#include "GraphDrawListbox.h"
#include "GraphDrawView.h"
#include "GraphDrawView2.h"
#include "GraphDraw.hrh"


// ================= MEMBER FUNCTIONS =========================================

// ----------------------------------------------------------------------------
// CGraphDrawListbox::CreateSettingItemL
// Updates descripter array for list box
// ----------------------------------------------------------------------------
//
CAknSettingItem* CGraphDrawListbox::CreateSettingItemL( TInt aSettingId )
    {
    CAknSettingItem* settingItem = NULL;

	switch(aSettingId)
	{
	case 1:
		settingItem = new (ELeave) CAknTextSettingItem( 1, iFuncF );
		break;
	case 2:
		settingItem = new (ELeave) CAknTextSettingItem( 2, iFuncG );
		break;
	case 3:
		settingItem = new (ELeave) CAknTextSettingItem( 3, iFuncH );
		break;
	case 4:
		settingItem = new (ELeave) CAknTextSettingItem( 4, iFuncT );
		break;
	case 5:
		settingItem = new (ELeave) CAknTextSettingItem( 5, iZoom );
		break;
	case 6:
		settingItem = new (ELeave) CAknTextSettingItem( 6, iX );
		break;
	case 7:
		settingItem = new (ELeave) CAknTextSettingItem( 7, iY );
		break;
	default:
		break;
	}

    return settingItem;
    }

// ----------------------------------------------------------------------------
// TKeyResponse CGraphDrawListbox::OfferKeyEventL( const TKeyEvent&,
//  TEventCode )
// Handles the key events.
// ----------------------------------------------------------------------------
//
TKeyResponse CGraphDrawListbox::OfferKeyEventL(
    const TKeyEvent& aKeyEvent,
    TEventCode aType )
    {
    if ( aType != EEventKey ) // Is not key event?
        {
        return EKeyWasNotConsumed;
        }

    switch ( aKeyEvent.iCode ) // The code of key event is...
        {
		case EKeyRightArrow:
			return EKeyWasNotConsumed;
            break;
        case EKeyLeftArrow:
			return EKeyWasNotConsumed;
            break;
        default:
            CAknSettingItemList::OfferKeyEventL(aKeyEvent, aType);
            break;
        }
    return EKeyWasConsumed;
    }

// ----------------------------------------------------------------------------
// CGraphDrawListbox::SizeChanged
// Size changed handler
// ----------------------------------------------------------------------------
//
void CGraphDrawListbox::SizeChanged()
    {
    if (ListBox()) 
        {
        ListBox()->SetRect(Rect());
        }
    }

// End of File
