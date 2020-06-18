#ifndef LAB05_MOVIESTATECHILDREN_H
#define LAB05_MOVIESTATECHILDREN_H

#include <MovieState.h>

class MovieStateChildren: public MovieState{

public:
    double getPrice(int nbDays) override {
        double amount = 1.5;
        if (nbDays > 3) {
            amount += (nbDays - 3) * 1.5;
        }

        return amount;
    }

    int getRenterPoints(int nbDays) override {
        return 0;
    }
};

#endif //LAB05_MOVIESTATECHILDREN_H
