/*
Convert number to reversed array of digits

Given a random non-negative number, you have to return the digits of this number within an array
Example:

348597 => [3,4,8,5,9,7]

*/


std::vector<int> digitize(unsigned long n)
{
	std::vector<int> digits;

	while(n){
		//get Least significant digit of decimal number
		digits.insert(digits.begin(), n%10);
		//right shift decimal number
		n /= 10;
	}

	return digits;
}

std::vector<int> digitize(unsigned long n)
{
	std::vector<int> digits;

	for(; n; digits.insert(digits.begin(), n%10), n/= 10);

	return digits;
}

//Reversed order

std::vector<int> digitize(unsigned long n)
{
	std::vector<int> digits;

	while(n){
		digits.push_back(n%10);
		n /= 10;
	}

	return digits;
}


std::vector<int> digitize(unsigned long n)
{
	std::vector<int> digits;

	for(;n; digits.push_back(n%10), n /= 10);

	return digits;
}
