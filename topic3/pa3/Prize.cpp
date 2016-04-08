#include "Prize.h"

Prize::Prize() : prizeName("NO NAME"), prizeValue(0) {
  // Do nothing else
}

Prize::Prize(const std::string& name, unsigned value) :
prizeName(name), prizeValue(value) {
  // Do nothing else
}

Prize::~Prize() {
  // Do nothing
}

const std::string&Prize::getPrizeName() const
{
  return prizeName;
}

void Prize::setPrizeName(const std::string& new_name)
{
  prizeName = new_name;
}

unsigned Prize::getPrizeValue() const
{
  return prizeValue;
}

void Prize::setPrizeValue(unsigned new_value)
{
  prizeValue = new_value;
}

bool operator==(Prize prizeOne, Prize prizeTwo)
{
  return ((prizeOne.prizeName == prizeTwo.prizeName) &&
          (prizeOne.prizeValue == prizeTwo.prizeValue));
}
