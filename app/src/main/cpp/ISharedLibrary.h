#pragma once

#include <vector>
#include <string>

namespace test::lib
{

struct ILoadedLibrary
{
    virtual ~ILoadedLibrary() = default;
    virtual std::vector<std::string> get_method_lists() = 0;
};

} // namespace test::lib