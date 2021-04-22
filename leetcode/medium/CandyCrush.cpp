#include <iostream>
#include <string>

using namespace std;

class Solution {
   public: 
     string candyCrush(string &str){
         if(str.length() <= 2){
             return str;
         }
         int curr  = 1, repeatingChar = 1; 

         //Iterate over string and remove repeating char according to rule 
         while(!str.empty() && curr != str.length()){
             if(str[curr] == str[curr -1]){
                 ++repeatingChar;
                 ++curr; 
                 if(curr == str.length() && repeatingChar >= 3){
                       str.erase(curr - repeatingChar, repeatingChar);
                       return str; 
                 }
             }
             else{
                 if(repeatingChar >= 3){
                     str.erase(curr - repeatingChar, repeatingChar);
                     curr = 0; 
                 }
                 else ++curr;
                 repeatingChar = 1;
             }
         }
         return str; 
     }
};

int main(){
    string str; 
    getline(cin, str);
    Solution s; 
    cout << "Output: " << s.candyCrush(str) << endl;
    return 0;
}