#include <iostream>
#include <fstream>
#include "hive.h"
#include <thread>
#include "Bee.h"
#include "Bear.h"
#include <cstring>

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cout << "incorrect command line, please enter correct parameters(-f filepath, -n <num of bees>)";
        return 0;
    }
    int num_of_bees;
    if (!strcmp(argv[1], "-n")) {
        num_of_bees = atoi(argv[2]);
        if (num_of_bees < 1 || num_of_bees > 50) {
            std::cout << "Incorrect num of bees, it should be 1 <= num <= 30";
            return 0;
        }
    } else if (!strcmp(argv[1], "-f")) {
        std::ifstream ifst(argv[2]);
        ifst >> num_of_bees;
        if (num_of_bees < 1 || num_of_bees > 50) {
            std::cout << "Incorrect num of bees, it should be 1 <= num <= 30";
            return 0;
        }
    } else {
        std::cout << "incorrect command line, please enter correct parameters(-f filepath, -n <num of bees>)";
        return 0;
    }

    Hive *hive = new Hive();

    hive->bees_inside = num_of_bees;

    for (int i = 0; i < num_of_bees; ++i) {
        std::thread bee(beeFunc, hive, i);
        bee.detach();
    }
    std::thread bear(bearFunc, hive);
    bear.join();
}
