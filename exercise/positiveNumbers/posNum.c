# include <stdio.h>
# include <string.h>

int main(){
  int num;
  do{
    printf("Type a positive number:\n");
    scanf("%d", &num);
  }
  while (num <= 0);
  
  int i;
  int sum = 0;
  for (i = 0; i <= num ; ++i){
    if (i % 2 == 0){
      sum += i; 
    }
  }
  printf("Sum of all even numbers is: %d\n", sum);
  return 0;
  
}