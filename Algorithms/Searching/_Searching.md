[Complexity.png]

The primary methods of searching are
Sequential
Binary


When using searching through a list, unless the list is sorted in some fashion, the only sure way to find a given value is to look at every value in the list. This is known as a sequential search.














## Searching by hashing
Hashing is a fundamental technique often used in practice since it is quite a simple technique to implement that has excellent empirical performances.

The two underlying ideas of hashing are:

– Convert object elements X into integer numbers x by a conversion function
x=I(X). The problem is then to transform a set of n integers sparsely lying
in N into a compact array of size m much less than n (written as m << n).

– Use an array to store the elements. Since arrays are of prescribed sizes, use a hashing function that operates some modulo operation to map an integer x into its hash index h(x).

The main problem hashing techniques have to deal with are collisions.

Collision occurs whenever two objects X and Y have been hashed into the same index.
That is, h(I(X)) is identical to h(I(Y)).

Often, the hashing function is taken as h(k) = k mod m, where m is a prime number.

Finding good hashing functions that minimize the risk of collisions, and adopting a good search/store policy in cases of collisions are the two challenging tasks of hashing
Interpolation Search












## Interpolation
An interpolation search, also known as an extrapolation search, is a technique for searching for a particular value in an ordered array.

Interpolation search resembles the method by which people search a telephone directory for a name (the key value by which the book's entries are ordered): in each step the algorithm calculates where in the remaining search space the sought item might be, based on the key values at the bounds of the search space and the value of the sought key, usually via a linear interpolation. The key value actually found at this estimated position is then compared to the key value being sought. If it is not equal, then depending on the comparison, the remaining search space is reduced to the part before or after the estimated position. This method will only work if calculations on the size of differences between key values are sensible.

An interpolation search; that is, instead of dividing the list into fixed halves, cuts it by an amount that seems most likely to succeed. This searching technique is more efficient than a binary search if the elements in the array are distributed in a practical manner.

For an interpolation search to be practical, two assumptions must be satisfied:
1. Each access must be very expensive compared to a typical instruction. For example, the array might be on a disk instead of in memory, and each comparison requires a disk access.

2. The data must not only be sorted, it must also be fairly uniformly distributed. For example, a phone book is fairly uniformly distributed. If the input items are {1, 2, 4, 8, 16, }, the distribution is not uniform.

These assumptions are quite restrictive, so you might never use an interpolation search. But it is interesting to see that there is more than one way to solve a problem and that no algorithm, not even the classic binary search, is the best in all situations.

On average the interpolation search makes about log(log(n)) comparisons (if the elements are uniformly distributed), where n is the number of elements to be searched. In the worst case (for instance where the numerical values of the keys increase exponentially) it can make up to O(n) comparisons.

The interpolation search requires that we spend more time to make an accurate guess regarding where the item might be. The binary search always uses the midpoint. However, searching for Hank Aaron in the middle of the phone book would be silly; somewhere near the start clearly would be more appropriate. Thus, instead of mid, we use next to indicate the next item that we will try to access:

[InterpolationNext.png]

The subtraction of 1 is a technical adjustment that has been shown to perform well in practice. Clearly, this calculation is more costly than the binary search calculation. It involves an extra division (the division by 2 in the binary search is really just a bit shift, just as dividing by 10 is easy for humans), multiplication, and four subtractions. These calculations need to be done using floating-point operations. One iteration may be slower than the complete binary search. However, if the cost of these calculations is insignificant when compared to the cost of accessing an item, speed is immaterial; we care only about the number of iterations.

In the worst case, where data is not uniformly distributed, the running time could be linear and every item might be examined. However, if we assume that the items are reasonably distributed, as with a phone book, the average number of comparisons has been shown to be . In other words, we apply the logarithm twice in succession. For N = 4 billion, is about 32 and is roughly 5. Of course, there are some hidden constants in the Big-Oh notation, but the extra logarithm can lower the number of iterations considerably, so long as a bad case does not crop up. Proving the result rigorously, however, is quite complicated.







## Iterative DFS
Here is an iterative version of DFS that uses an ArrayDeque to represent a stack of Node objects:
   private static void iterativeDFS(Node root) {
        Deque<Node> stack = new ArrayDeque<Node>();
        stack.push(root);
        while (!stack.isEmpty()) {
            Node node = stack.pop();
            if (node instanceof TextNode) {
                System.out.print(node);
            }
            List<Node> nodes = new ArrayList<Node>(node.childNodes());
            Collections.reverse(nodes);
            for (Node child : nodes) {
                stack.push(child);
            }
        }
    }

The parameter, root, is the root of the tree we want to traverse, so we start by creating the stack and
pushing the root onto it.
The loop continues until the stack is empty. Each time through, it pops a Node off the stack. If it gets a
TextNode, it prints the contents. Then it pushes the children onto the stack. In order to process the
children in the right order, we have to push them onto the stack in reverse order; we do that by
copying the children into an ArrayList, reversing the elements in place, and then iterating through the
reversed ArrayList.
One advantage of the iterative version of DFS is that it is easier to implement as a Java Iterator;
you’ll see how in the next chapter.
But first, one last note about the Deque interface: in addition to ArrayDeque, Java provides another
implementation of Deque, our old friend LinkedList. LinkedList implements both interfaces, List
and Deque. Which interface you get depends on how you use it. For example, if you assign a
LinkedList object to a Deque variable, like this:
Deqeue<Node> deque = new LinkedList<Node>();
you can use the methods in the Deque interface, but not all methods in the List interface. If you assign
it to a List variable, like this:
List<Node> deque = new LinkedList<Node>();
you can use List methods but not all Deque methods. And if you assign it like this:
LinkedList<Node> deque = new LinkedList<Node>();
you can use all the methods. But if you combine methods from different interfaces, your code will be
less readable and more error-prone.
