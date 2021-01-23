Introduction
Know the theoretical knowledge of the algorithm is essential, but it is not sufficient. You need to have a systematic approach to solve a problem.

We will follow a systematic five-step approach to reach to our solution.

Master this approach and you will be better than most of the candidates in
interviews.
Five steps for solving algorithm design questions are:
1. Constraints
2. Ideas Generation
3. Complexities
4. Coding
5. Testing

Constraints
Solving a technical question is not just about knowing the algorithms and designing a good software system. The interviewer wants to know you approach towards any given problem. Many people make mistakes, as they do not ask clarifying questions about a given problem. They assume many
things and begin working with that. There are a lot of data that is missing
that you need to collect from your interviewer before beginning to solve a
problem.
In this step, you will capture all the constraints about the problem. We
should never try to solve a problem that is not completely defined.
Interview questions are not like exam paper where all the details about a
problem are well defined. In the interview, the interviewer actually expects
you to ask questions and clarify the problem.
For example: When the problem statement says that write an algorithm to
sort numbers.
The first information you need to capture is what king of data. Let us
suppose interviewer respond with the answer Integer.
The second information that you need to know what is the size of data. Your
algorithm differs if the input data size if 100 integers or 1 billion integers.
Basic guideline for the Constraints for an array of numbers:
1. How many numbers of elements in the array?
2. What is the range of value in each element? What is the min and max
value?
3. What is the kind of data in each element is it an integer or a floating
point?
4. Does the array contain unique data or not?
Basic guideline for the Constraints for an array of string:
1. How many numbers of elements in the array?2. What is the length of each string? What is the min and max length?
3. Does the array contain unique data or not?
Basic guideline for the Constraints for a Graph
1. How many nodes are there in the graph?
2. How many edges are there in the graph?
3. Is it a weighted graph? What is the range of weights?
4. Is the graph directed or undirected?
5. Is there is a loop in the graph?
6. Is there negative sum loop in the graph?
7. Does the graph have self-loops?
We have already seen this in graph chapter that depending upon the
constraints the algorithm applied changes and so is the complexity of the
solution.Idea Generation
We have covered a lot of theoretical knowledge in this book. It is
impossible to cover all the questions as new ones are created every day.
Therefore, we should know how to handle new problems. Even if you know
the solution of a problem asked by the interviewer then also you need to
have a discussion with the interviewer and reach to the solution. You need
to analyze the problem also because the interviewer may modify a question
a little bit and the approach to solve it will vary.
Well, how to solve a new problem? The solution to this problem is that you
need to do a lot of practice and the more you practice the more you will be
able to solve any new question, which come in front of you. When you have
solved enough problems, you will be able to see a pattern in the questions
and able to solve new problems easily.
Following is the strategy that you need to follow to solve an unknown
problem:
1. Try to simplify the task in hand.
2. Try a few examples
3. Think of a suitable data-structure.
4. Think about similar problems you have already solved.
Try to simplify the task in hand
Let us look into the following problem: Husbands and their wives are
standing in random in a line. They have been numbered for husbands H1,
H2, H3 and so on. And their corresponding wives have number W1, W2,
W3 and so on. You need to arrange them so that H1 will stand first,
followed by W1, then H2 followed by W2 and so on.
At the first look, it looks difficult, but it is a simple problem. Try to find a
relation of the final position.
P(Hi) = i*2 – 1, P(Wi) = i*2
The rest of the algorithm we are leaving you to do something like InsertionSort and you are done.Try a few examples
In the same above problem if you have tried it with some example for 3
husband and wife pair then you may have reached to the same formula that
we have shown in the previous section. Some time thinking some more
examples try to solve the problem at hand.
Think of a suitable data-structure
For some problems, it is straight forward which data structure will be most
suitable for. For example, if we have a problem finding min/max of some
given value, then probably heap is the data structure we are looking for. We
have seen a number of data structure throughout this book. And we have to
figure out which data-structure will suite our need.
Let us look into a problem: We are given a stream of data at any time we
can be asked to tell the median value of the data and maybe we can be
asked to pop median data.
We can think about some sort of tree, may be balanced tree where the root
is the median. Wait but it is not so easy to make sure the tree root to be a
median.
A heap can give us minimum or maximum so we cannot get the desired
result from it too. However, what if we use two heap one max heap and one
min heap. The smaller values will go to min heap and the bigger values will
go to max heap. In addition, we can keep the count of how many elements
are there in the heap. The rest of the algorithm you can think yourself.
For every new problem think about the data structure, you know and may
be one of them or some combination of them will solve your problem.
Think about similar problems you have already solved. Let us suppose you
are given, two linked list head pointers and they meet at some point and
need to find the point of intersection. However, in place of the end of both
the linked list to be a null pointer there is a loop.You know how to find intersection point of two intersecting linked list, you
know how to find if a linked list have a loop (three-pointer solution).
Therefore, you can apply both of these solutions to find the solution of the
problem in hand.Complexities
Solving a problem is not just finding a correct solution. The solution should
be fast and should have reasonable memory requirement. You have already
read about Big-O notation in the previous chapters. You should be able to
do Big-O analysis. In case you think the solution you have provided is not
that optimal and there is some more efficient solution, then think again and
try to figure out this information.
Most interviewers expect that you should be able to find the time and Space
Complexity of the algorithms. You should be able to compute the time and
Space Complexity instantly. Whenever you are solving some problem, you
should find the complexity associated with it from this you would be able to
choose the best solutions. In some problems there is some trade-offs
between space and Time Complexity, so you should know these trade-offs.
Sometime taking some bit more space saves a lot of time and make your
algorithm much faster.Coding
At this point, you have already captured all the constraints of the problem,
proposed few solutions, evaluated the complexities of the various solutions
and picked the one solution to do final coding. Never ever, jump into
coding before discussing constraints, Idea generation and complexity with
the interviewer.
We are accustomed to coding in an IDE like visual studio. So many people
struggle when asked to write code on a whiteboard or some blank sheet.
Therefore, we should have a little practice to the coding on a sheet of paper.
You should think before coding because there is no back button in sheet of
paper. Always try to write modular code. Small functions need to be created
so that the code is clean and managed. If there is a swap function so just use
this function and tell the interviewer that you will write it later. Everybody
knows that you can write swap code.Testing
Once the code is written, you are not done. It is most important that you test
your code with several small test cases. It shows that you understand the
importance of testing. It also gives confidence to your interviewer that you
are not going to write a buggy code. Once you are done with, your coding it
is a good practice that you go through your code line by line with some
small test case. This is just to make sure your code is working as it is
supposed to work.
You should test few test cases.
Normal test cases: These are the positive test cases, which contain the most
common scenario, and focus is on the working of the base logic of the code.
For example, if we are going to write some algorithm for linked list, then
this may contain what will happen when a linked list with 3 or 4 nodes is
given as input. These test cases you should always run in your head before
saying the code is done.
Edge cases: These are the test cases, which are going to test the boundaries
of the code. For the same linked list algorithm, edge cases may be how the
code behaves when an empty list is passed or just one node is passed. These
test cases you should always run in your head before saying the code is
done. Edge cases may help to make your code more robust. Just few checks
need to be added to the code to take care of the condition.
Load testing: In this kind of test, your code will be tested with a huge data.
This will allow us to test if your code is slow or too much memory
intensive.
Always follow these five steps never jump to coding before doing
constraint analysis, idea generation, and Complexity Analysis: At least
never, miss the testing phase.Example
Let us suppose the interviewer ask you to give a best sorting algorithm.
Some interviewee will directly jump to Quick-Sort O(nlogn). Oops,
mistake you need to ask many questions before beginning to solve this
problem.
Questions 1: What kind of data we are talking about? Are they integer s?
Answer: Yes, they are integer s.
Questions 2: How much data are we going to sort?
Answer: May be thousands.
Questions 3: What exactly is this data about?
Answer: They store a person’s age
Questions 4: What kind of data-structure used to hold this data?
Answer: Data are given in the form of some array
Questions 5: Can we modify the given data-structure? In addition, many,
many more…?
Answer: No, you cannot modify the data structure provided
Ok from the first answer, we will deduce that the data is integer. The data is
not so big it just contains a few thousand entries. The third answer is
interesting from this we deduce that the range of data is 1-150. Data is
provided in an array. From fifths answer we deduce that we have to create
our own data structure and we cannot modify the array provided. So finally,
we conclude, we can just use bucket sort to sort the data. The range is just
1-150 so we need just 151-capacity integral array. Data is under thousands
so we do not have to worry about data overflow and we get the solution in
linear time O(N).
Note: We will read sorting in the coming chapters.Summary
At this point, you know the process of handling new problems very well. In
the coming chapter we will be looking into a lot of various data structure
and the problems they solve. A huge number of problems are solved in this
book. However, it is recommended to first try to solve them by yourself,
and then look for the solution. Always think about the complexity of the
problem. In the interview interaction is the key to get problem described
completely and discuss your approach with the interviewer.
