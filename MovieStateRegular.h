#ifndef LAB05_MOVIESTATEREGULAR_H
#define LAB05_MOVIESTATEREGULAR_H

#include <MovieState.h>

class MovieStateRegular: public MovieState{

public:
    double getPrice(int nbDays) override{
        return 0;
    }

    int getRenterPoints(int nbDays) override {
        return 0;
    }


};

#endif //LAB05_MOVIESTATEREGULAR_H
