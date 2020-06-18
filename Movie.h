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
    int getFrequentRenterBonusPoints(int nbDays) const;

private:

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
getFrequentRenterBonusPoints(int nbDays) const { return _state->getRenterPoints(nbDays);}



inline std::string Movie::
getTitle() const { return _title; }

#endif // MOVIE_H