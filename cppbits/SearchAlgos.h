#pragma once

#include "common.h"

#include <vector>

namespace cppbits {
    namespace algos {
        namespace search {

            /// <summary>
            /// Search in a sorted integer array for a target.
            /// The array might be pivoted at any index.
            /// e.g. 0,1,2,3,4,5 pivoted at index 3 => 3,4,5,0,1,2
            /// </summary>
            /// <param name="nums"></param>
            /// <param name="target"></param>
            /// <returns></returns>
            DllExport int searchInPivotedSortedArray(const std::vector<int>& nums, int target);
        }
    }
}
