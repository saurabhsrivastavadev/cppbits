#pragma once

#include "common.h"

namespace cppbits {
    namespace algos {
        namespace linkedlist {

            namespace ReversePortions {

                struct Node {
                    int val;
                    Node* next;
                    Node() : val(0), next(nullptr) {}
                    Node(int x) : val(x), next(nullptr) {}
                    Node(int x, Node* next) : val(x), next(next) {}
                };

                /// <summary>
                /// Reverse every sub link list in the main list of specified portion size.
                /// e.g. 
                /// 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7
                /// and portionSize = 3, the result should be:
                /// 3 -> 2 -> 1 -> 6 -> 5 -> 4 -> 7
                /// Any remaining nodes after integer multiples of portion size should stay 
                /// in the same order.
                /// </summary>
                /// <param name="head">Linked List Head</param>
                /// <param name="portionSize">Portion size in the list to reverse</param>
                /// <returns>Final list with portions reversed</returns>
                DllExport Node* reverseLinkedListPortions(Node* head, int portionSize);
            }
        }
    }
}
