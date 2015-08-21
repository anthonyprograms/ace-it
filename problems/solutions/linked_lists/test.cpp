#include "00ReverseLinkedList.soln.hpp"
#include "01RemoveDuplicates.soln.hpp"
#include <iostream>

int main()
{
    ListNode* head = new ListNode(1);
    head->appendToTail(2);
    head->appendToTail(3);
    head->appendToTail(4);
    head->appendToTail(4);
    head->appendToTail(5);
    head->appendToTail(3);
    head->appendToTail(4);

    std::cout << "Reverse List" << std::endl;
    head = reverseList(head);
    printList(head);
    std::cout << std::endl << "Remove Duplicates" << std::endl;
    removeDuplicatesHash(head);
    printList(head);

    return 0;
}
