#include "linked_list.h"

// Given access to the middle of a link list, delete it
//
// Here we can just grab the next node's data and 
// copy it over to the middle's data. Middle's next
// will then be set to next's next. Then we can
// just delete the next node
void deleteMiddle(ListNode* middle)
{
    if ( middle == NULL )
        return;

    ListNode* next = middle->next;
    middle->data = next->data;
    middle->next = next->next;
    // if doubly linked list
    /*
    middle->next->prev = middle;
    */
    delete next;
}
