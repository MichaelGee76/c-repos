# include <stdio.h>
# include <locale.h>

void convert_to_celsius(int temp){
      float celsius;
      celsius = ((5.0/9.0) * (temp -32));
      printf("The temperature is %.2f°C\n", celsius);
  }

  void convert_to_fahrenheit(int temp){
    float fahrenheit;
    fahrenheit = (temp * (9.0/5.0) + 32);
    printf("The temperature is %.2f°F\n", fahrenheit);
  }

int main (){
  setlocale(LC_ALL, "C.UTF-8");
  int answer, n;
  do{
    printf("Please choose.\n0 for converting fahrenheit to celcius\n1 for converting to fahrenheit.\n");
    scanf("%d", &answer);
  } while(answer != 0 && answer != 1);
  printf("Type a temperature to convert\n");
  scanf("%d", &n);
  if (answer == 0){
    convert_to_celsius(n);
  }
  if(answer == 1){
    convert_to_fahrenheit(n);
  }
  return 0;
}