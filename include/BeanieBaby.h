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
     *
     * Use case: "stocking" user inventory or market inventory with beanie babies without modifying global list of
     * babies or losing count of how many total babies are available overall (can look up original object's copies_)
     */
    BeanieBaby(const BeanieBaby& other_baby, int copies = 1);

    std::string get_name();

    int get_copies();

    double get_price();

    bool is_retired();

    void set_market_value(double market_value);

    /**Transfers copies from this baby to the other baby. Use case: consider a customer purchasing 3 babies from
     * a store that had 8 of those on sell. Now the store has 5 of those beanie babies, and that customer has taken 3.
     * There are 8 total copies either way.*/
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
     * @return modified output stream
     */
    friend std::ostream& operator<<(std::ostream&, const BeanieBaby& baby);
};

/**
 * (Sub-optimal) method to return an optional reference to a BeanieBaby parameter. The function actually returns
 * true or false depending on whether the target baby is found in the given collection, but if the baby is found the
 * result parameter will be updated to refer to the found object.
 * @param babies Collection of BeanieBaby objects
 * @param name name of BeanieBaby object
 * @param result result, will only be updated if search is successful
 * @return
 */
bool FindBabyByName(const std::vector<BeanieBaby>& babies, std::string name, BeanieBaby& target);

/**Method to read file from url and return string*/
std::string LoadBeanieBabyData();

/**Method to parse data from provided string and return BeanieBaby objects*/
std::vector<BeanieBaby>  ParseBeanieData(std::string json_string);

#endif //BEANIEBABYSIM_BEANIEBABY_H
