
#include <iostream>
#include <string>

using namespace std;

/* 
Problem: 
    Given a string s, return the longest palindromic substring in s. 
*/

class Solution {
public:
// Brute force 
// Run time: 300ms (O(n^2))
// Memory usage: 6.9mb (O(1))
/* 
    Intuition: starting with range i(0) and j(lenght of substring) find the longest substring, 
    that is all characters in the range i-j have equal corrsponding char ( i -n == j - n && i != j) 
*/
    string longestPalindrome(string s) {
        int lenght = s.size();
        if(lenght <= 1) return s.substr(0, 1);

        string maxPalindrome = "";
        maxPalindrome += s[0];
        int left = 0, right = 0; // range of the longest palindromic substring 
        bool lastPalindrome = false;

        //  Iterate over string starting from index 0 
        for(int i = 0; i < lenght; i++) {
            int temp = 0; // temporal which stores how man positions we have moved in the iteration
    
            for(int j = lenght -1; i != j ; --j){
                if(s[i] == s[j]){
                   if((j -1   == i || i + 1 == j - 1)){
                        if(right - left < (j + temp) - (i -temp)){
                            left = i- temp; right = j + temp;
                        
                            // change value oflongest substring if current is longer 
                            if( maxPalindrome.empty() || right - left  > maxPalindrome.size() -1 ) {
                                maxPalindrome = s.substr(left, right - left + 1);
                                // Stop and return if current substring is => than half the string and we have explored more than half of string
                                if(i >= lenght/2 && maxPalindrome.size() >= lenght/2) return maxPalindrome;
                            }
                        }
                        
                        // Reset i from all iterations 
                        i -= temp; 
                        break;
                   }
                   lastPalindrome = true;
                   ++i;  
                   ++temp; 
                }
                else{
                    left = 0; 
                    right = 0; 
                    
                    if(lastPalindrome){
                        i -= temp; 
                        j += temp; 
                        temp = 0; 
                        lastPalindrome = false;
                    }
                    else if(j -1    == i || i + 1 == j - 1)  i = i - temp; 
                }
            }
            lastPalindrome = false; 
        }

        return maxPalindrome; 
    }
};

int main(){
    Solution s; 
    string input;

    getline(cin, input);

    cout << "Output: "<< s.longestPalindrome(input) << endl;
    return 0; 
}