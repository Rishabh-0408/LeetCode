/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* merge(ListNode* list1, ListNode* list2){
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;
        while(list1 != nullptr && list2 != nullptr){
            if(list1 -> val <= list2 -> val){
                temp -> next = list1;
                list1 = list1 -> next;
            }
            else{
                temp -> next = list2;
                list2 = list2 -> next;
            }
            temp = temp -> next;
        }
        if(list1 != nullptr){
            temp -> next = list1;
        }
        if(list2 != nullptr){
            temp -> next = list2;
        }
        ListNode* ans = dummy -> next;
        delete dummy;
        return ans;
    } 
    ListNode* findmiddle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast != nullptr && fast -> next != nullptr){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return slow;
    }
    ListNode* sortList(ListNode* head) {
        //always write base case 
        if (head == nullptr || head -> next == nullptr) {
            return head;
        }
        ListNode* middle = findmiddle(head);
        //divide the list into two parts
        ListNode* right = middle -> next;
        middle -> next = nullptr;
        ListNode* left = head;

        //recursion
        left = sortList(head);
        right = sortList(right);

        //calling merge function
        return merge(left,right);
    }
};