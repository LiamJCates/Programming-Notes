There are many aspects of code quality. We can talk about efficient code, which is code that runs fast or doesn't waste resources such as memory. It can also be source code that is easy to read and understand for us humans and therefore is easy to read and maintain.

Defining code quality
It is tough to define the meaning of quality when it comes to program code. The reason is that all developers will have their own opinion of what it means. One developer can argue that we should focus on writing readable code as it will be easier to understand and maintain and, by that, reduce the chance of us inserting any bugs into the code. Another developer could argue that we shall focus on writing compact code; that is, as few code lines as possible. Even if the code is harder to read, less code will give us fewer chances to introduce bugs in the code. Here, the two developers would argue for the same thing – fewer bugs in the code – with two contradictory positions.


CISQ's quality model
Many efforts to define a model for measuring code quality have been made, and one of the better known is CISQ's quality model.

The Consortium for Information Software Quality (CISQ) has defined five rules that can be used to measure the quality of code. It was first defined with business software in mind but was later extended to also include embedded systems, used mainly in Internet of Things (IoT) applications. These rules are as follows:

  Reliability: Reliability measures the level of risk and the likelihood of failures. It will also measure the defects that are injected into existing code when it is updated or modified. The goal of measuring reliability is to prevent the time an application can't run because of severe bugs.

  Performance efficiency: When an application is running, the speed with which it performs its operations depends on how the code is written and structured. Measuring the efficiency at a code level will help to improve both the overall response time of an application and how we identify the potential risk of applications that need to process data at a high speed that fail as they fail to process data fast enough.

  Security: The security rule will measure the likelihood of potential security breaches due to poor coding practices.

  Maintainability: When we are talking about the maintainability of code, we usually refer to three things. We say that the code should be, namely, adaptable, which is code that we can adapt to changes as per the requirements; portable, which is code that can be used on different platforms, such as different operating systems; and transferable, which is code that can be transferred from one development team to another.

This can be applied to, more or less, all code, but we want to be able to do all three of these with as little effort as possible.

  Size: Size is not a quality attribute per se, but the size of the code can have an impact on its maintainability. The more code we have, the harder it will be to navigate, understand, and follow its logic.

We have now talked about the quality aspects regarding code. But what about quality from the user's perspective? What the CISQ model focuses very little on is quality from the user's perspective. An application can match all the CISQ rules, but a user of this application may still consider it being of poor quality


Understanding user quality
Dr. Tom DeMarco, an American software engineer, has proposed that a product's quality is a function of how much it changes the world for the better.

This statement can be interpreted as meaning that an application's functional quality and user satisfaction are more important than the structural quality of the code.

The American computer scientist Gerald Weinberg has said that Quality is value to some person. This implies that quality is subjective – what one person would define as quality in an application might be the opposite for another person.

This view will focus on asking the questions
Who are the people that want to value our software?
What will be valuable to them?

With these definitions in mind, we will start to realize that crafting software is much more than just writing code. Even if the code has excellent quality, if the users don't like what we have created, they will not use it. It is like if we build a chair using the best craftsmanship, but if it is incredibly uncomfortable, no one will buy it.

We must, therefore, understand our users and their needs. Doing so is not always easy as our potential users might not know about these needs. Before you had your first smartphone, you did not miss it as you did not know what it could offer you. Now, on the other hand, you would miss it just after a few hours if it was taken away from you.

To get to the point where we understand our user's needs before they understand it, we need to use our imagination. We can start by asking some simple questions.

They could be,
what problem will this application solve?
Who will benefit from it?
Is there a pattern that the people who will benefit from using this application have in common?
What kind of applications does this group already use?
Are there features, patterns, or ideas used in those applications that we can reuse in our application to make this group more familiar with how our application works from the start?

When we have an idea about who our future users might be, we will need to focus on the flow within the application. We all know how frustrating it is when we use a program, or any other product for that matter, and we can't figure out what to do. We try one thing after the other, and rather soon, we lose all interest in using it. If you invest time and money in developing something, you should at least give that great idea of yours every chance to succeed.

Great! We now have an idea of what code quality is and we also understand the quality aspects from a user perspective. I am sure you want both in your software, so let's put them together.


Putting them together
If we think about it, the art of creating quality software is, of course, neither writing code with high quality nor writing an application that the users find valuable; it is both. As we have seen in earlier chapters, applications that are used will be updated, modified, and extended. This means that the code needs to be read by other programmers (or by us) if we want to find where changes need to be made. It will all boil down to a question about money. We want to create software that gives our users added value and we can sell our application. But maybe even more important is that the programmers that maintain the code of the application can work efficiently. If they can find a bug quickly, they will spend less time fixing it. If the code is easy to read and understand, the programmers will also have a higher chance of avoiding inserting new bugs into the code, thus reducing the cost of fixing them. One problem many programmers will face is that they are not given the time needed to create the quality code they want and that can be understood. Tight time schedules, managers who don't fully understand the importance of well-crafted code, and impatient customers can all be aspects that will force programmers to produce code quickly, resulting in a loss of quality. This is, of course, a very short-term approach. You might ship the software faster, but with lower quality, both for the users and for the programmers who will need to maintain the code in the future. This will most likely be less cost-efficient than crafting high-quality code to begin with. It should also be noted that if we start a project with poorly written code, this project will most likely always contain low-quality code as the cost of going back and improving all the code will be too high. We have everything to win if we do a good job and write quality code and deliver software that is considered high quality by our users. The rest of this chapter will not focus on user quality. That does not mean that it's not essential, but this is a book about writing code, so let's see how we can do that with quality and style.
