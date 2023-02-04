#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <conio.h>
#include<time.h>
#include <dos.h>
#include <dir.h>
#include <windows.h>
#include"evaluation.h"
#define ENTER 13
#define TAB 9
#define BCKSPC 8

struct user{
	char fullName[50];
	char email[50];
	char password[50];
	char username[50];
	char phone[50];
	char ic[12];
	char gender[10];
};

void takeinput(char ch[50])
{
	fgets(ch, 50, stdin);
	//to remove slash from the end of the string
	ch[strlen(ch)-1] = 0;
}

void takepassword(char pwd[50])
{
    int i = 0;
    char ch;
    while(1)
    {
        ch = getch();
        if(ch == ENTER || ch == TAB)
        {
            pwd[i] = '\0';
            break;
        }
        else if(ch == BCKSPC)
        {
            if(i  > 0)
            {
                i--;
                printf("\b \b");
            }
        }
        else
        {
            pwd[i++] = ch;
            printf("* \b");
        }
    }
}

loop()
{
	int usrFound = 0;
	struct user user;
	char password2[50];
	char username[50], pword[50];
    //struct user usr;
    int k, l = 0, m, n = 0, p, q = 0, a, b;
    int month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int tdate=0, tmonth=0, tyear=0;
    int status1 = 1;

	SYSTEMTIME t2;
    GetLocalTime(&t2);
    int currentdate = t2.wDay;
    int currentmonth = t2.wMonth;
    int currentyear = t2.wYear;

	FILE * fp;

	system("cls");
	label:
    printf("\n\t\t\t------------Clinic Decision Support System for Anaemia----------");
    printf("\n\t\t\t--------------------------Log In Page---------------------------");
    printf("\n\t\t\tUsername\t:");
    takeinput(username);
    printf("\t\t\tPassword\t:");
    takepassword(pword);

    fp = fopen("users.txt", "r");

    while(fread(&user, sizeof(struct user), 1, fp))
    {
        if(!strcmp(user.username, username))
        {
            if(!strcmp(user.password, pword))
            {
                system("cls");
                printf("\n\t\t\t\t\tWelcome %s", user.fullName);
                printf("\n\nFull Name \t:%s", user.fullName);
                printf("\nEmail\t\t:%s", user.email);
                printf("\nContact no\t:%s", user.phone);
                printf("\nIC\t\t:%s", user.ic);

                b = user.ic[11] - '0';
                switch(b)
                {
                    case 0:
                    case 2:
                    case 4:
                    case 6:
                    case 8:
                        strcpy(user.gender, "Female");
                    break;
                    default:
                        strcpy(user.gender, "Male");
                    break;
                }
                printf("\nGender\t\t:%s", user.gender);

                for(k = 4; k < 6; k++)
                {
                    l = 10 * l + (user.ic[k] - '0');
                }

                for(m = 2; m < 4; m++)
                {
                    n = 10 * n + (user.ic[m] - '0');
                }

                a = user.ic[0] - '0';

                switch(a)
                {
                    case 0:
                    case 1:
                    case 2:
                        for(p = 0; p < 2; p++)
                        {
                            q = 10 * q + (user.ic[p] - '0');
                        }
                        q = q + 2000;
                        break;
                    default:
                        for(p = 0; p < 2; p++)
                        {
                            q = 10 * q + (user.ic[p] - '0');
                        }
                        q = q + 1900;
                        break;
                }

                if(l > currentdate)
                {
                    currentdate = currentdate + month[l - 1];
                    currentmonth = currentmonth - 1;
                }

                if(n > currentmonth)
                {
                    currentyear = currentyear - 1;
                    currentmonth = currentmonth + 12;
                }

                tdate = currentdate - l;
                tmonth = currentmonth - n;
                tyear = currentyear - q;
                printf("\nAge\t\t:%d years %d months %d days", tyear, tmonth, tdate);
            }

            else
            {
                printf("\n\nInvalid Password!");
                printf("\n\nPress ENTER key to log in again.");
                getchar();
                system("cls");
                goto label;
                Beep(800, 300);
            }
            usrFound = 1;
        }
    }



    if(!usrFound)
    {
        fclose(fp);
        while(status1 != 0)
        {
            printf("\n\nUser is not registered.");
            printf("\n\nPress ENTER to continue sign up page.");
            getchar();
            system("cls");
            printf("\n\t\t\t\t-------------------New Users Sign Up-------------------");
            printf("\n\t\t\t\tFull name\t:");
            takeinput(user.fullName);
            printf("\t\t\t\tEmail\t\t:");
            takeinput(user.email);
            printf("\t\t\t\tContact no\t:");
            takeinput(user.phone);
            printf("\t\t\t\tIC\t\t:");
            takeinput(user.ic);
            printf("\t\t\t\tUsername\t:");
            takeinput(user.username);
            printf("\t\t\t\tPassword\t:");
            takepassword(user.password);
            printf("\n\t\t\t\tConfirm your password\t:");
            takepassword(password2);

            fp = fopen("users.txt", "r");

            if(!strcmp(user.password, password2))
            {
                fp = fopen("users.txt", "a+");
                //store username in the file
                fwrite(&user, sizeof(struct user), 1, fp);
                if(fwrite != 0)
                {
                    status1 = 0;
                    printf("\n\nUser registration success, Your user name is %s.", user.username);
                    printf("\n\nPress ENTER to continue login.");
                    getchar();
                }

                else
                {
                    status1 = 1;
                    printf("\n\nSomething went wrong!");
                    printf("\n\nPress ENTER to sign up again.");
                    getchar();
                }
            }
            else
            {
                status1 = 1;
                printf("\nPassword do not match.");
                printf("\n\nPress ENTER to sign up again.");
            }fclose(fp);
        }loop();

    }
}

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
    float wbc;
    float mcv;
    float mch;
    float mchc;
    float ntr;
};
struct parameter user1;

int main()
{
	int usrFound = 0;
	struct user user;
	char password2[50];
	char username[50], pword[50];
    struct user usr;
    int k, l = 0, m, n = 0, p, q = 0, a, b;
    int month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int tdate, tmonth, tyear;
    int status1 = 1;
    int temp_age;
    char c_age;
    //parameter initialization
    int s_lc=0,s_mono_c=0,s_bc=0,s_ec=0,s_bili=0,s_rc=0,s_hb=0,s_rbc=0,s_hct=0;
    int s_wbc=0,s_mcv=0,s_mch=0,s_mchc=0,s_ntr=0;
    int result;
    int calc,calc2,calc3,calc4,calc5,calc6;
    int calc7,calc8,calc9;
    int calc10,calc11,calc12,calc13,calc14;
    char grbc, ghb, ghct, g_mono_c, g_ntr, g_ec, g_bc, g_bili, g_lc, g_wbc, g_mcv, g_mch, g_mchc, g_rc;
    char ic[12];

	SYSTEMTIME t2;
    GetLocalTime(&t2);
    int currentdate = t2.wDay;
    int currentmonth = t2.wMonth;
    int currentyear = t2.wYear;

	FILE * fp;

	label:
    printf("\n\t\t\t\t------------Clinic Decision Support System for Anaemia----------");
    printf("\n\t\t\t\t--------------------------Log In Page---------------------------");
    printf("\n\t\t\t\tUsername\t:");
    takeinput(username);
    printf("\t\t\t\tPassword\t:");
    takepassword(pword);

    fp = fopen("users.txt", "r");

    while(fread(&user, sizeof(struct user), 1, fp))
    {
        if(!strcmp(user.username, username))
        {
            if(!strcmp(user.password, pword))
            {
                system("cls");
                printf("\n\t\t\t\t\tWelcome %s", user.fullName);
                printf("\n\nFull Name \t:%s", user.fullName);
                printf("\nEmail\t\t:%s", user.email);
                printf("\nContact no\t:%s", user.phone);
                printf("\nIC\t\t:%s", user.ic);

                strncpy(ic, user.ic, 12);
                ic[12 - 1] = '\0';

                b = user.ic[11] - '0';
                if(b % 2 == 0)
                {
                    strcpy(user.gender, "Female");
                }
                else
                {
                    strcpy(user.gender, "Male");
                }

                printf("\nGender\t\t:%s", user.gender);

                for(k = 4; k < 6; k++)
                {
                    l = 10 * l + (user.ic[k] - '0');
                }

                for(m = 2; m < 4; m++)
                {
                    n = 10 * n + (user.ic[m] - '0');
                }

                a = user.ic[0] - '0';
                switch(a)
                {
                    case 0:
                    case 1:
                    case 2:
                        for(p = 0; p < 2; p++)
                        {
                            q = 10 * q + (user.ic[p] - '0');
                        }
                        q = q + 2000;
                        break;
                    default:
                        for(p = 0; p < 2; p++)
                        {
                            q = 10 * q + (user.ic[p] - '0');
                        }
                        q = q + 1900;
                        break;
                }

                if(l > currentdate)
                {
                    currentdate = currentdate + month[l - 1];
                    currentmonth = currentmonth - 1;
                }

                if(n > currentmonth)
                {
                    currentyear = currentyear - 1;
                    currentmonth = currentmonth + 12;
                }

                tdate = currentdate - l;
                tmonth = currentmonth - n;
                tyear = currentyear - q;
                printf("\nAge\t\t:%d years %d months %d days", tyear, tmonth, tdate);
            }
            else
            {
                printf("\n\nInvalid Password!");
                printf("\n\nPress ENTER key to log in again.");
                getchar();
                system("cls");
                goto label;
                Beep(800, 300);
            }
            usrFound = 1;
        }
    }

    if(!usrFound)
    {
        fclose(fp);
        while(status1 != 0)
        {
            printf("\n\nUser is not registered.");
            printf("\n\nPress ENTER to continue sign up page.");
            getchar();
            system("cls");
            printf("\n\t\t\t\t-------------------New Users Sign Up-------------------");
            printf("\n\t\t\t\tFull name\t:");
            takeinput(user.fullName);
            printf("\t\t\t\tEmail\t\t:");
            takeinput(user.email);
            printf("\t\t\t\tContact no\t:");
            takeinput(user.phone);
            printf("\t\t\t\tIC\t\t:");
            takeinput(user.ic);
            printf("\t\t\t\tUsername\t:");
            takeinput(user.username);
            printf("\t\t\t\tPassword\t:");
            takepassword(user.password);
            printf("\n\t\t\t\tConfirm your password\t:");
            takepassword(password2);

            fp = fopen("users.txt", "r");

            if(!strcmp(user.password, password2))
            {
                fp = fopen("users.txt", "a+");
                //store username in the file
                fwrite(&user, sizeof(struct user), 1, fp);
                if(fwrite != 0)
                {
                    status1 = 0;
                    printf("\n\nUser registration success, Your user name is %s.", user.username);
                    printf("\n\nPress ENTER to continue login.");
                    getchar();
                }

                else
                {
                    status1 = 1;
                    printf("\n\nSomething went wrong!");
                    printf("\n\nPress ENTER to sign up again.");
                    getchar();
                }
            }
            else
            {
                status1 = 1;
                printf("\nPassword do not match.");
                printf("\n\nPress ENTER to sign up again.");
            }fclose(fp);
        }
        loop();

    }

    printf("\n\n");
    system("pause");
    system("cls");

    printf("\n\t\t\t------------Clinic Decision Support System for Anaemia----------\n");
    while(user1.rbc < 0 || s_rbc != 1)
    {
        printf("\n Red Blood Cell count (x10^12/L)               : ");
        s_rbc = scanf("%f",&user1.rbc);
        scanf("%c", &grbc);
    }

    while(user1.hb < 0 || s_hb != 1)
    {
        printf(" Haemoglobin count (gL)                        : ");
        s_hb = scanf("%f",&user1.hb);
        scanf("%c", &ghb);
    }

    while(user1.hct < 0 || s_hct != 1)
    {
        printf(" Haematocrit count                             : ");
        s_hct = scanf("%f",&user1.hct);
        scanf("%c", &ghct);
    }

    while(user1.lc < 0 || s_lc != 1)
    {
        printf(" lymphocyte                                    : ");
        s_lc = scanf("%f",&user1.lc);
        scanf("%c", &g_lc);
    }

    while(user1.mono_c < 0 || s_mono_c != 1)
    {
        printf(" monocytes                                     : ");
        s_mono_c = scanf("%f",&user1.mono_c);
        scanf("%c", &g_mono_c);
    }
    while(user1.ntr < 0 || s_ntr != 1)
    {
        printf(" neutrophils                                   : ");
        s_ntr = scanf("%f",&user1.ntr);
        scanf("%c", &g_ntr);
    }

    while(user1.ec < 0 || s_ec != 1)
    {
        printf(" eosinophils                                   : ");
        s_ec = scanf("%f",&user1.ec);
        scanf("%c", &g_ec);
    }

    while(user1.bc < 0 || s_bc != 1)
    {
        printf(" basophils                                     : ");
        s_bc = scanf("%f",&user1.bc);
        scanf("%c", &g_bc);
    }

    while(user1.bili < 0 || s_bili != 1)
    {
        printf(" Total bilirubin                               : ");
        s_bili = scanf("%f",&user1.bili);
        scanf("%c", &g_bili);
    }

    while(user1.rc < 0 || s_rc != 1)
    {
        printf(" reticulocyte count                            : ");
        s_rc = scanf("%f",&user1.rc);
        scanf("%c", &g_rc);
    }

    while(user1.wbc < 0 || s_wbc != 1)
    {
        printf(" white blood cell (x10^9/L)                    : ");
        s_wbc = scanf("%f",&user1.wbc);
        scanf("%c", &g_wbc);
    }

    while(user1.mcv < 0 || s_mcv != 1)
    {
        printf(" mean corpuscular volume (fL)                  : ");
        s_mcv = scanf("%f",&user1.mcv);
        scanf("%c", &g_mcv);
    }

    while(user1.mch < 0 || s_mch != 1)
    {
        printf(" mean corpuscular hemoglobin (pg)              : ");
        s_mch =  scanf("%f",&user1.mch);
        scanf("%c", &g_mch);
    }

    while(user1.mchc < 0 || s_mchc != 1)
    {
        printf(" mean corpuscular hemoglobin concentration(g/L): ");
        s_mchc = scanf("%f",&user1.mchc);
        scanf("%c", &g_mchc);
    }

    if(tyear <=  0 ){
        temp_age = tmonth;
        c_age = 'm';
    }
    else if(tyear >= 0 ){
        temp_age = tyear;
        c_age = 'y';
    }

    printf("\n\n");
    system("pause");
    system("cls");

    int gender = 0;

    if (user.gender == "Female")
    {
        gender = 0;
    }
    else
    {
        gender = 1;
    }

    calc  = lymphocytes(temp_age,user1.lc,c_age);
    calc2 = monocytes(temp_age,user1.mono_c,c_age);
    calc3 = eosinophils(temp_age,user1.ec,gender,c_age);
    calc4 = basophils(temp_age,user1.bc,gender,c_age);
    calc5 = bilirubin(temp_age,user1.bili,c_age);
    calc6 = reticulocytes(temp_age,user1.rc,c_age);
    calc7 = redbloodcell(temp_age,user1.rbc,gender,c_age);
    calc8 = haemoglobin(temp_age,user1.hb,gender,c_age);
    calc9 = hematocrit(temp_age,user1.hct,gender,c_age);
    calc10 = whitebloodcell(temp_age,user1.wbc,c_age);
    calc11 = mcv_f(temp_age,user1.mcv,c_age);
    calc12 = mch_f(temp_age,user1.mch,c_age);
    calc13 = mchc_f(temp_age,user1.mchc,c_age);
    calc14 = neutrophils(temp_age,user1.ntr,c_age);

    //summary report
    printf("\n\t\t\t------------Clinic Decision Support System for Anaemia----------\n");
    printf(" ______________________________________________\n");
    printf("|          Patient Summary Report              |");
    printf("\n|______________________________________________|\n");
    printf("\n Name                                           : %s", user.fullName);
    printf("\n Gender                                         : %s", user.gender);
    printf("\n IC                                             : %s", ic);
    printf("\n Age                                            : %d years %d months %d days", tyear, tmonth, tdate);
    printf("\n Contact no                                     : %s", user.phone);
    printf("\n Email                                          : %s\n", user.email);

    printf("\n Red Blood Cell (x10^12/L)                      : %.2f",user1.rbc);
    printf("\n Haemoglobin (gL)                               : %.2f",user1.hb);
    printf("\n Hematocrit                                     : %.2f",user1.hct);
    printf("\n lymphocyte                                     : %.2f",user1.lc);
    printf("\n monocytes                                      : %.2f",user1.mono_c);
    printf("\n Neutrophils                                    : %.2f",user1.ntr);
    printf("\n Eosinophils                                    : %.2f",user1.ec);
    printf("\n Basophils                                      : %.2f",user1.bc);
    printf("\n Total bilirubin                                : %.2f",user1.bili);
    printf("\n Reticulocyte Count                             : %.2f",user1.rc);
    printf("\n White Blood Cell Count (x10^9/L)               : %.2f",user1.wbc);
    printf("\n Mean Corpuscular Volume (fL)                   : %.2f",user1.mcv);
    printf("\n Mean Corpuscular Hemoglobin (pg)               : %.2f",user1.mch);
    printf("\n Mean Corpuscular Hemoglobin Concentration(g/L) : %.2f",user1.mchc);

    FILE *fpt;
    fpt = fopen("Report.csv", "a+");
    fprintf(fpt,"\n _____________________\n");
    fprintf(fpt,"|Patient Summary Report|");
    fprintf(fpt,"\n|_____________________|\n");
    fprintf(fpt,"\n Name                                      , %s", user.fullName);
    fprintf(fpt,"\n Gender                                    , %s", user.gender);
    fprintf(fpt,"\n IC                                        , %s", ic);
    fprintf(fpt,"\n Age                                       , %d years %d months %d days", tyear, tmonth, tdate);
    fprintf(fpt,"\n Contact no                                , %s", user.phone);
    fprintf(fpt,"\n Email                                     , %s\n", user.email);
    fprintf(fpt,"\n Red Blood Cell                            , %.2f",user1.rbc);
    fprintf(fpt,"\n Haemoglobin                               , %.2f",user1.hb);
    fprintf(fpt,"\n Hematocrit                                , %.2f",user1.hct);
    fprintf(fpt,"\n lymphocyte                                , %.2f",user1.lc);
    fprintf(fpt,"\n monocytes                                 , %.2f",user1.mono_c);
    fprintf(fpt,"\n Neutrophils                               , %.2f",user1.ntr);
    fprintf(fpt,"\n Eosinophils                               , %.2f",user1.ec);
    fprintf(fpt,"\n Basophils                                 , %.2f",user1.bc);
    fprintf(fpt,"\n Total bilirubin                           , %.2f",user1.bili);
    fprintf(fpt,"\n Reticulocyte Count                        , %.2f",user1.rc);
    fprintf(fpt,"\n White Blood Cell Count                    , %.2f",user1.wbc);
    fprintf(fpt,"\n Mean Corpuscular Volume                   , %.2f",user1.mcv);
    fprintf(fpt,"\n Mean Corpuscular Hemoglobin               , %.2f",user1.mch);
    fprintf(fpt,"\n Mean Corpuscular Hemoglobin Concentration , %.2f",user1.mchc);

    printf("\n\n-----------------------------------------------------------------------------------------------------------------------------");
    printf("\n Pre Evaluation result: ");
    fprintf(fpt,"\n\n Pre Evaluation result:");
    if (calc7 == -1 || calc8 == -1 || calc9 == -1)
    {
        printf("\n\nYou are Anaemia Risk Patient");
        fprintf(fpt,"\n\nYou are Anaemia Risk Patient");
        printf("\n\nType of Anaemia: ");
        fprintf(fpt, "\n\nType of Anaemia: ,");
        if(calc11 == -1)
        {
            printf("Iron Deficiency / Thalassemia/ Lead poisoning/ Chronic Disease.");
            fprintf(fpt, "Iron Deficiency / Thalassemia/ Lead poisoning/ Chronic Disease.");
        }
        else if(calc11 == -1)
        {
            printf("Folate deficiency/ Vitamin B12 deficiency/ aplastic anaemia.");
            fprintf(fpt, "Folate deficiency/ Vitamin B12 deficiency/ aplastic anaemia.");
        }
        else
        {
            if(calc6 == -1)
            {
                if(calc10 == -1)
                {
                    printf("Bone marrow.");
                    fprintf(fpt, ",Bone marrow.");
                }
                else if(calc10 == 1)
                {
                    printf("Infection.");
                    fprintf(fpt, ",Infection.");
                }
                else
                {
                    printf("Pure red cell aplasia.");
                    fprintf(fpt, ",Pure red cell aplasia.");
                }
            }
            else if(calc6 == 1)
            {
                if(calc5 == 0)
                {
                    printf("Hemorrhage.");
                    fprintf(fpt, ",Hemorrhage.");
                }
                else if(calc5 == 1)
                {
                    printf("Hemolytic anaemia.");
                    fprintf(fpt, ",Hemolytic anaemia.");
                }
            }
        }
        printf("\n\nNotes: ");
        fprintf(fpt, "\n\nNotes: ");
        printf("\n\nPlease consult to nearest health care centre for future reference.");
        fprintf(fpt, "\n\nPlease consult to nearest health care centre for future reference.");
    }
    else
    {
        printf("You are healthy: ");
        fprintf(fpt, "You are healthy: ");
        printf("\n\nNotes: ");
        fprintf(fpt, "\n\nNotes: ");
        printf("\n-");
        fprintf(fpt, "\n-");
    }

    printf("\nThank you for visiting us :)");
    fprintf(fpt, "\nThank you for visiting us :)");


    fprintf(fpt,"\n");
    fclose(fpt);

    printf("\n");
    return 0;
}

