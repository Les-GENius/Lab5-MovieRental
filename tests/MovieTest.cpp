#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <tests/mock/MockMovieState.h>

#include <Movie.h>

TEST(RegularMovieTest, GetPrice){

    MockMovieStateRegular mock;

    EXPECT_CALL(mock, getPrice(1)).WillRepeatedly(testing::Return(2));
    EXPECT_CALL(mock, getPrice(2)).WillRepeatedly(testing::Return(2));
    EXPECT_CALL(mock, getPrice(3)).WillRepeatedly(testing::Return(3.5));

    Movie movie = Movie("Regular Movie", &mock);

    ASSERT_EQ(movie.getPrice(1), 2);
    ASSERT_EQ(movie.getPrice(2), 2);
    ASSERT_EQ(movie.getPrice(3), 3.5);
}

TEST(RegularMovieTest, GetFrequentRenterPoints){

    MockMovieStateRegular mock;

    EXPECT_CALL(mock, getBonusRenterPoints(1)).WillRepeatedly(testing::Return(0));
    EXPECT_CALL(mock, getBonusRenterPoints(2)).WillRepeatedly(testing::Return(0));
    EXPECT_CALL(mock, getBonusRenterPoints(3)).WillRepeatedly(testing::Return(0));

    Movie movie = Movie("Regular Movie", &mock);

    ASSERT_EQ(movie.getFrequentRenterPoints(1), 1);
    ASSERT_EQ(movie.getFrequentRenterPoints(2), 1);
    ASSERT_EQ(movie.getFrequentRenterPoints(3), 1);
}


TEST(ChildrenMovieTest, GetPrice){
    MockMovieStateChildren mock;

    EXPECT_CALL(mock, getPrice(1)).WillRepeatedly(testing::Return(1.5));
    EXPECT_CALL(mock, getPrice(2)).WillRepeatedly(testing::Return(1.5));
    EXPECT_CALL(mock, getPrice(4)).WillRepeatedly(testing::Return(3));

    Movie movie = Movie("Children Movie", &mock);
    ASSERT_EQ(movie.getPrice(1), 1.5);
    ASSERT_EQ(movie.getPrice(2), 1.5);
    ASSERT_EQ(movie.getPrice(4), 3);
}

TEST(ChildrenMovieTest, GetFrequentRenterPoints){

    MockMovieStateChildren mock;

    EXPECT_CALL(mock, getBonusRenterPoints(1)).WillRepeatedly(testing::Return(0));
    EXPECT_CALL(mock, getBonusRenterPoints(2)).WillRepeatedly(testing::Return(0));
    EXPECT_CALL(mock, getBonusRenterPoints(4)).WillRepeatedly(testing::Return(0));

    Movie movie = Movie("Children Movie", &mock);

    ASSERT_EQ(movie.getFrequentRenterPoints(1), 1);
    ASSERT_EQ(movie.getFrequentRenterPoints(2), 1);
    ASSERT_EQ(movie.getFrequentRenterPoints(4), 1);
}


TEST(NewReleaseMovieTest, GetPrice){

    MockMovieStateChildren mock;

    EXPECT_CALL(mock, getPrice(1)).WillRepeatedly(testing::Return(3));
    EXPECT_CALL(mock, getPrice(2)).WillRepeatedly(testing::Return(6));
    EXPECT_CALL(mock, getPrice(3)).WillRepeatedly(testing::Return(9));

    Movie movie = Movie("New Release Movie", &mock);

    ASSERT_EQ(movie.getPrice(1), 3);
    ASSERT_EQ(movie.getPrice(2), 6);
    ASSERT_EQ(movie.getPrice(3), 9);
}

TEST(NewReleaseMovieTest, GetFrequentRenterPoints){

    MockMovieStateChildren mock;

    EXPECT_CALL(mock, getBonusRenterPoints(1)).WillRepeatedly(testing::Return(0));
    EXPECT_CALL(mock, getBonusRenterPoints(2)).WillRepeatedly(testing::Return(1));
    EXPECT_CALL(mock, getBonusRenterPoints(3)).WillRepeatedly(testing::Return(1));

    Movie movie = Movie("New Release Movie", &mock);

    ASSERT_EQ(movie.getFrequentRenterPoints(1), 1);
    ASSERT_EQ(movie.getFrequentRenterPoints(2), 2);
    ASSERT_EQ(movie.getFrequentRenterPoints(3), 2);
}
