

#ifndef LAB05_MOVIESTATENEWRELEASE_H
#define LAB05_MOVIESTATENEWRELEASE_H
#include <MovieState.h>

class MovieStateNewRelease: public MovieState{

public:
    double getPrice(int nbDays) override{
        return nbDays * 3;
    }

    int getRenterPoints(int nbDays) override {
        int point = 1;
        // check if renter is eligeable for a bonus
        return (nbDays > 1) ? (point+1) : point;
    }
};
#endif //LAB05_MOVIESTATENEWRELEASE_H
