//
// Created by Tpshck on 3/25/2024.
//
#include "Appointment.h"

Appointment::Appointment(const string& date, const string& time, const Dentist* dentist, const Patient* patient, const Treatment* treatment)
        : date(date), time(time), dentist(dentist), patient(patient), treatment(treatment) {
    id = ++lastId;
}

int Appointment::lastId = 0;

string Appointment::getDate() const {
    return date;
}

void Appointment::setDate(const string& date) {
    this->date = date;
}

string Appointment::getTime() const {
    return time;
}

void Appointment::setTime(const string& time) {
    this->time = time;
}

const Dentist* Appointment::getDentist() const {
    return dentist;
}

void Appointment::setDentist(const Dentist* dentist) {
    this->dentist = dentist;
}

const Patient* Appointment::getPatient() const {
    return patient;
}

void Appointment::setPatient(const Patient* patient) {
    this->patient = patient;
}

const Treatment* Appointment::getTreatment() const {
    return treatment;
}

void Appointment::setTreatment(const Treatment* treatment) {
    this->treatment = treatment;
}

int Appointment::getId() const {
    return id;
}