#include <BeanieBaby.h>
#include "catch.hpp"

TEST_CASE("Loading data from url") {
   std::string json_url = "http://www.json-generator.com/api/json/get/ckqOcjuMwO?indent=2";
   std::string url_text = LoadBeanieBabyData(json_url);
   REQUIRE(!url_text.empty());
}