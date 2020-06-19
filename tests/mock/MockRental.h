#ifndef LAB05_MOCKRENTAL_H
#define LAB05_MOCKRENTAL_H

#include <gmock/gmock.h>

#include <Rental.h>

class MockRental : public Rental {
public:
    MockRental(const Movie& movie, int nbDays) : Rental(movie, nbDays) {}

    MOCK_METHOD(std::string, getMovieTitle, ());
    MOCK_METHOD(double, getPrice, ());
    MOCK_METHOD(int, getRenterPoints, ());
};

#endif //LAB05_MOCKRENTAL_H
