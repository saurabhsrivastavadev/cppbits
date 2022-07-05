#include "NumberUtils.h"

#include <stdint.h>
#include <stdio.h>
#include <cstring>

namespace cppbits {
    namespace utils {
        namespace number {

            using namespace std;

            double floatToDouble(float f) {

				// https://www.log2base2.com/storage/how-float-values-are-stored-in-memory.html

#define F_SIGNIFICANT 0x007FFFFF
#define F_EXPONENT    0x7F800000
#define F_SIGN        0x80000000
#define D_SIGNIFICANT 0x000FFFFFFFFFFFFF
#define D_EXPONENT    0x7FF0000000000000
#define D_SIGN        0x8000000000000000

				float f = 10456.123456789;

				uint32_t f32 = 0;
				uint64_t d64 = 0;

				memcpy(&f32, &f, sizeof(uint32_t));

				printf("f %f = f32 0x%x\n", f, f32);

				// Significant remains the same
				// Exponent offset is adjusted from 127 to 1023
				// Sign bit remains the same
				d64 =
					(((uint64_t)(f32 & F_SIGNIFICANT)) << 29) |	                
					(((((uint64_t)(f32 & F_EXPONENT)) >> 23) + 896) << 52) |    
					(((uint64_t)(f32 & F_SIGN)) << 32);                         

				printf("f32 0x%x => d64 0x%lx\n", f32, d64);

				double d;
				memcpy(&d, &d64, sizeof(double));

				printf("f %f => d %lf\n", f, d);
            }
        }
    }
}