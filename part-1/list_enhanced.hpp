
#ifndef __list_enhanced__
#define __list_enhanced__

#include "list.hpp"
#include <iostream>

template <typename T>
void list_delete_after(Node<T> *node)
{
    // If there is no node to delete give an error
    // !node checks if the node exists, !node-> next checks if the node after the given node exists
    if (!node || !node->next) {
        std::cerr << "Cannot delete this!" << std::endl;
    }

    // Get N.next
    std::unique_ptr<Node<T>> temporaryNode = std::move(node->next);

    // Set the next pointer of the given node to skip the next node. (Set Q.next to N.next)
    node->next = std::move(temporaryNode->next);

}

#endif // __list_enhanced__