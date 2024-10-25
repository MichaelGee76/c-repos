# include <stdio.h>

int main(){
  int answer;
  printf("Type a number\n");
  scanf("%d", &answer);
  if (answer % 2 == 0){
    printf("The number %d is even", answer);

  }
  else{
    printf("The number %d is odd.", answer);
  }
}