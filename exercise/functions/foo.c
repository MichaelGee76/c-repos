#include <stdio.h>

int increment(int *a){
    (*a)++;
    return *a;
}

int main() {
  int i  = 10;

  i = increment(&i);

  printf("i == %d\n", i);
}