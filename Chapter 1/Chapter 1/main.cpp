#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <tuple>
#include <map>
#include <string>

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

bool IsPermutation1_3(const string& a, const string& b)
{
	map<char, int> m1;
	map<char, int> m2;

	for (char c : a)
	{
		m1[c]++;
	}

	for (char d : b)
	{
		m2[d]++;
	}

	if (m1.size() < m2.size())
	{
		swap(m1, m2);
	}

	for (pair<char, int> m : m1)
	{
		char c = m.first;
		int freq = m.second;
		// what is the frequency of c in m2?
		if (m2[c] != freq)
		{
			return false;
		}
	}

	return true;
}

bool IsPermutation1_3b(string& a, string& b)
{
	if (a.size() != b.size())
	{
		return false;
	}

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] != b[i])
		{
			return false;
		}
	}

	return true;
}


void ReplaceSpaces1_4(char* s, int size, int newSize)
{
	char* a = s;
	int j = newSize - 1;
	for (int i = size-1; i >= 0; i--)
	{
		if (a[i] == ' ')
		{
			a[j] = '0';
			j--;
			a[j] = '2';
			j--;
			a[j] = '%';
			j--;
		}
		else
		{
			a[j] = a[i];
			j--;
		}
	}
}

string Compression1_5(const string& s)
{
	string compressed;

	int firstGroupPos = 0;
	while (firstGroupPos < s.size())
	{

		// We have the position of the beginning of a group
		// Find the last position that equals this group char

		char firstLetter = s[firstGroupPos];
		int nextGroupPos = firstGroupPos + 1;

		// Find next group position
		while (nextGroupPos < s.size() && s[nextGroupPos] == firstLetter)
		{
			nextGroupPos++;
		}

		int size = nextGroupPos - firstGroupPos;

		// add to final
		compressed += s[firstGroupPos] + to_string(size);

		// Set the position for the next group
		firstGroupPos = nextGroupPos;
	}

	//if (compressed.size() > s.size())
	//{
	//	return s;
	//}
	//return compressed;

	//same as above
	return (compressed.size() > s.size()) ? s : compressed;
}

string Compression1_5b(const string & s)
{
	string compressed;
	char letter = s[0];
	int count = 1;
	for (int i = 1; i < s.size(); ++i)
	{
		if (s[i] == letter)
		{
			count++;
		}
		else
		{
			compressed += letter + to_string(count);
			letter = s[i];
			count = 1;
		}
	}
	compressed += letter + to_string(count);

	if (compressed.size() > s.size())
	{
		return s;
	}
	return compressed;

}

vector<vector<int>> Rotation1_6(const vector<vector<int>>& grid)
{
	
	vector<vector<int>> rotated(grid.size(), vector<int>(grid[0].size()));
	

	

	int n = grid.size();
	for (int i = 0; i < grid.size(); i++)
	{
		for (int j = 0; j < grid[i].size(); j++)
		{
			rotated[j][n - 1 - i] = grid[i][j];
		}
	}
	return rotated;

}

void Rotate90(int n, int i, int j, int& newI, int& newJ)
{
	newJ = i;
	newI = n - 1 - j;
}

void Rotation1_6b(vector<vector<int>>& grid)
{
	int n = grid.size();
	for (int i0 = 0; i0 < grid.size() / 2; i0++)
	{
		for (int j0 = 0; j0 < grid[i0].size() / 2; j0++)
		{
			int i1, j1;
			Rotate90(n, i0, j0, i1, j1);

			int i2, j2;
			Rotate90(n, i1, j1, i2, j2);

			int i3, j3;
			Rotate90(n, i2, j2, i3, j3);

			int& a = grid[i0][j0];
			int& b = grid[i1][j1];
			int& c = grid[i2][j2];
			int& d = grid[i3][j3];

			int temp = d;
			d = c;
			c = b;
			b = a;
			a = temp;

			/*int temp = grid[i3][j3];
			grid[i3][j3] = grid[i2][j2];
			grid[i2][j2] = grid[i1][j1];
			grid[i1][j1] = grid[i0][j0];
			grid[i0][j0] = temp;*/
		}
	}
	

}

void RowColSetZero1_7(vector<vector<int>>& v)
{
	for (int i = 0; i < v.size(); i++) // N
	{
		for (int j = 0; j < v[i].size(); i++) // M
		{
			if (v[i][j] == 0)
			{
				// N + M
				for (int m = 0; m < v[i].size(); m++)
				{
					v[i][m] = 0;
				}
				for (int n = 0; n < v.size(); n++)
				{
					v[n][j] = 0;
				}

			}
		}
	}

	//another solution below (Faster)
	set<int> rows, cols;
	for (int i = 0; i < v.size(); ++i)
	{
		for (int j = 0; j < v[i].size(); ++j)
		{
			if (v[i][j] == 0)
			{
				rows.insert(i);
				cols.insert(j);
			}
		}
	}

	for (int i = 0; i < v.size(); ++i)
	{
		for (int j = 0; j < v[i].size(); ++j)
		{
			if (v[i][j] != 0 && (rows.count(i) || cols.count(i)))
			{
				v[i][j] = 0;
			}
		}
	}
}


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
	string a = "hello, ada!";
	cout << a << endl;
	reverse1_2(&a[0]);
	cout << a << endl;

	//Problem 1.3
	cout << "\nProblem 1.3" << endl;
	vector<tuple<string, string, bool>> tests1_3 =
	{
		{"abc", "bca", true},
		{"hair", "happy", false},
		{"missies", "siemiss", true},
		{"mole", "olmp", false}
	};

	for (tuple<string, string, bool> t : tests1_3)
	{
		string a = get<0>(t);
		string b = get<1>(t);
		bool exp = get<2>(t);

		// ternary expression
		string response = (IsPermutation1_3b(a, b) == exp) ? "passed" : "failed";
		cout << a << " " << b << " " << response << endl;
	}

	cout << "\nProblem 1.4" << endl;
	string john = "Mr John Smith    ";
	cout << john << endl;
	ReplaceSpaces1_4(&john[0], 13, john.size());
	cout << john << endl;

	cout << "\nProblem 1.6" << endl;
	vector<vector<int>> matrix = {
		{1,2,3},
		{4,5,6},
		{7,8,9}
	};
	vector<vector<int>> m = Rotation1_6(matrix);
	for (vector<int>& v : m)
	{
		for (int a : v)
		{
			cout << a << " ";
		}
		cout << endl;
	}




}