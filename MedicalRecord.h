//
// Created by Tpshck on 4/7/2024.
//

#pragma ocne

#include <string>


#ifndef DENTAL_CLINIC_EOOP_PROJECT_MEDICALRECORD_H
#define DENTAL_CLINIC_EOOP_PROJECT_MEDICALRECORD_H

#endif //DENTAL_CLINIC_EOOP_PROJECT_MEDICALRECORD_H

using namespace std;

class MedicalRecord {
private:
    string condition;
    string treatment;
    string date;
    string doctorName;

public:
    MedicalRecord(const string& condition, const string& treatment, const string& date, const string& doctorName);

    string getCondition() const;
    string getTreatment() const;
    string getDate() const;
    string getDoctorName() const;

    void setCondition(const string& condition);
    void setTreatment(const string& treatment);
    void setDate(const string& date);
    void setDoctorName(const string& doctorName);
};