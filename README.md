# Exercise 2 — Control Flow and Logic

## Overview

A menu-driven C program featuring six duck-themed mini-games that exercise control flow, bitwise operations, and input validation. The program uses only `stdio.h`, with no arrays or custom functions — all logic resides in `main`.

## Author

Avraham Tsaban

## Compilation

```bash
gcc ex2.c -o ex2.out -lm -std=c99 -DNDEBUG
```

## Running

```bash
./ex2.out
```

## Menu Options

1. **Ducky's Unity Game** — Reads a positive integer, counts its set bits (binary 1s), and reports the number of corn kernels earned.
2. **The Memory Game** — Reads a duck count (1–64), records for each duck whether it says QUAK using a bitmask, and reports which ducks quacked vs. stayed silent.
3. **Professor Pat's Power Calculation** — Reads a non-negative base and exponent, computes integer power via iterative multiplication.
4. **The Duck Parade** — Prints rows of ASCII ducks (up to 10 per row) until the requested count is exhausted.
5. **The Mystery of the Repeated Digits** — Reads a positive integer, tracks seen digits with a bitmask, and prints any digit that appears more than once.
6. **Good Night Ducks** — Prints a farewell message and exits.

All numeric inputs are validated; invalid entries trigger an error prompt and retry.

## Code Structure

The entire program resides in a single `main()` function (no custom functions allowed). A `do-while` loop displays the menu and a `switch` statement dispatches to each task:

- **Task 1 (Bit counting)** — Iterates through bits of the number with `& 1` and `>>= 1`.
- **Task 2 (Memory bitmask)** — Uses an `unsigned long long` as a 64-bit bitmask to store and recall per-duck QUAK state.
- **Task 3 (Power)** — Simple iterative multiplication in a `for` loop; no `math.h`.
- **Task 4 (Duck parade)** — Prints ASCII art ducks in rows of up to 10, using a `while` loop with a row counter.
- **Task 5 (Repeated digits)** — Extracts digits right-to-left (`% 10` / `/ 10`), tracks seen digits with a 10-bit `unsigned int` mask.

All input validation uses `while` loops that re-prompt until valid values are entered.

## Project Files

| File | Description |
|------|-------------|
| `ex2.c` | Source code |
| `ex2.example` | Reference Linux executable provided by the TA |
| `ex2_instructions.md` | Exercise instructions |

## Attribution

The exercise design, specifications, and instructions were created by **Noy Shafferman**, the Teaching Assistant responsible for this assignment. The instructions file (`ex2_instructions.md`) and the reference executable (`ex2.example`) are her work. Any license in this repository applies only to the student's code implementation.
