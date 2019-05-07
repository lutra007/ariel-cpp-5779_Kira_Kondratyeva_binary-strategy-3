#pragma once
#include <string>

namespace bullpgia {
    class Chooser {
        public:
            virtual ~Chooser() = default;
            virtual std::string choose(uint length) = 0;
    };
}
