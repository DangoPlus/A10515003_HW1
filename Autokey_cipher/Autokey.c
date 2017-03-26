
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int char_to_index(char c)
{
    char x = tolower(c);
    char result = x - 'a';
    return (int)result;
}

char index_to_char(int c)
{
    int result = c + 97;
    return (char)result;
}

char * xorencrypt(char * message, char * key) {
    size_t messagelen = strlen(message);
    size_t keylen = strlen(key);

    char * encrypted = malloc(messagelen+1);

    int i;
    for (i = 0; i < messagelen; i++) {
        int buf1 = char_to_index(message[i]);
        int buf2 = char_to_index(key[i % keylen]);
        char r = index_to_char(buf1 ^ buf2);
        encrypted[i] = r;
    }

    encrypted[messagelen] = '\0';

    return encrypted;
}

char * xordecode(char * cript, char * key) {
    size_t criptlen = strlen(cript);
    size_t keylen = strlen(key);

    char * message = malloc(criptlen+1);

    int i;
    for (i = 0; i < criptlen; i++) {
        int buf1 = char_to_index(cript[i]);
        int buf2 = char_to_index(key[i % keylen]);
        char r = index_to_char(buf1 ^ buf2);
        message[i] = r;
    }

    message[criptlen] = '\0';

    return message;
}

int main(int argc, const char * argv[]) {

//    printf("%s", "Введите сообщение: ");
    char * message = "Waribrus";
//    scanf("%s", &message);
    char * key = "key";

    char * encrypted = xorencrypt(message, key);
    printf("%s\n", encrypted);

    char * message1 = xordecode(encrypted, key);
    printf("%s\n", message1);

    return 0;
}
