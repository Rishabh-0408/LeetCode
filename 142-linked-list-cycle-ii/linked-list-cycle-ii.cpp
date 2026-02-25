/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* temp = head;
        unordered_map<ListNode*,int> map;
        while(temp != nullptr){
            if(map.find(temp) != map.end()){
                return temp;
            }

            //otherwise
            map[temp] = 1;
            temp = temp -> next;
        }
        return temp;
    }
};