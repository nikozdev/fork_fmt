#include <iostream>
#include <string_view>
#include <functional>
#include <unordered_map>
#include <fmt/format.h>
//forward
typedef struct GLFWwindow GLFWwindow;
//typedef
using tTestKey = std::string_view;
using tTestFun = std::function<int(void)>;
using tTestTab = const std::unordered_map<tTestKey, tTestFun>;
using tTestRef = tTestTab::const_iterator;
//actions
int main(int vArgC, char **vArgV)
{
  if (vArgC == 3 ? (std::string_view(vArgV[1]) == "test") : 0)
  {
    extern tTestTab vTestTab;
    tTestRef vTestRef = vTestTab.find(vArgV[2]);
    if (vTestRef == vTestTab.end())
    {
      return EXIT_FAILURE;
    }
    else
    {
      fmt::println("{}=", vTestRef->first);
      auto vCode = vTestRef->second();
      fmt::println("={}", vTestRef->first);
      return vCode;
    }
  }
  else
  {
    std::copy(
      &vArgV[0],
      &vArgV[vArgC],
      std::ostream_iterator<char*>(std::cout, "\n")
    );
  }
  return EXIT_SUCCESS;
}//main
tTestTab vTestTab = {
  { "HelloWorld",
    []()
    {
      fmt::println(stdout, "HelloWorld");
      return EXIT_SUCCESS;
    }
  },//HelloWorld
};//vTestTab
