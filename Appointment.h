//
// Created by Tpshck on 3/25/2024.
//
#pragma once

#include <string>
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
    Dentist* dentist;
    Patient* patient;
    const Treatment* treatment;
    int id;
    static int lastId;
public:
    Appointment(const string& date, const string& time, Dentist* dentist, Patient* patient, const Treatment* treatment);
    ~Appointment();
    string getDate() const;
    string getTime() const;
    Dentist* getDentist() const;
    Patient* getPatient() const;
    const Treatment* getTreatment() const;
    int getId() const;
};