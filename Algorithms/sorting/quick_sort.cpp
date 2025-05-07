#include <bits/stdc++.h>

using namespace std;


int partition(int arr[], int left, int right) {
  int i = left;
  int j = right;
  int pivot = arr[left];

  while (i < j) {
    do {
      i++;
    } while (arr[i] <= pivot);

    while (arr[j] > pivot) {
      j--;
    }

    if (i < j) swap(arr[i], arr[j]);
  }

  swap(arr[left], arr[j]); // swap pivot when i > j
  return j;
}

void quick_sort(int arr[], int l, int r) {
  if (l < r) {
    int pivot = partition(arr, l, r);
    quick_sort(arr, l, pivot - 1);
    quick_sort(arr, pivot + 1, r);
  }
}

int main(int argc, char *argv[])
{

  int arr[] = {65, 70, 75, 80, 85, 60, 55, 50, 45};

  quick_sort(arr, 0, 9); // 45 50 55 60 65 70 75 80 85

  for (int i = 0; i < 9; i++) cout << arr[i] << " ";
  cout << endl;

  return 0;
}
