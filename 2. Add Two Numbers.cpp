// You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 

// Example 1:


// Input: l1 = [2,4,3], l2 = [5,6,4]
// Output: [7,0,8]
// Explanation: 342 + 465 = 807.
// Example 2:

// Input: l1 = [0], l2 = [0]
// Output: [0]
// Example 3:

// Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
// Output: [8,9,9,9,0,0,0,1]
 

// Constraints:

// The number of nodes in each linked list is in the range [1, 100].
// 0 <= Node.val <= 9
// It is guaranteed that the list represents a number that does not have leading zeros.


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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode* ptr1 = l1 ;
        ListNode* ptr2 = l2 ;

        ListNode* head = new ListNode (-1) ;
        ListNode* tail = head ;

        int sum = 0 ;
        int carry = 0 ;
        while ( ptr1 != nullptr && ptr2 != nullptr )
        {
            sum = ptr1 -> val + ptr2 -> val + carry ;
            if( sum > 9 )
            {
                tail -> next = new ListNode ( sum % 10 ) ;
                tail = tail -> next ;
                carry = 1 ;
            }
            else 
            {
                tail -> next = new ListNode ( sum ) ;
                tail = tail -> next ;
                carry = 0 ;
            }
            ptr1 = ptr1 -> next ;
            ptr2 = ptr2 -> next ;
        }
        while ( ptr1 != nullptr )
        {
            sum = ptr1 -> val + carry ;
            if ( sum > 9 )
            {
                tail -> next = new ListNode ( sum % 10 ) ;
                tail = tail -> next ;
                carry = 1 ;
            }
            else
            {
                tail -> next = new ListNode ( sum ) ;
                tail = tail -> next ;
                carry = 0 ;
            }
            ptr1 = ptr1 -> next ;
        }
        while ( ptr2 != nullptr )
        {
            sum = ptr2 -> val + carry ;
            if ( sum > 9 )
            {
                tail -> next = new ListNode ( sum % 10 ) ;
                tail = tail -> next ;
                carry = 1 ;
            }
            else
            {
                tail -> next = new ListNode ( sum ) ;
                tail = tail -> next ;
                carry = 0 ;
            }
            ptr2 = ptr2 -> next ;
        }
        if ( carry == 1 )
            tail -> next = new ListNode ( 1 ) ;
        return head -> next ;
    }
};