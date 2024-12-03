/*
Description:

Data: an array of integers, a function f of two variables and an init value.

Example: a = [2, 4, 6, 8, 10, 20], f(x, y) = x + y; init = 0

Output: an array of integers, say r, such that

r = [r[0] = f(init, a[0]), r[1] = f(r[0], a[1]), r[2] = f(r[1], a[2]), ...]

With our example: r = [2, 6, 12, 20, 30, 50]
Task:

Write the following functions of two variables

    som : (x, y) -> x + y
    mini : (x, y) -> min(x, y)
    maxi : (x, y) -> max(x, y)
    lcmu : (x, y) -> lcm(abs(x), abs(y) (see note for lcm)
    gcdi : (x, y) -> gcd(abs(x), abs(y) (see note for gcd)

and

    function oper_array(fct, arr, init) (or operArray or oper-array) where

    fct is the function of to variables to apply to the array arr (fct will be one of som, mini, maxi, lcmu or gcdi)

    init is the initial value

Examples:

a = [18, 69, -90, -78, 65, 40]
oper_array(gcd, a, a[0]) => [18, 3, 3, 3, 1, 1]
oper_array(lcm, a, a[0]) => [18, 414, 2070, 26910, 26910, 107640]
oper_array(sum, a, 0) => [18, 87, -3, -81, -16, 24]
oper_array(min, a, a[0]) => [18, 18, -90, -90, -90, -90]
oper_array(max, a, a[0]) => [18, 69, 69, 69, 69, 69]

*/

#include <vector>

class Operarray
{
public:
    static long long gcdi(long long x, long long y);
    static long long lcmu(long long a, long long b);
    static long long som(long long a, long long b);
    static long long maxi(long long a, long long b);
    static long long mini(long long a, long long b);
    template<typename Func>
    static long long oper(Func func, long long a, long long b);
    template<typename Func>
    static std::vector<long long> operArray(Func func, std::vector<long long> &arr, long long init);
};

long long Operarray::gcdi(long long x, long long y)
{
    x = std::abs(x); y = std::abs(y);
    while (y != 0)
    {
        long long tmp = x; x = y; y = tmp % y;
    }
    return x;
}
long long Operarray::lcmu(long long a, long long b)
{
    return std::abs(a * b) / gcdi(a, b);
}
long long Operarray::som(long long a, long long b)
{
    return a + b;
}
long long Operarray::maxi(long long a, long long b)
{
    return std::max(a, b);
}
long long Operarray::mini(long long a, long long b)
{
    return std::min(a, b);
}
template<typename Func>
long long Operarray::oper(Func func, long long a, long long b)
{
    return func(a, b);
}
template<typename Func>
std::vector<long long> Operarray::operArray(Func func, std::vector<long long> &arr, long long init)
{
    long long c = init;
    std::vector<long long> res(arr.size());
    for (unsigned int i = 0; i < arr.size(); i++)
    {
        c = oper(func, c, arr[i]);
        res[i] = c;
    }
    return res;
}
