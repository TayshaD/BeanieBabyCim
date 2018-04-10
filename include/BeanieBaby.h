#ifndef BEANIEBABYSIM_BEANIEBABY_H
#define BEANIEBABYSIM_BEANIEBABY_H

#include <cpr/cpr.h>
#include <json.hpp>
#include <string>
#include <vector>
#include <iostream>
using json = nlohmann::json;

class BeanieBaby {
    /**Name of the Beanie Baby**/
    static std::string name_;

    /**Starting price of the baby before any adjustments.*/
    double base_price_;

    /**Essentially how valued/sought after this baby is. A value greater than 1 means it's value is greater than its
     * base price, a value lower than 1 means its value has depreciated from the base price*/
    double market_value_ = 1;

    /**The price of the baby after its current market value is taken into account*/
    double market_price_ = base_price_;

    /**How many copies of this baby exist in the sim world.*/
    int copies_;

    /**When a baby is retired, it is no longer being produced, and its market value increases*/
    bool retired_ = false;

public:
    BeanieBaby();

    explicit BeanieBaby(std::string name, int copies = 1, double base_price = 5);
};

/**Method to read file from url and return string*/
std::string LoadBeanieBabyData();

/**Method to parse data from provided string and return BeanieBaby objects*/
std::vector<BeanieBaby>  ParseBeanieData(std::string json_string);

#endif //BEANIEBABYSIM_BEANIEBABY_H
