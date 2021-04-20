#include <iostream>
#include <string>

using namespace std; 

 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };


class Solution{
    public: 
        // runtime error: signed integer overflow: 1000000000000000000 * 10 cannot be represented in type 'int' 
        // return the sum of all values from listNode
          int getNumberFromList(ListNode * l){
            int sum = 0; 
            int decimal = 1; //storing decimal digit of value to be calculated

            while(l != nullptr){
                sum += l->val * decimal; 
                decimal *= 10;
                l = l->next;
            }
            return sum; 
        }

        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            string sum = to_string(getNumberFromList(l1) + getNumberFromList(l2));
            int last = sum.length() -1;
            ListNode *first = new ListNode(sum[last] - '0'); 
            ListNode *curr = first;

            //iterate overall numbers in the string and store them in the list
            for(int i = last-1; i >= 0; --i){ 
                ListNode *temp = new ListNode(sum[i] - '0');
                curr->next = temp; 
                curr = temp;
            }

            return first;
        }
        
        // RUN TIME: 36 ms
        // MEMORY USAGE: 71.4 mb
        ListNode* addTwoNumbers2(ListNode* l1, ListNode* l2) {
            int takeOne = 0; // variable storing an increment to be added to right digit
            ListNode * first; 
            ListNode * curr; 
            
            for(int i = 0; l1 != nullptr || l2 != nullptr || takeOne != 0; ++i){
                int temp1 = 0, temp2= 0;

                if(l1 != nullptr){
                    temp1 = l1->val; 
                    l1 = l1->next;
                } 
                if(l2 != nullptr){
                    temp2 = l2->val;
                    l2 = l2->next; 
                }

                ListNode * temp = new ListNode(((temp1 + temp2 + takeOne) % 10) ); //store the decimal digit of an addition in the list 
                takeOne = (temp1 + temp2+ takeOne)/ 10;  
        
                if(i == 0){
                    first = temp;
                    curr = temp; 
                    continue; 
                }

                curr -> next = temp; 
                curr = temp; 
            }

            return first; 
        }
};

