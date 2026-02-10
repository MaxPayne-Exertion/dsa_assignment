

---

# Documentation for Question 4

## Implementation of Doubly Linked List with Insert and Delete Operations

---

## 1. Problem Overview

This program demonstrates how to implement a **Doubly Linked List** using structures in C++. It also provides methods to:

* Insert a new node **after a given node**
* Delete a specified node
* Search for a node
* Display the list

The `main()` function shows how these operations work in practice.

---

## 2. Data Structures Used

### Structure: `node`

The doubly linked list node is defined as:

```
struct node{
    int data;
    node* prev;
    node* next;
    node(int val):data(val),prev(nullptr),next(nullptr){}
};
```

Each node contains:

* `data`: stores the value of the node.
* `prev`: pointer to the previous node.
* `next`: pointer to the next node.

This allows traversal in **both forward and backward directions**.

---

## 3. Function Descriptions

### a) `node* createlist()`

**Purpose:**
Creates an initial doubly linked list manually with three nodes: `10 → 20 → 30`.

**Process:**

* Allocates memory for three nodes.
* Connects them using `next` and `prev` pointers.
* Returns the head of the list.

---

### b) `void displaylist(node* head)`

**Purpose:**
Displays the elements of the list from head to end.

**Process:**

* Traverses using `next` pointer.
* Prints each node’s data.

---

### c) `node* searchnode(node* head, int val)`

**Purpose:**
Searches for a node containing the given value.

**Process:**

* Traverses the list.
* Returns the pointer to the node if found.
* Returns `nullptr` if not found.

---

### d) `node* insertafter(node* head, node* targetnode, int value)`

**Purpose:**
Inserts a new node **after** a specified node.

**Process:**

1. Create a new node with the given value.
2. Adjust the `next` and `prev` pointers of:

   * New node
   * Target node
   * Target node’s next node (if it exists)
3. Return the updated head.

---

### e) `node* deletenode(node* head, node* nodetodelete)`

**Purpose:**
Deletes a specified node from the doubly linked list.

**Process:**

1. If the node is the head, move head to the next node.
2. Adjust `prev` and `next` pointers of neighboring nodes.
3. Free the memory of the deleted node.
4. Return the updated head.

---

## 4. Overview of `main()` Function

The `main()` function demonstrates the use of all operations:

1. Creates the initial list: `10 20 30`
2. Displays the list.
3. Searches for node `20` and inserts `23` after it.
4. Displays the updated list.
5. Searches for node `30` and deletes it.
6. Displays the final list.

---

## 5. Sample Output

```
10 20 30
insterted23AFTER node with value20
10 20 23 30
deleted node val30
10 20 23
```

---

## 6. Conclusion

* The program demonstrates how a doubly linked list is implemented using structures.
* It shows correct pointer manipulation for insertion and deletion.
* Searching and displaying operations support the main functionalities.

This example highlights the flexibility of doubly linked lists and how nodes can be efficiently inserted or removed from any position.
