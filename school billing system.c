#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
struct dat//for date(month and day
{
    int d,m;//d=day,m=month
};
int clscanf();//check class (1-12)
struct student
{
    struct dat dt;
    float f,fine,tot,adv,due;//f=fee
    char n[50];
    int r,c;//roll and class
} stud,s;
int chkdat(int,int);// for checking date
void addrec(int);//for adding records
void modrec(int);//for modifying records
void searchrec(int);//for searching records
void delrec(int);//for deleting records
FILE *fs,*ft;//file declaration
int mm,dd;//mm=month, dd=day
void ext();//for exiting
void main(void)
{
    int i,j,k;
    for(i=0; i<80; i++)
    {
        printf("\xdb");
    }
    printf("\n");
    for(i=0; i<80; i++)
    {
        printf("\xdb");
    }
    printf("\t|                                                      |\n");
    printf("\t|**WELCOME TO FEE MANAGEMENT SYSTEM |**\n");
    printf("\t ______________________________________________________\n");
    printf("\t| DEVELOPED BY : REG -11605503 SEC-K1624  ROLL NO-A17  |\n");
    printf("\t|****************************************************** |\n");
    printf(" \t_______________________________________________________\n");
    printf("\n\tPLEASE ENTER ANY KEY TO CONTINUE");
    for(i=0; i<5; i++)
    {
        printf(".");
        Sleep(500);//after printing one . another comes after 0.5 seconds
    }
    getch();
    system("cls");//clears the screen
    printf("\n");
    for(i=0; i<80; i++)
    {
        printf("\xdb");
    }
    printf("\n\n\t** WELCOME TO FEE MANAGEMENT SYSTEM **\n\n\n");
    for(i=0; i<80; i++)
    {
        printf("\xdb");
    }
    printf("\nPLEASE ENTER ANY KEY TO START\n");
    for(i=0; i<5; i++)
    {
        printf(".");
        Sleep(500);
    }
    fflush(stdin);
    getch();
    system("cls");
    printf("\n\t\tPLEASE ENTER CURRENT DATE\nmm dd\n ");
    scanf("%d%d",&mm,&dd);
    mm=chkdat(mm,dd);
    start();
}
void start()
{
    int i,j;//j is for selection of account type
    system("cls");
    printf("\n\t\tPLEASE ENTER ACCOUNT TYPE");
    printf("\n\t\t1:: Student");
    printf("\n\t\t2:: Exit");
    printf("\n\t\tAccount type choice  ");
    fflush(stdin);
    scanf("%d",&j);
    switch (j)
    {
    case 2:
        ext();
    case 1:
    {
        system("cls");
        printf("\n\t\tPLEASE ENTER THE CHOICE");
        printf("\n\t\t1:: Add record");
        printf("\n\t\t2:: Search record");
        printf("\n\t\t3:: Modify record");
        printf("\n\t\t4:: Delete record");
        printf("\n\t\t5:: Calculate fee");
        printf("\n\t\t6:: Exit");
        printf("\n\n Enter choice  ");
        fflush(stdin);
        scanf("%d",&i);
        switch (i)
        {
        case 1:
            addrec(j);//function call
            start();//function call
        case 2:
            searchrec(j);
            start();
        case 3:
            modrec(j);
            start();
        case 4:
            delrec(j);
            start();
        case 5:
            fee(mm);
            start();
        case 6:
            ext();
        default :
        {
            printf("\n\n\tInvalid entry!!");
            printf("\n\nTo Account Type\n\n\t");
            system("pause");
            start();
        }
        }
    }
    default :
    {
        printf("\n\n\tInvalid entry!!");
        printf("\n\nTo Account Type\n\n\t");
        system("pause");
        start();
    }
    }
}
void addrec(int j)
{
    int dif,cdat,ddat,month=0;//cdat=month till which fee is cleared
    float ff;//used in calculatin of fee of different class
    char c='y';
    system("cls");
    printf("\n\t*********************          ADD RECORD       *******************");
    if (j==1)
    {
        while(c=='y'||c=='Y')
        {
            int a=1;
            printf("\n\nEnter the name of student: ");
            fflush(stdin);
            scanf("%[^\n]",stud.n);
            printf("\nEnter the class: ");
            fflush(stdin);
            stud.c=clscanf();
            printf("\nEnter the Roll No.:");
            fflush(stdin);
            scanf("%2d",&stud.r);
            printf("\nEnter month and day till which fee is paid:");
            fflush(stdin);
            scanf("%2d%2d",&cdat,&ddat);
            cdat=chkdat(cdat,ddat);
            stud.dt.m=cdat;
            ff=stud.c/10.0;
            stud.f=1000*(1+ff);//fee of different classes
            dif=mm-stud.dt.m;//months of fee left to be paid
            stud.fine=(dif*stud.f)*1/100;
            stud.due=(dif)*stud.f;//fees left to be paid
            if(dif==1)
            {
                stud.tot=stud.f;
                stud.fine=0;
            }
            else
            {
                stud.tot=stud.fine+stud.due;
            }//for calculation of total fee
            fs=fopen("student","ab+");//opening a binary file in apend mode
            fwrite(&stud,sizeof(stud),1,fs);
            fclose(fs);
            printf("\n\nDo you want to continue with the process(press y or Y");
            fflush(stdin);
            c=getch();
        }
        getch();
    }
}
void searchrec(int j)
{
    char name[50],namet[50];
    int a=1,choice;
    char c='y';
    if (j==1)
    {
        while(c=='y'||c=='Y')
        {
            int a=1;
            system("cls");
            printf("\n\t*********************   SEARCH RECORD     *******************");
            printf("\n\n\t\tPLEASE CHOOSE SEARCH TYPE::");
            printf("\n\n\t\t1::Search by name::");
            printf("\n\n\t\t2::Search by class::");
            printf("\n\n\t\t3::Search by rollno::");
            printf("\n\n\t\t4::Exit");
            printf("\n\n\t\t::Enter your choice:: ");
            fflush(stdin);
            scanf("%d",&choice);
            if (choice==1)
            {
                a=1;
                printf("\n\nEnter name of student to search: ");
                fflush(stdin);
                scanf("%[^\n]",name);
                fs=fopen("student","rb");
                while(fread(&stud,sizeof(stud),1,fs)==1)
                {
                    if (strcmpi(name,stud.n)==0)
                    {
                        a=0;
                        printf("\nname = %s",stud.n);
                        printf("\nclass = %d",stud.c);
                        printf("\nroll no = %d",stud.r);
                        printf("\nmonthy fee =%.2f",stud.f);
                        printf("\nlast fee paid in month =%2d",stud.dt.m);
                        printf("\n due=%.2f",stud.due);
                        printf("\n fine=%.2f",stud.fine);
                        printf("\n total=%.2f\n\n",stud.tot);
                    }
                }
                if (a==1)
                    printf("\n\nRECORD NOT FOUND");
                printf("\n\n");
                system("pause");
                fflush(stdin);
                fclose(fs);
            }
            else if (choice==2)
            {
                int cl;
                a=1;
                printf("\n\nEnter class of student to search: ");
                fflush(stdin);
                cl=clscanf();
                fs=fopen("student","rb");
                while(fread(&stud,sizeof(stud),1,fs)==1)
                {
                    if (stud.c==cl)
                    {
                        a=0;
                        printf("\nname = %s",stud.n);
                        printf("\nclass = %d",stud.c);
                        printf("\nroll no = %d",stud.r);
                        printf("\nmonthy fee =%.2f",stud.f);
                        printf("\nlast fee paid in month =%2d",stud.dt.m);
                        printf("\n due=%.2f",stud.due);
                        printf("\n fine=%.2f",stud.fine);
                        printf("\n total=%.2f",stud.tot);
                    }
                }
                if (a==1)
                    printf("\n\nRECORD NOT FOUND");
                printf("\n\n");
                system("pause");
                fflush(stdin);
                fclose(fs);
            }
            else if (choice==3)
            {
                int rll;
                a=1;
                printf("\n\nEnter roll of student to search: ");
                fflush(stdin);
                rll=clscanf();
                fs=fopen("student","rb");
                while(fread(&stud,sizeof(stud),1,fs)==1)
                {
                    if (strcmpi(name,stud.n)==0)
                    {
                        a=0;
                        printf("\nname = %s",stud.n);
                        printf("\nclass = %d",stud.c);
                        printf("\nroll no = %d",stud.r);
                        printf("\nmonthy fee =%.2f",stud.f);
                        printf("\nlast fee paid in month =%2d",stud.dt.m);
                        printf("\n due=%.2f",stud.due);
                        printf("\n fine=%.2f",stud.fine);
                        printf("\n total=%.2f",stud.tot);
                    }
                }
                if (a==1)
                    printf("\n\nRECORD NOT FOUND");
                printf("\n\n");
                system("pause");
                fflush(stdin);
                fclose(fs);
            }
            else if(choice==4)
            {
                ext();
            }
            else
            {
                printf("\n\n\n\t\tINVALID ENTRY!!!!\n\n\t\t");
                system("pause");
                searchrec(1);
            }
            printf("\n\nDo you want to continue with the process(press y or Y");
            fflush(stdin);
            c=getch();
        }
        getch();
    }
}
void modrec(int j)
{
    char name[50];
    int a=1,choice,cl,rolno;
    char c='y';
    if (j==1)
    {
        while(c=='y'||c=='Y')
        {
            system("cls");
            printf("\n\t*********************   MODIFY RECORD     *******************");
            printf("\n\n\t\tPLEASE CHOOSE MODIFY TYPE::");
            printf("\n\n\t\t1::Modify by name::");
            printf("\n\n\t\t2::Modify by name &class::");
            printf("\n\n\t\t3::Modify by name,class & rollno::");
            printf("\n\n\t\t4::Exit");
            printf("\n\n\t\t::Enter your choice:: ");
            fflush(stdin);
            scanf("%d",&choice);
            if (choice==1)
            {
                int a=0;
                printf("\n\nenter name of student to modify: ");
                fflush(stdin);
                scanf("%[^\n]",name);
                fs=fopen("student","rb+");
                while(fread(&stud,sizeof(stud),1,fs)==1)
                {
                    a=1;
                    if (strcmpi(name,stud.n)==0)
                    {
                        a=0;
                        printf("\nenter new name of student: ");
                        fflush(stdin);
                        scanf("%[^\n]",stud.n);
                        printf("\nenter new class of student: ");
                        fflush(stdin);
                        stud.c=clscanf();
                        printf("\nenter new roll of student: ");
                        fflush(stdin);
                        scanf("%d",&stud.r);
                        fseek(fs,-sizeof(stud),SEEK_CUR);
                        fwrite(&stud,sizeof(stud),1,fs);
                        fclose(fs);
                    }
                }
                if (a==1)
                    printf("\n\nRECORDS NOT FOUND");
                else
                    printf("\n\nRECORDS SUCCESSFULLY  MODIFIED");
                printf("\n\n");
                system("pause");
            }
            else if (choice==2)
            {
                int a=0;
                printf("\n\nenter name of student to modify: ");
                fflush(stdin);
                scanf("%[^\n]",name);
                printf("\n\nenter class of student to modify: ");
                fflush(stdin);
                cl=clscanf();
                fs=fopen("student","rb+");
                while(fread(&stud,sizeof(stud),1,fs)==1)
                {
                    a=1;
                    if (strcmpi(name,stud.n)==0 && cl==stud.c)
                    {
                        a=0;
                        printf("\nenter new name of student: ");
                        fflush(stdin);
                        scanf("%[^\n]",stud.n);
                        printf("\nenter new class of student: ");
                        fflush(stdin);
                        stud.c=clscanf();
                        printf("\nenter new roll of student: ");
                        fflush(stdin);
                        scanf("%d",&stud.r);
                        fseek(fs,-sizeof(stud),SEEK_CUR);
                        fwrite(&stud,sizeof(stud),1,fs);
                        fclose(fs);
                    }
                }
                if (a==1)
                    printf("\n\nRECORDS NOT FOUND");
                else
                    printf("\n\nRECORDS SUCCESSFULLY  MODIFIED");
                printf("\n\n");
                system("pause");
            }
            else if (choice==3)
            {
                int a=0;
                printf("\n\nenter name of student to modify: ");
                fflush(stdin);
                scanf("%[^\n]",name);
                printf("\n\nenter class of student to modify: ");
                fflush(stdin);
                cl=clscanf();
                printf("\n\nenter roll of student to modify: ");
                fflush(stdin);
                scanf("%d",&rolno);
                fs=fopen("student","rb+");
                while(fread(&stud,sizeof(stud),1,fs)==1)
                {
                    a=1;
                    if (strcmpi(name,stud.n)==0 && cl==stud.c &&rolno==stud.r)
                    {
                        a=0;
                        printf("\nenter new name of student: ");
                        fflush(stdin);
                        scanf("%[^\n]",stud.n);
                        printf("\nenter new class of student: ");
                        fflush(stdin);
                        stud.c=clscanf();
                        printf("\nenter new roll of student: ");
                        fflush(stdin);
                        scanf("%d",&stud.r);
                        fseek(fs,-sizeof(stud),SEEK_CUR);
                        fwrite(&stud,sizeof(stud),1,fs);
                        fclose(fs);
                    }
                }
                if (a==1)
                    printf("\n\nRECORDS NOT FOUND");
                else
                    printf("\n\nRECORDS SUCCESSFULLY  MODIFIED");
                printf("\n\n");
                system("pause");
            }
            else if (choice==4) ext();
            else
            {
                printf("\n\n\n\t\tINVALID ENTRY!!!!\n\n\t\t");
                system("pause");
                modrec(1);
            }

            printf("\n\nDo you want to continue with the process(press y or Y");
            fflush(stdin);
            c=getch();
        }
        getch();
    }
}
void delrec(int j)
{
    system("cls");
    printf("\n\t*********************          DELETE RECORD     *******************");
    FILE *temp,*t1;
    int a=1;
    char name[50],c='y';
    if (j==1)
    {
        while(c=='y'||c=='Y')
        {
            int a=1;
            printf("\n\nenter name of student to delete: ");
            fflush(stdin);
            scanf("%[^\n]",name);
            fs=fopen("student","rb");
            temp=fopen("tempfile","wb");//opening of temporary file for deleting process
            while (fread(&stud,sizeof(stud),1,fs)==1)
            {
                if (strcmp(stud.n,name)==0)
                {
                    a=0;
                    continue;
                }
                else
                {
                    fwrite(&stud,sizeof(stud),1,temp);
                }
            }

            if (a==1)
                printf("\n\nRECORD NOT FOUND");
            else
                printf("\n\nRECORD SUCCESSFULLY  DELETED");
            printf("\n\n");
            system("pause");
            fflush(stdin);

            fclose(fs);
            fclose(temp);
            system("del student");/*all data except the data to be
            deleted in student were 1st moved to temp and data in student
            was deleted*/
            system("ren tempfile, student");//renaming temp to student
            printf("\n\nDo you want to continue with the process(press y or Y");
            fflush(stdin);
            c=getch();
        }
        getch();
    }
}
void fee(int mm)
{
    system("cls");
    printf("\n\t*********************          FEE     *******************");
    FILE *f,*t;
    int a=0;
    char name[50],c='y';
    int clas, roll,month,dif;
    while(c=='y'||c=='Y')
    {
        int a=1,day=0;
        fflush(stdin);
        printf("\n\nEnter name:: ");
        scanf("%[^\n]",name);
        printf("\n\nEnter class:: ");
        fflush(stdin);
        clas=clscanf();
        printf("\n\nEnter roll:: ");
        fflush(stdin);
        scanf("%d",&roll);
        f=fopen("student","rb+");
        t=fopen("te","wb");
        while(fread(&stud,sizeof(stud),1,f)==1)
        {
            if(strcmp(stud.n,name)==0 && clas==stud.c && roll==stud.r)
            {
                a=0;
                printf("\n\nEnter the month and day till which fee to be paid:: ");
                fflush(stdin);
                scanf("%d",&month,&day);
                month=chkdat(month,day);
                dif=mm-stud.dt.m;
                stud.fine=(dif*stud.f)*0.01;
                stud.due=(dif)*stud.f;
                if (stud.fine<0) stud.fine=0;
                if (stud.due<0) stud.due=0;
                if (stud.tot<0) stud.tot=0;
                stud.tot=stud.fine+stud.due+stud.adv;
                printf("\nfine :: %.2f",stud.fine);
                printf("\ndue :: %.2f",stud.due);
                printf("\ntotal :: %.2f",stud.tot);
                printf("\nadvance :: %.2f",stud.adv);
                stud.dt.m=month;
                stud.tot=0;
                stud.fine=0;
                stud.due=0;
                fwrite(&stud,sizeof(stud),1,t);
            }
        }
        if (a==1)
            printf("\n\nRECORD NOT FOUND");
        printf("\n\n");
        system("pause");
        fflush(stdin);

        fclose(f);
        fclose(t);
        system("del student");
        system("ren te, student");
        printf("\n\nDo you want to continue with the process(press y or Y");
        fflush(stdin);
        c=getch();
    }
    getch();
}
void ext()
{
system("cls");
    printf("\n\n\t\t Thank you for using C Program School Billing System Project\n\n");
    system("pause");
    getch();
	exit(0);
}

int chkdat(int mnt,int dnt)
{
    int mon,day;
    if (mnt>12 || mnt<1 || dnt<1 || dnt>31)
    {
        MessageBox(0,"Invalid Date!\nEnter Again","Error!",0);

        fflush(stdin);
        scanf("%d%d",&mon,&day);
        mon=chkdat(mon,day);
    }
    else
        return (mnt);
}
int clscanf()
{
    int mnt,mon;
    fflush(stdin);
    scanf("%d",&mnt);
    if (mnt>12 ||mnt<1)
    {

        MessageBox(0,"Invalid Class!\nEnter Class","Error!!",0);
        fflush(stdin);
        mon=clscanf();
    }
    else
        return mnt;
}
