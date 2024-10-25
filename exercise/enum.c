# include <stdio.h>

enum Level{
  LOW,
  MEDIUM,
  HIGH
};

int main(){
  enum Level myVar;
  myVar = 25;
  printf("%d", myVar);
  
}