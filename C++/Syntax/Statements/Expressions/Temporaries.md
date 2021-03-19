Temporaries

Sometimes, during the evaluation of an expression, the compiler must create temporary objects.

These are objects like any other: they require storage and they must be constructed and destroyed. The difference is that you never see them – the compiler is responsible for deciding that they’re needed and the details of their existence.

But there is one thing about temporaries: they’re automatically const. Because you usually won’t be able to get your hands on a temporary object, telling it to do something that will change that temporary is almost certainly a mistake because you won’t be able to use that information. By making all temporaries automatically const, the compiler informs you when you make that mistake.

class X {
	int i;
	public:
	X(int ii = 0);
	void modify();
};

X f() {
return X();
}
const X g() {
return X();
}
void f7(X& x) { // Pass by non-const reference
x.modify();
}

In an example, if f( ) returns a non-const X object. But in the
expression:
g(f());
the compiler must manufacture a temporary object to hold the
return value of f( ) so it can be passed to h( ). This would be fine if
h( ) took its argument by value; then the temporary would be
copied into h( ) and it wouldn’t matter what happened to the
temporary X. However, h( ) takes its argument by reference, which
means in this example takes the address of the temporary X. Since
h( ) doesn’t take its argument by const reference, it has permission
to modify the temporary object. But the compiler knows that the
temporary will vanish as soon as the expression evaluation is
complete, and thus any modifications you make to the temporary X
will be lost. By making all temporary objects automatically const,
this situation causes a compile-time error so you don’t get caught
by what would be a very difficult bug to find.
However, notice the expressions that are legal:
f() = X(1);
f().modify();
Although these pass muster for the compiler, they are actually
problematic. f( ) returns an X object, and for the compiler to satisfy
the above expressions it must create a temporary to hold that
return value. So in both expressions the temporary object is being
modified, and as soon as the expression is over the temporary is
cleaned up. As a result, the modifications are lost so this code is
probably a bug – but the compiler doesn’t tell you anything about
it. Expressions like these are simple enough for you to detect the
problem, but when things get more complex it’s possible for a bug
to slip through these cracks.
