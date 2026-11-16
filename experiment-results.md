# RLE Experiment Results

Comparing effectiveness of RLE on strings containing different patterns of repetition.

## Method

4 test strings were encoded using a simple C implementation of RLE. The number of characters in each original string was compared with the number of characters in its encoded representation.

Compression ratio was calculated as:

**Compression Ratio = Original Length / Encoded Length**

Percentage size change was calculated as:

**Size Change = ((Encoded Length − Original Length) / Original Length) × 100**

## Results

| Input | Original Length | Encoded Length | Compression Ratio | Size Change |
|---|---:|---:|---:|---:|
| AAAAAAAAAA | 10 | 3 | 3.33:1 | −70% |
| AAAABBBCC | 9 | 6 | 1.50:1 | −33.3% |
| ABCDEF | 6 | 12 | 0.50:1 | +100% |
| ABABABAB | 8 | 16 | 0.50:1 | +100% |

## Findings

The first string produced the greatest reduction because all ten characters belonged to a single run.

The second string also compressed effectively, but contained three separate runs.

The last two strings increased in length because every character required its own count-value pair.

These comparisons show that RLE is most effective when data contains long consecutive repetitions.

## Limitations

The experiment measures the length of the encoded text rather than the size of a complete compressed file. The results therefore illustrate the behavior of this particular encoding format rather than the performance of every RLE implementation.
