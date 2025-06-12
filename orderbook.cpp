#include "include/orderbook.h"
#include <iostream>
#include <mutex>

namespace StockTradingSystem {

    OrderBook::OrderBook() {
        strategy = new PriceTimeOrderMatchingStrategy(); // Default strategy
    }

    void OrderBook::addOrder(std::shared_ptr<Order> order) {
        static std::mutex mtx;
        std::lock_guard<std::mutex> lock(mtx);
        book.push_back(order);
    }

    void OrderBook::matchOrders() {
        if (strategy) {
            std::vector<std::shared_ptr<Order>> buys;
            std::vector<std::shared_ptr<Order>> sells;
            for (auto& o : book) {
                if (o->getOrdertype() == BUY)
                    buys.push_back(o);
                else
                    sells.push_back(o);
            }
            strategy->matchOrders(buys, sells);
        }
    }

    void OrderBook::printOrderBook() const {
        std::cout << "--- Order Book ---" << std::endl;
        for (const auto& order : book) {
            std::cout << "[" << (order->getOrdertype() == BUY ? "BUY" : "SELL") << "] "
                      << "Trader " << order->getTraider_id()
                      << " placed a " << order->getOrderType()
                      << " order for " << order->getQuantity()
                      << " at price " << order->getPrice() << std::endl;
        }
    }

    void OrderBook::setStrategy(OrderMatchingStrategy* s) {
        strategy = s;
    }

}
