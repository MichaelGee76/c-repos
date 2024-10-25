#include <stdio.h>

int main(){
  int i;
  int answer[10];
  printf("Type 10 numbers:\n");
  for(i = 0; i < 10; i++){
    scanf("%d", &answer[i]);
  }
  
  int max;
  max = answer[0];
  // find the max value of numbers in answer
  for (i = 0; i < 10; i++){
    if (max < answer[i]){
      max = answer[i];
    }
  }
  // find th min value in answer
  printf("Max value is: %d\n", max);
  int min;
  min = answer[0];
  for (i = 0; i < 10; ++i){
    if(min > answer[i]){
      min = answer[i];
    }
    

  }
  printf("Min value is: %d", min);
  return 0;
}

