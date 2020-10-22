A declaration introduces its name into a scope:
• Local scope: A name declared in a function (§1.3) or lambda (§6.3.2) is called a local name. Its scope extends from its point of declaration to the end of the block in which its declaration  occurs.  A block is  delimited by a {} pair.  Function  argument  names  are  considered local names.

• Class scope: A name is called a member name(or a class member name) if it is defined in a class  (§2.2,  §2.3,  Chapter  4),  outside  any  function  (§1.3),  lambda  (§6.3.2),  or enum  class(§2.5).   Its scope  extends  from  the  opening { of  its  enclosing  declaration  to  the  end  of  that declaration.

• Namespace scope: A name is called a namespace member name if  it  is  defined  in  a  name-space  (§3.4)  outside  any function,  lambda  (§6.3.2),  class  (§2.2,  §2.3,  Chapter  4),  or enum class(§2.5).  Its scope extends from the point of declaration to the end of its namespace.

A  name  not  declared  inside  any  other  construct  is  called  a global  name and  is  said  to  be  in  the global namespace.

An object must be constructed (initialized) before it is used and will be destroyed at the end of its scope.  For a namespace object the point of destruction is the end of the program.  For a member, the point of destruction is determined by the point of destruction of the object of which it is a member.  An object created by new ‘‘lives’’ until destroyed by delete

Indiscriminate use of global variables is considered poor programming practice. This is because global variables can be
assigned values in any/every function and can contain an unpredictable state, especially when functions that modify them run in
different threads or are programmed by different programmers in
a team.
