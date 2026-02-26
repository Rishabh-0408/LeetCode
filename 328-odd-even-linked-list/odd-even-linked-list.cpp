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
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* Odd = head;
        ListNode* Even = head -> next;
        ListNode* EvenNode = Even;
        while(Even != nullptr && Even->next != nullptr){
            Odd -> next = Odd -> next -> next;
            Odd = Odd -> next;
            Even -> next = Even -> next -> next;
            Even = Even  -> next;
        }
        Odd -> next = EvenNode;
        return head;
    }
};