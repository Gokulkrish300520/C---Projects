# C---Projects

# Snake Game in C++

## Overview

This repository contains a simple implementation of the classic Snake game using C++. The game runs in the terminal and allows the player to control the snake using the `W`, `A`, `S`, and `D` keys to move up, left, down, and right, respectively. The objective of the game is to eat the fruit (marked by `F`) that appears randomly on the grid, which increases the length of the snake. The game ends when the snake hits the wall or its own tail.

## Features

- **Terminal-Based Interface**: The game runs in the terminal, with simple text-based graphics.
- **Random Fruit Generation**: The fruit is placed randomly on the grid each time it is eaten by the snake.
- **Real-Time Input Handling**: The game processes user input in real-time to change the direction of the snake.
- **Scoring System**: The player's score increases as the snake eats more fruit.

## How to Run

1. **Clone the Repository**:
    ```bash
    git clone <repository-url>
    cd <repository-directory>
    ```

2. **Compile the Code**:
    You can compile the C++ code using a compiler like `g++`:
    ```bash
    g++ -o snake_game Snake_game.cpp
    ```

3. **Run the Game**:
    After compiling, you can run the game using:
    ```bash
    ./snake_game
    ```

4. **Game Controls**:
    - `W`: Move Up
    - `A`: Move Left
    - `S`: Move Down
    - `D`: Move Right
    - `X`: Exit the Game

## Code Structure

- **Variables**:
    - `gameOver`: A boolean that tracks whether the game has ended.
    - `width`, `height`: Constants that define the size of the game grid.
    - `x`, `y`: The current position of the snake's head.
    - `fruitPositionX`, `fruitPositionY`: The current position of the fruit.
    - `score`: Tracks the player's score.
    - `tailX`, `tailY`: Arrays that store the positions of the snake's tail segments.
    - `ntail`: The number of tail segments.

- **Functions**:
    - `setup()`: Initializes the game state, setting up the snake and the first fruit.
    - `draw()`: Renders the game grid, the snake, and the fruit in the terminal.
    - `input()`: Handles user input to control the direction of the snake.
    - `logic()`: Updates the game state, including snake movement, tail management, and collision detection.

## Future Enhancements

- **Increase Difficulty**: Gradually increase the speed of the snake as the player’s score increases.
- **Add Obstacles**: Introduce obstacles within the grid to make the game more challenging.
- **High Score Tracking**: Implement a system to track and display the highest score achieved by the player.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
