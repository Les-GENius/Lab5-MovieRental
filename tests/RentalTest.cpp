#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <tests/mock/MovieMock.h>

#include <Rental.h>

TEST(Rental, TestGetPrice) {

    MockMovie mock;

    EXPECT_CALL(mock, getPrice(3)).WillRepeatedly(testing::Return(2));

    ASSERT_EQ(Rental(mock, 3).getPrice(), 3.5);
}

TEST(Rental, TestGetRenterPoints) {

    MockMovie mock;

    EXPECT_CALL(mock, getFrequentRenterPoints(3)).WillRepeatedly(testing::Return(2));

    ASSERT_EQ(Rental(mock, 3).getRenterPoints(), 1);
}