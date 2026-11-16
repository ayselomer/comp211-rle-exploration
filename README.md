# comp211-rle-exploration

# Run-Length Encoding (RLE)

Exploration of Run-Length Encoding: a simple lossless data compression technique.

## Overview

Run-Length Encoding (RLE) compresses data by replacing consecutive repeated values with a count and the value itself. Instead of storing every occurrence of a repeated character individually, the algorithm stores how many times that character appears in a row.

For example:

- Original: `AAAAABBBCC`
- Encoded: `5A3B2C`

In this example, the representation decreases from 10 characters to 6.

This project focuses on:

- How RLE encodes and decodes repeated values
- Implementing the basic algorithm in C
- Measuring compression effectiveness using different input patterns
- Understanding when RLE reduces data size and when it increases it
- Exploring applications and limitations of the algorithm

## Implementation

The C program demonstrates RLE using character arrays, loops, counters, and null-terminated strings.

The implementation processes the input from left to right, counts consecutive occurrences of each character, and prints the encoded representation.

Its time complexity is O(n), where n is the length of the input string.

Note: This is a simplified implementation rather than a complete file compression utility.

## Running the Program

Compile using GCC:

```bash
gcc -Wall -Wextra -std=c11 rle.c -o rle
```

Run the program:

```bash
./rle
```

## Experiment

I compared four strings with different patterns of repetition.

| Original Input | Encoded Output | Size Change |
|---|---|---|
| `AAAAAAAAAA` | `10A` | 70% smaller |
| `AAAABBBCC` | `4A3B2C` | 33.3% smaller |
| `ABCDEF` | `1A1B1C1D1E1F` | 100% larger |
| `ABABABAB` | `1A1B1A1B1A1B1A1B` | 100% larger |

These results compare character counts in the simplified text representation, rather than measuring actual compressed file sizes.

## Findings

RLE is effective when data contains long sequences of identical values. However, when consecutive repetitions are uncommon, storing a count before every character can increase the size of the representation.

The experiment illustrates that compression effectiveness depends on the structure of the data.

## Limitations

The implementation prints encoded text and does not produce a binary compressed file. The count-character format also requires additional rules to handle inputs containing digits unambiguously.

## Presentation

The presentation slides are available in `presentation.pdf`.
