#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<time.h>
#include <dos.h>
#include <dir.h>
#include <windows.h>
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
struct parameter user1;

struct p_i{
    char ic[13];
    char bday[5];
    char bdate[5];
    char bmonth[5];
    char byear[5];
    char gender[5];
};
struct p_i user;

int main()
{
    int i=0;
    int yr,mt,dy,st,gd;
    int gender1,year_birth,days_inmonth, month_birth;
    time_t t;
    //parameter initialization
    int s_lc=0,s_mono_c=0,s_bc=0,s_ec=0,s_bili=0,s_rc=0,s_hb=0,s_rbc=0,s_hct=0;
    float result;
    float calc,calc2,calc3,calc4,calc5,calc6;
    float calc7,calc8,calc9;

    printf("IC number       : ");
    scanf("%s",&user.ic);

    while(user1.rbc < 0 || s_rbc != 1)
    {
        printf("\n Red Blood Cell count: ");
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
    //accesing every char in the user.ic array
    for (i=0;i<2;i++)
    {
     user.byear[i]=user.ic[i];
     user.bmonth[i]=user.ic[i+2];
     user.bday[i]=user.ic[i+4];
     user.gender[i]=user.ic[i+10];
    }
    //change the string char to int
    yr=atoi(user.byear);
    mt=atoi(user.bmonth);
    dy=atoi(user.bday);
    gd=atoi(user.gender);
    time(&t);
     //calculating gender
    gender1=gd&1;

    //CALCULATE MONTHS USING IC
     if(mt==1)
    {
        days_inmonth=31;
    }
    if(mt==2)
    {
        days_inmonth=29;
    }
    if(mt==3)
    {
        days_inmonth=31;
    }
    if(mt==4)
    {
        days_inmonth=30;
    }
    if(mt==5)
    {
        days_inmonth=31;
    }
    if(mt==6)
    {
        days_inmonth=30;
    }
    if(mt==7)
    {
        days_inmonth=31;
    }
    if(mt==8)
    {
        days_inmonth=31;
    }
    if(mt==9)
    {
        days_inmonth=30;
    }
    if(mt==10)
    {
        days_inmonth=31;
    }
    if(mt==11)
    {
        days_inmonth=30;
    }
    if(mt==12)
    {
        days_inmonth=31;
    }
    //real time age (using syntax time.h)
    struct tm tm=*localtime(&t);

    int age_inyear =(tm.tm_year+1900)-yr-1900;
    int age_inmonth =(tm.tm_mon + 1)- mt;
    int age_indays=(tm.tm_mday)- dy;

    if (age_inyear>=100)
    {
       age_inyear =(tm.tm_year+ 0000)-yr-100;
    }
    if (age_inmonth<=0)
    {
     age_inyear =(tm.tm_year+ 0000)-yr-1-100;
     age_inmonth= 12 + (tm.tm_mon + 1)- mt;
    }
    if (age_indays<=0)
    {
       age_inmonth =(tm.tm_mon + 1) + mt;
       age_indays = days_inmonth+(tm.tm_mday)-dy;
    }
   if (yr>=20&&yr<100)
    {
     year_birth=yr +1900;
     //printf("Birth date (dd/mm/yyyy)           : %d/ %d / %d \n", dy,mt,year_birth);
    }
    else
    {
     year_birth=yr + 2000;
     //printf("Birth date (dd/mm/yyyy)           : %d / %d / %d \n", dy,mt,year_birth);
    }

    calc = lymphocytes(age_inyear,user1.lc);
    calc2 = monocytes(age_inyear,user1.mono_c);
    calc3 = eosinophils(age_inyear,user1.ec,gender1);
    calc4 = basophils(age_inyear,user1.bc,gender1);
    calc5 = bilirubin(age_inyear,user1.bili);
    calc6 = reticulocytes(age_inyear,user1.rc);
    calc7 = redbloodcell(age_inyear,user1.rbc,gender1);
    calc8 = haemoglobin(age_inyear,user1.hb,gender1);
    calc9 = hematocrit(age_inyear,user1.hct,gender1);


    //summary report
    printf("\n------------------------");
    printf("Patient Record");
    printf("------------------------");
    if(gender1==1)
     {
      printf("\n Gender                            : Male\n");
     }
     else
     {
      printf("\n Gender                            : Female\n");
     }
    printf(" Age                               : %d years %d month %d days \n", age_inyear,age_inmonth,age_indays);

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
