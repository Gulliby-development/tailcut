#include <cstdio>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

#include "tailcut.hpp"

#ifdef _WIN32
#include <fcntl.h>
#include <io.h>
#endif

int main(int argc, char **argv) {
#ifdef _WIN32
    _setmode(_fileno(stdin), _O_BINARY);
    _setmode(_fileno(stdout), _O_BINARY);
    _setmode(_fileno(stderr), _O_BINARY);
#endif
    std::vector<std::string> args(argv + 1, argv + argc);
    std::string input;
    if (tailcut::reads_stdin(args)) {
        input.assign(std::istreambuf_iterator<char>(std::cin), std::istreambuf_iterator<char>());
    }
    tailcut::Result result = tailcut::run(args, input);
    std::fwrite(result.out.data(), 1, result.out.size(), stdout);
    std::fwrite(result.err.data(), 1, result.err.size(), stderr);
    return result.status;
}
