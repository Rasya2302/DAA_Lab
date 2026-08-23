# Design and Analysis of Algorithms (DAA) – Lab 04



This README contains the **algorithms, approaches, and complexity analysis only** for all six questions from DAA Lab-04.


# Table of Contents

1. [Question 1 – Sort Items by Colour](#question-1--sort-items-by-colour)
2. [Question 2 – Pair Sum from Two Sets](#question-2--pair-sum-from-two-sets)
3. [Question 3 – k Elements with Sum T](#question-3--k-elements-with-sum-t)
4. [Question 4 – Maximum People Simultaneously Present](#question-4--maximum-people-simultaneously-present)
5. [Question 5 – Merge Overlapping Intervals](#question-5--merge-overlapping-intervals)
6. [Question 6 – Point in Maximum Number of Intervals](#question-6--point-in-maximum-number-of-intervals)
7. [Complexity Summary](#complexity-summary)

---

# Question 1 – Sort Items by Colour

## Problem

We are given `n` pairs:

```text
(number, colour)
```

The colour is one of:

- Red
- Blue
- Yellow

The input is already sorted by number.

We need to arrange the pairs as:

```text
Red → Blue → Yellow
```

while preserving the increasing order of numbers within each colour.

### Example

Input:

```text
(1,R) (2,B) (3,R) (4,Y) (5,B) (6,Y)
```

Output:

```text
(1,R) (3,R) (2,B) (5,B) (4,Y) (6,Y)
```

## Algorithm

1. Create three separate lists:
   - `Red`
   - `Blue`
   - `Yellow`
2. Traverse the input from left to right.
3. If the colour is Red, append the pair to the Red list.
4. If the colour is Blue, append the pair to the Blue list.
5. If the colour is Yellow, append the pair to the Yellow list.
6. Output the Red list first.
7. Output the Blue list second.
8. Output the Yellow list last.

Because the input is already sorted by number, each individual colour list automatically remains sorted by number.

## Complexity

```text
Time  : O(n)
Space : O(n)
```

---

# Question 2 – Pair Sum from Two Sets

## Problem

Given two sets `S1` and `S2`, each containing `n` elements, and an integer `x`, determine whether there exist:

```text
a ∈ S1
b ∈ S2
```

such that:

```text
a + b = x
```

Required complexity:

```text
O(n log n)
```

## Algorithm

1. Sort `S2` using Merge Sort.
2. Traverse every element `a` of `S1`.
3. For the current element, calculate:
   ```text
   required = x - a
   ```
4. Perform Binary Search for `required` in sorted `S2`.
5. If Binary Search finds `required`, then:
   ```text
   a + required = x
   ```
   so return `YES`.
6. If all elements of `S1` are checked and no pair is found, return `NO`.

### Example

```text
S1 = {2, 8, 10}
S2 = {1, 4, 7}
x = 9
```

For `a = 2`:

```text
required = 9 - 2
         = 7
```

Since `7` exists in `S2`:

```text
2 + 7 = 9
```

Therefore the answer is `YES`.

## Complexity

Merge Sort:

```text
O(n log n)
```

Binary Search for every element:

```text
O(n log n)
```

Overall:

```text
O(n log n)
```

Space:

```text
O(n)
```

---

# Question 3 – k Elements with Sum T

## Problem

Given a set `S` of `n` integers, an integer `T`, and an integer `k`, determine whether `k` elements of `S` add up to `T`.

Required complexity:

```text
O(n^(k-1) log n)
```

## Algorithm

1. Sort the set `S`.
2. Select the first element.
3. Recursively select elements until `k-1` elements have been selected.
4. Keep track of the sum of the selected elements.
5. After selecting `k-1` elements, calculate:
   ```text
   required = T - current_sum
   ```
6. Perform Binary Search for `required` in the remaining sorted elements.
7. If found, return `YES`.
8. Otherwise, continue checking other combinations.
9. If no combination produces `T`, return `NO`.

### Example

```text
S = {2, 4, 5, 7, 9}
k = 3
T = 16
```

Choose:

```text
2 + 5
```

Then:

```text
required = 16 - 2 - 5
         = 9
```

`9` exists, therefore:

```text
2 + 5 + 9 = 16
```

Answer:

```text
YES
```

## Complexity

Selecting `k-1` elements:

```text
O(n^(k-1))
```

Binary Search:

```text
O(log n)
```

Overall:

```text
O(n^(k-1) log n)
```

Space:

```text
O(n + k)
```

---

# Question 4 – Maximum People Simultaneously Present

## Problem

For each person, we are given:

```text
Entry time = ai
Exit time  = bi
```

We need to determine the time when the maximum number of people were simultaneously present.

All entry and exit times are distinct.

Required complexity:

```text
O(n log n)
```

## Algorithm – Event Sorting / Sweep Line

For every person, create two events:

```text
Entry → +1
Exit  → -1
```

### Example

Suppose:

```text
Person 1: 1 → 5
Person 2: 2 → 6
Person 3: 4 → 8
```

Create:

```text
1 Entry
2 Entry
4 Entry
5 Exit
6 Exit
8 Exit
```

Then:

1. Sort all events by time.
2. Initialize:
   ```text
   current = 0
   maximum = 0
   ```
3. Traverse events from earliest to latest.
4. For an Entry event:
   ```text
   current = current + 1
   ```
5. For an Exit event:
   ```text
   current = current - 1
   ```
6. Whenever:
   ```text
   current > maximum
   ```
   update:
   ```text
   maximum = current
   maxTime = current event time
   ```
7. After processing all events, `maxTime` is the required time.

## Complexity

There are `2n` events.

Sorting:

```text
O(2n log(2n)) = O(n log n)
```

Sweep:

```text
O(n)
```

Overall:

```text
O(n log n)
```

Space:

```text
O(n)
```

---

# Question 5 – Merge Overlapping Intervals

## Problem

Given a list of intervals:

```text
(xi, yi)
```

merge all overlapping intervals.

Example:

```text
{(1,3), (2,6), (8,10), (7,18)}
```

Output:

```text
{(1,6), (7,18)}
```

Required worst-case complexity:

```text
O(n log n)
```

## Algorithm

### Step 1 – Sort

Sort all intervals according to their starting point.

For example:

```text
(1,3)
(2,6)
(7,18)
(8,10)
```

### Step 2 – Initialize

Take the first interval as the current interval:

```text
current = first interval
```

### Step 3 – Compare

For every next interval:

If:

```text
next.start <= current.end
```

then the intervals overlap.

Merge them by:

```text
current.end = max(current.end, next.end)
```

Otherwise:

1. Store the current interval.
2. Make the next interval the new current interval.

### Step 4 – Finish

After processing all intervals, store the final current interval.

## Example

Starting with:

```text
(1,3)
```

Compare with:

```text
(2,6)
```

Since:

```text
2 <= 3
```

merge:

```text
(1,6)
```

Next:

```text
(7,18)
```

Since:

```text
7 > 6
```

there is no overlap.

Start a new interval:

```text
(7,18)
```

Finally:

```text
(8,10)
```

overlaps with `(7,18)`, so the result remains:

```text
(1,6)
(7,18)
```

## Complexity

Sorting:

```text
O(n log n)
```

Merging:

```text
O(n)
```

Overall:

```text
O(n log n)
```

Space:

```text
O(n)
```

---

# Question 6 – Point in Maximum Number of Intervals

## Problem

Given `n` intervals:

```text
(li, ri)
```

find a point `p` that belongs to the largest possible number of intervals.

The question states that an endpoint counts as being inside its interval.

Example:

```text
(10,40)
(20,60)
(50,90)
(15,70)
```

A valid maximum-overlap point is:

```text
p = 50
```

which belongs to three intervals.

Required complexity:

```text
O(n log n)
```

## Algorithm – Sweep Line

For every interval:

```text
(l, r)
```

create two events:

```text
(l, +1)   → Start
(r, -1)   → End
```

### Important Endpoint Rule

Because endpoints count as being inside the interval, if a Start and End occur at the same coordinate:

```text
Start must be processed before End
```

For example:

```text
(1,5)
(5,10)
```

At:

```text
p = 5
```

both intervals contain the point.

Therefore the Start event at `5` must be processed before the End event at `5`.

## Steps

1. Create two events for every interval.
2. Sort all events by coordinate.
3. If two events have the same coordinate, put Start before End.
4. Initialize:
   ```text
   current = 0
   maximum = 0
   ```
5. Traverse the sorted events.
6. For Start:
   ```text
   current = current + 1
   ```
7. For End:
   ```text
   current = current - 1
   ```
8. Whenever:
   ```text
   current > maximum
   ```
   update:
   ```text
   maximum = current
   answerPoint = current coordinate
   ```
9. Return `answerPoint` and `maximum`.

## Complexity

There are `2n` events.

Sorting:

```text
O(2n log(2n)) = O(n log n)
```

Sweep:

```text
O(n)
```

Overall:

```text
O(n log n)
```

Space:

```text
O(n)
```

---

# Complexity Summary

| Question | Main Technique | Time Complexity | Space Complexity |
|---|---|---:|---:|
| Q1 | Three-way distribution | **O(n)** | O(n) |
| Q2 | Merge Sort + Binary Search | **O(n log n)** | O(n) |
| Q3 | Recursive selection + Binary Search | **O(n^(k-1) log n)** | O(n + k) |
| Q4 | Event Sorting + Sweep Line | **O(n log n)** | O(n) |
| Q5 | Merge Sort + Interval Merge | **O(n log n)** | O(n) |
| Q6 | Event Sorting + Sweep Line | **O(n log n)** | O(n) |

---

# Key Concepts Used

## 1. Sorting

Sorting makes many problems easier by putting data into an ordered form.

Used in:

```text
Q2, Q3, Q4, Q5, Q6
```

## 2. Binary Search

Binary Search searches a sorted array in:

```text
O(log n)
```

Used in:

```text
Q2, Q3
```

## 3. Sweep Line

Sweep Line processes events from left to right while maintaining the current count or state.

Used in:

```text
Q4, Q6
```

## 4. Interval Merging

After sorting intervals by their starting points, overlapping intervals can be merged in one linear scan.

Used in:

```text
Q5
```

---

# Final Pattern

```text
                         SORTING
                            |
          +-----------------+-----------------+
          |                 |                 |
     Binary Search      Sweep Line       Intervals
          |                 |                 |
       Q2, Q3            Q4, Q6               Q5
          |
       Merge Sort
```

All algorithms above follow the complexity requirements stated in the DAA Lab-04 question sheet.
