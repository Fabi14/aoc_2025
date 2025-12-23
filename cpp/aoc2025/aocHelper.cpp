#include <filesystem>
#include <fstream>
#include <string>
#include "aocHelper.h"


std::string aoc::readInput(const std::filesystem::path& fileName) {
    auto input = std::string{};
    if (auto readStream = std::ifstream(fileName); readStream.is_open())
    {
        input = std::string(
            std::istreambuf_iterator(readStream),
            std::istreambuf_iterator<char>());

        if (input.find("\r\n") != std::string::npos) {
            throw std::invalid_argument("input appears to be separated with windows style line endings!");
        }

        if (input[input.size() - 1] == '\n') {
            throw std::invalid_argument("input contains trailing new line!");
        }
    }

    return input;
}
