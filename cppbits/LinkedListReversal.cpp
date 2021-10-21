#include "LinkedListAlgos.h"

#include <vector>

namespace cppbits {
    namespace algos {
        namespace linkedlist {

            namespace ReversePortions {

                using namespace std;

                Node* reverseLinkedListPortions(Node* head, int portionSize) {

                    // Compute list size
                    int size = 0;
                    Node* node = head;
                    while (node != NULL) {
                        size++;
                        node = node->next;
                    }

                    // Store linked list node pointers in a vector for indexed access
                    vector<Node*> nodeList(size);
                    node = head;
                    int t = 0;
                    while (node != NULL) {
                        nodeList[t++] = node;
                        node = node->next;
                    }

                    // Reverse Portions
                    for (size_t i = 0; i < size / portionSize; i++) {

                        for (size_t j = 1; j < portionSize; j++) {
                            // Point all non-first nodes in each portion to previous node.
                            nodeList[(i * portionSize) + j]->next = nodeList[(i * portionSize) + j - 1];
                        }

                        // First node in each portion points to first node in next portion.
                        // Or to first node in unreversed portion of list at end.
                        size_t firstNodeInNextPortionIdx = ((i + 2) * portionSize) - 1;
                        size_t nonReversedPortionAtEndIdx = (i + 1) * portionSize;
                        nodeList[(i * portionSize)]->next =
                            firstNodeInNextPortionIdx < size ? 
                                nodeList[firstNodeInNextPortionIdx] :
                                (nonReversedPortionAtEndIdx < size ? nodeList[nonReversedPortionAtEndIdx] : NULL);
                    }

                    return nodeList[portionSize - 1 < size ? portionSize - 1 : 0];
                }

                static void reverseSubList(Node* subListHead, int portionSize,
                    Node** reversedHead, Node** reversedTail) {

                    Node* current = subListHead;
                    Node* previous = nullptr;
                    int count = 0, available = 0;

                    // Look for < k available nodes scenario first 
                    *reversedHead = subListHead;
                    *reversedTail = subListHead;
                    if (*reversedHead == nullptr || *reversedTail == nullptr) return;
                    while (current != nullptr && ++available < portionSize) {
                        current = current->next;
                        *reversedTail = current;
                    }
                    if (available < portionSize) return;
                    Node* nodeAfterSubList = (*reversedTail)->next;

                    // Available nodes > k 
                    current = subListHead;
                    while (count++ < portionSize && current != nullptr) {

                        Node* next = current->next;
                        if (previous == nullptr) {
                            *reversedTail = current;
                        }
                        else {
                            current->next = previous;
                        }

                        previous = current;
                        current = next;
                    }
                    *reversedHead = previous;
                    (*reversedTail)->next = nodeAfterSubList;
                }

                Node* reverseLinkedListPortionsInO1Space(Node* head, int portionSize) {

                    Node* reversedHead = nullptr;
                    Node* reversedTail = nullptr;

                    reverseSubList(head, portionSize, &reversedHead, &reversedTail);
                    Node* result = reversedHead;

                    while (reversedTail != nullptr && reversedTail->next != nullptr) {

                        Node* lastTail = reversedTail;
                        reverseSubList(reversedTail->next, portionSize, &reversedHead, &reversedTail);
                        lastTail->next = reversedHead;
                    }

                    return result;
                }
            }
        }
    }
}
