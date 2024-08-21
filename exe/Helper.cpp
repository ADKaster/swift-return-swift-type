
#include "Helper.h"

swift::Optional<int> getValue() noexcept { return swift::Optional<int>::some(42); }
swift::Optional<swift::String> getString() noexcept { return swift::Optional<swift::String>::none(); }

