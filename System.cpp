//
// Created by Tpshck on 4/4/2024.
//

#include "System.h"
#include <iostream>

using namespace std;

void printAllTreatments(const vector<Treatment*>& treatments) {
    cout << "-----------------------------------------------------------" << endl;
    if (treatments.empty()) {
        cout << "No treatments available." << endl;
        return;
    }
    cout << "Available Treatments:" << endl;
    for (const Treatment *treatment: treatments) {
        cout << "Name: " << treatment->getName() << ", "
             << "Description: " << treatment->getDescription() << ", "
             << "Cost: $" << treatment->getCost() << endl;
    }
    cout << "-----------------------------------------------------------" << endl;
}

void printAllAppointments(const vector<Appointment*>& appointments) {
    cout << "-----------------------------------------------------------" << endl;
    if (appointments.empty()) {
        cout << "No appointments available." << endl;
        return;
    }
    cout << "Appointments:" << endl;
    for (const Appointment *appointment: appointments) {
        cout
             << "Date: " << appointment->getDate() << ", "
             << "Time: " << appointment->getTime() << ", "
             << "Dentist: " << appointment->getDentist()->getName() << ", "
             << "Patient: " << appointment->getPatient()->getName() << ", "
             << "Treatment: " << appointment->getTreatment()->getName() << endl;
    }
    cout << "-----------------------------------------------------------" << endl;
}

void printAllDentists(const vector<Dentist*>& dentists) {
    cout << "-----------------------------------------------------------" << endl;
    if (dentists.empty()) {
        cout << "No dentists available." << endl;
        return;
    }
    cout << "Available Dentists:" << endl;
    for (const Dentist *dentist: dentists) {
        cout << "Name: " << dentist->getName() << ", "
             << "Specialization: " << dentist->getSpecialization() << endl;
    }
    cout << "-----------------------------------------------------------" << endl;
}

void printAllPatients(const vector<Patient*>& patients) {
    cout << "-----------------------------------------------------------" << endl;
    if (patients.empty()) {
        cout << "No patients available." << endl;
        return;
    }
    cout << "Registered Patients:" << endl;
    for (const Patient *patient: patients) {
        cout << "Name: " << patient->getName() << ", "
             << "Age: " << patient->getAge() << ", "
             << "Phone Number: " << patient->getPhoneNumber() << endl;
    }
    cout << "-----------------------------------------------------------" << endl;
}