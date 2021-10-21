#include <catch2/catch.hpp>
extern "C"
{
#include "stuff.h"
}

TEST_CASE("We can add", "[add]")
{
    SECTION("adding shit")
    {
        REQUIRE(add(1, 2) == 3);
    }
}
