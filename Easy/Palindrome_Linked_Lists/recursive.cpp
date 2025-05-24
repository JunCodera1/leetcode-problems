class Solution {
private:
    ListNode* curr;

    bool solve(ListNode* head){
        if(!head) return true;

        // Recurse to the end first

        if(!solve(head->next)) return false;

        // Now we're returning back - compare
        if(head->val != curr->val) return false;

        // Move forward pointer
        curr = curr->next;

        return true;
    }
public:
    bool isPalindrome(ListNode* head) {
        curr = head;
        return solve(head);
    }
};
