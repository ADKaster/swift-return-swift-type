#pragma once

#include "Color.h"
#include "shlib-Swift.h"
#include <optional>

std::optional<int> getValue() noexcept;
std::optional<std::string> getString() noexcept;
std::string getAString() noexcept;

