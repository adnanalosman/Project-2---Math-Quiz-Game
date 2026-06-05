# Math Quiz Game 🧮

**Project 2** from Course 5 of Abu Hadhoud Programming Road Map

## Description

A console-based interactive math quiz game built in C++ that challenges players to solve arithmetic problems. Players can customize their gaming experience by selecting difficulty levels, operation types, and the number of rounds they want to play.

## Features

✨ **Customizable Difficulty Levels**
- Easy: Numbers 1-10
- Mid: Mixed range numbers (10-100)
- Hard: Numbers 10-100
- Mix: Random difficulty for each question

✨ **Multiple Operation Types**
- Addition (+)
- Subtraction (-)
- Multiplication (×)
- Division (/)
- Mix: Random operation for each question

✨ **Game Mechanics**
- Adjustable rounds (1-10 questions per game)
- Instant feedback on answers (correct/incorrect)
- Displays correct answer if wrong
- Color-coded feedback (green for correct, red for incorrect)

✨ **Performance Tracking**
- Tracks wins and losses per game
- Generates detailed game report
- Shows overall game result (Winner/Loser)

✨ **Replay Feature**
- Play multiple rounds without restarting the program

## How to Use

### Prerequisites
- C++ compiler (Visual Studio, Code::Blocks, GCC, or Clang)
- Basic knowledge of command-line interface

### Compilation & Execution

**Using g++:**
```sh
g++ -o MathQuizGame "Math Quiz Game.cpp"
./MathQuizGame
```

**Using Visual Studio:**
1. Open the project in Visual Studio
2. Press `Ctrl + F5` to run without debugging
3. Or press `F5` to run with debugging

### Gameplay Instructions

1. **Select Rounds**: Enter number of questions (1-10)
2. **Choose Difficulty**: 
   - [1] Easy
   - [2] Mid
   - [3] Hard
   - [4] Mix
3. **Select Operation**:
   - [1] Addition
   - [2] Subtraction
   - [3] Multiplication
   - [4] Division
   - [5] Mix
4. **Answer Questions**: Solve each math problem and enter your answer
5. **View Results**: See your game report and final score
6. **Play Again**: Choose to play another round or exit

## Technologies Used

- **Language**: C++ (Standard C++98/C++11)
- **Platform**: Console/Command Line
- **Libraries**: 
  - `iostream` - Input/Output operations
  - `cmath` - Math functions
  - `ctime` - Time functions (for random seed)
  - `cstdlib` - Standard library functions

## Project Structure

```
├── Main Function
│   └── NewGame() - Main game loop
│
├── Input Functions
│   ├── ReadRange() - Validates user input within range
│   └── ReadMathInput() - Reads float answers from user
│
├── Math Functions
│   ├── Calculator() - Performs arithmetic operations
│   ├── Random() - Generates random numbers
│   └── MixOperation() - Handles mix operation logic
│
├── Game Logic
│   ├── GenNumRandomEasyToHard() - Generates numbers based on difficulty
│   ├── RandomLevelBased() - Handles level randomization
│   ├── OperationResult() - Validates user answer
│   ├── GamePlayResult() - Processes round results
│   ├── Question() - Displays question to player
│   └── RoundGamePlay() - Manages single round
│
└── Report Functions
    ├── PrintOperation() - Converts operation enum to symbol
    ├── GameResult() - Determines final game outcome
    └── GetGamePlayReport() - Displays final statistics
```

## Future Enhancements

- 🎯 Add score multipliers for difficulty levels
- 🎯 Implement time limits for questions
- 🎯 Add leaderboard to track high scores
- 🎯 Support for negative numbers
- 🎯 GUI interface instead of console
- 🎯 Sound effects and animations
- 🎯 Difficulty adjustment based on performance
- 🎯 Statistics history file storage

## Learning Outcomes

This project demonstrates:
- ✅ Enumerations for type-safe constants
- ✅ Conditional logic and loops
- ✅ Function design and modularity
- ✅ Random number generation
- ✅ User input validation
- ✅ Console formatting and coloring
- ✅ Game state management

## Author

**Project**: Graduation Project 2  
**Course**: Course 5 - Abu Hadhoud Programming Road Map  
**Language**: C++  
**Difficulty**: Beginner to Intermediate

---

**Enjoy the game and test your math skills! 🎮**
