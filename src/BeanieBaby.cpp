#include <BeanieBaby.h>

BeanieBaby::BeanieBaby() : name_(""), base_price_(5), copies_(1) {};

BeanieBaby::BeanieBaby(std::string name, int copies = 1, double base_price = 5) : name_(name),
                                                                                  copies_(copies),
                                                                                  base_price_(base_price){};

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
     auto parsed_json = json::parse(raw_json.c_str());


     return babies;
 }