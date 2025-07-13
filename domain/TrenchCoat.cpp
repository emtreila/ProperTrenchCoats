#include "TrenchCoat.h"

#include <fstream>
#include <sstream>
#include <vector>

TrenchCoat::TrenchCoat() {
    /**
     *Implicit constructor
    **/
    this->size = "";
    this->colour = "";
    this->price = 0;
    this->quantity = 0;
    this->photograph = "";
}

TrenchCoat::TrenchCoat(const std::string &size,
                       const std::string &colour,
                       double price,
                       unsigned int quantity,
                       const std::string &photograph) {
    /**
     *Explicit constructor
        @param size: the size of the trench coat
        @param colour: the colour of the trench coat
        @param price: the price of the trench coat
        @param quantity: the quantity of the trench coat
        @param photograph: the photograph of the trench coat
     **/
    this->size = size;
    this->colour = colour;
    this->price = price;
    this->quantity = quantity;
    this->photograph = photograph;
}

TrenchCoat::~TrenchCoat() = default; // Destroyer

TrenchCoat::TrenchCoat(const TrenchCoat &t) {
    /**
     *Copy constructor
        @param t: the trench coat to be copied
     **/
    this->size = t.size;
    this->colour = t.colour;
    this->price = t.price;
    this->quantity = t.quantity;
    this->photograph = t.photograph;
}

std::string TrenchCoat::getSize() const {
    /**
     *Getter for the size of the trench coat
        @return the size of the trench coat
     **/
    return this->size;
}

std::string TrenchCoat::getColour() const {
    /**
     *Getter for the colour of the trench coat
        @return the colour of the trench coat
     **/
    return this->colour;
}

double TrenchCoat::getPrice() const {
    /**
     *Getter for the price of the trench coat
        @return the price of the trench coat
     **/
    return this->price;
}

unsigned int TrenchCoat::getQuantity() const {
    /**
     *Getter for the quantity of the trench coat
        @return the quantity of the trench coat
     **/
    return this->quantity;
}

std::string TrenchCoat::getPhotograph() const {
    /**
     *Getter for the photograph of the trench coat
        @return the photograph of the trench coat
     **/
    return this->photograph;
}


void TrenchCoat::setSize(const std::string &newSize) {
    /**
     *Setter for the size of the trench coat
        @param newSize: the new size of the trench coat
     **/
    this->size = newSize;
}

void TrenchCoat::setColour(const std::string &newColour) {
    /**
     *Setter for the colour of the trench coat
        @param newColour: the new colour of the trench coat
     **/
    this->colour = newColour;
}

void TrenchCoat::setPrice(double newPrice) {
    /**
     *Setter for the price of the trench coat
        @param newPrice: the new price of the trench coat
     **/
    this->price = newPrice;
}

void TrenchCoat::setQuantity(unsigned int newQuantity) {
    /**
     *Setter for the quantity of the trench coat
        @param newQuantity: the new quantity of the trench coat
     **/
    this->quantity = newQuantity;
}

void TrenchCoat::setPhotograph(const std::string &newPhotograph) {
    /**
     *Setter for the photograph of the trench coat
        @param newPhotograph: the new photograph of the trench coat
     **/
    this->photograph = newPhotograph;
}

bool TrenchCoat::operator==(const TrenchCoat &t) const {
    /**
     *Overloading the == operator
        @param t: the trench coat to be compared with
        @return true if the trench coats are equal, false otherwise
     **/
    return (this->size == t.size && this->colour == t.colour);
}

std::ostream &operator<<(std::ostream &os, const TrenchCoat &coat) {
    os << coat.size << "," << coat.colour << "," << coat.price
            << "," << coat.quantity << "," << coat.photograph << "\n";
    return os;
}

std::istream &operator>>(std::istream &is, TrenchCoat &coat) {
    std::string line{};

    std::getline(is, line);

    std::istringstream ss(line);
    std::string substring;
    std::vector<std::string> tokens;

    while (std::getline(ss, substring, ',')) {
        tokens.push_back(substring);
    }

    if (tokens.size() < 5) {
        return is;
    }

    coat.setSize(tokens[0]);
    coat.setColour(tokens[1]);
    coat.setPrice(std::stod(tokens[2]));
    coat.setQuantity(std::stoi(tokens[3]));
    coat.setPhotograph(tokens[4]);

    return is;
}

std::string TrenchCoat::toString() {
    /**
     *Converts the trench coat to a string
        @return the string representation of the trench coat
     **/
    return this->size + "," + this->colour + "," + std::to_string(this->price) + "," +
           std::to_string(this->quantity) + "," + this->photograph;
}