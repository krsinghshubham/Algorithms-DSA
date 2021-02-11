// concept already discussed in notebook
class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        // as a[i] is less than n, we can use indexing.
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            while (nums[i] != i + 1)
            {
                if (nums[i] == nums[nums[i] - 1])
                {
                    // ans.push_back(nums[i]); // will do at the end, other wise we have to put -ve.
                    break;
                }
                else
                    swap(nums[i], nums[nums[i] - 1]);
            }
        }
        for (int i = 0; i < nums.size(); i++) // check faulty indexes.
        {
            if (nums[i] != i + 1)
                ans.push_back(nums[i]);
        }
        return ans;
    }
};

// [4,3,2,7,8,2,3,1]

// [1,2,3,4,5,2,7,8]
//  1,2,3,4,5,6,7,8

//      2

// [1,3,2,7,8,2,3,1]

// [1,2,3,3,8,2,7,1]
//  1,2,3,4,5,6,7,8
// * LESS OPTIMIZED ALGORITHM BELOW. 
class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        // as a[i] is less than n, we can use indexing.
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            while (nums[i] != i + 1 && nums[i] > 0)
            {
                if (nums[i] == nums[nums[i] - 1] && nums[i] > 0)
                {

                    ans.push_back(nums[i]);
                    nums[i] *= -1;
                    break;
                }
                else
                    swap(nums[i], nums[nums[i] - 1]);
            }
        }
        return ans;
    }
};

// [4,3,2,7,8,2,3,1]

// [1,2,3,4,5,2,7,8]
//  1,2,3,4,5,6,7,8

//      2

// [1,3,2,7,8,2,3,1]

// [1,2,3,3,8,2,7,1]
//  1,2,3,4,5,6,7,8
