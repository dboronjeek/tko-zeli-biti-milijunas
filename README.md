# Who Wants to Be a Millionaire

## Description

"Who Wants to Be a Millionaire" is a simple implementation of the popular game in the C programming language. Players answer a series of multiple-choice questions, aiming to win as much money as possible by answering correctly.

## Project Structure

* `main.c`: Main program managing the game logic.
* `program.c`: Additional functional code supporting the game.
* `testAnswerPrint.c`: Test code for printing answers.
* `testQuestionPrint.c`: Test code for printing questions.
* `testScorePrint.c`: Test code for printing scores.
* `odgovori.txt`: File containing possible answers.
* `pitanja.txt`: File containing game questions.
* `score.txt`: File storing player scores.
* `scoreSorted.txt`: File storing sorted player scores.

## How to Run

1. Clone the repository:

   ```bash
   git clone https://github.com/dboronjeek/tko-zeli-biti-milijunas.git
   ```

2. Navigate to the project directory:

   ```bash
   cd tko-zeli-biti-milijunas
   ```

3. Compile the program:

   ```bash
   gcc main.c program.c -o millionaire_game
   ```

4. Run the game:

   ```bash
   ./millionaire_game
   ```

## Translation Guide (Croatian to English)

| Croatian          | English          |
| ----------------- | ---------------- |
| Pitanje           | Question         |
| Odgovor           | Answer           |
| Točan odgovor     | Correct answer   |
| Netočan odgovor   | Incorrect answer |
| Novac             | Money            |
| Igra završena     | Game over        |
| Unesite svoje ime | Enter your name  |
| Vaš rezultat je   | Your score is    |
| Pobjednik         | Winner           |

## Technical Info

* Written in C.
* Uses standard libraries for input/output and file handling.
* No external dependencies.

## License

This project is licensed under [your license].

## Contact

For more information or questions, contact the author via GitHub: [dboronjeek](https://github.com/dboronjeek).
