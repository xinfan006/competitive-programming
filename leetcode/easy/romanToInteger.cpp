#include <iostream>
#include <string>

using namespace std;

class Solution {
public:

    //RUN TIME: 8ms
    //MEMORY USAGE: 5.8mb
    int romanToInt(string s) {
        int sum = 0; 

        for(int i = s.length() -1; i >= 0 ; --i){
            if(s[i] == 'I'){
                sum += 1; 
                continue;
            } 
            else if(s[i] == 'V'){
                if(i - 1 >= 0 && s[i-1] == 'I'){
                    sum += 4; 
                    --i;
                }
                else sum += 5;
                continue;

            }
            else if(s[i] == 'X'){
                 if(i - 1 >= 0 && s[i-1] == 'I'){
                     sum += 9;
                     --i;
                 }
                 else sum += 10;
                 continue;
            }
            else if(s[i] == 'L'){
                if(i - 1 >= 0 && s[i-1] == 'X'){
                    sum += 40;
                    --i;
                }
                else sum += 50;
                continue;
            }
            else if(s[i] == 'C'){
                  if(i - 1 >= 0 && s[i-1] == 'X'){
                       sum += 90;
                       --i;
                  }
                   else sum += 100;
                   continue;
            }
            else if(s[i] == 'D'){
                if(i - 1 >= 0 && s[i-1] == 'C'){
                       sum += 400;
                       --i;
                  }
                   else sum += 500;
                   continue;
            }
            else {
                 if(i - 1 >= 0 && s[i-1] == 'C'){
                       sum += 900;
                       --i;
                  }
                   else sum += 1000;
            }
        }

        return sum;
    }

    int mapToInt(char &c){
    if(c == 'I') return 1;
    if(c == 'V') return 5;
    if(c == 'X') return 10;
    if(c == 'L') return 50;
    if(c == 'C') return 100;
    if(c == 'D') return 500;
    else if(c == 'M') return 1000;
    return 0;
    }
    
    //RUN TIME: 4ms
    //MEMORY USAGE: 5.9mb
    int romanToInt2(string str){
        //stores last added/substructed number
        int prev = 0;
        int sum = 0;
        for(int i = str.length() - 1; i >= 0 ; --i){
          int num = mapToInt(str[i]);
          if(num >= prev) sum += num;
          else sum -= num;
          prev = num;
        }

        return sum;
    }
};

int main(){
    string str; 
    cin >> str; 
   
    Solution s; 
    cout << "Output: " << s.romanToInt2(str) << endl;
    return 0; 
}
