# fdf

fdf (or file de fer in french) is a program that reads a file containing a map of a relief landscape and displays it in 3D.
The goal of this project is to learn about graphics and to create a 3D representation of a map. 
The map is represented by a file containing a list of points in a 2D space. Each point is represented by its coordinates and its altitude. The program reads the file and displays the map in 3D.
example of a map file:

```bash
0 1 1 1 1 1
1 1 1 1 1 1
0 0 0 0 0 0
0 0 0 0 3 0
4 0 0 5 0 0
```

## How to use

first clone the repository

```bash
git clone
```

then compile the program

```bash
make
```

fdf takes a file as parameter and displays the map in 3D.

```bash
./fdf maps/42.fdf
```

## Controls

- `W` `A` `S` `D` to move
- `Q` `E` to rotate
- `+` `-` to zoom
- `ESC` to quit
- `R` to retract the map
- `F` to expand the map

## Screenshots

<img width="1083" alt="" src="https://user-images.githubusercontent.com/36860113/231562209-03a67030-2f95-40e0-b555-8d3e94871420.png">

<img width="1083" alt="" src="https://user-images.githubusercontent.com/36860113/231562197-9c43cdcb-3fc6-4535-9280-10c72f6745f5.png">

<img width="1433" alt="" src="https://user-images.githubusercontent.com/36860113/231562178-2abfa338-48f2-48e5-b1ab-6f565aa5ca46.png">

# What I learned

- How to use the minilibx library
- How to project a 3D point to a 2D point
- How to draw a line between two points

This project is one of my favorite projects at 42. I learned a lot about graphics and I really enjoyed working on it.
Math is what i like to have in a project, and this one is full of it. It reminded me of my high school days when i was learning about vectors and matrices.
