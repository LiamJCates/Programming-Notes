Because C++11 adds rvalue reference, there is a fourth way to pass parameters; call-by-rvalue-reference. The central concept is that since an rvalue stores a temporary that is about to be destroyed, an expression such as x=rval (where rval is an rvalue) can be implemented by a move instead of a copy; often moving an object’s state is much easier than copying it, as it may involve just a simple pointer change. What we see here is that x = y can be a copy if y is an lvalue, but a move if y is an rvalue. This gives a primary use case of overloading a function based on whether a parameter is an lvalue or rvalue, such as:

	// returns random item in lvalue arr
	string randomItem( const vector<string> & arr );
	// returns random item in rvalue arr
	string randomItem( vector<string> && arr );


	vector<string> v { "hello", "world" };
	cout << randomItem( v ) << endl; 											// invokes lvalue method
	cout << randomItem( { "hello", "world" } ) << endl; 	// invokes rvalue method
