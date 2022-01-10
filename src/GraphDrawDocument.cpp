/*
* ============================================================================
*  Name     : CGraphDrawDocument from GraphDrawDocument.h
*  Part of  : GraphDraw
*  Created  : 3/7/2003 by Makidis Michael
*  Implementation notes:
*     Initial content was generated by Series 60 AppWizard.
*  Copyright: Makidis Michael 2003-2004
* ============================================================================
*/

// INCLUDE FILES
#include "GraphDrawDocument.h"
#include "GraphDrawAppUi.h"

// ================= MEMBER FUNCTIONS =======================

// constructor
CGraphDrawDocument::CGraphDrawDocument(CEikApplication& aApp)
: CAknDocument(aApp),
// initialise the math constants pi & e
iPi(3.1415926535897932384626433832795),
iE(2.7182818284590452353602874713527)
    {
	iCenter.SetXY(0,0);
	for(TInt i = 0; i < FUNCTIONS; i++)
	{
		iEpith[i] = 0;
	}
	iZoom = 1000;
	iCenterSet = EFalse;
    }

// destructor
CGraphDrawDocument::~CGraphDrawDocument()
    {
	for(TInt i = 0; i < FUNCTIONS; i++)
	{
		delete iEpith[i];
	}
    }

// EPOC default constructor can leave.
void CGraphDrawDocument::ConstructL()
    {
		for(TInt i = 0; i < FUNCTIONS; i++)
		{
			iFunction[i] = _L("");
		}
    }

// Two-phased constructor.
CGraphDrawDocument* CGraphDrawDocument::NewL(
        CEikApplication& aApp)     // CGraphDrawApp reference
    {
    CGraphDrawDocument* self = new (ELeave) CGraphDrawDocument( aApp );
    CleanupStack::PushL( self );
    self->ConstructL();
    CleanupStack::Pop();

    return self;
    }
    
// ----------------------------------------------------
// CGraphDrawDocument::CreateAppUiL()
// constructs CGraphDrawAppUi
// ----------------------------------------------------
//
CEikAppUi* CGraphDrawDocument::CreateAppUiL()
    {
    return new (ELeave) CGraphDrawAppUi(this);
    }

// Compute and return the Y based on the "current"
// function and the input X
TInt CGraphDrawDocument::GetYL(TReal aX, TInt& aY, TUint aFuncId)
{
	// initial error-checking
	if(aFuncId >= FUNCTIONS) return 1;
	if (iFunction[aFuncId].Length() == 0) return 1;

	// prepare the variables
	CStack* vars = new(ELeave) CStack();
	TReal A, B, res;
	TReal zoomFactor = iZoom/1000.0;
    TNode *node, *node2;
    iEpith[aFuncId]->iStackIter.SetToFirst();

	// start reading node by node
    while ((node = iEpith[aFuncId]->iStackIter++) != NULL)
	{
		if(node->isChar)    // we have a char (function, constant...)
		// calculate its value and store it appropriately
		{
			if(node->iTheChar == 'x' || node->iTheChar == 'X'
				|| node->iTheChar == 'e' || node->iTheChar == 'p')
			{
				node2 = new(ELeave) TNode();
				switch(node->iTheChar)
				{
				case 'x':
				case 'X':
					node2->iNumber = aX;
					break;
				case 'e':
					node2->iNumber = iE;
					break;
				case 'p':
					node2->iNumber = iPi;
					break;
				}
				vars->AddToStack(*node2);
			} // node is x
			if(IsOperator(node->iTheChar))
			{
				node2 = vars->RemoveFromStack();
				B = node2->iNumber;
				delete node2;
				node2 = vars->RemoveFromStack();
				A = node2->iNumber;

				switch(node->iTheChar)
				{
				case '+':
					res = A + B;
					break;
				case '-':
					res = A - B;
					break;
				case '*':
					res = A * B;
					break;
				case '/':
					if(B == 0)
					{
						delete node2;
						delete vars;
						return 1;
					}
					else res = A / B;
					break;
				case '^':
					if(Math::Pow(res, A, B) != KErrNone)
					{
						delete node2;
						delete vars;
						return 1;
					}
					break;
				default:
					res = 0;
				} // switch
				node2->iNumber = res;
				vars->AddToStack(*node2);
			} // is operator
			if(IsFunction(node->iTheChar))
			{
				node2 = vars->RemoveFromStack();
				A = node2->iNumber;

				switch(node->iTheChar)
				{
				case 's':
					if(Math::Sin(res, A) != KErrNone)
					{
						delete node2;
						delete vars;
						return 1;
					}
					break;
				case 'c':
					if(Math::Cos(res, A) != KErrNone)
					{
						delete node2;
						delete vars;
						return 1;
					}
					break;
				case 't':
					if(Math::Tan(res, A) != KErrNone)
					{
						delete node2;
						delete vars;
						return 1;
					}
					break;
				case 'a':
					if(Math::ASin(res, A) != KErrNone)
					{
						delete node2;
						delete vars;
						return 1;
					}
					break;
				case 'b':
					if(Math::ACos(res, A) != KErrNone)
					{
						delete node2;
						delete vars;
						return 1;
					}
					break;
				case 'd':
					if(Math::ATan(res, A) != KErrNone)
					{
						delete node2;
						delete vars;
						return 1;
					}
					break;
				case 'o':
					if(Math::Exp(res, A) != KErrNone)
					{
						delete node2;
						delete vars;
						return 1;
					}
					break;
				case 'l':
					if(Math::Log(res, A) != KErrNone)
					{
						delete node2;
						delete vars;
						return 1;
					}
					break;
				case 'n':
					if(Math::Ln(res, A) != KErrNone)
					{
						delete node2;
						delete vars;
						return 1;
					}
					break;
				case 'q':
					if(Math::Sqrt(res, A) != KErrNone)
					{
						delete node2;
						delete vars;
						return 1;
					}
					break;
				default:
					res = 0;
				} // switch
			node2->iNumber = res;
			vars->AddToStack(*node2);
			} // is function
		} // is char
		else // we have a number - add it to the stack
		{
			node2 = new(ELeave) TNode(*node);
			vars->AddToStack(*node2);
		}
	} // while

	if(vars->iStack.IsEmpty())
	{
		delete vars;
		return 1;
	}

	// calculate the zoom
	aY = (TInt)(vars->iStack.Last()->iNumber*zoomFactor + 0.5);
	delete vars;

	// there was no error - the point exists
	return 0;
}

// Validate and parse the input function ("epithematiki parastasi...").
// Parts based on book "Domes Dedomenwn me C++", Th. Kalaboukis,
// published by Athens University of Economics and Business, 2001.
TBool CGraphDrawDocument::SetFunctionL(TBuf<EDWINMAXLENGTH>& aBuf, TUint aFuncId)
{
	// initial error-checking
	if(aFuncId >= FUNCTIONS) return EFalse;
	if(iFunction[aFuncId] == aBuf) return ETrue;

	// prepare the variables
	TChar theChar(' '); TChar prevChar(' '); // current & previous chars
	CStack* ep = new(ELeave) CStack(); // result stack
	CStack* ops = new(ELeave) CStack(); // operators stack
	CStack* funcs = new(ELeave) CStack(); // functions stack
	TNode* node;

	TReal Denom = 0;  // tens after comma
	TBool DecActive = EFalse; // flag whether we've reached a comma

	TChar Par1( '(' );
	TChar Par1X( '[' );
	TChar Par2( ')' );
	TInt i; // chars counter

	// ******************
	// Parentheseis... (check for parenthesis' validity)
	// ******************
	for(i = 0; i < aBuf.Length(); i++)
	{
		theChar = aBuf[i];
		if(theChar == Par1)
		{
			// add to stack
			node = new(ELeave) TNode;
			node->isChar = ETrue;
			node->iTheChar = theChar;
			ep->AddToStack(*node);
		}
		if(theChar == Par2)
		{
			if(ep->iStack.Last()->iTheChar == Par1)
			{
				// remove from stack
				node = ep->RemoveFromStack();
				delete node; node = 0;
			}
			else
			{
				// checking failed
				delete ep;
				delete ops;
				delete funcs;
				return EFalse;
			}
		}
	}

	ep->iStackIter.SetToFirst();
	if( ep->iStackIter++ != NULL )
	{
			delete ep;
			delete ops;
			delete funcs;
			return EFalse;
	}

	delete ep;
	ep = new(ELeave) CStack();

	// ***************************
	// Epithematiki parastasi... 
	// ("reverse polish notation")
	// ***************************
	for(i = 0; i < aBuf.Length(); i++)
	{
		if(i != 0)
		prevChar = theChar;
		theChar = aBuf[i];
		// is number
		if(IsNumber(theChar))
		{
			// PREV CHECK (= check the prev char)
			if(
				prevChar == Par2 || 
				IsFunction(prevChar) ||
				IsFunction(prevChar)
				)
			{
					delete ep;
					delete ops;
					delete funcs;
					return EFalse;
			}

			// Arithmos gia prwti fora
			// (the previous char was not a number)
			if(
				!IsNumber(prevChar) &&
				theChar != 'x' &&
				theChar != 'X' &&
				theChar != 'e' &&
				theChar != 'p')
			{
				// PREV CHECK
				if(
					prevChar == 'x' || 
					prevChar == 'X' ||
					prevChar == 'p' ||
					prevChar == 'e' ||
					theChar == '.'
					)
				{
						delete ep;
						delete ops;
						delete funcs;
						return EFalse;
				}
				// push to the stack
				node = new(ELeave) TNode;
				node->isChar = EFalse;
				node->iNumber = toInt(theChar);
				ep->AddToStack(*node);
			}
			else 
			{
				// Metabliti/it's a variable
				if(theChar == 'x' || theChar == 'X' ||
					theChar == 'e' || theChar == 'p')
				{
					// PREV CHECK
					if(
						IsNumber(prevChar) &&
						prevChar != 'x' && 
						prevChar != 'X' &&
						prevChar != 'p' &&
						prevChar != 'e'
						)
					{
							delete ep;
							delete ops;
							delete funcs;
							return EFalse;
					}
					// push to the stack
					node = new(ELeave) TNode;
					node->isChar = ETrue;
					node->iTheChar = theChar;
					ep->AddToStack(*node);
				}
				// Arithmos gia deyteri fora (another number)
				else
				{
					// PREV CHECK
					if(
						prevChar == 'x' || 
						prevChar == 'X' ||
						prevChar == 'p' ||
						prevChar == 'e'
						)
					{
							delete ep;
							delete ops;
							delete funcs;
							return EFalse;
					}

					// Ypodiastoli (comma)
					if(theChar == '.')
					{
						// PREV CHECK
						if(DecActive)
						{
								delete ep;
								delete ops;
								delete funcs;
								return EFalse;
						}
						// activate "after-comma mode"
						DecActive = ETrue;
						Denom = 10;
					}
					else
					{
						// append to the existing last node
						node = ep->iStack.Last();
						// Akeraio meros
						if(!DecActive)
						{
							node->iNumber = node->iNumber*10 + toInt(theChar);
						}
						// Dekadiko meros
						else
						{
							node->iNumber = node->iNumber + toInt(theChar)/Denom;
							Denom*=10;
						}
					}
				}
			}
		} // is number
		else // is not number
		{
			DecActive = EFalse;  // deactivate "after-comma mode"
			// is (
			if(theChar == Par1)
			{
				// PREV CHECK
				if(
					i == aBuf.Length() -1 ||
					IsNumber(prevChar) ||
					prevChar == Par2)
				{
					delete ep;
					delete ops;
					delete funcs;
					return EFalse;
				}

				// add to the stack
				// (check if it's part of a function,
				// or to just declare priority)
				node = new(ELeave) TNode;
				node->isChar = ETrue;
				if(IsFunction(prevChar))
					node->iTheChar = Par1X;
				else
					node->iTheChar = theChar;
				ops->AddToStack(*node);
				
			} // is (
			// is )
			else if(theChar == Par2)
			{
				// PREV CHECK
				if(
					i == 0 ||
					IsFunction(prevChar)||
					IsOperator(prevChar) ||
					prevChar == Par1
					)
				{
					delete ep;
					delete ops;
					delete funcs;
					return EFalse;
				}

				// find the accompanying (
				// push all the other elements to the
				// result stack
				while(ops->iStack.Last()->iTheChar != Par1 && 
					  ops->iStack.Last()->iTheChar != Par1X)
				{
					node = ops->RemoveFromStack();
					ep->AddToStack(*node);
				}

				// it wasn't part of a function
				if(ops->iStack.Last()->iTheChar == Par1)
				{
					node = ops->RemoveFromStack();
					delete node; node = 0;
				}
				// it was part of a function
				if(ops->iStack.Last()->iTheChar == Par1X) 
				{
					node = ops->RemoveFromStack();
					delete node;
					node = funcs->RemoveFromStack();
					ep->AddToStack(*node);
				}
			} // is )
			// is operator
			else if(IsOperator(theChar))
			{
				// PREV CHECK
				if( 
					i == aBuf.Length() -1 ||
					IsOperator(prevChar) || 
					(i == 0 && theChar != '+' && theChar != '-') ||
					(prevChar == Par1 && theChar != '+' && theChar != '-') || 
					IsFunction(prevChar) 
					)
				{
					delete ep;
					delete ops;
					delete funcs;
					return EFalse;
				}
				if(i == 0 || prevChar == Par1)
				{
					node = new(ELeave) TNode;
					node->isChar = EFalse;
					node->iNumber = 0;
					ep->AddToStack(*node);
				}
				ops->iStackIter.SetToFirst();
				if(ops->iStackIter++ != NULL)
				{
					// move the higher priority ops to the result stack
					while( Priority(theChar) <= Priority(ops->iStack.Last()->iTheChar) )
					{
						node = ops->RemoveFromStack();
						ep->AddToStack(*node);
					}
				}
				// add the operator to the stack
				node = new(ELeave) TNode;
				node->isChar = ETrue;
				node->iTheChar = theChar;
				ops->AddToStack(*node);
			} // is operator
			// is function
			else if(IsFunction(theChar))
			{
				// PREV CHECK
				if(
					i == aBuf.Length() -1 ||
					IsFunction(prevChar) ||
					IsNumber(prevChar) ||
					prevChar == Par2
					) 
				{
					delete ep;
					delete ops;
					delete funcs;
					return EFalse;
				}
				// add it to the stack
				node = new(ELeave) TNode;
				node->isChar = ETrue;
				node->iTheChar = theChar;
				funcs->AddToStack(*node);
			} // is function
			// is something else ??
			else
			{
					delete ep;
					delete ops;
					delete funcs;
					return EFalse;
			}
		}

	}


	// there was no error - save, cleanup & return

	while(!ops->iStack.IsEmpty())
	{
		node = ops->RemoveFromStack();
		ep->AddToStack(*node);
	}

	delete iEpith[aFuncId];
	iEpith[aFuncId] = ep;
	iFunction[aFuncId] = aBuf;

	delete ops;
	delete funcs;
	return ETrue;
}

TBool CGraphDrawDocument::IsOperator(TChar aChar)
{
	TChar OpPlus( '+' );
	TChar OpMinus( '-' );
	TChar OpMult( '*' );
	TChar OpDiv( '/' );
	TChar OpPow( '^' );

	return (aChar == OpPlus || aChar == OpMinus ||
		    aChar == OpMult || aChar == OpDiv ||
			aChar == OpPow);
}

TBool CGraphDrawDocument::IsFunction(TChar aChar)
{
	TChar FunSin( 's' );
	TChar FunCos( 'c' );
	TChar FunTan( 't' );

	TChar FunASin( 'a' );
	TChar FunACos( 'b' );
	TChar FunATan( 'd' );

	TChar FunExp( 'o' ); // e^x
	TChar FunLog( 'l' );
	TChar FunLn( 'n' );
	TChar FunSqrt( 'q' );

	return (aChar == FunSin ||
			aChar == FunCos ||
			aChar == FunTan ||
			aChar == FunASin ||
			aChar == FunACos ||
			aChar == FunATan ||
			aChar == FunExp ||
			aChar == FunLog ||
			aChar == FunLn ||
			aChar == FunSqrt);

}

// Get the relative operator priority
TInt CGraphDrawDocument::Priority(TChar aChar)
{
	TChar OpPlus( '+' );
	TChar OpMinus( '-' );
	TChar OpMult( '*' );
	TChar OpDiv( '/' );
	TChar OpPow( '^' );
	
	if(aChar == OpPlus || aChar == OpMinus) return 1;
	if(aChar == OpMult || aChar == OpDiv) return 2;
	if(aChar == OpPow) return 3;
	return 0;
}

TBool CGraphDrawDocument::IsNumber(TChar aChar)
{
	TChar One( '1' );
	TChar Two( '2' );
	TChar Three( '3' );
	TChar Four( '4' );
	TChar Five( '5' );
	TChar Six( '6' );
	TChar Seven( '7' );
	TChar Eight( '8' );
	TChar Nine( '9' );
	TChar Zero( '0' );
	TChar x( 'x' );
	TChar X( 'X' );
	TChar chPi( 'p' );
	TChar chE( 'e' );
	TChar chDec( '.' );

	return (aChar == One ||
		    aChar == Two ||
			aChar == Three ||
			aChar == Four ||
			aChar == Five ||
			aChar == Six ||
			aChar == Seven ||
			aChar == Eight ||
			aChar == Nine ||
			aChar == Zero ||
			aChar == x ||
			aChar == chPi ||
			aChar == chE ||
			aChar == chDec ||
			aChar == X);

}

// Convert from TChar to TInt
TInt CGraphDrawDocument::toInt(TChar aChar)
{
	switch(aChar)
	{
	case '1': return 1;
	case '2': return 2;
	case '3': return 3;
	case '4': return 4;
	case '5': return 5;
	case '6': return 6;
	case '7': return 7;
	case '8': return 8;
	case '9': return 9;
	case '0': return 0;
	default: return -1;
	}
}

// Delete/clear a function
void CGraphDrawDocument::ClearFunction(TUint aFuncId)
{
	_LIT(KText,"");
	iFunction[aFuncId] = KText;
	delete iEpith[aFuncId];
	iEpith[aFuncId] = 0;
}

// End of File 