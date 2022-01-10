/*
* ============================================================================
*  Name     : GraphDrawList from GraphDrawList.h
*  Part of  : GraphDraw
*  Created  : 3/7/2003 by Makidis Michael
*  Description:
*     A stack of TNodes, implemented on top of a linked list.
*  Copyright: Makidis Michael 2003-2004
* ============================================================================
*/

// INCLUDE FILES

#include "GraphDrawList.h"


CStack* CStack::NewLC()
    {
    CStack* self = CStack::NewL();
    CleanupStack::PushL(self);
    return self;
    }

CStack* CStack::NewL()
    {
    CStack* self = new (ELeave) CStack;
    return self;
    }

// constructor
CStack::CStack()
    : iStack(_FOFF(TNode,iLink)),iStackIter(iStack) 
    {}

// destructor
CStack::~CStack()
    {
    TNode* item;
    iStackIter.SetToFirst(); 
    while ((item = iStackIter++) != NULL)
        {
        iStack.Remove(*item);
        delete item;
        };
    }

// add an item at the top of the stack
void CStack::AddToStack(TNode& anItem)
    {
    iStack.AddLast(anItem);
    }

// remove the item at the top of the stack
TNode* CStack::RemoveFromStack()
    {
    TNode* lastitem;
    if (iStack.IsEmpty())
        return NULL;
    lastitem = iStack.Last();
    iStack.Remove(*lastitem); 
    return (lastitem);
    }


// End of File

