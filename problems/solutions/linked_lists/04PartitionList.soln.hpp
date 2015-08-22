#include "linked_list.h"

// Partition a linked to have values lower than x
// in the first half, and greater than or equal
// values in the second half. Order does not matter
//
// Here we can just keep track of two different lists:
// lower and higher. We can merge them at the end after
// creating the two lists
//
ListNode* partition(ListNode* head, int val)
{
    if ( head == NULL )
        return NULL;

    ListNode* lower = NULL;
    ListNode* lowerStart = NULL;
    ListNode* higher = NULL;
    ListNode* higherStart = NULL;
    while ( head != NULL )
    {
        if ( head->data < val )
        {
            if ( lowerStart == NULL )
            {
                lowerStart = head;
                lower = head;
            }
            else
            {
                lower->next = head;
                lower = head;
            }
        }
        else
        {
            if ( higherStart == NULL )
            {
                higherStart = head;
                higher = head;
            }
            else
            {
                higher->next = head;
                higher = head;
            }
        }
        head = head->next;
    }

    higher->next = NULL;
    if ( lowerStart == NULL )
        return higherStart;

    // Merge
    lower->next = higherStart;
    return lowerStart;
}

// Another solution shorter solution is to only
// add at the beginning of our lower and higher lists
// However, we will need to iterate through the lower list 
// to append the higher list. We can do this with our
// appendToTail function
//
ListNode* partition2(ListNode* head, int val)
{
    if ( head == NULL )
        return NULL;

    ListNode* lowerStart = NULL;
    ListNode* higherStart = NULL;

    while ( head != NULL )
    {
        ListNode* next = head->next;
        if ( head->data < val )
        {
            head->next = lowerStart;
            lowerStart = head;
        }
        else
        {
            head->next = higherStart;
            higherStart = head;
        }
        head = next;
    }

    if ( lowerStart == NULL )
        return higherStart;

    lowerStart->appendToTail(higherStart);
    return lowerStart;
}


