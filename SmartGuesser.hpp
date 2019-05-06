#pragma once
#include "Guesser.hpp"
#include "calculate.hpp"

namespace bullpgia {
    class SmartGuesser: public Guesser {
         public:
         std::string guess() override;
    };
}
