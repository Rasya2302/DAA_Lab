# DAA Lab-03 - Question 5
# Special-pattern matrix multiplication
# Validation of O(n^2) complexity

set title "Special-Pattern Matrix Multiplication: O(n^2)"
set xlabel "Matrix Size (n)"
set ylabel "Number of Scalar Multiplications"

set logscale x
set logscale y

set grid
set key left top

plot "result.txt" using 1:2 \
     with linespoints title "Actual Multiplications", \
     "result.txt" using 1:3 \
     with linespoints title "n^2"

pause -1
