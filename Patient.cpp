//
// Created by Tpshck on 3/25/2024.
//

#include <iostream>
#include "Patient.h"

int Patient::lastId = 0;

Patient::Patient(const string& name, int age, const string& phoneNumber)
        : id(++lastId), name(name), age(age), phoneNumber(phoneNumber) {}

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

void Patient::setName(const string &newName) {
    name = newName;
}

void Patient::setAge(int newAge) {
    age = newAge;
}

void Patient::setPhoneNumber(const string &newPhoneNumber) {
    phoneNumber = newPhoneNumber;
}

void Patient::addMedicalRecord(const MedicalRecord& record) {
    medicalRecords.push_back(record);
}

void Patient::printMedicalRecord() const {
    if (medicalRecords.empty()) {
        cout << "No medical records for " << name << "." << endl;
        return;
    }

    cout << "-----------------------------------------------------------" << endl;
    cout << "Medical Record for " << name << ":" << endl;
    for (const MedicalRecord& record : medicalRecords) {
        cout << "Condition: " << record.getCondition() << ", "
             << "Treatment: " << record.getTreatment() << ", "
             << "Date: " << record.getDate() << ", "
             << "Doctor: " << record.getDoctorName() << endl;
    }
    cout << "-----------------------------------------------------------" << endl;
}