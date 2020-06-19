// Customer.cpp
#include <sstream>
#include <vector>
#include "Customer.h"

using std::ostringstream;
using std::vector;

using namespace std;

string Customer::statement() {
    RawStatement statement = generateRawStatement();

    ostringstream result;
    result << "Rental Record for " << statement.clientName << "\n";

    for (const auto& moviePrice : statement.pricePerMovie)
        result << "\t" << moviePrice.first << "\t" << moviePrice.second << "\n";

    // add footer lines
    result << "Amount owed is " << statement.totalPrice << "\n";
    result << "You earned " << statement.frequentRenterPoints
           << " frequent renter points";

    return result.str();
}

Customer::RawStatement Customer::generateRawStatement() const {
    RawStatement statement;

    statement.clientName = getName();
    statement.totalPrice = getTotalAmount();
    statement.frequentRenterPoints = getFrequentRenterPoints();
    statement.pricePerMovie = getPricePerMovie();

    return statement;
}

int Customer::getFrequentRenterPoints() const {
    int frequentRenterPoints = 0;

    for (const auto &rental : _rentals)
        frequentRenterPoints += rental.getRenterPoints();

    return frequentRenterPoints;
}

double Customer::getTotalAmount() const {
    double totalAmount = 0;

    for (const auto &rental : _rentals)
        totalAmount += rental.getPrice();

    return totalAmount;
}

std::vector<std::pair<std::string, double>> Customer::getPricePerMovie() const {
    std::vector<std::pair<std::string, double>> pricePerMovie;

    for(const auto& rental: _rentals) {
        pricePerMovie.emplace_back(rental.getMovieTitle(), rental.getPrice());
    }

    return pricePerMovie;
}