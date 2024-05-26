//
// Created by Tpshck on 3/25/2024.
//

#include "Dentist.h"

Dentist::Dentist(const string& name, const string& specialization)
        : name(name), specialization(specialization) {}

string Dentist::getName() const {
    return name;
}

string Dentist::getSpecialization() const {
    return specialization;
}

void Dentist::setName(const string &newName) {
    name = newName;
}

void Dentist::setSpecialization(const string &newSpecialization) {
    specialization = newSpecialization;
}
