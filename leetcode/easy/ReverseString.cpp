#include <iostream>
#include <string>

using namespace std;


class Solution {
    public:

    string reverse(string str){
       int start = 0, end = str.length() -1;

       while(start < end){
           str[start] ^= str[end];
           str[end] ^= str[start];
           str[start] ^= str[end];
           ++start;
           --end;
       }
       return str; 
    }
};