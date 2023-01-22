#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<time.h>
#include <dos.h>
#include <dir.h>
#include <windows.h>

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


    printf("ic number       : ");
    scanf("%s",&user.ic);

     for (i=0;i<2;i++)
 {
     user.byear[i]=user.ic[i];
     user.bmonth[i]=user.ic[i+2];
     user.bday[i]=user.ic[i+4];
     //state[i]=user.ic[i+6];
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
     printf("Birth date (dd/mm/yyyy)           : %d/ %d / %d \n", dy,mt,year_birth);
 }
    else
 {
     year_birth=yr + 2000;
     printf("Birth date (dd/mm/yyyy)           : %d / %d / %d \n", dy,mt,year_birth);
 }

    printf("Age                               : %d years %d month %d days \n", age_inyear,age_inmonth,age_indays);

    if(gender1==1)
     {
      printf("Gender                            : Male\n");
     }
     else
     {
      printf("Gender                            : Female\n");
     }
    return 0;
}
