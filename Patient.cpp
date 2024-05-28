//
// Created by Tpshck on 3/25/2024.
//

#include "Patient.h"

Patient::Patient(const string& name, int age, const string& phoneNumber, DentalClinic* clinic)
        : name(name), age(age), phoneNumber(phoneNumber), clinic(clinic) {
    id = ++lastId;
}

int Patient::lastId = 0;

int Patient::getId() const {
    return id;
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