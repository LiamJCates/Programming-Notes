/*

Nestor was doing the work of his math class about three days but he is tired of make operations a lot and he should deliver his task tomorrow. His math’s teacher gives him two numbers a and b. The problem consist of finding the last digit of the potency of base a and index b. Help Nestor with his problem. You are given two integer numbers: the base a (0 <= a <= 20) and the index b (0 <= b <= 2,147,483,000), a and b both are not 0. You have to find the last digit of ab.
Input

The first line of input contains an integer t, the number of test cases (t <= 30). t test cases follow. For each test case will appear a and b separated by space.
Output

For each test case output an integer per line representing the result.
Example

Input:
2
3 10
6 2

Output:
9
6

*/

#include <iostream>
#define d ;break;
#define c case
int main(){
long t,b,i,
w[]={2,4,8,6},
h[]={3,9,7,1},
f[]={4,6},
s[]={7,9,3,1},
e[]={8,4,2,6},
n[]={9,1};
std::cin>>t;
while(t--){std::cin>>b>>i;i--;
switch(b%=10){
c 2:b=w[i%4]d
c 3:b=h[i%4]d
c 4:b=f[i%2]d
c 7:b=s[i%4]d
c 8:b=e[i%4]d
c 9:b=n[i%2]d}
printf("%ld\n",i==-1?1:b);}}
