#include <vecotr>
#include <algorithm>
#include <sting>

using namespace std;

/* 
Problem: 
    A company is planning to interview 2n people. Given the array costs where costs[i] = [aCosti, bCosti], the cost of flying the ith person to city a is aCosti, and the cost of flying the ith person to city b is bCosti.
    Return the minimum cost to fly every person to a city such that exactly n people arrive in each city. 
*/

 //sort vector according two bigger diffence
 bool wayToSort(vector<int> i,vector<int> j){
        int differenceA = abs(i[0] - i[1]);
        int differenceB = abs(j[0] - j[1]);
        return differenceA > differenceB;
    }

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(),costs.end(),wayToSort); //Sort costs according two biggest cost
        int minCost = 0;
        int cityA = 0;
        int cityB = 0;
        
        // Iterate over vector and select the cost with minimum incurring cost 
        for(int i = 0; i < costs.size();++i){
          if(costs[i][0] < costs[i][1] && cityA < costs.size()/2){
               minCost += costs[i][0];
               ++cityA;
           }
           else if(costs[i][0] > costs[i][1] && cityB < costs.size()/2){
                minCost += costs[i][1];
                ++cityB;
           }
           else if(cityA == costs.size()/2){
                minCost += costs[i][1];
                ++cityB;
           }
           else{
               minCost += costs[i][0];
               ++cityA;
           }
        }
   return minCost;
    }
};