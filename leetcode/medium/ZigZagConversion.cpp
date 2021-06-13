/* 
Problem: 
    Transfer given string in zigzag pattern according to number of Rows and return the  
*/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  
    // Intuition: return all characters in the row
    // Run time: 4ms(O(n))
    // Memory usage: 8.1mb(O(n))
    
    string convert(string s, int numRows) {

        if(s.size() <= 1 || numRows <= 1 || s.size() <= numRows) return s; 

        string output = ""; 
        int stringLength = s.size(), skipZigZag = numRows - 2;  // skipZigZag excempt first and last row adding ZigZag char in  the middle 
        
        for(int i = 0; i < numRows && i < stringLength; ++i){
            output += s[i]; // append first character in the row 
            int numIterations = 0;  // store the current column we are at 
            int currentZigZag = numRows + skipZigZag -1; // first zigZag character in th middle 
            for(int j = i ; j < stringLength; ){
                j += numRows;
                if(i != 0 && i != numRows -1 && currentZigZag- (i-1) < stringLength){
                    output += s[currentZigZag - (i-1)];
                    currentZigZag += (numRows + skipZigZag);
                    ++numIterations;
                }
                j +=  skipZigZag; 
                if(j < stringLength) output += s[j];
            }
        }
        
        return output;
    }
};

int main(){
    string s;
    int numberRows; 
    Solution solution; 

    cin >> s >> numberRows;
    cout << "Output: "<< solution.convert(s, numberRows) << "\n" <<endl; 
    return 0; 
}