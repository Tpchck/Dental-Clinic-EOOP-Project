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

void Dentist::removeClinic(DentalClinic* clinic) {
    for (auto it = clinics.begin(); it != clinics.end(); ++it) {
        if (*it == clinic) {
            clinics.erase(it);
            break;
        }
    }
    clinic->removeDentist(this);
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

void Dentist::removePatient(Patient* patient) {
    for (auto it = patients.begin(); it != patients.end(); ++it) {
        if (*it == patient) {
            patients.erase(it);
            break;
        }
    }
    patient->removeDentist(this);
}

void Dentist::addTreatment(Treatment* treatment) {
    treatments.push_back(treatment);
}

void Dentist::addAppointment(Appointment* appointment) {
    appointments.push_back(appointment);
}

void Dentist::removeAppointment(const Appointment* appointment) {
    for (auto it = appointments.begin(); it != appointments.end(); ++it) {
        if (*it == appointment) {
            appointments.erase(it);
            break;
        }
    }
    appointment->getPatient()->removeAppointment(appointment);
}

void Dentist::printTreatments() const {
    cout << "-------------------------------------------------------------------------------" << endl;
    cout << "Dentist " << name << " can perform following treatments: " << endl;
    cout << "-------------------------------------------------------------------------------" << endl;
    for (const auto& treatment : treatments) {
        if (treatment->getRequiredSpecialization() == specialization) {
            cout << "- " << treatment->getName() << endl;
        }
    }
}

void Dentist::printClinics() const {
    cout << "-------------------------------------------------------------------------------" << endl;
    cout << "Dentist " << name << " works in clinics: " << endl;
    for (const auto& clinic : clinics) {
        cout << "- " << clinic->getName() << endl;
    }
}

void Dentist::printPatients() const {
    cout << "-------------------------------------------------------------------------------" << endl;
    cout << "Dentist " << name << " has the following patients: " << endl;
    cout << "-------------------------------------------------------------------------------" << endl;
    for (const auto& patient : patients) {
        cout << "- " << patient->getName() << endl;
    }
}

void Dentist::printAppointments() const {
    cout << "-------------------------------------------------------------------------------" << endl;
    cout << "Dentist " << name << " has the following appointments: " << endl;
    cout << "-------------------------------------------------------------------------------" << endl;
    for (const auto& appointment : appointments) {
        cout << "- Appointment ID: " << appointment->getId() << ", Date: " << appointment->getDate() << ", Time: " << appointment->getTime() << ", Patient: " << appointment->getPatient()->getName() << ", Treatment: " << appointment->getTreatment()->getName() << endl;
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

Dentist::~Dentist() {

}
