#pragma once

#include "common.h"

#include <vector>
#include <string>

namespace cppbits {
    namespace utils {
        namespace vectorutils {

            /// <summary>
            /// Compare 2 vectors ignoring the order of elements.
            /// The default == comparison of vectors considers order as well.
            /// </summary>
            /// <param name="v1"></param>
            /// <param name="v2"></param>
            /// <returns>true if both vectors have same elements in any order.</returns>
            template <typename T>
            CPPBITS_API bool compareVectorIgnoreOrder(std::vector<T> v1, std::vector<T> v2);
        }
    }
}
