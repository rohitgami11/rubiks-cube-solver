

#include <bits/stdc++.h>
using namespace std;
#include "RubiksCube1dArray.cpp"
int main() {
    RubiksCube1dArray objectCube3d;

    objectCube3d.u();
    objectCube3d.print();
    objectCube3d.d();
    objectCube3d.print();
    objectCube3d.r();
    objectCube3d.print();
//    objectCube3d.l();
//    objectCube3d.print();
    objectCube3d.f();
    objectCube3d.print();
    objectCube3d.u();
    objectCube3d.print();



//    if(objectCube3d.isSolved()) cout<<"Solved\n";
//    else cout<<"Not Solved\n";
//    vector<GenericRubiksCube::MOVE> movesToshuffle = objectCube3d.randomShuffleCube(3);
//    for(auto move:movesToshuffle) cout << objectCube3d.getMove(move) << " ";
//    cout<<'\n';
//    objectCube3d.print();
//    if(objectCube3d.isSolved()) cout<<"Solved\n";
//    else cout<<"Not Solved\n";
    return 0;
}
