//
// Created by Tpshck on 3/25/2024.
//
#pragma once

#include <string>
#include "Dentist.h"
#include "Patient.h"
#include "Treatment.h"
#include <iostream>

class DentalClinic;

#ifndef DENTAL_CLINIC_EOOP_PROJECT_APPOINTMENT_H
#define DENTAL_CLINIC_EOOP_PROJECT_APPOINTMENT_H

#endif //DENTAL_CLINIC_EOOP_PROJECT_APPOINTMENT_H

using namespace std;

class Appointment {
private:
    string date;
    string time;
    const Dentist* dentist;
    const Patient* patient;
    const Treatment* treatment;
    DentalClinic& clinic;

    int id;
    static int lastId;

public:
    Appointment(const string &date, const string &time, const Dentist* dentist, const Patient* patient, const Treatment* treatment, DentalClinic& clinic);
    string getDate() const;
    string getTime() const;
    int getId() const;
    const Dentist* getDentist() const;
    const Patient* getPatient() const;
    const Treatment* getTreatment() const;

    void editDate(const string &newDate);
    void editTime(const string &newTime);
    void editDentist(const Dentist* newDentist);
    void editPatient(const Patient* newPatient);
    void setTreatment(const Treatment* newTreatment);
};