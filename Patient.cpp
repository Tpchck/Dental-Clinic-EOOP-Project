//
// Created by Tpshck on 3/25/2024.
//

#include "Patient.h"
#include <iostream>
#include "Dentist.h"

int Patient::lastId = 0;

Patient::Patient(const string& name, int age, const string& phoneNumber)
        : name(name), age(age), phoneNumber(phoneNumber) {
    id = ++lastId;
}

void Patient::addClinics(DentalClinic* clinic) {
    clinics.push_back(clinic);
}

void Patient::removeClinic(DentalClinic* clinic) {
    for (auto it = clinics.begin(); it != clinics.end(); ++it) {
        if (*it == clinic) {
            clinics.erase(it);
            break;
        }
    }
}

int Patient::getId() const {
    return id;
}

string Patient::getName() const {
    return name;
}

int Patient::getAge() const {
    return age;
}

string Patient::getPhoneNumber() const {
    return phoneNumber;
}

void Patient::addDentist(Dentist* dentist) {
    dentists.push_back(dentist);
}

void Patient::removeDentist(Dentist* dentist) {
    for (auto it = dentists.begin(); it != dentists.end(); ++it) {
        if (*it == dentist) {
            dentists.erase(it);
            break;
        }
    }
}

void Patient::addTreatment(Treatment* treatment) {
    treatments.push_back(treatment);
}

void Patient::addAppointment(Appointment* appointment) {
    appointments.push_back(appointment);
}

void Patient::removeAppointment(const Appointment* appointment) {
    for (auto it = appointments.begin(); it != appointments.end(); ++it) {
        if (*it == appointment) {
            appointments.erase(it);
            break;
        }
    }
}

void Patient::addMedicalRecord(MedicalRecord* record) {
    medicalRecords.push_back(*record);
}

vector<Appointment*> Patient::getAppointments() const {
    return appointments;
}

void Patient::printAppointments() const {
    cout<<"-------------------------------------------------------------------------------"<<endl;
    cout << "Patient " << name << " has the following appointments: " << endl;
    cout<<"-------------------------------------------------------------------------------"<<endl;
    for (const auto& appointment : appointments) {
        cout << "- Appointment ID: " << appointment->getId() << ", Date: " << appointment->getDate() << ", Time: " << appointment->getTime() << ", Dentist: " << appointment->getDentist()->getName() << ", Treatment: " << appointment->getTreatment()->getName() << endl;
    }
}

void Patient::printTreatments() const {
    cout<<"-------------------------------------------------------------------------------"<<endl;
    cout << "Patient " << name << " has the following treatments: " << endl;
    for (const auto& treatment : treatments) {
        cout << "- " << treatment->getName() << endl;
    }
    cout<<"-------------------------------------------------------------------------------"<<endl;
}

void Patient::printClinics() const {
    cout<<"-------------------------------------------------------------------------------"<<endl;
    cout << "Patient " << name << " is in clinics: " << endl;
    cout<<"-------------------------------------------------------------------------------"<<endl;
    for (const auto& clinic : clinics) {
        cout << "- " << clinic->getName() << endl;
    }
}

void Patient::printDentists() const {
    cout<<"-------------------------------------------------------------------------------"<<endl;
    cout << "Patient " << name << " has the following dentists: " << endl;
    cout<<"-------------------------------------------------------------------------------"<<endl;
    for (const auto& dentist : dentists) {
        cout << "- " << dentist->getName() << endl;
    }
}

Patient::~Patient() {

}
