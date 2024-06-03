//
// Created by Tpshck on 3/25/2024.
//

#include "DentalClinic.h"
#include "Appointment.h"
#include <iostream>
#include "Dentist.h"

DentalClinic::DentalClinic(const string& name): name(name) {}

void DentalClinic::addDentist(Dentist* dentist) {
    dentists.push_back(dentist);
    dentist->addClinics(this);
}

void DentalClinic::removeDentist(Dentist* dentist) {
    for (auto it = dentists.begin(); it != dentists.end(); ++it) {
        if (*it == dentist) {
            dentists.erase(it);
            break;
        }
    }
    dentist->removeClinic(this);
}

void DentalClinic::addPatient(Patient* patient) {
    patients.push_back(patient);
    patient->addClinics(this);
}

void DentalClinic::removePatient(Patient* patient) {
    for (auto it = patients.begin(); it != patients.end(); ++it) {
        if (*it == patient) {
            patients.erase(it);
            break;
        }
    }
    patient->removeClinic(this);
}

Appointment* DentalClinic::bookAppointment(const string& date, const string& time, Dentist* dentist, Patient* patient, Treatment* treatment) {
    // Parameter validation
    if (date.empty() || time.empty() || !dentist || !patient || !treatment) {
        cout << "Error: Invalid parameters." << endl;
        return nullptr;
    }

    if (!dentist->isAvailable(date, time)) {
        cout << "Error: The dentist is not available at the given date and time." << endl;
        return nullptr;
    }

    if (!dentist->canPerformTreatment(treatment)) {
        cout << "Error: The dentist cannot perform the required treatment." << endl;
        return nullptr;
    }

    for (const auto& appointment : patient->getAppointments()) {
        if (appointment->getDate() == date && appointment->getTime() == time) {
            cout << "Error: The patient is already booked for another appointment at the same date and time." << endl;
            return nullptr;
        }
    }

    Appointment* appointment = new Appointment(date, time, dentist, patient, treatment);
    appointments.push_back(appointment);
    dentist->addAppointment(appointment);
    patient->addAppointment(appointment);

    // Create a medical record for the appointment
    MedicalRecord* record = new MedicalRecord(appointment);
    patient->addMedicalRecord(record);

    return appointment;
}

void DentalClinic::cancelAppointment(Appointment* appointment) {
    for (auto it = appointments.begin(); it != appointments.end(); ++it) {
        if (*it == appointment) {
            appointments.erase(it);
            break;
        }
    }
    appointment->getDentist()->removeAppointment(appointment);
    appointment->getPatient()->removeAppointment(appointment);
    delete appointment;
}

Dentist* DentalClinic::findDentist(const string& name) {
    for (Dentist* dentist : dentists) {
        if (dentist->getName() == name) {
            return dentist;
        }
    }
    cout << "Error: Dentist " << name << " is not in the clinic." << endl;
    return nullptr;
}

Patient* DentalClinic::findPatient(const string& name) {
    for (Patient* patient : patients) {
        if (patient->getName() == name) {
            return patient;
        }
    }
    cout << "Error: Patient " << name << " is not found." << endl;
    return nullptr;
}

vector<Dentist*> DentalClinic::getDentists() const {
    return dentists;
}

vector<Patient*> DentalClinic::getPatients() const {
    return patients;
}

void DentalClinic::printAllAppointments() const {
    for (const auto& appointment : appointments) {
        cout << "-------------------------------------------------------------------------------" << endl;
        cout << "Appointment ID: " << appointment->getId() << ", "
             << "Date: " << appointment->getDate() << ", "
             << "Time: " << appointment->getTime() << ", "
             << "Dentist: " << appointment->getDentist()->getName() << ", "
             << "Patient: " << appointment->getPatient()->getName() << ", "
             << "Treatment: " << appointment->getTreatment()->getName() << endl;
    }
}

void DentalClinic::printAllDentists() const {
    for (const auto& dentist : dentists) {
        cout << "-------------------------------------------------------------------------------" << endl;
        cout << "Dentist ID: " << dentist->getId() << ", "
             << "Name: " << dentist->getName() << ", "
             << "Specialization: " << dentist->getSpecialization() << endl;
        cout << "-------------------------------------------------------------------------------" << endl;
    }
}

void DentalClinic::printAllPatients() const {
    for (const auto& patient : patients) {
        cout << "-------------------------------------------------------------------------------" << endl;
        cout << "Patient ID: " << patient->getId() << ", "
             << "Name: " << patient->getName() << ", "
             << "Age: " << patient->getAge() << ", "
             << "Phone Number: " << patient->getPhoneNumber() << endl;
        cout << "-------------------------------------------------------------------------------" << endl;
    }
}

void DentalClinic::removeAppointment(const string& date, const string& time, const Patient* patient) {
    for (auto it = appointments.begin(); it != appointments.end(); ++it) {
        if ((*it)->getDate() == date && (*it)->getTime() == time && (*it)->getPatient() == patient) {
            (*it)->getDentist()->removeAppointment(*it);
            (*it)->getPatient()->removeAppointment(*it);
            appointments.erase(it);
            break;
        }
    }
}

vector<Appointment*> DentalClinic::getAppointments() const {
    return appointments;
}

vector<Treatment*> DentalClinic::getTreatments() const {
    return treatments;
}

string DentalClinic::getName() const {
    return name;
}

Treatment* DentalClinic::findTreatment(const string& name) {
    for (Treatment* treatment : treatments) {
        if (treatment->getName() == name) {
            return treatment;
        }
    }
    cout << "Error: Treatment " << name << " is not found." << endl;
    return nullptr;
}

DentalClinic::~DentalClinic() {

}
