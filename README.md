# 🧠 Rubik’s Cube Solver

A modular and performant **C++ application** for modeling and solving the Rubik’s Cube using advanced algorithmic approaches and optimized cube representations.

---

## ✨ Key Features

🔸 **Multiple Cube Representations**

* 📦 `3D Array` – Traditional layer-based modeling
* 📏 `1D Array` – Linear, memory-efficient layout
* 💡 `Bitboard` – Compact binary encoding for fast bitwise operations

🔸 **Solving Algorithms**

* 🔍 `DFS` – Depth-First Search
* 🔎 `BFS` – Breadth-First Search
* 🔁 `IDDFS` – Iterative Deepening DFS

🔸 **Core Capabilities**

* 🎲 Random Cube Shuffling
* 🟰 Cube State Comparison and Assignment
* 🔐 Hashing Support for Efficient Search
* 🔁 Full Move Set: Standard and Inverse Moves

---

## 🚀 Getting Started

### ✅ Prerequisites

* C++14-compliant compiler (`g++`, `clang++`, or MSVC)
* [CMake](https://cmake.org/download/) ≥ 3.25
* [Ninja](https://ninja-build.org/) (recommended for fast builds)

### 🛠️ Build Instructions

```bash
# Clone the repo
git clone <repo-url>
cd rubiks-cube-solver

# Create and enter build directory
mkdir build && cd build

# Configure with CMake
cmake .. -G Ninja

# Build the executable
ninja
```

🔹 On success, the binary will be created as:

* `RubiksCubeSolve.exe` on **Windows**
* `RubiksCubeSolve` on **Linux/macOS**

---

## ▶️ Running the Solver

From the `build/` directory:

```bash
./RubiksCubeSolve
```

🧪 The main demo includes:

* Cube initialization and printing
* Random shuffling
* Solving via DFS, BFS, and IDDFS
* Displaying solution sequences

---

## 📁 Project Structure

```
rubiks-cube-solver/
├── main.cpp                      # Application entry point
├── GenericRubiksCube.*          # Abstract base class
├── RubiksCube3dArray.cpp        # 3D array cube implementation
├── RubiksCube1dArray.cpp        # 1D array cube implementation
├── RubiksCubeBitboard.cpp       # Bitboard cube implementation
├── DFSSolver.h                  # DFS algorithm
├── BFSSolver.h                  # BFS algorithm
└── IDDFSSolver.h                # IDDFS algorithm
```

---

## 🤝 Contributing

We welcome contributions and ideas from the community!
Feel free to:

* Fork and submit pull requests
* Open issues for enhancements or bug reports

> Please open an issue before submitting major changes to coordinate design direction.

---

## 📚 Acknowledgements

Inspired by foundational algorithmic techniques in Rubik’s Cube solving, including state space search, graph traversal, and compact modeling via bitboards.

---

## 📌 License

MIT License — feel free to use, modify, and distribute.

---
