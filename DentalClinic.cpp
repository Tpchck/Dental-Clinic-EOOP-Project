//
// Created by Tpshck on 3/25/2024.
//

#include "DentalClinic.h"
#include "Appointment.h"
#include "Dentist.h"
#include "Patient.h"
#include <iostream>

void DentalClinic::addDentist(Dentist* dentist) {
    dentists.push_back(dentist);
}

void DentalClinic::addPatient(Patient* patient) {
    patients.push_back(patient);
}

void DentalClinic::addTreatment(const std::string& name, const std::string& description, double cost, const std::string& requiredSpecialization) {
    treatments.push_back(new Treatment(name, description, cost, requiredSpecialization));
}

Appointment* DentalClinic::bookAppointment(const std::string& date, const std::string& time, Dentist* dentist, Patient* patient, Treatment* treatment) {
    Appointment* appointment = new Appointment(date, time, dentist, patient, treatment);
    appointments.push_back(appointment);
    return appointment;
}

Dentist* DentalClinic::findDentist(const std::string& name) {
    for (Dentist* dentist : dentists) {
        if (dentist->getName() == name) {
            return dentist;
        }
    }
    return nullptr;
}

Patient* DentalClinic::findPatient(const std::string& name) {
    for (Patient* patient : patients) {
        if (patient->getName() == name) {
            return patient;
        }
    }
    return nullptr;
}

std::vector<Dentist*> DentalClinic::getDentists() const {
    return dentists;
}

std::vector<Patient*> DentalClinic::getPatients() const {
    return patients;
}

bool DentalClinic::isDentistAvailable(const Dentist* dentist, const std::string& date, const std::string& time) const {
    // Implement this method based on your requirements
    return true;
}

bool DentalClinic::canDentistPerformTreatment(const Dentist* dentist, const Treatment* treatment) const {
    // Implement this method based on your requirements
    return true;
}

void DentalClinic::printAllAppointments() const {
    // Implement this method based on your requirements
}

void DentalClinic::printAllDentists() const {
    // Implement this method based on your requirements
}

void DentalClinic::printAllPatients() const {
    // Implement this method based on your requirements
}

void DentalClinic::removeAppointment(const std::string& date, const std::string& time, const Patient* patient) {
    // Implement this method based on your requirements
}