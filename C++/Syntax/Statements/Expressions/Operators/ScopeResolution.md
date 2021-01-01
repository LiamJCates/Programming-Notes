| Name | Syntax | Overloadable |
|------|--------|--------------|
| Scope Resolution | a::b | No |


The scope resolution operator :: is used to identify and disambiguate identifiers used in different scopes. For more scope information:
[C++\Semantics\Scope.md]


Syntax

    qualified-id:
     nested-name-specifier templateopt unqualified-id

    nested-name-specifier:
     ::
     type-name ::
     namespace-name ::
     decltype-specifier ::
     nested-name-specifier identifier ::
     nested-name-specifier templateopt simple-template-id ::

    unqualified-id:
     identifier
     operator-function-id
     conversion-function-id
     literal-operator-id
     ~ type-name
     ~ decltype-specifier
     template-id

Remarks

The identifier can be a variable, a function, or an enumeration value.
Use :: for classes and namespaces

By using the scope resolution operator, a global variable declared before the definition of a function (block) can be accessed by the function (or block) even if the function (or block) has an identifier with the same name as the variable.

The following example shows how the scope resolution operator is used with namespaces and classes:
C++

namespace NamespaceA{
    int x;
    class ClassA {
    public:
        int x;
    };
}

int main() {

    // A namespace name used to disambiguate
    NamespaceA::x = 1;

    // A class name used to disambiguate
    NamespaceA::ClassA a1;
    a1.x = 2;
}

A scope resolution operator without a scope qualifier refers to the global namespace.
C++

namespace NamespaceA{
    int x;
}

int x;

int main() {
    int x;

    // the x in main()
    x = 0;
    // The x in the global namespace
    ::x = 1;

    // The x in the A namespace
    NamespaceA::x = 2;
}

You can use the scope resolution operator to identify a member of a namespace, or to identify a namespace that nominates the member’s namespace in a using directive. In the example below, you can use NamespaceC to qualify ClassB, even though ClassB was declared in namespace NamespaceB, because NamespaceB was nominated in NamespaceC by a using directive.
C++

namespace NamespaceB {
    class ClassB {
    public:
        int x;
    };
}

namespace NamespaceC{
    using namespace NamespaceB;
}

int main() {
    NamespaceB::ClassB b_b;
    NamespaceC::ClassB c_b;

    b_b.x = 3;
    c_b.x = 4;
}

You can use chains of scope resolution operators. In the following example, NamespaceD::NamespaceD1 identifies the nested namespace NamespaceD1, and NamespaceE::ClassE::ClassE1 identifies the nested class ClassE1.
C++

namespace NamespaceD{
    namespace NamespaceD1{
        int x;
    }
}

namespace NamespaceE{
    class ClassE{
    public:
        class ClassE1{
        public:
            int x;
        };
    };
}

int main() {
    NamespaceD:: NamespaceD1::x = 6;
    NamespaceE::ClassE::ClassE1 e1;
    e1.x = 7  ;
}

Use :: for static members

You must use the scope resolution operator to call static members of classes.
C++

class ClassG {
public:
    static int get_x() { return x;}
    static int x;
};

int ClassG::x = 6;

int main() {

    int gx1 = ClassG::x;
    int gx2 = ClassG::get_x();
}

Use :: for scoped enumerations

The scoped resolution operator is also used with the values of a scoped enumeration Enumeration declarations, as in the following example:
C++

enum class EnumA{
    First,
    Second,
    Third
};

int main() {
    EnumA enum_value = EnumA::First;
}
