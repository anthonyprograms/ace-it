#include "linked_list.h"

// Given two numbers represented linked lists
// e.g. 415 as 4 -> 1 -> 5
// and  612 as 6 -> 1 -> 2
// Add the two numbers together to return
// 1027 1 - > 0 - > 2 -> 7
//
// Here we can add the sum of the linked lists
// then placing them into a new list by using 
// integer division to our advantage. 
//
ListNode* sumList(ListNode* head1, ListNode* head2)
{
    int sum1 = 0;
    int sum2 = 0;
    int multiplier = 10;
    int total;
    int mod;

    if ( head1 == NULL )
        return head2;
    if ( head2 == NULL )
        return NULL;

    while ( head1 != NULL )
    {
        sum1 = (sum1 * multiplier) + head1->data;
        head1 = head1->next;
    }
    while ( head2 != NULL )
    {
        sum2 = (sum2 * multiplier) + head2->data;
        head2 = head2->next;
    }
    total = sum1 + sum2;

    mod = 1;
    while ( mod * 10 <= total )
        mod *= 10;

    ListNode* return_sum = new ListNode(total / mod);
    total -= total / mod * mod;
    while ( mod != 1 )
    {
        mod /= 10;
        return_sum->appendToTail(total / mod);
        total -= total / mod * mod;
    }
    return return_sum;
}

// Repeat the above problem if the numbers were
// stored in reverse order
//
// Here we can find the total sum then
// add the trailing digits by modding that
// digit by a power of 10 that is 1 larger 
// digit than the one we are appending. Each
// step we can increase the number we mod by
// and subtracting off the trailing digit
//
ListNode* sumListReverse(ListNode* head1, ListNode* head2)
{
    int sum1 = 0;
    int sum2 = 0;
    int multiplier = 1;
    int mod = 10;
    int total;
    
    while ( head1 != NULL )
    {
        sum1 += head1->data * multiplier;
        head1 = head1->next;
        multiplier *= 10;
    }
    multiplier = 1;
    while ( head2 != NULL )
    {
        sum2 += head2->data * multiplier;
        head2 = head2->next;
        multiplier *= 10;
    }
    total = sum1 + sum2;

    mod = 10;
    ListNode* return_sum = new ListNode(total % mod);
    total -= total % mod;
    while ( mod <= total )
    {
        mod *= 10;
        return_sum->appendToTail((total % mod) / (mod / 10));
    }
    return return_sum;
}
