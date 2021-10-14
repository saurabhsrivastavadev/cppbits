#pragma once 
#include "pch.h"

#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>

export module PhoneKeypadLetterCombinations;

namespace cppbits {
    namespace algos {

        using namespace std;

        export class PhoneKeypadLetterCombinations {
        public:
            vector<string> letterCombinations(string digits) {

                vector<string> result;

                for (int idx = (int)digits.size() - 1; idx >= 0; idx--) {
                    result = join(numMap_[digits[idx]], result);
                }

                return result;
            }

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
    }
}
