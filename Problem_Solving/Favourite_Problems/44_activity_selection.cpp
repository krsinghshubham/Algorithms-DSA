//problem link: https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/  in sheet its same as 1st quesstion but here i am implementing another question based on same concept.
// Reference linK: activity selection. type.
// learning: comparator in sort function and that too in ternary format.
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fo(i, n) for (int i = 0; i < n; i++)
#define FAST_INPUT_OUTPUT_TEMPLATE_TEMPLATE ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define pb push_back
#define PI 3.1415926535897932384626
#define INF 1000000000 //10 ^9
/*
Algorithm:
SIMILAR as N meeting in one room
* NlognN for sort, N for traversal , overall Nlogn. 
* Time: O(nlogn), Space: O(1)
*/

class Solution
{
public:
  static bool cmp(const vector<int> &pt1, const vector<int> &pt2)
  {
    if (pt1[1] == pt2[1])
      return pt1[0] < pt2[0];
    return pt1[1] < pt2[1];
  }
  /* 
  Above function can be written in form of ternary operator as:
  
  static bool cmp(const vector<int> &p1, const vector<int> &p2)
      {
         return p1[1] < p2[1] || (p1[1] == p2[1] && p1[0] > p2[0]);
      }
  */

  int findMinArrowShots(vector<vector<int>> &points)
  {
    if (points.size() == 0)
      return 0;
    // if(points.size()==1)
    //     return 1;
    sort(points.begin(), points.end(), cmp);
    for (auto x : points)
      for (auto y : x)
        cout << y << " ";
    int arrows = 0;
    //int currLeft=points[0][0];
    int currRight = 0;
    for (int i = 0; i < points.size(); i++)
    {
      currRight = points[i][1];                                      //!
      while (i + 1 < points.size() && points[i + 1][0] <= currRight) //!
        i++;
      arrows++;
    }
    return arrows;
  }
};
/*
                    (9,  10)
               (7,          12)
            (6,   8)
        (3,       8),9)9)
    (2            8),9)
(0,          6),          9) 
________________________________________________
                        (7,8)
                (5,6)
        (3,4)
(1,2)



//                                        (10,                 16)


        
//                      (7,                        12)


                                        
//     (2,                      8)

// (1,             6)
...........................................



                                (7,  8)
                    (5      6)
       (2      6)
 (1       4)             .
_________________________________________________




*/
/*
                    (9,  10)
               (7,          12)
            (6,   8)
        (3,       8),9)9)
    (2            8),9)
(0,          6),          9) 
________________________________________________
                        (7,8)
                (5,6)
        (3,4)
(1,2)



//                                        (10,                 16)


        
//                      (7,                        12)


                                        
//     (2,                      8)

// (1,             6)
...........................................



                                (7,  8)
                    (5      6)
       (2      6)
 (1       4)             .
_________________________________________________




*/