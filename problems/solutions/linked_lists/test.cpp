#include "00ReverseLinkedList.soln.hpp"
#include "01RemoveDuplicates.soln.hpp"
#include "02DeleteMiddle.soln.hpp"
#include "03FindKthElement.soln.hpp"
#include "04PartitionList.soln.hpp"
#include "05FindLoop.soln.hpp"
#include "06SumList.soln.hpp"
#include <iostream>

/*
 * This is temporary testing function until we have
 * a working testing program working
*/

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

    std::cout << "Partition" << std::endl;
    head = partition2(head, 3);
    printList(head);
    std::cout << std::endl;

    std::cout << "Find Kth" << std::endl;
    std::cout << findKth(head, 2)->data << std::endl << std::endl;

    std::cout << "Reverse List" << std::endl;
    head = reverseList(head);
    printList(head);
    std::cout << std::endl << "Remove Duplicates" << std::endl;
    removeDuplicatesHash(head);
    printList(head);
    deleteList(head);
    
    
    head = new ListNode(1);
    ListNode* loop = new ListNode(9);
    head->appendToTail(2);
    head->appendToTail(3);
    head->appendToTail(4);
    head->appendToTail(loop);
    head->appendToTail(4);
    head->appendToTail(5);
    head->appendToTail(3);
    head->appendToTail(4);
    head->appendToTail(loop);

    std::cout << std::endl << "Find the loop!" << std::endl;
    std::cout << findLoop(head)->data << std::endl << std::endl;

    ListNode* num1 = new ListNode(4);
    num1->appendToTail(1);
    num1->appendToTail(5);

    ListNode* num2 = new ListNode(6);
    num2->appendToTail(1);
    num2->appendToTail(2);

    std::cout << std::endl << "Sum List!" << std::endl;
    printList(sumListReverse(num1, num2));

    return 0;
}
