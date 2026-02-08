Here is the **raw Markdown documentation** for your Dijkstra’s algorithm program. Save it as:

```
doc_7.md
```

---

# Documentation for Question 7

## Implementation of Dijkstra’s Algorithm for Shortest Path in a Weighted Graph

---

## 1. Problem Overview

This program implements **Dijkstra’s Algorithm** to find the **shortest distances** from a given source node to all other nodes in a **weighted, undirected graph**.

It uses a **priority queue** to efficiently select the next vertex with the minimum tentative distance, ensuring the algorithm runs efficiently.

---

## 2. Data Structures Used

### a) Graph Representation

The graph is represented using an **adjacency list**:

```cpp
unordered_map<int, vector<pair<int,int>>> graph;
```

* **Key**: Node number (integer)
* **Value**: Vector of pairs `(neighbor, weight)` representing edges and their weights.
* Example: `graph[0] = {{1, 4}, {2, 2}}` means node 0 connects to node 1 with weight 4 and node 2 with weight 2.

---

### b) Distance Map

```cpp
unordered_map<int,int> dist;
```

* Stores the shortest known distance from the source node to each vertex.
* Initialized to `INT_MAX` for all nodes except the source node, which is set to 0.

---

### c) Previous Node Map

```cpp
unordered_map<int,int> prev;
```

* Stores the previous node in the shortest path for each vertex.
* Used to reconstruct the shortest path if needed.
* Initialized to `-1` for all nodes.

---

### d) Priority Queue

```cpp
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
```

* Min-heap based on distance.
* Ensures the next node with the smallest tentative distance is selected efficiently.

---

## 3. Function Descriptions

### a) `void dijkstra(int start, unordered_map<int,int>& dist, unordered_map<int,int>& prev)`

**Purpose:**
Computes the shortest distance from `start` to all other nodes in the graph.

**Algorithm:**

1. Initialize the source node distance to 0 and push it into the priority queue.
2. While the priority queue is not empty:

   * Pop the node with the smallest distance (`current`).
   * Skip it if a shorter distance has already been recorded.
   * For each neighbor of `current`:

     * Compute new distance = `current distance + edge weight`.
     * If this is smaller than the recorded distance:

       * Update the distance.
       * Update the previous node.
       * Push the neighbor with updated distance into the priority queue.

**Key Concepts:**

* Greedy selection of the closest unvisited node.
* Updates distances and previous nodes iteratively.
* Efficient with a priority queue (`O((V + E) log V)`).

---

## 4. Overview of `main()` Function

1. Constructs the weighted graph using the adjacency list:

```cpp
graph[0]= {{1, 4}, {2, 2}};
graph[1]= {{0, 4}, {2, 1}, {3, 5}};
graph[2]= {{0, 2}, {1, 1}, {3, 8}, {4, 10}};
graph[3]= {{1, 5}, {2, 8}, {4, 2}, {5, 6}};
graph[4]= {{2, 10}, {3, 2}, {5, 3}};
graph[5]= {{3, 6}, {4, 3}};
```

2. Initializes distance and previous maps.
3. Calls `dijkstra(start, dist, prev)` with the starting node.
4. Prints the shortest distances from the source node to all other nodes.

---

## 5. Sample Output

Assuming the source node is `0`:

```
Shortest distances from node 0
  0: 0
  1: 3
  2: 2
  3: 8
  4: 10
  5: 13
```

---

## 6. Conclusion

* The program successfully implements **Dijkstra’s Algorithm** using a **priority queue** and adjacency list.
* It efficiently calculates shortest distances for weighted graphs with non-negative edges.
* The use of `prev` allows path reconstruction if required.
* This is a standard technique used in routing algorithms and network optimization problems.

---
