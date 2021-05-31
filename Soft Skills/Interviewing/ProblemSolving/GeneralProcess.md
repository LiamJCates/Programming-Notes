## Solving Problems

When you begin solving a problem, don’t start writing code immediately. First, make sure you completely understand the problem. It may help to work through a simple, concrete example and then try to generalize the process to an algorithm. When you’re convinced you have the right algorithm, explain it clearly. Writing the code should be one of your final steps.

Listen Carfully
Draw an Example
State a Brute Force solution
Optimize
Walk Through
Implement
Test



Optimization Technique

BUD
looking for
	Bottlenecks
	Unnecessary Work
	Duplicated Work





### Basic Steps

The best way to solve an interview problem is to approach it methodically:

1. Make sure you understand the problem.

Your initial assumptions about the problem may be wrong, or the interviewer’s explanation may be brief or difficult to follow. You can’t demonstrate your skills if you don’t understand the problem. Don’t hesitate to ask your interviewer questions, and don’t start solving the problem until you understand it. The interviewer may be deliberately obscuring things to determine whether you can find and understand the actual problem. In these cases, asking the right clarifying questions is an important part of the correct solution.

2. When you understand the question, try a simple example.

This example may lead to insights about how to solve the general problem or bring to light any remaining misunderstandings that you have. Starting with an example also demonstrates a methodical, logical thought process. Examples are especially useful if you don’t see the solution right away.

3. Focus on the algorithm and data structures you will use to solve the problem.

This can take a long time and require additional examples. This is to be expected. Interactivity is important during this process. If you stand quietly staring at the whiteboard, the interviewer has no way of knowing whether you’re making productive headway or are simply clueless. Talk to your interviewer about what you are doing. For example, you might say something like, “I’m wondering whether I can store the values in an array and then sort them, but I don’t think that will work because I can’t quickly look up elements in an array by value.” This demonstrates your skill, which is the point of the interview, and may also lead to hints from the interviewer, who might respond, “You’re close to the solution. Do you really need to look up elements by value, or could you….” It may take a long time to solve the problem, and you may be tempted to begin coding before you figure out a complete solution. Resist this temptation. Consider who you would rather work with: someone who thinks about a problem for a long time and then codes it correctly the first time or someone who hastily jumps into a problem, makes several errors while coding, and doesn’t have any idea what direction to take. Not a difficult decision, is it?

4. After you figure out your algorithm and how you can implement it, explain your solution to the interviewer.

This provides an opportunity to evaluate your solution before you begin coding. Your interviewer may say, “Sounds great, go ahead and code it,” or something like, “That’s not quite right because you can’t look up elements in a hash table that way.”

Another common response is “That sounds like it will work, but there’s a more efficient solution.” In any case, you gain valuable information about whether you should move on to coding or go back to working on the algorithm.

5. While you code, explain what you’re doing.

For example, you might say, “Here, I’m initializing the array to all zeros.” This narrative enables the interviewer to follow your code more easily.

6. Ask questions when necessary.

You generally won’t be penalized for asking factual questions that you might otherwise look up in a reference. You obviously can’t ask a question such as, “How do I solve this problem?” but it is acceptable to ask a question such as, “I can’t remember — what format string do I use to print out a localized date?” Although it’s better to know these things, it’s okay to ask this sort of question.

7. After you write the code for a problem, immediately verify that the code works by tracing through it with an example.

This step demonstrates clearly that your code is correct in at least one case.

It also illustrates a logical thought process and your intention to check your
work and search for bugs. The example may also help you flush out minor bugs in your solution.

8. Make sure you check your code for all error and special cases, especially boundary conditions.

Programmers often overlook error and special cases; forgetting these cases in an interview indicates you might forget them on the job. If time does not allow for extensive checking, at least explain that you should check for such failures. Covering error and special cases can impress your interviewer and help you correctly solve the problem.


After you try an example and feel comfortable that your code is correct, the interviewer may ask you questions about what you wrote. These questions often focus on running time, alternative implementations, and complexity (discussed later in this chapter).

If your interviewer does not ask you these questions, you should volunteer the information to show that you are cognizant of these issues. For example, you could say, “This implementation has linear running time, which is the best achievable running time since I need to check all the input values. The dynamic memory allocation will slow it down a little, as will the overhead of using recursion.



### When You Get Stuck

Getting stuck on a problem is expected and an important part of the interviewing process.

Interviewers want to see how you respond when you don’t recognize the answer to a question immediately. Giving up or getting frustrated is the worst thing to do if this happens to you. Instead, show interest in the problem and keep trying different ways to solve it:

➤ Go back to an example.
Try performing the task and analyzing what you are doing. Try extending your specific example to the general case. You may have to use detailed examples. This is okay, because it shows the interviewer your persistence in finding the correct solution.

NOTE When all else fails, return to a specific example. Try to move from the
specific example to the general case and from there to the solution.

➤ Try a different data structure.
Perhaps a linked list, an array, a hash table, or a binary search tree can help. If you’re given an unusual data structure, look for similarities between it and more familiar data structures. Using the right data structure often makes a problem much easier.

➤ Consider the less commonly used or more advanced aspects of a language.

Sometimes the key to a problem involves one of these features.

Even when you don’t feel stuck, you may not be converging on the optimal solution. You may miss an elegant or nonobvious way to implement something. Pause every once in a while to reconsider the bigger picture and whether there may be a better approach. One sign that you may be off track is if you find yourself writing too much code. Almost all interview coding questions have short answers.
You rarely need to write more than 30 lines of code and almost never more than 50. If you start writing a lot of code, you may be heading in the wrong direction.


### ANALYZING YOUR SOLUTION

After you answer the problem, you may be asked about the efficiency of your implementation. Often, you have to compare trade-offs between your implementation and another possible solution and identify the conditions that make each option more favorable. Common questions focus on run time and memory usage.

A good understanding of Big-O analysis is critical to making a good impression with the interviewer. Big-O analysis is a form of runtime analysis that measures the efficiency of an algorithm in terms of the time it takes for the algorithm to run as a function of the input size. It’s not a formal benchmark, just a simple way to classify algorithms by relative efficiency when dealing with very large input sizes.

For information about algorithm analysis, see:
[Algorithms\Analysis]
