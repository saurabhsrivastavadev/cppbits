#include "GroupingAlgos.h"

#include <map>

namespace cppbits {
    namespace algos {
        namespace grouping {

            namespace GroupAnagrams {

                using namespace std;

                static string sortLowercaseCharOnlyString(string str) {

                    char lowercaseArr[26] = { 0 };
                    for (char c : str) {
                        int value = c - 'a';
                        if (value > 25) return string();
                        lowercaseArr[value]++;
                    }
                    string result;
                    for (int i = 0; i < 26; i++) {
                        while (lowercaseArr[i]-- > 0) {
                            result += ((char)('a' + i));
                        }
                    }
                    return result;
                }

                vector<vector<string>> groupAnagrams(vector<string>& strs) {

                    vector<vector<string>> result;
                    map<string, vector<string>> anagramMap;

                    for (string str : strs) {
                        string sortedStr = sortLowercaseCharOnlyString(str);
                        anagramMap[sortedStr].push_back(str);
                    }

                    for (auto anagrams : anagramMap) {
                        result.push_back(anagrams.second);
                    }

                    return result;
                }
            }
        }
    }
}