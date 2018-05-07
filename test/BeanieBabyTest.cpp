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
    bool result;
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

TEST_CASE("transfer_copies shifts copies between objects") {
    BeanieBaby example_baby("Iggy Example", 16);
    BeanieBaby other_example("Ziggy Example", 8);

    SECTION("Valid value") {
        example_baby.transfer_copies(other_example, 8);
        CHECK(example_baby.get_copies() == 8);
        CHECK(other_example.get_copies() == 16);
    }

    SECTION("Value > source copies_") {
        example_baby.transfer_copies(other_example, 17);
        CHECK(example_baby.get_copies() == 0);
        CHECK(other_example.get_copies() == 24);
    }
}

TEST_CASE("Calculate total babies returns correct number") {
    BeanieBaby example("Iggy Example", 3);
    std::vector<BeanieBaby> example_baby;
    example_baby.push_back(example);
    std::cout << CalculateTotalBabies(example_baby);
}

TEST_CASE("Making copies functions logically") {
    BeanieBaby example("Iggs", 16);
    BeanieBaby result;

    SECTION("Valid num of copies") {
        example.make_copies(8, result);
        REQUIRE(result.get_copies() == 8);
    }

    SECTION("Specifying num of copies > available copies results in all copies  ") {
        example.make_copies(17, result);
        REQUIRE(result.get_copies() == 16);
    }
    
    SECTION("Specifying num of copies < 0 results in no copies being made") {
        example.make_copies(-1, result);
        REQUIRE(result.get_copies() == 0);
    }

}