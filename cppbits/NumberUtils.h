#pragma once

#include "common.h"

namespace cppbits {
    namespace utils {
        namespace number {

            /// <summary>
            /// A demo how float to double typecast might happen below the surface.
            /// Just for understand float and double memory layout. 
            /// </summary>
            /// <param name="f"></param>
            /// <returns></returns>
            CPPBITS_API double floatToDouble(float f);
        }
    }
}
