#include <BeanieBaby.h>

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