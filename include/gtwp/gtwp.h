#ifndef GTWP_GTWP_H
#define GTWP_GTWP_H

#pragma once

#include <gtest/gtest.h>
#include <sstream>

namespace testing { namespace internal {

/* https://stackoverflow.com/a/45344932/5218590 */
enum GTestColor { COLOR_DEFAULT, COLOR_RED, COLOR_GREEN, COLOR_YELLOW };
extern void ColoredPrintf(GTestColor color, const char* fmt, ...);

}} // namespace testing::internal

namespace {

std::string lineFeed()
{
    std::stringstream ss;
    ss << std::endl;
    return ss.str();
}

std::string LINE_FEED = lineFeed();

} // namespace anonymous

#define GTWP_COLORED_PRINTF_(color, leading, ...)        \
    do {                                                 \
        using namespace ::testing::internal;             \
        ColoredPrintf(color, leading);                   \
        ColoredPrintf(COLOR_DEFAULT, __VA_ARGS__);       \
        ColoredPrintf(COLOR_DEFAULT, LINE_FEED.c_str()); \
    } while (false)

#define GTWP_INFO(...) \
    GTWP_COLORED_PRINTF_(::testing::internal::COLOR_GREEN,  "[   INFO   ] ", __VA_ARGS__)

#define GTWP_WARN(...) \
    GTWP_COLORED_PRINTF_(::testing::internal::COLOR_YELLOW, "[   WARN   ] ", __VA_ARGS__)

#define GTWP_CRIT(...) \
    GTWP_COLORED_PRINTF_(::testing::internal::COLOR_RED,    "[   CRIT   ] ", __VA_ARGS__)

#endif // GTWP_GTWP_H
