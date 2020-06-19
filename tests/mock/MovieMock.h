#ifndef LAB05_MOVIEMOCK_H
#define LAB05_MOVIEMOCK_H

#include <gmock/gmock.h>

#include <Movie.h>
#include <MovieStateRegular.h>

class MockMovie : public Movie {
public:
    MockMovie() : Movie("Super Mocked Movie", new MovieStateRegular) {}
    ~MockMovie() { delete _state; }

    MOCK_METHOD(double, getPrice, (int nbDays));
    MOCK_METHOD(std::string, getTitle, ());
    MOCK_METHOD(int, getFrequentRenterPoints, (int nbDays));
};

#endif //LAB05_MOVIEMOCK_H
