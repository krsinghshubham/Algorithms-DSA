//problem link:https://www.spoj.com/problems/MPOW/
// Reference linK: https://www.youtube.com/watch?v=d8xB9jgEu-A&list=PL2q4fbVm1Ik4liHX78IRslXzUr8z5QxsG&index=11&ab_channel=CodeNCode
//* learning: implement BINARY EXPONENTIATION CONCEPT TO OPTIMISE IT.
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define PI 3.1415926535897932384626
#define INF 1000000000 //10 ^9
#define fo(i, n) for (size_t i = 0; i < n; i++)
#define N 101
ll matrix[N][N], I[N][N];
/*
ALGORITHM
1. take tc
2 for tc--, 
get dimension and power
take matrix input
declare and identity matrix to store in result
store the result matrix result back in identity , do this for the power times.
to calculate result multiply the array with ressult.
optimise it.
*/
void matrixMultiplication(ll arr[][N], ll Ix[][N], int dim) //
{                                                           // will store the final result into I to update it.
    ll result[dim + 1][dim + 1];                            //need to hold the long products.
    // multiplication of two arrays beginning....

    fo(i, dim)
        fo(j, dim)
    {
        result[i][j] = 0;
        fo(k, dim)
        {
            // ll temp = ((arr[i][k] * Ix[k][j]) % 1000000007);

            // result[i][j] = (result[i][j] + temp % 1000000007); // rows elemet cross columns element. //! its arr * I no ( I*I )

            result[i][j] =(result[i][j]+((arr[i][k] * Ix[k][j]) % 1000000007) )% 1000000007; // rows elemet cross columns element. //! its arr * I no ( I*I )
        }
    }

    fo(i, dim)
        fo(j, dim)
            I[i][j] = result[i][j]; // identity matrix updated.
    // ! next time this I will be updated.
}
int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.tie(NULL);
    int tc;
    cin >> tc;
    while (tc--)
    {
        int dim, power;
        cin >> dim >> power;
        // int matrix[dim][dim]; DECLALRED GOLBALLYJ,COZ IT WAS CAUSING PROBLEMS.
        fo(i, dim)
                fo(j, dim)
                    cin >>
            matrix[i][j]; // input taken

        // int I[dim][dim];
        fo(i, dim)
            fo(j, dim) if (i == j)
                I[i][j] = 1;
        else
        {
            I[i][j] = 0;
        }
        // identity matrix set.

        // *Naive method, complexity M^3*N
        // fo(i, power) //? Need to optimise it there.
        // {
        //     matrixMultiplication(matrix, I, dim);  //each time we will update I.
        // }

        //* Optimized METHOD using Binray exponentiation, COMPLEXITY M^3*logN
        while (power)
        {
            if (power % 2)
                matrixMultiplication(matrix, I, dim), power--; // odd then decrement power by 1 and multiply by result
            // dry run binary exponentiation if doubted
            else
            {
                matrixMultiplication(matrix, matrix, dim), power /= 2;
            }
        }
        // uptill now I contains the array. ... we can store this result back into the original array.
        fo(i, dim)
        {
            fo(j, dim)
                matrix[i][j] = I[i][j];
        }
        fo(i, dim)
        {
            fo(j, dim)
                    cout
                << matrix[i][j] << " ";
            cout << "\n";
        }
    }

    return 0;
}
// 2
// 2 3
// 1 0
// 1 1
// 3 3
// 1 0 4
// 1 2 2
// 0 4 42
