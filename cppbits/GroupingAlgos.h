#pragma once

#include "common.h"

#include <vector>
#include <string>

namespace cppbits {
    namespace algos {
        namespace grouping {

            namespace GroupAnagrams {

                /// <summary>
                /// Provided a list of strings, group them into sub-lists of anagrams.
                /// An Anagram is a rearrangement of a string characters into another string.
                /// The strings provided must be all lowercase alphabets.
                /// </summary>
                /// <param name="strs"></param>
                /// <returns>List of list of anagrams grouped together</returns>
                DllExport std::vector<std::vector<std::string>>
                    groupAnagrams(std::vector<std::string>& strs);
            }
        }
    }
}
