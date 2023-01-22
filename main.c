#include <stdio.h>
#include <stdlib.h>
#include"ec_patient.h"

struct parameter{

    float lc;
    float mono_c;
    float bc;
    float ec;
    float bili;
    float rc;
    float hb;
    float rbc;
    float hct;
};

struct p_i{
    float age;
    char gender;
};

int main()
{
    struct parameter user1;
    struct p_i user;
    float age;
    char f,m,c,gender;
    int s_lc=0,s_mono_c=0,s_bc=0,s_ec=0,s_bili=0,s_rc=0,s_hb=0,s_rbc=0,s_hct=0;
    float result;
    float calc,calc2,calc3,calc4,calc5,calc6;
    float calc7,calc8,calc9;

    printf("\n******************\n");
    printf(" Age = ");
    scanf("%f",&user.age);
    printf(" gender (f/m)=");
    fflush(stdin);
    scanf("%c",&user.gender);

    while(user1.rbc < 0 || s_rbc != 1)
    {
        printf(" Red Blood Cell count: ");
        s_rbc = scanf("%f",&user1.rbc);
    }

    while(user1.hb < 0 || s_hb != 1)
    {
        printf(" Haemoglobin count : ");
        s_hb = scanf("%f",&user1.hb);
    }

    while(user1.hct < 0 || s_hct != 1)
    {
        printf(" Haematocrit count : ");
        s_hct = scanf("%f",&user1.hct);
    }

    while(user1.lc < 0 || s_lc != 1)
    {
        printf(" lymphocyte : ");
        s_lc = scanf("%f",&user1.lc);
    }

    while(user1.mono_c < 0 || s_mono_c != 1)
    {
         printf(" monocytes: ");
        s_mono_c = scanf("%f",&user1.mono_c);
    }

    while(user1.ec < 0 || s_ec != 1)
    {
        printf(" eosinophils: ");
        s_ec = scanf("%f",&user1.ec);
    }

    while(user1.bc < 0 || s_bc != 1)
    {
        printf(" basophils: ");
        s_bc = scanf("%f",&user1.bc);
    }

    while(user1.bili < 0 || s_bili != 1)
    {
        printf(" Total bilirubin: ");
        s_bili = scanf("%f",&user1.bili);
    }

    while(user1.rc < 0 || s_rc != 1)
    {
        printf(" reticulocyte count: ");
        s_rc = scanf("%f",&user1.rc);
    }

    calc = lymphocytes(user.age,user1.lc);
    calc2 = monocytes(user.age,user1.mono_c);
    calc3 = eosinophils(user.age,user1.ec,user.gender);
    calc4 = basophils(user.age,user1.bc,user.gender);
    calc5 = bilirubin(user.age,user1.bili);
    calc6 = reticulocytes(user.age,user1.rc);
    calc7 = redbloodcell(user.age,user1.rbc,user.gender);
    calc8 = haemoglobin(user.age,user1.hb,user.gender);
    calc9 = hematocrit(user.age,user1.hct,user.gender);

    printf("\n------------------------");
    printf("Patient Record");
    printf("------------------------");
    printf("\n Red Blood Cell     : %.2f",user1.rbc);
    printf("\n Haemoglobin        : %.2f",user1.hb);
    printf("\n Hematocrit         : %.2f",user1.hct);
    printf("\n lymphocyte         : %.2f",user1.lc);
    printf("\n monocytes          : %.2f",user1.mono_c);
    printf("\n eosinophils        : %.2f",user1.ec);
    printf("\n basophils          : %.2f",user1.bc);
    printf("\n Total bilirubin    : %.2f",user1.bili);
    printf("\n Reticulocyte Count : %.2f",user1.rc);
    return 0;
}
