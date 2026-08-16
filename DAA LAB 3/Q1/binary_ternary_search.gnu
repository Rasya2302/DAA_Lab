# Q1
# Binary Search vs Ternary Search

set title "Binary Search vs Ternary Search"

set xlabel "Input Size (n)"

set ylabel "Number of Comparisons"

set grid

set key left top

plot "q1.txt" using 1:2 with linespoints \
     title "Binary Search", \
     "q1.txt" using 1:3 with linespoints \
     title "Ternary Search"


pause -1