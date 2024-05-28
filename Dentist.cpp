//
// Created by Tpshck on 3/25/2024.
//

#include "Dentist.h"

int Dentist::lastId = 0;

Dentist::Dentist(const string& name, const string& specialization, DentalClinic* clinic)
        : name(name), specialization(specialization), clinic(clinic) {
    id = ++lastId;
}

string Dentist::getName() const {
    return name;
}

void Dentist::setName(const string& name) {
    this->name = name;
}

string Dentist::getSpecialization() const {
    return specialization;
}

void Dentist::setSpecialization(const string& specialization) {
    this->specialization = specialization;
}

int Dentist::getId() const {
    return id;
}

void Dentist::addPatient(Patient* patient) {
    patients.push_back(patient);
}

void Dentist::addTreatment(Treatment* treatment) {
    treatments.push_back(treatment);
}