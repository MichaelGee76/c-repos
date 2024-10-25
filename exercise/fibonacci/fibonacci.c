# include <stdio.h>

int main(){
  int i,n;
  int n1=0;
  int n2 =1;
  

  
  printf("How many fibonacci numbers you want to see?\n");
  scanf("%d", &n);
  printf("%d, %d", n1, n2);
  int nextN = n1+n2;

  for (i= 3; i <=n; ++i){
    printf(", %d", nextN);
    n1 = n2;
    n2 = nextN;
    nextN = n1 + n2;
  }
  
  return 0;

}