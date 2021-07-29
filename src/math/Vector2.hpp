#ifndef VECTOR2_H
#define VECTOR2_H

template <typename Type>
class Vector2
{
  public:
    Vector2();
    explicit Vector2(const Type, const Type);

    Type x, y;
  private:
};

#include "Vector2.inl"

typedef Vector2<float>        Vector2f;
typedef Vector2<unsigned int> Vector2u;
typedef Vector2<int>          Vector2i;

template<typename Type>
inline bool operator==(const Vector2<Type>&, const Vector2<Type>&) noexcept;
template<typename Type>
inline bool operator!=(const Vector2<Type>&, const Vector2<Type>&) noexcept;

#endif