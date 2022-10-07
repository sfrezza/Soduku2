#pragma once
#include <iostream>
using namespace std;

enum CellType
{
	One, Two, Three, Four, Five, Six, Seven, Eight, Nine, Blank
};
class Cell
{
private:
	CellType _MyCell;
public:
	Cell(void);
	~Cell(void);
	bool convertToCellType(char c);
	char cPrintBlockValue();
	CellType cGetValue() { return _MyCell;} 

};

