#include "catch.hpp"

#include "commonex/commonex.h"

#include <vector>

using namespace std;

TEST_CASE("Check assertion"){
    CHECK_THROWS_AS(CHECK_ASSERTION(false), commonex::AssertionError);
    CHECK_NOTHROW(CHECK_ASSERTION(true));
}

TEST_CASE("Check null pointer"){
    CHECK_THROWS_AS(CHECK_NOTNULL(NULL), commonex::NullPointerException);

    int var;
    CHECK_NOTHROW(CHECK_NOTNULL(&var));
}

TEST_CASE("Check out of bounds"){
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    CHECK_THROWS_AS(CHECK_BOUNDS(v, 3), commonex::IndexOutOfBoundsException);
    CHECK_THROWS_AS(CHECK_BOUNDS(v, -1), commonex::IndexOutOfBoundsException);
    CHECK_NOTHROW(CHECK_BOUNDS(v, 0));
}
