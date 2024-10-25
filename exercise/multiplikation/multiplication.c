# include <stdio.h>

int main(){
  int number, i, result;
  printf("Please type a number:\n");
  scanf("%d", &number);

  for (i = 1; i < 11; ++i){
    result = number * i;
    printf("%d x %d = %d\n", number, i, result);
  }
  return 0;
}