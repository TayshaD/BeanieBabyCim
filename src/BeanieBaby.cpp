#include <BeanieBaby.h>

BeanieBaby::BeanieBaby() : name_(""), base_price_(5), copies_(1) {};

BeanieBaby::BeanieBaby(std::string name, int copies, double base_price /*=5*/) : name_(std::move(name)),
                                                                                 copies_(copies),
                                                                                 base_price_(base_price) {};

/**
 * Copy constructor which creates a duplicate object whose copies_ property is set to copies, rather than the
 * original object's copies_ property
 * @param other_baby baby to create a duplicate object of
 * @param copies # of copies to assign duplicate object
 */
BeanieBaby::BeanieBaby(const BeanieBaby& other_baby, int copies) {
    if (copies > other_baby.copies_) {
        copies = other_baby.copies_;
    } else if (copies < 0) {
        copies = 0;
    }

    this->name_ = other_baby.name_;
    this->base_price_ = other_baby.base_price_;
    this->market_value_ = other_baby.market_value_;
    this->copies_ = copies;
}

std::vector<BeanieBaby> All_Babies = ParseBeanieData(LoadBeanieBabyData());

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

void BeanieBaby::set_market_value(double market_value) {
    this->market_value_ = market_value;
    this->market_price_ = base_price_ * market_value;
}

void BeanieBaby::transfer_copies(BeanieBaby &other_baby, int copies_to_transfer) {
    if (copies_to_transfer > this->copies_) {
        copies_to_transfer = this->copies_;
    }

    other_baby.copies_ += copies_to_transfer;
    this->copies_ -= copies_to_transfer;
}

bool BeanieBaby::operator==(const BeanieBaby& other_baby) const {
    std::string lower_baby_name = this->name_;
    std::string lower_other_name = other_baby.name_;
    std::transform(this->name_.begin(), this->name_.end(), lower_baby_name.begin(), ::tolower);
    std::transform(other_baby.name_.begin(), other_baby.name_.end(), lower_other_name.begin(), ::tolower);
    std::cout << lower_baby_name << " vs " << lower_other_name;
    return (lower_baby_name == lower_other_name);
};

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

