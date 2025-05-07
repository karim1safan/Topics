#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int BinarySearch(vector<int> &arr, int target) { // O(log N)
  int n = arr.size();
  sort(arr.begin(), arr.end()); // O(N log N)
  int left = 0, right = n - 1;
  while (left <= right) { 
    int mid = (left + right) / 2;

    if (arr[mid] == target)
      return mid;
    else if (target > arr[mid]) 
      left = mid + 1;
    else
      right = mid - 1; 
  }
  return -1;
}

int main() {
  vector<int> arr = {1, 3, 5, 7, 9};
  cout << BinarySearch(arr, 5) << endl; // 2
  return 0;
}
