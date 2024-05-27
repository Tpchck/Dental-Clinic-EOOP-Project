//
// Created by Tpshck on 3/25/2024.
//

#include "DentalClinic.h"
#include "Treatment.h"
#include "Appointment.h"
#include "System.h"
#include "DentistsRegistry.h"
#include "PatientsRegistry.h"

using namespace std;

int main() {
    DentalClinic clinic1;
    DentalClinic clinic2;

    DentistsRegistry dentistsRegistry;
    PatientsRegistry patientsRegistry;

    dentistsRegistry.addDentist("Dr. Smith", "Orthodontics");
    patientsRegistry.addPatient("John Doe", 30, "1234567890");

    dentistsRegistry.addDentist("Dr. Johnson", "General Dentistry");
    patientsRegistry.addPatient("Morgan Freeman", 28, "0987654321");

    Treatment treatment1("Teeth Cleaning", "A procedure for the removal of tartar and stains from teeth", 50.0, "General Dentistry");
    Treatment treatment2("Root Canal", "A treatment to repair and save a badly damaged or infected tooth", 200.0, "Orthodontics");


    Dentist* dentist1 = nullptr;
    Patient* patient1 = nullptr;

    if((dentist1 = dentistsRegistry.findDentist("Dr. Smith")) == nullptr) {
        cout << "Dentist not found." << endl;
        return 1;               //TODO handle possible errors
    }

    if((patient1 = patientsRegistry.findPatient("John Doe")) == nullptr) {
        cout << "Patient not found." << endl;
        return 1;
    }

    patientsRegistry.printAllPatients();
    dentistsRegistry.printAllDentists();

    clinic1.addDentist(dentist1->getName(), dentist1->getSpecialization());
    clinic1.addPatient(patient1->getName(), patient1->getAge(), patient1->getPhoneNumber());

    clinic2.addDentist(dentist1->getName(), dentist1->getSpecialization());
    clinic2.addPatient(patient1->getName(), patient1->getAge(), patient1->getPhoneNumber());

    clinic1.bookAppointment("2024-05-01", "10:00", dentist1, patient1, &treatment1);  //TODO finish method implementation
    clinic2.bookAppointment("2024-05-02", "14:00", dentist1, patient1, &treatment2);

    cout << "Clinic 1 Appointments:" << endl;
    clinic1.printAllAppointments();
    clinic1.removeAppointment("2024-05-01", "10:00", patient1);
    clinic1.printAllAppointments();

    cout << "Clinic 1 Dentists:" << endl;
    clinic1.printAllDentists();

    cout << "Clinic 1 Patients:" << endl;
    clinic1.printAllPatients();

    cout << "Clinic 2 Dentists:" << endl;
    clinic2.printAllDentists();

    cout << "Clinic 2 Patients:" << endl;
    clinic2.printAllPatients();

    return 0;
}
