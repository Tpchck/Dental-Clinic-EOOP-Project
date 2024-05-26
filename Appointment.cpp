//
// Created by Tpshck on 3/25/2024.
//

#include "Appointment.h"
#include "DentalClinic.h"

int Appointment::lastId = 0;

Appointment::Appointment(const string &date, const string &time, const Dentist* dentist, const Patient* patient, const Treatment* treatment, DentalClinic& clinic)
        : id(++lastId), date(date), time(time), dentist(dentist), patient(patient), treatment(treatment), clinic(clinic) {}

const Dentist* Appointment::getDentist() const {
    return dentist;
}

const Patient* Appointment::getPatient() const {
    return patient;
}

const Treatment* Appointment::getTreatment() const {
    return treatment;
}

void Appointment::editDentist(const Dentist* newDentist) {
    dentist = newDentist;
}

void Appointment::editPatient(const Patient* newPatient) {
    patient = newPatient;
}

void Appointment::setTreatment(const Treatment* newTreatment) {
    treatment = newTreatment;
}

string Appointment::getTime() const {
    return time;
}

string Appointment::getDate() const {
    return date;
}

int Appointment::getId() const {
    return id;
}

void Appointment::editDate(const string &newDate) {
    date = newDate;
    cout << "Appointment has been changed" << endl;
}

void Appointment::editTime(const string &newTime) {
    if (!clinic.isDentistAvailable(dentist, date, newTime)) {
        cout << "Error: Dentist is not available at the given date and time. Appointment id: " << id << endl;
        return;
    }
    time = newTime;
}
