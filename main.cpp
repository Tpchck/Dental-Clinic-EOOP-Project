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
    try {
        DentalClinic clinic1;
        DentalClinic clinic2;

        DentistsRegistry dentistsRegistry;
        PatientsRegistry patientsRegistry;

        dentistsRegistry.addDentist("Dr. Smith", "Orthodontics");
        patientsRegistry.addPatient("John Doe", 30, "1234567890");

        dentistsRegistry.addDentist("Dr. Johnson", "Pediatric Dentistry");
        patientsRegistry.addPatient("Morgan Freeman", 28, "0987654321");

        Treatment treatment1("Teeth Cleaning", "A procedure for the removal of tartar and stains from teeth", 50.0, "General Dentistry");
        Treatment treatment2("Root Canal", "A treatment to repair and save a badly damaged or infected tooth", 200.0, "Endodontics");


        Dentist* dentist1 = dentistsRegistry.findDentist("Dr. Smith");
        Patient* patient1 = patientsRegistry.findPatient("John Doe");

        if (dentist1 == nullptr || patient1 == nullptr) {
            throw std::runtime_error("Dentist or patient not found.");
        }

        patientsRegistry.printAllPatients();
        dentistsRegistry.printAllDentists();

        // Add dentists and patients to the clinics
        clinic1.addDentist(dentist1->getName(), dentist1->getSpecialization());
        clinic1.addPatient(patient1->getName(), patient1->getAge(), patient1->getPhoneNumber());

        clinic2.addDentist(dentist1->getName(), dentist1->getSpecialization());
        clinic2.addPatient(patient1->getName(), patient1->getAge(), patient1->getPhoneNumber());

        Appointment* appointment1 = clinic1.bookAppointment("2024-05-01", "10:00", dentist1, patient1, &treatment1);
        Appointment* appointment2 = clinic2.bookAppointment("2024-05-02", "14:00", dentist1, patient1, &treatment2);

        if (appointment1 == nullptr || appointment2 == nullptr) {
            throw std::runtime_error("Failed to book an appointment.");
        }

        cout << "Clinic 1 Dentists:" << endl;
        clinic1.printAllDentists();

        cout << "Clinic 1 Patients:" << endl;
        clinic1.printAllPatients();

        cout << "Clinic 2 Dentists:" << endl;
        clinic2.printAllDentists();

        cout << "Clinic 2 Patients:" << endl;

        clinic2.printAllPatients();

        return 0;
    } catch (const std::bad_alloc& e) {
        cout << "Memory allocation failed: " << e.what() << '\n';
        return 1;
    } catch (const std::runtime_error& e) {
        cout << e.what() << '\n';
        return 1;
    } catch (const std::exception& e) {
        cout << "An error occurred: " << e.what() << '\n';
        return 1;
    }
}
