Data Abstraction
Data abstraction is a programming (and design) technique that relies on the separation of interface and implementation.

Data abstraction enforces a clear separation between the abstract properties of a data type and the concrete details of its implementation.

  The abstract properties are those that are visible to client code and specify a stable interface to the data type.
  The concrete implementation is kept entirely private, and can change.

The idea is that such changes, for example to incorporate efficiency improvements over time, have no impact on client code, since they involve no difference in the abstract behavior utilized through a stable interface.

Data abstraction is achieved through encapsulation the details of an object's specification, then presenting an interface that is composed of essential information to client code while using data hiding to obfuscate specific implementation details.
