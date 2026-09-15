# DAA Lab-07 – Algorithm Applications Based on Puzzles

## Course Information

* **Course:** Design and Analysis of Algorithm (DAA)
* **Lab:** Lab-07
* **Semester:** 3rd Semester
* **Program:** BTech (CS-B and CE)
* **Date:** September 8, 2026
* **Instructor:** Dr. Ajaya Kumar Dash

## Objective

This lab focuses on designing algorithms for puzzle-based problems, implementing the algorithms in C, validating the solutions using suitable inputs, and analyzing their time and space complexity.

## Problems Covered

### Q1. Invert the Coin-Triangle

Design an algorithm to flip an equilateral triangle of closely packed coins upside down using the minimum number of moves. In each move, one coin can be slid to a new position.

**Tasks:**

* Find the minimum number of moves.
* Derive a compact formula for the minimum moves.
* Implement the algorithm in C.
* Validate the procedure.
* Analyze the complexity.

### Q2. Super Egg Testing Experiment

Determine the highest floor in a 100-storey building from which a super-strong egg can fall without breaking, using two identical eggs.

**Tasks:**

* Find the minimum number of droppings guaranteed to determine the highest safe floor.
* Develop a generalized Dynamic Programming solution for `E` eggs and `F` floors.
* Implement the algorithm in C.
* Validate the solution.
* Analyze the complexity.

### Q3. Reve's Puzzle

Reve's Puzzle is a four-peg version of the Tower of Hanoi problem. Eight disks of different sizes are initially placed on the first peg, with the largest disk at the bottom.

**Tasks:**

* Develop an algorithm that solves the eight-disk puzzle in 33 moves.
* Generalize the solution for `n` disks.
* Implement the algorithm in C.
* Validate the procedure.
* Analyze the complexity.

### Q4. Security Switches

There are `n` security switches, initially all turned on. The switches can be toggled according to specific rules, and only one switch can be toggled at a time.

**Tasks:**

* Design an algorithm to turn all switches off.
* Find the minimum number of moves.
* Follow all given switching rules.
* Implement the algorithm in C.
* Validate the solution.
* Analyze the complexity.

### Q5. Hitting a Moving Target

A shooter must hit a target that can hide in any of `n > 1` positions arranged along a straight line. The target moves to an adjacent position between consecutive shots.

**Tasks:**

* Design an algorithm that guarantees hitting the target, if possible.
* If no guaranteed strategy exists, prove it.
* Implement the solution in C if applicable.
* Validate the algorithm.
* Analyze the complexity.

### Q6. The Best Time to Be Alive

Find the time when the largest number of prominent scientists were alive. The input contains the birth and death years of scientists.

**Important Condition:**

If one scientist died in the same year another scientist was born, the death is considered to have occurred before the birth.

**Tasks:**

* Design an appropriate algorithm.
* Use the given index information as input.
* Find the year with the maximum number of scientists alive.
* Implement the solution in C.
* Validate the algorithm.
* Analyze the complexity.

### Q7. Matrix Chain Multiplication (MCM)

Implement the Dynamic Programming solution for the Matrix Chain Multiplication problem.

**Tasks:**

* Find the minimum number of scalar multiplications.
* Find the corresponding optimal ordering/parenthesization.
* Implement the solution in C.
* Analyze the complexity.

## Project Structure

```text
DAA-Lab-07/
│
├── README.md
│
├── Q1_Coin_Triangle.c
├── Q2_Super_Egg_Testing.c
├── Q3_Reves_Puzzle.c
├── Q4_Security_Switches.c
├── Q5_Moving_Target.c
├── Q6_Best_Time_To_Be_Alive.c
└── Q7_Matrix_Chain_Multiplication.c
```

## How to Compile and Run

The programs can be compiled using GCC.

### Example for Q1

```bash
gcc Q1_Coin_Triangle.c -o Q1
./Q1
```

### Example for Q2

```bash
gcc Q2_Super_Egg_Testing.c -o Q2
./Q2
```

The same procedure can be followed for Q3, Q4, Q5, Q6, and Q7.

## Concepts Used

* Algorithm Design
* Complexity Analysis
* Dynamic Programming
* Recursion
* Optimization
* Puzzle-Based Problem Solving
* Minimum-Move Problems
* C Programming
* Mathematical Analysis
* Algorithm Validation

## Complexity Analysis

For each problem, the following should be analyzed:

### Time Complexity

Determines how the running time of the algorithm increases with the input size.

### Space Complexity

Determines how much additional memory is required by the algorithm.

## Learning Outcomes

After completing this lab, students should be able to:

1. Convert puzzle statements into algorithmic problems.
2. Design algorithms for different constraints.
3. Apply Dynamic Programming to optimization problems.
4. Use recursion where appropriate.
5. Determine whether a guaranteed solution exists.
6. Implement algorithms using C.
7. Test and validate algorithms using suitable inputs.
8. Analyze time and space complexity.

## Conclusion

DAA Lab-07 provides practical experience in solving challenging algorithmic problems based on puzzles. The problems cover optimization, recursion, Dynamic Programming, algorithm validation, and complexity analysis.

The lab helps develop logical thinking and the ability to convert real-world or puzzle-based problems into efficient computational algorithms.
