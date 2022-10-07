
#include "Cell.h"
using namespace std;

Cell::Cell(void)
{
	_MyCell = Blank;
}


Cell::~Cell(void)
{
}

bool
Cell::convertToCellType(char c)
{
	switch (c)
	{
		case '_':  
			_MyCell = Blank;
			break;
		case '1': 
			_MyCell = One;
			break;
		case '2': 
			_MyCell = Two;
			break;
		case '3': 
			_MyCell = Three;
			break;
		case '4': 
			_MyCell = Four;
			break;
		case '5': 
			_MyCell = Five;
			break;
		case '6': 
			_MyCell = Six;
			break;
		case '7': 
			_MyCell = Seven;
			break;
		case '8': 
			_MyCell = Eight;
			break;
		case '9': 
			_MyCell = Nine;
			break;
		default:
			return false;
			break;
		}
	return true;
}

char
Cell::cPrintBlockValue()
{
	switch(_MyCell)
	{
	case One:
		return '1';
		break;
	case Two:
		return '2';
		break;
	case Three:
		return '3';
		break;
	case Four:
		return '4';
		break;
	case Five:
		return '5';
		break;
	case Six:
		return '6';
		break;
	case Seven:
		return '7';
		break;
	case Eight:
		return '8';
		break;
	case Nine:
		return '9';
		break;
	default:
		return ' ';
		break;
	}
	return ' ';
}
