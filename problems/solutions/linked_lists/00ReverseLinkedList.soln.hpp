#include "linked_list.h"

// Reverse a singly linked list
//
// Recursively
ListNode* reverseList(ListNode* head)
{
    if ( head == NULL || head->next == NULL )
    {
        return head;
    }
    ListNode* reverse = reverseList(head->next);
    reverse->appendToTail(head);
    head->next = NULL;
    return reverse;
}

// Iteratively - Fastest Way
/*
ListNode* reverseList(ListNode* head)
{
    if ( head == NULL || head->next == NULL )
    {
        return head;
    }
    ListNode* next = head->next;
    head->next = NULL;
    while ( next != NULL )
    {
        ListNode* nextUp = next->next;
        next->next = head;
        head = next;
        next = nextUp;
    }
    return head;
}
*/
