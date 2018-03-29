//
// Created by taja on 3/28/18.
//

#ifndef BEANIEBABYSIM_LOCATION_H
#define BEANIEBABYSIM_LOCATION_H

#include <string>
#include <vector>

class Location {
protected:
    int local_time_;

public:
    void set_local_time(int time) {local_time_ = time;}

    int get_local_time() {return local_time_;}

    virtual void AdvanceTime(int delta_time) = 0;

    virtual std::vector<string> ExecuteCommand(std::string command) = 0;

    virtual std::vector<string> Help() = 0;
};
#endif //BEANIEBABYSIM_LOCATION_H

