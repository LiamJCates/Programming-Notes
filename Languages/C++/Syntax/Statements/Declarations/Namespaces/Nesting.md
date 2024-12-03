#### Nesting

Namespaces can be nested in one of two ways.

nest namespace blocks:

  namespace Namespace1 {
    namespace Namespace2 {
    // All symbols declared within this block
    // belong to the Namespace1::Namespace2 namespace
    }
  }

Use the scope-resolution operator:

  namespace Namespace1::Namespace2 {
    // All symbols declared within this block
    // belong to the Namespace1::Namespace2 namespace
  }

The latter approach is more succinct.
