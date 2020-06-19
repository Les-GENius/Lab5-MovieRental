#include <Customer.h>
#include <gtest/gtest.h>

#include <tests/mock/RentalMock.h>
#include <tests/mock/MovieMock.h>

#include <MovieStateRegular.h>
#include <MovieStateChildren.h>
#include <MovieStateNewRelease.h>

TEST(CustomerTest, PlainTextStatementGeneratedCorrectly){

    Customer customer("Olivier");
    customer.addRental( Rental( Movie("Karate Kid", new MovieStateRegular()), 7));
    customer.addRental( Rental( Movie("Avengers: Endgame", new MovieStateNewRelease()), 5));
    customer.addRental( Rental( Movie("Snow White", new MovieStateChildren()), 3 ));

    std::string s = "Rental Record for Olivier\n"
                    "\tKarate Kid\t9.5\n"
                    "\tAvengers: Endgame\t15\n"
                    "\tSnow White\t1.5\n"
                    "Amount owed is 26\n"
                    "You earned 4 frequent renter points";

    ASSERT_EQ(customer.statement(), s);
};


TEST(CustomerTest, GetFrequentRenterPoints) {
    MockMovieStateNewRelease state;
    EXPECT_CALL(state, getBonusRenterPoints(2)).WillOnce(testing::Return(1));

    MockMovie movie("Super Mocked Movie", &state);
    EXPECT_CALL(movie, getFrequentRenterPoints(2)).WillRepeatedly(testing::Return(0));

    MockRental mock(movie, 2);
    EXPECT_CALL(mock, getRenterPoints()).WillRepeatedly(testing::Return(1));

    Customer customer("Bob");
    customer.addRental(mock);

    ASSERT_EQ(customer.getFrequentRenterPoints(), 2);
}

TEST(CustomerTest, GetTotalAmount) {

    MockMovieStateNewRelease newRelease;
    EXPECT_CALL(newRelease, getPrice(2)).WillOnce(testing::Return(6));
    MockMovieStateRegular regular;
    EXPECT_CALL(regular, getPrice(3)).WillOnce(testing::Return(3.5));

    MockMovie movie("Super Mocked Movie", &newRelease);
    EXPECT_CALL(movie, getPrice(2)).WillRepeatedly(testing::Return(6));
    MockMovie movie2("Super Mocked Movie 2 : the revenge", &regular);
    EXPECT_CALL(movie, getPrice(3)).WillRepeatedly(testing::Return(3.5));

    MockRental rental1(movie, 2);
    EXPECT_CALL(rental1, getPrice()).WillRepeatedly(testing::Return(6));
    MockRental rental2(movie2, 3);
    EXPECT_CALL(rental2, getPrice()).WillRepeatedly(testing::Return(3.5));

    Customer customer("Bob");
    customer.addRental(rental1);
    customer.addRental(rental2);

    ASSERT_EQ(customer.getTotalAmount(), 9.5);
}

TEST(CustomerTest, GetPricePerMovie) {

    MockMovieStateNewRelease newRelease;
    EXPECT_CALL(newRelease, getPrice(2)).WillOnce(testing::Return(6));
    MockMovieStateRegular regular;
    EXPECT_CALL(regular, getPrice(3)).WillOnce(testing::Return(3.5));

    MockMovie movie("Super Mocked Movie", &newRelease);
    EXPECT_CALL(movie, getPrice(2)).WillRepeatedly(testing::Return(6));
    MockMovie movie2("Super Mocked Movie 2 : the revenge", &regular);
    EXPECT_CALL(movie, getPrice(3)).WillRepeatedly(testing::Return(3.5));

    MockRental rental1(movie, 2);
    EXPECT_CALL(rental1, getPrice()).WillRepeatedly(testing::Return(6));
    MockRental rental2(movie2, 3);
    EXPECT_CALL(rental2, getPrice()).WillRepeatedly(testing::Return(3.5));

    Customer customer("Bob");
    customer.addRental(rental1);
    customer.addRental(rental2);

    std::vector<std::pair<std::string, double>> expected;
    expected.emplace_back(std::pair<std::string, double>("Super Mocked Movie", 6));
    expected.emplace_back(std::pair<std::string, double>("Super Mocked Movie 2 : the revenge", 3.5));

    ASSERT_THAT(customer.getPricePerMovie(), expected);
}