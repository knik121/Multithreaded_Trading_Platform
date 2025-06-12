#include "order.h"
#include <iostream>

namespace StockTradingSystem {

    Order::Order(int trader_id, double price, int quantity)
        : traider_id(trader_id), price(price), quantity(quantity), timestamp(std::time(nullptr)) {}

    Order::~Order() {}

    int Order::getTraider_id() const { return traider_id; }
    double Order::getPrice() const { return price; }
    int Order::getQuantity() const { return quantity; }
    std::time_t Order::getTimestamp() const { return timestamp; }

    void Order::reduceQuantity(int q) { quantity -= q; }
    OrderType Order::getOrdertype() const { return ordertype; }
    void Order::setOrderType(OrderType t) { ordertype = t; }

    std::string MarketOrder::getOrderType() const {
        return "Market";
    }

    std::string LimitOrder::getOrderType() const {
        return "Limit";
    }

    OrderFactory::~OrderFactory() {}

    std::unique_ptr<Order> MarketOrderFactory::createOrder(int trader_id, double price, int quantity) {
        return std::make_unique<MarketOrder>(trader_id, price, quantity);
    }

    std::unique_ptr<Order> LimitOrderFactory::createOrder(int trader_id, double price, int quantity) {
        return std::make_unique<LimitOrder>(trader_id, price, quantity);
    }

    OrderMatchingStrategy::~OrderMatchingStrategy() {}

    void PriceTimeOrderMatchingStrategy::matchOrders(std::vector<std::shared_ptr<Order>>& buyOrders,
                                                     std::vector<std::shared_ptr<Order>>& sellOrders) {
        std::vector<std::shared_ptr<Order>> matchedOrders;

        for (auto sellOrder = sellOrders.begin(); sellOrder != sellOrders.end(); ++sellOrder) {
            for (auto it = buyOrders.begin(); it != buyOrders.end();) {
                if ((*sellOrder)->getPrice() <= (*it)->getPrice()) {
                    matchedOrders.push_back(*it);
                    it = buyOrders.erase(it);
                } else {
                    ++it;
                }
            }
        }

        buyOrders.insert(buyOrders.end(), matchedOrders.begin(), matchedOrders.end());
    }

}
