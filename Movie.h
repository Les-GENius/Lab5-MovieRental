// Movie.h
#ifndef MOVIE_H
#define MOVIE_H
#include <string>
#include <MovieState.h>



class Movie {
public:
    Movie( const std::string& title, MovieState* state);

    double getPrice(int nbDays) const;
    std::string getTitle() const;
    int getFrequentRenterPoints(int nbDays) const;

private:
    static const int DEFAULT_RENTER_POINT = 1;
    std::string _title;
    MovieState* _state;
};

inline Movie::
Movie( const std::string& title, MovieState* state )
        : _title(title)
        , _state(state)
{}

inline double Movie::
getPrice(int nbDays) const { return _state->getPrice(nbDays); }


inline int Movie::
getFrequentRenterPoints(int nbDays) const { return DEFAULT_RENTER_POINT + _state->getBonusRenterPoints(nbDays);}



inline std::string Movie::
getTitle() const { return _title; }

#endif // MOVIE_H