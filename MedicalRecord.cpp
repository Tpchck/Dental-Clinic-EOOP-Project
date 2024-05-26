//
// Created by Tpshck on 4/7/2024.
//

#include "MedicalRecord.h"

MedicalRecord::MedicalRecord(const string& condition, const string& treatment, const string& date, const string& doctorName)
        : condition(condition), treatment(treatment), date(date), doctorName(doctorName) {}

string MedicalRecord::getCondition() const {
    return condition;
}

string MedicalRecord::getTreatment() const {
    return treatment;
}

string MedicalRecord::getDate() const {
    return date;
}

string MedicalRecord::getDoctorName() const {
    return doctorName;
}

void MedicalRecord::setCondition(const string& condition) {
    this->condition = condition;
}

void MedicalRecord::setTreatment(const string& treatment) {
    this->treatment = treatment;
}

void MedicalRecord::setDate(const string& date) {
    this->date = date;
}

void MedicalRecord::setDoctorName(const string& doctorName) {
    this->doctorName = doctorName;
}