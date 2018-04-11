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

TEST_CASE("Finding baby by name works reliably") {
    std::vector<BeanieBaby> babies = ParseBeanieData(LoadBeanieBabyData());
    BeanieBaby target;
    bool result = false;
    SECTION("Ideal case, perfectly matching name in predetermined collection") {
        result = FindBabyByName(babies, "Cubbie the Bear", target);
        REQUIRE(result);
        REQUIRE(target.get_name() == "Cubbie the Bear");
    }

    SECTION("Name is case-insensitive") {
        result = FindBabyByName(babies, "cubBiE THE beaR", target);
        REQUIRE(result);
        REQUIRE(target.get_name() == "Cubbie the Bear");
    }

    SECTION("Returns false when baby is not located in list") {
        result = FindBabyByName(babies, "Mrs. Udderly", target);
        REQUIRE_FALSE(result);
    }
    SECTION("Returns false when given name is empty string") {
        result = FindBabyByName(babies, "", target);
        REQUIRE_FALSE(result);
    }
    SECTION("Returns false when provided vector is empty") {
        result = FindBabyByName({}, "Felix the Cat", target);
        REQUIRE_FALSE(result);
    }
}


TEST_CASE("Copying a BeanieBaby object doesn't copy the copies_ field") {
    BeanieBaby example_baby("Iggy Example", 16);

    SECTION("Specifying valid number of copies creates duplicate with specified number of copies") {
        BeanieBaby copy(example_baby, 8);
        CHECK(copy.get_copies() == 8);
        CHECK(example_baby.get_copies() == 16);
    }

    SECTION("Specifying an invalid number of copies creates duplicate with default number of copies") {
        SECTION("# of copies > original object results in copy.copies_ = original copies_ field") {
            BeanieBaby copy(example_baby, 24);
            CHECK(copy.get_copies() == example_baby.get_copies());
        }

        SECTION("# copies < 0 results in copies_ = 0") {
            BeanieBaby copy(example_baby, -4);
            CHECK(copy.get_copies() == 0);
        }
    }

    SECTION("Not specifying any # of copies results in copies_ = 1") {
        BeanieBaby copy(example_baby);
        CHECK(copy.get_copies() == 1);
    }
}

TEST_CASE("Comparison operator does not compare the copies_ field") {
    BeanieBaby example_baby("Iggy example", 16);
    BeanieBaby other_baby("Iggy example", 5);

    REQUIRE(example_baby == other_baby);
}

TEST_CASE("<< operator prints nicely formatted string") {
    BeanieBaby example_baby("Iggy Example", 16);
    std::ostringstream output;
    output << example_baby;
    REQUIRE(output.str() == "Iggy Example is a Beanie Baby worth $5.");
}