Strassen’s algorithm for matrix multiplication

If A and B are square nxn matrices, then in the product C = A ⋅ B, is defined

entry Cij for i,j = 1,2, ..., n by
       n
Cij =  ∑ Aik*Bik
      k-1


SQUARE-MATRIX-MULTIPLY(A,B)
  n = A.rows
  let C be a new n x n matrix
  for i = 1 to n
    for j = 1 to n
      cij = 0
      for k = 1 to n
        cij = cij + aik * bij

  return C

Because each of the triply-nested for loops runs exactly n iterations, and each execution of line 7 takes constant time, the SQUARE-MATRIX-MULTIPLY procedure takes Θ(n^3) time.



You might at first think that any matrix multiplication algorithm must take Θ(n^3) time, since the natural definition of matrix multiplication requires that many multiplications. You would be incorrect, however: we have a way to multiply matrices in o(n^3) time.

Strassen’s remarkable recursive algorithm for multiplying nxn matrices. It runs in O(n^lg(7)) time
Since lg 7 lies between 2.80 and 2.81, Strassen’s algorithm runs in O(n^2.81) time





## A simple divide-and-conquer algorithm

To keep things simple, when we use a divide-and-conquer algorithm to compute the matrix product C = A ⋅ B,
we assume that n is an exact power of 2 in each of the n x n matrices.
We make this assumption in each divide step, we will divide n x n matrices into four n/ 2 x n/2 matrices, and by assuming that n is an exact power of 2, we are guaranteed that as long as n % 2, the dimension n/2 is an integer.
Suppose that we partition each of A, B, and C into four n /2 x n/2 matrices

C11 C12 = A11 A12 + B11 B12
C21 C22   A21 A22 + B21 B22


C11 = A11 * B11 + A12 * B21
C12 = A11 * B12 + A12 * B22
C21 = A21 * B11 + A22 * B21
C22 = A21 * B12 + A22 * B22

Each of these four equations specifies two multiplications of n/2 x n /2 matrices and the addition of their n/2 x n/2 products. We can use these equations to create a straightforward, recursive, divide-and-conquer algorithm:

SQUARE-MATRIX-MULTIPLY-RECURSIVE(A, B)
  n = A.rows
  let C[n][n]
  if n == 1
    C[1][1] = A[1][1] * B[1][1]
  else
    C[1][1] = SQUARE-MATRIX-MULTIPLY-RECURSIVE(A[1][1], B[1][1]) +
              SQUARE-MATRIX-MULTIPLY-RECURSIVE(A[1][2], B[2][2])

    C[1][2] = SQUARE-MATRIX-MULTIPLY-RECURSIVE(A[1][1], B[1][2]) +
              SQUARE-MATRIX-MULTIPLY-RECURSIVE(A[1][2], B[2][2])

    C[2][1] = SQUARE-MATRIX-MULTIPLY-RECURSIVE(A[2][1], B[1][1]) +
              SQUARE-MATRIX-MULTIPLY-RECURSIVE(A[2][2], B[2][1])

    C[2][2] = SQUARE-MATRIX-MULTIPLY-RECURSIVE(A[2][1], B[1][2]) +
              SQUARE-MATRIX-MULTIPLY-RECURSIVE(A[2][2], B[2][2])

Return C

This pseudocode glosses over one subtle but important implementation detail.
How do we partition the matrices in line 5?
If we were to create 12 new n/2 x n/2 matrices, we would spend Θ(n^2) time copying entries. In fact, we can partition the matrices without copying entries.

The trick is to use index calculations. We identify a submatrix by a range of row indices and a range of column indices of the original matrix. We end up representing a submatrix a little differently from how we represent the original matrix, which is the subtlety we are glossing over.

The advantage is that, since we can specify submatrices by index calculations,
executing line 5 takes only Θ(1) time (although we shall see that it makes no
difference asymptotically to the overall running time whether we copy or partition in place).

Now, we derive a recurrence to characterize the running time Of SQUARE-
MATRIX-MULTIPLY-RECURSIVE. Let T(n) be the time to multiply two n x n
matrices using this procedure. In the base case, when n = 1, we perform just the
one scalar multiplication in line 4, and so

T(1) = Θ(1)
The recursive case occurs when n > 1. As discussed, partitioning the matrices in
line 5 takes Θ(1) time, using index calculations. In lines 6—9, we recursively call SQUARE-MATRIX-MULTIPLY-RECURSIVE a total of eight times. Because each
recursive call multiplies two n/2 x n/2 matrices, thereby contributing T(n/ 2) to the overall running time, the time taken by all eight recursive calls is 8T(n/2).
We also must account for the four matrix additions in lines 6—9. Each of these matrices contains n^2/4 entries, and so each of the four matrix additions takes Θ(n^2) time.
Since the number Of matrix additions is a constant, the total time spent adding matrices in lines 6—9 is Θ(n^2) (Again, we use index calculations to place the results of the matrix additions into the correct positions of matrix C, with an overhead Of Θ(1) time per entry) The total time for the recursive case, therefore, is the sum of the partitioning time, the time for all the recursive calls, and the time to add the
matrices resulting from the recursive calls:

T(n) = Θ(1) + 8T(n/2) + Θ(n^2)
       8T(n/2) + Θ(n^2)



As we shall see from the master method, this recurrence has the
solution T (n) = Θ(n^3) Thus, this simple divide-and-conquer approach is no
faster than the straightforward SQUARE-MATRIX-MULTIPLY procedure.

Partitioning each n x n matrix by index calculation takes time Θ(1), but we have two matrices to partition. Although you could say that partitioning the two matrices takes Θ(2) time, the constant of 2 is subsumed by the Θ-notation.

Adding two matrices, each with, say, k entries, takes Θ(k) time.
Since the matrices we add each have n^2/4 entries, you could say that adding each pair takes Θ(n^2/4) time.
Again, however, the Θ-notation subsumes the constant factor Of 1/4, and we say that adding two n/ 2 x n/ 2 matrices takes Θ(n^2) time.
We have four such matrix additions, and once again, instead Of saying that they take Θ(4n^2) time, we say that they take Θ(n^2) time.

(Of course, you might observe that we could say that the four matrix additions take Θ(4n^2 / 4) time, and that 4n^2/4 = n 2, but the point here is that Θ-notation
subsumes constant factors, whatever they are.)

When we account for the eight recursive calls, however, we cannot just subsume the constant factor of 8.
In other words, we must say that together they take 8T(n/2) time, rather than just T(n/ 2) time. You can get a feel for why by looking back at the recursion tree in Figure 2.5, for recurrence (2.1) (which is identical to recurrence (4.7)), with the recursive case T(n) = 2T(n/2) + Θ(n) — The factor of 2 determined how many children each tree node had, which in turn determined how many terms contributed to the sum at each level Of the tree. If we were to ignore the factor Of 8 in equation (4.16) or the factor Of 2 in recurrence (4.1 the recursion tree would just be linear, rather than "bushy," and each level would contribute only one term to the sum.
Bear in mind, therefore, that although asymptotic notation subsumes constant
multiplicative factors, recursive notation such as T (n/ 2) does not.
