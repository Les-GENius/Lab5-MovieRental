// Rental.h
#ifndef RENTAL_H
#define RENTAL_H
#include "Movie.h"

class Rental {
public:
    Rental( const Movie& movie, int daysRented );

    const Movie& getMovie() const;

    double getPrice() const {
        return _movie.getPrice(_daysRented);
    }

    int getRenterPoints() const {
        return _movie.getFrequentRenterPoints(_daysRented);
    }
private:
    Movie _movie;
    int _daysRented;
};

inline Rental::
Rental( const Movie& movie, int daysRented )
        : _movie( movie )
        , _daysRented( daysRented ) {}

inline const Movie& Rental::
getMovie() const { return _movie; }

#endif // RENTAL_H