# include <stdio.h>

int main(){
  int number, i, length, digit;
  int sum = 0;
  printf("Please type a number.\n");
  scanf("%d", &number);
  for (i = 0; number > 0; ++i){
    digit = number % 10;
    sum += digit;
    number = number / 10;
  }
  printf("Sum of all digits: %d", sum);  

}