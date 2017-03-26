#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef unsigned int status;
typedef unsigned short ushort;

#define ERROR 1
#define SUCCESS 0
#define OVERFLOW -1

#define EXTRA_LENGTH 20
#define TEXT_LENGTH 100

char *encrypt(char *plaintext, char *key);
char *decrypt(char *code, char *key);
status changeDeaultValue(char ch);
void getKeyMatrix(char (*matrix)[5], char *srckey);
char *sortPlainText(char *text);
char getDefaultValue();
ushort get_XY_From5x5Matrix(char ch, char (*matrix)[5]);
int abs(int num);
int main()
{
	char plainText[100] = "";
	char cipherText[100] = "";
	char key[100] = "";

	printf("Please input plaintext: ");
	scanf("%s", plainText);
	printf("please input key：");
	scanf("%s", key);
	char *cprText = encrypt(plainText, key);
	printf("encrypted text：");
 	printf("%s",cprText);
 	printf("\n");
	//puts();

	return 0;
}
char defaultValue = 'X';

char *encrypt(char *plainText, char *key)
{
	// build matrix
	char matrix[5][5];
	// get ket
	getKeyMatrix(matrix, key);

	//get legalPlnText
	char *legalPlnText = sortPlainText(plainText);

	//malloc
	char *cprText = (char *)malloc(sizeof(char) * TEXT_LENGTH);

	if (cprText == NULL) {
		exit(OVERFLOW);
	}
	memset(cprText, 0, (int)strlen(legalPlnText));

	/* encypted */
	int k = 0;
	for (int i = 0; i < (int)strlen(legalPlnText); i += 2) {
		int tmpPos1 = get_XY_From5x5Matrix(legalPlnText[i], matrix);
		int tmpPos2 = get_XY_From5x5Matrix(legalPlnText[i + 1], matrix);

		int x1 = tmpPos1 / 10;
		int x2 = tmpPos2 / 10;
		int y1 = tmpPos1 % 10;
		int y2 = tmpPos2 % 10;

		if ((x1 == x2) && (y1 != y2)) {
			cprText[k++] = matrix[x1][(y1 + 1) % 5];
			cprText[k++] = matrix[x2][(y2 + 1) % 5];
		}
		else  if((x1 != x2) && (y1 == y2)) {

			cprText[k++] = matrix[(x1 + 1) % 5][y1];
			cprText[k++] = matrix[(x2 + 1) % 5][y2];
		}
		else  if ((x1 != x2) && (y1 != y2)) {
			cprText[k++] = matrix[x1][y2];
			cprText[k++] = matrix[x2][y1];
		}
		else {
			return NULL;
		}
	}
	cprText[k] = 0;

	return cprText;
}

status changeDeaultValue(char ch)
{
	if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
		defaultValue = (ch >= 'a' ? ch - 'a' + 'A' : ch);

		return SUCCESS;
	}
	else {
		return ERROR;
	}
}
char getDefaultValue()
{
	return defaultValue;
}

void getKeyMatrix(char (*matrix)[5], char *key)
{
	int k = 0;
	char temp[26];
	memset(temp, 0, 26);

	while (*key != 0) {
		if (strchr(temp, *key) == NULL) {
			if ((*key >='a' && *key <= 'z') || (*key >= 'A' && *key <= 'Z')) {
				temp[k++] = *key;
			}
		}
		key++;
	}

	int i = 0;
	while (temp[i] != '\0') {
		temp[i] = temp[i] >= 'a' ? temp[i] - 'a' + 'A' : temp[i];
		i++;
	}

	for (int i = 'A'; i <= 'Z'; i++) {
		if (i == 'J') {
			continue;
		}
		else {
			if (strchr(temp, i) == NULL) {
				temp[k++] = i;
			}
		}
	}
	memcpy(matrix, temp, 25);
}

char *sortPlainText(char *text)
{
	int textLength = 0;
	char *tmp = NULL;

	textLength = (int)strlen(text);

	tmp = (char *)malloc(sizeof(char) * (textLength + EXTRA_LENGTH));
	if (tmp == NULL) {

		exit(OVERFLOW);
	}
	memset(tmp, 0, textLength + EXTRA_LENGTH);

	int k = 0;
	for (int i = 0; i < textLength; i++) {
		if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z')) {
			if (text[i] == 'j' || text[i] == 'J') {
				tmp[k++] = 'I';
			}
			else {
				tmp[k++] = text[i] >= 'a' ? text[i] - 'a' + 'A' : text[i];
			}
		}
	}

	for (int i = 1; i < (int)strlen(tmp); i++) {
		if ((tmp[i] == tmp[i - 1]) && (i % 2 != 0)) {
			for (int j = (int)strlen(tmp); j >i; j--) {
				tmp[j] = tmp[j - 1];
			}
			if (defaultValue != tmp[i - 1]) {
				tmp[i] = defaultValue;
			}
			else {
				tmp[i] = (defaultValue - 'A' + 1) % 26 + 'A';
			}
		}
	}

	int len = (int)strlen(tmp);
	if (len % 2 != 0) {
		if (defaultValue != tmp[len - 1]) {
				tmp[len] = defaultValue;
		}
		else {
			tmp[len] = (defaultValue - 'A' + 1) % 26 + 'A';
		}
	}

	return tmp;
}

ushort get_XY_From5x5Matrix(char ch, char (*matrix)[5])
{
	for (int x = 0; x < 5; x++) {
		for (int y = 0; y < 5; y++) {
			if (matrix[x][y] == ch) {
				return (x * 10 + y);
			}
		}
	}
}

int abs(int num)
{
	return (num > 0 ? num : -num);
}
