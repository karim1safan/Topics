// Karim Mahmoud Safan
#include <iostream>
#include <vector>
using namespace std;

void SelectionSort(vector<int> &arr) { // O(N^2)
  int n = arr.size();

  for (int i = 0; i < n - 1; i++) {
    int min = i;
    for (int j = i + 1; j < n; j++) {
      if (arr[min] > arr[j]) {
        min = j;
      }
    }
    int temp = arr[i];
    arr[i] = arr[min];
    arr[min] = temp;
  }
}

int main() {
  vector<int> arr = {89, 45, 68, 90, 29, 34, 17};
  SelectionSort(arr); // 17 29 34 45 68 89 90
  for (auto &it : arr) {
    cout << it << " ";
  }
  cout << endl;
  return 0;
}
