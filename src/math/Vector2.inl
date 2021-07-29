#include "Vector2.hpp"

template<typename Type>
Vector2<Type>::Vector2()
{
}
template<typename Type>
Vector2<Type>::Vector2(const Type __x, const Type __y)
  : x(__x), y(__y)
{
}


template<typename Type>
inline bool operator==(const Vector2<Type> &left, const Vector2<Type> &right) noexcept
{
  return left.x == right.x && left.y == right.y;
}
template<typename Type>
inline bool operator!=(const Vector2<Type> &left, const Vector2<Type> &right) noexcept
{
  return left.x != right.x && left.y != right.y;
}