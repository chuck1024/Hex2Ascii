#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdint.h>
int Ascii2Hex(char* ascii, char* hex)                 //ASCII 转16进制

{
	int i, len = strlen(ascii);
	char chHex[] = "0123456789ABCDEF";

	for (i = 0; i<len; i++)
	{
		hex[i * 2] = chHex[(ascii[i]) >> 4];
		hex[i * 2 + 1] = chHex[(ascii[i]) & 0xf];
		//hex[i * 3 + 2] = ' ';
	}
	//hex[len * 3] = '/0';
	return len * 3;
}
int Hex2Ascii(char *hex, char *ascii)             //16进制转ASCII
{
	int len = strlen(hex), tlen, i, cnt;

	for (i = 0, cnt = 0, tlen = 0; i<len; i++)
	{
		char c = toupper(hex[i]);
		if ((c >= '0'&& c <= '9') || (c >= 'A'&& c <= 'F'))
		{
			uint8_t t = (c >= 'A') ? c - 'A' + 10 : c - '0';
			if (cnt)
				ascii[tlen++] += t, cnt = 0;
			else
				ascii[tlen] = t << 4, cnt = 1;
		}
	}

	return tlen;
}
int main()
{
	char ascii[20] ="adc";
	char ascii1[20];
	char str1[20];
	Ascii2Hex(ascii, str1);
	printf("str1=%s\n", str1);
	
	Hex2Ascii(str1, ascii1);
	printf("ascii=%s\n", ascii1);
	
}
