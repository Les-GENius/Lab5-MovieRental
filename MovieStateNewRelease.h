

#ifndef LAB05_MOVIESTATENEWRELEASE_H
#define LAB05_MOVIESTATENEWRELEASE_H
#include <MovieState.h>

class MovieStateNewRelease: public MovieState{

public:
    virtual double getPrice(int nbDays) override{
        return nbDays * 3;
    }

    virtual int getBonusRenterPoints(int nbDays) override {
        return nbDays > 1 ? 1 : 0;
    }
};
#endif //LAB05_MOVIESTATENEWRELEASE_H
