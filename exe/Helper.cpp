#include "Helper.h"
#include <optional>

std::optional<int> getValue() noexcept { return std::optional<int>(42); }
std::optional<std::string> getString() noexcept { return std::nullopt; }
std::string getAString() noexcept { return std::string("suh dude"); }

