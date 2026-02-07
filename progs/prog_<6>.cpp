#include <iostream>
#include <vector>
#include <algorithm>
 

using namespace std;

void maxHeapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        maxHeapify(arr, n, largest);
    }
}


void minHeapify(vector<int>& arr, int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[smallest])
        smallest = left;
    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}


void buildMaxHeap(vector<int>& arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);
}


void buildMinHeap(vector<int>& arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--)
        minHeapify(arr, n, i);
}

int main() {
    vector<int> arr = {4, 10, 3, 5, 1, 8, 7};
    vector<int> minHeap = arr;
    vector<int> maxHeap = arr;

    buildMinHeap(minHeap);
    buildMaxHeap(maxHeap);

    cout << "Original array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    cout << "Min-Heap: ";
    for (int num : minHeap) cout << num << " ";
    cout << endl;

    cout << "Max-Heap: ";
    for (int num : maxHeap) cout << num << " ";
    cout << endl;

    return 0;
}