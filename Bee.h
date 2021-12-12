//
// Created by rhy on 09.12.2021.
//

#ifndef HW5__BEE_H_
#define HW5__BEE_H_

#include "rnd.h"
#include "hive.h"
#include <thread>
#include <mutex>

[[noreturn]] void beeFunc(Hive *hive, int i) {
    while (true) {
        srand(static_cast<unsigned int>(time(0)));
        if (hive->bees_inside > 0) {
            hive->bees_inside--;
            std::this_thread::sleep_for(std::chrono::milliseconds (Random(1, 2000)));
            hive->bees_inside++;
            if (hive->amount_of_honey < 30) {
                hive->amount_of_honey++;
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(Random(1, 2000)));
        }
    }
}

#endif //HW5__BEE_H_
