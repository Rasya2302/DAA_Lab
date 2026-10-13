# DAA Lab-09: Greedy Design Paradigm

This repository contains 10 separate C programs based on the questions in **Design and Analysis of Algorithms (DAA), Lab-09**.

## Contents

| No. | File | Problem | Main technique |
|---:|---|---|---|
| 1 | `Q1_fractional_knapsack_decay.c` | Fractional Knapsack with Deterioration Rate | Greedy simulation |
| 2 | `Q2_huffman_canonical.c` | Huffman Coding | Huffman tree and canonical code assignment |
| 3 | `Q3_minimum_fuel_stops.c` | Minimum Refuelling Stops | Max-heap |
| 4 | `Q4_minimum_cost_connect_sticks.c` | Minimum Cost to Connect Sticks | Min-heap |
| 5 | `Q5_candy_distribution.c` | Candy Distribution | Two-pass greedy |
| 6 | `Q6_reorganize_string_k_distance.c` | Reorganise String with K-Distance Apart | Max-heap and cooldown queue |
| 7 | `Q7_minimize_deviation.c` | Minimise Deviation in Array | Max-heap |
| 8 | `Q8_minimum_meeting_rooms.c` | Minimum Number of Meeting Rooms | Sorting and two pointers |
| 9 | `Q9_alphabetic_adjacent_merge_simulation.c` | Hu-Tucker Greedy Simulation | Adjacent merge simulation |
| 10 | `Q10_greedy_superstring.c` | Greedy Shortest Superstring | Maximum-overlap merging |

## Requirements

- A C compiler such as GCC.
- A terminal or command prompt.
- Standard C library.

## Compile and run

Compile a program with GCC:

```bash
gcc Q5_candy_distribution.c -o candy
```

Run on Linux/macOS:

```bash
./candy
```

On Windows with MinGW:

```bash
gcc Q5_candy_distribution.c -o candy.exe
candy.exe
```

Replace the filename and output name with the program you want to run. Each `.c` file has its own `main()` function, so compile and run each program separately.

## Program descriptions

### 1. Fractional Knapsack with Deterioration Rate

**Input:** Number of items, each item's base value, weight and decay rate, then knapsack capacity.

**Idea:** At each selection step, calculate the current effective density:

`value / remaining_weight - decay_rate * time`

and choose the remaining item with the highest positive density. The program advances time by one unit after each selection.

**Complexity:** `O(n^2)` time and `O(n)` space.

**Limitation:** The problem statement does not define precisely how consumption duration and time evolve for fractional selections. This program is a greedy simulation under the one-time-unit-per-selection assumption, not a proof of global optimality for every interpretation of the problem.

### 2. Huffman Coding

**Input:** Number of symbols, followed by one positive frequency for each symbol. The program uses symbol indices `0, 1, 2, ...` as labels.

**Idea:** Repeatedly combine the two least-frequent nodes to build a Huffman tree, then assign canonical binary codes ordered by code length and symbol index.

**Complexity:** The simple tree construction uses `O(n^2)` time; storage is `O(n)` for the supported input range.

**Note:** When frequencies tie, multiple optimal Huffman trees may exist. The particular tie-breaking rule can affect code lengths assigned to individual symbols. Canonical assignment standardizes the code representation after lengths are chosen.

### 3. Minimum Refuelling Stops

**Input:** Number of stations, each station's distance from the origin and fuel amount, then destination distance and initial fuel.

**Idea:** Sort stations by distance. Whenever current fuel cannot reach the destination, take the largest fuel amount among stations already reachable, using a max-heap.

**Complexity:** `O(n log n)` time, including sorting and heap operations; `O(n)` space.

**Assumption:** Fuel units correspond to distance units, and each station can be used at most once.

### 4. Minimum Cost to Connect Sticks

**Input:** Number of sticks, followed by their non-negative lengths.

**Idea:** Repeatedly combine the two shortest sticks, add their sum to the total cost, and insert the combined stick back into a min-heap.

**Complexity:** `O(n log n)` time and `O(n)` space.

### 5. Candy Distribution

**Input:** Number of children, followed by their ratings.

**Idea:** Give every child one candy. Make a left-to-right pass to satisfy increasing ratings, then a right-to-left pass to satisfy decreasing ratings while preserving larger allocations with `max`-style updates.

**Output:** Candy count for each child and the minimum total.

**Complexity:** `O(n)` time and `O(n)` space.

### 6. Reorganise String with K-Distance Apart

**Input:** A string without spaces and integer `K`.

**Idea:** Choose the most frequent currently available character using a max-heap, and keep used characters unavailable until their cooldown has passed.

**Output:** A rearranged string or `Impossible`.

**Complexity:** For the fixed 256-character ASCII alphabet, heap operations are bounded by a constant alphabet size, so runtime is effectively `O(n)`; space is `O(n)` for the result and waiting data.

**Distance convention:** The implementation enforces at least `K` positions between equal-character placements as a separation in output indices; if your course defines distance as the absolute index difference, verify whether it expects `K` or `K-1` intervening positions.

### 7. Minimise Deviation in an Array

**Input:** Number of positive integers, followed by the integers.

**Idea:** Double each odd number once. Then repeatedly halve the current maximum while it is even, tracking the smallest value and the best deviation.

**Complexity:** `O(n log n)` time for heap construction and updates, with `O(n)` space.

**Note:** Use values small enough that doubling and sums do not overflow the chosen integer type.

### 8. Minimum Number of Meeting Rooms

**Input:** Number of meetings, then each meeting's start and end time.

**Idea:** Sort all start times and end times. Use two pointers to count concurrent meetings and track the maximum number of rooms required.

**Complexity:** `O(n log n)` time and `O(n)` space.

**Endpoint convention:** This implementation treats a meeting ending at time `t` as freeing a room for a meeting starting at time `t` (`[start, end)` convention).

### 9. Hu-Tucker Greedy Simulation

**Input:** Number of ordered weights, followed by the weights.

**Idea:** Repeatedly merge the least-cost adjacent pair, preserving the sequence order.

**Complexity:** `O(n^2)` time and `O(n)` space.

**Important limitation:** This is an educational adjacent-merge simulation, **not the full Hu-Tucker algorithm** and is not guaranteed to produce an optimal alphabetic tree. The full Hu-Tucker algorithm requires additional compatibility and level-management steps.

### 10. Greedy Shortest Superstring

**Input:** Number of strings, followed by strings without spaces.

**Idea:** Merge strings using suffix-prefix overlap, preferring a pair with maximum overlap. Strings already contained in another input string may be removed first.

**Purpose:** Demonstrates the maximum-overlap greedy heuristic.

**Limitation:** This heuristic is not guaranteed to produce the shortest possible superstring. The implementation uses fixed-size buffers; very long inputs may exceed the supported buffer size.

## Complexity summary

| No. | Algorithm | Time complexity | Auxiliary space |
|---:|---|---:|---:|
| 1 | Fractional knapsack decay simulation | `O(n^2)` | `O(n)` |
| 2 | Huffman / canonical code assignment | `O(n^2)` | `O(n)` |
| 3 | Minimum refuelling stops | `O(n log n)` | `O(n)` |
| 4 | Connect sticks | `O(n log n)` | `O(n)` |
| 5 | Candy distribution | `O(n)` | `O(n)` |
| 6 | Reorganise string, fixed alphabet | `O(n)` effectively | `O(n)` |
| 7 | Minimise deviation | `O(n log n)` | `O(n)` |
| 8 | Meeting rooms | `O(n log n)` | `O(n)` |
| 9 | Adjacent-merge simulation | `O(n^2)` | `O(n)` |
| 10 | Greedy superstring heuristic | Roughly `O(n^3 L)` in a straightforward bound, where `L` is the maximum string length | Depends on total merged string size |

## Suggested test cases

### Candy distribution
```text
5
1 2 3 2 1
```
Expected candy allocation: `1 2 3 2 1`; total: `9`.

### Connect sticks
```text
3
2 3 4
```
Expected minimum total cost: `14`.

### Meeting rooms
```text
3
0 30
5 10
15 20
```
Expected number of rooms: `2`.

### Minimum deviation
```text
4
1 2 3 4
```
Expected minimum deviation: `1`.

## Academic note

These programs are intended for learning and lab practice. For questions whose statement leaves important assumptions unspecified, or whose full algorithm is more advanced than a simple greedy simulation, check the limitations above and confirm the required interpretation with your instructor before claiming optimality.
