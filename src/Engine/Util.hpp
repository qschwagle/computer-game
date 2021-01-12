#include <array>

template <typename A, std::size_t N>
constexpr std::size_t lengthof(T (&)[N])
{
  return N;
}
