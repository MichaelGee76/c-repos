# include <stdio.h>

int main(){
  FILE *fptr;
  fptr = fopen("test.txt", "r");
  // fprintf(fptr, "Emma doesn't join us anymore.\n");
  char str[100];
  while(fgets(str, 100, fptr)){
      printf("%s", str);

  }
  fclose(fptr);
  return 0;
}