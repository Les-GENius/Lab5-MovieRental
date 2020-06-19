#include <Customer.h>
#include <gtest/gtest.h>

#include <tests/mock/RentalMock.h>
#include <tests/mock/MovieMock.h>

#include <MovieStateRegular.h>
#include <MovieStateChildren.h>
#include <MovieStateNewRelease.h>

TEST(Customer, statement){

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


TEST(Customer, GetFrequentRenterPoints) {
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
