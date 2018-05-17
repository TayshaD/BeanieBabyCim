//
// Created by taja on 3/28/18.
//

#ifndef BEANIEBABYSIM_LOCATION_H
#define BEANIEBABYSIM_LOCATION_H

#include <string>
#include <vector>
#include <Context.h>

class Location : public Context {
public:
    void set_local_time(int time) {local_time_ = time;}

    virtual void AdvanceTime(int delta_time) = 0;

};
#endif //BEANIEBABYSIM_LOCATION_H

