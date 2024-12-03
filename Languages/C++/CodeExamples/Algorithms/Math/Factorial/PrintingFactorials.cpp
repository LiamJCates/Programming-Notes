#include <iostream>
using namespace std;

#define MAX 500

int multiply(int x, int res[], int res_size);

void factorial(int n)
{
    int res[MAX];

    res[0] = 1;
    int res_size = 1;

    for (int x=2; x<=n; x++)
        res_size = multiply(x, res, res_size);


    for (int i=res_size-1; i>=0; i--)
        cout << res[i];
    cout << endl;
}

int multiply(int x, int res[], int res_size)
{
    int carry = 0;

    for (int i=0; i<res_size; i++)
    {
        int prod = res[i] * x + carry;
        res[i] = prod % 10;
        carry  = prod/10;
    }

    while (carry)
    {
        res[res_size] = carry%10;
        carry = carry/10;
        res_size++;
    }
    return res_size;
}



int main()
{
    int num;
    cin >> num;
        factorial(num);
}






















#include <iostream>
#include <string>
#include <sstream>
using namespace std;

#define MAX 500

int multiply(int x, int res[], int res_size);

std::string factorial(int n)
{
    int res[MAX];

    res[0] = 1;
    int res_size = 1;

    for (int x=2; x<=n; x++)
        res_size = multiply(x, res, res_size);

    std::ostringstream os;
    for (int i=res_size-1; i>=0; i--)
        os << res[i];
    return std::string(os.str());
}

int multiply(int x, int res[], int res_size)
{
    int carry = 0;

    for (int i=0; i<res_size; i++)
    {
        int prod = res[i] * x + carry;
        res[i] = prod % 10;
        carry  = prod/10;
    }

    while (carry)
    {
        res[res_size] = carry%10;
        carry = carry/10;
        res_size++;
    }
    return res_size;
}



int main()
{
    cout << factorial(100) << endl;
}














using namespace std;
string factorial(int factorial){
  std::vector<int> r = {1};
  int c = 0;
  for(int i = 1; i <= factorial; i++) {
    for(auto& d : r) {
       int v = d*i + c;
       d = v%10;
       c = v/10;
    }
    for(;c > 0; c /= 10)
      r.push_back(c%10);
  }
  std::stringstream s;
  std::copy(std::rbegin(r), std::rend(r), std::ostream_iterator<int>(s));
  return s.str();
}
