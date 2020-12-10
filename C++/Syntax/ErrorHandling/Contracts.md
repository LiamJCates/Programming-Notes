Contracts
There is currently no general and standard way of writing optional run-time tests of invariants, preconditions, etc. A contract mechanism is proposed for C++20 [Garcia,2016] [Garcia,2018]. The
aim is to support users who want to rely on testing to get programs right – running with extensive
run-time checks – but then deploy code with minimal checks. This is popular in high-performance
applications in organizations that rely on systematic and extensive checking.
For now, we hav e to rely on ad hoc mechanisms. For example, we could use a command-line
macro to control a run-time check:
double& Vector::operator[](int i)
{
if (RANGE_CHECK && (i<0 || size()<=i))
throw out_of_range{"Vector::operator[]"};
return elem[i];
}
The standard library offers the debug macro, asser t(), to assert that a condition must hold at run
time. For example:
void f(const char∗ p)
{
assert(p!=nullptr); // p must not be the nullptr
// ...
}
If the condition of an asser t() fails in ‘‘debug mode,’’ the program terminates. If we are not in
debug mode, the asser t() is not checked. That’s pretty crude and inflexible, but often sufficient.
