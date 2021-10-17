#include "MergeAlgos.h"

#include <map>

namespace cppbits {
    namespace algos {
        namespace merge {

            namespace MergedSortedLinkedLists {

                using namespace std;

                Node* mergeSortedLists(vector<Node*>& lists) {

                    Node* resultHead = NULL;
                    Node* lastNode = NULL;
                    Node* it = NULL;

                    map<int, int> valCount;

                    for (Node* node : lists) {

                        it = node;
                        while (it != NULL) {
                            valCount[it->val]++;
                            it = it->next;
                        }
                    }

                    for (auto valPair : valCount) {

                        int val = valPair.first;
                        int count = valPair.second;

                        while (count-- > 0) {

                            if (resultHead == NULL) {
                                resultHead = new Node(val);
                                lastNode = resultHead;
                            }
                            else {
                                Node* node = new Node(val);
                                lastNode->next = node;
                                lastNode = node;
                            }
                        }
                    }

                    return resultHead;
                }
            }
        }
    }
}