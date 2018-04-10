#include <BeanieBaby.h>

BeanieBaby::BeanieBaby() : name_(""), base_price_(5), copies_(1) {};

BeanieBaby::BeanieBaby(std::string name, int copies, double base_price /*=5*/) : name_(name),
                                                                                 copies_(copies),
                                                                                 base_price_(base_price) {};

std::string BeanieBaby::get_name() {
    return this->name_;
}

int BeanieBaby::get_copies() {
    return this->copies_;
}

double BeanieBaby::get_price() {
    return this->market_price_;
}

bool BeanieBaby::is_retired() {
    return this->retired_;
}


/**
 * Loads BeanieBaby data from fixed url to a string
 * @return string with url contents (i.e. json) or empty string on load fail
 */
 std::string LoadBeanieBabyData() {
    std::string json_url = "http://www.json-generator.com/api/json/get/ckqOcjuMwO?indent=2";
    auto request = cpr::Url(json_url);
    auto response = cpr::Get(request);
    if (response.status_code == 200) {
        return response.text;
    }
    return "";
}

/**
 * Parses raw json into BeanieBaby objects
 * @param raw_json json string
 * @return vector of beanie babies
 */
std::vector<BeanieBaby> ParseBeanieData(std::string raw_json) {
    std::vector<BeanieBaby> babies;
    //parses input string to an object constructed with properties defined in raw json string
    auto parsed_json = json::parse(raw_json.c_str());

    for (int json_index = 0; json_index < parsed_json.size(); json_index++) {
         std::string name = parsed_json[json_index]["name"];
         int copies = parsed_json[json_index]["copies"];
         auto base_price = parsed_json[json_index]["base_price"];
         BeanieBaby baby = (base_price != nullptr) ? BeanieBaby(name, copies, base_price) : BeanieBaby(name, copies);
         babies.push_back(baby);
    }

    return babies;
 }

std::vector<BeanieBaby> All_Babies = ParseBeanieData(LoadBeanieBabyData());