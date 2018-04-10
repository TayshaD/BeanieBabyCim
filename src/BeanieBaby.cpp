#include <BeanieBaby.h>

/**
 * Loads BeanieBaby data from provided url as a string.
 * @param url url to read data from.
 * @return string with url contents (i.e. json) or empty string on load fail
 */
std::string LoadBeanieBabyData(std::string url) {
    auto request = cpr::Url(url);
    auto response = cpr::Get(request);
    if (response.status_code == 200) {
        return response.text;
    }

    return "";
}