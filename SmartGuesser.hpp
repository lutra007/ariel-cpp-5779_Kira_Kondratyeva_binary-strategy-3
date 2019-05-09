#pragma once
#include <set>
#include "Guesser.hpp"
#include "calculate.hpp"

namespace bullpgia {
    class SmartGuesser: public Guesser {
         public:
         std::string guess() override;
         void startNewGame(int len) override;
         void learn(std::string reply) override;

         private:
         int random_number = 0;
         int ii = 0;
         std::string last_guess;
         std::set <std::string> candidates;
         std::set <std::string> all_candidates;
    };
}
