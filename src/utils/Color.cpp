#include "Color.hpp"

const Color Color::Black(0, 0, 0, 255);
const Color Color::White(255, 255, 255, 255);
const Color Color::Red(255, 0, 0, 255);
const Color Color::Green(0, 255, 0, 255);
const Color Color::Blue(0, 0, 255, 255);

Color::Color() noexcept
    : r(0), g(0), b(0), a(255)
{
}
Color::Color(const std::uint8_t __r, const std::uint8_t __g, const std::uint8_t __b, const std::uint8_t __a) noexcept
    : r(__r), g(__g), b(__b), a(__a)
{
}