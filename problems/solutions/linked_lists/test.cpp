#include "00ReverseLinkedList.soln.hpp"

int main()
{
    ListNode* head = new ListNode(1);
    head->appendToTail(2);
    head->appendToTail(3);
    head->appendToTail(4);
    head->appendToTail(5);

    head = reverseList(head);
    printList(head);

    return 0;
}
