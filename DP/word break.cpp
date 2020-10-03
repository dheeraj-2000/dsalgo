#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to segment given string into a space-separated
// sequence of one or more dictionary words
void wordBreak(vector<string> const &dict, string str, string out)
{
	// if we have reached the end of the string,
	// print the output string

	if (str.size() == 0)
	{
		cout << out << endl;
		return;
	}

	for (int i = 1; i <= str.size(); i++)
	{
		// consider all prefixes of current string
		string prefix = str.substr(0, i);

		// if the prefix is present in the dictionary, add prefix to the
		// output string and recur for remaining string

		if (find(dict.begin(), dict.end(), prefix) != dict.end())
			wordBreak(dict, str.substr(i), out + " " + prefix);
	}
}

// Word Break Problem
int main()
{
	// vector of strings to represent dictionary
	// we can also use trie or std::set to store dictionary

	vector<string> dict = { "this", "th", "is", "famous", "Word", "break",
			"b", "r", "e", "a", "k", "br", "bre", "brea", "ak", "problem" };

	// input string
	string str = "Wordbreakproblem";

	wordBreak(dict, str, "");

	return 0;
}