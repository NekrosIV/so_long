# so_long

## Description

`so_long` is a 2D tile-based game written in C with MiniLibX. The player must collect all collectibles (`C`) and then reach the exit (`E`) while moving through a map described in a `.ber` file.

This repository contains a mandatory game (`so_long`) and a bonus codebase (`so_long_bonus`) with extra gameplay mechanics.

## Features

### Mandatory

- `.ber` map parsing with explicit error handling.
- Map validation:
  - rectangular shape,
  - closed by walls (`1`),
  - allowed symbols only (`0`, `1`, `C`, `E`, `P`),
  - exactly one player, exactly one exit, at least one collectible.
- Reachability check using flood fill (all collectibles and the exit must be reachable).
- Real-time rendering with MiniLibX and XPM sprites.
- Player movement with arrow keys.
- Collision rules (cannot walk through walls, exit usable only when all collectibles are collected).
- Move counter printed in the shell.
- Clean exit on `ESC` and window close.

### Bonus (code present in `bonus/`)

- Enemy tiles (`M`) and loss condition when the player is caught.
- Animated movement/death logic.
- On-screen move counter.
- Additional path validation logic (BFS-based checks).

## How It Works

1. `main` validates arguments, parses the map, initializes MLX, creates the window, and loads sprites.
2. The parser checks map format and gameplay constraints before the game starts.
3. The loop redraws the map continuously and handles input events.
4. On each move, the game updates player position, collectible count, and move count.
5. When all collectibles are collected and the exit is reached, the game prints a win message and exits cleanly.

## Installation / Build

### Dependencies

- `cc` compiler
- `make`
- X11 development libraries (for MiniLibX Linux build)

The repository already includes:

- `libft/`
- `mlx/`

### Build mandatory target

```bash
make
```

This creates `./so_long`.

### Build bonus target

```bash
make bonus
```

Note: in the current repository state, the bonus target fails to compile with `-Werror` because of an unused variable in `bonus/anime_pacman.c`.

## Usage

Run the game with a `.ber` map:

```bash
./so_long map/little.ber
```

Controls (mandatory build):

- `Up`, `Down`, `Left`, `Right`: move
- `ESC`: quit

## Example

Command:

```bash
./so_long map/little.ber
```

Observed shell output in this repository environment:

```text
Moves: 1
...
you won in 32 moves
```

If you run mandatory mode with a map containing `M` (monster tile), parsing fails with:

```text
Error
Invalid symbol in map
```

## Project Structure

```text
.
├── include/        # Headers (mandatory + bonus)
├── src/            # Mandatory game implementation
├── bonus/          # Bonus game implementation
├── map/            # .ber maps
├── img/            # XPM textures/sprites
├── libft/          # Local libft
├── mlx/            # MiniLibX source
└── Makefile
```

## What I Learned

- Building a full parsing and validation pipeline for file-driven game state.
- Managing an event loop with MiniLibX (window lifecycle, input hooks, render loop).
- Implementing gameplay constraints directly in C data structures.
- Using flood fill / BFS to verify path feasibility before runtime.
- Improving resource management and clean shutdown in graphical C programs.

## Resources

- 42 subject: `So_Long.pdf`
- MiniLibX Linux source and API: `mlx/`
- X11 key symbols (`X11/keysym.h`) used for input handling