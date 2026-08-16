# DAA Lab-03 - Question 6
# Selection Sort and Loop Invariant
# Validation of Theta(n^2)

set title "Selection Sort: Loop Invariant Complexity"
set xlabel "Input Size (n)"
set ylabel "Number of Comparisons"

set logscale x
set logscale y

set grid
set key left top

plot "result.txt" using 1:2 \
     with linespoints title "Actual Comparisons", \
     "result.txt" using 1:3 \
     with linespoints title "n(n-1)/2"

pause -1
