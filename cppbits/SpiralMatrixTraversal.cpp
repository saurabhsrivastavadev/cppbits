#include "TraversalAlgos.h"

#include <vector>

namespace cppbits {
    namespace algos {
        namespace traversal {

            using namespace std;

            class SpiralMatrixTraversal {
            public:
                vector<int> spiralOrder(vector<vector<int>>& matrix) {

                    _maxRowIdx = (int)matrix.size() - 1;
                    _maxColumnIdx = (int)matrix[0].size() - 1;

                    _current = { 0,0 };

                    // Mark first node as traversed
                    // Each matrix value is constrained to -100 <= val <= 100
                    // Use this fact and make any traversed node value > 100 by adding 300
                    matrix[_current.first][_current.second] += 300;

                    vector<int> result;
                    do {
                        result.push_back(matrix[_current.first][_current.second] - 300);
                    } while (0 == makeMove(matrix));

                    return result;
                }

            private:
                int _maxRowIdx;
                int _maxColumnIdx;

                enum class Move {
                    INVALID, RIGHT, LEFT, UP, DOWN, NONE
                };

                Move _lastMove = Move::INVALID;
                pair<int, int> _current;

            private:
                int makeMove(vector<vector<int>>& matrix) {

                    auto nextMove = getNextMove(matrix);
                    switch (nextMove) {
                    case Move::RIGHT:
                        _current.second++;
                        break;
                    case Move::LEFT:
                        _current.second--;
                        break;
                    case Move::DOWN:
                        _current.first++;
                        break;
                    case Move::UP:
                        _current.first--;
                        break;
                    case Move::INVALID:
                    case Move::NONE:
                        return -1;
                    }

                    // Mark current node as traversed
                    // Each matrix value is constrained to -100 <= val <= 100
                    // Use this fact and make any traversed node value > 100 by adding 300
                    matrix[_current.first][_current.second] += 300;
                    _lastMove = nextMove;

                    return 0;
                }

                Move getNextMove(vector<vector<int>>& matrix) {

                    bool canMoveRight = (_current.second < _maxColumnIdx&&
                        matrix[_current.first][(size_t)_current.second + 1] <= 100);
                    bool canMoveDown = (_current.first < _maxRowIdx&&
                        matrix[(int)((size_t)_current.first + 1)][_current.second] <= 100);
                    bool canMoveLeft = (_current.second > 0 &&
                        matrix[_current.first][(size_t)_current.second - 1] <= 100);
                    bool canMoveUp = (_current.first > 0 &&
                        matrix[(size_t)_current.first - 1][_current.second] <= 100);

                    switch (_lastMove) {
                    case Move::NONE:
                    case Move::INVALID:
                    case Move::RIGHT:
                        return canMoveRight ? Move::RIGHT : (canMoveDown ? Move::DOWN : Move::NONE);
                    case Move::LEFT:
                        return canMoveLeft ? Move::LEFT : (canMoveUp ? Move::UP : Move::NONE);
                    case Move::UP:
                        return canMoveUp ? Move::UP : (canMoveRight ? Move::RIGHT : Move::NONE);
                    case Move::DOWN:
                        return canMoveDown ? Move::DOWN : (canMoveLeft ? Move::LEFT : Move::NONE);
                    }

                    return Move::NONE;
                }
            };
        }
    }
}