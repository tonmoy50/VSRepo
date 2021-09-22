#include <stdio.h>
#include <string.h>

int check_vowel(char ch)
{
	if (ch == 'a' || ch == 'A' || ch == 'e' || ch == 'E' || ch == 'i' || ch == 'I' || ch == 'o' || ch == 'O' || ch == 'u' || ch == 'U')
		return 1;
	else
		return 0;
}

void check_conso(char s[], char final_str[]) {
	int i = 0;
	int j = 0;
	while (s[i] != '\0') {
		if (s[i] != '0' && s[i] != '1' && s[i] != '2' && s[i] != '3' && s[i] != '4' && s[i] != '5' && s[i] != '6' && s[i] != '7' && s[i] != '8' && s[i] != '9') {
			final_str[j] = '.';
			final_str[++j] = s[i];
			j++;
		}
		i++;
	}
	final_str[j] = '\0';
}

int main()
{
	int n = 0, testcase;
	scanf("%d", &testcase);
	getchar();
	while (n < testcase) {
		char s[100], t[100];
		int c, d = 0;
		int i = 0;
		char final_str[100];

		printf("Enter a string\n");
		gets(s);

		for (c = 0; s[c] != '\0'; c++) {
			if (check_vowel(s[c]) == 0) {
				t[d] = s[c];
				d++;
			}
		}

		t[d] = '\0';

		strcpy(s, t);

		check_conso(s, final_str);

		printf("Final String: %s\n", final_str);
		n++;
	}
	

	return 0;
}



