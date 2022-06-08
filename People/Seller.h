#ifndef BUFFET_SELLER_H
#define BUFFET_SELLER_H

#include <string>

#include "Human.h"

class Seller : public Human
{
public:
    Seller(const std::string&, const std::string&, const std::string&, const std::string&);
};


#endif //BUFFET_SELLER_H
