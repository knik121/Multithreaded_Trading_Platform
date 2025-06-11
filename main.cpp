<<<<<<< HEAD
#include "include/orderBook.h"
#include "include/trader.h"

#include <iostream>
#include <vector>
#include <thread>
#include <mutex>

using namespace StockTradingSystem;

// Define a trader function to simulate traders placing orders
void traderFunction(Trader& trader, OrderBook& orderBook) {
    Stock someStock(145, "a");
    Stock anotherStock(154, "b");
    trader.addStock(someStock);
    trader.addStock(anotherStock);
    int quantity = 25;

    // Place buy and sell orders
    std::shared_ptr<Order> buyOrder = std::make_shared<MarketOrder>(trader.getID(), someStock.getPrice(), quantity);
    buyOrder->setOrderType(OrderType::BUY);
    std::shared_ptr<Order> sellOrder = std::make_shared<MarketOrder>(trader.getID(), anotherStock.getPrice(), quantity);
    sellOrder->setOrderType(OrderType::SELL);

    trader.trade(150, 160, 12, 13);

    // Add orders to the order book
    orderBook.addOrder(buyOrder);
    orderBook.addOrder(sellOrder);
}

int main() {
    // Create an order book
    OrderBook orderBook;

    // Create and start multiple trader threads
    std::vector<std::thread> traderThreads;
    int numTraders = 3;
    for (int i = 0; i < numTraders; ++i) {
        Trader trader("Trader " + std::to_string(i + 1));
        traderThreads.emplace_back(traderFunction, std::ref(trader), std::ref(orderBook));
    }

    // Join trader threads
    for (auto& thread : traderThreads) {
        thread.join();
    }

    // Print the order book after all trading is done
    orderBook.printOrderBook();

    return 0;
=======
#include <iostream>

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    // TIP Press <shortcut actionId="RenameElement"/> when your caret is at the <b>lang</b> variable name to see how CLion can help you rename it.
    auto lang = "C++";
    std::cout << "Hello and welcome to " << lang << "!\n";

    for (int i = 1; i <= 5; i++) {
        // TIP Press <shortcut actionId="Debug"/> to start debugging your code. We have set one <icon src="AllIcons.Debugger.Db_set_breakpoint"/> breakpoint for you, but you can always add more by pressing <shortcut actionId="ToggleLineBreakpoint"/>.
        std::cout << "i = " << i << std::endl;
    }

    return 0;
    // TIP See CLion help at <a href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>. Also, you can try interactive lessons for CLion by selecting 'Help | Learn IDE Features' from the main menu.
>>>>>>> 66a2da399ebf537c4c9c3897103e1848d7ad6b4e
}