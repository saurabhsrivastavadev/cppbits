#include "MergeAlgos.h"

#include <map>

namespace cppbits {
    namespace algos {
        namespace merge {

            namespace MergeIntervals {

                using namespace std;

                vector<Interval> mergeIntervals(vector<Interval>& intervals) {

                    vector<Interval> result;

                    map<int, map<int, Interval>> sortedMap;
                    for (auto interval : intervals) {
                        sortedMap[interval.first][interval.second] = interval;
                    }

                    for (auto mapEntry : sortedMap) {
                        for (auto pair : mapEntry.second) {
                            auto interval = pair.second;
                            if (result.size() == 0) {
                                result.push_back(interval);
                            }
                            else {
                                auto& lastInterval = result.back();
                                if (lastInterval.second >= interval.first) {
                                    if (interval.second > lastInterval.second) {
                                        lastInterval.second = interval.second;
                                    }
                                }
                                else {
                                    result.push_back(interval);
                                }
                            }
                        }
                    }

                    return result;
                }
            }
        }
    }
}