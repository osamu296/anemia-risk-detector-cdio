#include<stdio.h>
#include"ec_patient.h"

int k = 0;
int j = 0;

float normal(float x,float y,float i){

    float result;

    if ( i >= x && i <= y  ){

        printf(" normal\n");
        //j++;
    }
    else if(i<=x)
    {
        printf(" anaemia risk patient\n");
        k++;
    }

    result = k;

    return result;
}

float lymphocytes(float age,float y ){

    char f,m,gender;
    float result;
    float a,b,calc;

    if(age>=18 ){
        a = 1.0;
        b = 4.5;
        result = normal(a, b, y);
    }
    else if (age < 18 ){

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
        else if(age >= 0.5 && age <= 1 ){
            a = 1.5;
            b = 7.0;
            result = normal(a, b, y);
        }}
    return calc;
}

float monocytes(float age,float y ){

    char f,m,gender;
    float result;
    float a,b,calc2;

    if(age >= 18 ){
        a = 0.2;
        b = 0.8;
        result = normal(a, b, y);
    }
    else if (age < 18 ){

        if(age >= 0.5 && age <= 17){
            a = 0.2;
            b = 1.0;
            result = normal(a, b, y);
        }}
    return calc2;
}

float eosinophils(float age,float y,char gender){

    char f,m;
    float result;
    float a,b,calc3;

    if(age >= 18 && gender == 'f'){
        a = 0.04;
        b = 0.4;
        result = normal(a, b, y);
    }
    else if(age >= 18 && gender =='m'){
        a = 0.04;
        b = 0.5;
        result = normal(a, b, y);
    }
    else if (age < 18 ){

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
        }}
    return calc3;
}

float basophils(float age,float y,char gender){

    char f,m;
    float result;
    float a,b,calc4;

    if(age >= 18 && gender =='f'){
        a = 0.00;
        b = 0.1;
        result = normal(a, b, y);
    }
    else if(age >= 18 && gender =='m'){
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
    return calc4;
}
float bilirubin(float age,float y){

    char f,m;
    float result;
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
    return calc5;
}
float reticulocytes(float age,float y){

    char f,m;
    float result;
    float a,b,calc6;

    if(age >= 18){
        a = 0.5;
        b = 2.5;
        result = normal(a, b, y);
    }
    else if (age < 18 ){

        if(age >= 1 && age <= 17 ){
            a = 0.5 ;
            b = 2.0;
            result = normal(a, b, y);}
        }
    return calc6;
}

float redbloodcell(float age,float y,char gender){

    char f,m;
    float result;
    float a,b,calc7;

    if(age >= 18 && gender == 'f'){
        a = 3.8;
        b = 5.8;
        result = normal(a, b, y);
    }
    else if(age >= 18 && gender =='m'){
        a = 4.5;
        b = 6.5;
        result = normal(a, b, y);
    }
    else if (age < 18 ){

        if(age >= 12 && age <= 17 && gender== 'm'){
            a = 4.5 ;
            b = 5.3;
            result = normal(a, b, y);}
        else if(age >= 12 && age <= 17 && gender== 'f'){
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
        }}
    return calc7;
}

float haemoglobin(float age,float y,char gender){

    char f,m;
    float result;
    float a,b,calc8;

    if(age >= 18 && gender == 'f'){
        a = 115;
        b = 160;
        result = normal(a, b, y);
    }
    else if(age >= 18 && gender =='m'){
        a = 135;
        b = 180;
        result = normal(a, b, y);
    }
    else if (age < 18 ){

        if(age >= 12 && age <= 17 && gender== 'm'){
            a = 130;
            b = 170;
            result = normal(a, b, y);}
        else if(age >= 12 && age <= 17 && gender== 'f'){
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
        }}
    return calc8;
}
float hematocrit(float age,float y,char gender){

    char f,m;
    float result;
    float a,b,calc9;

    if(age >= 18 && gender == 'f'){
        a = 0.36;
        b = 0.48;
        result = normal(a, b, y);
    }
    else if(age >= 18 && gender =='m'){
        a = 0.4;
        b = 0.54;
        result = normal(a, b, y);
    }
    else if (age < 18 ){

        if(age >= 12 && age <= 17 && gender== 'm'){
            a = 0.37;
            b = 0.49;
            result = normal(a, b, y);}
        else if(age >= 12 && age <= 17 && gender== 'f'){
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
        }}
    return calc9;
}
