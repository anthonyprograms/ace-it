#include "linked_list.h"
#include <iostream>

// Find the kth element of a linked list
// 0th element would be the last node
// before NULL
//
// Iterative Solution
//
ListNode* findKth(ListNode* head, int k)
{
    if ( head == NULL || k < 0 )
        return NULL;

    ListNode* runner = head;
    for ( int i = 0; i < k; i++ )
    {
        runner = runner->next;
        if ( runner == NULL )
            return NULL;
    }
    while ( runner->next != NULL )
    {
        runner = runner->next;
        head = head->next;
    }
    return head;
}

// Recursive Solution
// 
// This solution only works if we only want
// to print out the data, otherwise it does not
//
int findKthR(ListNode* head, int k)
{
    if ( head == NULL )
        return -1;

    int i = findKthR(head->next, k) + 1;
    if ( i == k )
        std::cout << head->data << std::endl;

    return i;
}

// Easy Solution
//
// Given length of list (doubt this will happen)
// use length - k - 1
//
ListNode* findKthWithLength(ListNode* head, int k, int length)
{
    if ( head == NULL || k < 0 || length < 0 )
        return NULL;

    for ( int i = 0; i < length - k - 1; i++ )
    {
        head = head->next;
        if ( head == NULL )
            return NULL;
    }
    return head;
}
