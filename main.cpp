

#include <bits/stdc++.h>
using namespace std;
#include "RubiksCubeBitboard.cpp"
int main() {
    RubiksCubeBitboard objectCube;

    objectCube.u();
//    objectCube.print();
    objectCube.d();
//    objectCube.print();
    objectCube.r();
//    objectCube.print();
    objectCube.l();
//    objectCube.print();
//    vector<GenericRubiksCube::MOVE> movesToshuffle = objectCube.randomShuffleCube(6);
//    for(auto move:movesToshuffle) cout << objectCube.getMove(move) << " ";
//    cout<<'\n';
    objectCube.print();
    objectCube.f();
    objectCube.print();
//    objectCube.b();
//    objectCube.print();
//    objectCube.u();
//    objectCube.print();



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
