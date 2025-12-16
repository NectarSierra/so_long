# SO_LONG

**so_long** is a 2D maze-based game developed as part of the 42 curriculum.  
The project is built using **MiniLibX**, a lightweight graphical library provided by 42, and focuses on fundamental concepts such as window management, event handling, textures, and basic game logic.

## Overview

The goal of the game is to navigate through a maze, collect all collectibles, and reach the exit while avoiding obstacles.  
The player must carefully plan their movement to complete the map successfully.

![Gameplay](readme_srcs/gameplay.png?raw=true)

## Features

- 2D top-down maze gameplay
- Keyboard-based player movement
- Collectibles and exit system
- Map validation and error handling
- Custom-made graphical assets
- Smooth rendering using MiniLibX

## Bonus Features

In addition to the mandatory requirements, the project includes a **pathfinding visualization system**.  
This feature displays the path used to validate map solvability and helps visualize how the player can reach all collectibles and the exit.

![Pathfinding](readme_srcs/pathfinding.png?raw=true)

The pathfinding system is compiled and available **only in the bonus version**.

## Compilation

To compile the mandatory version:

```bash
make
```

To compile the bonus version:

```bash
make bonus
```

## Usage

Run the game by providing a map file as an argument:

```bash
./so_long path_to_map.ber
```

Several example maps are available in the following directory:

`srcs/maps/`

Custom maps must follow the .ber format and project specifications.

## Assets

All assets used in this project were entirely drawn by hand.
The visual style was designed to be coherent and distinctive while remaining readable during gameplay.
