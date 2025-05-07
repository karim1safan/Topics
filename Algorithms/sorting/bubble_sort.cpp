// Karim Mahmoud Safan
#include <iostream>
#include <vector>
using namespace std;

void BubbleSort(vector<int> &arr) { // O(N^2)
  int n = arr.size();

  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - 1 - i; j++) {
      if (arr[j] > arr[j+1]) {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}


int main() {
  vector<int> arr = {89, 45, 68, 90, 29, 34, 17};
  BubbleSort(arr); // 17 29 34 45 68 89 90
  for (auto &it : arr) {
    cout << it << " ";
  }
  cout << endl;
  return 0;
}
