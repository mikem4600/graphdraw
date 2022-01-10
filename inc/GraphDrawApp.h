/*
* ============================================================================
*  Name     : CGraphDrawApp from GraphDrawApp.h
*  Part of  : GraphDraw
*  Created  : 3/7/2003 by Makidis Michael
*  Description:
*     Declares main application class.
*  Copyright: Makidis Michael 2003-2004
* ============================================================================
*/

#ifndef GRAPHDRAWAPP_H
#define GRAPHDRAWAPP_H

// INCLUDES
#include <aknapp.h>

// CONSTANTS
// UID of the application
const TUid KUidGraphDraw = { 0x04CF613A }; // please request a UID from Symbian

// CLASS DECLARATION

/**
* CGraphDrawApp application class.
* Provides factory to create concrete document object.
* 
*/
class CGraphDrawApp : public CAknApplication
    {
    
    public: // Functions from base classes
    private:

        /**
        * From CApaApplication, creates CGraphDrawDocument document object.
        * @return A pointer to the created document object.
        */
        CApaDocument* CreateDocumentL();
        
        /**
        * From CApaApplication, returns application's UID (KUidGraphDraw).
        * @return The value of KUidGraphDraw.
        */
        TUid AppDllUid() const;
    };

#endif

// End of File

