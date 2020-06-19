#ifndef LAB05_MOCKMOVIE_H
#define LAB05_MOCKMOVIE_H

#include <gmock/gmock.h>

#include <tests/mock/MockMovieState.h>

#include <Movie.h>
#include <MovieStateRegular.h>

class MockMovie : public Movie {
public:
    MockMovie(const std::string& name, MovieState* state) : Movie(name, state) {}

    MOCK_METHOD(double, getPrice, (int nbDays));
    MOCK_METHOD(std::string, getTitle, ());
    MOCK_METHOD(int, getFrequentRenterPoints, (int nbDays));
};

#endif //LAB05_MOCKMOVIE_H
