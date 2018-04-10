#include <BeanieBaby.h>
#include "catch.hpp"

TEST_CASE("Loading data from url") {
   std::string url_text = LoadBeanieBabyData();
   REQUIRE(!url_text.empty());
}

TEST_CASE("Parsing beanie baby data from text") {

}