Access modifiers in C++ class defines the access control rules.
Access controls restrict class-member access.

C++ has 3 access modifier keywords:
  public
  private
  protected

These access modifiers are used to set boundaries for availability of members of a class.

Access modifiers are followed by a colon.

They change the boundary for all the declarations that follow them:

  Public class members are available to all class clients.
  Private class members are not available to any code outside of the class.
  Protected class members are available inside the class and to any derived class.

Invalid access will result in a compile time error

Protected
When you create a class, member functions can access both public and private member variables and functions. Users of the class can access only the
public member variables and functions. But when you derive a new class,
the picture changes. The derived class cannot access the private members in
its own class. Private members are reserved for a class itself and not for any
derived class.

When members need to be accessible by derived classes we specify the protected access modifier.

Protected members and private members work the same way, but derived
classes can access only protected members, not private members.
