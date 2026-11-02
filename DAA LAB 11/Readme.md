# DAA Lab 11 – Breadth First Search (BFS)

## 📌 About the Lab

This lab focuses on solving graph problems using different variations of the **Breadth First Search (BFS)** algorithm.

BFS is a graph traversal technique that explores vertices level by level. It uses a queue to visit neighbouring vertices before moving to the next level.

In this lab, we implement three important BFS techniques using the **C programming language**.

---

## 📝 List of Problems

### Q1. Shortest Path on Parity-Constrained Graphs

**Concepts Used:** 0-1 BFS, Graph Theory, Deque

**Description:**

Finds the shortest path in a graph where edges have weights of either 0 or 1, while satisfying the given parity constraint.

The 0-1 BFS algorithm uses a deque (double-ended queue):
- Weight 0 edges are added to the front.
- Weight 1 edges are added to the back.

This helps calculate the shortest path efficiently.

**Time Complexity:** O(V + E)

**Space Complexity:** O(V + E)

---

### Q2. Multi-Source BFS for Radius-Constrained Voronoi Cell Partitioning

**Concepts Used:** Multi-Source BFS, Graph Traversal, Connected Regions

**Description:**

Uses multiple starting vertices to perform BFS simultaneously. Each vertex is assigned to the nearest source within the given radius.

The algorithm helps divide a graph into regions based on the distance from multiple source vertices.

**Time Complexity:** O(V²) for the adjacency-matrix implementation.

**Space Complexity:** O(V²)

---

### Q3. Bidirectional BFS for Shortest Transformation Sequence in Word Graph

**Concepts Used:** Bidirectional BFS, Hashing, String Manipulation

**Description:**

Finds the shortest transformation sequence between two words.

Each transformation changes a word into another valid word according to the problem's transformation rules.

Bidirectional BFS searches from both the starting word and the target word simultaneously. When both searches meet, the shortest transformation sequence is obtained.

A hash table is used to store and search words efficiently.

**Time Complexity:** Depends on the number of words and the cost of generating neighbouring words.

**Space Complexity:** O(N) for storing the words and search information, excluding any explicitly constructed graph.

---

## 🛠️ Technologies Used

- **Programming Language:** C
- **Compiler:** GCC
- **Data Structures:** Queue, Deque, Hash Table, Graph
- **Algorithms:** BFS, 0-1 BFS, Multi-Source BFS, Bidirectional BFS

---
## 📂 Project Structure

```text
DAA-Lab-11/
│
├── q1.c
├── q2.c
├── q3.c
│
└── README.md
```

---

## 🎯 Learning Outcomes

After completing this lab, I learned:

- How Breadth First Search works in graph traversal.
- How to find shortest paths using 0-1 BFS.
- How to use a deque for efficient traversal.
- How Multi-Source BFS works with multiple starting vertices.
- How to divide a graph into regions based on distance.
- How Bidirectional BFS reduces the search space.
- How hashing helps in efficient word searching.
- How different BFS techniques solve real-world graph problems.

---

## 📖 Conclusion

This lab helped me understand different applications of Breadth First Search in graph algorithms.

By implementing 0-1 BFS, Multi-Source BFS, and Bidirectional BFS, I gained practical knowledge of shortest path problems, graph partitioning, and word transformation problems using the C programming language.