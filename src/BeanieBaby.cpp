#include <BeanieBaby.h>

BeanieBaby::BeanieBaby() : name_(""), base_price_(5), copies_(1) {};

BeanieBaby::BeanieBaby(std::string name, int copies, double base_price /*=5*/) : name_(name),
                                                                                 copies_(copies),
                                                                                 base_price_(base_price),
                                                                                 market_price_(base_price){};


std::vector<BeanieBaby> All_Babies = ParseBeanieData(LoadBeanieBabyData());

std::string BeanieBaby::get_name() const{
    return this->name_;
}

int BeanieBaby::get_copies() const {
    return this->copies_;
}

double BeanieBaby::get_price() const{
    return this->market_price_;
}

bool BeanieBaby::is_retired() const {
    return this->retired_;
}

void BeanieBaby::set_market_value(double market_value) {
    this->market_value_ = market_value;
    this->market_price_ = base_price_ * market_value;
}

void BeanieBaby::make_copies(int copies_to_make, BeanieBaby& output_baby) {
    if (copies_to_make > this->copies_) {
        copies_to_make = this->copies_;
    } 

    if (copies_to_make < 0) {
        copies_to_make = 0;
    }

    output_baby.copies_ = copies_to_make;
}

void BeanieBaby::transfer_copies(BeanieBaby &other_baby, int copies_to_transfer) {
    if (copies_to_transfer > this->copies_) {
        copies_to_transfer = this->copies_;
    }

    other_baby.copies_ += copies_to_transfer;
    this->copies_ -= copies_to_transfer;
}


std::ostream& operator<<(std::ostream& output_stream, const BeanieBaby& baby) {
    output_stream << baby.name_ << " is a Beanie Baby worth $" << baby.market_price_ << ".";
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

bool FindBabyByName(const std::vector<BeanieBaby>& babies, std::string name, BeanieBaby& target) {
    if (babies.empty() || name.empty()) {
        return false;
    }

    BeanieBaby mock(name, 0);

    for (const auto& baby : babies) {
        if (baby == mock) {
            target = baby;
            return true;
        }
    }

    return false;
}

int CalculateTotalBabies(const std::vector<BeanieBaby>& babies) {
    if (babies.empty()) {
        return 0;
    }

    int total_babies = 0;
    for (const auto& baby : babies) {
        total_babies += baby.get_copies();
    }
    return total_babies;
}
