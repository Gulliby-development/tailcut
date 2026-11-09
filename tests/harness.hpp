#ifndef TAILCUT_HARNESS_HPP
#define TAILCUT_HARNESS_HPP

#include <cstdio>
#include <string>
#include <vector>

#include "tailcut.hpp"

// One row of a row file: the arguments, the standard input text, the exit status, the standard output text and the standard error text.
struct Row {
    std::vector<std::string> args;
    std::string input;
    int status;
    std::string out;
    std::string err;
};

// Runs every row through tailcut::run; prints every mismatch to standard error and returns 1 when there is one, else 0.
inline int check_rows(const std::vector<Row> &rows) {
    int failed = 0;
    for (std::size_t i = 0; i < rows.size(); i++) {
        tailcut::Result got = tailcut::run(rows[i].args, rows[i].input);
        if (got.status != rows[i].status || got.out != rows[i].out || got.err != rows[i].err) {
            std::fprintf(stderr, "row %zu: expected status %d out [%s] err [%s], got status %d out [%s] err [%s]\n", i + 1, rows[i].status, rows[i].out.c_str(), rows[i].err.c_str(), got.status, got.out.c_str(), got.err.c_str());
            failed = 1;
        }
    }
    return failed;
}

// Runs every row through tailcut::reads_stdin: each row's args hold the command line and status is 1 when it must read standard input, else 0.
inline int check_reads(const std::vector<Row> &rows) {
    int failed = 0;
    for (std::size_t i = 0; i < rows.size(); i++) {
        bool got = tailcut::reads_stdin(rows[i].args);
        if (got != (rows[i].status == 1)) {
            std::fprintf(stderr, "row %zu: expected reads %d, got %d\n", i + 1, rows[i].status, got ? 1 : 0);
            failed = 1;
        }
    }
    return failed;
}

#endif
