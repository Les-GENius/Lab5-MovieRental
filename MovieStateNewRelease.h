

#ifndef LAB05_MOVIESTATENEWRELEASE_H
#define LAB05_MOVIESTATENEWRELEASE_H
#include <MovieState.h>

class MovieStateNewRelease: public MovieState{

public:
    double getPrice(int nbDays) override{
        return nbDays * 3;
    }

    int getBonusRenterPoints(int nbDays) override {
        return nbDays > 1 ? 1 : 0;
    }
};
#endif //LAB05_MOVIESTATENEWRELEASE_H
