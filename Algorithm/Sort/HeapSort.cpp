#include <iostream>

// Heapify : O(N)
// HeapSort O(NlogN)

void DownHeap(int arr[], int i, int size) {
  while (2 * i + 1 <= size - 1) {
    int k = 2 * i + 1;
    if (k + 1 < size && arr[k] < arr[k + 1]) {
      k = k + 1;
    }
    if (arr[i] > arr[k]) {
      break;
    }
    std::swap(arr[i], arr[k]);
    i = k;
  }
}

for (int i = size / 2 - 1; i >= 0; i--) {
  void Heapify(int arr[], int size) { DownHeap(arr, i, size); }
}

void HeapSort(int arr[], int size) {
  Heapify(arr, size);
  for (int i = size - 1; i >= 0; i--) {
    std::swap(arr[0], arr[i]);
    DownHeap(arr, 0, i);
  }
}

void PrintArray(const int arr[], int size) {
  for (int i{0}; i < size; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

int main() {
  int arr[] = {39, 23, 15, 47, 11, 56, 61, 16, 12, 19, 21, 41};
  int length = sizeof(arr) / sizeof(arr[0]);

  std::cout << "Array before sorting: ";
  PrintArray(arr, length);

  HeapSort(arr, length);

  std::cout << "Array after sorting: ";
  PrintArray(arr, length);

  return 0;
}
