#include "GroupingAlgos.h"

namespace cppbits {
    namespace algos {
        namespace grouping {

            namespace GroupStringIntoIpAddresses {

                using namespace std;

                vector<string> groupIpAddresses(string str) {

                    vector<string> result;
                    if (str.size() > 12 || str.size() < 4) return result;

                    // b1/b2/b3/b4 represent the number of digits in each part of IP address
                    // e.g. 1.21.32.200 -> b1=1 / b2=2 / b3=2 / b4=3
                    for (size_t b1 = 1; b1 <= 3; b1++) {
                        for (size_t b2 = 1; b2 <= 3; b2++) {
                            for (size_t b3 = 1; b3 <= 3; b3++) {
                                for (size_t b4 = 1; b4 <= 3; b4++) {

                                    // Sum of digits in each part same as input str size
                                    if (b1 + b2 + b3 + b4 == (int)str.size()) {

                                        string b1str = str.substr(0, b1);
                                        string b2str = str.substr(b1, b2);
                                        string b3str = str.substr(b1 + b2, b3);
                                        string b4str = str.substr(b1 + b2 + b3, b4);

                                        int b1int = atoi(b1str.c_str());
                                        int b2int = atoi(b2str.c_str());
                                        int b3int = atoi(b3str.c_str());
                                        int b4int = atoi(b4str.c_str());

                                        // If first char of a part is '0' then that part can only be 0
                                        // i.e. 01.01.01.01 is not valid, must be 1.1.1.1
                                        if ((b1str[0] != '0' || b1str.size() == 1) && b1int <= 255 &&
                                            (b2str[0] != '0' || b2str.size() == 1) && b2int <= 255 &&
                                            (b3str[0] != '0' || b3str.size() == 1) && b3int <= 255 &&
                                            (b4str[0] != '0' || b4str.size() == 1) && b4int <= 255) {

                                            result.push_back(b1str + "." + b2str + "." + b3str + "." + b4str);
                                        }
                                    }
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