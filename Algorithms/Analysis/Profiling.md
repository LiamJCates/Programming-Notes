Profiling

for(int i = 10,000 i < 1000000000; i *= 2)
double start = System.currentTimeMillis() / 1000.0;
testMethod(i);
double now  = System.currentTimeMillis() / 1000.0;
StdOut.printf("input size: %d \t(%.0f seconds)\n", i, now - start);


A concrete example.
 To illustrate the approach, we start with ThreeSum.java [https://introcs.cs.princeton.edu/java/41analysis/ThreeSum.java.html] which counts the number of triples in an array of n integers that sums to 0. What is the relationship between the problem size n and running time for ThreeSum?
Doubling hypothesis.
For a great many programs, we can quickly formulate a hypothesis for the following question: What is the effect on the running time of doubling the size of the input?
Empirical analysis.
One simple way to develop a doubling hypothesis is to double the size of the input and observe the effect on the running time. DoublingTest.java [https://introcs.cs.princeton.edu/java/41analysis/ThreeSum.java.html] generates a sequence of random input arrays for ThreeSum, doubling the array length at each step, and prints the ratio of running times of ThreeSum.count() for each input over the previous (which was one-half the size). If you run this program, you will find that the elapsed time increases by about a factor of 8 to print each line. This leads immediately to the hypothesis that the running time increases by a factor of 8 when the input size doubles.

Log–logplot. We might also plot the running times on a standard plot (left) or log–log plot (right). The log–log plot is a straight line with slope 3, suggesting the hypothesis that the running time satisfies a power law of the form cn^3.

[standard-plot.png] [log-log-plot.png]

A Profiler that contains code that runs a method with a range of problem sizes, measures runtimes, and plots the results.
You will use Profiler to classify the performance of the add method for the Java implementations of
ArrayList and LinkedList.
Here’s an example that shows how to use the profiler:

public class ProfileListAdd {

    public static void main(String[] args) {
        profileArrayListAddEnd();
    }

    /**
     * Characterize the run time of adding to the end of an ArrayList
     */
    public static void profileArrayListAddEnd() {
        Timeable timeable = new Timeable() {
            List<String> list;

            public void setup(int n) {
                list = new ArrayList<String>();
            }

            public void timeMe(int n) {
                for (int i=0; i<n; i++) {
                    list.add("a string");
                }
            }
        };
        int startN = 4000;
        int endMillis = 1000;
        runProfiler("ArrayList add end", timeable, startN, endMillis);
    }

    private static void runProfiler(String title, Timeable timeable, int startN, int endMillis) {
        Profiler profiler = new Profiler(title, timeable);
        XYSeries series = profiler.timingLoop(startN, endMillis);
        profiler.plotResults(series);
    }
}



This method measures the time it takes to run add on an ArrayList, which adds the new element at
the end. I’ll explain the code and then show the results.
In order to use Profiler, we need to create a Timeable object that provides two methods: setup
and timeMe. The setup method does whatever needs to be done before we start the clock; in this
case it creates an empty list. Then timeMe does whatever operation we are trying to measure; in this
case it adds n elements to the list.
The code that creates timeable is an anonymous class that defines a new implementation of the
Timeable interface and creates an instance of the new class at the same time.
