# include <stdio.h>

int main(){
  int num, i, j,  digit;
  int newNum[10];
  printf("Please type a number:\n");
  scanf("%d", &num);

  for(i = 0; num > 0; ++i){
    digit = num % 10;
    newNum[i] = digit;
    num = num / 10;
  }
  int reversedNum = 0;
  for (j = 0; j < i; ++j){
      reversedNum = reversedNum * 10 + newNum[j];
  }
  printf("Reversed number: %d", reversedNum);
  return 0;
}