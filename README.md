# Rubiks Cube Solver

A C++ application for modeling and solving the Rubik's Cube using multiple algorithmic approaches and cube representations.

## Features

- **Multiple Cube Representations**: 
  - 3D Array
  - 1D Array
  - Bitboard

- **Solving Algorithms**:
  - **DFS (Depth-First Search) Solver**
  - **BFS (Breadth-First Search) Solver**
  - **IDDFS (Iterative Deepening Depth-First Search) Solver**

- **Random Shuffle**: Randomly scrambles the cube for testing solver robustness.
- **Equality and Assignment**: Compare and assign cube states.
- **Hashing**: Efficient hashing for cube states, useful for search algorithms.
- **Move Operations**: Supports all standard Rubik's Cube moves and their inverses.

## Getting Started

### Prerequisites

- C++14 compatible compiler (e.g., GCC, MinGW, MSVC)
- CMake 3.25 or higher
- Ninja (recommended for fast builds)

### Build Instructions

1. **Clone the repository:**
   ```sh
   git clone <repo-url>
   cd rubiks-cube-solver-master
   ```

2. **Configure and build with CMake:**
   ```sh
   mkdir build
   cd build
   cmake .. -G Ninja
   ninja
   ```

   The executable will be generated as `RubicksCubeSolve.exe` (on Windows) or `RubicksCubeSolve` (on Linux/Mac).

### Running

Run the executable from the build directory:
```sh
./RubicksCubeSolve
```

The main function demonstrates:
- Creating and printing cubes
- Shuffling and solving using DFS, BFS, and IDDFS
- Printing the solution moves

## File Structure

- `main.cpp` - Entry point, demonstrates usage and testing of solvers.
- `GenericRubiksCube.*` - Abstract base class for cube models.
- `RubiksCube3dArray.cpp` - 3D array cube implementation.
- `RubiksCube1dArray.cpp` - 1D array cube implementation.
- `RubiksCubeBitboard.cpp` - Bitboard cube implementation.
- `DFSSolver.h`, `BFSSolver.h`, `IDDFSSolver.h` - Solver algorithm headers.

## Contributing

Pull requests are welcome! For major changes, please open an issue first to discuss what you would like to change.

## License

[MIT](LICENSE) (Add a LICENSE file if you want to specify the license.)

## Acknowledgements

- Inspired by classic Rubik's Cube solving algorithms and data structures.
