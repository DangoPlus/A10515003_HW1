#include<stdio.h>
#include<string.h>
int main()
{
  int i,j,k,n=0,matrixLen,verticalLength;
  char key[10],tempChar;
  char matrix[10][10],plainText[50];
  printf("Please input plaintext: ");
  gets(plainText);
  printf("encrypt key: ");
  gets(key);


  matrixLen=strlen(key);
  for(i=0;i<matrixLen;i++)
  {
    for(j=0;j<matrixLen;j++)
    {
      if(plainText[n]=='\0')
      {
        break;
      }
      matrix[i][j]=plainText[n++];
    }
  }
  verticalLength=matrixLen - (((matrixLen*matrixLen)-strlen(plainText)) / matrixLen);
  j=matrixLen - ( (matrixLen*verticalLength) - strlen(plainText) );
  n='z'- (matrixLen-j) + 1;  //First character of filler

  for(;j<matrixLen;j++)
  {
    matrix[verticalLength-1][j]=n++;
  }

  //Print Matrix
  printf("\n");
  for(i=0;i<matrixLen;i++)
  {
    printf("%c ",key[i]);
  }
  printf("\n\n");
  for(i=0;i<verticalLength;i++)
  {
    for(j=0;j<matrixLen;j++)
    {
      printf("%c ",matrix[i][j]);
    }
    printf("\n");
  }

  printf("\n\nCipher Text : ");
  tempChar='1';
  for(i=0;i<matrixLen;i++)
  {
    for(j=0;j<matrixLen;j++)
    {
      if(key[j]==tempChar)
      {
        tempChar++;
        for(k=0;k<verticalLength;k++)
        {
          printf("%c",matrix[k][j]);
        }
      }
    }
  }
  printf("\n");
  return 0;
}
