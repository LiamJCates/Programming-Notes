The unit part indicates that the test will be done on an individual unit of our code. This is typically at a function level. This means that we will try to isolate one single function (or another small unit of code) and run our tests on just that unit.

These tests are typically written by the developer of the code unit to be tested and are often automated. This means that as soon as a block of code is ready to be committed to the version control system, it must first pass the unit test written for it. Since the unit test only tests a single code unit, they are typically rather trivial.

To test our calc functions, we must first decide what we want to test. First, we can set up some test cases for valid input and match these inputs to some expected results.

Unit tests are typically written in a separate file that will call the code to be tested. They might look something like this:

function test_add_one()
  result = add(2, 3)
  assert.equal(5, result)

The first argument, assert.equal, is what we expect as a result, and it is compared to the content of the result variable. If they match, this test will pass; if not, the test will fail.


For simple tests like these, the structure will be the same—call the function we want to test, store the returned value in a variable, and compare the returned value with the expected one. We should also think of odd cases and what kind of result we expect to get. For example, what will happen if we make this call to divide? Here is how the code appears:

  result = divide(10, 0)

We can't divide a number by zero. This will result in an exception. If we expect to get an exception when this is done, the function works, but if we expect the function to handle this case, it will need to be modified. This is done so that it returns whatever we decide it should return. This may happen if we decide that we should get another exception that indicates that we can't pass a 0 as the second argument. So, no matter what we expect, it should be tested.
