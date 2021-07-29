#ifndef COLOR_H
#define COLOR_H

#include <iostream>
#include <cstdint>

class Color
{
  public:
    static const Color Black;
    static const Color White;
    static const Color Red;
    static const Color Green;
    static const Color Blue;

    Color() noexcept;
    explicit Color(const std::uint8_t, const std::uint8_t, const std::uint8_t, const std::uint8_t) noexcept;

    std::uint8_t r, g, b, a;
};

#endif