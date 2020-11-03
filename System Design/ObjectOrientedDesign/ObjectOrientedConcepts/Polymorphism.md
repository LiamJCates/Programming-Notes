Polymorphism is the capability to provide multiple implementations of an action and to select the
correct implementation based on the surrounding context. For example, a class might define two
versions of a method with different parameters. Or the same method might be defined both in a parent class and a subclass, the latter overriding the former for instances of the subclass.

Considering the is-a relationship defined previously, polymorphism can be thought of as using a subclass when a superclass has been asked for. The behavior of the subclass will remain, but the user of the polymorphic type is none the wiser.
