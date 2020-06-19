// Rental.h
#ifndef RENTAL_H
#define RENTAL_H
#include "Movie.h"

class Rental {
public:
    Rental( const Movie& movie, int daysRented );

    Rental();

    const std::string getMovieTitle() const;

    virtual double getPrice() const {
        return _movie.getPrice(_daysRented);
    }

    virtual int getRenterPoints() const {
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

inline const std::string Rental::
getMovieTitle() const { return _movie.getTitle(); }

#endif // RENTAL_H