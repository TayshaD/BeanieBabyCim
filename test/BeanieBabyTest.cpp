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