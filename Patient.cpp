//
// Created by Tpshck on 3/25/2024.
//

#include "Patient.h"
#include <iostream>
#include <algorithm>

Patient::Patient(const string& name, int age, const string& phoneNumber)
        : name(name), age(age), phoneNumber(phoneNumber) {
    id = ++lastId;
}

int Patient::lastId = 0;

int Patient::getId() const {
    return id;
}

void Patient::addClinics(DentalClinic* clinic) {
    clinics.push_back(clinic);
}

string Patient::getName() const {
    return name;
}

void Patient::setName(const string& name) {
    this->name = name;
}

int Patient::getAge() const {
    return age;
}

void Patient::setAge(int age) {
    this->age = age;
}

string Patient::getPhoneNumber() const {
    return phoneNumber;
}

void Patient::setPhoneNumber(const string& phoneNumber) {
    this->phoneNumber = phoneNumber;
}

vector<MedicalRecord> Patient::getMedicalRecords() const {
    return medicalRecords;
}

void Patient::addMedicalRecord(const MedicalRecord& medicalRecord) {
    medicalRecords.push_back(medicalRecord);
}

void Patient::addDentist(Dentist* dentist) {
    dentists.push_back(dentist);
}

void Patient::addTreatment(Treatment* treatment) {
    treatments.push_back(treatment);
}

vector<Treatment*> Patient::getTreatments() const {
    return treatments;
}

void Patient::printTreatments() const {
    cout<<"-------------------------------------------------------------------------------"<<endl;
    cout << "Patient " << name << " has the following treatments: " << endl;
    for (const auto& treatment : treatments) {
        cout << "- " << treatment->getName() << endl;
    }
    cout<<"-------------------------------------------------------------------------------"<<endl;
}

vector<DentalClinic*> Patient::getClinics() const {
    return clinics;
}

void Patient::printClinics() const {
    cout<<"-------------------------------------------------------------------------------"<<endl;
    cout << "Patient " << name << " is in clinics: " << endl;
    cout<<"-------------------------------------------------------------------------------"<<endl;
    for (const auto& clinic : clinics) {
        cout << "- " << clinic->getName() << endl;
    }
}