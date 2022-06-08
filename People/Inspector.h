#ifndef BUFFET_INSPECTOR_H
#define BUFFET_INSPECTOR_H

#include <string>

#include "Human.h"

class Inspector : public Human
{
public:
    Inspector(const std::string&, const std::string&, const std::string&, const std::string&);
};


#endif //BUFFET_INSPECTOR_H
