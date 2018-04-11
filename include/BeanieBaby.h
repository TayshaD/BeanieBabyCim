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
     * to be copied, as in the default. Consider the case where one buys from the store. You now have x amount
     * of objects, but the store has y amount of the same object. In total there are still x+y objects.
     */
    BeanieBaby(const BeanieBaby& other_baby, int copies = 1);

    std::string get_name();

    int get_copies();

    double get_price();

    bool is_retired();

    void transfer_copies(BeanieBaby& other_baby, int copies_to_transfer);

    static std::vector<BeanieBaby> All_Babies;

    /**I need a custom == operator because two Beanie Babies are equal when they have the same name and base price, not
     * necessarily when they have the same number of copies.
     * @param other_baby the baby to compare to
     * @return whether the two babies are equal
     */
    bool operator==(const BeanieBaby& other_baby) const;

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
