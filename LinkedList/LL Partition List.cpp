//Input: head = [1,4,3,2,5,2], x = 3
//Output: [1,2,2,4,3,5]

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
     ListNode* partition(ListNode* head, int x) {

        ListNode* small = new ListNode(0);
        ListNode* large = new ListNode(0);
        ListNode* small_head = small;
        ListNode* large_head = large;

        while (head){
            if (head->val < x){
                small->next = head;
                small = small -> next;
                head = head -> next;
                small->next = nullptr;
            }
            else{
                large->next = head;
                large = large -> next;
                head = head -> next;
                large -> next = nullptr;
            }
        }
        small -> next = large_head -> next;

        return small_head -> next;
    }
};