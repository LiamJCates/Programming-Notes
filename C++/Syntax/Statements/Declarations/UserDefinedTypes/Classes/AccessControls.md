Access modifiers in C++ class defines the access control rules.
Access controls restrict class-member access.

C++ has 3 access modifier keywords:
  public
  private
  protected

These access modifiers are used to set boundaries for availability of members of a class.

Access modifiers are followed by a colon.

There are no restrictions on how often an access label may appear. Each access label specifies the access level of the succeeding member definitions. The specified access level remains in effect until the next access label is encountered or the closing right brace of the class body is seen.

They change the boundary for all the declarations that follow them:

  Public class members are available to all class clients.
  Private class members are not available to any code outside of the class.
  Protected class members are available inside the class and to any friends or derived classes.

Invalid access will result in a compile time error
