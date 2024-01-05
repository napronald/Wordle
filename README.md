# Wordle Clone Project

This project is a clone of the popular word-guessing game Wordle. It is a console-based application where players have six attempts to guess a randomly selected word. Each guess provides feedback in the form of colored tiles, indicating when letters match or occupy the correct position.

![Figure 1](https://github.com/napronald/Wordle/blob/main/Figures/w4.png)

## How to Play
- Run the application.
- Enter your guess (a valid 5-letter word).
- Review the color-coded feedback:
  - **Green**: Letter is in the word and in the correct position.
  - **Yellow**: Letter is in the word but in the wrong position.
  - **Black**: Letter is not in the word in any spot.
- Use the feedback to make your next guess.
- Try to guess the word in six attempts or fewer.

![Figure 1](https://github.com/napronald/Wordle/blob/main/Figures/w6.png)



## Features

- **Console-Based Interface**: Easy to use and navigate.

![Figure 1](https://github.com/napronald/Wordle/blob/main/Figures/w1.png)

- **Historical Tracking**: Maintain a detailed record of previous games, including statistics on performance over time.

![Figure 1](https://github.com/napronald/Wordle/blob/main/Figures/w5.png)
  
- **Color Feedback**: Receive immediate, color-based hints after each guess to help refine subsequent attempts.

![Figure 1](https://github.com/napronald/Wordle/blob/main/Figures/w3.png)

![Figure 1](https://github.com/napronald/Wordle/blob/main/Figures/w7.png)

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes.

### Prerequisites

What things you need to install the software and how to install them:

- C++ Compiler (GCC recommended)
- Make (optional for building)
- Git

### Installing and Running

Follow these steps to set up and run the Wordle game in your development environment.

1. **Clone the repository:**
   Clone the Wordle repository from GitHub to your local machine.
    ```sh
    git clone https://github.com/napronald/Wordle.git
    ```
2. **Navigate to the directory:**
   Change into the directory where the Wordle game code is located.
    ```sh
    cd Wordle
    ```
3. **Compile the project:**
   Compile the `main.cpp` file into an executable named Wordle. Make sure you have a C++ compiler like g++ installed.
    ```sh
    g++ -o Wordle main.cpp
    ```
4. **Run the game with command-line arguments:**
   Run the compiled Wordle game. The game expects a command-line argument representing the desired word length (4, 5, 6, or 7). For example, to play with 5-letter words:
    ```sh
    ./Wordle 5 5-letter-words.txt 5-allowed-guesses.txt
    ```
   Replace  `5`, `5-letter-words.txt`, and `5-allowed-guesses.txt` with the desired word length (4, 5, 6, or 7).

5. **Running Keyboard Interface Concurrently:**
   If you wish to have a keyboard interface running concurrently with the main game, navigate to the `MyWordle` directory in a new terminal window and compile the keyboard interface:
    ```sh
    cd path/to/MyWordle
    g++ -o KeyboardInterface keyboard.cpp
    ```
   Then, run the `KeyboardInterface` program:
    ```sh
    ./KeyboardInterface
    ```
   This will allow you to interact with the Wordle game using a keyboard interface in real time.
