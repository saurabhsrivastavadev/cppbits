#pragma once 

#include <vector>
#include <string>
#include <unordered_map>

namespace cppbits {
    namespace utils {
        namespace str {

            template <typename T>
            __declspec(dllexport)
            std::string printVector(std::vector<T> vec);
        }
    }
}
