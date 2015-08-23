#include "linked_list.h"

// Given a circular linked list, find the node
// in which the loop starts. 
// e.g. Given A -> B -> C -> D -> E -> C
// returns C
//
// Here we can use some math to solve the algorithm
// We will use two pointers here to help us solve the
// problem. 1 slow pointer moving at 1 step and 1
// fast pointer moving at 2 steps.
// Let's assume we have a loop of length k
// After k steps, the slow pointer should have
// ended up at the beginning of the loop. The fast
// pointer will now be k steps INTO the loop. This makes
// fast pointer LOOP_SIZE - k steps behind the slow pointer.
// From there we can see that it will take the fast 
// pointer LOOP_SIZE - k steps before colliding with
// the slow pointer. Once met, they will be k steps
// away from the loop start. Now we can place slow at
// the head of linked list again and move each pointer
// 1 step until they collide, giving us the start of 
// the loop.
//
ListNode* findLoop(ListNode* head)
{
    ListNode* slow = head;
    ListNode* fast = head;

    while ( fast != NULL && fast->next != NULL )
    {
        slow = slow->next;
        fast = fast->next->next;

        if ( slow == fast )
            break;
    }

    // There is no loop
    if ( fast == NULL || fast->next == NULL )
        return NULL;

    slow = head;
    while ( slow != fast )
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}


// Another solution and much faster/shorter
// solution is to make each visited
// node's ->next equal to NULL then looping
// until we hit a node whose next is equal to NULL.
// However, this solution would destroy the linked list
// and the assumption is that we are given a linked
// list with a loop. e.g. Circular loop
//
ListNode* findLoop2(ListNode* head)
{
    if ( head == NULL )
        return NULL;
    
    ListNode* prev;
    while ( head->next != NULL )
    {
        prev = head;
        head = head->next;
        prev->next = NULL;
    }
    return head;
}
