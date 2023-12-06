#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<time.h>

int choice=1;
typedef struct mole
{
    int id;
    double mass;
    char name[20];
    char symbol[5];
    int group;
    char dd[20];
    struct mole *next;
} mole;
mole* createnodes()
{
    int n=119;
    mole *head=NULL,*tmp=NULL,*current=NULL;
    head=(mole*)malloc(sizeof(mole));
    current=head;
    int i=1;
    while(i<n)
    {
        tmp=(mole*)malloc(sizeof(mole));
        current->next=tmp;
        current=current->next;
        i++;
    }
    current->next=NULL;
    return head;
}
void loginmenu(mole * head);
void signin(mole * head);
void signup();
void delay(int number_of_seconds);
void menu(mole *head);
void display(mole *h);
void fileread(mole *head);
void displaymole(mole *h);
void findmole(mole *h);

void byname(mole *h){
    char name[20];
    system("cls");
    printf("        Enter name to search: ");
    scanf("%s",name);
    printf("\n\n");
    while(h!=NULL){
        if(strcmp(name,h->name)==0){
            displaymole(h);
            return;
        }
        h=h->next;
    }
    printf("        Not found!\n        Enter any key to continue......");
    getch();
}
void byan(mole *h){
    int id;
    system("cls");
    printf("        Enter Atomic number to search: ");
    scanf("%d",&id);
    while(h!=NULL){
        if(h->id==id){
            displaymole(h);
            return;
        }
        h=h->next;
    }
    printf("        Not found!\n        Enter any key to continue......");
    getch();
}
void bysymbol(mole *h){
    char sy[5];
    system("cls");
    printf("        Enter symbol to search: ");
    scanf("%s",sy);
    while(h!=NULL){
        if(strcmp(sy,h->symbol)==0){
            displaymole(h);
            return;
        }
        h=h->next;
    }
    printf("        Not found!\n        Enter any key to continue......");
    getch();
}
void byam(mole *h){
    double mass;
    system("cls");
    printf("        Enter Atomic mass to search: ");
    scanf("%lf",&mass);
    while(h!=NULL){
        if(h->mass==mass){
            displaymole(h);
            return;
        }
        h=h->next;
    }
    printf("        Not found!\n        Enter any key to continue......");
    getch();
}
void groupdisplay(mole * h){
    int c=1,g;
    system("cls");
    printf("        Enter group no to search: ");
    scanf("%d",&g);
    while(h!=NULL){
        if(h->group==g){
            printf("\n        %5d:%2s\n",h->id,h->symbol);
            c=0;
        }
        h=h->next;
    }
    if(c==1)printf("\n        Not found!\n        Enter any key to continue......\n");
        printf("\n        Enter any key to continue......");
    getch();
}


void fileread(mole *head)
{
    int id,group;
    double mass;
    char sy[5],nam[20],yer[20];
    FILE *fp;
    fp=fopen("Information.txt","r");
    for(int i=0; i<=118; ++i)
    {
        fscanf(fp,"%d\n%lf\n%s\n%s\n%s\n%d\n",&id,&mass,nam,sy,yer,&group);
        head->id=id;
        head->mass=mass;
        strcpy(head->name,nam);
        strcpy(head->symbol,sy);
        strcpy(head->dd,yer);
        head->group=group;
        head=head->next;
    }
    fclose(fp);
}
void displaymole(mole *h)
{
    printf("\n\n\t\tName          : %s\n\t\tSymbol        : %s\n\t\tAtomic Number : %d\n\t\tAtomic Mass   : %.5lf\n\t\tGroup         : %d\n\t\tDiscovery date: %s\n\n\n",h->name,h->symbol,h->id,h->mass,h->group,h->dd);
    printf("\n        Enter any key to continue......");
    getch();
    return;
}

void display(mole *h)
{
    system("cls");
    //system("color b");
    printf("\t\t\t\t\t\txxxxxxxxxx-----PERIODIC TABLE-----xxxxxxxxxx\n\n");
    for(int i=0; i<9; i++)
    {
        for(int j=0; j<18; j++)
        {
            if((i==0 && j>0 && j<17) || (i==1 && j>1 && j<12) || (i==2 && j>1 && j<12) || (i==7 && j<3) || (i==8 && j<3) || (i==7 && j>16) || (i==8 && j>16)) printf("        ");
            else
            {
                printf("%5d:%2s",h->id,h->symbol);
                h=h->next;
            }
        }
        printf("\n");
        printf("\n");
        printf("\n");
    }
    printf("\n        Enter any key to continue......");
    getch();
}
void findmole(mole *h){
    system("cls");
        printf("         ____________________________\n");
        printf("        |            MENU            |\n");
        printf("        |____________________________|\n");
        printf("        | 1.Find by Atomic number    |\n");
        printf("        | 2.Find by Atomic Mass      |\n");
        printf("        | 3.Find by Atomic Symbol    |\n");
        printf("        | 4.Find by Atomic Name      |\n");
        printf("        | 0.Exit                     |\n");
        printf("        |____________________________|\n");
        printf("        Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
        case 0: exit(0);
        case 1: byan(h);
                break;
        case 2:byam(h);
                break;
        case 3: bysymbol(h);
                break;
        case 4:byname(h);
                break;
        default:menu(h);
        }
}
void adminlogin(){
    system("cls");
    printf("        Coming Soon......, stay tuned ");
    printf("\n        Enter any key to continue......");
    getch();
}
void menu(mole *head)
{
    printf("            ____________________________\n");
    printf("           |          MAIN MENU         |\n");
    printf("           |____________________________|\n");
    printf("           | 1.View periodic table      |\n");
    printf("           | 2.Find Mole                |\n");
    printf("           | 3.Grouped View             |\n");
    printf("           | 4.Admin Login              |\n");
    printf("           | 0.Exit                     |\n");
    printf("           |____________________________|\n");
    printf("           Enter your choice: ");
    scanf("%d",&choice);
    switch(choice){
    case 0:exit(0);
    case 1:display(head);
            break;
    case 2:findmole(head);
            break;
    case 3:groupdisplay(head);
            break;
    case 4:adminlogin();
            break;
    default:menu(head);
    }
}
void delay(int number_of_seconds)
{
    int milli_seconds = 1000 * number_of_seconds;
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds)
        ;
}
void signup()
{
    FILE *fp;
    fp=fopen("detail.txt","a");
    char user[10],pass[10];
    system("cls");
    printf("\t\tENTER USERNAME: ");
    scanf("%s",user);
    printf("\t\tENTER PASSWORD: ");
    scanf("%s",pass);
    fprintf(fp,"%s\t%s\n",user,pass);
    fclose(fp);
    printf("\t\tSign-up Successful....\n\t\tEnter any key to continue");
    getch();
}
void signin(mole * head)
{
    system("cls");
    char user[10],pass[10];
    char fuser[10],fpass[10];
    int f,i=0;
    char ch;
    printf("\t\tENTER USERNAME: ");
    scanf("%s",user);
    printf("\t\tENTER PASSWORD: ");
    //scanf("%s",pass);
    while((ch=getch())!=13)
    {
        pass[i]=ch;
        printf("*");
        i++;
    }
    pass[i]='\0';
    FILE *fp;
    fp=fopen("detail.txt","r");
    while((fscanf(fp,"%s\t%s\n",fuser,fpass))!=-1)
    {
        if(strcmp(user,fuser)==0 && strcmp(pass,fpass)==0)
        {
            f=1;
            break;
        }
    }
    if(f==1)
    {
        printf("\n\t\tloading........\n");
        for(i=0; i<3; i++)
            delay(1);
        system("cls");
        printf("\n\t\t  Welcome %s\n",user);
        menu(head);
    }
    else{
        system("cls");
        printf("\n\t\tInvalid Username or Password\n\n\t\tEnter any key to continue");
        getch();
    }
    fclose(fp);
}
void loginmenu(mole * head){
        printf("             ____________________________\n");
        printf("            |            MENU            |\n");
        printf("            |____________________________|\n");
        printf("            | 1.Sign-Up                  |\n");
        printf("            | 2.Log-In                   |\n");
        printf("            | 0.Exit                     |\n");
        printf("            |____________________________|\n");
        printf("            Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
        case 1: signup();
                break;
        case 2:signin(head);
                break;
        default:exit(1);
        }
}


int main()
{
    mole * head=createnodes();
    fileread(head);
    while(choice!=0){
        system("cls");
        loginmenu(head);
        }
    return 0;
}
