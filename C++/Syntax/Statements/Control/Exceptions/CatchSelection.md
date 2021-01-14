When an exception is thrown, it may be caught by the following types of catch handlers:

    A handler that can accept any type (using the ellipsis syntax, ...).

    A handler that accepts the same type as the exception object; because it is a copy, const and volatile modifiers are ignored.

    A handler that accepts a reference to the same type as the exception object.

    A handler that accepts a reference to a const or volatile form of the same type as the exception object.

    A handler that accepts a base class of the same type as the exception object; since it is a copy, const and volatile modifiers are ignored. The catch handler for a base class must not precede the catch handler for the derived class.

    A handler that accepts a reference to a base class of the same type as the exception object.

    A handler that accepts a reference to a const or volatile form of a base class of the same type as the exception object.

    A handler that accepts a pointer to which a thrown pointer object can be converted via standard pointer conversion rules.

The order in which catch handlers appear is significant, because handlers for a given try block are examined in order of their appearance. For example, it is an error to place the handler for a base class before the handler for a derived class. After a matching catch handler is found, subsequent handlers are not examined. As a result, an ellipsis catch handler must be the last handler for its try block.
