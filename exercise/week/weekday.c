# include <stdio.h>
# include <string.h>



int main(){
  char *week[7] = {"Monday", "Tuesday","Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
  
  int answer;
  printf("Please type a number: \n");
  scanf("%d", &answer);

  switch (answer)
  {
    case 1:
      printf("%s", week[0]);
      break;
    case 2:
      printf("%s", week[1]);
      break;
    case 3:
      printf("%s", week[2]);
      break;
    case 4:
      printf("%s", week[3]);
      break;
    case 5:
      printf("%s", week[4]);
      break;
    case 6:
      printf("%s", week[5]);
      break;
    case 7:
      printf("%s", week[6]);
      break;              
    default:
      printf("Choice is out of range");
      break;
  }
  return 0;

}