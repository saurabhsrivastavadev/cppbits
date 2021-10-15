#include <vector>
#include <string>
#include <unordered_map>

export module StringAlgos;

using namespace std;

namespace cppbits {
    namespace stringalgos {
        
        namespace PhoneKeypadLetterCombinations {

            /// <summary>
            /// For specified digits typed on a phone keypad, 
            /// get all possible letter combinations.
            /// Assume the standard digit to alphabet mapping on the keypad,
            /// 2=abc 3=def 4=ghi 5=jkl 6=mno 7=pqrs 8=tuv 9=wxyz
            /// e.g. digits="23" will result in below possible strings:
            /// {"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"}
            /// </summary>
            /// <param name="digits">String contains typed digits on keypad</param>
            /// <returns>
            /// Vector containing all possible strings based on typed digits
            /// </returns>
            export vector<string> getAllLetterCombinations(string digits);
        }
    }
}
