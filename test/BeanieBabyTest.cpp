#include <BeanieBaby.h>
#include "catch.hpp"

TEST_CASE("Loading data from url") {
   std::string url_text = LoadBeanieBabyData();
   REQUIRE(!url_text.empty());
}

TEST_CASE("Parsing beanie baby data from text") {
   std::string raw_text = LoadBeanieBabyData();
   std::vector<BeanieBaby> babies = ParseBeanieData(raw_text);

   SECTION("All baby objects were loaded") {
      REQUIRE(babies.size() == 45);
   }
}

TEST_CASE("Copying a BeanieBaby object doesn't copy the copies_ field") {
    BeanieBaby example_baby("Iggy Example", 16);

    SECTION("Specifying valid number of copies creates duplicate with specified number of copies") {

    }

    SECTION("Specifying an invalid number of copies creates duplicate with default number of copies") {
        SECTION("# of copies > original object results in copy.copies_ = original copies_ field") {}
        SECTION("# copies < 0 results in copies_ = 1") {}
    }

    SECTION("Not specifying any # of copies results in copies_ = 1") {}
}

TEST_CASE("Comparison operator does not compare the copies_ field") {
    BeanieBaby example_baby("Iggy example", 16);
    BeanieBaby other_baby("Iggy example", 5);

    REQUIRE(example_baby == other_baby);
}

TEST_CASE("<< operator prints nicely_formatted string") {
    BeanieBaby example_baby("Iggy Example", 16);
    std::ostringstream output;
    output << example_baby;
    REQUIRE(output.str() == "Iggy Example is a Beanie Baby worth $5.");
}