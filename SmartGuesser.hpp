#pragma once
#include "Guesser.hpp"

namespace bullpgia {
    class SmartGuesser: public Guesser {
         public:
         std::string guess() override;
    };
}
