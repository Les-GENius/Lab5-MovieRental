#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <tests/mock/MovieStateMock.h>

#include <Movie.h>
#include <MovieStateNewRelease.h>

TEST(RegularMovie, TestGetPrice){

    MockMovieStateRegular mock;

    EXPECT_CALL(mock, getPrice(1)).WillRepeatedly(testing::Return(2));
    EXPECT_CALL(mock, getPrice(2)).WillRepeatedly(testing::Return(2));
    EXPECT_CALL(mock, getPrice(3)).WillRepeatedly(testing::Return(3.5));

    Movie movie = Movie("Regular Movie", &mock);

    ASSERT_EQ(movie.getPrice(1), 2);
    ASSERT_EQ(movie.getPrice(2), 2);
    ASSERT_EQ(movie.getPrice(3), 3.5);
}

TEST(RegularMovie, TestGetFrequentRenterPoints){

    MockMovieStateRegular mock;

    EXPECT_CALL(mock, getBonusRenterPoints(1)).WillRepeatedly(testing::Return(0));
    EXPECT_CALL(mock, getBonusRenterPoints(2)).WillRepeatedly(testing::Return(0));
    EXPECT_CALL(mock, getBonusRenterPoints(3)).WillRepeatedly(testing::Return(0));

    Movie movie = Movie("Regular Movie", &mock);

    ASSERT_EQ(movie.getFrequentRenterPoints(1), 1);
    ASSERT_EQ(movie.getFrequentRenterPoints(2), 1);
    ASSERT_EQ(movie.getFrequentRenterPoints(3), 1);
}


TEST(ChildrenMovie, TestGetPrice){
    MockMovieStateChildren mock;

    EXPECT_CALL(mock, getPrice(1)).WillRepeatedly(testing::Return(1.5));
    EXPECT_CALL(mock, getPrice(2)).WillRepeatedly(testing::Return(1.5));
    EXPECT_CALL(mock, getPrice(4)).WillRepeatedly(testing::Return(3));

    Movie movie = Movie("Children Movie", &mock);
    ASSERT_EQ(movie.getPrice(1), 1.5);
    ASSERT_EQ(movie.getPrice(2), 1.5);
    ASSERT_EQ(movie.getPrice(4), 3);
}

TEST(ChildrenMovie, TestGetFrequentRenterPoints){

    MockMovieStateChildren mock;

    EXPECT_CALL(mock, getBonusRenterPoints(1)).WillRepeatedly(testing::Return(0));
    EXPECT_CALL(mock, getBonusRenterPoints(2)).WillRepeatedly(testing::Return(0));
    EXPECT_CALL(mock, getBonusRenterPoints(4)).WillRepeatedly(testing::Return(0));

    Movie movie = Movie("Children Movie", &mock);

    ASSERT_EQ(movie.getFrequentRenterPoints(1), 1);
    ASSERT_EQ(movie.getFrequentRenterPoints(2), 1);
    ASSERT_EQ(movie.getFrequentRenterPoints(4), 1);
}


TEST(NewReleaseMovie, getPrice){
    Movie movie = Movie("New Release Movie", new MovieStateNewRelease());

    ASSERT_EQ(movie.getPrice(1), 3);
    ASSERT_EQ(movie.getPrice(2), 6);
    ASSERT_EQ(movie.getPrice(3), 9);
}

TEST(NewReleaseMovie, getFrequentRenterPoints){
    Movie movie = Movie("New Release Movie", new MovieStateNewRelease());

    ASSERT_EQ(movie.getFrequentRenterPoints(1), 1);
    ASSERT_EQ(movie.getFrequentRenterPoints(2), 2);
    ASSERT_EQ(movie.getFrequentRenterPoints(3), 2);
}
