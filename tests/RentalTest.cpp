#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <tests/mock/MockMovie.h>

#include <Rental.h>

TEST(RentalTest, GetPrice) {
    MockMovieStateRegular state;
    EXPECT_CALL(state, getPrice(3)).WillRepeatedly(testing::Return(3.5));

    MockMovie mock("Super Mocked Movie", &state);
    EXPECT_CALL(mock, getPrice(3)).WillRepeatedly(testing::Return(2));

    ASSERT_EQ(Rental(mock, 3).getPrice(), 3.5);
}

TEST(RentalTest, GetRenterPoints) {
    MockMovieStateNewRelease state;
    EXPECT_CALL(state, getBonusRenterPoints(3)).WillOnce(testing::Return(1));

    MockMovie mock("Super Mocked Movie", &state);
    EXPECT_CALL(mock, getFrequentRenterPoints(3)).WillRepeatedly(testing::Return(2));
    ASSERT_EQ(Rental(mock, 3).getRenterPoints(), 2);
}