#ifndef EC_PATIENT_H_INCLUDED
#define EC_PATIENT_H_INCLUDED

float normal(float, float, float);
float redbloodcell(float,float,int);
float haemoglobin(float,float,int);
float hematocrit(float,float,int);
float lymphocytes(float,float);
float monocytes(float,float);
float eosinophils(float,float,int);
float basophils(float,float,int);
float bilirubin(float,float);
float reticulocytes(float,float);
float whitebloodcell (float,float);
float mcv_f(float,float);
float mch_f(float,float);
float mchc_f(float,float);
float neutrophils(float,float);

extern int j;
extern int k;

#endif // EC_PATIENT_H_INCLUDED

