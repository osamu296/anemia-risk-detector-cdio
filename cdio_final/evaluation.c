#include<stdio.h>
#include <string.h>
#include"evaluation.h"

int k = 0;
int j = 0;
int RBCvalue = 0;
int HCTvalue = 0;
int HBvalue = 0;
int RCvalue = 0;
int MCVvalue = 0;
int WBCvalue = 0;
int BILIvalue = 0;
char diagnoseResult[] = "NOTHING";


//x-lower range
//y-upper range
//i - input
/*
    normal function will return 3 values, -1, 0, 1
    -1 -> lower than range
    0 -> in range
    1 -> higher than range
*/
int normal(float x,float y,float i){

    if(i >= x && i <= y)
        return 0;
    else if (i < x) return -1;
    else if (i > y) return 1;
}

int lymphocytes(float age,float y,char c_age){

    char f,m,gender;
    int result = 0;
    float a,b,calc;

    if(age>=18 && c_age == 'y' ){
        a = 1.0;
        b = 4.5;
        result = normal(a, b, y);
    }
    else if (age < 18 && c_age == 'y'){

        if(age >= 12 && age <= 18){
            a = 1.1;
            b = 4.5;
            result = normal(a, b, y);
        }
        else if(age >= 6 && age <= 12){
            a = 1.5;
            b = 7.0;
            result = normal(a, b, y);
        }
        else if(age >= 1 && age <= 6){
            a = 1.5;
            b = 9.5;
            result = normal(a, b, y);
        }
        else if(age >= 0.5 && age <= 1 ){
            a = 4.0;
            b = 12.0;
            result = normal(a, b, y);
        }
    }
    else if(c_age == 'm' && age>=2 && age<= 6){
        a = 4.0;
        b = 10.0;
        result = normal(a, b, y);
    }
    return result;
}

int monocytes(float age,float y,char c_age){

    char f,m,gender;
    int result = 0;
    float a,b,calc2;

    if(age >= 18 && c_age == 'y' ){
        a = 0.2;
        b = 0.8;
        result = normal(a, b, y);
    }
    else if (age < 18 ){

        if(age >= 0.5 && age <= 17){
            a = 0.2;
            b = 1.0;
            result = normal(a, b, y);
        }
    }
    else if(c_age == 'm' && age>=2 && age<= 6){
        a = 0.4;
        b = 1.2;
        result = normal(a, b, y);
    }
    return result;
}

int eosinophils(float age,float y,int gender,char c_age){

    char f,m;
    int result = 0;
    float a,b,calc3;

    if(age >= 18 && gender == 0 && c_age == 'y'){
        a = 0.04;
        b = 0.4;
        result = normal(a, b, y);
    }
    else if(age >= 18 && gender == 1 && c_age == 'y'){
        a = 0.04;
        b = 0.5;
        result = normal(a, b, y);
    }
    else if (age < 18  ){

        if(age >= 12 && age <= 17){
            a = 0.0 ;
            b = 0.81;
            result = normal(a, b, y);}
        else if(age >= 6 && age <= 11){
            a = 0.0;
            b = 0.81;
            result = normal(a, b, y);}
        else if(age >= 0.5 && age <= 1){
            a = 0.0;
            b = 0.81;
            result = normal(a, b, y);
        }
    }
    return result;
}

int basophils(float age,float y,int gender,char c_age){

    char f,m;
    int result = 0;
    float a,b,calc4;

    if(age >= 18 && gender == 0){
        a = 0.00;
        b = 0.1;
        result = normal(a, b, y);
    }
    else if(age >= 18 && gender == 1 ){
        a = 0.00;
        b = 0.2;
        result = normal(a, b, y);
    }
    else if (age < 18 ){

        if(age >= 0.5 && age <= 17 ){
            a = 0.0 ;
            b = 0.21;
            result = normal(a, b, y);}

        }
    return result;
}
int bilirubin(float age,float y,char c_age){

    char f,m;
    int result = 0;
    float a,b,calc5;

    if(age >= 18 ){
        a = 0.1;
        b = 1.2;
        result = normal(a, b, y);
    }
    else if (age < 18 ){

        if(age >= 1 && age <= 17 ){
            a = 0.3 ;
            b = 0.1;
            result = normal(a, b, y);}

        }
    return result;
}
int reticulocytes(float age,float y,char c_age){

    char f,m;
    int result = 0;
    float a,b,calc6;

    if(age >= 18 && c_age == 'y'){
        a = 0.5;
        b = 2.5;
        result = normal(a, b, y);
    }
    else if (age < 18 && c_age == 'y' ){

        if(age >= 1 && age <= 17 ){
            a = 0.5 ;
            b = 2.0;
            result = normal(a, b, y);}
        }
    else if(c_age == 'm' && age>=2 && age<= 6){
        a = 0.5;
        b = 3.1;
        result = normal(a, b, y);
    }
    return result;
}

int redbloodcell(float age,float y,int gender,char c_age){

    char f,m;
    int result = 0;
    float a,b,calc7;

    if(age >= 18 && gender == 0 && c_age == 'y' ){
        a = 3.8;
        b = 5.8;
        result = normal(a, b, y);
    }
    else if(age >= 18 && gender == 1 && c_age == 'y'){
        a = 4.5;
        b = 6.5;
        result = normal(a, b, y);
    }
    else if (age < 18 && c_age == 'y' ){

        if(age >= 12 && age <= 17 && gender== 1){
            a = 4.5 ;
            b = 5.3;
            result = normal(a, b, y);}
        else if(age >= 12 && age <= 17 && gender== 0 ){
            a = 4.1 ;
            b = 5.1;
            result = normal(a, b, y);}
        else if(age >= 6 && age <= 11){
            a = 4.0;
            b = 5.2;
            result = normal(a, b, y);}
        else if(age >= 1.0 && age <= 5){
            a = 3.9;
            b = 5.3;
            result = normal(a, b, y);
        }
    }
    else if ( c_age == 'm'){
        if ( age >= 2 && age <= 6 ){
            a = 3.1;
            b = 4.3;
            result = normal(a,b,y);
        }
    }
    return result;
}

int haemoglobin(float age,float y,int gender,char c_age){

    char f,m;
    int result = 0;
    float a,b,calc8;

    if(age >= 18 && gender == 0 && c_age == 'y'){
        a = 115;
        b = 160;
        result = normal(a, b, y);
    }
    else if(age >= 18 && gender == 1 && c_age == 'y'){
        a = 135;
        b = 180;
        result = normal(a, b, y);
    }
    else if (age < 18 && c_age == 'y'){

        if(age >= 12 && age <= 17 && gender== 1 ){
            a = 130;
            b = 170;
            result = normal(a, b, y);}
        else if(age >= 12 && age <= 17 && gender== 0 ){
            a = 120 ;
            b = 160;
            result = normal(a, b, y);}
        else if(age >= 6 && age <= 11){
            a = 115;
            b = 155;
            result = normal(a, b, y);}
        else if(age >= 1.0 && age <= 5){
            a = 115;
            b = 140;
            result = normal(a, b, y);
        }
    }
    else if(c_age == 'm' && age>=2 && age<= 6){
        a = 94.0;
        b = 130.0;
        result = normal(a, b, y);
    }

    return result;
}
int hematocrit(float age,float y,int gender,char c_age){

    char f,m;
    int result = 0;
    float a,b,calc9;

    if(age >= 18 && gender == 0 && c_age == 'y'){
        a = 0.36;
        b = 0.48;
        result = normal(a, b, y);
    }
    else if(age >= 18 && gender == 1 && c_age == 'y' ){
        a = 0.4;
        b = 0.54;
        result = normal(a, b, y);
    }
    else if (age < 18 && c_age == 'y' ){

        if(age >= 12 && age <= 17 && gender== 1){
            a = 0.37;
            b = 0.49;
            result = normal(a, b, y);}
        else if(age >= 12 && age <= 17 && gender== 0 ){
            a = 0.36;
            b = 0.46;
            result = normal(a, b, y);}
        else if(age >= 6 && age <= 11){
            a = 0.35;
            b = 0.40;
            result = normal(a, b, y);}
        else if(age >= 1.0 && age <= 5){
            a = 0.34;
            b = 0.4;
            result = normal(a, b, y);
        }
    }
    else if(c_age == 'm' && age>=2 && age<= 6){
        a = 0.28;
        b = 0.42;
        result = normal(a, b, y);
    }
    return result;
}
int whitebloodcell (float age,float y,char c_age){

    char f,m,gender;
    int result = 0;
    float a,b,calc10;

    if(age>=18 && c_age == 'y' ){
        a = 4.0;
        b = 11.0;
        result = normal(a, b, y);
    }
    else if (age < 18 && c_age == 'y' ){

        if(age >= 12 && age <= 18){
            a = 4.5;
            b = 13.0;
            result = normal(a, b, y);
        }
    else if(age >= 6 && age <= 12){
            a = 4.5;
            b = 14.5;
            result = normal(a, b, y);
        }

    else if(age >= 1 && age <= 6){
            a = 5.0;
            b = 17.0;
            result = normal(a, b, y);

        }

    else if(age >= 0.5 && age <= 1){
            a = 6.0;
            b = 17.5;
            result = normal(a, b, y);

        }
    }
    else if(c_age == 'm' && age>=2 && age<= 6){
        a = 5.0;
        b = 15.0;
        result = normal(a, b, y);
    }
    return result;
}
int mcv_f(float age,float y,char c_age){

    char f,m,gender;
    int result = 0;
    float a,b,calc11;

    if(age >= 18  && c_age == 'y' ){
        a = 78;
        b = 100;
        result = normal(a, b, y);
    }
    else if (age < 18  && c_age == 'y'){

        if(age >= 11 && age <= 12){
            a = 77;
            b = 95;
            result = normal(a, b, y);
    }

        else if(age >=  10 && age < 11){
            a = 76;
            b = 88;
            result = normal(a, b, y);
    }

    else if(age >=  9 && age < 10){
            a = 73;
            b = 89;
            result = normal(a, b, y);
        }
    else if(age >=  8 && age < 9){
            a = 78;
            b = 97;
            result = normal(a, b, y);
    }
    else if(age >=  7 && age < 8 ){
            a = 73;
            b = 87;
            result = normal(a, b, y);
    }

    else if(age >=  6 && age < 7){
            a = 74;
            b = 91;
            result = normal(a, b, y);
    }

    else if(age >=  5 && age < 6){
            a = 73;
            b = 87;
            result = normal(a, b, y);
    }

    else if(age >=  4 && age < 5){
            a = 71;
            b = 85;
            result = normal(a, b, y);
    }

    else if(age >=  3 && age < 4){
            a = 74;
            b = 87;
            result = normal(a, b, y);
    }

    else if(age >=  2 && age < 3){
            a = 71;
            b = 83;
            result = normal(a, b, y);
    }

    else if(age >=  1 && age < 2){
            a = 72;
            b = 84;
            result = normal(a, b, y);
        }
    }
    else if(c_age == 'm' && age>=2 && age<= 6){
        a = 83.0;
        b = 97.0;
        result = normal(a, b, y);
    }
    return result;

}
int mch_f(float age,float y,char c_age){

    char f,m;
    int result = 0;
    float a,b,calc12;

    if(age >= 18 && c_age == 'y'){
        a = 27.0;
        b = 32.0;
        result = normal(a, b, y);
    }
    else if (age < 18 && c_age == 'y'){

        if(age >= 11 && age <= 17 ){
            a = 25.0 ;
            b = 33.0;
            result = normal(a, b, y);
        }

        if(age >= 10 && age < 11 ){
            a = 24.9 ;
            b = 30.2;
            result = normal(a, b, y);
        }

        if(age >= 9 && age < 10 ){
            a = 25.3 ;
            b = 29.8;
            result = normal(a, b, y);
        }

        if(age >= 8 && age <  9 ){
            a = 26.0 ;
            b = 29.4;
            result = normal(a, b, y);
        }
         if(age >= 7 && age <  8 ){
            a = 23.6 ;
            b = 31.0;
            result = normal(a, b, y);
         }

        if(age >= 6 && age <  7 ){
            a = 24.5 ;
            b = 29.6;
            result = normal(a, b, y);
        }

        if(age >= 5 && age <  6 ){
            a = 24.0 ;
            b = 30.0 ;
            result = normal(a, b, y);
        }

         if(age >= 4 && age <  5 ){
            a = 23.4 ;
            b = 29.1 ;
            result = normal(a, b, y);
         }

         if(age >= 3 && age <  4 ){
            a = 24.8 ;
            b = 28.9 ;
            result = normal(a, b, y);
         }

        if(age >= 2 && age <  3 ){
            a =  23.4;
            b =  29.1;
            result = normal(a, b, y);
        }

         if(age >= 1 && age <  2 ){
            a =  25.0;
            b =  29.0;
            result = normal(a, b, y);
        }
    }
    else if(c_age == 'm' && age>=2 && age<= 6){
        a = 27.0;
        b = 33.0;
        result = normal(a, b, y);
    }
    return result;

}
int mchc_f(float age,float y,char c_age){

    char f,m;
    int result = 0;
    float a,b,calc13;

    if(age >= 18 && c_age == 'y'){
        a = 310;
        b = 370;
        result = normal(a, b, y);
    }

    else if (age < 18 && c_age == 'y'){

        if(age >= 11 && age <= 17 ){
            a = 310 ;
            b = 370 ;
            result = normal(a, b, y);
        }
        if(age >= 10 && age <  11 ){
            a =  317;
            b =  355;
            result = normal(a, b, y);
        }
         if(age >= 9 && age <  10 ){
            a =  323;
            b =  361;
            result = normal(a, b, y);
         }
         if(age >= 8 && age <  9 ){
            a =  323;
            b =  361;
            result = normal(a, b, y);
         }
         if(age >= 7 && age <  8 ){
            a =  319;
            b =  369;
            result = normal(a, b, y);
         }
        if(age >= 6 && age <  7 ){
            a =  323;
            b =  360;
            result = normal(a, b, y);
        }
        if(age >= 5 && age <  6 ){
            a =  320;
            b =  348;
            result = normal(a, b, y);
        }
         if(age >= 4 && age <  5 ){
            a =  319;
            b =  356;
            result = normal(a, b, y);
         }
         if(age >= 3 && age <  4 ){
            a =  313;
            b =  352;
            result = normal(a, b, y);
         }
         if(age >= 2 && age <  3 ){
            a =  320;
            b =  359;
            result = normal(a, b, y);
         }
        if(age >= 1 && age <  2 ){
            a =  320;
            b =  360;
            result = normal(a, b, y);
        }
    }
    else if(c_age == 'm' && age>=2 && age<= 6){
        a = 31.0;
        b = 35.0;
        result = normal(a, b, y);
    }
    return result;
}
int neutrophils(float age,float y,char c_age)
{

    char f,m;
    int result = 0;
    float a,b,calc14;

   if(age >= 18 && c_age == 'y'){
        a = 2.0;
        b = 7.5;
        result = normal(a, b, y);
    }
    else if (age < 18 && c_age == 'y'){

        if(age >= 12 && age <= 17 ){
            a = 1.5 ;
            b = 8.0 ;
            result = normal(a, b, y);}

        if(age >= 6 && age < 12 ){
            a = 1.0 ;
            b = 8.0 ;
            result = normal(a, b, y);}

        if(age >= 0.5 && age < 6 ){
            a = 1.0 ;
            b = 8.0 ;
            result = normal(a, b, y);}
    }
    else if(c_age == 'm' && age>=2 && age<= 6){
        a = 1.0;
        b = 5.0;
        result = normal(a, b, y);
    }
      return result;
}

/*void diagnose(float age,int gender,char c_age)
{

    //FOR DECIDING ANEMIA
        //RBC OR HCT OR HB
        //IF(RBC OR HCT OR HB)
        //DETERMINE WHICH TYPE OF ANEMIA BASED ON MVC
            //IF(x < MVC) LOW IRON DEFIENCY ANIME
            //IF(x > MVC) FOLIATE DEFIENCY ANIME
            //IF(MVC INRANGE)
                //CHECK RC COUNT
                //IF(x > RC) CHECK BILIRUBIN
                    //IF(x is HIGH) HEMOLYTIC AMENIA
                    //IF(x is LOW) HEMORYTE AMENIA
                    //IF(x is IN RANGE) ANEMIA
                //IF(x < RC) CHECK WBC
                    //IF(x is HIGH) INFECTION
                    //IF(x is LOW) BONE MARROW DEPRESSION
                    //IF(x is IN RANGE) Pure red cell fantasia
                //IF(x is INRANGE RC) ANEMIA
    char message[100] = "NOPE";
    if(redbloodcell(age, RBCvalue, gender, c_age) == -1 || hematocrit(age, HCTvalue, gender, c_age) == -1 || haemoglobin(age, HBvalue, gender, c_age) == -1)
    {
        char s1[] = "ANEMIA";
        strcpy(message, s1);
        if(mcv_f(age, MCVvalue, c_age) == -1)
        {
            char s1[] = "LOW IRON DEFIENCY ANEMIA";
            strcpy(message, s1);
        }
        else if (mcv_f(age, MCVvalue, c_age) == 1)
        {
            char s1[] = "FOLIATE DEFIENCY ANEMIA";
            strcpy(message, s1);
        }
        else
        {
            if(reticulocytes(age, RCvalue, c_age) == 1)
            {
                if(bilirubin(age, BILIvalue, c_age) == 1)
                {
                    char s1[] = "HEMOLYTIC ANEMIA";
                    strcpy(message, s1);
                }
                else if(bilirubin(age, BILIvalue, c_age) == -1)
                {
                    char s1[] = "HEMORRAGE ANEMIA";
                    strcpy(message, s1);

                }
                else
                {
                    char s1[] = "ANEMIA";
                    strcpy(message, s1);
                }
            }
            else if (reticulocytes(age, RCvalue,  c_age) == -1)
            {
                if(whitebloodcell(age, WBCvalue, c_age) == 1)
                {
                    char s1[] = "INFECTION";
                    strcpy(message, s1);

                }
                else if(whitebloodcell(age, WBCvalue, c_age) == -1)
                {
                    char s1[] = "BONE MARROW DEPRESSION";
                    strcpy(message, s1);
                }
                else
                {
                    char s1[] = "PURE RED CELL APLASIA";
                    strcpy(message, s1);
                }
            }
            else
            {
                char s1[] = "ANEMIA";
                strcpy(message, s1);
            }
        }
    }
    strcpy(diagnoseResult, message);

}*/
