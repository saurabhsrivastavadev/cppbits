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
            }
        }
    }
}
