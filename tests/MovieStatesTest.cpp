#include <gtest/gtest.h>
#include <MovieStateRegular.h>
#include <MovieStateChildren.h>
#include <MovieStateNewRelease.h>

TEST(MovieStateRegularTest, GetPrice){

    MovieStateRegular movieStateRegular;

    ASSERT_EQ(movieStateRegular.getPrice(1), 2);
    ASSERT_EQ(movieStateRegular.getPrice(2), 2);
    ASSERT_EQ(movieStateRegular.getPrice(3), 3.5);
}

TEST(MovieStateRegularTest, GetRenterPoints){

    MovieStateRegular movieStateRegular;

    ASSERT_EQ(movieStateRegular.getBonusRenterPoints(1), 0);
    ASSERT_EQ(movieStateRegular.getBonusRenterPoints(2), 0);
}

TEST(MovieStateChildrenTest, GetPrice){

    MovieStateChildren movieStateChildren;

    ASSERT_EQ(movieStateChildren.getPrice(1), 1.5);
    ASSERT_EQ(movieStateChildren.getPrice(2), 1.5);
    ASSERT_EQ(movieStateChildren.getPrice(4), 3);
}

TEST(MovieStateChildrenTest, GetRenterPoints){

    MovieStateChildren movieStateChildren;

    ASSERT_EQ(movieStateChildren.getBonusRenterPoints(1), 0);
    ASSERT_EQ(movieStateChildren.getBonusRenterPoints(2), 0);
}

TEST(MovieStateNewReleaseTest, GetPrice){

    MovieStateNewRelease movieStateNewRelease;

    ASSERT_EQ(movieStateNewRelease.getPrice(1), 3);
    ASSERT_EQ(movieStateNewRelease.getPrice(2), 6);
    ASSERT_EQ(movieStateNewRelease.getPrice(4), 12);
}

TEST(MovieStateNewReleaseTest, GetRenterPoints){

    MovieStateNewRelease movieStateNewRelease;

    ASSERT_EQ(movieStateNewRelease.getBonusRenterPoints(1), 0);
    ASSERT_EQ(movieStateNewRelease.getBonusRenterPoints(3), 1);
}