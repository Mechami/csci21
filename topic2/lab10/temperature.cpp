#include "temperature.h"

Temperature::Temperature() : kelvin_(0)
{
}

Temperature::Temperature(double kelvin) : kelvin_(kelvin)
{
}

Temperature::Temperature(double temp, char unit)
{
  unit = tolower(unit);

  if (unit == 'f')
  {
    this->kelvin_ = ((5.0 * (temp - 32) / 9) + 273.15);
  }
  else if (unit == 'c')
  {
    this->kelvin_ = (temp + 273.15);
  }
  else
  {
    this->kelvin_ = temp;
  }
}

void Temperature::SetTempFromKelvin(double kelvin)
{
  this->kelvin_ = kelvin;
}

void Temperature::SetTempFromCelsius(double celsius)
{
  this->kelvin_ = celsius + 273.15;
}

void Temperature::SetTempFromFahrenheit(double fahrenheit)
{
  this->kelvin_ = (5.0 * (fahrenheit - 32) / 9) + 273.15;
}

double Temperature::GetTempAsKelvin() const
{
  return this->kelvin_;
}

double Temperature::GetTempAsCelsius() const
{
  return (this->kelvin_ - 273.15);
}

double Temperature::GetTempAsFahrenheit() const
{
 return (((this->kelvin_ - 273.15) * 9.0) / 5) + 32;
}

string Temperature::ToString(char unit) const
{
  unit = tolower(unit);
  stringstream ss;
  ss.precision(2);
  ss << std::fixed;

  if (unit == 'k')
  {
    ss << this->GetTempAsKelvin() << " Kelvin";
  }
  else if (unit == 'c')
  {
    ss << this->GetTempAsCelsius() << " Celsius";
  }
  else if (unit == 'f')
  {
    ss << this->GetTempAsFahrenheit() << " Fahrenheit";
  }
  else
  {
    ss << "Invalid Unit";
  }

  return ss.str();
}
