Dynamic programming can be thought of as the art of solving simple problems first

Dynamic programming (DP) solves intricate problems by breaking them down into simpler components.

DP can be applied to problems exhibiting two properties:
overlapping subproblems
optimal substructure

Overlapping subproblems means that any recursive algorithm solving the problem should solve the same subproblems over and over, rather than generating new subproblems.

Optimal substructure means that any optimal solution can be constructed efficiently from the optimal solutions of its subproblems.

In other words, suppose that each subproblem has its own cost function:
the optimal substructure implies that the minima of each of these cost functions can be found as the minima of the global cost function restricted to the same subsets.

DP pursues to solve each subproblem only once.
After the solution to a given subproblem has been computed, it is stored in a table or "memoized".

Next time the same solution is required, it is simply looked up. DP solves problems in either two methods:

Top-down approach:
This is a consequence of the recursive mathematical definition associated to many DP problems.

Bottom-up approach:
This requires a reformulation of the recursive mathematical definition where subproblems are solved first and their solutions used to build-on and achieve
solutions for bigger subproblems


1. Fibonacci numbers

Solution
The first two numbers in the Fibonacci sequence are 0 and 1, and each subsequent number is the sum of the previous two. By describing the numbers in his book Liber Abaci, Leonardo Fibonacci introduced the sequence to Western European mathematics in 1200, although the sequence had been described
earlier in Indian mathematics.
Fibonacci numbers are mathematically defined as

f(n) = f(n-1) + f(n-2)

where n0 = 0 and n1 = 1

Code
It is trivial to write a recursive solution directly derived from the mathematical formulation. Here we provide an implementation where Fibonacci is computed at compile time leveraging the power of templates.

template <int N>
struct CTFibonacci {
	static constexpr int value() {
		return CTFibonacci<N-1>::value() + CTFibonacci<N-2>::value();
	}
};

template <>
struct CTFibonacci<1> {
	static constexpr int value() {
		return 1;
	}
};

template <>struct CTFibonacci<0> {
	static constexpr int value() {
		return 0;
	}
};

Complexity
Complexity is here exponential

An alternative and more efficient solution memorizes the intermediate results and it avoids to recompute the same sub-problem for multiple times:

unsigned int Fibonacci(unsigned int n)
{
	int a = 0, b = 1, sum = a + b;

	if (n <= 1)
		return n;

	for (unsigned int i = 2; i < n; ++i)
	{
		a = b;
		b = sum;
		sum = a + b;
	}
	return sum;
}

Complexity

Linear in time and constant in space



2. Binomial Coefficient

The binomial coefficient indexed by n and k and denoted by (n/k) is the coefficient of the x^k term in the polynomial expansion of the binomial power (1 + x)^n.

The value of this coefficient is given by:

	n! / k!(n - k)!

Solution
Computing the binomial coefficient directly from the closed formula would be inefficient. However, we can prove by induction that = and we know that and
. Therefore, we have a direct way to compute the binomial
coefficient with dynamic programming. Note that Matrix is a class
defined in the appendix.
Code
unsigned int bin(unsigned int n, unsigned int k,
Matrix<int> & table)
{
std::cout << "n=" << n << " k=" << k << std::endl;
if (n == 0) return 0;
if (!table(n - 1, k - 1))
table(n - 1, k - 1) = bin(n - 1, k - 1, table);
if (!table(n - 1, k))
table(n - 1, k) = bin(n - 1, k, table);
return table(n - 1, k - 1) + table(n - 1, k);
}
unsigned int binomial(unsigned int n, unsigned int k)
{
if (k == 0) return 1;if (n == 0) return 0;
Matrix<int> table(n + 1, k + 1, 0);
for (unsigned int i = 0; i <= n; i++)
table(i , 0) = 1;
return bin(n, k, table);
} C
omplexity
Linear in time ). Space occupancy is






3. Max sub-array problem

Given an array of integers, compute the largest sum continuous sub array

Solution
This problem is a little gem. An elegant solution has been provided
by Kadane.[1]

In the code below
max_so_far represents the maximum value computed before analyzing the current subsequence, while max_ending_here represents the maximum for the current subsequence.

If max_ending_here < 0, we violate the sequence continuity and therefore we can safely reset max_ending_here = 0. If max_so_far < max_ending_here, then we have found a new maximum and we can update the accordingly:

int maxSubArraySum(const std::vector<int> & v)
{
	int max_so_far = 0, max_ending_here = 0;

	for (unsigned int i = 0; i < v.size(); ++i)
	{
		max_ending_here = max_ending_here + v[i];

		if (max_ending_here < 0)
			max_ending_here = 0;

		if (max_so_far < max_ending_here)
			max_so_far = max_ending_here;
	}

	return max_so_far;
}

The second implementation also returns the start and the end point
for the max continuous sequence:

#include <climits>

int kadane(const std::vector<int> & v, int & start, int & finish)
{
	int maxSum = INT_MIN, sum = 0;
	unsigned int left = 0, right = 0;
	start = finish = 0;

	for (unsigned int i = 0; i < v.size(); ++i)
	{
		sum += v[i];
		if (sum > maxSum)
		{
			maxSum = sum;
			finish = right = i;
			start = left;
		}
		else if (sum < 0)
		{
			sum = 0;
			left = right = i+1;
		}
	}
	return maxSum;
}

Complexity
Linear in the size of the input



4. Catalan Numbers

Catalan numbers are mathematically defined as:
Those numbers have multiple applications in combinatorics. For
example: counts the number of expressions containing pairs of
parentheses which are correctly matched (e.g. represents
((())) ()(()) ()()() (())() (()()) ). Also, is the number of
different ways factors can be completely parenthesized (e.g.
represents ((ab)c)d (a(bc))d (ab)(cd) a((bc)d)
a(b(cd))) ). In addition, is also the number of full binary trees
with leaves. For a complete description of the applications
please refer Wikipedia[2].
Solution
The solution provided is directly implementing the recursive
definition.
Code
unsigned int cat(unsigned int n,
std::vector<unsigned int> & table)
{
if (n == 0) return 1;
for (unsigned int i = 0; i < n; i++)
{
if (!table[i])
table[i] = cat(i, table);
if (!table[n - 1 - i])
table[n - 1 - i] = cat(n - 1 - i, table);
table[n] += table[i] * table[n - 1 - i];}
return table[n];
} C
omplexity
Linear in the size of the input,
Solution
Notice that we can leverage the symmetry in the definition. For
instance .
This observation leads to the following recursive implementation.
Code
unsigned int catalan2(unsigned int n)
{
if (n == 0) return 1;
unsigned int sum = 0;
for (unsigned int i = 0; i < n/2; ++i) {
sum += catalan(i)*catalan(n-1-i);
}
sum *= 2;
if (n % 2) {
unsigned int c = catalan(n/2);
sum += c*c;
}
return sum;
}5. Integer Knapsack – A knapsack has max
capacity C and there are n items each with weight
w[i] and value v[i]. Maximize the value in the
knapsack without exceeding its max capacity
Solution
An item can be inserted in the knapsack or not: if the item is
inserted, then the total value contained in the knapsack will
increase of and the capacity will decreases of . If the item is
not inserted, than the capacity will remain unchanged. This means
that the solution can be then obtained recursively. Mathematically,
we can define:
In the remaining, we provide two different solutions: the first is
top-down and recursive, while the second is based on dynamic
programming and it is built bottom-up by storing partial results in a
support array .
Code
unsigned int knapRecursive(const unsigned int C,
const unsigned int w[],
const unsigned int v[],
const unsigned int n)
{
if (n == 0 || C == 0)
return 0;
if (w[n - 1] > C)
return knapRecursive(C, w, v, n - 1);
else return std::max(v[n - 1] +knapRecursive(C - w[n - 1], w, v, n - 1),
knapRecursive(C, w, v, n - 1));
}
unsigned int knapSack(const unsigned int C,
const unsigned int w[],
const unsigned int v[],
const unsigned int n)
{
Matrix<unsigned int> table(n + 1, C + 1);
for (unsigned int i = 0; i <= n; ++i)
for (unsigned int j = 0; j <= C; ++j)
{
if (i == 0 || j == 0)
table(i, j) = 0;
else if (w[i - 1] <= j)
table(i, j) =
std::max(v[i - 1] + table(i - 1, j - w[i - 1]),
table(i - 1, j));
else
table(i, j) = table(i - 1, j);
}
return table(n, C);
} C
omplexity
Pseudolinear in time and Pseudolinear in space6. Edit Distance -– Given two strings, compute
the edit distance between them
Solution
The edit distance is the minimum number of edits required to
convert one string into another. For simplicity, we assume that the
cost of insertion and deletion is 1. Consider two strings and
, we can define a cursor for scanning S1 and a
cursor for scanning S2. The edit distance is defined as
it follows:
In other words: if the characters are aligned, the edit distance for
the problem will not increase, otherwise we need to align the
strings by reducing the size of S1, or S2 or both.
Now let’s consider the base cases. Clearly, because this case
represents the empty strings. We can also define and ,
because in this case we are comparing a string of length
(respectively ) with the empty string. We can use the above
definition for computing the edit distance by tabulating all the
values with complexity .
However, we can significantly improve the complexity by taking
into account that we only need the input from the previous column
in the table for computing the current column. This will allow us to
require only . The code uses initialize the column
for each and this represents the maximum cost for position
. Then, we have two loops. The most external loop scans the
string for each and it initializes which the
maximum cost for the position. The internal loop scans the string
for each and updates the edit distance value by directly
applying the recursive definition. When the internal loop isconcluded the columns and are swapped and the scan of
continues.
There are situations where it is appropriate to have different costs
according to the specific edit operations (delete, insert) required to
align the strings. Those changes are left as an exercise for the
reader.
Code
unsigned int editDistance(const std::string &s1,
const std::string & s2)
{
const size_t len1 = s1.size(), len2 = s2.size();
std::vector<unsigned int> col(len2 + 1),
prevCol(len2 + 1);
std::iota(prevCol.begin(), prevCol.end(), 0);
for (unsigned int i = 0; i < len1; ++i) {
col[0] = i + 1;
for (unsigned int j = 0; j < len2; ++j)
col[j + 1] = std::min(1 + col[j],
std::min(1 + prevCol[j],
prevCol[j] +
(s1[i] == s2[j] ? 0 : 1)));
col.swap(prevCol);
}
return prevCol[len2];
} C
omplexity
Complexity is7. Neat Print – Given a sequence of words and a
max number of words which can be put in a line,
print the sequence of words neatly. Assume that
no word is split across lines.
Solution
Let be the length of word . Intuitively, the cost of the first
word is and for the remaining words we can initially
define . Also, let and consider the
following recurrence, where we build the optimal cost for word ,
by considering the optimal cost for word :
However this definition is not yet meeting our goal for two reasons.
First, only considers the cost of the previous word, while it
should consider all the words that can fit a line up to a maximal
cost . Therefore we need to redefine in such a way to
accumulate the cost of the previous words and stop before at the
point where this cost becomes negative. Intuitively for each given
word we need to scan no more than a position backwards. This
can be addressed by defining for a
leftmost word such that . Second, the cost should be
non-linear because we want to balance across lines (e.g. leaving
two positions in one same line should intuitively cost more than
leaving a position in one and the other position in another line).
This requirement can be fulfilled in multiple ways, for instance by
defining or more conveniently forbitwise computation: . To summarize our
goal is to find:
such that . In the code the
vector will contain final decreasing values containing the
residuals for each word added to a given line. The values will
increase again anytime that there is a need to change line.
Code
void neatPrint(std::vector<unsigned int> & M,
const std::vector<unsigned int> &
length,
unsigned int max, int n)
{
int penalty;
for (int i = 0; i < n; i++)
{
penalty = max - length[i];
M[i] = std::min(M[i], (i - 1 < 0 ? 0 : M[i - 1]) +
(1 << penalty));
for (int j = i - 1; j >= 0; j--)
{
penalty -= (length[j] + 1);
if (penalty < 0)
break; // generate next line
M[i] = std::min(M[i],
((j - 1 < 0) ? 0 : M[j - 1]) +
(1 << penalty));
}
}
}
void solveNeatPrint(const std::vector<unsigned int> & length, unsigned int
max)
{int n = length.size();
std::vector<unsigned int> M(n,
std::numeric_limits<unsigned int>::max());
neatPrint(M, length, max, n);
for (int i = 0; i < n; ++i)
std::cout << M[i] << ' ';
std::cout << std::endl;
} C
omplexity
Note that can be computed in linear time of the input size,
while can be computed in time.8. Eggs Drop – Given k eggs and n floors in a
building, find the minimum number of trials
required to determine the lowest floor from which
an egg can be dropped without getting broken.
Solution
This is a classical puzzle, frequently asked during interviews. Let
be the minimum number of attempts given eggs and n
floors. A dynamic solution can be computed by considering that
when we drop an egg from floor f there are only two possible
outcomes:
a) If the egg breaks, then we have eggs and we need
to check the floor
b) If the egg does not break, then we have eggs and the
remaining floors left
Since we want to minimize the number of attempts, in the worst
scenario we have to consider the maximum between a) and b). The
relation then becomes:
The base case are: because if we have only one egg
then we have no other option but to climb the floors one by one,
and because if we have only one floor then we just
need to check it. In addition, we can define and
because those are borderline cases.
This characterization leads to a straightforward recursion
implementation given below where we memorize partial solutions
in a support for avoiding the recompute those solutions again
and again.Code
int eggDropHelper(unsigned int k, unsigned int n,
Matrix<int> & table)
{
if (n == 1 || n == 0)
return n;
if (k == 1)
return n;
if (!k)
return 0;
unsigned int min =
std::numeric_limits<unsigned int>::max();
unsigned int res;
for (unsigned int f = 1; f <= n; ++f)
{
res = std::max(
((table(k - 1, f - 1) == -1) ?
table(k - 1, f - 1) =
eggDropHelper(k - 1, f - 1,
table) :
table(k - 1, f - 1)
),
(table(k, n - f) == -1) ?
table(k, n - f) =
eggDropHelper(k, n - f, table) :
table(k, n - f)
);
if (res < min)
min = res;
}
return min + 1;
}int eggDrop(unsigned int k, unsigned int n)
{
Matrix<int> table(k+1, n+1, -1);
return eggDropHelper(k, n, table);
} C
omplexity
The DP solution is left as exercise. A straightforward
implementation needs entries in a table where each entry is
computed at most times. Therefore, the algorithm runs in
time. Time complexity can be reduced to , if we consider that
the optimal floor for is certainly equal or larger than the one
for , so we can avoid to restart the minimum computation
from 1. Also, it could be useful to prove that the function
is convex in f so the minimum is
unique and can be computed with a linear scan.9. Jump Stairs – There is a stair with n steps.
You can climb either one step or two steps
at a time. How many different ways there
are to climb the stair?
Solution
Let’s try a number of examples: If we have only one step, then
there is only a way to climb the stair; if we have two steps, then
there are two ways (e.g. 1 step, 1 step, or 2 steps); if we have three
steps, then there are three ways. More examples are given in the
following table:
Steps #Confs Configurations
1 1 1
2 2 (1, 1); (2)
3 3 (1, 1, 1); (1, 2) ; (2, 1)
4 5 (1, 1, 1, 1); ( 2, 1, 1); (1, 2, 1); (1, 1, 2); (2, 2)
5 8 (1, 1, 1, 1, 1); ( 2, 1, 1, 1); (1, 2, 1, 1); (1, 1, 2, 1); (1, 1, 1,
2);
(2, 2, 1); (1, 2, 2), (2, 1, 2)
We notice that there is a pattern: at each step the number of
configurations is the sum of the number of configurations of the
previous and last steps but one. Mathematically:
This formula has a straightforward interpretation: we jump to the n
step either from the step or from the step. Note that the
base cases are different with respect to Fibonacci.Code
unsigned long jump(unsigned int n)
{
if (n == 1) return 1;
if (n == 2) return 2;
unsigned long current = 0, prev = 2, prevPrev = 1;
for (unsigned int i = 3; i <= n; i++)
{
current = prev + prevPrev;
prevPrev = prev;
prev = current;
}
return current;
} C
omplexity
Linear in the input size.10. Jumping Array – Given an array of nonnegative numbers, start at the first element and
reach the end with a minimum number of jumps.
A jump cannot exceed the length contained in the
current position.
Solution
Given the array ], the base cases are when or when
. For those cases, we have no solution. Otherwise, the
mathematical formulation can be computed for each position by
finding the maximum jump length for position such that the
required constrain is not violated. Mathematically
.
Code
unsigned int jump(const unsigned int a[], unsigned int n)
{
std::vector<unsigned int> result(n);
if (n == 0 || a[0] == 0)
return std::numeric_limits<unsigned int>::max();
result[0] = 0;
for (unsigned int i = 1; i < n; ++i)
{
result[i] =
std::numeric_limits<unsigned int>::max();
for (unsigned int j = 0; j < i; j++)
if ((a[j] >= (i - j)) &&
(result[j] + 1 < result[i]))
result[i] = result[j] + 1;
}
return result[n - 1];
}C
omplexityLinear in time and space11. Dice -– Given n dice, count how many
ways to get sum s.
Solution
Let’s suppose that each die has m faces and define a function
which counts how many ways we have to get sum for
dices with faces. We can compute this function starting from the
result with dices. In particular, if we get a sum from
dice we need to add from the die for each :
Note that we have terms in this sum. We use a support table
where we store the current sum and the current dice. The base
case is with only one die and in this case there is only one way to
get the sum therefore for . Then, for each
possible sum value and for each possible dice and
for each possible valid value produced by a die we
update according to the above definition.
Code
unsigned long playDices(unsigned int n, unsigned int m, unsigned int s)
{
if ((n == 0) || (m < 2) || (s == 0) || (n*m < s) )
return 0;
Matrix<int> mem(s + 1, n + 1, 0);
for (unsigned i = 1; i <= m && i <= s; ++i)
mem(i, 1) = 1;
for (unsigned i = 1; i <= s; ++i)
for (unsigned j = 2; j <= n; ++j)
for (unsigned k = 1; k <= m && k < i; ++k)
mem(i, j) += mem(i - k, j - 1);
return mem(s, n);} C
omplexity
Complexity is12. Coin Change – Given n dollars, how
many different ways there are to make the
change into a set of coins S?
Solution
Let’s define and let be the change for dollars
given a set of coins. We suppose to a have an infinite amount of
each type of coin . A coin can either be part of the change or
not. This simple observation is used for a dynamic programming
solution
where counts when the coin has been not selected,
while counts the selection of a new coin . The base
cases are for where the only solution is not to change
any money, for where there is no solution because
we have a negative amount of money and
because we have money but there is no change
available. The first implementation is recursive, while the second
is based on dynamic programming.
Code
int changeCoin(int n, const unsigned int S[], int t)
{
if (n == 0)
return 1;
if ((n<0) || (t < 0 && n > 0))
return 0;
return changeCoin(n, S, t - 1)
+ changeCoin(n - S[t], S, t);
}int changeCoinDP(unsigned int n, const unsigned int S[],
unsigned int t)
{
Matrix<unsigned int> table(n + 1, t);
for (unsigned int j = 0; j < t; ++j)
table(0, j) = 1;
for (unsigned int i = 1; i <= n; ++i)
for (unsigned int j = 0; j < t; ++j)
table(i, j) =
((i >= S[j]) ? table(i - S[j], j) : 0) +
((j>0) ? table(i, j - 1) : 0);
return table(n, t-1);
} C
omplexity
Time complexity is13. Longest Palindrome String – Given a
string, compute the longest palindromic
substring
A string is palindromic if it is read the same backward and
forward, as Madam, I’m Adam or Poor Dan is in a droop.
Solution
A solution can be computed for the string by considering
that and
This definition computes the longest palindromic substring by
starting from the whole string and it is easy to directly
write the code implementing this recursive formulation.
However, another more convenient approach is to define
if the string is palindromic for . The following base
cases hold for single characters and for couple of characters:
In addition, we can define the recurrence
for increasing lengths
where and .
Note that with this definition the interval is contained in
the interval and therefore we just need to test the two
characters in the border ). The code keep tracks of the
starting position where the palindromic string begins ( )
and its length ( ).
Code
std::string longestPalindrome(const std::string & s) {unsigned int n = s.length();
if (n == 0)
return s;
unsigned int longestStart= 0;
unsigned int maxLen = 1;
Matrix<unsigned int> table(n, n, false);
for (unsigned int i = 0; i < n; ++i)
table(i, i) = true;
for (unsigned int i = 0; i < n - 1; ++i) {
if (s[i] == s[i + 1]) {
table(i, i + 1) = true;
longestStart = i;
maxLen = 2;
}
}
for (unsigned int len = 3; len <= n; ++len) {
for (unsigned int i = 0; i < n - len + 1; ++i) {
unsigned int j = i + len - 1;
if (table(i + 1, j - 1) && s[i] == s[j])
{
table(i, j) = true;
if (len > maxLen)
{
longestStart = i;
maxLen = len;
}
}
}
}
return s.substr(longestStart, maxLen);
} C
omplexityComplexity is and space is . Providing a solution with
reduced space is left as exercise.14. String Palindromes -– Given a string,
find the minimum number of characters to
be inserted for converting the string into a
palindrome
Solution
Consider the string and define as the number of
characters to be inserted for getting a palindrome. We have:
The base case are if and
A dynamic programming implementation can be realized by
adopting a which stores the minimum number of insertions
needed to convert into a palindrome. The table is filled in by
incremental gap such that and by considering the
subintervals contained between the positions ,
Code
unsigned int numInsertionPaly(const std::string & str,
unsigned int l, unsigned int r)
{
if (r <= l)
return 0;
if (l == r - 1)
return (str[l] == str[r]) ? 0 : 1;
if (str[l] == str[r])
return numInsertionPaly(str, l + 1, r - 1);
else
return (std::min(numInsertionPaly(str, l + 1, r),numInsertionPaly(str, l, r - 1)) + 1);
}
int minInsertionsPalyndromeDP(const std::string & str)
{
unsigned int n = str.length();
Matrix<unsigned int> table(n + 1, n + 1, 0);
unsigned int gap, left, right;
for (gap = 1; gap < n; ++gap)
for (left = 0, right = gap;
right < n; ++left, ++right)
table(left, right) =
(str[left] == str[right]) ?
table(left + 1, right - 1) :
(std::min(table(left, right - 1),
table(left + 1, right)) + 1);
return table(0, n - 1);
} C
omplexity
Complexity is in time and space15.LCS -– Given two strings S1 and i, find
the longest common substring
The longest common substring problem consists in finding the
longest string that is a substring of two strings.[3]
Solution
On way to solve the problem is to find the longest common suffix
for all the pairs of prefixes for the strings and S2. The longest
common suffix is:
Given , we can compute the longest common substring because
the maximal of the longest common suffixes of all possible prefixes
is the longest common substring of S1 and T1.
Code
int LCSubStr(const std::string & S1, const std::string & S2)
{
unsigned int m = S1.length();
unsigned int n = S2.length();
unsigned int result = 0;
Matrix<unsigned int> LCSuff(m + 1, n + 1);
for (unsigned int i = 0; i <= m; i++) {
for (unsigned int j = 0; j <= n; j++) {
if (i == 0 || j == 0) {
LCSuff(i, j) = 0;
} else if (S1[i - 1] == S2[j - 1]) {
result = std::max(
(LCSuff(i, j) = LCSuff(i - 1, j - 1) + 1),result
);
} else {
LCSuff(i, j) = 0;
}
}
}
return result;
} C
omplexity
Complexity is and space is . Reducing the space to
is left as an exercise.16. LCS – Given two strings, find the
longest common subsequence
Given the two strings, two subsequences are in common if they
appear in the same order but not necessarily contiguous. The main
difference with the previous problem is that here the terms are not
consecutive.
Solution
A dynamic programming solution can be computed for the string
and the string 1] by defining a recursive function
on the prefixes and of length and
A dynamic programming solution can be built by using a table
where we store the partial results of the above computation
(function ). In addition we store the direction that generated the
table for reconstructing the common subsequence in a next step
(function )
Code
enum where{DiagonalUpward, Upward, Downward};
void printLCS(const Matrix<where>& directions, const std::string& str,
unsigned int i, unsigned int j)
{
if (i == 0 || j == 0)return;
if (directions(i, j) == DiagonalUpward)
{
printLCS(directions, str, i - 1, j - 1);
std::cout << str[i];
}
else if (directions(i, j) == Upward)printLCS(directions, str, i - 1, j);
else
printLCS(directions, str, i, j - 1);
}
void LCS(const std::string& s1, const std::string& s2)
{
const unsigned int m = s1.size() + 1;
const unsigned int n = s2.size() + 1;
Matrix<unsigned int> table(m, n, 0);
Matrix<where> directions(m, n);
for (unsigned int i = 1; i<m; i++)
for (unsigned int j = 1; j<n; j++)
if (s1[i] == s2[j])
{
table(i, j) = table(i - 1, j - 1) + 1;
directions(i, j) = DiagonalUpward;
}
else
if (table(i - 1,j) >= table(i, j - 1))
{
table(i, j) = table(i - 1, j);
directions(i, j) = Upward;
}
else
{
table(i, j) = table(i, j - 1);
directions(i, j) = Downward;
}
printLCS(directions, s1, m-1, n-1);
} C
omplexity
Complexity is and space is .17. LIS – Given an array of integers, find
the longest increasing subsequence
Solution
The solution can be quickly identified by dynamic programming.
Suppose that we scan the array A, then at position we have that
Code
unsigned int LIS(const std::vector<unsigned int> & v)
{
unsigned int max;
unsigned int n = v.size();
std::vector<unsigned int> maxHere(n, 0);
for (unsigned int k = 0; k < n; ++k)
{
max = 0;
for (unsigned int j = 0; j < k; ++j)
if (v[k] > v[j])
if (maxHere[j] > max)
max = maxHere[j];
maxHere[k] = max + 1;
}
max = 0;
for (unsigned int k = 0; k < n; ++k)
if (maxHere[k] > max)
max = maxHere[k];
return max;
} C
omplexityComplexity is and space is . An algorithm is described
here[4].18. Bridge Matching – n cities are on the
northern bank of a river and n cities are on
the southern bank. You can build a bridge
only between cities with the same number
Solution
Let be the number of cit on the northern bank and the
number of cit on the southern bank. The problem can be
reduced to the one of finding the longest common subsequence.
Suppose to sort the bridges built by their first city. If two bridges
cross, then we have one bridge and another bridge such
that either and or and . We can sort the
tuples by increasing indexes and then compute the longest
increasing sequence (LIS) on the sequence of .
Code
Left as exercise
Complexity
Since we need to sort the complexity is19. LBS – Given an array of integers, find
the longest bitonic sequence
Solution
A sequence is bitonic, if it initially increases and then decreases.
For an array we can compute the longest increasing sequence
ending at position and the longest decreasing sequence
starting at position . For each position we define:
and
Code
Left as exercise
Complexity
Complexity is .20.Box Stacking – Given a set of 3d boxes,
compute the largest stack of boxes. A box
can be stacked only on top of another box
with larger base.
Solution
This problem is a variation of the longest increasing sequence.
Each box has three dimensions which can
be rotated to form the base: either ( ), or ,
or . If we suppose having infinite amount of each
box types, then we can solve this problem by computing the LIS
for the remaining dimensions of the box.
Code
Left as exercise
Complexity
Complexity is .21. Sum Subset -– Given an array of
integers of size n, partition it in such a way
that the two subsets have equal sum s
Solution
Sum subset problem is and important problem in computer science
with application in cryptography and complexity[5]. The problem
is NP-Complete. The most naïve solution generates all the subsets
and for each of them it checks whether the sum is the right
number. The complexity is where the size of the array.
We can use Dynamic programming for providing a pseudopolynomial solution. First, if the sum is odd there is no solution,
while if the sum is even we can try to find a subset. Second, if the
current element is larger than the sum we must skip it, otherwise
we can decide whether we want to include it or not. Therefore
depends on , if we don't include the element for the
position and for the current sum value . While it
depends on if we include the element.
The base cases are because there is always a subset
with zero sum, and because the empty set cannot have
a subset of sum . The code implements a recursive and a dynamic
programming solution
Code
bool isSubsetSum(const std::vector<unsigned int> & v,
const unsigned int n, unsigned int sum)
{
if (n == 0 && sum != 0)
return false;if (sum == 0)
return true;
if (v[n - 1] > sum)
return isSubsetSum(v, n - 1, sum);
return isSubsetSum(v, n - 1, sum) ||
isSubsetSum(v, n - 1, sum - v[n - 1]);
}
bool partition(const std::vector<unsigned int> & v,
unsigned int n)
{
int sum = std::accumulate(v.begin(), v.end(), 0);
if (sum % 2 != 0)
return false;
return isSubsetSum(v, n, sum / 2);
}
bool isSubsetSumDP(const std::vector<unsigned int> & v,
const unsigned int n, unsigned int sum)
{
Matrix<bool> subset(sum + 1, n + 1);
for (unsigned int j = 0; j <= n; j++)
subset(0, j) = true;
for (unsigned int i = 1; i <= sum; i++)
subset(i, 0) = false;
for (unsigned int i = 1; i <= sum; i++)
for (unsigned int j = 1; j <= n; j++) {
subset(i, j) = subset(i, j - 1);
if (i >= v[j - 1]) {
subset(i, j) = subset(i, j) ||
subset(i - v[j - 1], j - 1);
}
}
return subset(sum, n);
}Complexity
Complexity is pseudo-polynomial22.Partition Set – partition a multiset S of
positive integers into two
subsets S1 and S2, such that the sum of the
numbers in S1 equals the sum of the
numbers in S2
Solution
This is a variant of the previous problem with a similar pseudo
linear solution based on dynamic programming.
Code
bool isPartitionDP(const std::vector<unsigned int> & v)
{
unsigned int sum = std::accumulate(v.begin(), v.end(), 0);
return isSubsetSumDP(v, v.size(), sum / 2);
}
void testPartition()
{
int v1[] = { 3, 1, 1, 2, 2, 1 };
std::vector<unsigned int> vec1(v1,
v1 + sizeof(v1) / sizeof(int));
if (isPartitionDP(vec1) == true)
std::cout << "Found a partition";
else
std::cout << "No partition";
} C
omplexity
Complexity is pseudo-polynomial ), where is the sum of
elements in the vector.23. Segment Partition -– Given a segment
of integer length n, cut it into different
integer parts in such a way to maximize
the product of the lengths of all parts.
Solution
We can split the segment for all the integer positions and compute
the max product of the two parts. If we split it in position , then
the product is . In addition, the part can be further
split. So the product can be reclusively computed as
. The base cases are
.
Code
unsigned int segment(unsigned int n)
{
if (n == 0 || n == 1) return 0;
unsigned int m = 0;
for (unsigned int i = 1; i < n; i++)
m = std::max(m, std::max(i * (n - i),
segment(n - i) * i));
return m;
}
unsigned int segmentDPhelper(unsigned int n,
std::vector<unsigned int> & seg)
{
unsigned int m = 0;
for (unsigned int i = 1; i < n; i++)
{
if (!seg[n - i])
seg[n - i] = segmentDPhelper(n - i, seg);m = std::max(m, std::max(i * (n - i),
seg[n - i] * i));
}
return m;
}
unsigned int segmentDP(unsigned int n)
{
if (n == 0 || n == 1) return 0;
std::vector<unsigned int> seg(n, 0);
return segmentDPhelper(n, seg);
} C
omplexity
Linear in time and space24.Cutting a Rod – given a rod of length n
and a vector of prices for different lengths,
cut the rod for maximizing the gain
Solution
The idea is very similar to the one of the previous problem. Let’s
suppose to have an array of we can define
for
Code
unsigned int cutDPhelper(
const std::vector<unsigned int> & price,
unsigned int n, std::vector<unsigned int> & cut)
{
unsigned int m = 0;
for (unsigned int i = 1; i < n; i++)
{
if (!cut[n - i - 1])
cut[n - i - 1] =
cutDPhelper(price, n - i - 1, cut);
m = std::max(m, price[i] + cut[n - i - 1]);
}
return m;
}
unsigned int cutDP(const std::vector<unsigned int> & price,
unsigned int n)
{
if (n <= 0) return 0;
std::vector<unsigned int> seg(n, 0);
return cutDPhelper(price, n, seg);
} C
omplexityLinear in time and space.25. Bellman-Ford – Given a graph G and a
source vertex, find the shortest paths from
the source src to all vertices. The graph
may contain negative edges
Solution
This is a classical dynamic programming problem and the solution
is due to Bellman-Ford[6]. Let’s suppose that is the weight
associated to the for each edge in a directed graph .
For our computation we need a support array of size . The
first step is to initialize all entries in to infinite with the only
exception of because is reachable with zero distance.
Then, for times we compute:
At the end a negative edge can be detected by checking for each
edge whether , if
Code
void BellmanFord(const Graph & g, int src)
{
std::vector<int> dist(g.numNodes(),
std::numeric_limits<int>::max());
std::vector<int> predecessor(g.numNodes(), -1);
dist[src] = 0;
for (nodeID u = 0; u < g.numNodes(); u++)
for (auto const & e : g.edges(u))
{
if (dist[u] + e.w < dist[e.v]){
dist[e.v] = dist[u] + e.w;
predecessor[e.v] = u;
}
}
for (nodeID u = 0; u < g.numNodes(); u++)
for (auto const & e : g.edges(u))
if (dist[u] + e.w < dist[e.v])
std::cout << "negative cycle";
for (nodeID v = 0; v < g.numNodes(); ++v)
std::cout << predecessor[v] << "->"
<< v << " d=" << dist[v] << std::endl;
} C
omplexity
Time complexity is26. Max Submatrix 0/1 - Given a matrix
consisting only of 0s and 1s, find the
maximum size square sub-matrix with all
1s
Solution
A dynamic programming solution can be defined as follows. Let
be the matrix of 0s and 1s of size and consider another matrix
of same size. If , then it can contribute to either position
[j], or , or ] which can be expressed as
. If then .
Here is the code
Code
void FindMaxSubSquare(const Matrix<bool> & m,
int &maxI, int &maxJ, int &size)
{
Matrix<int> s(m.dim1(), m.dim2());
for (unsigned i = 0; i < m.dim1(); i++)
s(i, 0) = m(i, 0);
for (unsigned j = 0; j < m.dim2(); j++)
s(0, j) = m(0, j);
for (unsigned int i = 1; i < m.dim1(); i++)
for (unsigned int j = 1; j < m.dim2(); j++)
{
if (m(i,j))
s(i,j) = std::min(std::min(s(i,j - 1),
s(i - 1, j)), s(i - 1,j - 1)) + 1;
else
s(i, j) = 0;
}size = s(0, 0); maxI = 0; maxJ = 0;
for (unsigned int i = 0; i < m.dim1(); i++)
for (unsigned int j = 0; j < m.dim2(); j++)
if (size < s(i, j))
{
size = s(i, j);
maxI = i;
maxJ = j;
}
} C
omplexity
Complexity is27. Matrix Parenthesization -- Given a set
of m Matrices find the most efficient way
of multiplying them
Solution
Matrix multiplication is associative so there are multiple ways of
performing the multiplication and therefore the number of
operations (sum and multiplications) performed on scalars is
different. Let’s suppose that the dimensions of the matrix is
contained in positions for a vector . We can scan
the vector and find a solution recursively.
Code
unsigned int MatrixOrder(const std::vector<unsigned int>&p,
int i, int j)
{
if (i == j)
return 0;
unsigned int min =
std::numeric_limits<unsigned int>::max();
unsigned int res;
for (int k = i; k <j; ++k)
{
res = MatrixOrder(p, i, k) +
MatrixOrder(p, k + 1, j) +
p[i - 1] * p[k] * p[j];
if (res < min)
min = res;
}
return min;
}unsigned int MatrixChainOrder(const std::vector<unsigned int> & p)
{
unsigned int n = p.size();
Matrix<unsigned int> m(n, n);
for (unsigned int i = 0; i < n; ++i)
m(i, i) = 0;
unsigned int j, cost;
// len = 2, 1 <= i < n - 1 ; j = i + 1
// len = 3, 1 <= i < n - 2; j = i + 2
//
// len = n-2, i=1, i = 2 , j = i + n - 3
// len = n-1, i=1 , j = n - 1
for (unsigned int len = 2; len < n; ++len)
for (unsigned i = 1; i < n - len + 1; ++i)
{
j = i + len - 1;
m(i, j) =
std::numeric_limits<unsigned int>::max();
for (unsigned int k = i; k <= j - 1; ++k)
{
cost = m(i, k) + m(k + 1, j) +
p[i - 1] * p[k] * p[j];
if (cost < m(i, j)) {
m(i, j) = cost;
}
}
}
return m(1, n - 1);
} C
omplexity
Complexity is28.Max Submatrix – Given a matrix of size
n x n find the maximum sum rectangle
Solution
The problem is a natural generalization of the Kandane’s problem
discussed previously. Suppose that we fix columns and , then we
can compute in linear time the top and bottom rows which
maximize the rectangle.
Code
void findMaxSum(const Matrix<int> & M)
{
unsigned int rows = M.dim1();
unsigned int columns = M.dim2();
unsigned int finalLeft, finalRight, finalUp, finalDown;
int sum, start, stop, maxSum = std::numeric_limits<int>::min();
for (unsigned int left = 0; left < columns; ++left)
{
std::vector<int> temp(rows, 0);
for (unsigned int right = left; right < columns; ++right)
{
for (unsigned int i = 0; i <rows; ++i)
temp[i] += M(i, right);
sum = kadane(temp, start, stop);
if (sum > maxSum)
{
maxSum = sum;
finalLeft = left; finalRight = right;
finalUp = start; finalDown = stop;
}
}
}
std::cout << "maxSum=" << maxSum <<" (Top, Left) (" << finalUp <<
" ," << finalLeft <<
") (Bottom, Right) (" << finalDown <<
"," << finalRight << ')' << std::endl;
} C
omplexity
Complexity is , because Kandane is linear.29. Given a Binary Search Tree, find the
size of the largest independent set of nodes
Solution
A set of nodes in a tree is independent if there are no edges directly
connecting them in a father-children relation. A dynamic programming
solution is based on the consideration that a node can be either part of
the largest independent set or not. In the former case the size of the
largest set will be the sum of the largest set of grandchildren plus 1
because we skip the grandchildren’s father. In the latter case the size of
the largest set is the sum of the largest set of children because by
construction we do not add any new node to the set. Formally:
If a node is null then . For avoiding re-computing partial
results we can store the LIS(x) inside the node X.
Code
template <typename T>
struct node
{
T value;
mutable unsigned int liss;
struct node* left, *right;
node(T v) : value(v), liss(0), left(NULL), right(NULL) {};
};
template <typename T>
unsigned int LargestIndipendentSet(const node<T> * root)
{
if (root == NULL)
return 0;
if (root->liss)return root->liss;
unsigned int sizeWithThisNode = 1;
if (root->left)
sizeWithThisNode +=
LargestIndipendentSet(root->left->left) +
LargestIndipendentSet(root->left->right);
if (root->right)
sizeWithThisNode +=
LargestIndipendentSet(root->right->left) +
LargestIndipendentSet(root->right->right);
unsigned int sizeWithoutThisNode =
LargestIndipendentSet(root->right) +
LargestIndipendentSet(root->left);
root->liss = std::max(sizeWithThisNode,
sizeWithoutThisNode);
return root->liss;
} C
omplexity
The total complexity is where is the number of nodes in the binary
search tree.30. Optimal Binary Tree – given a set S of
tuples <k, freq[k]> , where k is an integer
and freq[k] is the number of times that k
has been observed, build a binary search
three such that the total cost of all single
searches is minimized
Solution
One key intuition is that the cost of accessing a key is ,
where is the depth of key . A tuple can be the root of the
binary search tree (BST) provided that it respects the BST
properties:
The left subtree of a node contains only nodes with keys
less than the node's key
The right subtree of a node contains only nodes with keys
greater than the node's key
For the left and right subtree: each one must also be a
binary search tree
There must be no duplicate nodes
Therefore we can write the cost function for the keys in as it follows:
In other words: when the node becomes a root and we need
to minimize the cost of the left keys and the right keys . In
addition, all the nodes below the new root node will have an
additional level of depth and therefore we need to sum all their
frequencies. The code provided uses memorization for avoidingrecomputation of the same values again and again. The solution is
built bottom-up.
Code
int costBST_DP(const std::vector<unsigned int> & freq)
{
unsigned int n = freq.size();
Matrix<unsigned int> cost(n, n);
Matrix<unsigned int> sumFreq(n, n);
unsigned int localCost;
for (unsigned int i = 0; i < n; ++i)
cost(i, i) = freq[i];
for (unsigned int i = 0; i < n; ++i)
for (unsigned int j = i; j < n; ++j)
{
sumFreq(i, j) = 0;
for (unsigned int s = i; s <= j && s < n; ++s)
sumFreq(i, j) += freq[s];
}
// range = 2 (0<=i<n-1) -> j=i+1 1<=j<=n-1
// range = 3 (0<=i<n-2) -> j=i+2 0<=j<=n-1
// range = n (i=0) -> j = n-1
for (unsigned int range = 2; range <= n; ++range)
for (unsigned int i = 0; i < n - range + 1; ++i)
{
unsigned int j = i + range - 1;
cost(i, j) = std::numeric_limits<unsigned int>::max();
for (unsigned int k = i; k <= j; k++)
{
localCost =
((k > i) ? cost(i, k - 1) : 0) +
((k < j) ? cost(k + 1, j) : 0) + sumFreq(i,
j);
if (localCost < cost(i, j))cost(i, j) = localCost;
}
}
return cost(0, n - 1);
} C
omplexity
The cost is and space is31. Boolean Parenthesization – given a
Boolean expression of and, or, xor, true,
false, find the number of ways to
parenthesize and evaluate to true
Solution
Let be the number of parenthesizations which are
evaluated to true between positions and ; and be the
number of parenthesization which are evaluated to false
between positions and . Recursively
Code
Left as exercise
Complexity
The running time is , where are the number of items in the
expression.32. Games of Coins – a set of coins are
aligned and two players can pick one coin
from each side in turn. Maximize the value
of the coins picked by the first player
Solution
Let suppose that the coins are represented in an array . The
value picked when the coins left are must satisfy the recursive
relation :
The key intuition is that the first player should select either coin or
coin with the goal of maximizing his gain. For the sake of
simplicity, let’s suppose he selects : the other case is symmetric.
We count plus we aim at minimizing the value of the second
player who can either pick another coin from the side (position
a+2) or pick a coin from the side. The value is clearly 0 if .
Code
Left as exercise
Complexity
There are values for and each single evaluation is , so the
total run time is33. Maximum value contiguous
subsequence – given an array of real
numbers, find a contiguous subsequence
with max sum s
Solution
Let’s define as the maximum value subsequence which ends at
. The element in position can be either added or not. Recursively
Code
Left as exercise
Complexity
There are elements in and the computing of each element
requires to compute the maximum between two values. Therefore
complexity is34. Balanced partition – given an array of
integers between 0 and M, divide the
integers into two sets such that the
difference of their sums is minimized
Solution
Let , if the subset } sums to j. Recursively for the set of
elements we can start with a set of elements and keep it as it
is, or we can expand it by adding the element
Then considering the row representing } we search the
value such that and the difference is minimized.
Code
Left as exercise
Complexity
There are elements bounded by while needs to scan elements.
Therefore the complexity is35. Scheduling – given n jobs, each one
with a processing time ti a profit pi and a
deadline d
i, maximize the profit
Solution
Suppose that each job has processing time profit and deadline
for and that we get no profit, if the job is executed after
its deadline. We want to maximize the profit for jobs
executed at time . Recursively,
Code
Left as exercise
Complexity
If we assume that the processing time is bounded by , then we
need to compute up to and we have jobs to consider. Therefore
the total complexity is36. Stock prices – Given a histogram array
of unsigned integers encoding the price of
a stock title during the previous year,
compute the area for the largest rectangle
contained in this histogram
Solution
Let A be the histogram array, we need to compute
)
The most naïve implementation has complexity . However we
can achieve complexity by processing each element and
looking for the largest rectangle with height being at least .
Complexity can be further improved by considering that if we have
and , then we can immediately discard when
processing the entry and this can be efficiently achieved by using
a stack.
Code
unsigned int largestRectangle(
const std::vector<unsigned int> & H)
{
std::stack<unsigned int> stk;
std::vector<unsigned int> left;
for (unsigned int i = 0; i < H.size(); ++i)
{
while (!stk.empty() && H[stk.top()] > H[i])
stk.pop();
stk.push(i);
left.push_back(stk.empty() ? -1 : stk.top());}
while (!stk.empty()) { stk.pop(); }
std::vector<unsigned int> right(H.size());
for (int i = H.size() - 1; i >= 0; --i)
{
while (!stk.empty() && H[stk.top()] > H[i])
stk.pop();
right[i] = stk.empty() ? H.size() : stk.top();
stk.push(i);
}
unsigned int maxArea = 0;
for (unsigned int i = 0; i < H.size(); ++i)
{
maxArea =
std::max(maxArea, H[i] * (right[i] - left[i] - 1));
}
return maxArea;
} C
omplexity
Code runs in .37. Ship Battle – Given a matrix M and an
array V, match the array in the matrix
Solution
Let be the matrix of size , and the array of size . We can
scan the matrix by rows and by columns and if
, with vector at position , we can recursively
check, if there is a match for the eight positions adjacent to
with . Particular attention must be put for the corner cases as
explained in the code. If we cache the situations where the match
does not happen for tuples , we can obtain complexity
Code
// (i, j, k) -> v
typedef Tensor<unsigned int, unsigned int,
unsigned int, bool> Cache;
bool matchHelper(const Matrix<int> &m,
const std::vector<int> &v,
Cache & doNot,
int i,
int j,
unsigned int len)
{
// std::cout << " matchHelper i=" << i
<< " j=" << j << " len=" << len << std::endl;
if (v.size() == len)
return true;
if (i < 0 || i >= (int)m.dim1() ||
j < 0 || j >= (int)m.dim2() || doNot.exist(i, j, len))
return false;
if ((m(i, j) == v[len]) &&(matchHelper(m, v, doNot,
i - 1, j, len + 1) || /* horizontal */
matchHelper(m, v, doNot,
i + 1, j, len + 1) || /* horizontal */
matchHelper(m, v, doNot,
i, j - 1, len + 1) || /* vertical */
matchHelper(m, v, doNot,
i, j + 1, len + 1) || /* vertical */
matchHelper(m, v, doNot,
i - 1, j - 1, len + 1) || /* diagonal */
matchHelper(m, v, doNot,
i - 1, j + 1, len + 1) || /* diagonal */
matchHelper(m, v, doNot,
i + 1, j - 1, len + 1) || /* diagonal */
matchHelper(m, v, doNot,
i + 1, j + 1, len + 1) /* diagonal */
))
return true;
doNot(i, j, len) = true;
return false;
}
bool matchVectorInMatrix(const Matrix<int> & m,
const std::vector<int> & v)
{
Cache c;
for (unsigned int i = 0; i < m.dim1(); ++i)
for (unsigned int j = 0; j < m.dim2(); ++j)
if (matchHelper(m, v, c, i, j, 0))
return true;
return false;
} C
omplexity
Code runs in .Appendix
This appendix contains two support classes defined for solving a
certain number of problems
Graph class
#include <forward_list>
typedef unsigned int nodeID;
typedef int weight;
struct Edge
{
nodeID v;
weight w;
Edge(nodeID d, weight wt) : v(d), w(wt) {};
};
typedef std::forward_list<Edge> edgesList; // list of edges leaving a node
typedef std::vector<edgesList> Edges;
class Graph
{
public:
// allocate |V| lists of edges
Graph(unsigned int V) : _V(V), _E(0), _edges(new Edges(V)) {};
~Graph(){ delete _edges; };
void addEdge(nodeID v1, nodeID v2, weight w)
{
if (v1 > _V || v2 > _V) return;
Edge e(v2, w);
(*_edges)[v1].push_front(e);
_E++;
}
void addNode()
{
edgesList el;
_edges->push_back(el);_V++;
}
edgesList & edges(nodeID v) const { return (*_edges)[v]; };
unsigned int numNodes() const { return _V; };
unsigned int numEdges() const { return _E; };
private:
unsigned int _V, _E;
Edges * _edges;
};
std::ostream & operator << (std::ostream & os,
const Graph & g)
{
for (nodeID u = 0; u < g.numNodes(); u++)
{
os << " node=" << u << std::endl;
for (auto const & e : g.edges(u))
os << " ->" << e.v << " w=" << e.w << std::endl;
}
return os;
}Matrix class
template<typename T>
class Matrix
{
public:
Matrix(const Matrix&) = delete;
Matrix& operator=(const Matrix&) = delete;
Matrix(unsigned int dim1, unsigned int dim2)
: _M(new T*[dim1]), _dim1(dim1), _dim2(dim2)
{
for (unsigned int i = 0; i < dim1; ++i)
_M[i] = new T[dim2];
}
Matrix(unsigned int dim1, unsigned int dim2,
T defaultValue)
: Matrix(dim1, dim2)
{
for (unsigned int i = 0; i < _dim1; ++i)
for (unsigned int j = 0; j < _dim2; ++j)
_M[i][j] = defaultValue;
}
Matrix(Matrix&& aMatrix) {
_dim1 = aMatrix._dim1;
_dim2 = aMatrix._dim2;
_M = aMatrix._M;
aMatrix._dim1 = 0;
aMatrix._dim2 = 0;
aMatrix._M = nullptr;
}
~Matrix()
{for (unsigned int i = 0; i < _dim1; ++i)
delete[] _M[i];
delete[] _M;
}T
& operator()(const unsigned int i, const unsigned int j)
{
return _M[i][j];
} T
& operator()(const unsigned int i, const unsigned int j) const
{
return _M[i][j];
}
unsigned int dim1() const { return _dim1; };
unsigned int dim2() const { return _dim2; };
friend std::ostream & operator <<(std::ostream & out,
const Matrix<T>& m)
{
for (unsigned int i = 0; i < m._dim1; ++i){
for (unsigned int j = 0; j < m._dim2; ++j)
out << m._M[i][j] << ' ';
out << std::endl;
}
return out;
}
void swap(Matrix & other)
{
std::swap(_M, other._M);
std::swap(_dim1, other._dim1);
std::swap(_dim2, other._dim2);
}
private:
T** _M;
unsigned int _dim1, _dim2;
};Tensor class
#include <functional>
#include <unordered_map>
template <typename T1, typename T2, typename T3, typename V>
class Tensor
{
public:
V & operator()(const T1 i, const T2 j, const T3 k)
{
Point p(i, j, k);
return _M[p];
}V
& operator()(const T1 i, const T2 j, const T3 k)const
{
Point p(i, j, k);
return _M[p];
}
bool exist(const T1 i, const T2 j, const T3 k) const
{
Point p(i, j, k);
return (_M.find(p) != _M.cend());
}
void swap(Tensor<T1, T2, T3, V> & other)
{
std::swap(_M, other._M);
} T
ensor & operator = (Tensor<T1, T2, T3, V> & other)
{
swap(other);
return *this;
}
friend std::ostream & operator <<(std::ostream & out,const Tensor<T1, T2, T3, V>& ts)
{
for (const auto & p : ts._M)
std::cout << "(" << p.first.i << "," <<
p.first.j << "," << p.first.k << ")=" <<
p.second << std::endl;
return out;
}
private:
struct Point
{
T1 i; T2 j; T3 k;
Point(T1 p, T2 q, T3 r) : i(p), j(q), k(r) {};
bool operator == (const Point & right) const
{
return (i == right.i) & (j == right.j) &
(k == right.k);
}
};
struct hashPoint
{
size_t operator() (const Point & p) const
{
return std::hash<T1>()(p.i) ^
std::hash<T2>()(p.j) ^
std::hash<T3>()(p.k);
}
};
std::unordered_map<Point, V, hashPoint> _M;
};
