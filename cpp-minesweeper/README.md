# C++ Minesweeper

A small Minesweeper project written in C++ with a clean structure that is easy to extend into a graphical version later.

## Current Version

This first version is a playable console game with:

- A 9x9 board and 10 mines
- First-move safety
- Recursive reveal for empty areas
- Flag placement and removal
- Win and loss detection
- A simple command-based interface

## Project Structure

```text
cpp-minesweeper/
├─ include/
├─ src/
├─ CMakeLists.txt
└─ README.md
```

## Build

### With CMake

```bash
cmake -S . -B build
cmake --build build
```

### With g++

```bash
g++ -std=c++17 -Wall -Wextra -Wpedantic -I include src/main.cpp src/Board.cpp src/Game.cpp -o minesweeper
```

## Run

```bash
./build/minesweeper
```

On Windows with Visual Studio generators, the executable may also appear in a configuration directory such as `build/Debug/`.
If you build with `g++`, run `./minesweeper` instead.

## Controls

- `r row col`: reveal a cell
- `f row col`: place or remove a flag
- `n`: start a new game
- `h`: show help
- `q`: quit

Example:

```text
r 3 4
f 1 7
```

## Next Ideas

- Add beginner, intermediate, and expert difficulty modes
- Build an SFML graphical interface
- Add a timer and best-score tracking
- Support mouse input in the GUI version
