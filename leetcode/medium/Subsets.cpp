/*
Problem:
    Given an integer array nums of unique elements, return all possible subsets (the power set).
    The solution set must not contain duplicate subsets. Return the solution in any order. 
 */

#include <iostream>
#include <string>
#include <sstream>
#include <vector> 
#include <math.h> 
#include <bitset>

using namespace std;

class Solution {
public:
    // Casceding Approach: 
    // RUNTIME + SPACE COMPLEXITY: 2^N  
    // RUN TIME: 4ms 
    // SPACE COMPLEXITY: 7.2.MB
    vector<vector<int>> subsets(vector<int>& nums) {
       vector<vector<int>> output;

     //Iterate over all numbers in the vector and append number to all combination in the output and append it self
       for(auto num : nums){
            int size = output.size();

            for(int i = 0; i < size; ++i){
               vector<int> temp(output[i]);
               temp.push_back(num);
               output.push_back(temp);
           }
           output.push_back(vector<int>{num});
       }

       output.push_back(vector<int>()); // add empty vector
       return output;
    }

    // Print all subsets in the vector
    void display(const vector<vector<int>>& subsets){
        for(auto subset : subsets){
            cout << "[" ;
            for(auto number : subset){
                cout << number << ",";
            }
            cout << "]" << endl;
        }
    }
    

    // RECURSION + BACKTRACKING
    // RUN TIME: 128ms
    // SPACE COMPLEXITY: 53.7mb
    vector<vector<int>> sets(vector<int>& nums, int next, vector<int> &current, vector<vector<int>> &powerSet) {
        if(next == nums.size()) return powerSet;
        else{
          for(int i = next; i < nums.size(); ++i){
              current.push_back(nums[i]);
              powerSet.push_back(current);
              sets(nums, i + 1, current, powerSet);
              //Back track 
              current.pop_back();
          }
        }
        return powerSet;
    }

    vector<vector<int>> subsets2(vector<int>& nums) {
        vector<vector<int>> powerSet;
        vector<int> current;
        powerSet.push_back(current);
        sets(nums, 0, current, powerSet);
        return powerSet;
    }


};

//  extract all numbers from string and store them in a vector
vector<int> getNumbers(string str){
    stringstream ss; 
    vector<int> numbers;
    int number; 
    string temp; //storing the temporal char to be converted to int 
    ss << str; 

    while(!ss.eof()){
        ss >> temp; 
        if(stringstream(temp) >> number){
            numbers.push_back(number);
        }
        temp = "";
    }

    return numbers; 
}

int main(){
    string str; 
    getline(cin, str); 
    vector<int> numbers = getNumbers(str);
    
    Solution s; 
    s.display(s.subsets(numbers));

    return 0; 
}