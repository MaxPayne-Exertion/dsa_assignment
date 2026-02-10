
---

# Documentation for Question 6

## Building Min Heap and Max Heap from an Unsorted Array

---

## 1. Problem Overview

This program demonstrates how to construct both a **Min-Heap** and a **Max-Heap** from an unsorted array of integers.

A heap is a **complete binary tree** that satisfies the heap property:

* **Min-Heap:** Parent node is smaller than or equal to its children.
* **Max-Heap:** Parent node is greater than or equal to its children.

The program uses heapify operations to convert the array into valid heap structures.

---

## 2. Data Structures Used

### a) Vector (`vector<int>`)

* The heap is represented using a vector.
* This vector represents a **complete binary tree**.
* For any index `i`:

  * Left child = `2*i + 1`
  * Right child = `2*i + 2`

This array representation avoids using pointers and simplifies heap implementation.

---

## 3. Function Descriptions

### a) `void maxHeapify(vector<int>& arr, int n, int i)`

**Purpose:**
Ensures the subtree rooted at index `i` satisfies the **max-heap property**.

**Process:**

1. Compare the current node with its left and right children.
2. Find the largest value among them.
3. If the largest is not the current node, swap and recursively heapify the affected subtree.

---

### b) `void minHeapify(vector<int>& arr, int n, int i)`

**Purpose:**
Ensures the subtree rooted at index `i` satisfies the **min-heap property**.

**Process:**

1. Compare the current node with its children.
2. Find the smallest value.
3. Swap and recursively heapify if necessary.

---

### c) `void buildMaxHeap(vector<int>& arr)`

**Purpose:**
Builds a max-heap from the given array.

**Process:**

* Starts heapifying from the last non-leaf node (`n/2 - 1`) up to the root.
* Applies `maxHeapify` at each index.

---

### d) `void buildMinHeap(vector<int>& arr)`

**Purpose:**
Builds a min-heap from the given array.

**Process:**

* Similar to `buildMaxHeap`, but uses `minHeapify`.

---

## 4. Overview of `main()` Function

The `main()` function:

1. Declares an unsorted array: `{4, 10, 3, 5, 1, 8, 7}`.
2. Copies the array into two vectors:

   * One for min-heap
   * One for max-heap
3. Calls the respective heap building functions.
4. Prints:

   * Original array
   * Min-Heap representation
   * Max-Heap representation

---

## 5. Sample Output

```
Original array: 4 10 3 5 1 8 7
Min-Heap: 1 4 3 5 10 8 7
Max-Heap: 10 5 8 4 1 3 7
```

---

## 6. Conclusion

* The program shows how heap structures can be built efficiently from an unsorted array.
* Heapify operations ensure the correct ordering of elements.
* The array representation simplifies the implementation of heaps.

This implementation demonstrates a key concept used in priority queues and heap sort algorithms.
