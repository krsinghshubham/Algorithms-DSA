//problem link:
// Reference linK:https://www.youtube.com/watch?v=geLyvdjxQNg&list=PL2q4fbVm1Ik4liHX78IRslXzUr8z5QxsG&index=6&ab_channel=CodeNCode
// Reference: https://www.geeksforgeeks.org/print-all-prime-factors-of-a-given-number/
// learning: Optimized method for finding it.
//! Optimized !!
#include <bits/stdc++.h>

using namespace std;

void primeFactors(int n)
{
	for (int i = 2; i * i <= n; i++) // think 18 and 17*17*19
	{
		int count = 0;
		while (n % i == 0) // 2*3*3
		{
			count++;
			n = n / i;
		}
		if (count >= 1)
			cout << i << "^" << count << " "; // for composite n=0 till here, but for ex. 19 or prime it wont be zero.
	}
	// uptill here all composite no cases handled.
	if (n > 1) // no is prime and left out, no. itself will be the prime factor.
		cout << n << "^" << 1;
}
int main()
{
	int n;
	cin >> n;
	primeFactors(n);
	return 0;
}
// TIME COMPLEXITY: o(sqrt N) ... sayad
