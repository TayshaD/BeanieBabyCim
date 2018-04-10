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
    std::string name_;

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

    BeanieBaby(std::string name, int copies, double base_price = 5);

    /**Breaking the rule of three/five: I need a custom copy constructor, because in my case I DON'T want every member
     * to be copied, as in the default. Consider the case where one buys
     * @param other_Baby Baby to be copied.
     * @param copies number of copies that should exist of the new baby
     * @return
     */
    friend BeanieBaby& operator=(BeanieBaby& other_baby, const int& copies);

    /**I need a custom == operator because two Beanie Babies are equal when they have the same name and base price, not
     * necessarily when they have the same number of copies.
     * @param other_baby the baby to compare to
     * @return whether the two babies are equal
     */
    friend bool operator==(BeanieBaby& other_baby);

    /**Overloading << operator to allow
     * @param baby
     * @return
     */
    friend std::ostream& operator<<(std::ostream&, const BeanieBaby& baby);
};

/**Method to read file from url and return string*/
std::string LoadBeanieBabyData();

/**Method to parse data from provided string and return BeanieBaby objects*/
std::vector<BeanieBaby>  ParseBeanieData(std::string json_string);

#endif //BEANIEBABYSIM_BEANIEBABY_H
