#include "SmartGuesser.hpp"
#include <iostream>
#include <map>

namespace bullpgia {
    void SmartGuesser::startNewGame(int len) {
        length = len;
        candidates.clear();
        
        int start = 1;
        for (int i=0; i<(len-1); ++i) {
            start *= 10;
        }

        int end = start*10;
        for (int i = start; i<end; ++i) {
            candidates.insert(std::to_string(i));
        }

        all_candidates = candidates;        
    }

    std::string SmartGuesser::guess() {
	std::string r="";

        std::set <std::string> knut_candidates;
        int knut_minimax_score = 0;

        std::map <std::string,int> record;
        int min_score = 0;
        for (const auto& check_guess : all_candidates) {
            std::cout << check_guess << std::endl;
            record.clear();
            for (const auto& candidate : candidates) {
                std::string check = calculateBullAndPgia (candidate, check_guess);
                record[check]++;
            }
            
            min_score = candidates.size();
            for (const auto& [check,check_score] : record) {
                if (check_score < min_score) {
                    min_score = check_score;
                }
            }
            
            if (min_score == knut_minimax_score) {
                knut_candidates.insert(check_guess);
            } else if (min_score > knut_minimax_score) {
                knut_minimax_score = min_score;
                knut_candidates.clear();
                knut_candidates.insert(check_guess);
            }
        }

        for (const auto& pick_guess : knut_candidates) {
            if (candidates.count(pick_guess) == 1) {
                r = pick_guess;
                break;
            } else {
                r = pick_guess;
            }
        }

        last_guess = r;
	return r;
    }

    void SmartGuesser::learn(std::string reply) {
        std::set <std::string> candidates_copy = candidates;
        for (const auto& candidate : candidates_copy) {
            std::string check = calculateBullAndPgia (candidate, last_guess);
            if (check != reply) {
                candidates.erase(candidate);
            }
        }
    }
}
