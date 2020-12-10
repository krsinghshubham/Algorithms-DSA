// Find the next lexicographically : https://www.geeksforgeeks.org/find-the-next-lexicographically-greater-word-than-a-given-word/
/* we can use 
bool x= next_permutation(s.begin(), s.end()) // which permutted and returns a boolean that if the permutaion happened or not.
*/
#include <iostream>
using namespace std;
// algo in notebook.
void revers(string &s, int l, int r) //! VERY IMPORATANT LEARNING ... IF WE DONT USE & THEN IT WONT CHANGE THE ORIGINAL STINGG. IN THAT CASE WE HAVE TO RETURN A STRING.
{
	while (l < r)
		swap(s[l++], s[r--]);
}

bool nextpermutaion(string &s) //! VERY IMPORATANT LEARNING ... IF WE DONT USE & THEN IT WONT CHANGE THE ORIGINAL STINGG. IN THAT CASE WE HAVE TO RETURN A STRING.
{ //abedc
	//a(b)edc
	//a(b)ed(c)
	// last index se left traverse...
	// find index which is breaking descending order
	// if its -1 it means it already sorted in ascending order , print and return false and break.
	// swap the index with the next big in right
	// to find next big use binary searcch to get index of that next big.. use binary search for fast traversal... u can iterate linearly too to get element
	// swap i with that index.
	// sort/reverse the substring from i+1 to length-1... (reverse will also work becuase substring is already sorted but in reverse order.)
	int n = s.length(); // consider s="abedc"v
	int i = n - 2;
	while (i >= 0 && s[i] >= s[i + 1])
	{
		i--;
	}
	//in i  we got the value of index which is breaking the sequence.
	int index;
	if (i < 0) // already last of the sequecne, next would be completly sorted.
	{
		revers(s, 0, n - 1);
		return false;
	}
	// cout<<i<<endl;
	// string is already sorted.
	for (int x = n - 1; x > i; x--) //to find next big we can use binary search to optimise this because right now this is o(n) // complexity of programe is also o(n)
	{
		if (s[x] > s[i])
		{
			swap(s[x], s[i]);
			break;
		}
	}
	// cout<<s<<endl;
	revers(s, i + 1, n - 1);
	// cout<<s<<endl;
	return true;
}

int main()
{
	string s = "abedc";

	bool val = nextpermutaion(s);
	if (val == false)
		cout << "No Word Possible" << endl;
	else
		cout << s << endl;
	return 0;
}
