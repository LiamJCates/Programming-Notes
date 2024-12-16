```cpp
int main()
{
  int aNumber = 10;

	/*
		We have a int type value called aNumber,
		and have assigned it the value 10.
	*/

  /*
	All values live in the memory at some address
	For this example, say the value above is held in memory location 1000
  */

  // Memory snapshot 1
  //with the declaration of the variable aNumber above, we have told the system to
  // reserve space in memory for an int type value
  // set the value of that memory slot to 10
  // call that memory slot "aNumber" so we can reference it later


  // Below we declare a pointer of type int
  int* intPointer;

  // Memory snapshot 2
  //with this declaration of the variable intPointer we have told the system
  // reserve space in memory for an int pointer type value
  // call that memory slot "intPointer" so we can reference it later

  //This variable expects that we will set it to the address of a int variable


  //Memory Snapshot 3
  // Below we have used the address of operator on aNumber to get its address
  // then set the value of the intPointer to the address of aNumber
  intPointer = &aNumber; // 1000

  //with the expression above we have said
  // get the address of aNumber, which is 1000 in this example
  // got to the memory slot that we called intPointer
  // put into that memory slot the address of aNumber


  //Declare a new int object
  int newNumber;
  // Memory snapshot 4
  //with the declaration of the variable aNumber above, we have told the system to
  // reserve space in memory for an int type value
  // call that memory slot "newNumber" so we can reference it later


  //get the address in the intPointer slot, follow the address there, assign the value at that location to newNumber
  newNumber = *intPointer;

  //Memory snapshot 5
  // The above expression tells the system
  // use the dereference operator "*" on the pointer value intPointer
  // as we have previously assigned intPointer the address of aNumber, address 1000, we go to the memory slot 1000
  // as 1000 is a reference to a memory slot, when we dereference that slot, it results in the value found there
  // as 1000 is the address of aNumber, the value previously stored there is 10
  // assign the value of 10 to the newNumber memory slot

}

/*
memory snapshot 1

aNumber 	1000 | 10

memory snapshot 2:

aNumber 	1000 | 10
intPointer	1001 |

memory snapshot 3:

aNumber 	1000 | 10
intPointer	1001 | 0x3E8		//Memory locations are represented by hexadecimal numbers so we begin them with 0x
								// 1000 in decimal is represented by 0x3E8 in hexadecimal, but it still means 1000
memory snapshot 4:

aNumber 	1000 | 10
intPointer	1001 | 0x3E8
newnumber	1002 |


memory snapshot 5:

aNumber 	1000 | 10
intPointer	1001 | 0x3E8
newnumber	1002 | 10
*/
```
