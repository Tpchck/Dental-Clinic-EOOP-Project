//
// Created by Tpshck on 3/25/2024.
//

#include "Treatment.h"

Treatment::Treatment(const string& name, const string& description, double cost, const string& requiredSpecialization)
        : name(name), description(description), cost(cost), requiredSpecialization(requiredSpecialization) {}

string Treatment::getName() const {
    return name;
}

string Treatment::getDescription() const {
    return description;
}

double Treatment::getCost() const {
    return cost;
}

string Treatment::getRequiredSpecialization() const {
    return requiredSpecialization;
}

void Treatment::setDescription(const string &newDescription) {
    description = newDescription;
}

void Treatment::setCost(double newCost) {
    cost = newCost;
}