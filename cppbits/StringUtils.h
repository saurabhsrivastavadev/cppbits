#pragma once

#include "common.h"

#include <vector>
#include <string>

namespace cppbits {
    namespace utils {
        namespace str {

            /// <summary>
            /// Print the elements of a vector separated with single space.
            /// </summary>
            /// <typeparam name="T"></typeparam>
            /// <param name="vec"></param>
            /// <returns></returns>
            template <typename T>
            CPPBITS_API std::string printVector(std::vector<T> vec);

            /// <summary>
            /// Trim the leading and trailing whitespaces from a string.
            /// </summary>
            /// <param name="str"></param>
            /// <returns></returns>
            CPPBITS_API std::string trimLeft(std::string str);
            CPPBITS_API std::string trimRight(std::string str);
            CPPBITS_API std::string trim(std::string str);
        }
    }
}
