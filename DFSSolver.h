//
// Created by rohit on 30-06-2023.
//
#include<bits/stdc++.h>
#include "GenericRubiksCube.h"
#ifndef RUBICKSCUBESOLVE_DFSSOLVER_H
#define RUBICKSCUBESOLVE_DFSSOLVER_H

template<typename T, typename H>
class DFSSolver {
private:

    vector<GenericRubiksCube::MOVE> moves;
    int max_search_depth;

//    DFS code to find the solution (helper function)
    bool dfs(int dep) {
        if (rubiksCube.isSolved()) return true;
        if (dep > max_search_depth) return false;
        for (int i = 0; i < 18; i++) {
            rubiksCube.move(GenericRubiksCube::MOVE(i));
            moves.push_back(GenericRubiksCube::MOVE(i));
            if (dfs(dep + 1)) return true;
            moves.pop_back();
            rubiksCube.invert(GenericRubiksCube::MOVE(i));
        }
        return false;
    }

public:
    T rubiksCube;

    DFSSolver(T _rubiksCube, int _max_search_depth = 8) {
        rubiksCube = _rubiksCube;
        max_search_depth = _max_search_depth;
    }

    vector<GenericRubiksCube::MOVE> solve() {
        dfs(1);
        return moves;
    }

};

#endif //RUBICKSCUBESOLVE_DFSSOLVER_H
