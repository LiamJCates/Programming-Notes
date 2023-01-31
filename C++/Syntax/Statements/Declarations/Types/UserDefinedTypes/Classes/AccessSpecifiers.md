Class Access Specifiers

Access specifiers / modifiers in C++ classes define access control rules.
Access controls restrict access to effected class members.

C++ has 3 access specifier keywords:
  public
  private
  protected

They change the boundary for all the declarations that follow them:

  Public members are available to all class clients.
  Private members are not available to any code outside of the class.
  Protected members are available inside the class and to friends or derived classes.

Invalid access will result in a compile time error.

class class_name
{
  private:
    // private_member_list
  protected:
    // protected_member_list
  public:
    // public_member_list
}

Syntax Rules:
  Access specifier are followed by a colon.
  There are no restrictions on how often an access label may appear.
  Each access label specifies the access level of subsequent member definitions.
  The specified access level remains in effect until the next access label is encountered or the closing right brace of the class body.
  The default access specifier for classes is private and structs is public.
