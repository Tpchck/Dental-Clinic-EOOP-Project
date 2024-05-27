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

    dentistsRegistry.addDentist("Dr. Johnson", "Pediatric Dentistry");
    patientsRegistry.addPatient("Jane Doe", 28, "0987654321");

    Treatment treatment1("Teeth Cleaning", "A procedure for the removal of tartar and stains from teeth", 50.0, "General Dentistry");
    Treatment treatment2("Root Canal", "A treatment to repair and save a badly damaged or infected tooth", 200.0, "Endodontics");

    Dentist* dentist1 = dentistsRegistry.findDentist("Dr. Smith");
    Patient* patient1 = patientsRegistry.findPatient("John Doe");

    Dentist* dentist2 = dentistsRegistry.findDentist("Dr. Johnson");
    Patient* patient2 = patientsRegistry.findPatient("Jane Doe");

    // Add dentists and patients to the clinics
    clinic1.addDentist(dentist1->getName(), dentist1->getSpecialization());
    clinic1.addPatient(patient1->getName(), patient1->getAge(), patient1->getPhoneNumber());

    clinic2.addDentist(dentist2->getName(), dentist2->getSpecialization());
    clinic2.addPatient(patient2->getName(), patient2->getAge(), patient2->getPhoneNumber());

    Appointment* appointment1 = clinic1.bookAppointment("2024-05-01", "10:00", dentist1, patient1, &treatment1);
    Appointment* appointment2 = clinic2.bookAppointment("2024-05-02", "14:00", dentist2, patient2, &treatment2);

    if (appointment1 == nullptr || appointment2 == nullptr) {
        cout << "Failed to book an appointment." << endl;
        return 1;
    }

    cout << "Clinic 1 Dentists:" << endl;
    printAllDentists(clinic1.getDentists());

    cout << "Clinic 1 Patients:" << endl;
    printAllPatients(clinic1.getPatients());

    cout << "Clinic 2 Dentists:" << endl;
    printAllDentists(clinic2.getDentists());

    cout << "Clinic 2 Patients:" << endl;
    printAllPatients(clinic2.getPatients());

    return 0;
}
