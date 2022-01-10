/*
* ============================================================================
*  Name     : CGraphDrawList from GraphDrawList.h
*  Part of  : GraphDraw
*  Created  : 3/7/2003 by Makidis Michael
*  Description:
*     A stack of TNodes, implemented on top of a linked list.
*  Copyright: Makidis Michael 2003-2004
* ============================================================================
*/

#ifndef GRAPHDRAWLIST_H
#define GRAPHDRAWLIST_H


// INCLUDES
#include "GraphDrawNode.h"
#include <e32base.h>

// CLASS DECLARATION

/**
*  CStack class.
* 
*/
class CStack : public CBase
    {
    public:
		static CStack* NewL();
		static CStack* NewLC();
        CStack();
		virtual ~CStack();      

		TSglQue<TNode> iStack; 
		TSglQueIter<TNode> iStackIter;

		TNode* RemoveFromStack();
		void AddToStack(TNode& anItem);
    };

#endif

// End of File
