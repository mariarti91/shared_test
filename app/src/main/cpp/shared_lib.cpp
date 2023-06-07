#include "Shared.h"

using namespace std::string_literals;

namespace test::lib::shared
{

namespace
{

static const std::vector<std::vector<std::string>> table = {
    {"lib1"s, "shared"s},
    {"lib2"s, "shared"s},
};

}

std::vector<std::string> get_data(int id)
{
    if (id < table.size()) return table[id];
    return {};
}

} // namespace test::lib::shared