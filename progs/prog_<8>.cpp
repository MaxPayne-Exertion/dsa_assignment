#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

void bubbleSort(vector<int>& arr, int& comp, int& swp);
void selectionSort(vector<int>& arr, int& comp, int& swp);
void insertionSort(vector<int>& arr, int& comp, int& swp);
void mergeSort(vector<int>& arr, int& comp, int& swp);
void mergeSortRec(vector<int>& arr, int l, int r, int& comp, int& swp);
void merge(vector<int>& arr, int l, int m, int r, int& comp, int& swp);

int main() {
    srand(time(0));
    
    int n;
    cout << "Enter number of integers to generate (1-1000): ";
    cin >> n;
    
    if (n < 1 || n > 1000) {
        cout << "Invalid input! Using default 10." << endl;
        n = 10;
    }
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000 + 1;
    }
    
    cout << "\nBefore sorting: ";
    for (int i = 0; i < min(20, n); i++) {
        cout << arr[i] << " ";
    }
    if (n > 20) cout << "...";
    cout << endl;
    
    cout << "\nChoose sorting algorithm:\n";
    cout << "1. Bubble Sort\n2. Selection Sort\n";
    cout << "3. Insertion Sort\n4. Merge Sort\n";
    cout << "Enter choice (1-4): ";
    
    int choice;
    cin >> choice;
    
    vector<int> sorted = arr;
    int comp = 0, swp = 0;
    
    clock_t start = clock();
    
    switch(choice) {
        case 1: bubbleSort(sorted, comp, swp); break;
        case 2: selectionSort(sorted, comp, swp); break;
        case 3: insertionSort(sorted, comp, swp); break;
        case 4: mergeSort(sorted, comp, swp); break;
        default: cout << "Invalid choice!\n"; return 1;
    }
    
    clock_t end = clock();
    double time = double(end - start) / CLOCKS_PER_SEC;
    
    cout << "\nSorted array: ";
    for (int num : sorted) {
        cout << num << " ";
    }
    cout << endl;
    
    cout << "\n--- Statistics ---\n";
    cout << "Comparisons: " << comp << endl;
    cout << "Swaps: " << swp << endl;
    cout << "Time: " << time << " seconds\n";
    
    return 0;
}

void bubbleSort(vector<int>& arr, int& comp, int& swp) {
    int n = arr.size();
    comp = swp = 0;
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            comp++;
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                swp++;
            }
        }
    }
}

void selectionSort(vector<int>& arr, int& comp, int& swp) {
    int n = arr.size();
    comp = swp = 0;
    for (int i = 0; i < n-1; i++) {
        int minIdx = i;
        for (int j = i+1; j < n; j++) {
            comp++;
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        if (minIdx != i) {
            swap(arr[i], arr[minIdx]);
            swp++;
        }
    }
}

void insertionSort(vector<int>& arr, int& comp, int& swp) {
    int n = arr.size();
    comp = swp = 0;
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i-1;
        comp++;
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            swp++;
            j--;
            if (j >= 0) comp++;
        }
        arr[j+1] = key;
    }
}

void mergeSort(vector<int>& arr, int& comp, int& swp) {
    comp = swp = 0;
    mergeSortRec(arr, 0, arr.size()-1, comp, swp);
}

void mergeSortRec(vector<int>& arr, int l, int r, int& comp, int& swp) {
    if (l >= r) return;
    int m = l + (r - l) / 2;
    mergeSortRec(arr, l, m, comp, swp);
    mergeSortRec(arr, m+1, r, comp, swp);
    merge(arr, l, m, r, comp, swp);
}

void merge(vector<int>& arr, int l, int m, int r, int& comp, int& swp) {
    vector<int> left(arr.begin()+l, arr.begin()+m+1);
    vector<int> right(arr.begin()+m+1, arr.begin()+r+1);
    
    int i = 0, j = 0, k = l;
    
    while (i < left.size() && j < right.size()) {
        comp++;
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
            swp++;
        }
    }
    
    while (i < left.size()) arr[k++] = left[i++];
    while (j < right.size()) arr[k++] = right[j++];
}