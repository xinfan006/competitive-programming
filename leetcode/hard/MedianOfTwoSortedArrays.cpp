#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/* 
PROBLEM : 
    Given two sorted arrays nums1 and nums2 of size m and n respectively, 
    return the median of the two sorted arrays. 
*/

class Solution {
public:
     // Merge two vector using merge sort technique
     // Time complexity: 2T(n/2) + θ(n) 
     vector<int> mergeVectors(vector<int> &nums1, vector<int> &nums2){
            vector<int> mergedNums;
            int x = 0; 
            int y = 0;

            for(int i = 0; i < nums1.size() + nums2.size(); ++i){
                if(x >= nums1.size()){
                    mergedNums.push_back(nums2[y]);
                    ++y;
                }
                else if(y >= nums2.size()){
                    mergedNums.push_back(nums1[x]);
                    ++x;
                }
                else if(nums1[x] <= nums2[y]){
                    mergedNums.push_back(nums1[x]);
                    ++x;
                }
                else{
                    mergedNums.push_back(nums2[y]);
                    ++y;
                }
            }

            return mergedNums;
        }
    
    // calculate median 
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
         vector<int> mergedNums = mergeVectors(nums1, nums2);
          int mid = mergedNums.size() /2; 

          if(mergedNums.size() == 1){
              return mergedNums[0];
          }
          else if(mergedNums.size() % 2 != 0){
              return mergedNums[mid];
          }
          else{
              double median = ((double)mergedNums[mid] + (double)mergedNums[mid -1]) /2;
              return median;
          }
        
    }
};