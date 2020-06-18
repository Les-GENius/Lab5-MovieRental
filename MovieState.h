//
// Created by kurisukun on 18.06.20.
//

#ifndef LAB05_MOVIESTATE_H
#define LAB05_MOVIESTATE_H


class MovieState {

public:
    virtual double getPrice(int nbDays) = 0;
    virtual int getBonusRenterPoints(int nbDays) = 0;

};


#endif //LAB05_MOVIESTATE_H
