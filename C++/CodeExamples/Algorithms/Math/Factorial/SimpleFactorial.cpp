/*
Your task is to write function factorial.

https://en.wikipedia.org/wiki/Factorial

*/

//recursive
long long factorial(int n){
  return n ? n * factorial(n - 1) : 1;
}

//iterative
long long factorial(int n){
  long long r = 1;
  while(n) r *= n--;
  return r;
}
