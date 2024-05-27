//
// Created by Tpshck on 3/25/2024.
//

#include "Treatment.h"

Treatment::Treatment(const string& name, const string& description, double cost, const string& requiredSpecialization)
        : name(name), description(description), cost(cost), requiredSpecialization(requiredSpecialization) {}

string Treatment::getName() const {
    return name;
}

void Treatment::setName(const string& name) {
    this->name = name;
}

string Treatment::getDescription() const {
    return description;
}

void Treatment::setDescription(const string& description) {
    this->description = description;
}

double Treatment::getCost() const {
    return cost;
}

void Treatment::setCost(double cost) {
    this->cost = cost;
}

string Treatment::getRequiredSpecialization() const {
    return requiredSpecialization;
}

void Treatment::setRequiredSpecialization(const string& requiredSpecialization) {
    this->requiredSpecialization = requiredSpecialization;
}