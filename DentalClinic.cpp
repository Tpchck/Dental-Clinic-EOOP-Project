//
// Created by Tpshck on 3/25/2024.
//
#include "DentalClinic.h"
#include "Appointment.h"
#include <stdexcept>
#include <algorithm>


DentalClinic::~DentalClinic() {
    for (Dentist *dentist: dentists) delete dentist;
    for (Patient *patient: patients) delete patient;
    for (Treatment *treatment: treatments) delete treatment;
    for (Appointment *appointment: appointments) delete appointment;
}

void DentalClinic::addDentist(const string &name, const string &specialization) {
    if (name.empty()) {
        cout << "Error: Dentist name cannot be empty." << endl;
        return;
    }
    Dentist* dentist = new Dentist(name, specialization);
    dentists.push_back(dentist);
}

void DentalClinic::addPatient(const string &name, int age, const string &contactInfo) {
    if (name.empty()) {
        cout << "Error: Patient name cannot be empty." << endl;
        return;
    }
    Patient* patient = new Patient(name, age, contactInfo);
    patients.push_back(patient);
}

void DentalClinic::addTreatment(const string &name, const string &description, double cost, const string &requiredSpecialization) {
    if (name.empty()) {
        cout << "Error: Treatment name cannot be empty." << endl;
        return;
    }
    Treatment* treatment = new Treatment(name, description, cost, requiredSpecialization);
    treatments.push_back(treatment);
}

Appointment* DentalClinic::bookAppointment(const string &date, const string &time, const Dentist* dentist, const Patient* patient, const Treatment* treatment) {
    if (!dentist) {
        cout << "Error: Dentist not found." << endl;
        return nullptr;
    }

    if (!patient) {
        cout << "Error: Patient not found." << endl;
        return nullptr;
    }

    if (!treatment) {
        cout << "Error: Treatment not found." << endl;
        return nullptr;
    }

    if (!isDentistAvailable(dentist, date, time)) {
        cout << "Error: Dentist is not available at the given date and time." << endl;
        return nullptr;
    }

    if (dentist->getSpecialization() != treatment->getRequiredSpecialization()) {
        cout << "Error: Dentist's specialization does not match the required treatment specialization." << endl;
        return nullptr;
    }

    Appointment* newAppointment = new Appointment(date, time, dentist, patient, treatment, *this);
    appointments.push_back(newAppointment);
    return newAppointment;
}

const Dentist* DentalClinic::findDentist(const string &name) const {
    string normalizedInputName = normalizeName(name);
    for (Dentist* dentist : dentists) {
        if (normalizeName(dentist->getName()) == normalizedInputName) {
            return dentist;
        }
    }
    cout << "Error: Dentist with name " << name << " not found." << endl;
    return nullptr;
}

const Patient* DentalClinic::findPatient(const string &name) const {
    string normalizedInputName = normalizeName(name);
    for (Patient* patient : patients) {
        if (normalizeName(patient->getName()) == normalizedInputName) {
            return patient;
        }
    }
    cout << "Error: Patient with name " << name << " not found." << endl;
    return nullptr;
}

string DentalClinic::normalizeName(const string& name) const {
    if (name.empty()) {
        cout << "Warning: Name cannot be empty" << endl;
        return "";
    }

    string normalized;
    normalized.reserve(name.size());
    for (char c : name) {
        if (c != ' ' && c != '-' && c != '\'') {
            normalized += c;
        }
    }

    transform(normalized.begin(), normalized.end(), normalized.begin(), ::tolower);

    return normalized;
}

const Treatment* DentalClinic::findTreatment(const string &name) const {
    for (Treatment* treatment : treatments) {
        if (treatment->getName() == name) {
            return treatment;
        }
    }
    return nullptr;
}
bool DentalClinic::isDentistAvailable(const Dentist* dentist, const string& date, const string& time) {
    for (Appointment* appointment : appointments) {
        if (appointment->getDentist() == dentist && appointment->getDate() == date && appointment->getTime() == time) {
            return false;
        }
    }
    return true;
}

const vector<Treatment*>& DentalClinic::getTreatments() const {
    return treatments;
}

const vector<Appointment*>& DentalClinic::getAppointments() const {
    return appointments;
}

void DentalClinic::addPatientMedicalRecord(int patientId, const vector<string>& medicalRecordDetails) {
    for (Patient* patient : patients) {
        if (patient->getId() == patientId) {
            MedicalRecord record(medicalRecordDetails[0], medicalRecordDetails[1], medicalRecordDetails[2], medicalRecordDetails[3]);
            patient->addMedicalRecord(record);
            return;
        }
    }
    cout << "Error: Patient with id " << patientId << " not found." << endl;
}

void DentalClinic::deleteAppointment(int appointmentId) {
    for (auto it = appointments.begin(); it != appointments.end(); ++it) {
        if ((*it)->getId() == appointmentId) {
            delete *it;
            appointments.erase(it);
            cout << "Appointment with id " << appointmentId << " has been deleted." << endl;
            return;
        }
    }
    cout << "Error: Appointment with id " << appointmentId << " not found." << endl;
}
