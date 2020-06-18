#include <gtest/gtest.h>
#include <Movie.h>
#include <MovieStateRegular.h>
#include <MovieStateChildren.h>
#include <MovieStateNewRelease.h>

TEST(RegularMovie, getPrice){
    Movie movie = Movie("Regular Movie", new MovieStateRegular());

    ASSERT_EQ(movie.getPrice(1), 2);
    ASSERT_EQ(movie.getPrice(2), 2);
    ASSERT_EQ(movie.getPrice(3), 3.5);
}

TEST(ChildrenMovie, getPrice){
    Movie movie = Movie("Children Movie", new MovieStateChildren());

    ASSERT_EQ(movie.getPrice(1), 1.5);
    ASSERT_EQ(movie.getPrice(2), 1.5);
    ASSERT_EQ(movie.getPrice(4), 3);
}

TEST(NewReleaseMovie, getPrice){
    Movie movie = Movie("New Release Movie", new MovieStateNewRelease());

    ASSERT_EQ(movie.getPrice(1), 3);
    ASSERT_EQ(movie.getPrice(2), 6);
    ASSERT_EQ(movie.getPrice(3), 9);
}
