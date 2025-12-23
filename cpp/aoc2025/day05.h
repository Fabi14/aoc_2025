#pragma once
#include "aocHelper.h"
#include <ranges>
#include <string>
#include <print>
#include <filesystem>
#include <vector>
#include <string_view>

struct FreshIDRange
{
	long long int firstID{};
	long long int lastID{};
};


constexpr std::vector<FreshIDRange> createMergedRages(const std::string& input)
{
	using namespace std::views;
	std::vector<FreshIDRange> freshIDs{};

	auto notEmptyline = [](auto line) {return std::ranges::distance(line) != 0; };
	auto toInt = [](auto line) {return aoc::svto<long long>(std::string_view(line)); };

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
		return {};

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
	return cleanFreshIDs;
}

constexpr long long part1(const std::string& input)
{
	using namespace std::views;

	 auto notEmptyline = [](auto line) {return std::ranges::distance(line) != 0; };
	 auto toInt = [](auto line) {return aoc::svto<long long>(std::string_view(line)); };

	const std::vector<FreshIDRange> freshIDs{ createMergedRages(input) };
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
	return sum;
}


constexpr long long part2(const std::string& input)
{
	const std::vector<FreshIDRange> cleanFreshIDs{ createMergedRages(input)};

	long long  sum = 0;
	for (const auto range : cleanFreshIDs)
	{
		sum += range.lastID - range.firstID + 1;
	}
	return  sum;
}

void day05()
{
	// Tests
    static_assert(part1("3-5\n10-14\n16-20\n12-18\n\n1\n5\n8\n11\n17\n32") == 3ll);
	static_assert(part2("3-5\n10-14\n16-20\n12-18\n\n1\n5\n8\n11\n17\n32") == 14ll);


	auto input = aoc::readInput(std::filesystem::path("day05.txt"));

	for (auto f : { part1, part2 })
	{
		auto timer = aoc::Timer::start();
		const auto answer = f(input);
		const auto micros = timer.stop().get<std::chrono::microseconds>();
		std::println("{} ({})", answer, micros);
	}
}