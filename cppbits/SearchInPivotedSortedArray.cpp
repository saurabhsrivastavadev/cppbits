#include "SearchAlgos.h"

#include <vector>

namespace cppbits {
    namespace algos {
        namespace search {

            using namespace std;

            static int searchPivotIndex(const vector<int>& nums, int start, int end) {

                if (start >= end || nums[start] <= nums[end]) return 0;

                int middle = (start + end) / 2;
                if (nums[middle] > nums[(size_t)middle + 1]) return middle + 1;

                if (nums[middle] < nums[start]) return searchPivotIndex(nums, start, middle);
                return searchPivotIndex(nums, middle, end);
            }

            static int binarySearch(const vector<int>& nums, int target, int start, int end) {

                int middle = (start + end) / 2;

                if (start > end) return -1;
                if (start == end) return (nums[start] == target) ? start : -1;
                if (nums[start] == target) return start;
                if (nums[end] == target) return end;
                if (nums[middle] == target) return middle;

                int left = binarySearch(nums, target, start, middle);
                if (left >= 0) return left;

                int right = binarySearch(nums, target, middle + 1, end);
                if (right >= 0) return right;

                return -1;
            }

            int searchInPivotedSortedArray(const vector<int>& nums, int target) {

                // find rotation pivot point
                int pivotIndex = searchPivotIndex(nums, 0, (int)nums.size() - 1);

                int targetAt = -1;

                // binary search in portion left of pivot point
                if (pivotIndex > 0) {
                    targetAt = binarySearch(nums, target, 0, pivotIndex - 1);
                }

                // binary search in portion right of pivot point
                if (targetAt < 0) {
                    targetAt = binarySearch(nums, target, pivotIndex, (int)nums.size() - 1);
                }

                return targetAt;
            }
        }
    }
}