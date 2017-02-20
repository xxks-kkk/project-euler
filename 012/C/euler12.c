/*
 * Solution to problem 12 in Project Euler
 * copyright (c) 2017, Zeyuan Hu, ferrishu3886@gmail.com
 */

// Reference:
// 1. https://en.wikipedia.org/wiki/Primality_test
// 2. https://en.wikipedia.org/wiki/Trial_division
// 3. http://www.mathblog.dk/triangle-number-with-more-than-500-divisors/ (other methods: divisor function, Sieve of Eratosthenes)

#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <time.h>

#define generateTriangleNumber(i) (1+i)*i/2

int numFactors(int);
int method1();

int
main()
{
  printf("/////////////////\n");
  printf("// PROJECT EULER 12 \n");
  printf("/////////////////\n\n");

  printf("METHOD1:\n");
  clock_t begin = clock();
  printf("The value of the first triangle number to have over five hundred divisors: %d\n", method1());    
  clock_t end = clock();
  double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  printf("Solution took %f s\n", time_spent);
  return 0;
}

int
method1()
{
  int number = 0;
  int i = 1;

  while(numFactors(number) < 500)
  {
    number += i;
    i++;
  }
  return number;
}  

// any non zero integer n can be represented as a product of distinct primes.
int
numFactors(int num)
{
  int nod = 0;
  // the reason we only need to check until sqrt(num) is that
  // for any number n = p * q. if p > sqrt(n), then q < sqrt(n).
  // if we check beyond sqrt(n), say q. Then p < sqrt(n) is already checked
  // and there is redundancy. 
  int tmp = sqrt(num); 

  int i;
  for(i = 1; i <= tmp; i++)
  {
    if (num%i == 0)
      nod += 2;
  }
  // correction if the number is a perfect square, where p = q 
  // (p < sqrt(n) is the same as the correspondent q > sqrt(n))
  if (tmp * tmp == num) 
  {
    nod--;
  }
  return nod;
}
