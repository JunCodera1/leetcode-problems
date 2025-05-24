class Solution {
public:
    ListNode* reverse(ListNode* head){
        ListNode* prev = nullptr;
        while(head){
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
    // NULL<-1 2->1->2->1
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;

        // Step 1 : Find middle using two pointers
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next){
            slow = slow ->next;
            fast = fast->next->next;
        }
        //Step 2: Reverse second half
        ListNode* secondHalf = reverse(slow);

        // Step 3: Compare both halves
        ListNode* firstHalf = head;
        while(secondHalf){
            if(firstHalf->val != secondHalf->val){
                return false;
            }
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }
        return true;
    }
};
