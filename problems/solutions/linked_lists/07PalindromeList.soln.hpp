#include "linked_list.h"
#include <stack>

// Given a linked list, determine if
// the linked list is a palindrome
//
// Here we can use a stack to store all the 
// values up to the half of the list. We 
// can do this by using a slow and fast 
// pointer until we reached the end. Then
// we can compare the stack to the last 
// half of the list.
//
bool isPalindrome(ListNode* head)
{
    ListNode* slow = head;
    ListNode* fast = head;
    std::stack<int> stack = std::stack<int>();

    while ( fast != NULL && fast->next != NULL )
    {
        stack.push(slow->data);
        slow = slow->next;
        fast = fast->next->next;
    }

    // if fast != NULL, the list contains
    // an odd number of items, skip the middle
    if ( fast != NULL )
        slow = slow->next;

    while ( slow != NULL )
    {
        if ( slow->data != stack.top() )
            return false;
        slow = slow->next;
        stack.pop();
    }
    return true;
}
