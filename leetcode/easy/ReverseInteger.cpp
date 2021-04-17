#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        string str = to_string(x);

        //Swap variables
       int start = 0, end = str.length() -1;
       while(start < end){
           str[start] ^= str[end];
           str[end] ^= str[start];
           str[start] ^= str[end];
           ++start;
           --end;
       }
         cout << str << endl;
        int res = stoul(str);
           cout << res << endl;
       if(x < 0 && -res >= INT_MIN){
           return -res;
       }
       if(x > 0 && res <= INT_MAX){
           return res; 
       }

        return 0;
    }
};

int main(){
    Solution s;
    int num; 
    cin >> num;
    cout << "\n" << s.reverse(num) << endl;
    return 0;
}