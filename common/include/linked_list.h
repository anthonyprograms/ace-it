#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

// Doubly linked list functions are commented out
// Uncomment them if you want to assume all questions
// use a doubly linked list

// Linked list struct
struct ListNode {
    ListNode* next;
    // ListNode* prev;
    int data;

    // Constructs the linked list with the given start node
    ListNode(int d)
    {
        data = d;
        next = NULL;
        // prev = NULL;
    }

    // Appends a new node with the data d
    void appendToTail(int d) 
    { 
        ListNode* end = new ListNode(d);
        ListNode* n = this;
        while (n->next != NULL)
        {
            n = n->next;
        }
        n->next = end;
        // end->prev = n;
    }

    // Appends an entire node to the linked list
    void appendToTail(ListNode* node)
    {
        ListNode* n = this;
        while (n->next != NULL)
        {
            n = n->next;
        }
        n->next = node;
        // node->prev = n;
    }
};

// Deletes the node with specified data d
ListNode* deleteNode(ListNode* head, int d);

// Prints the data stored at each node in order
void printList(ListNode* head);

// Deletes the entire linked list and its nodes
void deleteList(ListNode* head);

#endif
