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
    int id;
    static int lastId;
public:
    Appointment(const string& date, const string& time, const Dentist* dentist, const Patient* patient, const Treatment* treatment);
    string getDate() const;
    void setDate(const string& date);
    string getTime() const;
    void setTime(const string& time);
    const Dentist* getDentist() const;
    void setDentist(const Dentist* dentist);
    const Patient* getPatient() const;
    void setPatient(const Patient* patient);
    const Treatment* getTreatment() const;
    void setTreatment(const Treatment* treatment);
    int getId() const;
};