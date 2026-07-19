*This project has been created as part of the 42 curriculum by diomende and jomaia.*

# cub3D

A first-person raycasting engine written in C, inspired by *Wolfenstein 3D* — the game credited with defining the FPS genre. cub3D reads a text-based scene description (`.cub`) and renders a real-time, walkable 3D view of the maze it describes, using [MinilibX](https://github.com/42Paris/minilibx-linux) for windowing and pixel drawing.

## Description

The goal of cub3D is to explore the mathematics behind raycasting: for every column of the screen, a ray is cast from the player's position into the map, its intersection with the nearest wall is computed with a DDA (Digital Differential Analysis) algorithm, and the resulting distance is used to determine how tall that wall slice should be drawn — the closer the wall, the taller the slice. Doing this once per column, 60+ times a second, produces the illusion of a continuous 3D space rendered from a purely 2D grid.

Beyond the renderer itself, the project also required building a strict parser for the custom `.cub` scene format: it validates textures, colors, and map layout (including checking that the map is fully enclosed by walls) before a single ray is ever cast.

### Features

**Mandatory**
- Real-time raycasting engine using MinilibX, rendered through image buffers (not pixel-by-pixel `mlx_pixel_put`) for performance
- Distinct wall textures depending on which cardinal side is hit (North / South / East / West)
- Configurable floor and ceiling colors
- Smooth window management (focus changes, minimizing, clean shutdown on `ESC` or the window's close button)
- Full `.cub` file parser: texture paths, floor/ceiling RGB colors, and the ASCII map, with explicit `Error\n` + message on any malformed input (unclosed map, invalid characters, missing identifiers, out-of-range colors, etc.)

**Bonus**
- Wall collision so the player can no longer walk through `1` tiles (`Source/Exec/movement.c`)

## Controls

| Key(s) | Action |
| --- | --- |
| `W` `A` `S` `D` | Move forward / left / back / right |
| `←` `→` | Rotate the camera left / right |
| `ESC` | Quit cleanly |
| Window close button | Quit cleanly |

## Instructions

### Requirements
- Linux with an X11 server (the project links against MinilibX, `Xext`, and `X11`)
- `cc`, `make`

### Build

```bash
git clone https://github.com/jlmaia1999/Cube3D.git
cd Cube3D
make
```

`make` first builds the vendored `libft` (`Resources/Libft`) and `MinilibX` (`Resources/Minilibx`) via their own Makefiles, then compiles and links `cub3D`.

### Run

```bash
./cub3D Maps/<map_name>.cub
```

The program takes exactly one argument: the path to a valid `.cub` scene file.

### Makefile rules

| Rule | Description |
| --- | --- |
| `make` / `make all` | Builds libft, MinilibX, and the `cub3D` binary |
| `make clean` | Removes object files |
| `make fclean` | Removes object files and the binary |
| `make re` | Full rebuild |

## The `.cub` file format

A scene file describes textures, colors, and the maze itself:

```
NO ./North.xpm
SO ./South.xpm
WE ./West.xpm
EA ./East.xpm

F 220,100,0
C 225,30,0

111111111111111111
100000000000000001
101100001110000001
1001000000000000001
1100000111010101N0111
111111111111111111
```

- `NO` / `SO` / `WE` / `EA` — path to the texture used for that wall orientation
- `F` / `C` — floor / ceiling color as `R,G,B` (0–255 each)
- The map is made of `0` (floor), `1` (wall), and one spawn character `N`/`S`/`E`/`W` (player start position + facing direction)
- The map must always come last in the file and must be fully enclosed by walls, or parsing fails with an explicit error

## Project structure

```
Cube3D/
├── Includes/            # Header files
├── Maps/                # Sample .cub scene files
├── Resources/
│   ├── Libft/            # 42 libft, vendored
│   └── Minilibx/         # MinilibX, vendored
├── Source/
│   ├── Parsing/          # .cub file parsing & validation
│   │   ├── main.c
│   │   ├── map_parsing.c
│   │   ├── map_reader.c
│   │   ├── map_extractor.c
│   │   ├── txs_extractor.c
│   │   ├── txs_parsing.c
│   │   └── parsing_error.c
│   ├── Exec/              # Rendering & game loop
│   │   ├── draw.c
│   │   ├── ray.c
│   │   ├── textures.c
│   │   ├── background.c
│   │   ├── movement.c
│   │   └── mini_map.c
│   │   └── utils.c
│   └── cub3d.c            # Entry point / game state initialization
├── *.xpm                  # Wall textures (N/S/E/W, two variants each)
└── Makefile
```

The split between `Parsing/` (everything that happens before the window ever opens: reading the file, extracting textures/colors, validating the map) and `Exec/` (everything that happens once the game loop is running: raycasting, drawing, movement, the minimap) keeps scene validation fully separate from rendering.

## Technical choices

- Compiled with `-O3 -march=native -flto -ftree-vectorize -funroll-loops -ffast-math`, CAUSE ITS FASTER.
- MinilibX and libft are built as sub-projects via their own Makefiles (`$(MAKE) -C ...`) rather than requiring a manual build step.

## Resources

- [Lodev's Raycasting tutorial](https://lodev.org/cgtutor/raycasting.html)
- [42 MinilibX documentation](https://github.com/42Paris/minilibx-linux)
- 42 cub3D subject
