#include<stdio.h>
#include<string.h>
#include"header.h"
// this is a single line commnent
#define MAX 100
#define ADD(a,b) ((a)+(b))
#define MSG "welcome to c"
#define SUM(a,b) (a+b)
/*this is
multi line
comment*/
int main()
{
int a=MAX ,b=20,result=SUM(a,b);
printf("%s",MSG);
printf("MAX =%d\n",MAX);
printf("SUM=%d\n",ADD(a,b));
printf("result=%d",result);
return 0;
}
