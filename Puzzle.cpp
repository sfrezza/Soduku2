
#include "Puzzle.h"
#include "Cell.h"  //has CellType
#include "Block.h" //has BLOCK_SIZE

#include<iostream>
#include<fstream>
#include<string>
#include<math.h>

using namespace std;

Puzzle::Puzzle(void)
{
    //Initialize as a puzzle of all blanks...
}

Puzzle::Puzzle(const string FileName) : Puzzle() {
    bInputGrid(FileName);
    //Initialize a puzzle from a block-oriented text file.
}

Puzzle::~Puzzle(void)
{
}

void
gPrintThreeBlocks(Block gBlock1, Block gBlock2, Block gBlock3)
{
	const char BLOCK_VERTICAL_WALL = '|';
	
	// Prints one row at a time until the whole puzzle is printed.
	for (int index=0; index < BLOCK_SIZE; index +=3)
	{
		cout << BLOCK_VERTICAL_WALL << ' ' << gBlock1.cPrintBlockValue(index+0)
									<< ' ' << gBlock1.cPrintBlockValue(index+1) 
									<< ' ' << gBlock1.cPrintBlockValue(index+2) 
									<< ' ';
		cout << BLOCK_VERTICAL_WALL << ' ' << gBlock2.cPrintBlockValue(index+0)
									<< ' ' << gBlock2.cPrintBlockValue(index+1) 
									<< ' ' << gBlock2.cPrintBlockValue(index+2) 
									<< ' ';
		cout << BLOCK_VERTICAL_WALL << ' ' << gBlock3.cPrintBlockValue(index+0)
									<< ' ' << gBlock3.cPrintBlockValue(index+1) 
									<< ' ' << gBlock3.cPrintBlockValue(index+2) 
									<< ' ';
		cout << BLOCK_VERTICAL_WALL << endl;
	}
	return;
}

void
Puzzle::gPrintGrid()  //CellType gPuzzle[BLOCK_SIZE][BLOCK_SIZE]) 
{
	const char* ROW_HEADING = "+-------+-------+-------+";
	for (int index = 0; index < BLOCK_SIZE; index +=3)
	{
		cout << ROW_HEADING << endl;
		// Print next three blocks
		gPrintThreeBlocks(_blkBlockOrientedPuzzle[index], _blkBlockOrientedPuzzle[index+1], _blkBlockOrientedPuzzle[index+2]);
	}
	cout << ROW_HEADING;
	return;
}

bool
Puzzle::bInputGrid(const string FileName){
    //Open the (hopefully correctly formatted) textfile. Convert each character to a CellType.
    ifstream inputFile(FileName);
    
    if (!inputFile) {

    }
    else {
        string sBlockString;
        while ( getline(inputFile, sBlockString) ) {

        }
    }
    return false;   //Nothing more to read
}

bool
Puzzle::bInputGrid()  
{
	char sBlockString[BLOCK_SIZE][BLOCK_SIZE+20];
	for(int iBlockNo = 0; iBlockNo < BLOCK_SIZE; )//iBlockNo++)
	{
		// Read in the block information sequentially; verify it; 
		// continue or exit as necessary
		if (_blkBlockOrientedPuzzle[iBlockNo].bGetBlockString(sBlockString[iBlockNo]))
		{	
			cout << "You chose to quit.  Enter a character to exit. " << endl;
			return false;	
		}
		else if(_blkBlockOrientedPuzzle[iBlockNo].bValidBlock())
		{
			//convertToCellType(sBlockString[iBlockNo],gSudokuPuzzle[iBlockNo]);
			iBlockNo++;
		}
		else if(_blkBlockOrientedPuzzle[iBlockNo].bValidBlock()==false)
		{
			cout << "\tInvalid block!\n\n";
		}
	}
	return true;
}

void gCopyRowOrientedPuzzle(Block blkBlockOrientedPuzzle[BLOCK_SIZE], Block gRowOrientedPuzzle[BLOCK_SIZE])
{
	gRowOrientedPuzzle[0].SetCell(0, blkBlockOrientedPuzzle[0].GetCell(0) );
	gRowOrientedPuzzle[0].SetCell(1, blkBlockOrientedPuzzle[0].GetCell(1) );
	gRowOrientedPuzzle[0].SetCell(2, blkBlockOrientedPuzzle[0].GetCell(2) );

	gRowOrientedPuzzle[0].SetCell(3, blkBlockOrientedPuzzle[1].GetCell(0) );
	gRowOrientedPuzzle[0].SetCell(4, blkBlockOrientedPuzzle[1].GetCell(1) );
	gRowOrientedPuzzle[0].SetCell(5, blkBlockOrientedPuzzle[1].GetCell(2) );
			
	gRowOrientedPuzzle[0].SetCell(6, blkBlockOrientedPuzzle[2].GetCell(0) );
	gRowOrientedPuzzle[0].SetCell(7, blkBlockOrientedPuzzle[2].GetCell(1) );
	gRowOrientedPuzzle[0].SetCell(8, blkBlockOrientedPuzzle[2].GetCell(2) );
	
	gRowOrientedPuzzle[1].SetCell(0, blkBlockOrientedPuzzle[0].GetCell(3) );
	gRowOrientedPuzzle[1].SetCell(1, blkBlockOrientedPuzzle[0].GetCell(4) );
	gRowOrientedPuzzle[1].SetCell(2, blkBlockOrientedPuzzle[0].GetCell(5) );
	
	gRowOrientedPuzzle[1].SetCell(3, blkBlockOrientedPuzzle[1].GetCell(3) );
	gRowOrientedPuzzle[1].SetCell(4, blkBlockOrientedPuzzle[1].GetCell(4) );
	gRowOrientedPuzzle[1].SetCell(5, blkBlockOrientedPuzzle[1].GetCell(5) );

	gRowOrientedPuzzle[1].SetCell(6, blkBlockOrientedPuzzle[2].GetCell(3) );
	gRowOrientedPuzzle[1].SetCell(7, blkBlockOrientedPuzzle[2].GetCell(4) );
	gRowOrientedPuzzle[1].SetCell(8, blkBlockOrientedPuzzle[2].GetCell(5) );

	gRowOrientedPuzzle[2].SetCell(0, blkBlockOrientedPuzzle[0].GetCell(6) );
	gRowOrientedPuzzle[2].SetCell(1, blkBlockOrientedPuzzle[0].GetCell(7) );
	gRowOrientedPuzzle[2].SetCell(2, blkBlockOrientedPuzzle[0].GetCell(8) );

	gRowOrientedPuzzle[2].SetCell(3, blkBlockOrientedPuzzle[1].GetCell(6) );
	gRowOrientedPuzzle[2].SetCell(4, blkBlockOrientedPuzzle[1].GetCell(7) );
	gRowOrientedPuzzle[2].SetCell(5, blkBlockOrientedPuzzle[1].GetCell(8) );
		
	gRowOrientedPuzzle[2].SetCell(6, blkBlockOrientedPuzzle[2].GetCell(6) );
	gRowOrientedPuzzle[2].SetCell(7, blkBlockOrientedPuzzle[2].GetCell(7) );
	gRowOrientedPuzzle[2].SetCell(8, blkBlockOrientedPuzzle[2].GetCell(8) );

	gRowOrientedPuzzle[3].SetCell(0, blkBlockOrientedPuzzle[3].GetCell(0) );
	gRowOrientedPuzzle[3].SetCell(1, blkBlockOrientedPuzzle[3].GetCell(1) );
	gRowOrientedPuzzle[3].SetCell(2, blkBlockOrientedPuzzle[3].GetCell(2) );

	gRowOrientedPuzzle[3].SetCell(3, blkBlockOrientedPuzzle[4].GetCell(0) );
	gRowOrientedPuzzle[3].SetCell(4, blkBlockOrientedPuzzle[4].GetCell(1) );
	gRowOrientedPuzzle[3].SetCell(5, blkBlockOrientedPuzzle[4].GetCell(2) );
		
	gRowOrientedPuzzle[3].SetCell(6, blkBlockOrientedPuzzle[5].GetCell(0) );
	gRowOrientedPuzzle[3].SetCell(7, blkBlockOrientedPuzzle[5].GetCell(1) );
	gRowOrientedPuzzle[3].SetCell(8, blkBlockOrientedPuzzle[5].GetCell(2) );
			
	gRowOrientedPuzzle[4].SetCell(0, blkBlockOrientedPuzzle[3].GetCell(3) );
	gRowOrientedPuzzle[4].SetCell(1, blkBlockOrientedPuzzle[3].GetCell(4) );
	gRowOrientedPuzzle[4].SetCell(2, blkBlockOrientedPuzzle[3].GetCell(5) );

	gRowOrientedPuzzle[4].SetCell(3, blkBlockOrientedPuzzle[4].GetCell(3) );
	gRowOrientedPuzzle[4].SetCell(4, blkBlockOrientedPuzzle[4].GetCell(4) );
	gRowOrientedPuzzle[4].SetCell(5, blkBlockOrientedPuzzle[4].GetCell(5) );
	
	gRowOrientedPuzzle[4].SetCell(6, blkBlockOrientedPuzzle[5].GetCell(3) );
	gRowOrientedPuzzle[4].SetCell(7, blkBlockOrientedPuzzle[5].GetCell(4) );
	gRowOrientedPuzzle[4].SetCell(8, blkBlockOrientedPuzzle[5].GetCell(5) );
	
	gRowOrientedPuzzle[5].SetCell(0, blkBlockOrientedPuzzle[3].GetCell(6) );
	gRowOrientedPuzzle[5].SetCell(1, blkBlockOrientedPuzzle[3].GetCell(7) );
	gRowOrientedPuzzle[5].SetCell(2, blkBlockOrientedPuzzle[3].GetCell(8) );

	gRowOrientedPuzzle[5].SetCell(3, blkBlockOrientedPuzzle[4].GetCell(6) );
	gRowOrientedPuzzle[5].SetCell(4, blkBlockOrientedPuzzle[4].GetCell(7) );
	gRowOrientedPuzzle[5].SetCell(5, blkBlockOrientedPuzzle[4].GetCell(8) );
			
	gRowOrientedPuzzle[5].SetCell(6, blkBlockOrientedPuzzle[5].GetCell(6) );
	gRowOrientedPuzzle[5].SetCell(7, blkBlockOrientedPuzzle[5].GetCell(7) );
	gRowOrientedPuzzle[5].SetCell(8, blkBlockOrientedPuzzle[5].GetCell(8) );

	gRowOrientedPuzzle[6].SetCell(0, blkBlockOrientedPuzzle[6].GetCell(0) );
	gRowOrientedPuzzle[6].SetCell(1, blkBlockOrientedPuzzle[6].GetCell(1) );
	gRowOrientedPuzzle[6].SetCell(2, blkBlockOrientedPuzzle[6].GetCell(2) );

	gRowOrientedPuzzle[6].SetCell(3, blkBlockOrientedPuzzle[7].GetCell(0) );
	gRowOrientedPuzzle[6].SetCell(4, blkBlockOrientedPuzzle[7].GetCell(1) );
	gRowOrientedPuzzle[6].SetCell(5, blkBlockOrientedPuzzle[7].GetCell(2) );
			
	gRowOrientedPuzzle[6].SetCell(6, blkBlockOrientedPuzzle[8].GetCell(0) );
	gRowOrientedPuzzle[6].SetCell(7, blkBlockOrientedPuzzle[8].GetCell(1) );
	gRowOrientedPuzzle[6].SetCell(8, blkBlockOrientedPuzzle[8].GetCell(2) );
		
	gRowOrientedPuzzle[7].SetCell(0, blkBlockOrientedPuzzle[6].GetCell(3) );
	gRowOrientedPuzzle[7].SetCell(1, blkBlockOrientedPuzzle[6].GetCell(4) );
	gRowOrientedPuzzle[7].SetCell(2, blkBlockOrientedPuzzle[6].GetCell(5) );

	gRowOrientedPuzzle[7].SetCell(3, blkBlockOrientedPuzzle[7].GetCell(3) );
	gRowOrientedPuzzle[7].SetCell(4, blkBlockOrientedPuzzle[7].GetCell(4) );
	gRowOrientedPuzzle[7].SetCell(5, blkBlockOrientedPuzzle[7].GetCell(5) );
			
	gRowOrientedPuzzle[7].SetCell(6, blkBlockOrientedPuzzle[8].GetCell(3) );
	gRowOrientedPuzzle[7].SetCell(7, blkBlockOrientedPuzzle[8].GetCell(4) );
	gRowOrientedPuzzle[7].SetCell(8, blkBlockOrientedPuzzle[8].GetCell(5) );

	gRowOrientedPuzzle[8].SetCell(0, blkBlockOrientedPuzzle[6].GetCell(6) );
	gRowOrientedPuzzle[8].SetCell(1, blkBlockOrientedPuzzle[6].GetCell(7) );
	gRowOrientedPuzzle[8].SetCell(2, blkBlockOrientedPuzzle[6].GetCell(8) );

	gRowOrientedPuzzle[8].SetCell(3, blkBlockOrientedPuzzle[7].GetCell(6) );
	gRowOrientedPuzzle[8].SetCell(4, blkBlockOrientedPuzzle[7].GetCell(7) );
	gRowOrientedPuzzle[8].SetCell(5, blkBlockOrientedPuzzle[7].GetCell(8) );
			
	gRowOrientedPuzzle[8].SetCell(6, blkBlockOrientedPuzzle[8].GetCell(6) );
	gRowOrientedPuzzle[8].SetCell(7, blkBlockOrientedPuzzle[8].GetCell(7) );
	gRowOrientedPuzzle[8].SetCell(8, blkBlockOrientedPuzzle[8].GetCell(8) );
	return;
}

void gCopyColOrientedPuzzle(Block blkBlockOrientedPuzzle[BLOCK_SIZE], Block gColOrientedPuzzle[BLOCK_SIZE])
{
    const int BLOCK_WIDTH = (int)sqrt(BLOCK_SIZE);
    for (int columnID = 0; columnID < BLOCK_SIZE; columnID++) {
        int blockOffset = columnID / BLOCK_WIDTH;
        for(int cellID = 0; cellID < BLOCK_SIZE; cellID +=BLOCK_WIDTH) {
            int blockID = cellID + blockOffset;
            for(int offset = 0; offset < BLOCK_WIDTH; offset++) {
                gColOrientedPuzzle[columnID].SetCell(cellID+offset,blkBlockOrientedPuzzle[blockID].GetCell(columnID%BLOCK_WIDTH + offset * BLOCK_WIDTH));
            }
            /*
            gColOrientedPuzzle[columnID].SetCell(cellID,blkBlockOrientedPuzzle[blockID].GetCell(columnID%BLOCK_WIDTH));
            gColOrientedPuzzle[columnID].SetCell(cellID+1,blkBlockOrientedPuzzle[blockID].GetCell(columnID%BLOCK_WIDTH +3));
            gColOrientedPuzzle[columnID].SetCell(cellID+2,blkBlockOrientedPuzzle[blockID].GetCell(columnID%BLOCK_WIDTH +6));
             */
        }
    }
    /*
	gColOrientedPuzzle[0].SetCell(0, gSudokuPuzzle[0].GetCell(0) );
	gColOrientedPuzzle[0].SetCell(1, gSudokuPuzzle[0].GetCell(3) );
	gColOrientedPuzzle[0].SetCell(2, gSudokuPuzzle[0].GetCell(6) );

	gColOrientedPuzzle[0].SetCell(3, gSudokuPuzzle[3].GetCell(0) );
	gColOrientedPuzzle[0].SetCell(4, gSudokuPuzzle[3].GetCell(3) );
	gColOrientedPuzzle[0].SetCell(5, gSudokuPuzzle[3].GetCell(6) );
			
	gColOrientedPuzzle[0].SetCell(6, gSudokuPuzzle[6].GetCell(0) );
	gColOrientedPuzzle[0].SetCell(7, gSudokuPuzzle[6].GetCell(3) );
	gColOrientedPuzzle[0].SetCell(8, gSudokuPuzzle[6].GetCell(6) );
	
	gColOrientedPuzzle[1].SetCell(0, gSudokuPuzzle[0].GetCell(1) );
	gColOrientedPuzzle[1].SetCell(1, gSudokuPuzzle[0].GetCell(4) );
	gColOrientedPuzzle[1].SetCell(2, gSudokuPuzzle[0].GetCell(7) );
	
	gColOrientedPuzzle[1].SetCell(3, gSudokuPuzzle[3].GetCell(1) );
	gColOrientedPuzzle[1].SetCell(4, gSudokuPuzzle[3].GetCell(4) );
	gColOrientedPuzzle[1].SetCell(5, gSudokuPuzzle[3].GetCell(7) );
	
	gColOrientedPuzzle[1].SetCell(6, gSudokuPuzzle[6].GetCell(1) );
	gColOrientedPuzzle[1].SetCell(7, gSudokuPuzzle[6].GetCell(4) );
	gColOrientedPuzzle[1].SetCell(8, gSudokuPuzzle[6].GetCell(7) );

	gColOrientedPuzzle[2].SetCell(0, gSudokuPuzzle[0].GetCell(2) );
	gColOrientedPuzzle[2].SetCell(1, gSudokuPuzzle[0].GetCell(5) );
	gColOrientedPuzzle[2].SetCell(2, gSudokuPuzzle[0].GetCell(8) );

	gColOrientedPuzzle[2].SetCell(3, gSudokuPuzzle[3].GetCell(2) );
	gColOrientedPuzzle[2].SetCell(4, gSudokuPuzzle[3].GetCell(5) );
	gColOrientedPuzzle[2].SetCell(5, gSudokuPuzzle[3].GetCell(8) );
		
	gColOrientedPuzzle[2].SetCell(6, gSudokuPuzzle[6].GetCell(2) );
	gColOrientedPuzzle[2].SetCell(7, gSudokuPuzzle[6].GetCell(5) );
	gColOrientedPuzzle[2].SetCell(8, gSudokuPuzzle[6].GetCell(8) );

	gColOrientedPuzzle[3].SetCell(0, gSudokuPuzzle[1].GetCell(0) );
	gColOrientedPuzzle[3].SetCell(1, gSudokuPuzzle[1].GetCell(3) );
	gColOrientedPuzzle[3].SetCell(2, gSudokuPuzzle[1].GetCell(6) );

	gColOrientedPuzzle[3].SetCell(3, gSudokuPuzzle[4].GetCell(0) );
	gColOrientedPuzzle[3].SetCell(4, gSudokuPuzzle[4].GetCell(3) );
	gColOrientedPuzzle[3].SetCell(5, gSudokuPuzzle[4].GetCell(6) );
			
	gColOrientedPuzzle[3].SetCell(6, gSudokuPuzzle[7].GetCell(0) );
	gColOrientedPuzzle[3].SetCell(7, gSudokuPuzzle[7].GetCell(3) );
	gColOrientedPuzzle[3].SetCell(8, gSudokuPuzzle[7].GetCell(6) );
			
	gColOrientedPuzzle[4].SetCell(0, gSudokuPuzzle[1].GetCell(1) );
	gColOrientedPuzzle[4].SetCell(1, gSudokuPuzzle[1].GetCell(4) );
	gColOrientedPuzzle[4].SetCell(2, gSudokuPuzzle[1].GetCell(7) );

	gColOrientedPuzzle[4].SetCell(3, gSudokuPuzzle[4].GetCell(1) );
	gColOrientedPuzzle[4].SetCell(4, gSudokuPuzzle[4].GetCell(4) );
	gColOrientedPuzzle[4].SetCell(5, gSudokuPuzzle[4].GetCell(7) );
			
	gColOrientedPuzzle[4].SetCell(6, gSudokuPuzzle[7].GetCell(1) );
	gColOrientedPuzzle[4].SetCell(7, gSudokuPuzzle[7].GetCell(4) );
	gColOrientedPuzzle[4].SetCell(8, gSudokuPuzzle[7].GetCell(7) );
	
	gColOrientedPuzzle[5].SetCell(0, gSudokuPuzzle[1].GetCell(2) );
	gColOrientedPuzzle[5].SetCell(1, gSudokuPuzzle[1].GetCell(5) );
	gColOrientedPuzzle[5].SetCell(2, gSudokuPuzzle[1].GetCell(8) );

	gColOrientedPuzzle[5].SetCell(3, gSudokuPuzzle[4].GetCell(2) );
	gColOrientedPuzzle[5].SetCell(4, gSudokuPuzzle[4].GetCell(5) );
	gColOrientedPuzzle[5].SetCell(5, gSudokuPuzzle[4].GetCell(8) );
			
	gColOrientedPuzzle[5].SetCell(6, gSudokuPuzzle[7].GetCell(2) );
	gColOrientedPuzzle[5].SetCell(7, gSudokuPuzzle[7].GetCell(5) );
	gColOrientedPuzzle[5].SetCell(8, gSudokuPuzzle[7].GetCell(8) );

	gColOrientedPuzzle[6].SetCell(0, gSudokuPuzzle[2].GetCell(0) );
	gColOrientedPuzzle[6].SetCell(1, gSudokuPuzzle[2].GetCell(3) );
	gColOrientedPuzzle[6].SetCell(2, gSudokuPuzzle[2].GetCell(6) );

	gColOrientedPuzzle[6].SetCell(3, gSudokuPuzzle[5].GetCell(0) );
	gColOrientedPuzzle[6].SetCell(4, gSudokuPuzzle[5].GetCell(3) );
	gColOrientedPuzzle[6].SetCell(5, gSudokuPuzzle[5].GetCell(6) );
			
	gColOrientedPuzzle[6].SetCell(6, gSudokuPuzzle[8].GetCell(0) );
	gColOrientedPuzzle[6].SetCell(7, gSudokuPuzzle[8].GetCell(3) );
	gColOrientedPuzzle[6].SetCell(8, gSudokuPuzzle[8].GetCell(6) );
			
	gColOrientedPuzzle[7].SetCell(0, gSudokuPuzzle[2].GetCell(1) );
	gColOrientedPuzzle[7].SetCell(1, gSudokuPuzzle[2].GetCell(4) );
	gColOrientedPuzzle[7].SetCell(2, gSudokuPuzzle[2].GetCell(7) );

	gColOrientedPuzzle[7].SetCell(3, gSudokuPuzzle[5].GetCell(1) );
	gColOrientedPuzzle[7].SetCell(4, gSudokuPuzzle[5].GetCell(4) );
	gColOrientedPuzzle[7].SetCell(5, gSudokuPuzzle[5].GetCell(7) );
			
	gColOrientedPuzzle[7].SetCell(6, gSudokuPuzzle[8].GetCell(1) );
	gColOrientedPuzzle[7].SetCell(7, gSudokuPuzzle[8].GetCell(4) );
	gColOrientedPuzzle[7].SetCell(8, gSudokuPuzzle[8].GetCell(7) );

	gColOrientedPuzzle[8].SetCell(0, gSudokuPuzzle[2].GetCell(2) );
	gColOrientedPuzzle[8].SetCell(1, gSudokuPuzzle[2].GetCell(5) );
	gColOrientedPuzzle[8].SetCell(2, gSudokuPuzzle[2].GetCell(8) );

	gColOrientedPuzzle[8].SetCell(3, gSudokuPuzzle[5].GetCell(2) );
	gColOrientedPuzzle[8].SetCell(4, gSudokuPuzzle[5].GetCell(5) );
	gColOrientedPuzzle[8].SetCell(5, gSudokuPuzzle[5].GetCell(8) );
			
	gColOrientedPuzzle[8].SetCell(6, gSudokuPuzzle[8].GetCell(2) );
	gColOrientedPuzzle[8].SetCell(7, gSudokuPuzzle[8].GetCell(5) );
	gColOrientedPuzzle[8].SetCell(8, gSudokuPuzzle[8].GetCell(8) );
     */
	return;
}

bool Puzzle::bIsSolution()
{
	Block blkRowOrientedCopy[BLOCK_SIZE];
	gCopyRowOrientedPuzzle(_blkBlockOrientedPuzzle, blkRowOrientedCopy);
	Block blkColumnOrientedCopy[BLOCK_SIZE];
	gCopyColOrientedPuzzle(_blkBlockOrientedPuzzle, blkColumnOrientedCopy);
	for (int iBlockNo=0; iBlockNo<BLOCK_SIZE; iBlockNo++) // check all blocks
	{
		//bool check = bSolveBlock(gBlockOrientedPuzzle[iBlockNo]);
		bool bBlockSolved = _blkBlockOrientedPuzzle[iBlockNo].bIsSolvedBlock();
        bool bRowSolved = blkRowOrientedCopy[iBlockNo].bIsSolvedBlock();
        bool bColSoved = blkColumnOrientedCopy[iBlockNo].bIsSolvedBlock();
		if (bBlockSolved && bRowSolved && bColSoved == false)
			return false;		
	}
	return true;
}
