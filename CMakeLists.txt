cmake_minimum_required(VERSION 3.26)
project(Dental_Clinic_EOOP_project)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Dental_Clinic_EOOP_project
        main.cpp
        DentalClinic.h
        Patient.h
        Patient.cpp
        Appointment.cpp
        Appointment.h
        Dentist.cpp
        Dentist.h
        DentalClinic.cpp
        Treatment.cpp
        Treatment.h
        System.cpp
        System.h
        MedicalRecord.cpp
        MedicalRecord.h
        Tests.cpp
        Tests.h
)
