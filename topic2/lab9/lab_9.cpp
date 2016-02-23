/*
 * Name        : lab_9.cpp
 * Author      : Philip Muzzall
 * Description : Building a Spaceship Class
 */
#include "lab_9.h"

void Spaceship::set_name(string name) {
  this->name_ = name;
}

void Spaceship::set_top_speed(double top_speed) {
  this->top_speed_ = top_speed;
}

void Spaceship::set_fuel_source(string fuel_source) {
  this->fuel_source_ = fuel_source;
}

void Spaceship::set_crew_capacity(int crew_capacity) {
  this->crew_capacity_ = crew_capacity;
}

string Spaceship::name() const {
  return this->name_;
}

double Spaceship::top_speed() const {
  return this->top_speed_;
}

string Spaceship::fuel_source() const {
  return this->fuel_source_;
}

int Spaceship::crew_capacity() const {
  return this->crew_capacity_;
}

string Spaceship::ToString() const {
  string description = name_ + '\n';

  description += "Top Speed:     Warp " + std::to_string(this->top_speed_).substr(0, 4) + '\n';
  description += "Fuel Source:   " + this->fuel_source_ + '\n';
  description += "Crew Capacity: " + std::to_string(this->crew_capacity_);

  return description;
}
