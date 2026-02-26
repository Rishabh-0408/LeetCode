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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL){
            return NULL;
        }
        // if(head -> next = nullptr){
        //     delete(head);
        // }
        ListNode* temp = head;
        ListNode* prev = NULL;
        //ListNode* front;
        int count = 0;
        while(temp != nullptr ){
            count++;
            temp = temp -> next;
        }
        int newcount = count - n;
        if(newcount == 0){
            ListNode* todelete = head;
            head = head -> next;
            delete todelete;
            return head;
        }
        temp = head;
        for(int i = 0; i < newcount-1;i++){
            temp = temp -> next;
        }

        ListNode* toDelete = temp->next;
        temp->next = temp->next->next; // Bypass the node
        delete toDelete;
        return head;
    }
};