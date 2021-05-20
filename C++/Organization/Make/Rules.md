## Writing Rules

A rule appears in the makefile and says when and how to remake certain files, called the rule’s targets (most often only one per rule). It lists the other files that are the prerequisites of the target, and the recipe to use to create or update the target.

The order of rules is not significant, except for determining the default goal: the target for make to consider, if you do not otherwise specify one. The default goal is the target of the first rule in the first makefile. If the first rule has multiple targets, only the first target is taken as the default.

There are two exceptions:
	a target starting with a period is not a default unless it contains one or more slashes, ‘/’, as well
	a target that defines a pattern rule has no effect on the default goal.

## Rule Syntax

In general, a rule looks like this:

```make
targets : prerequisites
	recipe
	...
```

or like this:

```make
targets : prerequisites ; recipe
	recipe
	...
```

The targets are file names, separated by spaces.

Wildcard characters may be used
[Using Wildcard Characters in File Names]

Usually there is only one target per rule, but occasionally there is a reason to
have more. see [Multiple Targets in a Rule]


A rule tells make two things: when the targets are out of date, and how to update them when necessary.

The criterion for being out of date is specified in terms of the prerequisites, which consist of file names separated by spaces.

A target is out of date if it does not exist or if it is older than any of the prerequisites (by comparison of last-modification times). The idea is that the contents of the target file are computed based on information in the prerequisites, so if any of the prerequisites changes, the contents of the existing target file are no longer necessarily valid.

How to update is specified by a recipe. This is one or more lines to be executed by the shell (normally ‘sh’), but with some extra features



### Types of Prerequisites
There are actually two different types of prerequisites understood by GNU make:
	normal prerequisites, which consist of file names separated by spaces
	order-only prerequisites.


A normal prerequisite makes two statements:
	First, it imposes an order in which recipes will be invoked: the recipes for all prerequisites of a target will be completed before the recipe for the target is run.
	Second, it imposes a dependency relationship: if any prerequisite is newer than the target, then the target is considered out-of-date and must be rebuilt.

Occasionally, however, you have a situation where you want to impose a specific ordering on the rules to be invoked without forcing the target to be updated if one of those rules is executed. In that case, you want to define order-only prerequisites.

Order-only prerequisites can be specified by placing a pipe symbol (|) in the prerequisites list: any prerequisites to the left of the pipe symbol are normal; any prerequisites to the right are order-only:

targets : normal-prerequisites | order-only-prerequisites

The normal prerequisites section may of course be empty. Also, you may still declare multiple lines of prerequisites for the same target: they are appended appropriately (normal prerequisites are appended to the list of normal prerequisites; order-only prerequisites are appended to the list of order-only prerequisites).

Note that if you declare the same file to be both a normal and an order-only prerequisite, the normal prerequisite takes precedence
(since they have a strict superset of the behavior of an order-only prerequisite).
