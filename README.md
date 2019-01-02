# little_Cpp-projects
Some little projects in C++ wrote between 2016 and 2017

-Last year, I have been involved in some simple projects concerning the
implementation of some algorithms. For instance, I wrote a customized C++ matrix
class having two different methods for calculating the determinant of a square
matrix: one by the Leibniz formula, and the other one by the LU decomposition.
The former method is inefficient for large matrixes because of its factorial
computational complexity. Indeed, the time needed to solve 12x12 or larger
matrixes is over 15 minutes. Nevertheless, this issue led me to study the
time-computation development depending on the matrix order, confirming the
expected factorial trend.
The latter method, which uses the LU decomposition, works well for 32x32 or
smaller matrixes, but as the order increases, rounding errors affect the result,
presumably because of the accumulation of floating point rounding errors in the
large number of calculations.

-Recently, I was also asked by some colleagues to conduct a survey on Bachelors
students who want to remain at my University for a Masters Degree in Physics next
year. After conducting the survey on a 20-person sample, I processed the data with
a simple C++ program which calculates the probability distribution of the number of
students enrolled at my University next year. For completeness, I also fitted a
Gaussian distribution, finding a good match between the two distributions.

