## Restrictions on Arrays

Consider the following statements:

  int myList[5] = {0, 4, 8, 12, 16};
  int yourList[5];

Note that these arrays are of the same type and have the same number of components.

C++ does not allow aggregate operations on an array. An aggregate operation on an array is any operation that manipulates the entire array as a single unit. Examples follow.



### Array Element Copy

Suppose that you want to copy the elements of myList into the corresponding elements of yourList.

The following statement is illegal:

  yourList = myList; //illegal

In fact, this statement will generate a syntax error.

To copy one array into another array, you must copy it component-wise—that is, one component at a time. For example, the following statements copy myList into yourList.

  yourList[0] = myList[0];
  yourList[1] = myList[1];
  yourList[2] = myList[2];
  yourList[3] = myList[3];
  yourList[4] = myList[4];

This can be accomplished more efficiently using a loop, such as the following:

  for (int index = 0; index < 5; index++)
    yourList[index] = myList[index];



### Array Element Input

Next, suppose that you want to read data into the array yourList. The following statement is illegal and, in fact, would generate a syntax error:

  cin >> yourList; //illegal

To read data into yourList, you must read one component at a time, using a loop such as the following:

  for (int index = 0; index < 5; index++)
    cin >> yourList[index];



### Array Element Output

Next, suppose that you want to output the data in an array, yourList. The following statement, while legal, does not produce the intended output:

  cout << yourList;

this statement will not output the values of the components of myList. In fact, the statement outputs the value stored in myList, which is the base address of the array. This is why the statement will not generate a syntax error.

To output yourList elements, you must read one component at a time, using a loop such as the following:

  for (int index = 0; index < 5; index++)
    cout << yourList[index];



### Comparing Array Elements

Similarly, determining whether two arrays have the same elements must be done component-wise. While the following statement is legal in the sense that it does not generate a syntax error, the desired result is not produced as the comparison deals with the array's base address.

  if (myList <= yourList)
		cout << "yourList is greater";

the expression myList <= yourList evaluates to true if the base address of the array myList is less than the base address of the array yourList; and evaluates to false otherwise. It does not determine whether the elements of myList are less than or equal to the corresponding elements of yourList.

To compare the elements of myList and yourList, you must read one component at a time, using a loop such as the following:

  for (int index = 0; index < 5; index++)
    if(myList[index] <= yourList[index])
			cout << "yourList index " << index << " is greater"; 
