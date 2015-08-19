#include "linkedList.h"

// Reverse a singly linked list
//
// Recursively
ListNode* reverseList(ListNode* head)
{
    if ( head->next == NULL )
    {
        return head;
    }
    ListNode* reverse = reverseList(head->next);
    reverse->appendToTail(head);
    head->next = NULL;
    return reverse;
}
