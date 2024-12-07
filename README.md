# Bouncing Balls Simulation

A fun simulation of balls bouncing around in a confined space with collision detection and physics-inspired interactions, created using **SFML** (Simple and Fast Multimedia Library).

## Features
- **Dynamic Ball Movement**: Balls move within the window, bouncing off the edges.
- **Collision Detection**: Handles collisions between multiple balls with realistic velocity adjustments.
- **Customizable Simulation**: Easily add or modify balls with different velocities, positions, and colors.
- **SFML-Based Visualization**: Provides smooth and visually appealing animations.

## Getting Started

### Prerequisites
- **SFML Library**: Make sure SFML is installed on your system. [Get SFML](https://www.sfml-dev.org/download.php)
- A C++ compiler that supports C++11 or later (e.g., GCC, Clang, MSVC).

### Installation
1. Clone the repository:
   ```bash
   git clone https://github.com/your-username/bouncing-balls-simulation.git
   cd bouncing-balls-simulation
2. Now open the terminal and run the following commands 
    Linux:
    g++ -o BouncingBalls main.cpp -lsfml-graphics -lsfml-window -lsfml-system
    ./BouncingBalls
    Windows:
    mingw32-make -B
    main.exe
