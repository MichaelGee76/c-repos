#include <stdio.h>

int main(){
  int num, isPrime =1;
  do{
    printf("Type a number:\n");
    scanf("%d", &num);
  }
  while (num <= 0);
  int i;
  if (num == 1){
    isPrime == 0;

  } else{
    for (i = 2; i <= num / 2; ++i){
      if(num % i == 0){
        isPrime = 0;
        break;
      }
    }
  }
  if(isPrime == 1){
    printf("%d is a prime number\n", num);
  }
  else{
    printf("%d is not a prime number\n", num);
  }
  return 0;



}