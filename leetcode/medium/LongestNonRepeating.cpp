/* 
    Problem: 
    Given a string s, find the length of the longest substring without 
    repeating characters. 
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    //Brute force: 
    //Run time: 136ms 
    //Memory usage: 32.9mb
   int lengthOfLongestSubstring(string s) {

        if(s.length() <= 1) return s.length();

        int lenght = s.length();
        vector<string> substrings; // Container storing all possible substrings 

        // Iterate and check for substrings
        for(int i = 0; i < lenght - 1; ++i){
            string temp = ""; // Temporal storage location for substring 
            temp = s[i];
            for(int j = i + 1; j < lenght; ++j){
                if(temp.find(s[j]) == std::string::npos) {
                    temp += s[j]; 
                }
                else {
                    substrings.push_back(temp);
                    break;
                }
                
                if(j == lenght -1){
                    substrings.push_back(temp);
                    break;
                }
            }
        }

        string temp =  "";
        temp +=  s[lenght - 1];
        substrings.push_back(temp);  // Add last character which was exluded in the iteration 
        
        // Sort all strings according to lenght 
        sort(substrings.begin(), substrings.end(), []
            (const string &first, const string & second){
                return first.size() < second.size();
            }
        );
        
        return   substrings.back().length(); 

    }

    //Sliding window: 
    //Run time: 4ms 
    //Memory usage: 7.7mb

    int lengthOfLongestSubstring2(string s){
        int lenght = s.size();

        if(lenght <= 1) return lenght;

        int maxlenght = 0;

        vector<int> occurance(128); //vector storing all occurances of characters in a string 
        int right = 0, left = 0;

        for( ; right < lenght ; ++right){

            if(occurance[s[right]] != 0) left = max(left, occurance[s[right]]);
             
            maxlenght = max(maxlenght, right - left + 1);
            occurance[s[right]] = right + 1;
            int num =  (s[right]);
        }
        
        return maxlenght; 

    }
};

int main(){
    string input;
    Solution s; 
    getline(std::cin, input);
    
    //Brute force: 
    cout << "Output is: " << s.lengthOfLongestSubstring(input) << endl;

    //Sliding window: 
    cout << "Output2 is: " << s.lengthOfLongestSubstring2(input) << endl;

    return 0;
}

