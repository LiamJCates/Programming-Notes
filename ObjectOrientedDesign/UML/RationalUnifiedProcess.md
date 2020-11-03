UML covers all the aspects of the usual software development process. Now
we have said that UML itself is not a step-by-step process or methodology
for building software. However, the designers of UML have provided enough
diagram types and symbols that it can be used with all the different steps
of software development. Therefore, to learn UML, learning a methodology
along with it is a good idea. In fact, the people who designed UML, The Three
Amigos (see the nearby sidebar by that name), have also designed a methodology. Theirs is called the Rational Unified Process (RUP, pronounced rup—
like up with an R added). That’s the methodology we use. (And to be quite
frank, most methodologies are more or less the same.)

Rational Unified Process, or RUP. There are five main steps
(which tend to be the same for most methodologies). These main steps,
which are called workflows, are as follows:
1. Requirements
2. Analysis
3. Design
4. Implementation
5. Testing





So you know what happened, but why did it happen? Finally, you put your
finger on it: It’s another chicken-and-egg syndrome, and it goes like this: How
could you have known you needed a low-level communications system until
you finally started coding the thing? Yet, you needed that information while
you were in the analysis and design workflows, before you started coding it!
In effect, which comes first, the chicken (the analysis and design) or the egg
(the realization that you need a low-level communications system)?
Although this might sound horribly apocryphal, it happens all the time in
the software world. If you want to see tempers flare, visit some software
engineers when such an abysmal situation arises.
Well, we think we’ve made our point, but before you rush off to the psychiatrist for a nice, big supply of antidepressants, fear not: RUP is here to save
the day!
www.it-ebooks.info292 Building with UML and the Rational Unified Process
The designers of RUP knew well that these problems occur. And thus, they
made a set of higher-level processes called phases, and put the five workflows inside these higher levels. During each phase, you cycle through several of the five workflows. Then when you’re finished, you can cycle through
them again, or you can move on to the next phase. And you once again cycle
through several of the five workflows.
The idea is that each time you cycle through several of the workflows, you
finish an iteration.
Phasing in and out
RUP consists of four main phases. In each phase, you focus on various
workflows, such as analysis or design, but you are free to move forward to
later workflows. The only catch is that, although you can start and stop at
any workflow, you must complete all the workflows in between for a single
iteration. For example, you can’t jump from analysis to test; you must first
do analysis, then design, then implementation, and finally test. Here are the
phases of RUP:
✦ Inception: During this phase, you determine the objectives of your
software.
✦ Elaboration: In this phase, you analyze and design your software.
✦ Construction: This is when you focus primarily on coding the software.
✦ Transition: This final phase is when you deliver the software. For retail
software, this means sending it to the disc duplicators and packagers;
for in-house software, it means shipping it to the groups who will be
using it.
And here’s the really great part: Each of these four phases can be a whole set
of workflows: Requirements, analysis, design, implementation, and testing.
But how can that be, my dear friend, you ask? It goes like this: In the inception
phase, you gather requirements and go through the process of getting some
basic analysis and design down. And if need be, you even do some rough
prototypes of the software, where you basically play around and try out
some things. In effect, you do a basic coding (implementation). And yes, you
might even spend a little time testing it. But you’re not building a full-scale
software system, by any means! You’re just doing pieces and parts and parts
and pieces. But more so, you’re doing a proof of concept just to see if you
think, as a professional engineer, this idea is going to fly. And undoubtedly,
you will run into some issues that the original requirements failed to take
into account


Now if you’re building a super-cool Web browser that specializes in mindreading, during the inception phase you might do a basic prototype that has
all the major features, even if they don’t work well. But during that time, you
spot something you left out: the communications system. But now you know
that you need it! So you return to the analysis phase, where you can actually
add it, perhaps as a component. Cool, no?
Now each time you backtrack through your workflows and change something, you begin a new iteration. Therefore, you can see that the phases are
broken up into iterations, each with several of the five workflows. And you
may go through several iterations within a single phase.
You don’t have to get all the way to the end, to the testing workflow, before
you back up. Thus, each iteration might consist of only one or two
workflows.
If all this sounds a little strange, look at it this way: If you discover that you
don’t have something quite right, what do you do? You go back and fix it! But
software engineers like to sound a bit more technical than that, so instead
they say that they begin a new iteration.















The inception phase
The inception phase is the first phase. During this phase, you may not make it to the point where you’re coding a prototype and finding problems. But if you’re building a big project,
you just may make it to the point of writing small prototypes of only various portions of the project.

And during the inception phase, you try to do the following:
✦ Determine feasibility
✦ Determine primary requirements.

The term feasibility is a word that comes up again and again, and it’s primarily the result of people having great ideas but later determining that, well, frankly, those ideas are not practical or reasonable. But instead, businesses prefer the kinder, gentler term, feasible.

Requirements gathering is a particularly touchy issue because, during that time, people are going to want to include everything. Not only will they want the software to browse the Web, but they will also want it to inject the Web page back into your brain and also give you the ability to download it straight from your brain to your friends’ brains and print a copy by just laying your finger on the printer. They want the software to do everything.
But thankfully, during this time, you start to map out the project, probably build some prototypes, and determine what it really should do. Is it feasible to transfer the pages back into the brain, or is that technology not going to come for another year or two? If not, it probably isn’t feasible.


The goal in this phase is to solidify the requirements and do some basic analysis. During this time, you will get people to agree to what it is you’re going to build. (These people are called stakeholders because they hold a big stake — like their jobs — in the success of this software. And when you finish writing it for them and they become millionaires, they will treat themselves to a nice, big steak.) You will also get them to agree on things such
as what computers the software will run on and the software’s limits. For example, can the browser read multiple people’s brains or just one person’s brain at a time? (That’s a limit.) And will it run on Windows, or will it also run= on Macintosh, Unix, and Linux?
And, of course, the business folks will want a bit of say in all this, too. So the
goals of this phase will also include things such as a schedule and cost for
the project: How soon will you have it completed, and how much will it cost
the business? Will you need to hire more engineers to work on the project?
And will you need to buy more computers and tools, such as compilers?
And finally at the end of this phase, you will want to have a basic architecture of the system, consisting of UML diagrams. Now these diagrams may be
rough and basic, but they will provide an overall outline of the system.









The elaboration phase
During the elaboration phase, you solidify the functionality of your software.
You use tools called use cases — descriptions of individual pieces of the
software functionality. For example, a word processor would have use cases
such as set italic on, set italic off, print, set left-align, and delete a page. The
use cases are all the things you can do with the software.
www.it-ebooks.infoBook II
Chapter 2
Describing Your
Program with UML
Building with UML and the Rational Unified Process 295
Also during the elaboration phase, you develop a plan for when you build
the thing. This means elaborating on the basic designs you created in the
inception phase by going through more analysis and design.
Some of the major goals of the elaboration phase are to finalize the scope of
the software and to incorporate any changes to the software (for example,
after further inspection, you may have determined that more things were not
feasible and that other parts were); to finalize the project plan, including the
number of people you need and how long it will take; and to make sure the
stakeholders are all happy and hunky-dory with the project.
And during the elaboration phase, you also create a first, rough-draft version
of the software. Yes, you may have built some code in the inception phase,
but that was just prototyping for determining feasibility. You don’t use that
rough code from the inception phase in the real coding. Here, however, you
make a first run of coding the real application. To get there, you continue
with your analysis and design, and get into coding (implementation). Of
course, the software is just a rough draft, but it is more than a prototype;
unlike the preceding phase, in the elaboration phase you’ll be saving much
of the code and reusing it for the next phase. Thus, you once again move
through iterations, cycling through workflows, such as analysis, design, and
implementation.








The construction phase
During the construction phase, you continue with the implementation. But by
now, all your analysis and design should be pretty much finished. Everybody
(including the famous stakeholders) agrees by now on what the software will
and won’t do, how much it will cost, how long it will take to build it, and how
many people will work on it. But further, you have drawn up your groups
of classes that you will be designing and have decided how the classes fit
together and how they communicate with each other. The analysis and design
is ready for prime time, and now you can focus on actually making the system
work. Here you look for parts that don’t quite fit together, and you fix problems to make them fit together. You make sure that your system has no major
holes whereby the entire thing could come to a crashing halt under a strange,
unexpected situation. In a word, you make your software stable.
If you were involved with computers in the early 1990s, when things were
finally settling down and we were starting to see practical, real software,
you probably also saw something else: little error messages that popped up
called general protection faults (GPFs). GPFs appeared when the application
really screwed up bad, and the only way to fix the application was to attempt
to click the Ignore button to ignore the error (an option that, trust us, never
worked) or abort the application. We remember those days well because
they made us start to consider job offers from distant cousins who rented
beach umbrellas on the Gulf of Mexico.

Now why did these errors happen? Because the software wasn’t stable. You
managed to put the software into a situation that the programmers didn’t
expect, and the thing choked, coughing up a general protection fault. And
why did the programmers create software that allowed this situation to
occur? Because they didn’t thoroughly go through the construction phase!
The construction phase includes implementation and testing workflows. You
may have some analysis and design flaws, but they will be little; the main time
you’ll see these flaws is if you find you forgot something or need to change
something in the classes. By now, you will be going through iterations of writing code, testing, testing, testing, and finally more testing. When the testers
encounter errors, you go back and fix the code. Then, eventually, the testers
determine that they can’t find any more bugs. The day is done! You are ready
to ship.
Thus, if you follow the construction phase properly, you will limit the
number of operating system errors that pop up when your application goes
haywire — because if you did everything correctly, it shouldn’t go haywire.
If you are heading up a project where you will be using RUP to design a largescale software system, you will want to give your testers a certain amount of
authority. Think of the testers as the quality assurance people. And in fact,
some companies call them Q/A engineers instead of testers. Your testers
shouldn’t allow your company to put its name on the software until they say it
works. This has multiple benefits because it allows the Q/A engineers to feel a
certain amount of authority, and it also puts a heavy responsibility on them,
which will help ensure that they do a thorough job. And that will help ensure
that your software is both good and stable. Sounds like a good plan to us!






The transition phase
The transition phase is both the happiest time and the scariest. As a software engineer, we know that this can be a frightening time because the final
moment of truth has arrived: Did you and the rest of the team build a product that is actually going to work? Or is it going to get out on the customer’s
computer and crash and burn?
Most likely, because you did everything correctly in the first three phases,
the software will run on the customer’s computers. However, just because
you did it right doesn’t mean that you won’t be anxious. But relax: If you
are shipping a piece of software to one specific customer, you and the other
engineers will probably be on hand that day for the big installation. It may
not go perfectly at first, but in our experience most of the problems will not
involve faulty software. Rather, the customer’s computers will not be set up
quite right. Fortunately, such problems are pretty easy to track down and fix.

But if you’re shipping software that will be sold through the retail chains to
potentially millions of people, the transition phase has an important step that
many companies don’t think of. In this final step, you choose a workday and
invite all the employees who want to come in for a giant beat-up-the-software
party. Yeah! They all come in, and you pass out CD-ROMs containing your
software. These are copies of the CD-ROM you intend to ship, assuming that
all goes well today. The employees get free pizza and soft drinks (beer isn’t
allowed on company property; besides, you want them thinking clearly!), and
they get to beat the stuffing out of your software. They install it, play with it,
manipulate it, use it, fiddle with it, and do everything they can with it; and in
the process, give it a pounding it will never forget. And if they encounter a
problem, they let you know (politely, of course). But your personal job, on this
day, is not to join them in testing the software. Your job is to get to work fixing
any problems they find. Generally, they will be minor problems, and you’ll be
able to crank out the fixes in no time.
If you actually have a big test day like this, try to make it as exciting as possible. Free pizza, free soft drinks, maybe loud, fun music blasting, and maybe a
relaxation room where people can go and goof off for a few minutes and
forget about the project. Believe us, these folks will enjoy this special day if
you make it exciting for them. And the result, of course, is a successful software package.
