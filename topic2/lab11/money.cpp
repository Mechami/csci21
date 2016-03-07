#include "money.h"

// The Constructor, Accessors and Mutators have been defined for you
Money::Money(int dollars, int cents)
      : dollars_(dollars),
        cents_(cents) {
}

int Money::dollars() const {
    return dollars_;
}

int Money::cents() const {
    return cents_;
}

void Money::set_dollars(int dollars) {
  dollars_ = dollars;
}

void Money::set_cents(int cents) {
  cents_ = cents;
}

// This function definition provided as an example and is FULLY COMPLETE
const Money operator +(const Money& amount1, const Money& amount2) {
  // Get all the cents of object 1
  int all_cents1 = amount1.cents_ + amount1.dollars_ * 100;
  // Get all the cents of object 2
  int all_cents2 = amount2.cents_ + amount2.dollars_ * 100;
  // Add all the cents together
  int sum_all_cents = all_cents1 + all_cents2;
  // Handle the fact that money can be negative
  int abs_all_cents = abs(sum_all_cents);
  int final_dollars = abs_all_cents / 100;
  int final_cents = abs_all_cents % 100;
  // If the result of the operation was negative, negate final dollars and cents
  if (sum_all_cents < 0) {
    final_dollars = -final_dollars;
    final_cents = -final_cents;
  }
  return Money(final_dollars, final_cents);
}

const Money operator -(const Money& amount1, const Money& amount2) {
	int amount1_cents = amount1.cents_ + (amount1.dollars_ * 100);
	int amount2_cents = amount2.cents_ + (amount2.dollars_ * 100);
	int cent_diff = amount1_cents - amount2_cents;
	int total_dollars = cent_diff / 100;
	int total_cents = cent_diff % 100;

	return Money(total_dollars, total_cents);
}

bool operator ==(const Money &amount1, const Money &amount2) {
  int amount1_cents = amount1.cents_ + (amount1.dollars_ * 100);
  int amount2_cents = amount2.cents_ + (amount2.dollars_ * 100);
  return (amount1_cents == amount2_cents);
}

const Money operator -(const Money &amount) {
  return Money(-amount.dollars_, -amount.cents_);
}

ostream& operator <<(ostream &out, const Money &amount) {

  // Check the signbit for each variable
  // and prepend a negative sign if either one is active
  out << (((amount.dollars_ & 0x80000000) || (amount.cents_ & 0x80000000))? "$-"
                                                                         : "$");

  // Cache the default values for the width and fill parameters
  int stream_width = out.width();
  char fill_char = out.fill();

  // Since we do our negative sign above take the absolute value of the money variables
  out << abs(amount.dollars_) << ".";
  // Cents needs special handling to make sure it's formatted properly
  out << std::setw(2) << std::setfill('0') << abs(amount.cents_);
  // Restore the default values now that we've submitted our cent text
  out << std::setw(stream_width) << std::setfill(fill_char) << std::flush;

  return out;
}
