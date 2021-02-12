/*

*/


// Swap character starting from either side
void reverse(string& str)
{
    int n = str.length();

    for (int i = 0; i < n / 2; i++)
        swap(str[i], str[n - i - 1]);
}

void reverse(string& str)
{
	reverse(str.begin(), str.end());
	return str;
}

void reverse(string& str)
{
	return string(str.rbegin(),str.rend());
}


// Swap character starting from either side
void reverse(string& str)
{
	string ans = "";

	for(int i = str.size() - 1; i >= 0; i--){
		ans += str[i];

	return ans;
}
