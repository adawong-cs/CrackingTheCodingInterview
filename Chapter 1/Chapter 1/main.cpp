#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

bool stringUnique1_1(const string& a)
{
	set<char> s;

	for (char c : a)
	{
		s.insert(c);
	}

	if (s.size() != a.size())
	{
		return false;
	}

	return true;
}

bool stringUnique1_1b(const string& a)
{
	for (int i = 0; i < a.size(); i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (a[i] == a[j])
			{
				return false;
			}
		}
	}
	return true;
}

bool stringUnique1_1c(const string& s)
{
	string a = s;
	sort(a.begin(), a.end());

	for (int i = 0; i + 1 < a.size(); i++)
	{
		if (a[i] == a[i + 1])
		{
			return false;
		}
	}

	return true;
}

void reverse1_2(char* str)
{
	int count = 0;
	char* ptr = str;
	while (*ptr != 0)
	{
		ptr++;
		count++;
	}
	
	for (int i = 0; i < count / 2; i++)
	{
		swap(str[i], str[count - 1 - i]);
	}
}

// *(str+i)  == str[i]



int main()
{
	// Problem 1.1
	cout << "Problem 1.1" << endl;
	vector<pair<string, bool>> tests1_1 =
	{
		pair<string, bool>("string", true),
		{"ada", false},
		pair<string,bool>("beat", true),
		pair<string, bool>("hello", false)
	};
	
	for (pair<string, bool> a : tests1_1)
	{
		if (a.second == stringUnique1_1c(a.first))
		{
			cout << a.first << " passed" << endl;
		}
		else
		{
			cout << a.first << " failed" << endl;
		}
	}


	// Problem 1.2
	cout << "\nProblem 1.2" << endl;
	string s = "hello, ada!";
	cout << s << endl;
	reverse1_2(&s[0]);
	cout << s << endl;


}