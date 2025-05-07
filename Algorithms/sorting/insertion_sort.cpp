#include <iostream>
using namespace std;

void insertion_sort(int arr[], int n)
{ // O(n^2)
  for (int i = 0; i < n; i++)
  {
    int v = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > v)
    {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = v;
  }
}

int main() {
  int arr[] = {89, 45, 68, 90, 29, 34, 17};
  insertion_sort(arr, 7);
  for (int i = 0; i < 7; i++)
    cout << arr[i] << " ";
  cout << endl;
  return 0;
}
