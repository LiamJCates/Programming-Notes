Casts

static_cast

When a value of one data type is automatically
changed to another data type, an implicit type coercion is said to have occurred.
As the examples in the preceding section illustrate, if you are not careful about data
types, implicit type coercion can generate unexpected results.
To avoid implicit type coercion, C11 provides for explicit type conversion through
the use of a cast operator. The cast operator, also called type conversion or type
casting, takes the following form:
static_cast<dataTypeName>(expression)
First, the expression is evaluated. Its value is then converted to a value of the type
specified by dataTypeName. In C11, static_cast is a reserved word.

| Expression | Evaluates to |
|------------|--------------|
| static_cast<int>(7.9) | 7 |
| static_cast<double>(25) | 25.0 |
| static_cast<double>(5 + 3) | = static_cast<double>(8) = 8.0 |
| static_cast<double>(15) / 2 | = 15.0 / 2 = 7.5 |
| static_cast<double>(15/2) | = static_cast<double>(7) = 7.0 |
| static_cast<int>(7.8 + static_cast<double>(15)/2) | = static_cast<int>(7.8 + 7.5) = static_cast<int>(15.3) = 15 |
| static_cast<int>(7.8 + static_cast<double>(15/2)) | = static_cast<int>(7.8 + 7.0) = static_cast<int>(14.8) = 14 |
| static_cast<int>('A') | = 65 |
|  static_cast<char>(56) | = '8' |

NOTE
In C11, the cast operator can also take the form dataType(expression). This form is called C-like casting. For example, double(5) = 5.0 and int(17.6) = 17.

However, static_cast is more stable than C-like casting.


reinterpret_cast
const_cast
