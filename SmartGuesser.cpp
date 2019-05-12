#include "SmartGuesser.hpp"
#include <cstdlib>
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
        
        for (int i = 0; i<start; ++i) {
            std::string add = std::to_string(i);
            while (add.length() < length) {
                add = "0" + add;
            }
            candidates.insert(add);
        }

        int end = start*10;
        for (int i = start; i<end; ++i) {
            candidates.insert(std::to_string(i));
        }

        all_candidates = candidates;        
    }

    std::string SmartGuesser::guess() {
	std::string r="";
        
        /* std::set <std::string> knut_candidates;
        int knut_minimax_score = 0;

        std::map <std::string,int> record;
        int min_score = 0;
        for (const auto& check_guess : all_candidates) {
            //std::cout << check_guess << std::endl;
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
        } */
        random_number = (std::rand() % candidates.size());
        
        ii = 0;
        for (const auto& candidate : candidates) {
            if (ii == random_number) {
                r = candidate;
                //std::cout << "Chosen: " << r << std::endl;
                break;
            }
            ii++;
        }
        last_guess = r;
	return r;
    }

    void SmartGuesser::learn(std::string reply) {
        int bull, pgia;
        sscanf(reply.c_str(), "%d,%d", &bull, &pgia);
        //std::cout << "\nLast reply: " << reply << "\n";
        std::set <std::string> candidates_copy = candidates;
        for (const auto& candidate : candidates_copy) {
            auto [bull_check, pgia_check] = calculateBullAndPgia2 (candidate, last_guess);
            
            if (bull != bull_check || pgia != pgia_check) {
                candidates.erase(candidate);
            }
        }
        //std::cout << "Reply: " << reply << " Candidates left: " << candidates.size() << std::endl;
    }
}
