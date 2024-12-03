Concurrency Intro

How do you run code in parallel?
Java code is run in threads. When you start a simple application, such as a traditional Hello
World application, the code is run in the main thread. As you would expect, an application
needs at least one thread to run.
It is possible to create your own threads. Whenever you create a new thread, the code provided
to run in that thread will run immediately. Considering that it is not physically possible to run
more than one piece of code on a single CPU core at any one time, it is the job of the JVM to
manage these threads and schedule which thread to run and when.





To create a new thread, you construct a new Thread object. This object takes an instance of the
Runnable interface. The Runnable interface has one method, public void run(). Notice that to
start the thread, you do not ever call this run method. You call start on the thread object, which in
turn will call run once the JVM has created the new thread in order to run the code.
The Thread class is special, because it calls out to the JVM to create new threads to allow for parallel execution. If you look at the source code for the start method, you will see that it eventually
calls a private method called start0, which itself is a native method: It is implemented in the Java
Native Interface, specific to the host operating system.
A closer inspection of Listing 11-1 shows that it is doing three main operations: creating a new
thread, starting that thread, and then in both threads it is printing the name of the thread every second for five seconds. If you run this code a few times, you will see that the ordering between the two
threads may change: Sometimes the printed line from the main thread is first, and sometimes the
printed lined from the new thread is first. The JVM is deciding which thread to schedule to run.

   public class Threads {
        public static void main(String[] args) throws InterruptedException {
            final Thread separateThread = new Thread(new ThreadPrinter());
            separateThread.start();
            for (int i = 0; i < 5; i++) {
                System.out.println("From the main thread: " + Thread.currentThread().getName());
                Thread.sleep(1000);
            }
        }
    }

    public class ThreadPrinter implements Runnable {
        @Override
        public void run() {
            for (int i = 0; i < 5; i++) {
                System.out.println("From the new thread: " + Thread.currentThread().getName());
                try {
                    Thread.sleep(1000);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }
    }


The Try/Catch Block

Notice that you cannot add a throws declaration to the run method on the ThreadPrinter code in Listing 11-1, so the call to Thread.sleep must be surrounded in a try/catch block. The Runnable interface does not have a throws declaration, so neither can any implementing classes. When the Callable interface was introduced in Java 5, the call method was defined to throw any exception, so this means that the code can throw an exception itself rather than managing it in a try/catch block.
