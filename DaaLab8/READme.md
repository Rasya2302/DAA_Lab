# DAA Lab-08 – Dynamic Programming

## Design and Analysis of Algorithms

**Course:** B.Tech (CS-B & CE), 3rd Semester
**Lab:** Lab-08
**Date:** September 29, 2026
**Topic:** Dynamic Programming

---

## 📌 Objective

The objective of this lab is to understand and implement problems using the **Dynamic Programming** design paradigm.

The programs are implemented in **C language** and include algorithm validation and complexity analysis.

---

## 📝 Problems Covered

### 1. Minimum Coin Change

Given a set of coin denominations and a target amount, find the **minimum number of coins** required to make the target amount.

* Infinite supply of each coin is available.
* If the amount cannot be formed, return `-1`.
* **Technique:** Dynamic Programming
* **Time Complexity:** `O(n × V)`
* **Space Complexity:** `O(V)`

---

### 2. Coin Change – Total Number of Ways

Find the **total number of distinct combinations** of coins that can make a given target amount.

* Infinite supply of coins is available.
* Order of coins does not matter.
* Example: `1 + 2` and `2 + 1` are considered the same combination.
* **Technique:** Dynamic Programming
* **Time Complexity:** `O(n × V)`
* **Space Complexity:** `O(V)`

---

### 3. Longest Common Subsequence (LCS)

Given two sequences, find:

1. The length of their **Longest Common Subsequence**.
2. The actual LCS string.

* **Technique:** Dynamic Programming
* **Time Complexity:** `O(m × n)`
* **Space Complexity:** `O(m × n)`

---

### 4. Longest Increasing Subsequence (LIS)

Given an integer array, find the length of the longest subsequence in which every element is **strictly greater than the previous element**.

* **Technique:** Dynamic Programming
* **Time Complexity:** `O(n²)`
* **Space Complexity:** `O(n)`

---

### 5. Maximum Sum Increasing Subsequence

Find the **maximum possible sum** of a strictly increasing subsequence.

* The array contains positive integers.
* **Technique:** Dynamic Programming
* **Time Complexity:** `O(n²)`
* **Space Complexity:** `O(n)`

---

### 6. Edit Distance with Traceback

Given two strings, find the minimum number of operations required to transform one string into another.

Allowed operations:

* Insertion
* Deletion
* Substitution

The program also prints the **traceback information** showing the operations used.

* **Technique:** Dynamic Programming
* **Time Complexity:** `O(m × n)`
* **Space Complexity:** `O(m × n)`

---

### 7. Rod Cutting with Reconstruction

Given a rod of length `n` and prices for pieces of different lengths, determine:

1. Maximum revenue obtainable.
2. Exact lengths of pieces used in the optimal solution.

* Cuts are integral.
* The rod may also be left uncut.
* **Technique:** Dynamic Programming
* **Time Complexity:** `O(n²)`
* **Space Complexity:** `O(n)`

---

### 8. Optimal Binary Search Tree (OBST)

Given sorted keys, successful search probabilities, and unsuccessful search probabilities, construct an **Optimal Binary Search Tree** having minimum expected search cost.

* **Technique:** Dynamic Programming
* **Time Complexity:** `O(n³)`
* **Space Complexity:** `O(n²)`

---

### 9. Collatz Conjecture

The Collatz sequence is defined as:

* If `n` is even:
  `n = n / 2`
* If `n` is odd:
  `n = 3n + 1`

The process continues until `n = 1`.

The program analyzes the trajectory of user-provided starting values over an interval `[a, b]`.

> **Note:** The Collatz Conjecture is an open mathematical problem. It is conjectured that every positive integer eventually reaches `1`, but this has not been proven.

The assignment focuses on:

* Iterative control structures
* Functional decomposition
* Dynamic memory allocation
* Pointers
* Integer overflow handling
* Analysis of arithmetic trajectories

---

## 🛠️ Technologies Used

* **Language:** C
* **Concept:** Dynamic Programming
* **Compiler:** GCC / MinGW
* **IDE:** VS Code
* **Operating System:** Windows / Linux

---

## 📂 Suggested Project Structure

```text
DAA-Lab-08/
│
├── README.md
│
├── Q1_Minimum_Coin_Change.c
├── Q2_Coin_Change_Ways.c
├── Q3_LCS.c
├── Q4_LIS.c
├── Q5_Maximum_Sum_LIS.c
├── Q6_Edit_Distance.c
├── Q7_Rod_Cutting.c
├── Q8_OBST.c
└── Q9_Collatz.c
```

---

## ▶️ How to Compile and Run

### Compile

```bash
gcc Q1_Minimum_Coin_Change.c -o Q1
```

### Run

```bash
./Q1
```

For Windows:

```bash
Q1.exe
```

Similarly, compile and run the other programs.

---

## 📊 Complexity Summary

| Question | Problem                            |             Time Complexity |          Space Complexity |
| -------- | ---------------------------------- | --------------------------: | ------------------------: |
| Q1       | Minimum Coin Change                |                     `O(nV)` |                    `O(V)` |
| Q2       | Coin Change – Number of Ways       |                     `O(nV)` |                    `O(V)` |
| Q3       | LCS                                |                     `O(mn)` |                   `O(mn)` |
| Q4       | LIS                                |                     `O(n²)` |                    `O(n)` |
| Q5       | Maximum Sum Increasing Subsequence |                     `O(n²)` |                    `O(n)` |
| Q6       | Edit Distance                      |                     `O(mn)` |                   `O(mn)` |
| Q7       | Rod Cutting                        |                     `O(n²)` |                    `O(n)` |
| Q8       | Optimal BST                        |                     `O(n³)` |                   `O(n²)` |
| Q9       | Collatz                            | Depends on trajectory/input | Depends on implementation |

---

## 🎯 Learning Outcomes

After completing this lab, we understand:

* How **Dynamic Programming** works.
* How to identify overlapping subproblems.
* How to use **memoization and tabulation**.
* How to reconstruct solutions from DP tables.
* How to analyze **time and space complexity**.
* How to implement algorithms using C.
* How to handle dynamic memory and pointers.
* How to analyze the Collatz sequence computationally.

---

## 👨‍💻 Author

**DAA Lab-08 Assignment**

B.Tech – 3rd Semester
