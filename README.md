# ReadMe

## Summary
The NR (Numerical Recipes) repo is based on the famous Numerical Recipes book.
This is a personal implementation of selected peices for my own enjoyment.

## Linear Algebra (LA) - Chapter 2
### Core
The Core of the LA module includes a Matrix template class for integer, double, 
and complex Matrices.
### Solvers
The Solvers of the LA module include the following:
#### Gauss-Jordan Elimination (GJE)
GJE is for inverting a matrix, and is about as efficient as any other method. 
It provides *both* the solution of the linear equations provided for one or 
more right-hand side vectors *b*, and also the matrix inverse *A^-1*. It has
two major weaknesses, (i) it requires all the right-hand side vectors to be 
stored and manipulated at the same time, and (ii) that when the inverse matrix 
is not desired it is provided making it 3 times slower than the best alternative
technique for solving a single linear set. It's major strength is it's stability.
This method should not be the the first choice.
