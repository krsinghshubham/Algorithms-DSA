// faster 

class Solution
{
public:
  // first sort the nums
  // since nums is sorted so dupicate subsets will occur consecutively. so before adding
  // we have to check if its already exist or not.
  vector<vector<int>> subsetsWithDup(vector<int> &nums)
  {
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end()); // sorted to make dups came one after each other.
    vector<int> bufferVector;
    addSets(nums, 0, bufferVector, ans);
    return ans;
  }
 // map<vector<int>, int>mp;
  // unordered_map<vector<int>, int>mp;
     set<vector<int>>mp;

  void addSets(vector<int> nums, int index, vector<int> bufferVector, vector<vector<int>> &ans)
  {
    if(index==nums.size())
    {
        ans.push_back(bufferVector);
        return;
    }
    bufferVector.push_back(nums[index]);
      if(mp.count(bufferVector)==0)
      {
        mp.insert(bufferVector);
        addSets(nums, index+1,bufferVector, ans);
      }
      bufferVector.pop_back();
      addSets(nums, index+1, bufferVector,ans);
  }
};

// slower: 640ms, 170 MB
class Solution
{
public:
  bool contains(vector<vector<int>> &ans, vector<int> &subSet)
  {
    // for(auto jp: ans)
    // {
    //     for(auto jpp: jp)
    //         cout<<jpp<<" ";
    //     cout<<endl;
    // }
    cout << endl;
    vector<vector<int>>::iterator itAns = ans.begin();
    for (auto x : ans)
    {
      if (subSet.size() != x.size())
        continue;
      map<int, int> mpForVec;
      map<int, int> mpForSubSet;
      for (auto it : x)
        mpForVec[it]++;
      for (auto itChild : subSet)
        mpForSubSet[itChild]++;
      // if both elements does not contans same no of elements , it does not contain other wise not.
      if (mpForVec == mpForSubSet)
        return true;
    }
    if (itAns == ans.end()) // does not contain
      return false;
    return false;
  }
  void addSubSetsWithoutDups(int size, vector<int> nums, vector<int> subSet, int index, vector<vector<int>> &ans)
  {

    if (index > size - 1) // index cross over
    {
      if (!contains(ans, subSet))
        ans.push_back(subSet);
      return;
    }
    subSet.push_back(nums[index]);
    addSubSetsWithoutDups(size, nums, subSet, index + 1, ans); // element addedd to subset
    subSet.pop_back();
    addSubSetsWithoutDups(size, nums, subSet, index + 1, ans); // element not addedd to subset
  }
  vector<vector<int>> subsetsWithDup(vector<int> &nums)
  {
    // no reptitions in chart using recursion, time is O(2^n) but n is less than 10, so it will run
    int index = 0;
    int size = nums.size();
    vector<vector<int>> ans;
    vector<int> subSet = {};
    addSubSetsWithoutDups(size, nums, subSet, index, ans);
    return ans;
  }
};