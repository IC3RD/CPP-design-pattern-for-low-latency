#include "debug.h"

#include <OrderManager.h>
#include <binance/BinanceOrderManager.h>
#include <cstdio>
#include <iostream>
#include <memory>

int main() {
  std::cout << "Executing Order System\n";
  /* Sample class usage: */

  /* ExchangeAPIFactory factory {Exchange.Coinbase}; (Exchange.Coinbase is enum)
     OrderManager manager = factory.createOrderManager();
     // Since we haven't implemented a factory yet i'll just create an instance
     // manually.
   */

  std::unique_ptr<OrderManager> manager =
      std::make_unique<BinanceOrderManager>();

  OrderBuilder ob = manager->createOrderBuilder();

  ob.createBuyOrder(60000);
  ob.addLimit(52);

  manager->submitOrder(ob.toOrder());

}