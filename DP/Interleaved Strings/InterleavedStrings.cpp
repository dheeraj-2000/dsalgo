// A Dynamic Programming based program to check whether a string str3 is an interleaving of two other strings str1 and str2.
#include <iostream>
#include <string.h>
using namespace std;

bool isInterleaved(
	char* str1, char* str2, char* str3)
{
	// Find lengths of the two strings
	int lenOfStr1= strlen(str1), lenOfStr2 = strlen(str2);

	bool table[lenOfStr1 + 1][lenOfStr2 + 1];

	// Initialize all values as false.
	memset(table, 0, sizeof(table));

	if ((lenOfStr1 + lenOfStr2) != strlen(str3))
		return false;

	// Process all characters of str1 and str2
	for (int i = 0; i <=lenOfStr1 ; ++i) {
		for (int j = 0; j <=lenOfStr2 ; ++j) {
			// two empty strings have an
			// empty string as interleaving
			if (i == 0 && j == 0)
				table[i][j] = true;

			// str1 is empty
			else if (i == 0) {
				if (str2[j - 1] == str3[j - 1])
					table[i][j] = table[i][j - 1];
			}

			// str2 is empty
			else if (j == 0) {
			    if (str1[i - 1] == str3[i - 1])
					table[i][j] = table[i - 1][j];
			}

			// Current character of str3 matches
			// with current character of str1,
			// but doesn't match with current
			// character of str2
			else if (
				str1[i - 1] == str3[i + j - 1]
				&& str2[j - 1] != str3[i + j - 1])
				table[i][j] = table[i - 1][j];

			// Current character of str3 matches
			// with current character of str2,
			// but doesn't match with current
			// character of str1
			else if (str1[i - 1] != str3[i + j - 1]&& str2[j - 1] == str3[i + j - 1])
				table[i][j] = table[i][j - 1];

			// Current character of str3 matches
			// with that of both str1 and str2
			else if (str1[i - 1] == str3[i + j - 1]&& str2[j - 1] == str3[i + j - 1])
				table[i][j]= (table[i - 1][j]|| table[i][j - 1]);
		}
	}

	return table[lenOfStr1][lenOfStr2];
}

// A function to run test cases
void test(char* str1, char* str2, char* str3)
{
	if (isInterleaved(str1, str2, str3))
		cout << str3 << " is interleaved of "
			<< str1 << " and " << str2 << endl;
	else
		cout << str3 << " is not interleaved of "
			<< str1 << " and " << str2 << endl;
}

// Driver program to test above functions
int main()
{
	test("XXY", "XXZ", "XXZXXXY");
	test("XY", "WZ", "WZXY");
	test("XY", "X", "XXY");
	test("YX", "X", "XXY");
	test("XXY", "XXZ", "XXXXZY");
	return 0;
}
// Time complexity of program is O(length of str1 * length of str2)
