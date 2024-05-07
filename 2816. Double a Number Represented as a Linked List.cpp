// You are given the head of a non-empty linked list representing a non-negative integer without leading zeroes.

// Return the head of the linked list after doubling it.

 

// Example 1:


// Input: head = [1,8,9]
// Output: [3,7,8]
// Explanation: The figure above corresponds to the given linked list which represents the number 189. Hence, the returned linked list represents the number 189 * 2 = 378.
// Example 2:


// Input: head = [9,9,9]
// Output: [1,9,9,8]
// Explanation: The figure above corresponds to the given linked list which represents the number 999. Hence, the returned linked list reprersents the number 999 * 2 = 1998. 
 

// Constraints:

// The number of nodes in the list is in the range [1, 104]
// 0 <= Node.val <= 9
// The input is generated such that the list represents a number that does not have leading zeros, except the number 0 itself.


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
    ListNode* doubleIt(ListNode* head) {
        std::stack<int> s;
        
        // Push values of the linked list onto the stack
        while (head != nullptr) {
            s.push(head->val);
            head = head->next;
        }
        
        ListNode* tail = nullptr;
        int res = 0;
        // Process each digit in the sum, starting from the least significant digit
        while (!s.empty() || res != 0) {
            tail = new ListNode(0, tail);
            if (!s.empty()) {
                res += s.top() * 2; // Double the digit and add the carry
                s.pop(); // Pop the used digit
            }
            tail->val = res % 10; // Store the least significant digit
            res /= 10; // Update the carry for the next iteration
        }

        return tail;
    }
};