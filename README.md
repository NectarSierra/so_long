# SO_LONG

**so_long** is a 2D maze-based game developed as part of the 42 curriculum.  
The project is built using **MiniLibX**, a lightweight graphical library provided by 42, and focuses on fundamental concepts such as window management, event handling, textures, and basic game logic.

## Overview

The goal of the game is to navigate through a maze, collect all collectibles, and reach the exit while avoiding obstacles.  
The player must carefully plan their movement to complete the map successfully.

<p align="center">
  <img src="readme_srcs/gameplay_00.png" alt="gameplay">
</p>

## Features

- 2D top-down maze gameplay
- Keyboard-based player movement
- Collectibles and exit system
- Map validation and error handling
- Custom-made graphical assets
- Smooth rendering using MiniLibX

<p align="center">
  <img src="readme_srcs/gameplay_01.png" alt="gameplay">
</p>

## Bonus Features

### Pathfinding
In addition to the mandatory requirements, the project includes a **pathfinding system**. 
Since I wanted to show to my pear the pathfinding systeme I've added this visualisation at the begining of the game.
This feature displays the path used to validate map solvability and helps visualize how the player can reach all collectibles and the exit.

<p align="center">
  <img src="readme_srcs/pathfinding.gif" alt="Pathfinding">
</p>

### HUD

To keep track of steps I made and HUD that show how many steps you made and keys there is still on the map.
In the subject it was only asked to display text, I tought that it was ugly and made images instead.

<p align="center">
  <img src="readme_srcs/hud.png" alt="Hud">
</p>

### Sprite animations

There is some frame animation, for example the door change sprite when opened, and the enemies keep track of you by still looking towards you.

<p align="center">
  <img src="readme_srcs/animation_00.gif" alt="enemies">
</p>

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
