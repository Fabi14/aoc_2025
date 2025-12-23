#pragma once
#include <string>
#include <chrono>
#include <filesystem>

namespace aoc
{
    std::string readInput(const std::filesystem::path& fileName);

    constexpr auto abs(auto i)
    {
        return i < 0 ? -i : i;
    }

    template<typename T>
    constexpr T svto(std::string_view const& sv)
    {
        if (T value; std::from_chars(sv.data(), sv.data() + sv.size(), value).ec == std::errc{})
        {
            return value;
        }

        throw std::invalid_argument("not a number");
    }

    class Timer
    {
    public:
        static Timer start()
        {
            return Timer();
        }
        const Timer& stop()
        {
            m_end = std::chrono::high_resolution_clock::now();
            return *this;
        }

        template<typename T>
        [[nodiscard]] auto get() const
        {
            return std::chrono::duration_cast<T> (m_end - m_start);
        }
    private:
        Timer() :m_start{ std::chrono::high_resolution_clock::now() }
        {
        }
        std::chrono::steady_clock::time_point m_start;
        std::chrono::steady_clock::time_point m_end;
    };
}