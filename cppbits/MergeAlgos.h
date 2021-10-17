#pragma once

#include <vector>

namespace cppbits {
    namespace algos {
        namespace merge {

            namespace MergedSortedLinkedLists {

                struct Node {
                    int val;
                    Node* next;
                    Node() : val(0), next(nullptr) {}
                    Node(int x) : val(x), next(nullptr) {}
                    Node(int x, Node* next) : val(x), next(next) {}
                };

                /// <summary>
                /// Merge the provided sorted linked lists, and return the new merged list.
                /// </summary>
                /// <param name="lists">Vector of sorted linked lists head pointers.</param>
                /// <returns>Merged linked list in sorted order.</returns>
                Node* mergeSortedLists(std::vector<Node*>& lists);
            }
        }
    }
}
