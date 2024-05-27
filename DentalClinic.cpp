//
// Created by Tpshck on 3/25/2024.
//
#include "DentalClinic.h"
#include <iostream>

void DentalClinic::addDentist(const string& name, const string& specialization) {
    dentists.push_back(new Dentist(name, specialization));
}

void DentalClinic::addPatient(const string& name, int age, const string& phoneNumber) {
    patients.push_back(new Patient(name, age, phoneNumber));
}

void DentalClinic::addTreatment(const string& name, const string& description, double cost, const string& requiredSpecialization) {
    treatments.push_back(new Treatment(name, description, cost, requiredSpecialization));
}

Appointment* DentalClinic::bookAppointment(const string& date, const string& time, Dentist* dentist, Patient* patient, Treatment* treatment) {
    if (dentist == nullptr) {
        cout << "Error: Dentist not found." << endl;
        return nullptr;
    }
    if (patient == nullptr) {
        cout << "Error: Patient not found." << endl;
        return nullptr;
    }
    Appointment* appointment = new Appointment(date, time, dentist, patient, treatment);
    appointments.push_back(appointment);
    return appointment;
}

Dentist* DentalClinic::findDentist(const string& name) {
    for (Dentist* dentist : dentists) {
        if (dentist->getName() == name) {
            return dentist;
        }
    }
    return nullptr;
}

Patient* DentalClinic::findPatient(const string& name) {
    for (Patient* patient : patients) {
        if (patient->getName() == name) {
            return patient;
        }
    }
    return nullptr;
}

vector<Dentist*> DentalClinic::getDentists() const {
    return dentists;
}

vector<Patient*> DentalClinic::getPatients() const {
    return patients;
}

bool DentalClinic::isDentistAvailable(const Dentist* dentist, const string& date, const string& time) const {
    for (const Appointment* appointment : appointments) {
        if (appointment->getDentist() == dentist && appointment->getDate() == date && appointment->getTime() == time) {
            std::cout << "Warning: Dentist with ID " << dentist->getId() << " is not available at the specified date and time." << std::endl;
            return false;
        }
    }
    return true;
}

bool DentalClinic::canDentistPerformTreatment(const Dentist* dentist, const Treatment* treatment) const {
    if (dentist->getSpecialization() != treatment->getRequiredSpecialization()) {
        std::cout << "Warning: Dentist with ID " << dentist->getId() << " cannot perform the specified treatment." << std::endl;
        return false;
    }
    return true;
}

void DentalClinic::printAllDentists() const {
    cout << "-----------------------------------------------------------" << endl;
    if (dentists.empty()) {
        cout << "No dentists available." << endl;
        return;
    }
    cout << "Available Dentists:" << endl;
    for (const Dentist *dentist: dentists) {
        cout << "Name: " << dentist->getName() << ", "
             << "Specialization: " << dentist->getSpecialization() << endl;
    }
    cout << "-----------------------------------------------------------" << endl;
}

void DentalClinic::printAllPatients() const {
    cout << "-----------------------------------------------------------" << endl;
    if (patients.empty()) {
        cout << "No patients available." << endl;
        return;
    }
    cout << "Registered Patients:" << endl;
    for (const Patient *patient: patients) {
        cout << "Name: " << patient->getName() << ", "
             << "Age: " << patient->getAge() << ", "
             << "Phone Number: " << patient->getPhoneNumber() << endl;
    }
    cout << "-----------------------------------------------------------" << endl;
}