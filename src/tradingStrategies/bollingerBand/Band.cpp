#pragma once

#include "Band.h"

#include <math.h>

Band::Band() {
  meanPrice = 0;
  stdDeviation = 0;
  noOfElements = 0;
}

Band::~Band() {}

long Band::getMean() { return meanPrice; }

long Band::getStd() { return stdDeviation; }

int Band::getNoOfElements() { return noOfElements; }

void Band::insertNewData(long price, std::shared_ptr<OrderBook> book) {
  if (price > book->getLowestAsk()->getOrderPrice() + stdDeviation || price <
  book->getHighestBid()->getOrderPrice() - stdDeviation) { return;
      //this is just a measure to ensure data that is far from our bands is not
  affected
  }

  long newMean = (meanPrice * noOfElements + price) / (noOfElements + 1);
  long delta = newMean - meanPrice;
  int newNoOfElements = noOfElements + 1;
  long newVar = ((price - newMean) * (price - newMean) / newNoOfElements) +
                (noOfElements / newNoOfElements) *
                    ((stdDeviation * stdDeviation) + (delta * delta));
  meanPrice = newMean;
  stdDeviation = sqrt(newVar);
  noOfElements = newNoOfElements;
}