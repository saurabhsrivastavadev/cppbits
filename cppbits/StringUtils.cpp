#include "StringUtils.h"

#include <vector>
#include <string>
#include <unordered_map>

namespace cppbits {
    namespace utils {
        namespace str {

            using namespace std;

            template <typename T>
            string printVector(vector<T> vec) {
                
                string res = "";
                for (T el : vec) {
                    res += el + " ";
                }
                return res;
            }

            // Need to explicitly list all supported types for linking
            template __declspec(dllexport) string printVector(vector<string> vec);
            template __declspec(dllexport) string printVector(vector<int> vec);
        }
    }
}