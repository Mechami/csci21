#include "Box.h"

Box::Box() : boxNumber(0), boxColor("NO COLOR"),
prizeCapacity(5), prizeCount(0) {
  prizes = new Prize*[prizeCapacity];

  for (unsigned index = 0; index < prizeCapacity; index++) {
    prizes[index] = NULL;
  }
}

Box::Box(unsigned box_number,
         const std::string& box_color, unsigned prize_capacity) :
boxNumber(box_number), boxColor(box_color),
prizeCapacity(prize_capacity), prizeCount(0) {
  prizes = new Prize*[prizeCapacity];

  for (unsigned index = 0; index < prizeCapacity; index++) {
    prizes[index] = NULL;
  }
}

unsigned Box::getBoxNumber() const {
  return boxNumber;
}

void Box::setBoxNumber(unsigned new_number) {
  boxNumber = new_number;
}

const std::string& Box::getBoxColor() const {
  return boxColor;
}

void Box::setBoxColor(const std::string& color) {
  boxColor = color;
}

unsigned Box::getPrizeCapacity() const {
  return prizeCapacity;
}

unsigned Box::getPrizeCount() const {
  return prizeCount;
}

bool Box::addPrize(const Prize& prize) {
  bool result = false;

  if (prizeCount < prizeCapacity) {
    prizes[prizeCount] = new Prize(prize);
    prizeCount += 1;
    result = true;
  }

  return result;
}

Prize& Box::getPrize(unsigned index) {
  return ((index >= prizeCount)? scratch : *prizes[index]);
}

Prize Box::removePrize(unsigned index) {
  Prize prize = scratch;

  if (index < prizeCount) {
    prize = *prizes[index];
    delete prizes[index];
    prizes[index] = NULL;
    prizeCount -= 1;
  }

  return prize;
}

Box::~Box() {
  for (unsigned index = 0; index < prizeCount; index++) {
    delete prizes[index];
  }

  delete[] prizes;
}
