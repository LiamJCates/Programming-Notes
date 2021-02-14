Relationships Between Classes
Three relationships are common among classes:
• Dependency ("uses")
• Aggregation ("has")
• Inheritance ("is")

Dependency
A class depends on another class if it manipulates objects of the other class in any way.
If a class can carry out all of its tasks without being aware that the other class even exists, then it doesn't use that class.
This shows that dependency is an asymmetric relationship.

One important design goal is to minimize the number of dependency relationships; that is, to minimize the coupling between classes.
If one class is unaware of the existence of another, it is also unconcerned about any changes in that other class.
A low degree of coupling tends to make it much easier to implement changes in the future.

Aggregation
Aggregation takes place if objects of one class contain objects of another class over a period of time.
Aggregation is a special case of dependency. Of course, if a class contains objects of another class, then it is acutely aware of the existence of that class. Aggregation is often informally described as the "has-a" relationship. A message queue has a message

With aggregation relationships, it is useful to keep track of these multiplicities. There may be a 1:1 or l:n relationship.
Aggregation is usually implemented through instance fields. This particular implementation can serve as a 1:1 or 1 :0 ... 1 relationship (if you allow myObject == null to indicate that there is no object).
For a 1:n relationship, you need an array or a collection object.

Inheritance
A class inherits from another if all objects of its class are special cases of objects of the other class, capable of exhibiting the same behavior but possibly with additional responsibilities and a richer state.
A subclass object must be usable in all situations in which a superclass object is expected.
Inheritance is often called the "is-a" relationship. This intuitive notion makes it easy to distinguish inheritance from aggregation. However, we must point out that inheritance is much less common than the dependency and aggregation relationships. Many designs can best be modeled by employing inheritance in a few selected places.
