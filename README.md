The docs: https://docs.google.com/document/d/1BFdbF1hX_0scbRBuHutbZe7ZNmMLdyckUDQTWmsXHkI/edit?tab=t.0

Program Documentation
=====================

Build and Run
- Recommended hardened compile command: `gcc -lm -std=c99 -Wall -Wextra -Wpedantic -Wshadow -Wformat=2 -Wstrict-overflow=2 -Wwrite-strings -Wcast-align -Wpointer-arith -Werror -Wconversion -O2 -DNDEBUG  ex2.c -o ex2.out`
- Input is via stdin; output is via stdout. No third-party dependencies beyond the standard C library (libm linked per the flags list).

Overview
- The program presents a looped menu with six options. The loop terminates only when option 6 is chosen.
- Each option runs a small game or calculation, then returns to the menu.
- All numeric inputs are validated for legality; the user is reprompted on invalid values.

Menu Options
- 1. "Ducky's Unity Game": Reads a positive integer, counts its set bits, and reports the number of corn kernels earned.
- 2. "The Memory Game": Reads a duck count (1–64), records for each duck whether it says QUAK using a bitmask, and reports which ducks quacked versus stayed silent.
- 3. "Professor Pat's Power Calculation": Reads a non-negative base and exponent, computes the integer power via iterative multiplication, and prints the result.
- 4. "The Duck Parade": Prints rows of ASCII ducks, up to 10 per line, until the requested duck count is exhausted.
- 5. "The Mystery of the Repeated Digits": Reads a positive integer, tracks seen digits with a bitmask, and prints any digit that appears more than once.
- 6. "Good Night Ducks": Prints a farewell message and exits the main loop.

Input Validation
- Every numeric input is range-checked (e.g., positive values, up to 64 ducks, or non-negative exponents). Invalid entries trigger an error prompt and retry.
- Invalid menu choices print "Invalid option, please try again" and return to the menu.

Data Structures and Methods
- Bitmasks (`unsigned long long` / `unsigned int`) store duck QUAK states and seen digits, enabling constant-time checks via bitwise shifts and masks.
- Power calculation uses straightforward iterative multiplication suitable for non-negative exponents within the `int` range.

Potential Improvements
- Add robust scanf error handling (checking return values, clearing stdin on bad input).
- Guard against overflow in power calculation by pre-checking bounds or using wider integer types.
- Refactor each game into a dedicated function to improve readability and testability.
