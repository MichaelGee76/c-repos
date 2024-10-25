# include <stdio.h>
# include <math.h>



int main(){
  double number, squareRoot;
  printf("Check for square: \n");
  scanf("%lf", &number);
  squareRoot = sqrt(number);
  printf("Square root of %.2lf is: %.2lf\n", number, squareRoot);
  if (squareRoot == floor(squareRoot)){
    printf("%.2lf is a square number", squareRoot);
  }
  else{
    printf("%.2lf is not a square number", squareRoot);
  }
  return 0;
}