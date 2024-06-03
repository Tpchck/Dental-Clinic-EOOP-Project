//
// Created by Tpshck on 3/25/2024.
//
#include "Appointment.h"

Appointment::Appointment(const string& date, const string& time, Dentist* dentist, Patient* patient, const Treatment* treatment)
        : date(date), time(time), dentist(dentist), patient(patient), treatment(treatment) {
    id = ++lastId;
}

int Appointment::lastId = 0;

string Appointment::getDate() const {
    return date;
}

string Appointment::getTime() const {
    return time;
}

Dentist* Appointment::getDentist() const {
    return dentist;
}

Patient* Appointment::getPatient() const {
    return patient;
}

const Treatment* Appointment::getTreatment() const {
    return treatment;
}

int Appointment::getId() const {
    return id;
}

Appointment::~Appointment() {

}
