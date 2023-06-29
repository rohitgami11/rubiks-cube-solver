//
// Created by rohit on 29-06-2023.
//

#include "GenericRubiksCube.h"

class RubiksCube3dArray : public GenericRubiksCube{
private:
    void rotateFace(int index){
        char temp[3][3] = {};
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                temp[i][j] = cube[index][i][j];
            }
        }
        for(int i = 0; i < 3; i++){
            cube[index][0][i] = temp[2 - i][0];
        }
        for(int i = 0; i < 3; i++){
            cube[index][i][2] = temp[0][i];
        }
        for(int i = 0; i < 3; i++){
            cube[index][2][2 - i] = temp[i][2];
        }
        for(int i = 0; i < 3; i++){
            cube[index][2-i][0] = temp[2][2-i];
        }
    }
public:
    char cube[6][3][3]{};
    //constructor
    RubiksCube3dArray() {
        for(int i = 0; i < 6; i++){
            for(int j = 0; j < 3; j++){
                for(int k = 0; k < 3; k++){
                    cube[i][j][k] = getColorLetter(COLOR(i));
                }
            }
        }
    }

    COLOR getColor(FACE face, unsigned row, unsigned col) const override {
        char color = cube[int(face)][row][col];
        switch(color){
            case 'B':
                return COLOR::BLUE;
            case 'R':
                return COLOR::RED;
            case 'G':
                return COLOR::GREEN;
            case 'Y':
                return COLOR::YELLOW;
            case 'O':
                return COLOR::ORANGE;
            default:
                return COLOR::WHITE;
        }
    }

    bool isSolved() const override {
        for(int i = 0; i < 6; i++){
            for(int j = 0; j < 3; j++){
                for(int k = 0; k < 3; k++) {
                    if (cube[i][j][k] == getColorLetter(COLOR(i))) continue;
                    return false;
                }
            }
        }
        return true;
    }

    GenericRubiksCube &u() override{
        this->rotateFace(0);

        char temp[3] = {};
        for(int i = 0; i < 3; i++) temp[i] = cube[4][0][i];
        for(int i = 0; i < 3; i++) cube[4][0][i] = cube[1][0][i];
        for(int i = 0; i < 3; i++) cube[1][0][i] = cube[2][0][i];
        for(int i = 0; i < 3; i++) cube[2][0][i] = cube[3][0][i];
        for(int i = 0; i < 3; i++) cube[3][0][i] = temp[i];
        //*this may be helpful when chaining member function
        return *this;
    }

    GenericRubiksCube &uPrime() override{
        //such that three clockwise rotations are equivalent to one anticlockwise rotation
        this->u();
        this->u();
        this->u();
        //*this may be helpful when chaining member function
        return *this;
    }

    GenericRubiksCube &u2() override {
        //two clockwise rotation
        this->u();
        this->u();
        //*this may be helpful when chaining member function
        return *this;
    }

    GenericRubiksCube &l() override
    {
        this->rotateFace(1);

        char temp[3] = {};
        for(int i = 0; i < 3; i++) temp[i] = cube[0][i][0];
        for(int i = 0; i < 3; i++) cube[0][i][0] = cube[4][2-i][2];
        for(int i = 0; i < 3; i++) cube[4][2-i][2] = cube[5][i][0];
        for(int i = 0; i < 3; i++) cube[5][i][0] = cube[2][i][0];
        for(int i = 0; i < 3; i++) cube[2][i][0] = temp[i];
        //*this may be helpful when chaining member function
        return *this;
    }

    GenericRubiksCube &lPrime() override{
        //such that three clockwise rotations are equivalent to one anticlockwise rotation
        this->l();
        this->l();
        this->l();
        //*this may be helpful when chaining member function
        return *this;
    }

    GenericRubiksCube &l2() override{
        //two clockwise rotation
        this->l();
        this->l();
        //*this may be helpful when chaining member function
        return *this;
    }

    GenericRubiksCube &f() override{
        this->rotateFace(2);

        char temp[3] = {};
        for(int i = 0; i < 3; i++) temp[i] = cube[5][0][i];
        for(int i = 0; i < 3; i++) cube[5][0][i] = cube[3][2-i][0];
        for(int i = 0; i < 3; i++) cube[3][2-i][0] = cube[0][2][2-i];
        for(int i = 0; i < 3; i++) cube[0][2][2-i] = cube[1][i][2];
        for(int i = 0; i < 3; i++) cube[1][i][2] = temp[i];
        //*this may be helpful when chaining member function
        return *this;
    }

    GenericRubiksCube &fPrime() override{
        //such that three clockwise rotations are equivalent to one anticlockwise rotation
        this->f();
        this->f();
        this->f();
        //*this may be helpful when chaining member function
        return *this;
    }

    GenericRubiksCube &f2() override{
        //two clockwise rotations
        this->f();
        this->f();
        //*this may be helpful when chaining member function
        return *this;
    }

    GenericRubiksCube &r() override{
        this->rotateFace(3);

        char temp[3] = {};
        for(int i = 0; i < 3; i++) temp[i] = cube[0][i][2];
        for(int i = 0; i < 3; i++) cube[0][i][2] = cube[2][i][2];
        for(int i = 0; i < 3; i++) cube[2][i][2] = cube[5][i][2];
        for(int i = 0; i < 3; i++) cube[5][i][2] = cube[4][2-i][0];
        for(int i = 0; i < 3; i++) cube[4][2-i][2] = temp[i];
        //*this may be helpful when chaining member function
        return *this;
    }

    GenericRubiksCube &rPrime() override{
        //such that three clockwise rotations are equivalent to one anticlockwise rotation
        this->r();
        this->r();
        this->r();
        //*this may be helpful when chaining member function
        return *this;
    }

    GenericRubiksCube &r2() override{
        //two clockwise rotation
        this->r();
        this->r();
        //*this may be helpful when chaining member function
        return *this;
    }

    GenericRubiksCube &b() override{
        this->rotateFace(4);

        char temp[3] = {};
        for(int i = 0; i < 3; i++) temp[i] = cube[0][0][i];
        for(int i = 0; i < 3; i++) cube[0][0][i] = cube[3][i][2];
        for(int i = 0; i < 3; i++) cube[3][i][2] = cube[5][2][2-i];
        for(int i = 0; i < 3; i++) cube[5][2][2-i] = cube[1][2-i][0];
        for(int i = 0; i < 3; i++) cube[1][2-i][0] = temp[i];
        //*this may be helpful when chaining member function
        return *this;
    }

    GenericRubiksCube &bPrime() override{
        //such that three clockwise rotations are equivalent to one anticlockwise rotation
        this->b();
        this->b();
        this->b();
        //*this may be helpful when chaining member function
        return *this;
    }

    GenericRubiksCube &b2() override{
        //two clockwise rotation
        this->b();
        this->b();
        //*this may be helpful when chaining member function
        return *this;
    }

    GenericRubiksCube &d() override{
        this->rotateFace(5);

        char temp[3] = {};
        for(int i = 0; i < 3; i++) temp[i] = cube[2][2][i];
        for(int i = 0; i < 3; i++) cube[2][2][i] = cube[1][2][i];
        for(int i = 0; i < 3; i++) cube[1][2][i] = cube[4][2][i];
        for(int i = 0; i < 3; i++) cube[4][2][i] = cube[3][2][i];
        for(int i = 0; i < 3; i++) cube[3][2][i] = temp[i];
        //*this may be helpful when chaining member function
        return *this;
    }

    GenericRubiksCube &dPrime() override{
        //such that three clockwise rotations are equivalent to one anticlockwise rotation
        this->d();
        this->d();
        this->d();
        //*this may be helpful when chaining member function
        return *this;
    }

    GenericRubiksCube &d2() override{
        //two clockwise rotation
        this->d();
        this->d();
        //*this may be helpful when chaining member function
        return *this;
    }

    bool operator==(const RubiksCube3dArray &r1) const {
        for(int i = 0; i < 6; i++){
            for(int j = 0; j < 3; j++){
                for(int k = 0; k < 3; k++){
                    if(r1.cube[i][j][k] != cube[i][j][k]) return false;
                }
            }
        }
        return true;
    }

    RubiksCube3dArray &operator=(const RubiksCube3dArray &r1) {
        for(int i = 0; i < 6; i++){
            for(int j = 0; j < 3; j++){
                for(int k = 0; k < 3; k++){
                    cube[i][j][k] = r1.cube[i][j][k];
                }
            }
        }
        return *this;
    }
};
// It overloads the function call operator operator() to calculate the hash value for a given RubiksCube3dArray object.
struct  Hash3d {
    size_t operator()(const RubiksCube3dArray &r1) const {
        string str = "";
        for(int i = 0; i < 6; i++){
            for(int j = 0; j < 3; j++){
                for(int k = 0; k < 3; k++){
                    str += r1.cube[i][j][k];
                }
            }
        }
        return hash<string>()(str);
    }
};
