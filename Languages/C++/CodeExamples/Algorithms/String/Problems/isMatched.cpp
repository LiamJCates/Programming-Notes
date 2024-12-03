/*
Given a string that contains left and right parenthesis characters. Write code to determine whether the parentheses are correctly nested. For example, the strings "(())" and "()()" are correctly nested but "(()()" and ")(" are not.
*/

bool isMatched(std::string &p)
{
	int count = 0;
	for(char c : p)
	{
			if(c == '(') count++;
			else if(c == ')') count--;
			if(count < 0) return false;
	}

	return count == 0;
}


/*
Given a string that contains lowercase vowels and consonants. Write code to determine whether the number of consonant is equal to the number of vowels.
*/

#incude <unordered_set>

bool isMatched(std::string &p)
{
	std::unordered_set<char> s{'a','e','i','o','u'};
	int count = 0;

	for(char c : p)
			s.find(c) == s.end() count++ : count--;

	return count == 0;
}
