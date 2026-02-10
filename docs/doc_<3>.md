# Documentation for Question 3

## Reverse Traversal of a Linked List Using Recursion

---

## 1. Problem Overview

This program demonstrates how to perform a **reverse traversal** of a singly linked list using a **recursive algorithm**.

Instead of modifying the linked list or reversing the links, the program prints the elements in reverse order by utilizing the recursive call stack.

The `main()` function creates a linked list, prints it in forward order, and then prints it in reverse order using the recursive function.

---

## 2. Data Structures Used

### Structure: `node`

A singly linked list node is defined as:

```
struct node{
    int data;
    node* next;
    node(int val): data(val), next(nullptr){}
};
```

Each node contains:

* `data`: stores the integer value.
* `next`: pointer to the next node in the list.
* A constructor to initialize the node.

This structure forms a **singly linked list** where each node points to the next.

---

## 3. Function Descriptions

### a) `node* createlist(int arr[], int n)`

**Purpose:**
Creates a linked list from an array of integers.

**Process:**

1. Create the head node using the first element.
2. Iterate through the array.
3. Dynamically create new nodes and link them sequentially.
4. Return the head pointer.

---

### b) `void printForward(node* head)`

**Purpose:**
Prints the linked list in normal (forward) order.

**Process:**

* Traverse from head to the last node.
* Print each node’s data.

---

### c) `void recursiveReverse(node* head)`

**Purpose:**
Prints the linked list in reverse order using recursion.

**Algorithm:**

1. Base case: If the node is `nullptr`, return.
2. Recursively call the function for the next node.
3. Print the current node’s data while returning from recursion.

This uses the call stack to reverse the order of printing.

---

### d) `void deletelist(node* head)`

**Purpose:**
Intended to delete the linked list from memory.

**Note:**
The current implementation deletes only the first node. For proper deletion, a loop should be used to free all nodes.

---

## 4. Overview of `main()` Function

The `main()` function performs the following steps:

1. Declares an array of integers: `{10, 20, 30, 40}`.
2. Calls `createlist()` to convert the array into a linked list.
3. Prints the list in forward order using `printForward()`.
4. Prints the list in reverse order using `recursiveReverse()`.

This clearly demonstrates the difference between normal traversal and reverse traversal.

---

## 5. Sample Output

```
regularlist:10 20 30 40
reverse traversed list:40 30 20 10
```

---

## 6. Conclusion

* The program demonstrates reverse traversal without modifying the list.
* Recursion is effectively used to reverse the output order.
* The linked list is dynamically created from an array, showing practical usage of pointers and dynamic memory.

This example highlights the use of **recursion with linked lists** for reverse traversal operations.

---
