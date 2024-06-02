//
// Created by Tpshck on 3/25/2024.
//

#include "DentalClinic.h"
#include "Appointment.h"
#include "Dentist.h"
#include "Patient.h"
#include <iostream>

DentalClinic::DentalClinic(const string& name): name(name) {}

void DentalClinic::addDentist(Dentist* dentist) {
    dentists.push_back(dentist);
    dentist->addClinics(this);
}

void DentalClinic::addPatient(Patient* patient) {
    patients.push_back(patient);
    patient->addClinics(this);
}

Appointment* DentalClinic::bookAppointment(const string& date, const string& time, Dentist* dentist, Patient* patient, Treatment* treatment) {
    if (!dentist->isAvailable(date, time)) {
        cout<<"-------------------------------------------------------------------------------"<<endl;
        cout << "Error: The time slot is already occupied." << endl;
        cout<<"-------------------------------------------------------------------------------"<<endl;
        return nullptr;
    } else {
        Appointment* appointment = new Appointment(date, time, dentist, patient, treatment);
        appointments.push_back(appointment);
        dentist->addPatient(patient);
        patient->addDentist(dentist);
        return appointment;
    }
}

Dentist* DentalClinic::findDentist(const string& name) {
    for (Dentist* dentist : dentists) {
        if (dentist->getName() == name) {
            return dentist;
        }
    }
    cout<<"-------------------------------------------------------------------------------"<<endl;
    cout << "Error: Dentist " << name << " is not in the clinic." << endl;
    cout<<"-------------------------------------------------------------------------------"<<endl;
    return nullptr;
}

Patient* DentalClinic::findPatient(const string& name) {
    for (Patient* patient : patients) {
        if (patient->getName() == name) {
            return patient;
        }
    }
    cout<<"-------------------------------------------------------------------------------"<<endl;
    cout << "Error: Patient " << name << " is not found." << endl;
    cout<<"-------------------------------------------------------------------------------"<<endl;
    return nullptr;
}

vector<Dentist*> DentalClinic::getDentists() const {
    return dentists;
}

vector<Patient*> DentalClinic::getPatients() const {
    return patients;
}

void DentalClinic::printAllAppointments() const {
    for (const auto& appointment : appointments) {
        cout<<"-------------------------------------------------------------------------------"<<endl;
        cout << "Appointment ID: " << appointment->getId() << ", "
                  << "Date: " << appointment->getDate() << ", "
                  << "Time: " << appointment->getTime() << ", "
                  << "Dentist: " << appointment->getDentist()->getName() << ", "
                  << "Patient: " << appointment->getPatient()->getName() << ", "
                  << "Treatment: " << appointment->getTreatment()->getName() << endl;
    }
}

void DentalClinic::printAllDentists() const {
    for (const auto& dentist : dentists) {
        cout<<"-------------------------------------------------------------------------------"<<endl;
        cout << "Dentist ID: " << dentist->getId() << ", "
                  << "Name: " << dentist->getName() << ", "
                  << "Specialization: " << dentist->getSpecialization() << endl;
        cout<<"-------------------------------------------------------------------------------"<<endl;
    }
}

void DentalClinic::printAllPatients() const {
    for (const auto& patient : patients) {
        cout<<"-------------------------------------------------------------------------------"<<endl;
        cout << "Patient ID: " << patient->getId() << ", "
                  << "Name: " << patient->getName() << ", "
                  << "Age: " << patient->getAge() << ", "
                  << "Phone Number: " << patient->getPhoneNumber() << endl;
        cout<<"-------------------------------------------------------------------------------"<<endl;
    }
}

void DentalClinic::removeAppointment(const string& date, const string& time, const Patient* patient) {
    for (auto it = appointments.begin(); it != appointments.end(); ++it) {
        if ((*it)->getDate() == date && (*it)->getTime() == time && (*it)->getPatient() == patient) {
            appointments.erase(it);
            break;
        }
    }
}

vector<Appointment*> DentalClinic::getAppointments() const {
    return appointments;
}

vector<Treatment*> DentalClinic::getTreatments() const {
    return treatments;
}

string DentalClinic::getName() const {
    return name;
}

Treatment* DentalClinic::findTreatment(const string& name) {
    for (Treatment* treatment : treatments) {
        if (treatment->getName() == name) {
            return treatment;
        }
    }
    cout<<"-------------------------------------------------------------------------------"<<endl;
    cout << "Error: Treatment " << name << " is not found." << endl;
    cout<<"-------------------------------------------------------------------------------"<<endl;
    return nullptr;
}