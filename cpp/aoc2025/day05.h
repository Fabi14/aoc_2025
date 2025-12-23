#pragma once
#include "aocHelper.h"
#include <ranges>
#include <string>
#include <print>
#include <filesystem>
#include <numeric>
#include <functional>
#include <vector>

struct FreshIDRange
{
	long long int firstID{};
	long long int lastID{};
};

long long part1(const std::string& input)
{
	std::vector<FreshIDRange> freshIDs{};

	using namespace std::views;

	auto notEmptyline = [](auto line) {return std::ranges::distance(line) != 0; };
	auto toInt = [](auto line) {return std::stoll(std::string(std::string_view(line))); };


	for (const auto& line : input
		| std::views::split('\n')
		| std::views::take_while(notEmptyline))
	{
		auto range = line | split('-');
		freshIDs.push_back(FreshIDRange{
		.firstID = toInt(*range.begin()),
		.lastID = toInt(*std::next(range.begin()))
			});
	}
	long long sum{ 0 };
	for (const auto& id : input | split('\n')
		| drop_while(notEmptyline)
		| drop(1)
		| transform(toInt))
	{
		auto it = std::ranges::find_if(freshIDs, [id](const FreshIDRange& range)
			{
				return id >= range.firstID && id <= range.lastID;
			});
		if (it != freshIDs.end())
		{
			sum++;
		}
	}

	//std::println("{}",input);
	return sum;
}


long long part2(const std::string& input)
{
	std::vector<FreshIDRange> freshIDs{};

	using namespace std::views;

	auto notEmptyline = [](auto line) {return std::ranges::distance(line) != 0; };
	auto toInt = [](auto line) {return std::stoll(std::string(std::string_view(line))); };


	for (const auto& line : input
		| std::views::split('\n')
		| std::views::take_while(notEmptyline))
	{
		auto range = line | split('-');
		freshIDs.push_back(FreshIDRange{
		.firstID = toInt(*range.begin()),
		.lastID = toInt(*std::next(range.begin()))
			});
	}

	if (freshIDs.empty())
		return 0;

	std::ranges::sort(freshIDs, {}, &FreshIDRange::firstID);

	std::vector<FreshIDRange> cleanFreshIDs{ freshIDs.front() };

	for (const auto& range : freshIDs | drop(1))
	{
		auto& backRange = cleanFreshIDs.back();

		if (range.firstID <= backRange.lastID)
		{
			backRange.lastID = range.lastID > backRange.lastID ? range.lastID : backRange.lastID;
		}
		else
		{
			cleanFreshIDs.push_back(range);
		}
	}

	long long  sum = 0;
	for (const auto range : cleanFreshIDs)
	{
		sum += range.lastID - range.firstID + 1;
	}

	//std::println("{}",input);
	return  sum;
}

void day05()
{
	// Tests
   /* static_assert(part1("L68\nL30\nR48\nL5\nR60\nL55\nL1\nL99\nR14\nL82") == 3);
	static_assert(part2("L68\nL30\nR48\nL5\nR60\nL55\nL1\nL99\nR14\nL82") == 6);*/


	auto input = aoc::readInput(std::filesystem::path("day05.txt"));

	for (auto f : { part1, part2 })
	{
		auto timer = aoc::Timer::start();
		const auto answer = f(input);
		const auto micros = timer.stop().get<std::chrono::microseconds>();
		std::println("{} ({})", answer, micros);
	}
}