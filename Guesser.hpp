#pragma once
#include <string>


namespace bullpgia {
    class Guesser {
         public:
         virtual ~Guesser() = default;
         virtual std::string guess() = 0;

         int length;
         virtual void startNewGame(int len) {
              length = len;
         };
         virtual void learn(std::string reply) {};
    };
}
