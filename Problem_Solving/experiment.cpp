//problem link:
// Reference linK:
// learning:
#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define fo(i, n) for (int i = 0; i < n; i++)
#define FAST_INPUT_OUTPUT_TEMPLATE_TEMPLATE ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define pb push_back
#define PI 3.1415926535897932384626
#define INF 1000000007

void printAllPermutation(string str, string osf)
{
  if (str.length() == 0)
  {
    cout << osf << endl;
    return;
  }
  unordered_set<char> uset;
  for (int i = 0; i < str.size(); i++)
  {
    if (uset.count(str[i]) == 0)
      printAllPermutation(str.substr(0, i) + str.substr(i + 1), osf + str[i]);
    uset.insert(str[i]);
  }
}
// "ABC" , i=0
// abc, i=0;

void printAllPermutationWithoutRecursion(string str, int index)
{
  if (index == 2)
  {
    cout << str << endl;
    return;
  }
  for (int i = 0; i < str.length(); i++)
  {
    swap(str[i], str[index]);
    printAllPermutationWithoutRecursion(str, index + 1);
    swap(str[i], str[index]);
  }
}

int main()
{
  clock_t begin = clock();
  //* --------------------------------
// void printAllPermutation("ai","");
//   printAllPermutation("ABC", "");
//   cout << "\n\n\n";
//   printAllPermutationWithoutRecursion("ABC", 0);

char str[30]="12345678910111213";
// cout<<strrchr(str, '2')-str;
int x= 5<3;

  //*---------------------------------
  clock_t end = clock();
  cout << "\n\nExecute In: " << double(end - begin) / CLOCKS_PER_SEC << " ms";
  return 0;
}
