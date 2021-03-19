





/*
Brute Force
*/

unsigned int sum_cubes(unsigned int n) {

  unsigned int sum = 1;
  for(int i = 2; i <= n; sum += i*i*i, i++);
  return sum;
}


/*
Formula
*/
unsigned int sum_cubes(unsigned int n){
  return (n * (n + 1) / 2) * (n * (n + 1) / 2);
}
