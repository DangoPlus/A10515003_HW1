#include <stdio.h>
#include <string.h>
#define MAXSIZE 100

int main()
{
 char str[MAXSIZE]; //init new empty array.
 int i;
 int offset;  //offset.
 int n;

 printf("Please input plaintext："); //maximum size is 100.
 gets(str);   //get keyboard input.
 printf("please input Offset (1 - 25)：");  //offset range is 1-25.
 scanf("%d%*c", &offset);
 n = strlen(str);
 for (i = 0; i < n; i++)
 {
  if ('a' <= str[i] && str[i] <= 'z' - offset || 'A' <= str[i] && str[i] <= 'Z' - offset)
   str[i] += offset;
  else
   str[i] += offset - 26;
 }
 printf("encrypted text：");
 printf("%s",str);
 printf("\n");
 return 0;
}
