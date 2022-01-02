#include "src/allTheIppFiles.hpp"
#include <iostream>
int
main ()
{
  auto test = Something<int>{};
  std::cout << test.some_interface () << std::endl;
}