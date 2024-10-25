# include <stdio.h>

int get_fak(int n){
  if(n == 0 || n == 1){
    return 1;
  }
  else{
    return n * get_fak(n-1);
  }
}


int main(){
  int answer;
  printf("Type a positive number:\n");
  scanf("%d", &answer);
  printf("%d! = %d\n",answer , get_fak(answer));

}