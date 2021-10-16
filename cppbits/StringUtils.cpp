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
                return trim(res);
            }

            // Need to explicitly list all supported types for linking
            template __declspec(dllexport) string printVector(vector<string> vec);
            template __declspec(dllexport) string printVector(vector<int> vec);

            string trimLeft(string str) {
                size_t strStart = str.find_first_not_of(" \n\t\r");
                return strStart == string::npos ? "" : str.substr(strStart);
            }
            string trimRight(string str) {
                size_t strEnd = str.find_last_not_of(" \n\t\r");
                return strEnd == string::npos ? "" : str.substr(0, strEnd + 1);
            }
            string trim(string str) {
                return trimLeft(trimRight(str));
            }
        }
    }
}