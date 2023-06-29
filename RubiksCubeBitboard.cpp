//
// Created by rohit on 29-06-2023.
//

#include "GenericRubiksCube.h"

class RubiksCubeBitboard : public GenericRubiksCube{
private:
    int arr[3][3] = {{0, 1, 2},
                     {7, 8, 3},
                     {6, 5, 4}};
    uint64_t one_8 = (1 << 8) - 1, one_24 = (1 << 24) - 1;
    uint64_t solved_face_config[6];
    void rotateFace(int ind) {
        uint64_t temp  = bitboard[ind];
        bitboard[ind] = (temp << 16)|(temp >> 48);
    }

    int get5bitCorner(string corner) {
        int ret = 0;
        string actual_str;
        for (auto c: corner) {
            if (c != 'W' && c != 'Y') continue;
            actual_str.push_back(c);
            if (c == 'Y') {
                ret |= (1 << 2);
            }
        }

        for (auto c: corner) {
            if (c != 'R' && c != 'O') continue;
            if (c == 'O') {
                ret |= (1 << 1);
            }
        }

        for (auto c: corner) {
            if (c != 'B' && c != 'G') continue;
            if (c == 'G') {
                ret |= (1 << 0);
            }
        }

        if (corner[1] == actual_str[0]) {
            ret |= (1 << 3);
        } else if (corner[2] == actual_str[0]) {
            ret |= (1 << 4);
        }
        return ret;
    }

    void rotateSide(int s1,int s1_1,int s1_2,int s1_3,int s2,int s2_1,int s2_2,int s2_3){
        uint64_t clr1 = (bitboard[s2] & (one_8<<(8*s2_1)))>>(8*s2_1);
        uint64_t clr2 = (bitboard[s2] & (one_8<<(8*s2_2)))>>(8*s2_2);
        uint64_t clr3 = (bitboard[s2] & (one_8<<(8*s2_3)))>>(8*s2_3);

        bitboard[s1] = (bitboard[s1] & ~(one_8<<(8<<s1_1))) | (clr1<<(8*s1_1));
        bitboard[s1] = (bitboard[s1] & ~(one_8<<(8<<s1_2))) | (clr2<<(8*s1_2));
        bitboard[s1] = (bitboard[s1] & ~(one_8<<(8<<s1_3))) | (clr3<<(8*s1_3));
    }

public:
    uint64_t bitboard[6];

    RubiksCubeBitboard() {
        for(int i = 0; i < 6; i++){
            uint64_t temp = 1<<i ;
            for(int j = 0; j < 8; j++){
                bitboard[i] |= (temp<<(8*j));
            }
            solved_face_config[i] = bitboard[i];
        }
    }

    COLOR getColor(FACE face, unsigned row, unsigned col) const override {
        int ind = arr[row][col];
        if (ind == 8) return (COLOR)((int) face);

        uint64_t side = bitboard[(int) face];
        uint64_t color = (side >> (8 * ind)) & one_8;

        int bit_pos = 0;
        while (color != 0) {
            color = color >> 1;
            bit_pos++;
        }
        return (COLOR)(bit_pos - 1);
    }

    bool isSolved() const override{
        for(int i = 0; i < 6; i++){
            if(bitboard[i] != solved_face_config[i]) return false;
        }
        return true;
    }

    RubiksCubeBitboard &u() override{
        this->rotateFace(0);

        uint64_t temp = bitboard[2] & one_24;
        bitboard[2] = (bitboard[2] & ~one_24) | (bitboard[3] & one_24);
        bitboard[3] = (bitboard[3] & ~one_24) | (bitboard[4] & one_24);
        bitboard[4] = (bitboard[4] & ~one_24) | (bitboard[1] & one_24);
        bitboard[1] = (bitboard[1] & ~one_24) | temp;
        //this will help to chain member function if required
        return *this;
    };

    RubiksCubeBitboard &uPrime() override{
        //three clockwise rotation leads to one clockwise rotation
        this->u();
        this->u();
        this->u();
        //this will help to chain member function if required
        return *this;
    };

    RubiksCubeBitboard &u2() override{
        //two clockwise rotation
        this->u();
        this->u();
        //this will help to chain member function if required
        return *this;
    };

    RubiksCubeBitboard &l() override{
        this->rotateFace(1);
        uint64_t clr1 = (bitboard[2] & (one_8 << (8*0))) >> (8*0);
        uint64_t clr2 = (bitboard[2] & (one_8 << (8*7))) >> (8*7);
        uint64_t clr3 = (bitboard[2] & (one_8 << (8*6))) >> (8*6);

        this->rotateSide(2,0,7,6,0,0,7,6);
        this->rotateSide(0,0,7,6,4,4,3,2);
        this->rotateSide(4,4,3,2,5,0,7,6);

        bitboard[5] = (bitboard[5] & ~(one_8<<(8*0))) | (clr1<<(8*0));
        bitboard[5] = (bitboard[5] & ~(one_8<<(8*7))) | (clr2<<(8*7));
        bitboard[5] = (bitboard[5] & ~(one_8<<(8*6))) | (clr3<<(8*6));
        //this will help to chain member function if required
        return *this;
    };

    RubiksCubeBitboard &lPrime() override{
        //three clockwise rotation leads to one clockwise rotation
        this->l();
        this->l();
        this->l();
        //this will help to chain member function if required
        return *this;
    };

    RubiksCubeBitboard &l2() override{
        //two clockwise rotation
        this->l();
        this->l();
        //this will help to chain member function if required
        return *this;
    };

    RubiksCubeBitboard &f() override{
        this->rotateFace(2);
        uint64_t clr1 = (bitboard[0] & (one_8<<(8*6)))>>(8*6);
        uint64_t clr2 = (bitboard[0] & (one_8<<(8*5)))>>(8*5);
        uint64_t clr3 = (bitboard[0] & (one_8<<(8*4)))>>(8*4);

        this->rotateSide(0,6,5,4,1,4,3,2);
        this->rotateSide(1,4,3,2,5,2,1,0);
        this->rotateSide(5,2,1,0,3,0,7,6);

        bitboard[3] = (bitboard[3] & ~(one_8<<(8*0))) | (clr1<<(8*0));
        bitboard[3] = (bitboard[3] & ~(one_8<<(8*7))) | (clr2<<(8*7));
        bitboard[3] = (bitboard[3] & ~(one_8<<(8*6))) | (clr3<<(8*6));
        //this will help to chain member function if required
        return *this;
    };

    RubiksCubeBitboard &fPrime() override{
        //three clockwise rotation leads to one clockwise rotation
        this->f();
        this->f();
        this->f();
        //this will help to chain member function if required
        return *this;
    };

    RubiksCubeBitboard &f2() override{
        //two clockwise rotation
        this->f();
        this->f();
        //this will help to chain member function if required
        return *this;
    };

    RubiksCubeBitboard &r() override{
        this->rotateFace(2);
        uint64_t clr1 = (bitboard[0] & (one_8<<(8*4)))>>(8*4);
        uint64_t clr2 = (bitboard[0] & (one_8<<(8*3)))>>(8*3);
        uint64_t clr3 = (bitboard[0] & (one_8<<(8*2)))>>(8*2);

        this->rotateSide(0,4,3,2,2,4,3,2);
        this->rotateSide(2,4,3,2,5,4,3,2);
        this->rotateSide(5,4,3,2,4,0,7,6);

        bitboard[4] = (bitboard[4] & ~(one_8<<(8*0))) | (clr1<<(8*0));
        bitboard[4] = (bitboard[4] & ~(one_8<<(8*7))) | (clr2<<(8*7));
        bitboard[4] = (bitboard[4] & ~(one_8<<(8*6))) | (clr3<<(8*6));
        //this will help to chain member function if required
        return *this;
    };

    RubiksCubeBitboard &rPrime() override{
        //three clockwise rotation leads to one clockwise rotation
        this->r();
        this->r();
        this->r();
        //this will help to chain member function if required
        return *this;
    };

    RubiksCubeBitboard &r2() override{
        //two clockwise rotation
        this->r();
        this->r();
        //this will help to chain member function if required
        return *this;
    };

    RubiksCubeBitboard &b() override{
        this->rotateFace(4);
        uint64_t clr1 = (bitboard[0] & (one_8<<(8*2)))>>(8*2);
        uint64_t clr2 = (bitboard[0] & (one_8<<(8*1)))>>(8*1);
        uint64_t clr3 = (bitboard[0] & (one_8<<(8*0)))>>(8*0);

        this->rotateSide(0,2,1,0,3,4,3,2);
        this->rotateSide(3,4,3,2,5,6,5,4);
        this->rotateSide(5,6,5,4,1,0,7,6);

        bitboard[1] = (bitboard[1] & ~(one_8<<(8*0))) | (clr1<<(8*0));
        bitboard[1] = (bitboard[1] & ~(one_8<<(8*7))) | (clr2<<(8*7));
        bitboard[1] = (bitboard[1] & ~(one_8<<(8*6))) | (clr3<<(8*6));
        //this will help to chain member function if required
        return *this;
    };

    RubiksCubeBitboard &bPrime() override{
        //three clockwise rotation leads to one clockwise rotation
        this->b();
        this->b();
        this->b();
        //this will help to chain member function if required
        return *this;
    };

    RubiksCubeBitboard &b2() override{
        //two clockwise rotation
        this->b();
        this->b();
        //this will help to chain member function if required
        return *this;
    };

    RubiksCubeBitboard &d() override{
        this->rotateFace(5);
        uint64_t clr1 = (bitboard[2] & (one_8<<(8*6)))>>(8*6);
        uint64_t clr2 = (bitboard[2] & (one_8<<(8*5)))>>(8*5);
        uint64_t clr3 = (bitboard[2] & (one_8<<(8*4)))>>(8*4);

        this->rotateSide(2,6,5,4,1,6,5,4);
        this->rotateSide(1,6,5,4,4,6,5,4);
        this->rotateSide(4,6,5,4,3,6,5,4);

        bitboard[3] = (bitboard[3] & ~(one_8<<(8*6))) | (clr1<<(8*6));
        bitboard[3] = (bitboard[3] & ~(one_8<<(8*5))) | (clr2<<(8*5));
        bitboard[3] = (bitboard[3] & ~(one_8<<(8*4))) | (clr3<<(8*4));
        //this will help to chain member function if required
        return *this;
    };

    RubiksCubeBitboard &dPrime() override{
        //three clockwise rotation leads to one clockwise rotation
        this->d();
        this->d();
        this->d();
        //this will help to chain member function if required
        return *this;
    };

    RubiksCubeBitboard &d2() override{
        //two clockwise rotation
        this->d();
        this->d();
        //this will help to chain member function if required
        return *this;
    };

    bool operator==(const RubiksCubeBitboard &r1) const{
        for(int i = 0; i < 6; i++){
            if(bitboard[i] != r1.bitboard[i]) return false;
        }
        return true;
    }

    RubiksCubeBitboard &operator==(const RubiksCubeBitboard &r1){
        for(int i = 0; i < 6; i++){
            bitboard[i] = r1.bitboard[i];
        }
        return *this;
    }

    uint64_t getCorners(){
        uint64_t ret = 0;

        string top_front_right = "";
        top_front_right += getColorLetter(getColor(FACE::UP,2,2));
        top_front_right += getColorLetter(getColor(FACE::FRONT,0,2));
        top_front_right += getColorLetter(getColor(FACE::RIGHT,0,0));

        string top_front_left = "";
        top_front_left += getColorLetter(getColor(FACE::UP,2,0));
        top_front_left += getColorLetter(getColor(FACE::FRONT,0,0));
        top_front_left += getColorLetter(getColor(FACE::LEFT,0,2));

        string top_back_right = "";
        top_back_right += getColorLetter(getColor(FACE::UP,0,2));
        top_back_right += getColorLetter(getColor(FACE::BACK,0,0));
        top_back_right += getColorLetter(getColor(FACE::RIGHT,0,2));

        string top_back_left = "";
        top_back_left += getColorLetter(getColor(FACE::UP,0,0));
        top_back_left += getColorLetter(getColor(FACE::BACK,0,2));
        top_back_left += getColorLetter(getColor(FACE::LEFT,0,0));

        string bottom_front_right = "";
        bottom_front_right += getColorLetter(getColor(FACE::DOWN, 0, 2));
        bottom_front_right += getColorLetter(getColor(FACE::FRONT, 2, 2));
        bottom_front_right += getColorLetter(getColor(FACE::RIGHT, 2, 0));

        string bottom_front_left = "";
        bottom_front_left += getColorLetter(getColor(FACE::DOWN, 0, 0));
        bottom_front_left += getColorLetter(getColor(FACE::FRONT, 2, 0));
        bottom_front_left += getColorLetter(getColor(FACE::LEFT, 2, 2));

        string bottom_back_right = "";
        bottom_back_right += getColorLetter(getColor(FACE::DOWN, 2, 2));
        bottom_back_right += getColorLetter(getColor(FACE::BACK, 2, 0));
        bottom_back_right += getColorLetter(getColor(FACE::RIGHT, 2, 2));

        string bottom_back_left = "";
        bottom_back_left += getColorLetter(getColor(FACE::DOWN, 2, 0));
        bottom_back_left += getColorLetter(getColor(FACE::BACK, 2, 2));
        bottom_back_left += getColorLetter(getColor(FACE::LEFT, 2, 0));

        ret |= get5bitCorner(top_front_right);
        ret = ret<<5;

        ret |= get5bitCorner(top_front_left);
        ret = ret<<5;

        ret |= get5bitCorner(top_back_right);
        ret = ret<<5;

        ret |= get5bitCorner(top_back_left);
        ret = ret<<5;

        ret |= get5bitCorner(bottom_front_right);
        ret = ret<<5;

        ret |= get5bitCorner(bottom_front_left);
        ret = ret<<5;

        ret |= get5bitCorner(bottom_back_right);
        ret = ret<<5;

        ret |= get5bitCorner(bottom_back_left);
        ret = ret<<5;

        return ret;
    }

};

struct HashBitboard{
    size_t operator()(const RubiksCubeBitboard &r1) const {
        uint64_t final_hash = r1.bitboard[0];
        for(int i = 1; i < 6; i++){
            final_hash ^= r1.bitboard[i];
        }
        return (size_t) final_hash;
    }
};