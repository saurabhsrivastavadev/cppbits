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
                CPPBITS_API std::vector<std::vector<std::string>>
                    groupAnagrams(std::vector<std::string>& strs);
            }

            namespace GroupStringIntoIpAddresses {

                /// <summary>
                /// Group specified string into IP Addresses that can be created without 
                /// reordering or replicating any characters from the string.
                /// Basically just by inserting 3 .[dot]s into the string to create an 
                /// IP address.
                /// </summary>
                /// <param name="str"></param>
                /// <returns>List of all possible IP addresses</returns>
                CPPBITS_API std::vector<std::string> groupIpAddresses(std::string str);
            }
        }
    }
}
