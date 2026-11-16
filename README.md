# Run-Length Encoding (RLE)

An exploration of Run-Length Encoding (RLE), a simple lossless data compression technique, for COMP 211.

## Overview

Run-Length Encoding (RLE) compresses data by replacing consecutive repeated values with their count and value. Instead of storing each repeated character individually, the algorithm records how many times it appears in a row.

For example:

- Original: `AAAAABBBCC`
- Encoded: `5A3B2C`

The representation decreases from 10 characters to 6 without losing information.

## Implementation

The project includes two C programs:

- **`rle.c`** — A basic RLE encoder that processes a string from left to right, counts consecutive repeated characters, and prints the encoded representation.
- **`rle_comparison.c`** — An extended implementation that tests four strings and calculates their original and encoded lengths, compression ratios, and percentage changes.

Both programs use the count-first format, where `AAAAABBBCC` becomes `5A3B2C`.

The implementation uses character arrays, loops, counters, and null-terminated strings. Its time complexity is **O(n)**, where n is the length of the input string, because each character is processed once by the counting loop.

## Running the Programs

Compile and run the basic encoder:

```bash
gcc -Wall -Wextra -std=c11 rle.c -o rle
./rle
```

Compile and run the comparison program:

```bash
gcc -Wall -Wextra -std=c11 rle_comparison.c -o rle_comparison
./rle_comparison
```

## Experiment

I tested four strings with different patterns of consecutive repetition to compare how effectively RLE reduces their encoded lengths.

| Original Input | Encoded Output | Compression Ratio | Size Change |
|---|---|---|---|
| `AAAAAAAAAA` | `10A` | 3.33:1 | 70% smaller |
| `AAAABBBCC` | `4A3B2C` | 1.50:1 | 33.33% smaller |
| `ABCDEF` | `1A1B1C1D1E1F` | 0.50:1 | 100% larger |
| `ABABABAB` | `1A1B1A1B1A1B1A1B` | 0.50:1 | 100% larger |

### Testing and Verification

I compiled and ran both C programs in VS Code. Using `rle_comparison.c`, I compared the actual encoded outputs, lengths, compression ratios, and percentage changes against the values calculated during my ChatGPT exploration.

All four tests matched the predicted results.

The experiment confirmed that RLE is most effective when data contains long runs of identical characters. `AAAAAAAAAA` produced the greatest reduction (70%), while `ABCDEF` and `ABABABAB` doubled in encoded length because neither contained consecutive repetitions.

These comparisons measure encoded text lengths rather than actual compressed file sizes or total program memory usage.

## Findings

RLE's effectiveness depends on the pattern of the data, not simply how often a particular character appears.

Long sequences of repeated values can be represented efficiently using a count and character. However, when characters change frequently, adding a count before each one can increase the size of the representation.

The algorithm also runs in O(n) time despite using nested loops, since the index only moves forward through the input string.

## Limitations

The implementations print encoded text rather than creating a compressed file or storing a separate compressed string.

The simplified count-character format can also become ambiguous when the original input contains digits. A more complete implementation would need a clearly defined encoding format so the original data can be reconstructed reliably.

## Presentation

The presentation slides are available in [`comp 211 checkoff 3.pdf`](comp 211 checkoff 3.pdf).

## Resources

References and additional learning materials are listed in [`resources.md`](resources.md).
