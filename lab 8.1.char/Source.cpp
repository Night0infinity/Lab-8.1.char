#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

char* Change(char* s)
{
	char* t = new char[strlen(s)];
	char* p;
	int pos1 = 0,
		pos2 = 0;
	*t = 0;
	while (p = strchr(s + pos1, 'w'))
	{
		if (s[p - s + 1] == 'h')
		{
			if (s[p - s + 2] == 'i')
			{
				if (s[p - s + 3] == 'l')
				{
					if (s[p - s + 4] == 'e')
					{
						pos2 = p - s + 5;
						strncat(t, s + pos1, pos2 - pos1 - 5);
						strcat(t, "**");
						pos1 = pos2;
					}
				}
			}
		}
	}
	strcat(t, s + pos1);
	strcpy(s, t);
	return t;
}

bool Include(const char* s, const char* cs)
{
	bool r = true;
	for (int i = 0; cs[i] != '\0'; i++)
		r = r && (strchr(s, cs[i]));
	return r;
}

int main()
{
	char str[101];
	cout << "Enter string:" << endl;
	cin.getline(str, 100);
	/*char a = 'w';
	char b = 'h';
	char c = 'i';
	char d = 'l';
	char e = 'e';
	if (strchr(str, a) && strchr(str, b) && strchr(str, c) && strchr(str, d) && strchr(str, e))
		cout << "yes" << endl;
	else
		cout << "no" << endl;*/
	char cs[] = "while";
	if (Include(str, cs))
		cout << "yes" << endl;
	else
		cout << "no" << endl;
	char* dest = new char[151];
		dest = Change(str);
	cout << "Modified string (param) : " << str << endl;
	cout << "Modified string (result): " << dest << endl;

	return 0;
}