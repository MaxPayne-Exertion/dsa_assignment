
---

# Documentation for Question 8

## Random Number Generation and Sorting with Statistics

---

## 1. Problem Overview

This program generates a list of **N random integers** in the range `[1, 1000]` and allows the user to sort the numbers using one of the following algorithms:

* Bubble Sort
* Selection Sort
* Insertion Sort
* Merge Sort

Additionally, the program prints:

* The numbers before and after sorting
* Total number of comparisons and swaps performed
* Time taken for sorting

---

## 2. Data Structures Used

### a) Vector (`vector<int>`)

* Stores the list of random integers.
* Provides dynamic sizing and easy access to elements.

### b) Variables for Statistics

* `comp` – Counts the number of comparisons performed.
* `swp` – Counts the number of swaps performed.

### c) Timing

* `clock_t start` and `clock_t end` are used to measure execution time.

---

## 3. Function Descriptions

### a) `void bubbleSort(vector<int>& arr, int& comp, int& swp)`

**Purpose:**
Sorts the array using **Bubble Sort**.

**Process:**

1. Repeatedly compares adjacent elements.
2. Swaps them if they are in the wrong order.
3. Updates `comp` for each comparison and `swp` for each swap.

---

### b) `void selectionSort(vector<int>& arr, int& comp, int& swp)`

**Purpose:**
Sorts the array using **Selection Sort**.

**Process:**

1. Select the smallest element from the unsorted part.
2. Swap it with the first unsorted element.
3. Track comparisons and swaps.

---

### c) `void insertionSort(vector<int>& arr, int& comp, int& swp)`

**Purpose:**
Sorts the array using **Insertion Sort**.

**Process:**

1. Pick elements one by one and insert them at the correct position in the sorted part.
2. Count comparisons and swaps during insertion.

---

### d) `void mergeSort(vector<int>& arr, int& comp, int& swp)`

**Purpose:**
Sorts the array using **Merge Sort**.

**Process:**

1. Recursively divide the array into two halves (`mergeSortRec`).
2. Merge the sorted halves using `merge`.
3. Track comparisons and swaps during merging.

---

### e) Helper Functions

* `void mergeSortRec(vector<int>& arr, int l, int r, int& comp, int& swp)`

  * Recursively divides the array and calls merge.

* `void merge(vector<int>& arr, int l, int m, int r, int& comp, int& swp)`

  * Merges two sorted subarrays.
  * Updates `comp` for comparisons and `swp` for movements during merge.

---

## 4. Overview of `main()` Function

1. Ask the user to enter the number of integers `N`.
2. Generate `N` random integers in the range `[1,1000]`.
3. Display the first 20 numbers before sorting (or all if `N ≤ 20`).
4. Ask the user to choose a sorting algorithm (1–4).
5. Copy the array to a new vector `sorted`.
6. Call the chosen sorting algorithm while measuring:

   * Comparisons (`comp`)
   * Swaps (`swp`)
   * Execution time
7. Print the sorted array.
8. Display statistics.

---

## 5. Sample Output

```
Enter number of integers to generate (1-1000): 10

Before sorting: 345 12 789 23 456 87 654 321 90 10 

Choose sorting algorithm:
1. Bubble Sort
2. Selection Sort
3. Insertion Sort
4. Merge Sort
Enter choice (1-4): 1

Sorted array: 10 12 23 87 90 321 345 456 654 789 

--- Statistics ---
Comparisons: 45
Swaps: 15
Time: 0.000123 seconds
```

> Note: The numbers, comparisons, swaps, and time vary with each run due to random generation.

---

## 6. Conclusion

* The program demonstrates four classical sorting algorithms.
* Random integer generation allows flexible testing.
* Comparison and swap counters provide insights into algorithm efficiency.
* Merge Sort uses recursion and is more efficient for large datasets than Bubble, Selection, or Insertion Sort.
