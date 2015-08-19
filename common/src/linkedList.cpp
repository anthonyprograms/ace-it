#include "linkedList.h" 

ListNode* deleteNode(ListNode* head, int d)
{
    ListNode* n = head;

    if (n->data == d)
    {
        ListNode* next_head = n->next;
        delete head;
        return next_head;
    }

    while (n->next != NULL)
    {
        if (n->next->data == d)
        {
            ListNode* new_next = n->next->next;
            n->next->next->prev = n->next->prev;
            delete n->next;
            n->next = new_next;
            return head;
        }
        n = n->next;
    }
    return head;
}

void printList(ListNode* head)
{
    while (head != NULL)
    {
        std::cout << head->data << std::endl;
        head = head->next;
    }
}

void deleteList(ListNode* head)
{
    while (head->next != NULL)
    {
        head = head->next;
        delete head->prev;
    }
    delete head;
}
