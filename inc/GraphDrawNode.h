/*
* ============================================================================
*  Name     : CGraphDrawNode from GraphDrawNode.h
*  Part of  : GraphDraw
*  Created  : 3/7/2003 by Makidis Michael
*  Description:
*     The nodes of the stack/list.
*  Copyright: Makidis Michael 2003-2004
* ============================================================================
*/

#ifndef GRAPHDRAWNODE_H
#define GRAPHDRAWNODE_H

// INCLUDES
#include <e32std.h>

// CONSTANTS

// FORWARD DECLARATIONS

// CLASS DECLARATION

/**
*  TGraphDrawNode class.
* 
*/
class TNode
    {
    public: // Constructors and destructor
		TNode()
		:iNumber(0), isChar(EFalse), iTheChar(' ')
		{}

    //public: // Functions from base classes        

    public:
		TReal iNumber;
		TBool isChar;
		TChar iTheChar;
		TSglQueLink iLink;

    //private: // Data
    };

#endif

// End of File
