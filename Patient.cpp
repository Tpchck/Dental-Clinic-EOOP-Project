//
// Created by Tpshck on 3/25/2024.
//

#include "Patient.h"

Patient::Patient(const string& name, int age, const string& phoneNumber) : name(name), age(age), phoneNumber(phoneNumber) {
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