
#include "Block.h" //has BLOCK_SIZE
#include <iostream>

using namespace std;

Block::Block(void)
{
}

Block::~Block(void)
{
}

bool
Block::bGetBlockString(string sBlockString)
{	
	cout << "Enter 9 characters:\n";
	cin >> sBlockString; 
	if (sBlockString[0]=='q') 
		return true;
	else
		// Fill in the values into the Block private variables...
	{
		convertToCellType(sBlockString);
	}
	return false;
}

bool Block::bValidBlock() 
{
	bool bIsUsed[BLOCK_SIZE] = {false, false, false, false, false, false, false, false, false};
	for (int iCharNo=0; iCharNo<BLOCK_SIZE; iCharNo++)
	{
		switch (gBlock[iCharNo].cGetValue())
		{
		case Blank:  break;
		case One: 
			if (bIsUsed[One]) return false;
			bIsUsed[One] = true;
			break;
		case Two: 
			if (bIsUsed[Two]) return false;
			bIsUsed[Two] = true;
			break;
		case Three: 
			if (bIsUsed[Three]) return false;
			bIsUsed[Three] = true;
			break;
		case Four: 
			if (bIsUsed[Four]) return false;
			bIsUsed[Four] = true;
			break;
		case Five: 
			if (bIsUsed[Five]) return false;
			bIsUsed[Five] = true;
			break;
		case Six: 
			if (bIsUsed[Six]) return false;
			bIsUsed[Six] = true;
			break;
		case Seven: 
			if (bIsUsed[Seven]) return false;
			bIsUsed[Seven] = true;
			break;
		case Eight: 
			if (bIsUsed[Eight]) return false;
			bIsUsed[Eight] = true;
			break;
		case Nine: 
			if (bIsUsed[Nine]) return false;
			bIsUsed[Nine] = true;
			break;
		default:
			return false;
			break;
		}
	}
	return true;
}

bool 
Block::bIsSolvedBlock()
{
	bool bIsUsed[BLOCK_SIZE] = {false, false, false, false, false, false, false, false, false};
	for (int iCharNo=0; iCharNo<BLOCK_SIZE; iCharNo++)
	{
		switch (gBlock[iCharNo].cGetValue())
		{
		case One: 
			if (bIsUsed[One]) return false;
			bIsUsed[One] = true;
			break;
		case Two: 
			if (bIsUsed[Two]) return false;
			bIsUsed[Two] = true;
			break;
		case Three: 
			if (bIsUsed[Three]) return false;
			bIsUsed[Three] = true;
			break;
		case Four: 
			if (bIsUsed[Four]) return false;
			bIsUsed[Four] = true;
			break;
		case Five: 
			if (bIsUsed[Five]) return false;
			bIsUsed[Five] = true;
			break;
		case Six: 
			if (bIsUsed[Six]) return false;
			bIsUsed[Six] = true;
			break;
		case Seven: 
			if (bIsUsed[Seven]) return false;
			bIsUsed[Seven] = true;
			break;
		case Eight: 
			if (bIsUsed[Eight]) return false;
			bIsUsed[Eight] = true;
			break;
		case Nine: 
			if (bIsUsed[Nine]) return false;
			bIsUsed[Nine] = true;
			break;
		default:
			return false;
			break;
		}
	}
	return true;
}

bool Block::convertToCellType(string sBlockString) //, Cell *gTestBlock[])//Puts numbers into cells of Block.
																
{
	for (int iCharNo = 0; iCharNo< BLOCK_SIZE; iCharNo++)
	{
		bool worked = gBlock[iCharNo].convertToCellType(sBlockString[iCharNo]); 
		if(!worked) return false;
	}
	return true;
}
char
Block::cPrintBlockValue(int iPos)
{
	return gBlock[iPos].cPrintBlockValue();

}

