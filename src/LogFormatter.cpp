#include "LogFormatter.hpp"

#include <algorithm>
#include <ctime>

namespace foo {

std::string LogFormatter::getTimeStamp() {
  const auto time = std::time(nullptr);
  std::string str = std::string{std::asctime(std::localtime(&time))};
  str.erase(std::remove(str.begin(), str.end(), '\n'), str.end());

  return str;
}

} // namespace foo