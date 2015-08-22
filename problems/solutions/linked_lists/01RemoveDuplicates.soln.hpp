#include "linked_list.h"
#include <unordered_map>

// Remove all the duplicates from the linked list with/without using a buffer
// 
// Without using a temporary buffer - Slower Solution -> O(n^2)
//
void removeDuplicates(ListNode* head)
{
    if ( head == NULL )
        return;

    while ( head != NULL )
    {
        ListNode* checker = head;
        while ( checker->next != NULL )
        {
            if ( head->data == checker->next->data )
            {
                ListNode* toDelete = checker->next;
                checker->next = checker->next->next;
                delete toDelete;
                // Add if doubly linked list
                /*
                checker->next->prev = head;
               */
            }
            else
                checker = checker->next;
        }
        head = head->next;
    }
}

// With using a temporary buffer - Faster Solution -> O(n)
// Here we can use a unordered_map to keep track of the values
// that were reached, if we reach a key that has already been inserted
// we have a duplicate. The number inserted as a value is arbitrary
// as we only care about the key
//
void removeDuplicatesHash(ListNode* head)
{
    if ( head == NULL )
        return;
    
    std::unordered_map<int, int> hash_table = std::unordered_map<int, int>();
    hash_table.insert(std::pair<int,int>(head->data, 1));
    while ( head->next != NULL )
    {
        if ( hash_table.count(head->next->data) > 0 )
        {
            ListNode* toDelete = head->next;
            head->next = head->next->next;
            delete toDelete; 
            // if doubly linked list
            /* 
            head->next->prev = head->next;
            */
        }
        else
        {
            hash_table.insert(std::pair<int,int>(head->next->data, 1));
            head = head->next;
        }
    }
}
