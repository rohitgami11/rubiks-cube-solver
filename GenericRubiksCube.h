//
// Created by rohit on 26-06-2023.
//

#ifndef RUBICKSCUBESOLVE_GENERICRUBIKSCUBE_H
#define RUBICKSCUBESOLVE_GENERICRUBIKSCUBE_H

#include "bits/stdc++.h"

using namespace std;

/*
 * A base class for all Rubik's Cube Model.
 * There are various representation for Rubik's Cube.
 * Each one has its own special ways of definitions.
 * This class provides a shared functionality between all models.
 */

class GenericRubiksCube {
public:
    enum class FACE {
        UP,
        LEFT,
        FRONT,
        RIGHT,
        BACK,
        DOWN
    };

    enum class COLOR {
        WHITE,
        GREEN,
        RED,
        BLUE,
        ORANGE,
        YELLOW
    };

    enum class MOVE {
        L, LPRIME, L2,
        R, RPRIME, R2,
        U, UPRIME, U2,
        D, DPRIME, D2,
        F, FPRIME, F2,
        B, BPRIME, B2
    };

    //Returns the color of the cell at (row, col) in face(0-indexed).
    virtual COLOR getColor(FACE face, unsigned row, unsigned col) const = 0;

    //returns the first letter of the given COLOR
    static char getColorLetter(COLOR color);

    //returns true if the RubikCube is solved, otherwise returns false.
    virtual bool isSolved() const = 0;

    //return the move in string
    virtual string getMove(MOVE index);

    //print the Rubiks Cube in planer format
    void print() const;

    //Randomly shuffle the cube with 'times' moves and returns the moves performed.
    vector<MOVE> randomShuffleCube(unsigned int times);

    // Perform moves on the Rubiks Cube
    GenericRubiksCube &move(MOVE index);

    //Invert a move
    GenericRubiksCube &invert(MOVE index);

    /*
     * Rotational Moves on the Rubiks Cubes
     * F, F’, F2,
     * U, U’, U2,
     * L, L’, L2,
     * D, D’, D2,
     * R, R’, R2,
     * B, B’, B2
     */

    virtual GenericRubiksCube &f() = 0;

    virtual GenericRubiksCube &fPrime() = 0;

    virtual GenericRubiksCube &f2() = 0;

    virtual GenericRubiksCube &u() = 0;

    virtual GenericRubiksCube &uPrime() = 0;

    virtual GenericRubiksCube &u2() = 0;

    virtual GenericRubiksCube &l() = 0;

    virtual GenericRubiksCube &lPrime() = 0;

    virtual GenericRubiksCube &l2() = 0;

    virtual GenericRubiksCube &r() = 0;

    virtual GenericRubiksCube &d() = 0;

    virtual GenericRubiksCube &dPrime() = 0;

    virtual GenericRubiksCube &d2() = 0;

    virtual GenericRubiksCube &rPrime() = 0;

    virtual GenericRubiksCube &r2() = 0;

    virtual GenericRubiksCube &b() = 0;

    virtual GenericRubiksCube &bPrime() = 0;

    virtual GenericRubiksCube &b2() = 0;

    string getCornerColorString(uint8_t index) const;

    uint8_t getCornerIndex(uint8_t index) const;

    uint8_t getCornerOrientation(uint8_t index) const;
};


#endif //RUBICKSCUBESOLVE_GENERICRUBIKSCUBE_H
