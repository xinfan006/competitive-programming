#include <vecotr>
#include <algorithm>
#include <sting>

using namespace std;

class Solution {
public:
     vector<vector<int>> sets(vector<int>& nums, int next, vector<int> &current,              vector<vector<int>> &powerSet) {
        if(next == nums.size())return powerSet;
        else{
          for(int i = next; i < nums.size(); ++i){
              current.push_back(nums[i]);
              powerSet.push_back(current);
              sets(nums, i + 1, current, powerSet);
              current.pop_back();
          }
        }
        return powerSet;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> powerSet;
        vector<int> current;
        powerSet.push_back(current);
        sets(nums, 0, current, powerSet);
        return powerSet;
    }
    
  
};