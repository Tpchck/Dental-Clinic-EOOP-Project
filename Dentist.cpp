//
// Created by Tpshck on 3/25/2024.
//

#include "Dentist.h"
#include <iostream>
#include "Appointment.h"

int Dentist::lastId = 0;

Dentist::Dentist(const string& name, const string& specialization)
        : name(name), specialization(specialization) {
    id = ++lastId;
}

void Dentist::addClinics(DentalClinic* clinic) {
    clinics.push_back(clinic);
}

string Dentist::getName() const {
    return name;
}

string Dentist::getSpecialization() const {
    return specialization;
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

vector<Treatment*> Dentist::getTreatments() const {
    return treatments;
}

void Dentist::printTreatments() const {
    cout<<"-------------------------------------------------------------------------------"<<endl;
    cout << "Dentist " << name << " can perform following treatments: " << endl;
    cout<<"-------------------------------------------------------------------------------"<<endl;
    for (const auto& treatment : treatments) {
        if (treatment->getRequiredSpecialization() == specialization) {
            cout << "- " << treatment->getName() << endl;
        }
    }
}

vector<DentalClinic*> Dentist::getClinics() const {
    return clinics;
}

void Dentist::printClinics() const {
    cout<<"-------------------------------------------------------------------------------"<<endl;
    cout << "Dentist " << name << " works in clinics: " << endl;
    for (const auto& clinic : clinics) {
        cout << "- " << clinic->getName() << endl;
    }
}
bool Dentist::isAvailable(const string& date, const string& time) const {
    for (const auto& clinic : clinics) {
        for (const auto& appointment : clinic->getAppointments()) {
            if (appointment->getDentist() == this && appointment->getDate() == date && appointment->getTime() == time) {
                return false;
            }
        }
    }
    return true;
}

bool Dentist::canPerformTreatment(const Treatment* treatment) const {
    return treatment->getRequiredSpecialization() == specialization;
}

void Dentist::printPatients() const {
    cout<<"-------------------------------------------------------------------------------"<<endl;
    cout << "Dentist " << name << " has the following patients: " << endl;
    cout<<"-------------------------------------------------------------------------------"<<endl;
    for (const auto& patient : patients) {
        cout << "- " << patient->getName() << endl;
    }
}