#include "mystring.h"
#include "number.h"
#include "bit.h"
#include <stdio.h>
int main() {
  char s[]="silpa";
  int prime=7,palindrome=151,fact=4,num=5,k=1;
  

  printf("length of the string is %lu\n ",mystrlen(s));
  

  if(isPrime(prime))
      printf("the number is prime\n");

  if(ispalindrome(palindrome))
      printf("the number is palindrome\n");


  printf("factorial of %d is %d \n",fact,factorial(fact));

  printf("setting %d th of %d is %d \n",k,num,set(num,k));
  printf("setting %d th of %d is %d \n",k,num,clear(num,k));
  printf("setting %d th of %d is %d \n",k,num,flip(num,k));



  return 0;
}
