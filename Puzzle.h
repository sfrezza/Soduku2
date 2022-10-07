#pragma once
#include "Cell.h"  //has CellType
#include "Block.h" //has BLOCK_SIZE
#include <iostream>
using namespace std;

class Puzzle
{
private:
	Block _blkBlockOrientedPuzzle[BLOCK_SIZE];
    
public:
	Puzzle(void);
    Puzzle(const string FileName);
	~Puzzle(void);

	void gPrintGrid();
	bool bInputGrid();
    bool bInputGrid(const string FileName);
	bool bIsSolution();

};

