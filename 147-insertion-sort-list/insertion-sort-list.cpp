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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* jNode = head;
        while(jNode != NULL){
            ListNode* iNode = head;
            while(iNode != jNode){
                if(iNode->val > jNode->val){
                    swap(iNode->val, jNode->val);
                }
                iNode = iNode->next;
            }
            jNode = jNode->next;
        }
        return head;
    }
};