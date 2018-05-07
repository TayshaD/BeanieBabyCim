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
    double market_price_;

    /**How many copies of this baby exist in the sim world.*/
    int copies_;

    /**When a baby is retired, it is no longer being produced, and its market value increases*/
    bool retired_ = false;

public:
    explicit BeanieBaby();

    explicit BeanieBaby(std::string name, int copies, double base_price = 5);

    std::string get_name() const;

    int get_copies() const ;

    double get_price() const;

    bool is_retired() const;

    void set_market_value(double market_value);

    /**
     * Makes a duplicate object from the input baby with the specified number of copies rather than duplicating the copies field.
     * @param original_baby
     * @param make_copies
     * @return
     */
    void make_copies(int copies_to_make, BeanieBaby& output_baby);

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
 * @param target result, will only be updated if search is successful
 * @return
 */
bool FindBabyByName(const std::vector<BeanieBaby>& babies, std::string name, BeanieBaby& target);

/**
 * Counts the  total number of babies within a given collection based on how many copies of each baby exists, NOT based
 * on the amount of Baby objects the collection contains.
 * @param babies vector of Beaniebaby objects
 * @return aggregation of baby copies_
 */
int CalculateTotalBabies(const std::vector<BeanieBaby>& babies);
/**Method to read file from url and return string*/
std::string LoadBeanieBabyData();

/**Method to parse data from provided string and return BeanieBaby objects*/
std::vector<BeanieBaby>  ParseBeanieData(std::string json_string);

#endif //BEANIEBABYSIM_BEANIEBABY_H
