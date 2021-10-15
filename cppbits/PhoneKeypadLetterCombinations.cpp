#include <vector>
#include <string>
#include <unordered_map>

module StringAlgos;

namespace cppbits {
    namespace algos {
        namespace str {

            namespace PhoneKeypadLetterCombinations {

                using namespace std;

                class PhoneKeypadLetterCombinations {
                public:
                    vector<string> letterCombinations(string digits) {

                        vector<string> result;

                        for (int idx = (int)digits.size() - 1; idx >= 0; idx--) {
                            result = join(numMap_[digits[idx]], result);
                        }

                        return result;
                    }

                private:
                    vector<string> join(string str, vector<string> vec) {

                        vector<string> res;
                        for (char c : str) {
                            for (string s : vec) {
                                res.push_back(c + s);
                            }
                            if (vec.empty()) {
                                res.push_back(string(1, c));
                            }
                        }
                        return res;
                    }

                private:
                    unordered_map<char, string> numMap_ = {
                        {'2', "abc"}, {'3', "def"}, {'4', "ghi"},
                        {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
                        {'8', "tuv"}, {'9', "wxyz"}
                    };
                };

                vector<string> getAllLetterCombinations(string digits) {

                    PhoneKeypadLetterCombinations pk;
                    return pk.letterCombinations(digits);
                }
            }
        }
    }
}
