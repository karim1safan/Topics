#include <iostream>
#include <chrono>

using namespace std;

const int N = 1000;
int arr[N][N] = { 0 };

void access_row_col_test()
{
	auto s = chrono::steady_clock::now(); // Start

	for(int k = 0; k < N; k++)
		for(int i = 0; i < N; i++)
			for(int j = 0; j < N; j++)
				arr[i][j] = i + j;

	auto e = chrono::steady_clock::now(); // End

	auto diff = e - s;	// End - Start

	cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
}

// slow due to locality of reference -> computer architecture course
void access_col_row_test()
{
	auto s = chrono::steady_clock::now(); // Start

	for(int k = 0; k < N; k++)
		for(int j = 0; j < N; j++)
			for(int i = 0; i < N; i++)
				arr[i][j] = i + j;

	auto e = chrono::steady_clock::now(); // End

	auto diff = e - s;	// End - Start

	cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
}
int main()
{
	// Debugging mode is slower than release mode
	// Access the array using row_col is faster than access the array using col_row

	access_row_col_test();
	access_col_row_test();

	// In debug mode: takes -> 2333.64 Ms
	// In debug mode: takes -> 7872.65 Ms

	// In release mode: 143.351 Ms
	// In release mode: 130.685 Ms

	// when we turn from debug mode to release mode we must make the configuration for the project

	// If we in debug mode we can make a debug -> has debug symbols
	// If we in release mode we can't debug the program -> doesn't have debug symbols
	return 0;
}
