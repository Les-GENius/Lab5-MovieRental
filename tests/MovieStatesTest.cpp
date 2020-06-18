#include <gtest/gtest.h>
#include <MovieStateRegular.h>
#include <MovieStateChildren.h>
#include <MovieStateNewRelease.h>

TEST(MovieStateRegular, getPrice){

    MovieStateRegular movieStateRegular;

    ASSERT_EQ(movieStateRegular.getPrice(1), 2);
    ASSERT_EQ(movieStateRegular.getPrice(2), 2);
    ASSERT_EQ(movieStateRegular.getPrice(3), 3.5);
}

TEST(MovieStateRegular, getRenterPoints){

    MovieStateRegular movieStateRegular;

    ASSERT_EQ(movieStateRegular.getRenterPoints(1), 1);
    ASSERT_EQ(movieStateRegular.getRenterPoints(2), 1);
}

TEST(MovieStateChildren, getPrice){

    MovieStateChildren movieStateChildren;

    ASSERT_EQ(movieStateChildren.getPrice(1), 1.5);
    ASSERT_EQ(movieStateChildren.getPrice(2), 1.5);
    ASSERT_EQ(movieStateChildren.getPrice(4), 3);
}

TEST(MovieStateChildren, getRenterPoints){

    MovieStateChildren movieStateChildren;

    ASSERT_EQ(movieStateChildren.getRenterPoints(1), 1);
    ASSERT_EQ(movieStateChildren.getRenterPoints(2), 1);
}

TEST(MovieStateNewRelease, getPrice){

    MovieStateNewRelease movieStateNewRelease;

    ASSERT_EQ(movieStateNewRelease.getPrice(1), 3);
    ASSERT_EQ(movieStateNewRelease.getPrice(2), 6);
    ASSERT_EQ(movieStateNewRelease.getPrice(4), 12);
}

TEST(MovieStateNewRelease, getRenterPoints){

    MovieStateNewRelease movieStateNewRelease;

    ASSERT_EQ(movieStateNewRelease.getRenterPoints(1), 1);
    ASSERT_EQ(movieStateNewRelease.getRenterPoints(3), 2);
}