#pragma once
#include "aocHelper.h"
#include <ranges>
#include <string>
#include <print>
#include <filesystem>
#include <numeric>
#include <functional>
#include <vector>



constexpr auto parseLine = [](std::string_view const& line)
    {
        auto const distance = aoc:: svto<int>(line.substr(1));
        return line[0] == 'L' ? -distance : distance;
    };

constexpr int mod(int const i, int const n)
{
    return (i % n + n) % n;
}

constexpr int part1(const std::string& input)
{
    auto numbers = input
        | std::views::split('\n')
        | std::views::transform([](auto const& line) { return std::string_view(line); })
        | std::views::transform(parseLine)
        | std::views::common;
    std::vector<int> positions;
    std::exclusive_scan(numbers.begin(), numbers.end(),std::back_inserter(positions), 50);
     return static_cast<int>(std::ranges::distance( positions
         | std::views::transform(std::bind_back(std::modulus{},100))
         | std::views::filter(std::bind_front(std::equal_to{},0) )));
}

constexpr auto part2(const std::string& input)
{
    auto answer = 0;
    auto dial = 50;
    for (auto const number : input
        | std::views::split('\n')
        | std::views::transform([](auto const& line) { return std::string_view(line); })
        | std::views::transform(parseLine))
    {
        auto const prev_dial = dial;
        dial += number;
        if (dial < 1 || dial > 99)
        {
            answer += aoc::abs(dial) / 100;
            if (dial <= 0 && prev_dial != 0)
            {
                answer += 1;
            }
        }

        dial = mod(dial, 100);
    }
    return answer;
}

void day01()
{
    // Tests
    static_assert(part1("L68\nL30\nR48\nL5\nR60\nL55\nL1\nL99\nR14\nL82") == 3);
    static_assert(part2("L68\nL30\nR48\nL5\nR60\nL55\nL1\nL99\nR14\nL82") == 6);


    auto input = aoc::readInput(std::filesystem::path("day01.txt"));

    for (auto f : { part1, part2 })
    {
        auto timer = aoc::Timer::start();
        const auto answer = f(input);
        const auto micros = timer.stop().get<std::chrono::microseconds>();
        std::println("{} ({})", answer, micros);
    }
}