#include <stdio.h>
#include <stdlib.h>

int main()
{
    //list
    char List[27] = { 0 };
    //Alphabet
    char Alpha[26] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };
    //key
    char Key[26] = { 'Q','W','E','R','T','Y','U','I','O','P','A','S','D','F','G','H','J','K','L','Z','X','C','V','B','N','M' };
    //char Key[101] = { 0 };
    //plaintext
    char Message[100] = { 0 };
    //encrypted text
    char CipherText[100] = { 0 };
    int Num = 0;


    for (int i = 0; Key[i]; ++i)
    {
        if (Key[i] == ' ')
            continue;
        for (int j = 0; j < 26; ++j)
        {
            if (Alpha[j] == Key[i])
            {
                Alpha[j] = 0;
                List[Num++] = Key[i];
            }
        }
    }
    for (int i = 0; i < 26; ++i)
    {
        if (!Alpha[i])
            continue;
        List[Num++] = Alpha[i];
    }

    //get keyboard input
    printf("Please input plaintext: ");
    gets(Message);

    //encrypt
    for (int i = 0; Message[i]; ++i)
    {
        if (Message[i] == ' ')
            CipherText[i] = ' ';
        else
            CipherText[i] = List[Message[i] - 'a'];
    }

    //print
    printf("encrypted text: %s\n", CipherText);
    return 0;
}
