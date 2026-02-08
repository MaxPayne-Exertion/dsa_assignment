Here is the **raw Markdown content** for:

```
doc_5.md
```

Copy this exactly into the file.

---

# Documentation for Question 5

## Implementation of Undirected Graph Using Adjacency Matrix with BFS and DFS Traversal

---

## 1. Problem Overview

This program implements an **undirected graph** using an **adjacency matrix**. It also provides functions to perform:

* Breadth First Search (BFS)
* Depth First Search (DFS)

The `main()` function demonstrates these traversals on a sample graph of 7 vertices.

---

## 2. Data Structures Used

### a) Adjacency Matrix (`vector<vector<int>>`)

The graph is represented using a 2D vector (matrix):

* `adjmatrix[i][j] = 1` indicates an edge between vertex `i` and vertex `j`.
* `adjmatrix[i][j] = 0` indicates no edge.
* Since the graph is **undirected**, the matrix is symmetric:

  ```
  adjmatrix[u][v] = adjmatrix[v][u]
  ```

### b) Queue (`queue<int>`)

Used in BFS to explore vertices level by level.

### c) Stack (`stack<int>`)

Used in DFS to explore vertices deeply before backtracking.

### d) Visited Array (`vector<bool>`)

Tracks whether a vertex has been visited during traversal.

---

## 3. Class: `graph`

The `graph` class contains:

* Number of vertices
* Adjacency matrix
* Methods to add edges and perform traversals

---

## 4. Function Descriptions

### a) `graph(int vert)`

**Purpose:**
Constructor that initializes the graph with a given number of vertices and creates an empty adjacency matrix.

---

### b) `void addedge(int u, int v)`

**Purpose:**
Adds an undirected edge between vertex `u` and `v`.

**Process:**

* Sets `adjmatrix[u][v] = 1`
* Sets `adjmatrix[v][u] = 1`

---

### c) `void display()`

**Purpose:**
Displays the adjacency matrix of the graph.

---

### d) `void BFS(int start)`

**Purpose:**
Performs Breadth First Search starting from a given vertex.

**Algorithm:**

1. Mark the start vertex as visited.
2. Insert it into the queue.
3. While the queue is not empty:

   * Remove a vertex from the queue.
   * Visit all its unvisited adjacent vertices.
4. Continue until all reachable vertices are visited.

BFS explores vertices **level by level**.

---

### e) `void DFS(int start)`

**Purpose:**
Performs Depth First Search starting from a given vertex.

**Algorithm:**

1. Push the start vertex onto the stack.
2. While the stack is not empty:

   * Pop a vertex.
   * If not visited, mark it visited.
   * Push all its unvisited adjacent vertices onto the stack.
3. Continue until all reachable vertices are visited.

DFS explores vertices **deeply** before backtracking.

---

## 5. Overview of `main()` Function

The `main()` function:

1. Creates a graph with 7 vertices.
2. Adds edges to form the example graph.
3. Displays the adjacency matrix.
4. Performs BFS starting from vertex 0.
5. Performs DFS starting from vertex 0.

---

## 6. Example Graph Structure

Edges added:

* 0 — 1
* 0 — 2
* 1 — 3
* 1 — 4
* 2 — 5
* 2 — 6
* 3 — 4
* 5 — 6

---

## 7. Sample Output

Adjacency Matrix:

```
0 1 1 0 0 0 0
1 0 0 1 1 0 0
1 0 0 0 0 1 1
0 1 0 0 1 0 0
0 1 0 1 0 0 0
0 0 1 0 0 0 1
0 0 1 0 0 1 0
```

BFS

```
:BFS starting from vert0 :0 1 2 3 4 5 6
```

DFS

```
DFS from 0 0 1 3 4 2 5 6
```

---

## 8. Conclusion

* The program successfully demonstrates graph representation using an adjacency matrix.
* BFS and DFS traversals are implemented using queue and stack respectively.
* The example graph clearly shows how vertices are visited using both techniques.

This example highlights fundamental graph traversal algorithms used in many real-world applications.
