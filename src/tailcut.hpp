#ifndef TAILCUT_HPP
#define TAILCUT_HPP

#include <cstddef>
#include <string>
#include <vector>

namespace tailcut {

// All the arithmetic is on 64-bit integers (a long is 32 bits on Windows).
using i64 = long long;

// What one command line produced: the exit status and the text for standard output and standard error.
struct Result {
    int status;
    std::string out;
    std::string err;
};

// Thrown by a command or the list reader: the exit status and the message without "tailcut: " and the line feed.
struct Failure {
    int status;
    std::string message;
};

// One candidate of the list: the token and its weight.
struct Candidate {
    std::string token;
    i64 weight;
};

// The options of a command line, with the defaults filled in: format plain, unit permille; k, p, ratio and at are -1 and steps is empty when absent.
struct Options {
    std::string format;
    std::string unit;
    i64 k;
    i64 p;
    i64 ratio;
    std::string steps;
    i64 at;
};

using Handler = Result (*)(const Options &options, const std::vector<Candidate> &items);

// A command: its name, the options it accepts, the option that must be given (or "") and its handler (which may throw Failure).
struct Command {
    const char *name;
    std::vector<std::string> options;
    const char *required;
    Handler run;
};

// One line of an output table: the token, the number shown and the number that stands for a full bar (twenty hash marks).
struct Row {
    std::string token;
    i64 value;
    i64 full;
};

extern const char *const VERSION;
extern const char *const USAGE;
extern const std::size_t MAX_LINES;
extern const std::vector<Command> COMMANDS;

// cli.cpp
Result run(const std::vector<std::string> &args, const std::string &input);
bool reads_stdin(const std::vector<std::string> &args);

// input.cpp: the candidates of the list in input order (throws Failure(1, ...))
std::vector<Candidate> read_candidates(const std::string &input);

// report.cpp: the table in a format (plain, csv or bar), one line per row, and a count with its noun
std::string render_rows(const std::vector<Row> &rows, const std::string &format);
std::string plural(std::size_t count, const std::string &noun);

// bars.cpp: the hash marks of a value against a full bar
std::string bar(i64 value, i64 full);

// rank.cpp: the indexes of the candidates by weight, heaviest first, equal weights in input order
std::vector<std::size_t> ranking(const std::vector<Candidate> &items);

// cmd_check.cpp, cmd_share.cpp, cmd_filters.cpp, cmd_chain.cpp, cmd_draw.cpp
Result check_command(const Options &options, const std::vector<Candidate> &items);
Result share_command(const Options &options, const std::vector<Candidate> &items);
Result topk_command(const Options &options, const std::vector<Candidate> &items);
Result topp_command(const Options &options, const std::vector<Candidate> &items);
Result minp_command(const Options &options, const std::vector<Candidate> &items);
Result chain_command(const Options &options, const std::vector<Candidate> &items);
Result draw_command(const Options &options, const std::vector<Candidate> &items);

} // namespace tailcut

#endif
