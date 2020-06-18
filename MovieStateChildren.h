#ifndef LAB05_MOVIESTATECHILDREN_H
#define LAB05_MOVIESTATECHILDREN_H

#include <MovieState.h>

class MovieStateChildren: public MovieState{

public:
    double getPrice(int nbDays) override{
        return 0;
    }

    int getRenterPoints(int nbDays) override {
        return 0;
    }
};

#endif //LAB05_MOVIESTATECHILDREN_H
