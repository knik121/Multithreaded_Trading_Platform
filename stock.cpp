#include "stock.h"

namespace StockTradingSystem {

    Stock::Stock() : price(0.0), name("") {}

    Stock::Stock(double price, const std::string& name) : price(price), name(name) {}

    void Stock::setPrice(double p) { price = p; }

    void Stock::setName(const std::string& n) { name = n; }

    double Stock::getPrice() const { return price; }

    std::string Stock::getName() const { return name; }

}
