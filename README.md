<p align="center"><img src="docs/logo.svg" width="96" alt="" /></p>

# tailcut

[![CI](https://github.com/Gulliby-development/tailcut/actions/workflows/ci.yml/badge.svg)](https://github.com/Gulliby-development/tailcut/actions/workflows/ci.yml) [![License: MIT](https://img.shields.io/badge/license-MIT-blue.svg)](LICENSE)

tailcut replays the cuts that a language-model sampler makes on its candidates: top-k, top-p (nucleus) and min-p. It reads a short list of weighted candidates on standard input, one candidate per line, and prints what is left. It is a small C++17 program that uses only the standard library. It makes no model call, uses no random numbers and no clock, and does all its arithmetic on 64-bit integers, so the same input always gives the same output.

It is for people who tune or debug samplers and want to see a cut on a list they can read. It works in a terminal, in a script or in CI.

Build it with CMake (C++17, on Windows, macOS or Linux):

```text
cmake -S . -B build
cmake --build build
```

Then run the program from the build folder: `build/tailcut` with a single-configuration generator, or `build/Debug/tailcut` with the Visual Studio generator on Windows.

## Usage

```text
usage: tailcut check
       tailcut share [--unit UNIT] [--format FORMAT]
       tailcut topk --k N [--format FORMAT]
       tailcut topp --p PERMILLE [--format FORMAT]
       tailcut minp --ratio PERMILLE [--format FORMAT]
       tailcut chain --steps STEPS [--format FORMAT]
       tailcut draw --at N
```

Every command reads the list of candidates from standard input. A command that works writes its result to standard output and nothing to standard error. A command that fails writes nothing to standard output and one line `tailcut: MESSAGE` to standard error.

The commands:

1. `check` validates the list and prints `ok, N candidates, total T`.
2. `share` prints each weight as a share of the total, in input order.
3. `topk` keeps the k heaviest candidates.
4. `topp` keeps the smallest group of heaviest candidates that reaches a share of the total.
5. `minp` keeps the candidates that weigh at least a ratio of the heaviest one.
6. `chain` applies one to four filters one after the other.
7. `draw` names the candidate that a position in the cumulative weights falls on.

`help`, `-h` and `--help` as the first word print the usage above on standard output and exit 0, whatever follows. `--version` prints `tailcut 0.1.0` and exits 0, whatever follows. With no word the usage goes to standard error and the exit status is 2. Any other first word is an unknown command.

Options:

- `--format` is `plain`, `csv` or `bar`. The default is `plain`.
- `--unit` is `permille`, `percent` or `ppm`. The default is `permille`.
- `--k` is a whole number from 1 to 32.
- `--p` is a whole number from 1 to 1000.
- `--ratio` is a whole number from 0 to 1000.
- `--at` is a whole number from 0 to 999999999.
- `--steps` is one to four steps separated by commas. Each step is `topk:N`, `topp:P` or `minp:R`, with a value in the range of the option of the same name, for example `topk:3,minp:100`.

Numbers are written with no sign, no leading zero and no more digits than the largest value has (`0` is fine where the range starts at 0, `05` is not). The word after an option is always its value, whatever that word is. There is no `--option=value` form. `share` accepts `--unit` and `--format`; `topk`, `topp`, `minp` and `chain` accept their own option and `--format`; `draw` accepts `--at`; `check` accepts no option. `topk`, `topp`, `minp`, `chain` and `draw` each require their own option.

The command line is checked first (exit 2, the input is not read), then the list (exit 1), then the command.

## List format

- The input is cut into lines at each LF. A final line without LF counts as a line, and one CR at the end of a line is dropped.
- At most 32 lines are allowed, skipped ones included.
- A line that holds only spaces and tabs, or whose first word starts with `#`, is skipped.
- Every other line is one candidate: a token and a weight, separated by spaces or tabs. Spaces and tabs at the ends of the line are ignored.
- A token is one to twelve characters from `A-Z`, `a-z`, `0-9`, `_`, `.` and `-`. Upper and lower case are different tokens.
- A weight is `0` or one to six decimal digits with no leading zero and no sign.
- A token may appear only once.
- A list needs at least one candidate, and the total weight must not be zero.

The lines are checked from first to last and the first problem is the error. On one line the checks run in this order: the number of words, the token, the weight, the duplicate.

## Formats

A table has one line per row, in one of three formats:

- `plain`: `TOKEN NUMBER`
- `csv`: `TOKEN,NUMBER`
- `bar`: `TOKEN NUMBER MARKS`, where MARKS is a run of `#` characters.

The marks are `NUMBER * 20 / FULL`, rounded down, with at least one mark for a number above 0 and at most 20. FULL is the unit scale for `share` (1000, 100 or 1000000) and the heaviest weight of the table for the other commands. A number of 0 has no marks, so its line ends with a space.

Rankings are by weight, heaviest first. Candidates with the same weight keep their input order.

## Filters

- `share`: each line is `(WEIGHT * SCALE + TOTAL / 2) / TOTAL` with integer division, where SCALE is 1000 for `permille`, 100 for `percent` and 1000000 for `ppm`. A half rounds up, and the shares need not add up to the scale. Lines stay in input order.
- `topk --k N`: the N heaviest candidates in ranking order (all of them when the list is shorter).
- `topp --p PERMILLE`: walk down the ranking and keep every candidate up to and including the first one at which the weight kept so far times 1000 is at least P times the total weight.
- `minp --ratio PERMILLE`: keep the candidates whose weight times 1000 is at least RATIO times the heaviest weight. The heaviest one always stays.
- `chain --steps STEPS`: apply the steps in order, each to the candidates the step before it kept (the first one to the whole list). A `topp` step uses the total weight of the candidates that are left, and a `minp` step uses the heaviest weight of the candidates that are left. The weights do not change. The output is the table of what is left, in ranking order.
- `draw --at N`: the position N in the cumulative weights of the list in input order. The answer is the token of the first candidate whose running total after its own weight is above N, followed by a line feed. Candidates of weight 0 are never drawn.

## Examples

In the examples, `tailcut` stands for the built program: `build/Debug/tailcut` with the Visual Studio generator on Windows, `build/tailcut` with a single-configuration generator. The examples run in a POSIX shell, in the repository directory, after the build, with `tailcut` defined as a shell function that runs the program (for example `tailcut() { build/tailcut "$@"; }`). `2>&1` shows the error line.

```text
$ printf 'the 500\ncat 300\ndog 150\nsat 40\nmat 10\n' | tailcut topp --p 900
the 500
cat 300
dog 150
$ printf 'the 500\ncat 300\ndog 150\n' | tailcut share --unit percent --format bar; printf 'a 1\nb 3\n' | tailcut share --format csv
the 53 ##########
cat 32 ######
dog 16 ###
a,250
b,750
$ printf 'the 500\ncat 300\ndog 150\nsat 40\nmat 10\n' | tailcut chain --steps topk:4,minp:100; printf 'the 500\ncat 300\ndog 150\n' | tailcut draw --at 520
the 500
cat 300
dog 150
cat
$ printf 'a 1\nb\n' | tailcut check 2>&1; printf 'a 1\n' | tailcut topk 2>&1
tailcut: line 2: expected TOKEN WEIGHT
tailcut: missing --k
```

## Errors

Exit statuses:

- 0: success.
- 1: an error in the list or in a command.
- 2: an error in the command line; the input is not read.

Every error is written to standard error as `tailcut: MESSAGE` and a line feed.

Command line (exit 2):

- `tailcut: unknown command WORD`
- `tailcut: unexpected argument WORD` (a word that does not start with `-`, or is exactly `-`, or is empty)
- `tailcut: unknown option WORD`
- `tailcut: option OPTION is not valid for COMMAND`
- `tailcut: given twice: OPTION`
- `tailcut: missing value for OPTION`
- `tailcut: bad value for OPTION`
- `tailcut: missing --k`, `tailcut: missing --p`, `tailcut: missing --ratio`, `tailcut: missing --steps`, `tailcut: missing --at`

With no word at all, the usage goes to standard error and the exit status is 2.

List (exit 1):

- `tailcut: input is too long (max 32 lines)`
- `tailcut: line N: expected TOKEN WEIGHT`
- `tailcut: line N: bad token WORD`
- `tailcut: line N: bad weight WORD`
- `tailcut: line N: duplicate token WORD`
- `tailcut: no candidates`
- `tailcut: total weight is zero`

Command (exit 1):

- `tailcut: draw position N is outside the total T`

## Development

Check the formatting of the sources with the repository's `.clang-format`:

```text
clang-format --dry-run --Werror src/*.cpp src/*.hpp tests/*.cpp tests/*.hpp
```

Build as shown above, then run the tests:

```text
ctest --test-dir build -C Debug
```

The build uses C++17 with `/W4 /WX` (MSVC) or `-Wall -Wextra -Wpedantic -Werror` (gcc, clang), so it must produce no warning. Only `src/main.cpp` reads or writes a stream; every other function takes the input as a string and returns a result.

## License

MIT, see the `LICENSE` file.

---

Built with [BAKED](https://github.com/Gulliby-development/baked), an open-source coding agent (bench round R102).
