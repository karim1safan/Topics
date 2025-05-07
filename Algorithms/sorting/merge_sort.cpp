#include<iostream>
#include <vector>
using namespace std;

void merge(int arr[], int left, int mid, int right) { // O(n1 + n2)

  int n1 = mid - left + 1; // first subarray size arr[left..mid]
  int n2 = right - mid;    // second subarray size arr[mid+1..right]
  int L[n1], R[n2];        // temporary arrays

  for (int i = 0; i < n1; i++)
    L[i] = arr[left + i]; // copy data to temp arrays
  for (int j = 0; j < n2; j++)
    R[j] = arr[mid + 1 + j]; // copy data to temp arrays

  int i = 0, j = 0, k = left;
  while (i < n1 && j < n2)
  {
    if (L[i] <= R[j])
    {
      arr[k] = L[i];
      i++;
    }
    else
    {
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  while (i < n1)
  {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2)
  {
    arr[k] = R[j];
    j++;
    k++;
  }
}

void merge_sort(int arr[], int left, int right) { // O(n log n)
  if (left < right) {
    int mid = left + (right - left) / 2; // find the middle point
    merge_sort(arr, left, mid);          // sort first half
    merge_sort(arr, mid + 1, right);     // sort second half
    merge(arr, left, mid, right);        // merge the sorted halves
  }
}

int main()
{
  int arr[7] = {89, 45, 68, 90, 29, 34, 17};
  merge_sort(arr, 0, 6); // 17 29 34 45 68 89 90
  for (int i = 0; i < 7; i++)
    cout << arr[i] << " ";
  cout << endl;

  return 0;
}
