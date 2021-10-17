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
            DllExport
            std::string printVector(std::vector<T> vec);

            /// <summary>
            /// Trim the leading and trailing whitespaces from a string.
            /// </summary>
            /// <param name="str"></param>
            /// <returns></returns>
            DllExport
            std::string trimLeft(std::string str);
            DllExport
            std::string trimRight(std::string str);
            DllExport
            std::string trim(std::string str);
        }
    }
}
