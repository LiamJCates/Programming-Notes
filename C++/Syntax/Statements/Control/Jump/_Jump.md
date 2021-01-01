## Jump Statements

Jump statements transfer control flow. Unlike selection statements, jump statements are not conditional. You should avoid using them because they can almost always be replaced with higher-level control structures.

(1) attr(optional) break ;
(2) attr(optional) continue ;
(3) attr(optional) return expression(optional) ;
(4) attr(optional) return braced-init-list ; (since C++11)
(5) attr(optional) goto identifier ;

1) break statement;
2) continue statement;
3) return statement with an optional expression;
4) return statement using list initialization;
5) goto statement.

Note: for all jump statements, transfer out of a loop, out of a block, or back past an initialized variable with automatic storage duration involves the destruction of objects with automatic storage duration that are in scope at the point transferred from but not at the point transferred to. If multiple objects were initialized, the order of destruction is the opposite of the order of initialization.
