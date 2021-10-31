#include "VectorUtils.h"

#include <vector>
#include <string>
#include <unordered_map>

namespace cppbits {
    namespace utils {
        namespace vectorutils {

            using namespace std;

            template <typename T>
            bool compareVectorIgnoreOrder(vector<T> v1, vector<T> v2) {

                unordered_map<T, int> elementCount;
                for (auto e1 : v1) {
                    elementCount[e1]++;
                }
                for (auto e2 : v2) {
                    elementCount[e2]--;
                }
                for (auto ec : elementCount) {
                    if (ec.second > 0) return false;
                }
                return true;
            }
        }
    }
}
