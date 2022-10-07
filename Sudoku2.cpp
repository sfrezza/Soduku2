// refact_Sudoku.cpp : Defines the entry point for the console application.

#include "Cell.h"
#include "Block.h"
#include "Puzzle.h"
#include <iostream>
#include <fstream>
using namespace std;


int main(int argc, const char * argv[])
{
    cout << "Input puzzle definition file name: ";
    string localFileName;
    cin >> localFileName;
    
	Puzzle *gSudokuPuzzle = new Puzzle(localFileName);

    if (gSudokuPuzzle->bIsSolution()) {
            gSudokuPuzzle->gPrintGrid();
            cout << endl << "Valid Solution!!" << endl;
    }
    else {
            gSudokuPuzzle->gPrintGrid();
            cout << endl << "Invalid Solution." << endl;
    }
	return 0;	
}



