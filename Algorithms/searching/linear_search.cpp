#include <iostream>
#include <vector>
using namespace std;

int SequentialSearch(vector<int> arr, int target) { // O(N)
  for (int i = 0; i < arr.size(); i++) { 
    if (arr[i] == target) {
      return i;
    }
  }
  return -1;
}


int main() {
  vector<int> arr = {10, 2, 30, 5, 3};
  cout << SequentialSearch(arr, 5) << endl; // 3
  return 0;
}
