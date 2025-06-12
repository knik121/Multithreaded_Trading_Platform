#include "include/trader.h"
#include <iostream>

namespace StockTradingSystem {

    int Trader::id_counter = 1;

    Trader::Trader() : id(id_counter++), name("Unnamed"), orderFactory(nullptr), orderBook(nullptr) {}

    Trader::Trader(const std::string& name)
        : id(id_counter++), name(name), orderFactory(nullptr), orderBook(nullptr) {}

    Trader::Trader(const std::string& name, const std::vector<Stock>& stocks,
                   OrderFactory* orderFactory, OrderBook* orderBook)
        : id(id_counter++), name(name), stocks(stocks),
          orderFactory(orderFactory), orderBook(orderBook) {}

    void Trader::buy(const Stock& stock, int quantity) {
        std::shared_ptr<Order> order = std::make_shared<LimitOrder>(id, stock.getPrice(), quantity);
        order->setOrderType(BUY);
        orders.push_back(order);
    }

    void Trader::sell(const Stock& stock, int quantity) {
        std::shared_ptr<Order> order = std::make_shared<LimitOrder>(id, stock.getPrice(), quantity);
        order->setOrderType(SELL);
        orders.push_back(order);
    }

    void Trader::trade(double price1, double price2, int quantity1, int quantity2) {
        if (stocks.size() < 2) return;
        buy(stocks[0], quantity1);
        sell(stocks[1], quantity2);
    }

    int Trader::getID() const { return id; }

    const std::vector<std::shared_ptr<Order>>& Trader::getOrders() const {
        return orders;
    }

    void Trader::addStock(const Stock& stock) {
        stocks.push_back(stock);
    }

    std::vector<Stock> Trader::getStocks() const {
        return stocks;
    }

    Trader::~Trader() {}

    TraderException::TraderException(const std::string& msg) : message(msg) {}

    const char* TraderException::what() const noexcept {
        return message.c_str();
    }

}
