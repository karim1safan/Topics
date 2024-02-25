#include <iostream>
#include <iomanip>
using namespace std;

int main(){

    const int ROWS = 3, COLS = 4;

    int arr2D[ROWS][COLS] = {
		{8, 16, 9, 52}, // row 0
		{3, 15, 27, 6}, // row 1
		{14, 25, 2, 10}, // row 2
    };

    // Flatten 2D => 1D
    int arr1D[ROWS*COLS] = {8, 16, 9, 52, 3, 15, 27, 6, 14, 25, 2, 10};

	int r = 1, c = 3;
	cout << arr2D[r][c] << endl; // 6

	// If we want to access an element from flatten array
	int idx = r * COLS + c; // we 'll  division this equ. to COLS
	cout << idx << " " << arr1D[idx] << endl; // 7 6

	// If we want the opposite
	int rr = idx / COLS, cc = idx % COLS;
	cout << rr << " " << cc << endl; // 1 3
	
	
	//  If you want to know how many cell befor specific cell in the arr
    // cell before an item = r * COL + c 
    // if we start from 1 we'll minus 1 to be[ r-1 * COL + c-1 ]
    
    // If we know where are in the memory for specific item
    // element_size[r * COL + c] -> we suppose we  start from 0 

    // If the computer want access a value in the RAM -> does it in the cache or NOT, If it in the cache use it, ELSE take a block (Copy) of RAM and store it in cache
    
	return 0;
}
