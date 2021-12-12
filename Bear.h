//
// Created by rhy on 13.12.2021.
//

#ifndef HW5__BEAR_H_
#define HW5__BEAR_H_
#include "hive.h"
#include <iostream>
#include <mutex>

std::mutex m;

[[noreturn]] void bearFunc(Hive *hive) {
    while (true) {
        if (hive->amount_of_honey >= 15) {
            {
                std::lock_guard<std::mutex> guard(m);
                if (hive->bees_inside < 3) {
                    std::cout << "Bear stole " << hive->amount_of_honey << " honey." << std::endl;
                    hive->amount_of_honey = 0;
                } else {
                    std::cout << "Bear tried to steal honey but was bitten." << std::endl;
                    std::this_thread::sleep_for(std::chrono::seconds(2));
                }
            }
        }
    }
}
#endif //HW5__BEAR_H_
