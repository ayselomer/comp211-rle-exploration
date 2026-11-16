# RLE Experiment Results

This experiment compares effectiveness of Run-Length Encoding (RLE) on strings with different patterns of consecutive repetition.

## Method

I used `rle_comparison.c` to test four strings using the count-first RLE format, where `AAAAABBBCC` becomes `5A3B2C`.

The program measured the original and encoded lengths of each string and calculated the compression ratio and percentage size change.

**Compression Ratio = Original Length / Encoded Length**

**Percentage Size Change = ((Encoded Length − Original Length) / Original Length) × 100**

A negative percentage indicates a reduction in size, while a positive percentage indicates an increase.

## Results

| Original Input | Encoded Output | Original Length | Encoded Length | Compression Ratio | Size Change |
|---|---|---:|---:|---:|---:|
| `AAAAAAAAAA` | `10A` | 10 | 3 | 3.33:1 | −70% |
| `AAAABBBCC` | `4A3B2C` | 9 | 6 | 1.50:1 | −33.33% |
| `ABCDEF` | `1A1B1C1D1E1F` | 6 | 12 | 0.50:1 | +100% |
| `ABABABAB` | `1A1B1A1B1A1B1A1B` | 8 | 16 | 0.50:1 | +100% |

## Testing and Verification

I compiled and ran both `rle.c` and `rle_comparison.c` in VS Code using GCC.

The basic encoder produced the expected encoded strings, while the comparison program calculated the original lengths, encoded lengths, compression ratios, and percentage changes.

I compared the program's output against the predictions from my ChatGPT exploration. All four tests matched the expected results.

## Findings

The first string, `AAAAAAAAAA`, produced the greatest reduction (70%) because all ten characters formed a single consecutive run.

The second string, `AAAABBBCC`, also compressed effectively, reducing its encoded length by 33.33%, but contained three separate runs.

The last two strings, `ABCDEF` and `ABABABAB`, doubled in encoded length because neither contained consecutive repetitions. Each character therefore required its own count-value pair.

These results demonstrate that RLE's effectiveness depends on consecutive repetition rather than simply how frequently a character appears.

## Limitations

The experiment measures the length of the encoded text printed by the program rather than the size of an actual compressed file.

The simplified count-first format can also be ambiguous when the original string contains digits. A complete RLE implementation would need additional formatting rules to ensure reliable decoding.

These results therefore demonstrate the behavior of this particular text-based implementation rather than every possible RLE encoding format.
