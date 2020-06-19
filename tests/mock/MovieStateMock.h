#ifndef LAB05_MOVIESTATEMOCK_H
#define LAB05_MOVIESTATEMOCK_H
#include <gmock/gmock.h>

#include <MovieState.h>
#include <MovieStateRegular.h>
#include <MovieStateChildren.h>
#include <MovieStateNewRelease.h>

class MockMovieState : public MovieState {
public:
    MOCK_METHOD(double, getPrice, (int nbDays));
    MOCK_METHOD(int, getBonusRenterPoints, (int nbDays));
};

class MockMovieStateRegular : public MockMovieState {};

class MockMovieStateChildren : public MockMovieState {};

#endif //LAB05_MOVIESTATEMOCK_H
