// concept already discussed in notebook
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) 
    {
        // as a[i] is less than n, we can use indexing. 
        vector<int>ans;
        for(int i=0;i<nums.size();i++)
        {
            while(nums[i]!=i+1 && nums[i]>0)
            {   if(nums[i]==nums[nums[i]-1] && nums[i]>0)
                {
                   
                    ans.push_back(nums[i]);
                 nums[i]*=-1;
                    break;
                }
             else
                swap(nums[i],nums[nums[i]-1]);
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
