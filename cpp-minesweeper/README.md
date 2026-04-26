# C++ Minesweeper

A C++ Minesweeper project with two playable versions:

- `minesweeper_console`: the original console game
- `minesweeper_sfml`: a graphical second version with menu and difficulty selection

## Version 2 Highlights

- Beginner, intermediate, and expert difficulty modes
- SFML graphical interface with a menu screen
- Mouse controls for reveal and flag actions
- First-move safety
- Recursive reveal for empty areas
- Win and loss banners
- Timer and remaining-mine counter
- Project-local image assets for tiles, mines, and flags

## Project Structure

```text
cpp-minesweeper/
|- assets/
|  \- images/
|- include/
|- src/
|- CMakeLists.txt
\- README.md
```

## Build

### Console version with g++

```bash
g++ -std=c++17 -Wall -Wextra -Wpedantic -I include src/main.cpp src/Board.cpp src/Game.cpp -o minesweeper_console
```

### CMake

```bash
cmake -S . -B build
cmake --build build
```

The CMake project always builds `minesweeper_console`.
If SFML 2.5 or newer is available on your machine, it also builds `minesweeper_sfml`.

If SFML is not installed, CMake falls back to the console target only.

## Run

### Console

```bash
./minesweeper_console
```

### SFML GUI

```bash
./build/minesweeper_sfml
```

On Windows with multi-config generators, the GUI executable may be inside a folder such as `build/Debug/`.

## Controls

### Console

- `r row col`: reveal a cell
- `f row col`: place or remove a flag
- `n`: start a new game
- `h`: show help
- `q`: quit

### SFML GUI

- Left click: reveal a cell
- Right click: place or remove a flag
- `Reset` button: restart the current round
- `Menu` button or `Esc`: return to the difficulty menu

## Assets

The GUI version includes local image assets in `assets/images/`:

- `tile_hidden.png`
- `tile_revealed.png`
- `icon_mine.png`
- `icon_flag.png`

## Notes

- The game logic is shared between the console and GUI versions.
- The GUI uses project-local art assets and a code-defined bitmap label renderer, so it does not depend on an external font file.

## Next Ideas

- Add chord-click behavior for revealed numbered cells
- Add a best-time record per difficulty
- Add sound effects and a polished victory screen
- Package the SFML version for easier distribution
