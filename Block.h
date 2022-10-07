#pragma once
#include "Cell.h"  //has CellType
#include "Block.h" //has BLOCK_SIZE
#include <iostream>
using namespace std;

const int BLOCK_SIZE=9;

class Block
{
private:
	Cell gBlock[BLOCK_SIZE];
public:
	Block(void);
	~Block(void);

	bool bGetBlockString(string sBlockString);
	bool bValidBlock();
	bool bIsSolvedBlock();
	char cPrintBlockValue(int eBlkValue);
    bool convertToCellType(string sBlockString);
    
	void SetCell(int iPos, Cell c) { gBlock[iPos] = c;}
	Cell GetCell(int iPos) { return gBlock[iPos]; }

	
};

