// learning : how to handle equality collision in 2d arrays.
class Solution
{
public:
    static bool cmp(const vector<int> &pt1, const vector<int> &pt2)
    {
        if (pt1[0] < pt2[0])
            return pt1[0] < pt2[0];
        else
            return pt1[1] < pt2[1];
    }
    int findMinArrowShots(vector<vector<int>> &points)
    {
        if (points.size() == 0)
            return 0;
        // if(points.size()==1)
        //     return 1;
        sort(points.begin(), points.end(), cmp);
        // for (auto x : points)
        //     for (auto y : x)
        //         cout << y << " ";
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
