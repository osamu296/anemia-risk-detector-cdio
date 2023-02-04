#ifndef EVALUATION_H_INCLUDED
#define EVALUATION_H_INCLUDED

int normal(float, float, float);
int redbloodcell(float,float,int,char);
int haemoglobin(float,float,int,char);
int hematocrit(float,float,int,char);
int lymphocytes(float,float,char);
int monocytes(float,float,char);
int eosinophils(float,float,int,char);
int basophils(float,float,int,char);
int bilirubin(float,float,char);
int reticulocytes(float,float,char);
int whitebloodcell (float,float,char);
int mcv_f(float,float,char);
int mch_f(float,float,char);
int mchc_f(float,float,char);
int neutrophils(float,float,char);
void diagnose(float age, int gender,char c_age);

extern int j;
extern int k;
extern int RBCvalue;
extern int HCTvalue;
extern int HBvalue;
extern int RCvalue;
extern int MCVvalue;
extern int WBCvalue;
extern int BILIvalue;

extern char diagnoseResult[];

#endif // EVALUATION_H_INCLUDED
