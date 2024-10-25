#include <stdio.h>

int main(){
  int i;
  int answer[10];
  printf("Type 10 numbers:\n");
  for(i = 0; i < 10; i++){
    scanf("%d", &answer[i]);
  }
  int sum = 0;
  for (i = 0; i < 10; i++){
    sum = sum + answer[i];
  }
  printf("Sum is %d", sum);
  return 0;
}