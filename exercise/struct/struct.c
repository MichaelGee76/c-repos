# include <stdio.h>
# include <string.h>

struct MyStruct{
    int myNum;
    char myString[15];
    float myFloat;
    char myArray;
  };

int main(){
  struct MyStruct struct1;

  struct1.myNum = 19;
  strcpy(struct1.myString, "Hello Walter");

  printf("%d\n%s\n", struct1.myNum, struct1.myString);

  return 0;
  


}