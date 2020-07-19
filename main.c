#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
int survey(char type[],char name[]);
int submit();
void login();
void seller(char nameseller[]);
void customer(char namecustomer[]);
int sell(int price);
void transfer (int price);
void admin(void);
void ssort(char thing[],char nameseller[]);
//void search (file,char c[]);
void basket(char namecu[]);
void Purchasedgoods(char namecu[]);
void specification(char name[],char familyname[]);//send file of customer or name
void showbuy(char c[]);
void newgood();//send file the seller
void soldgood(void);//send file of customer or boss
void comment(char c[]);//send name of boss or customer
void bossmangerin(char c[]);///send name of file of boss too
void usres(char c[]);//send file of boss
void comment(char sellername[]);
void transfer (char nameseller[]);
char idcards[30];
char passwords[30];
char users[30];
int mojoody;
int time;
int karmozd;


typedef struct opinions
{
    char opinion[10000];
    int year;
    int mounth;
    int day;
    int hour;
    char name[1000];
    char nameseller[100];

} opinions;
typedef struct goodprofile//seller
{
    char name[1000];
    float  price;
    char explanation[200];
    int num;
    char type[100];
    int score;
    char nameseller[100];
    int id;
    char status[50];
} good;
typedef struct member//submit
{
    char name[100];
    char username[1000];
    char password[1000];
    char phonenumber[15];
    char type[100];
    char homeaddrese[10000];
    char workaddrese[10000];
    char status[50];

} memb;
typedef struct basket
{
    char status[100];
    char name[100];
    char namecustomer[100];
    char nameseller[100];
    int numbergood;
    int price;
    int year;
    int mounth;
    int day;
    int hour;

} baskets;
typedef struct card
{
    char id[100];
    char netpass[100];
    char user[100];
    int mojody;
    char type[50];
} card;
char idcards[30];
char passwords[30];
char users[30];
int mojoody;
int price=100;



int main()
{
    FILE *ptr=fopen("good.bin","a+b");
    FILE *ptt=fopen("memberspe.bin","a+b");
    FILE *Ptc=fopen("comment.bin","a+b");
    FILE *boosdis=fopen("dicount.bin","a+b");
    FILE *idcard=fopen("idcard.txt","a+");
    FILE *pmk=fopen ("basknotpay.bin", "a+b");
loop:
    system("color b0");
    system("cls");
    printf("Welcome to the main page of shop \n");
    printf("please inter the number of section you want:))\n");
    puts("1-for surving number 1\n2-for register number 2\n3-for login number 3");
    int a;
    scanf("%d",&a);

    switch(a)
    {
    case 1:
        survey("guest","");
        if(survey("guest","")==0)
        {
            goto loop;
        }
    case 2:
        submit();
    case 3:
        login();
    }

    return 0;
}

int  submit(void)
{
    memb mem;
    FILE *ptr=fopen("membersp","a+b");
    system("color e1");
    system("cls");
    //in this place i think we must use file in the past copmplete
    printf("welcome to the submit section\nplease inter your name and family name");
    gets(mem.name);
    puts("user name ");
    gets(mem.username);
    puts("password");
    gets(mem.password);
    puts("phone numer");
    gets(mem.phonenumber);
    printf("are you customer or seller .if you are customer inter 0,if seller 1");

    int d;
    scanf("%d",&d);
    char c[20];
    gets(c);
    if(d==0)
    {
        mem.type[100]="customer";
        printf("plese inter your home address ");
        gets(mem.homeaddrese);

    }
    else if(d==1)
    {
        mem.type[100]="seller";
        printf("plese inter work address");
        gets(mem.workaddrese);

    }
    int x=fwrite(&mem,sizeof(struct member),1,ptr);
    if(x==NULL)
    {
        printf("sorry your spefication dont save please inter again");
        submit();
    }


    printf("if you want back to main menu inter 1");
    int back;
    scanf("%d",&back);
    if(back)
    {
        return main();
    }


}

void login()
{

    //openn file declare in submit
    FILE *ptr=fopen("memberspe","a+b");
    char username[1000];
    printf("plese inter your username");
    gets(username);
    printf("plese inter your password");
    char password[1000];
    gets(password);
    memb members;
    ///customer(file or name of the file)||seller(file or name of file)
    fseek (ptr,-sizeof (struct member), SEEK_SET);
    if (ptr)
    {
        while(fread(&members, sizeof (struct member), 1, ptr)) ///ok shod
        {
            if(strcmp(password,members.password)==0&&strcmp(username,members.username)==0)
            {
                if(strcmp(members.type,"customer"))
                {
                    customer(members.name);
                }
                else if(strcmp(members.type,"seller"))
                {
                    seller(members.name);
                }


            }
            else
            {
                printf("sorry your username or password isnt true please inter again");
                login();
            }
        }
        fclose (ptr);
    }


}

void customer(char namecustomer[])
//must send stucture that have Specifications seller
{
    system("color c1");
    system("cls");
    printf("welcome to the customer section\n for surving number1\nfor see what you buyed and Non-delivered purchases number2\n for changing Specifications number3\nand for see shop list numer4\n back to the main page num 5\n");
    printf("for exist number -1");
    int a;
    scanf("%d",&a);
    switch(a)
    {
    case 1:
        survey("customer",namecustomer);
        break;
    case 2:
        Purchasedgoods(file or name of file);//sent file or name of file

        break;
    case 3:
        specification(namecustomer);
        //send the file or name of customer to open the file
        //change address ,username and...with structure send to function
        break;
    case 4:
        basket(char namecustomer);
        break;
    case 5:
        main();


    }

}

void seller(char nameseller[])
{
    system("color a1");
    system("cls");
    printf("welcome to the customer page");
    puts("for add goods and sorting num1\nsee what you sold num2\n see opnions num6\nchange Specifications num 3\n surving num4\nTransfer to account num5 ");
    //open file seller have link list for selles
    //open comment file
    int a;
    scanf("%d",&a);
    switch(a)
    {
    case 1:

        newgood(nameseller);//send file to add good
        break;
    case 2:
        soldgood();//send file of seller
        break;
    case 3:
        specification(nameseller);//send file of seller
        break;
    case 4:
        survey("guest",nameseller);
        break;
    case 5:

        transfer(nameseller);//send file or name of the file
        break;
    case 6:
        comment(nameseller,"seller");
        break;
    }

}
void comment(char sellername[],char type[])
{
    if(strcmp(type,"seller")==0)
    {
        opinions opin;
        FILE *fptr=fopen("comment.bin","a+b");
        int p[5][1000];
        int i=0;

        int temp;
        int j;
        int n;
        while(fread(&opin, sizeof (struct opinions), 1, fptr)!=NULL) ///ok shod
        {
            if(strcmp(sellername,opin.nameseller)==0)
            {
                p[0][1000]=i;
                p[1][1000]=opin.day;
                p[2][1000]=opin.hour;
                p[3][1000]=opin.mounth;
                p[4][1000]=opin.year;
                n++;
            }
            i++;


        }
        for(i=0; i<n; i++)
        {
            for(j=i; j<=n; j++)
            {
                if((p[4][i]<p[4][j])||(p[4][i]==p[4][j]&&p[3][i]<p[3][j])||(p[4][i]==p[4][j]&&p[3][i]==p[3][j]&&p[2][i]<p[2][j])||(p[4][i]==p[4][j]&&p[3][i]==p[3][j]&&p[2][i]<p[2][j]&&p[1][i]<p[1][j])
            {
                temp=p[0][j];
                    p[0][j]=p[0][i];
                    p[0][i]=temp;
                }
            }
        }
        opinions
        fseek(fptr,-sizeof(struct opinions),1);
        fclose(fptr);
        for(j=0; j<=n; j++)
        {
            FILE *pte=fopen("basknotpay.bin","a+b");
            fseek (pte,-sizeof (struct opinions), SEEK_SET);
            i=0;
            while(fread(&opin, sizeof (struct opinions), 1, pte)!=NULL) ///ok shod
            {
                if(p[0][j]==i)
                {
                    printf("  %d %d  %d  %d   \n",opin.hour,opin.day,opin.mounth,opin.year);

                }
                i++;
            }
        }
        fclose(pte)
    }
    if(strcmp(type,"boss")==0)
    {
        opinions opin;
        FILE *fptrbo=fopen("comment.bin","a+b");
        int p[5][1000];
        int i=0;

        int temp;
        int j;
        int n;
        while(fread(&opin, sizeof (struct opinions), 1, fptrbo)!=NULL) ///ok shod
        {

            p[0][1000]=i;
            p[1][1000]=opin.day;
            p[2][1000]=opin.hour;
            p[3][1000]=opin.mounth;
            p[4][1000]=opin.year;
            n++;
            i++;
        }
        for(i=0; i<n; i++)
        {
            for(j=i; j<=n; j++)
            {
                if((p[4][i]<p[4][j])||(p[4][i]==p[4][j]&&p[3][i]<p[3][j])||(p[4][i]==p[4][j]&&p[3][i]==p[3][j]&&p[2][i]<p[2][j])||(p[4][i]==p[4][j]&&p[3][i]==p[3][j]&&p[2][i]<p[2][j]&&p[1][i]<p[1][j])
            {
                temp=p[0][j];
                    p[0][j]=p[0][i];
                    p[0][i]=temp;
                }
            }
        }
        opinions
        fseek(fptrbo,-sizeof(struct opinions),1);
        fclose(fptrbo);
        for(j=0; j<=n; j++)
        {
            FILE *pteboos=fopen("basknotpay.bin","a+b");
            fseek (pteboos,-sizeof (struct opinions), SEEK_SET);
            i=0;
            while(fread(&opin, sizeof (struct opinions), 1, pteboos)!=NULL) ///ok shod
            {
                if(p[0][j]==i)
                {
                    printf("  %d %d  %d  %d   \n",opin.hour,opin.day,opin.mounth,opin.year);

                }
                i++;
            }
        }
        fclose(pteboos)



    }
    printf("if you want to add comment num 1 ");
    int c;
    scanf("%d",&c);
    if(c==1)
    {
        FILE *ptc=fopen("comment.bin","a+b");
        printf("please inter comment");
        gets(opin.opinion);
        printf("please inter name of good you want to add");
        getc(opin.name);///or
        /*int idgoods;
        int o=0;
        puts("please inter id good you want to comment ");
        scanf("%d",&idgoods);
        FILE *ppp=fopen ("good.bin", "a+b");
        fseek (ppp,-sizeof (struct goodprofile), SEEK_SET);
        if (ppp)
        {
            while(fread(&goods, sizeof (struct goodprofile), 1, ppp)!=NULL) ///ok shod
            {
                if(o==idgoods)
                {
                    break;
                }
                o++
            }
        strcpy(opin.name,goods.name);
            fclose (ptr);
        }*/

        SYSTEMTIME time;
        GetSystemTime(&time);
        opin.day=time.wDay;
        opin.hour=time.wHour;
        opin.year=time.wYear;
        opin.mounth=time.wMonth;
        strcpy(sellername,opin.nameseller);
        fwrite(&opin,sizeof (struct opinions), 1, ptc);
        fclose(ptc);

    }



}
void boss(void)
{
    system("color b3");
    system("cls");
    //open file for boss have link list for discount code ,all sold goods and time and percent of every sell
    //maby need to create a file just for sold goods and then divide it with name of every seller and for boss show all of them
    printf("for create discount num1\nsee all users num 2\nsee all comments num 3/nsee sales num 4\nsee unrecived good num 5");
    int a;
    scanf("%d",&a);
    switch(a)
    {
    case 1:
        bossmangerin("discountkode");///send name of file of boss too
        break;
    case 2:
        users();
        break

    case 3:
        comment();//send name of boss
        break;
    case 4:
        soldgood();//send file or name of the boss
        break;
    case 5:
        bossmangerin("unrecived");//send file of boss to

    }

}
void bossmangerin(char c[])
{
    if (c=="discountkode")
    {
        //open boss file declare code and ... in it
        printf("if you want to declare discount code num 1\n to declare time to cancel order num2\nwage of order num 3\n to back num -1or 4");
        int a;
        do
        {
            scanf("%d",&a);
            switch(a)
            {
            case 1:
                FILE *ptr=fopen("dicount.bin","a+b");
                dis discode;
                printf("idcard");
                scanf("%s",discode.idcard);
                printf("year\n");
                scanf("%d",&discode.year);
                printf("mounth\n");
                scanf("%d",&discode.mounth);
                printf("day\n");
                scanf("%d",&discode.day);
                printf("hour\n");
                scanf("%d",&discode.hour);
                fwrite(&discode,sizeof(struct discount),1,ptr);
                fclose(ptr);
                break;
            case 2:
                printf("please inter time recived");
                scanf("%d",&time);
                break;
            case 3:
                printf("please inter wage for evry sell");
                scanf("%d",&karmozd);
                break;
            case 4:
                boss();//send file that recived
                break;



            }
        }
        while(a!=-1);


    }
    else if(c=="unrecived")
    {

        //print all unrecived sold
        //change unrecived sold ro recived


    }


}



void user(char c[])
{
    good goods;
    memb members;
    FILE *ptr=fopen("membersp.bin","r+b");
    while(fread(&members, sizeof (struct member), 1, ptr)!=0)
    {
        printf("%s  %s ",members.name,members.type);
    }
    fclose(ptr);
int a;
    do
    {
        memb members;
        basket bask;
        int k=0;
        int t=0;
        int i=0;
        int j=0;

        printf("if you want to sort based on baskets num 1 for customer num 6 for seller\n based on price for customer num 2 for seller num 7\n see seller goods num and decrease goods seller num 3\n delete seller num5 and for exit num -1\n");

        int n=0;
        int temp;
        int temp1;
        scanf("%d",&a);
        char c[50];
        gets(c);
        int idgood=0;
        if(a==1)
        {
            int p[2][100];
            FILE *pyu=fopen("membersp.bin","a+b");
            FILE *pre=fopen("basknotpay.bin", "a+b");
            while(fread(&members,sizeof(struct member),1,pyu)!=0)
            {
                p[1][k]=0;
                while(fread(&bask,sizeof(struct basket),1,pyu)!=0)
                {
                    if(strcmp(bask.namecustomer,members.name)==0&&strcmp(members.type,"customer")==0)
                    {
                        p[0][k]=k;
                        p[1][k]+=1;
                        n++;
                    }
                }
                k++;
            }
            for(i=0; i<n; i++)
            {
                for(j=i; j<n; j++)
                {
                    if(p[1][j]>p[1][i])
                    {
                        temp=p[1][j];
                        p[1][j]=p[1][i];
                        p[1][i]=temp;
                        temp1=p[0][j];
                        p[0][j]=p[0][i];
                        p[0][i]=temp1;
                    }
                }

            }
            fclose(pyu);
            fclose(pre);
            j=0;
              for(i=0; i<n; i++)
            {
                FILE *poi=fopen("membersp.bin","a+b");

                while(fread(&members,sizeof(struct member),1,pyu)!=0)
                {
                    if(p[0][i]==j)
                    {
                        printf("%s   %d",members.name,p[1][i]);
                    }
                    j++;

                }
            }
        }
        if(a==2)
        {
            int p[2][100];
            FILE *pyu=fopen("membersp.bin","a+b");
            FILE *pre=fopen("basknotpay.bin", "a+b");
            while(fread(&members,sizeof(struct member),1,pyu)!=0)
            {
                p[1][k]=0;
                while(fread(&bask,sizeof(struct basket),1,pyu)!=0)
                {
                    if(strcmp(bask.namecustomer,members.name)==0&&strcmp(members.type,"customer")==0)
                    {
                        p[0][k]=k;
                        p[1][k]+=bask.price;
                        n++;
                    }
                }
                k++;
            }
            for(i=0; i<n; i++)
            {
                for(j=i; j<n; j++)
                {
                    if(p[1][j]>p[1][i])
                    {
                        temp=p[1][j];
                        p[1][j]=p[1][i];
                        p[1][i]=temp;
                        temp1=p[0][j];
                        p[0][j]=p[0][i];
                        p[0][i]=temp1;
                    }
                }

            }
            fclose(pyu);
            fclose(pre);
            j=0;
              for(i=0; i<n; i++)
            {
                FILE *poi=fopen("membersp.bin","a+b");

                while(fread(&members,sizeof(struct member),1,pyu)!=0)
                {
                    if(p[0][i]==j)
                    {
                        printf("%s   %d",members.name,p[1][i]);
                    }
                    j++;

                }
            }

        }
        if(a==3)
        {
            FILE *pyu=fopen("good.bin","a+b");
            while(fread(&goods,sizeof(struct goodprofile),1,pyu)!=0)
            {
                printf("%s  %s  %s",goods.name,goods.nameseller,goods.num);
                printf("%d\n",idgood);

            }
            puts("if you want to decrese number of good num 1");
            fclose(pyu);
            int num;
            scanf("%d",&num);
            char c[50];///alaki
            gets(c);
            if(num==1)
            {
                printf("please inter id of good you want ");
                int id;
                scanf("%d",&id);
                FILE *ptt=fopen("good.bin","r+b");
                i=0;
                while(fread(&goods,sizeof(struct goodprofile),1,ptt)!=0)
                {
                    i++;
                    if(i==id)
                    {
                        break;
                    }

                }
                printf("please inter number of good you want to decrese ");
                int number;
                scanf("%d",&number);
                if(number>goods.num)
                {
                    printf("you cant decrese goodsnum<number you want");
                    continue;
                }
                goods.num-=number;
                fseek(ptt,(id)*sizeof(struct goodprofile),SEEK_SET);
                fwrite(&goods,sizeof(struct goodprofile),1,ptt);



            }




        }

        if(a==5)
        {
            FILE *pgo=fopen("good.bin","r+b");
            printf("please inter name you want to remove");
            char name [100];
            char namecu[50][50];
            char namese[50][50];
            int price[2][50];
            int pricet=0;
            gets(name);
            i=0;
            j=0;
            while(fread(&goods,sizeof(struct goodprofile),1,pgo)!=0)
            {
                if(strcmp(goods.nameseller,name)==0)
                {

                    strcpy(goods.status,"removedbyboss");
                    fseek(pgo,(i)*sizeof(struct goodprofile),SEEK_SET);
                    fwrite(&goods,sizeof(struct goodprofile),1,pgo);
                    j++;
                }
                i++;
            }
            fclose(pgo);

            FILE *pyy=fopen("membersp.bin","r+b");
            int j=0;
            while(fread(&members,sizeof(struct member),1,pyy)!=0)
            {
                if(strcmp(members.name,name)==0)
                {
                    printf("%s  %s",members.name,members.status);
                    strcpy(members.status,"removedbyboss");
                    fseek(pyy,(j)*sizeof(struct member),SEEK_SET);
                    fwrite(&members,sizeof(struct member),1,pyy);
                }
                j++;
            }
            fclose(pyy);
            FILE *plk=fopen ("basknotpay.bin", "a+b");
            i=0;
            j=0;
            ///esafe kardan khesarat
            while(fread(&bask,sizeof(struct basket),1,plk)!=0)
            {
                if(strcmp(bask.nameseller,name)==0)
                {
                    strcpy(namecu[i],bask.namecustomer);
                    strcpy(namese[i],bask.nameseller);
                    price[0][i]=i;
                    price[1][i]=bask.price;
                    pricet+=bask.price;

                    i++;

                }
            }
            fclose(plk);
            FILE *puu=fopen("idcard.txt","r+");
            int numg;
            for(j=0; j<i; j++)
            {
                while(fscanf(pyy,"%29s %29s %29s %d",idcards,passwords,users,&mojoody)!=0)
                {
                    if(strcmp(namecu[j],users)==0)
                    {
                        break;
                    }
                    numg++;

                }
                mojoody+=price[1][j];
                fseek(puu,(numg)*(strlen(idcards)+strlen(passwords)+strlen(users)+9),SEEK_SET);
                fprintf(puu,"\n%s %s %s %d\n",idcards,passwords,users,mojoody);
                numg=0;
            }
            numg=0;
            fclose(puu);
            FILE *piu=fopen("idcard.txt","r+");

             for(j=0; j<i; j++)
            {
                while(fscanf(piu,"%29s %29s %29s %d",idcards,passwords,users,&mojoody)!=0)
                {
                    if(strcmp(namese[j],users)==0)
                    {
                        break;
                    }
                    numg++;

                }
                mojoody-=(price[1][j]-price[1][j]*karmozd/100);
                fseek(piu,(numg)*(strlen(idcards)+strlen(passwords)+strlen(users)+9),SEEK_SET);
                fprintf(piu,"\n%s %s %s %d\n",idcards,passwords,users,mojoody);
                numg=0;
            }
numg=0;
fclose(piu);

FILE *pmk=fopen("idcard.txt","r+");

             for(j=0; j<i; j++)
            {
                while(fscanf(pmk,"%29s %29s %29s %d",idcards,passwords,users,&mojoody)!=0)
                {
                    if(strcmp("boss",users)==0)
                    {
                        break;
                    }
                    numg++;

                }
                mojoody-=(pricet*karmozd/100);
                fseek(pmk,(numg)*(strlen(idcards)+strlen(passwords)+strlen(users)+9),SEEK_SET);
                fprintf(pmk,"\n%s %s %s %d\n",idcards,passwords,users,mojoody);
                numg=0;
            }

fclose(pmk);


        }
        if(a==6)
        {
            int p[2][100];
            FILE *pyu=fopen("membersp.bin","a+b");
            FILE *pre=fopen("basknotpay.bin", "a+b");
            while(fread(&members,sizeof(struct member),1,pyu)!=0)
            {
                p[1][k]=0;
                while(fread(&bask,sizeof(struct basket),1,pyu)!=0)
                {
                    if(strcmp(bask.nameseller,members.name)==0&&strcmp(members.type,"seller")==0)
                    {
                        p[0][k]=k;
                        p[1][k]+=1;
                        n++;
                    }
                }
                k++;
            }
            for(i=0; i<n; i++)
            {
                for(j=i; j<n; j++)
                {
                    if(p[1][j]>p[1][i])
                    {
                        temp=p[1][j];
                        p[1][j]=p[1][i];
                        p[1][i]=temp;
                        temp1=p[0][j];
                        p[0][j]=p[0][i];
                        p[0][i]=temp1;
                    }
                }

            }
            fclose(pyu);
            fclose(pre);
            j=0;
              for(i=0; i<n; i++)
            {
                FILE *poi=fopen("membersp.bin","a+b");

                while(fread(&members,sizeof(struct member),1,pyu)!=0)
                {
                    if(p[0][i]==j)
                    {
                        printf("%s   %d",members.name,p[1][i]);
                    }
                    j++;

                }
            }
        }
        if(a==7)
        {
            int p[2][100];
            FILE *pyu=fopen("membersp.bin","a+b");
            FILE *pre=fopen("basknotpay.bin", "a+b");
            while(fread(&members,sizeof(struct member),1,pyu)!=0)
            {
                p[1][k]=0;
                while(fread(&bask,sizeof(struct basket),1,pyu)!=0)
                {
                    if(strcmp(bask.nameseller,members.name)==0&&strcmp(members.type,"seller")==0)
                    {
                        p[0][k]=k;
                        p[1][k]+=bask.price;
                        n++;
                    }
                }
                k++;
            }
            for(i=0; i<n; i++)
            {
                for(j=i; j<n; j++)
                {
                    if(p[1][j]>p[1][i])
                    {
                        temp=p[1][j];
                        p[1][j]=p[1][i];
                        p[1][i]=temp;
                        temp1=p[0][j];
                        p[0][j]=p[0][i];
                        p[0][i]=temp1;
                    }
                }

            }
            fclose(pyu);
            fclose(pre);
            j=0;
              for(i=0; i<n; i++)
            {
                FILE *poi=fopen("membersp.bin","a+b");

                while(fread(&members,sizeof(struct member),1,pyu)!=0)
                {
                    if(p[0][i]==j)
                    {
                        printf("%s   %d",members.name,p[1][i]);
                    }
                    j++;

                }
            }



        }

    }while(a!=-1);





}
int  survey(char type[],char name[])
{
    good goods;
    int idgood=0;
    do
    {

        system("color e1");
        system("cls");
        printf("welcome to the item list\n");
        puts("we have 3itemes now\nif you want to add a filter please inter number1");
        puts("if you want to searching item number2\ for see  item number 3\nand if you want to go to the main page inter -1 ");
        puts("Foodstuff  \t   Stationery  \t   Digital goods");
        FILE *ptr=fopen ("good.bin", "rb");
        fseek (ptr,-sizeof (struct goodprofile), SEEK_SET);
        if (ptr)
        {
            while(fread(&goods, sizeof (struct goodprofile), 1, ptr)!=NULL) ///ok shod
            {
                printf ("%s  ,%d  ,%s  ,%d   ,%s   %s  ",goods.name,goods.price,goods.explanation,goods.num,goods.type);
                printf("%d\n",idgood);
                //fseek (ptr,-2*sizeof (struct goodprofile), SEEK_CUR);
                idgood++;
            }


            fclose (ptr);
        }

        puts("if you want to see just9 \n1 super market num4\nstationary num5\ndigital goods num6");
        puts("if you want too add comment num 7\nto buy num 8");
        //open the file of goods &show it(print file)
        //open the file customer or seller or admin
        //goods file have 3 section with link list super market & satationary  &digital goods

        int a;
        printf("\nplease inter the num section");
        scanf("%d",&a);

        switch(a)
        {
        case 1:
            //send goods file to function ssort
            ssort("goods","");
            break;

        case 2:
            //send goods file & name that we need to search
            printf("please inter name of good you want to search");
            char name[1000];
            gets(name);
            FILE *ptr=fopen ("good.bin", "a+b");
            fseek (ptr,-sizeof (struct goodprofile), SEEK_SET);
            if (ptr)
            {
                while(fread(&goods, sizeof (struct goodprofile), 1, ptr)!=NULL) ///ok shod
                {
                    if(strcmp(name,goods.name)==0)
                    {
                        printf ("%s  ,%f  ,%s  ,%d   ,%s   %s\n",goods.name,goods.price,goods.explanation,goods.num,goods.type);
                        //fseek (ptr,-2*sizeof (struct goodprofile), SEEK_CUR);
                    }
                }
            }
            fclose(ptr);

            break;
        case 3:
            printf("please inter name of good");
            char namese[1000];
            gets(namese);
            FILE *ptt=fopen ("good.bin", "a+b");
            fseek (ptt,-sizeof (struct goodprofile), SEEK_SET);
            if (ptt)
            {
                while(fread(&goods, sizeof (struct goodprofile), 1, ptt)!=NULL) ///ok shod
                {
                    if(strcmp(namese,goods.name)==0)
                    {
                        printf ("%s  ,%f  ,%s  ,%d   ,%s   %s\n",goods.name,goods.price,goods.explanation,goods.num,goods.type);

                        //fseek (ptr,-2*sizeof (struct goodprofile), SEEK_CUR);
                    }
                }
            }
            fclose(ptt);

            break;


        case 4:

            printf("food market");
            FILE *ptz=fopen ("good.bin", "a+b");
            fseek (ptz,-sizeof (struct goodprofile), SEEK_SET);
            if (ptz)
            {
                while(fread(&goods, sizeof (struct goodprofile), 1, ptt)!=NULL) ///ok shod
                {
                    if(strcmp("food market",goods.type)==0||strcmp("foodmarket",goods.type)==0);
                    {
                        printf ("%s  ,%f  ,%s  ,%d   ,%s   %s\n",goods.name,goods.price,goods.explanation,goods.num,goods.type);

                        //fseek (ptr,-2*sizeof (struct goodprofile), SEEK_CUR);
                    }
                }
            }
            fclose(ptt);
            break;


        case 5:
            printf("Stationery");
            FILE *pty=fopen ("good.bin", "a+b");
            fseek (pty,-sizeof (struct goodprofile), SEEK_SET);
            if (pty)
            {
                while(fread(&goods, sizeof (struct goodprofile), 1, pty)!=NULL) ///ok shod
                {
                    if(strcmp("stationery",goods.type)==0)
                    {
                        printf ("%s  ,%f  ,%s  ,%d   ,%s   %s\n",goods.name,goods.price,goods.explanation,goods.num,goods.type);

                        //fseek (ptr,-2*sizeof (struct goodprofile), SEEK_CUR);
                    }
                }
            }
            fclose(pty);
            break;


        case 6:
            printf("Digital goods");
            FILE *ptu=fopen ("good.bin", "a+b");
            fseek (ptu,-sizeof (struct goodprofile), SEEK_SET);
            if (ptu)
            {
                while(fread(&goods, sizeof (struct goodprofile), 1, ptu)!=NULL) ///ok shod
                {
                    if(strcmp("Digital goods",goods.type)==0||strcmp("Digital goods",goods.type))
                    {
                        printf ("%s  ,%f  ,%s  ,%d   ,%s   %s\n",goods.name,goods.price,goods.explanation,goods.num,goods.type);

                        //fseek (ptr,-2*sizeof (struct goodprofile), SEEK_CUR);
                    }
                }
            }
            fclose(ptu);
            break ;



        case 7:
            if(strcmp(type,"guest")!=0)
            {
                opinions opin;
                puts("please inter the name of goods you want to add comment ");
                ///agar khaty zir ra jaygozin kon
                /*  int idgoods;
                int o=0;
                puts("please inter id good you want to comment ");
                scanf("%d",&idgoods);
                FILE *ppp=fopen ("good.bin", "a+b");
                fseek (ppp,-sizeof (struct goodprofile), SEEK_SET);
                if (ppp)
                {
                    while(fread(&goods, sizeof (struct goodprofile), 1, ppp)!=NULL) ///ok shod
                    {
                        if(o==idgoods)
                        {
                            break;
                        }
                        o++
                    }

                    fclose (ptr);
                }
                strcpy(opin.name,goods.name);*/
                char name[1000];
                gets(opin.name);
                FILE *ptc=fopen("comment.bin","a+b");
                printf("please inter comment");
                gets(opin.opinion);
                SYSTEMTIME time;
                GetSystemTime(&time);
                opin.day=time.wDay;
                opin.hour=time.wHour;
                opin.year=time.wYear;
                opin.mounth=time.wMonth;
                fwrite(&opin,sizeof (struct opinions), 1, ptc);
                fclose(ptc);

            }
            fclose(ptr);



            break;

        case 8:
            if(strcmp(type,"guest")!=0)
            {

                basket bask;

                int a;
                do
                {
                    printf("for exit iner -1");
                    scanf("%d",&a);
                    FILE *ptb=fopen("basknotpay.bin","a+b");
                    FILE *ptr=fopen ("good.bin", "a+b");
                    basket bask;
                    int number;
                    char name[100];//hazf
                    int idgood=0;
                    printf("please inter id number of good;");
                    int id;
                    scanf("%d",&id);
                    //fwrite(&goods,sizeof(goods),1,ptb)
                    int i=0;
                    while(fread(&goods, sizeof (struct goodprofile), 1, ptr)!=NULL) ///ok shod
                    {
                        //printf ("%s  ,%d  ,%s  ,%d   ,%s   %s  ",goods.name,goods.price,goods.explanation,goods.num,goods.type);
                        //printf("%d\n",idgood);
                        if(i==id)
                        {
                            printf("%s",goods.name);
                            break;
                        }
                        i++;

                    }
                    printf("please inter number of goods you want");
                    int numbergood;
                    scanf("%d",&numbergood);
                    if(numbergood>goods.num)
                    {
                        printf("not have enogh goods");
                        continue;
                    }
                    bask.numbergood=numbergood;
                    strcpy(bask.name,goods.name);
                    bask.price=goods.price;
                    strcpy(bask.nameseller,goods.nameseller);
                    SYSTEMTIME time;
                    GetSystemTime(&time);
                    bask.day=time.wDay;
                    bask.hour=time.wHour;
                    bask.year=time.wYear;
                    bask.mounth=time.wMonth;
                    bask.numbergood=numbergood;
                    strcpy(bask.namecustomer,name);
                    strcpy(bask.nameseller,goods.nameseller);
                    fwrite(&bask,sizeof(basket),1,ptb);

                }
                while(a!=-1)
                }

            break;
        case 9:
        {
            opinions opin;
            printf("please inter name of good you want to see");
            char name[1000];
            gets(name);
            FILE *ptr=fopen ("good.bin", "a+b");
            fseek (ptr,-sizeof (struct goodprofile), SEEK_SET);
            if (ptr)
            {
                while(fread(&goods, sizeof (struct goodprofile), 1, ptr)!=NULL) ///ok shod
                {
                    if(strcmp(name,goods.name)==0)
                    {
                        printf ("%s  ,%f  ,%s  ,%d   ,%s   %s\n",goods.name,goods.price,goods.explanation,goods.num,goods.type);
                        printf ("\t%s  %d  %d  %d  %d\n",opin.opinion,opin.mounth,opin.hour,opin.day,opin.year);
                        //fseek (ptr,-2*sizeof (struct goodprofile), SEEK_CUR);
                    }
                }
            }
            fclose(ptr);
        }



        case -1:
            return main();
            break;

        }



    }
    while(1);
}



void ssort(char thing[],char sellername[])
{
    baskets bask;
    if(strcmp(thing,"seller1"))==0)
    {

        printf("if you want to sort based on num");

        int numb[2][1000];
        int i=0;
        int n=0;
        FILE *pmk=fopen ("basknotpay.bin", "a+b");
        fseek (pmk,-sizeof (struct basket), SEEK_SET);
        if (pmk)
        {
            while(fread(&bask, sizeof (struct basket), 1, pmk)!=0) ///ok shod
            {

                numb[0][i]=i;
                numb[1][i]=bask.num;
                n++;

                i++;
            }
            numb[2][i+1]=0;
        }
        //fclose(pmk);

        int temp=0;
        int temp1=0;
        int j=0;
        for(i=0; i<n; i++)
        {
            for(j=i; j<n; j++)
            {
                if(numb[1][j]>numb[1][i])
                {
                    temp=numb[1][j];
                    numb[1][j]=numb[1][i];
                    numb[1][i]=temp;
                    temp1=numb[0][j];
                    numb[0][j]=numb[0][i];
                    numb[0][i]=temp1;
                }
            }

        }

        //fseek (pcc,-sizeof (struct goodprofile), SEEK_SET);
        for(j=0; j<n; j++)
        {
            FILE *pju=fopen ("basknotpay.bin", "a+b");
            fseek (pju,-sizeof (struct basket), SEEK_SET);
            i=0;
            while(fread(&bask, sizeof (struct basket), 1, pju)!=0) ///ok shod
            {
                if(numb[0][j]==i)
                {
                    printf ("%s %d\n",bask.name,goods.num);
                }
                i++;

            }
        }

    }

    if(strcmp(thing,"seller1"))==0)
    {

        printf("if you want to sort based on num \if you want to sort based on histroy num 2");
        int h;
        scanf("%d",&h);
        if(h==1)
        {
            int num[2][1000];
            int i=0;
            int n=0;
            FILE *pyy=fopen ("basknotpay.bin", "a+b");
            fseek (pyy,-sizeof (struct basket), SEEK_SET);
            if (pyy)
            {
                while(fread(&bask, sizeof (struct basket), 1, pyy)!=0) ///ok shod
                {
                    if(strcmp(bask.nameseller,sellername)==0)///dorost she
                    {
                        printf ("%s,%d,%s\n",bask.name,bask.price,bask.nameseller);
                        num[0][i]=i;
                        num[1][i]=bask.num;
                        n++;
                    }
                    i++;
                }
                num[2][i+1]=0;
            }
            //fclose(pyy);
            for(i=0; i<n; i++)
            {
                printf("%d   %d\n",num[0][i],num[1][i]);
            }
            int temp=0;
            int temp1=0;
            int j=0;
            for(i=0; i<n; i++)
            {
                for(j=i; j<n; j++)
                {
                    if(num[1][j]>num[1][i])
                    {
                        temp=num[1][j];
                        num[1][j]=num[1][i];
                        num[1][i]=temp;
                        temp1=num[0][j];
                        num[0][j]=num[0][i];
                        num[0][i]=temp1;
                    }
                }

            }
            for(i=0; i<n; i++)
            {
                printf("%d   %d\n",num[0][i],num[1][i]);
            }
            i=0;
            //fseek (pcc,-sizeof (struct goodprofile), SEEK_SET);

            for(j=0; j<n; j++)
            {
                FILE *pcc=fopen ("basknotpay.bin", "a+b");
                fseek (pcc,-sizeof (struct basket), SEEK_SET);
                i=0;
                while(fread(&bask, sizeof (struct basket), 1, pcc)!=0) ///ok shod
                {
                    if(num[0][j]==i)
                    {
                        printf ("%s %d\n",bask.name,goods.num);
                    }
                    i++;

                }
            }
        }
        if(h==2)
        {
            FILE *fptr=fopen("basknotpay.bin","a+b");
            int p[5][1000];
            int i=0;
            baskets base;
            int temp;
            int j;
            int n;
            while(fread(&base, sizeof (struct basket), 1, fptr)!=NULL) ///ok shod
            {
                if(strcmp(sellername,base.nameseller)==0)
                {
                    p[0][1000]=i;
                    p[1][1000]=base.day;
                    p[2][1000]=base.hour;
                    p[3][1000]=base.mounth;
                    p[4][1000]=base.year;
                    n++;
                }
                i++;


            }
            for(i=0; i<n; i++)
            {
                for(j=i; j<=n; j++)
                {
                    if((p[4][i]<p[4][j])||(p[4][i]==p[4][j]&&p[3][i]<p[3][j])||(p[4][i]==p[4][j]&&p[3][i]==p[3][j]&&p[2][i]<p[2][j])||(p[4][i]==p[4][j]&&p[3][i]==p[3][j]&&p[2][i]<p[2][j]&&p[1][i]<p[1][j])
                {
                    temp=p[0][j];
                        p[0][j]=p[0][i];
                        p[0][i]=temp;
                    }
                }
            }
            fseek(fptr,-sizeof(struct basket),1);
            fclose(fptr);
            for(j=0; j<=n; j++)
            {
                FILE *pte=fopen("basknotpay.bin","a+b");
                fseek (pte,-sizeof (struct basket), SEEK_SET);
                i=0;
                while(fread(&base, sizeof (struct basket), 1, pte)!=NULL) ///ok shod
                {
                    if(p[0][j]==i)
                    {
                        printf("  %d %d  %d  %d   \n",base.hour,base.day,base.mounth,base.year);

                    }
                    i++;
                }
            }

        }

    }



    if(strcmp(thing,"good")==0)
{
    printf("what kind of sort do you want 1-on price num 1\n 2-on score num 2");
        int a;
        scanf("%d",&a);
        if(a==1)
        {
            //print structure on price
            good goods;
            int i;
            int price[2][1000];
            i=0;
            int n=0;
            FILE *pyy=fopen ("good.bin", "a+b");
            fseek (pyy,-sizeof (struct goodprofile), SEEK_SET);
            if (pyy)
            {
                while(fread(&goods, sizeof (struct goodprofile), 1, pyy)!=0) ///ok shod
                {
                    printf ("%s,%d,%s,%d,%s  %s\n",goods.name,goods.price,goods.explanation,goods.num);
                    price[0][i]=i;
                    price[1][i]=goods.price;
                    i++;
                    n++;
                }
                price[2][i+1]=0;
            }
            fclose(pyy);
            for(i=0; i<n; i++)
            {
                printf("%d   %d\n",price[0][i],price[1][i]);
            }
            int temp=0;
            int temp1=0;
            int j=0;
            for(i=0; i<n; i++)
            {
                for(j=i; j<n; j++)
                {
                    if(price[1][j]<price[1][i])
                    {
                        temp=price[1][j];
                        price[1][j]=price[1][i];
                        price[1][i]=temp;
                        temp1=price[0][j];
                        price[0][j]=price[0][i];
                        price[0][i]=temp1;
                    }
                }

            }
            for(i=0; i<n; i++)
            {
                printf("%d   %d\n",price[0][i],price[1][i]);
            }
            i=0;
            //fseek (pcc,-sizeof (struct goodprofile), SEEK_SET);

            for(j=0; j<4; j++)
            {
                FILE *pcc=fopen ("good.bin", "a+b");
                fseek (pcc,-sizeof (struct goodprofile), SEEK_SET);
                i=0;
                while(fread(&goods, sizeof (struct goodprofile), 1, pcc)!=0) ///ok shod
                {
                    if(price[0][j]==i)
                    {
                        printf ("%s,%d,%s,%d,%s  %s\n",goods.name,goods.price,goods.explanation,goods.num);
                    }
                    i++;

                }
            }


        }
        else
        {

            int score[2][1000];
            good goods;
            int i=0;
            int n=0;
            FILE *pyy=fopen ("good.bin", "a+b");
            fseek (pyy,-sizeof (struct goodprofile), SEEK_SET);
            if (pyy)
            {
                while(fread(&goods, sizeof (struct goodprofile), 1, pyy)!=0) ///ok shod
                {
                    printf ("%s,%d,%s,%d,%s  %s\n",goods.name,goods.score,goods.explanation,goods.num);
                    score[0][i]=i;
                    score[1][i]=goods.score;
                    i++;
                    n++;
                }
                score[2][i+1]=0;
            }
            fclose(pyy);
            for(i=0; i<n; i++)
            {
                printf("%d   %d\n",score[0][i],score[1][i]);
            }
            int temp=0;
            int temp1=0;
            int j=0;
            for(i=0; i<n; i++)
            {
                for(j=i; j<n; j++)
                {
                    if(score[1][j]>score[1][i])
                    {
                        temp=score[1][j];
                        score[1][j]=score[1][i];
                        score[1][i]=temp;
                        temp1=score[0][j];
                        score[0][j]=score[0][i];
                        score[0][i]=temp1;
                    }
                }

            }
            for(i=0; i<n; i++)
            {
                printf("%d   %d\n",score[0][i],score[1][i]);
            }
            i=0;
            //fseek (pcc,-sizeof (struct goodprofile), SEEK_SET);

            for(j=0; j<4; j++)
            {
                FILE *pcc=fopen ("good.bin", "a+b");
                fseek (pcc,-sizeof (struct goodprofile), SEEK_SET);
                i=0;
                while(fread(&goods, sizeof (struct goodprofile), 1, pcc)!=0) ///ok shod
                {
                    if(score[0][j]==i)
                    {
                        printf ("%s,%d,%s,%d,%s  %s\n",goods.name,goods.score,goods.explanation,goods.num);
                    }
                    i++;

                }
            }

        }
    }

    else if(strcmp(thing,"customer")==0)
{
    printf("what kind of sort do you want 1-on price num 1\n on history num 2");
        int a;
        scanf("%d",&a);
        if(a==1)
        {
            //print structure on price
            baskets sortp;
            int i;
            int price[2][1000];
            i=0;
            int n=0;
            FILE *pyy=fopen ("basknotpay.bin", "a+b");
            fseek (pyy,-sizeof (struct basket), SEEK_SET);
            if (pyy)
            {
                while(fread(&sortp, sizeof (struct basket), 1, pyy)!=0) ///ok shod
                {
                    if(strcmp(sortp.namecustomer,sellername)==0)
                    {
                        price[0][i]=i;
                        price[1][i]=sortp.price;

                        n++;
                    }
                    i++;

                }
                price[2][i+1]=0;
            }
            fclose(pyy);
            for(i=0; i<n; i++)
            {
                printf("%d   %d\n",price[0][i],price[1][i]);
            }
            int temp=0;
            int temp1=0;
            int j=0;
            for(i=0; i<n; i++)
            {
                for(j=i; j<n; j++)
                {
                    if(price[1][j]<price[1][i])
                    {
                        temp=price[1][j];
                        price[1][j]=price[1][i];
                        price[1][i]=temp;
                        temp1=price[0][j];
                        price[0][j]=price[0][i];
                        price[0][i]=temp1;
                    }
                }

            }
            for(i=0; i<n; i++)
            {
                printf("%d   %d\n",price[0][i],price[1][i]);
            }
            i=0;


            for(j=0; j<4; j++)
            {
                FILE *pcc=fopen ("basknotpay.bin", "a+b");
                fseek (pcc,-sizeof (struct basket), SEEK_SET);
                i=0;
                while(fread(&sortp, sizeof (struct basket), 1, pcc)!=0) ///ok shod
                {
                    if(price[0][j]==i)
                    {
                        printf ("%s,%s %d,\n",sortp.name,sortp.nameseller,sortp.price);
                    }
                    i++;

                }
            }





        }
        else
        {
            FILE *fptr=fopen("basknotpay.bin","a+b");
            int p[5][1000];
            int i=0;
            baskets basks;
            int temp;
            int j;
            int n;
            while(fread(&basks, sizeof (struct basket), 1, fptr)!=NULL) ///ok shod
            {

                if(strcmp(sellername,basks.namecustomer)==0)
                {
                    p[0][1000]=i;
                    p[1][1000]=basks.day;
                    p[2][1000]=basks.hour;
                    p[3][1000]=basks.mounth;
                    p[4][1000]=basks.year;
                    n++;
                }
                i++;


            }
            for(i=0; i<n; i++)
            {
                for(j=i; j<=n; j++)
                {
                    if((p[4][i]<p[4][j])||(p[4][i]==p[4][j]&&p[3][i]<p[3][j])||(p[4][i]==p[4][j]&&p[3][i]==p[3][j]&&p[2][i]<p[2][j])||(p[4][i]==p[4][j]&&p[3][i]==p[3][j]&&p[2][i]<p[2][j]&&p[1][i]<p[1][j])
                {
                    temp=p[0][j];
                        p[0][j]=p[0][i];
                        p[0][i]=temp;
                    }
                }
            }
            fseek(fptr,-sizeof(struct basket),1);
            fclose(fptr);
            for(j=0; j<=n; j++)
            {
                FILE *pte=fopen("basknotpay.bin","a+b");
                fseek (pte,-sizeof (struct basket), SEEK_SET);
                i=0;
                while(fread(&basks, sizeof (struct basket), 1, pte)!=NULL) ///ok shod
                {
                    if(p[0][j]==i)
                    {
                        printf("%s %s %s  %d\n",basks.name,basks.nameseller,basks.status,basks.price);

                    }
                    i++;
                }
            }
        }
    }
    else if(strcmp(thing,"seller")==0)
{
    good goods;
    printf("if you want to sort based on number of thing num1\if you want to sort based on score num 2");
        int h;
        scanf("%d",&h);
        if(h==1)
        {
            int num[2][1000];
            int i=0;
            int n=0;
            FILE *pyy=fopen ("good.bin", "a+b");
            fseek (pyy,-sizeof (struct goodprofile), SEEK_SET);
            if (pyy)
            {
                while(fread(&goods, sizeof (struct goodprofile), 1, pyy)!=0) ///ok shod
                {
                    if(strcmp(goods.nameseller,sellername)==0)
                    {
                        printf ("%s,%d,%s,%d,%s  %s\n",goods.name,goods.num,goods.explanation,goods.num);
                        num[0][i]=i;
                        num[1][i]=goods.num;
                        n++;
                    }
                    i++;
                }
                num[2][i+1]=0;
            }
            //fclose(pyy);
            for(i=0; i<n; i++)
            {
                printf("%d   %d\n",num[0][i],num[1][i]);
            }
            int temp=0;
            int temp1=0;
            int j=0;
            for(i=0; i<n; i++)
            {
                for(j=i; j<n; j++)
                {
                    if(num[1][j]>num[1][i])
                    {
                        temp=num[1][j];
                        num[1][j]=num[1][i];
                        num[1][i]=temp;
                        temp1=num[0][j];
                        num[0][j]=num[0][i];
                        num[0][i]=temp1;
                    }
                }

            }
            for(i=0; i<n; i++)
            {
                printf("%d   %d\n",num[0][i],num[1][i]);
            }
            i=0;
            //fseek (pcc,-sizeof (struct goodprofile), SEEK_SET);

            for(j=0; j<n; j++)
            {
                FILE *pcc=fopen ("good.bin", "a+b");
                fseek (pcc,-sizeof (struct goodprofile), SEEK_SET);
                i=0;
                while(fread(&goods, sizeof (struct goodprofile), 1, pcc)!=0) ///ok shod
                {
                    if(num[0][j]==i)
                    {
                        printf ("%s  %d\n",goods.nameseller,goods.num);
                    }
                    i++;

                }
            }

        }
        if(h==2)
        {
            int score[2][1000];
            int i=0;
            int n=0;
            FILE *pyy=fopen ("good.bin", "a+b");
            fseek (pyy,-sizeof (struct goodprofile), SEEK_SET);
            if (pyy)
            {
                while(fread(&goods, sizeof (struct goodprofile), 1, pyy)!=0) ///ok shod
                {
                    if(strcmp(goods.nameseller,sellername)==0)
                    {
                        printf ("%s,%d,%s,%d,%s  %s\n",goods.name,goods.score,goods.explanation,goods.num);
                        score[0][i]=i;
                        score[1][i]=goods.score;
                        n++;
                    }
                    i++;
                }
                score[2][i+1]=0;
            }
            //fclose(pyy);
            for(i=0; i<n; i++)
            {
                printf("%d   %d\n",score[0][i],score[1][i]);
            }
            int temp=0;
            int temp1=0;
            int j=0;
            for(i=0; i<n; i++)
            {
                for(j=i; j<n; j++)
                {
                    if(score[1][j]>score[1][i])
                    {
                        temp=score[1][j];
                        score[1][j]=score[1][i];
                        score[1][i]=temp;
                        temp1=score[0][j];
                        score[0][j]=score[0][i];
                        score[0][i]=temp1;
                    }
                }

            }
            for(i=0; i<n; i++)
            {
                printf("%d   %d\n",score[0][i],score[1][i]);
            }
            i=0;
            //fseek (pcc,-sizeof (struct goodprofile), SEEK_SET);

            for(j=0; j<n; j++)
            {
                FILE *pcc=fopen ("good.bin", "a+b");
                fseek (pcc,-sizeof (struct goodprofile), SEEK_SET);
                i=0;
                while(fread(&goods, sizeof (struct goodprofile), 1, pcc)!=0) ///ok shod
                {
                    if(score[0][j]==i)
                    {
                        printf ("%s  %d\n",goods.nameseller,goods.score);
                    }
                    i++;

                }
            }


        }
    }
}




void search(void)
{
    printf("please inter your name ");
    //get char
    //search in structures and  if there is exist show it
}

void Purchasedgoods(char namecu[])//send file customer
{

    system("color b2");
    system("cls");


    printf("if you want to see recived goods num 0\nnon recived goods num1");
    int c;
    scanf("%c",&c);
    if(c==0)
    {
        FILE *prr=fopen("basknotpay.bin","a+b");
        int id=0;
        baskets bask;
        SYSTEMTIME time;
        GetSystemTime(&time);
        while(fread(&bask, sizeof (struct basket), 1, prr)!=NULL) ///ok shod///after one hour
        {
            if((bask.day<time.wDay)||(bask.hour<time.wHour)|| (bask.year<time.wYear)||(bask,bask.mounth<time.wMonth))
            {
                printf(" %s %s %s  ",bask.name,bask.nameseller,bask.status);
                printf("%d\n",id);
                id++;
            }


        }
        fclose(prr);

        //divide goods to recived and non recived with time and prin them
        printf("if you want to sort num 1\nand if you want to see the item information num 2\nand back to the last menu num 3");
        int a;
        do
        {
            scanf("%d",&a);
            switch(a)
            {
            case 1:
                ssort("customer",namecu);
                //send strucure
                break;
            case 2:
                int idgood;
                basket bas;
                //good goods;
                opinions opp;
                int numg=0;
                printf("please inter the number of item ");
                scanf("%d",&idgood);
                FILE *pcc=fopen ("basknotpay.bin", "a+b");
                fseek (pcc,-sizeof (struct basket), SEEK_SET);
                int i=0;
                while(fread(&bas, sizeof (struct basket), 1, pcc)!=0) ///ok shod
                {
                    i++;
                    if(idgood==i)
                    {
                        break;
                    }
                }
                FILE *poi=fopen("goods.bin","a+b");
                while(fread(&goods, sizeof (struct goodprofile), 1, poi)==0) ///ok shod
                {
                    if(strcmp(goods.name,bas.name)==0)
                    {
                        printf("%s  %s  %s  %d  %d ",goods.name,goods.explanation,goods.nameseller,goods.price,goods.score);
                    }

                }

                printf("if you want to add comment write comment");
                char c[100];
                gets(c);

                if(strcmp(c,"comment")==0)
                {
                    FILE *pjj=fopen("comment.bin","a+b");
                    printf("please add comment");
                    gets(opp.opinion);
                    strcpy(opp.name,bas.name);
                    strcpy(opp.nameseller,bas.nameseller);
                    SYSTEMTIME time;
                    GetSystemTime(&time);
                    opp.day=time.wDay;
                    opp.hour=time.wHour;
                    opp.year=time.wYear;
                    opp.mounth=time.wMonth;
                    fwrite(&opp,sizeof(struct opinions),1,pjj);

                }
                printf("if you want to give score inter score");
                char g[50];
                gets(g);
                if(strcmp(g,"score")==0)
                {
                    FILE *pnn=fopen("goods.bin","a+b");
                    while(fread(&goods, sizeof (struct goodprofile), 1, pnn)==0) ///ok shod
                    {

                        if(strcmp(goods.name,bas.name)==0)
                        {
                            break;

                        }
                        numg++;

                    }
                    printf("please inter your score");
                    int scor;
                    scanf("%d",&scor);
                    goods.score+=scor;
                    fseek(pnn,(numg)*sizeof(struct goodprofile),SEEK_SET);
                    fwrite(&goods,sizeof(struct goodprofile),1,pnn);

                }

                //saved number of basket in every struct and divide with it
                break;
            case 3:
                return customer(namecu);
                break;


            }

        }
        while(a!=-1);
        return customer();
    }
    if(c==1)
    {
        FILE *pll=fopen("basknotpay.bin","a+b");
        int id=0;
        baskets bask;
        SYSTEMTIME time;
        GetSystemTime(&time);
        while(fread(&bask, sizeof (struct basket), 1, pll)!=NULL) ///ok shod
        {
            if((bask.day>=time.wDay)&& (bask.year>=time.wYear)&&(bask,bask.mounth>=time.wMonth))
            {
                if((bask.hour-time.wHour)<=1)
                {
                    printf("  %s  ",bask.status);
                    printf("%d  minute to send good",(60-time.wMinute));
                    printf("%d\n",id);
                    id++;
                    fclose(pll);

                }

            }


        }
        printf("what section do you want to change");

    }


}
void showbuy(char c[])
{
    system("color b2");
    system("cls");
    //open file of seller and search for id item recived and show it
    printf("if you want to add comment num 1\ngive score num 2 \nback to the last page num 3");
    int a;
    do
    {
        scanf("%d",&a);
        switch(a)
        {
        case 1:
            //add comment maby in file seller or maby make comment file and save in it
            break;
        case 2:
            //define sumscore in struct of every good and get score from customer/number of customer that give score
            break;
        case 3:
            Purchasedgoods();
            break;
        }
    }
    while(a!=-1);
}


void basket(char namecu[])//send file or name of file customer
{
    baskets bask;
    int id=0;
    FILE *ptu=fopen("basknotpay.bin","a+b");
    fseek (ptu,-sizeof (struct basket), SEEK_SET);
    while(fread(&bask, sizeof (struct basket), 1, ptu)!=NULL) ///ok shod
    {
        printf("  %s  ",bask.status);
        printf("%d\n",id);
        id++;

    }
    fclose(ptu);
    int a;
    int idgood;
    int pricet=0;
    int counter=0;
    card idca;
    int k=0;
    int t=0;



    FILE *pty=fopen("basknotpay.bin","r+b");
    do
    {
        printf("if you want to finish buying nember 2 \n for remove number 1 ");
        scanf("%d",&a);
        if(a==1)
        {
            printf("please inter id number");
            scanf("%d",&idgood);
            strcpy(bask.status,"remove");
            fseek(pty,(idgood)*sizeof(struct basket),SEEK_SET);
            fwrite(&bask,sizeof(struct basket),1,pty);

        }

    }
    while(a!=2);
    FILE *pee=fopen("basknotpay.bin","a+b");

    while(fread(&bask, sizeof (struct basket), 1, ptu)!=NULL) ///ok shod
    {
        if(strcmp(bask.status,"remove")!=0)
        {
            printf("%s %d  %d %s  %s  \n",bask.name,bask.price,bask.numbergood,bask.namecustomer,bask.nameseller);
            pricet+=bask.price;
            counter++;

        }


    }
    fclose(pee);
    printf("total price :%d $",pricet);
    FILE *puu=fopen("basknotpay.bin","r+b");
    if(sell(pricet)==1)
    {
        int num=0;

        FILE *aut=fopen ("basknotpay.bin", "a+b");
        FILE *iut=fopen ("good.bin", "r+b");
        ///variz be hesab froshandejh
        FILE *ptr;
        FILE *ptf=fopen ("basknotpay.bin", "a+b");
        card idca;
        int idk=0;
        int numpr=0;
        ///variz be boss
        k=0;
        t=0;

        FILE *pyy=fopen("idcard.txt","r+");
        fseek (pyy,0, SEEK_SET);
        char idcards[30];
        char passwords[30];
        char users[30];

        int t=0;

        if (pyy)
        {

            while(fscanf(pyy,"%29s %29s %29s %d",idcards,passwords,users,&mojoody)!=0)
            {

                if(strcmp(users,"boss")==0)
                {
                    break;

                }
                t++;

            }


            mojoody+=((int)price[1][k]*karmozd/100);
            fseek(pyy,(t)*(strlen(idcards)+strlen(passwords)+strlen(users)+9),SEEK_SET);
            fprintf(pyy,"\n%s %s %s %d\n",idcards,passwords,users,mojoody);

        }
        t=0;
        fclose(pyy);
        *pyy=fopen("idcard.txt","r+");

        if (pyy)
        {

            while(fscanf(pyy,"%29s %29s %29s %d",idcards,passwords,users,&mojoody)!=0)
            {

                if(strcmp(users,namecu)==0)
                {
                    break;

                }
                t++;

            }


            mojoody-=price[1][k];
            fseek(pyy,(t)*(strlen(idcards)+strlen(passwords)+strlen(users)+9),SEEK_SET);
            fprintf(pyy,"\n%s %s %s %d\n",idcards,passwords,users,mojoody);

        }
        t=0;
        fclose(pyy);


        int price[2][100];


        while(fread(&bask, sizeof (struct basket), 1, ptf)!=NULL) ///ok shod
        {
            ptr=fopen("idcard.txt","r+");
            while(fscanf(pyy,"%29s %29s %29s %d",idcards,passwords,users,&mojoody)!=0) ///ok shod
            {
                if(strcmp(bask.nameseller,users)==0&&strcmp(bask.status,"removed")!=0&&strcmp(bask.status,"buyed")!=0)
                {


                    price[0][k]=idk;
                    price[1][k]=bask.price;
                    k++;
                    numpr++;
                }
                idk++;
            }
        }


        for(k=0; k<numpr; k++)
        {
            iut=fopen("idcard.txt","r+");
            fseek (iut,0, SEEK_SET);
            while(fscanf(pyy,"%29s %29s %29s %d",idcards,passwords,users,&mojoody)!=0) ///ok shod
            {
                if(price[0][k]==t)
                {
                    break;

                }
                t++;

            }
            mojoody+=(price[1][k]-((int)price[1][k]*karmozd/100));
            fseek(iut,(t)*(strlen(idcards)+strlen(passwords)+strlen(users)+9),SEEK_SET);
            fprintf(iut,"\n%s %s %s %d\n",idcards,passwords,users,mojoody);
            t=0;
            fclose(iut);

        }
        fclose(ptr);
        fclose(ptf);

        while(fread(&goods, sizeof (struct goodprofile), 1, iut)!=NULL) ///ok shod
        {
            printf("%s  %d\n",goods.name,goods.num);

        }
        printf("bask\n\n\n");
        while(fread(&bask, sizeof (struct basket), 1, aut)!=NULL) ///ok shod
        {
            printf("%s  %d\n",bask.name,bask.numbergood);


        }
        int n[20][100];
        fclose(iut);
        fclose(aut);
        FILE *ptz=fopen ("basknotpay.bin", "a+b");
        int i=0;
        FILE *ptr;
        int idkalas=0;
        while(fread(&bask, sizeof (struct basket), 1, ptz)!=NULL) ///ok shod
        {
            ptr=fopen ("good.bin", "r+b");
            while(fread(&goods, sizeof (struct goodprofile), 1, ptr)!=NULL) ///ok shod
            {
                if(strcmp(bask.name,goods.name)==0&&strcmp(bask.status,"removed")!=0&&strcmp(bask.status,"buyed")!=0)
                {

                    printf("%s  %s  %d\n",bask.name,goods.name,idkalas);
                    n[0][i]=idkalas;
                    n[1][i]=bask.numbergood;
                    i++;
                    num++;

                }
                idkalas++;
            }
            idkalas=0;
            fclose(ptr);

        }
        i=0;
        int j=0;
        for(i=0; i<num; i++)
        {
            FILE *iut=fopen ("good.bin", "r+b");
            fseek (iut,-sizeof (struct goodprofile), SEEK_SET);
            while(fread(&goods, sizeof (struct goodprofile), 1, iut)!=NULL) ///ok shod
            {
                if(n[0][i]==j)
                {

                    break;

                }
                j++;

            }
            goods.num-=n[1][i];
            fseek(iut,(j)*sizeof (struct goodprofile),SEEK_SET);
            fwrite(&goods,sizeof (struct goodprofile), 1, iut);
            j=0;
            fclose(iut);

        }


        while(counter!=0) ///ok shod
        {
            if(strcmp(bask.status,"remove")!=0)
            {

                strcpy(bask.status,"buyed");
                fseek(puu,(counter)*sizeof(struct basket),SEEK_SET);
                SYSTEMTIME time;
                GetSystemTime(&time);
                bask.day=time.wDay;
                bask.hour=time.wHour;
                bask.year=time.wYear;
                bask.mounth=time.wMonth;
                fwrite(&bask,sizeof(struct basket),1,puu);
                printf("ok");
                counter--;
            }


        }
        fseek (ptu,-sizeof (struct basket), SEEK_SET);
        while(fread(&bask, sizeof (struct basket), 1, ptu)!=NULL) ///ok shod
        {
            printf("  %s  ",bask.status);
            printf("%d\n",id);
            id++;

        }

    }
    fclose(puu);

}


int sell(int price)
{
    system("color a1");
    system("cls");
    //open the file of customer ,the file of password and id card
    FILE *boosdis=fopen("dicount.bin","a+b");
    FILE *idcard= fopen("idcard.txt","r+");
    card idcards;
    printf("if you have discount counter inter discount");
    char idcas[30];
    char passs[30];
    int mojody;
    char dis[20];
    gets(dis);
    dis disco;
    SYSTEMTIME time;
    GetSystemTime(&time);
    if(strcmp(dis,"discount")==0)
    {
        printf("please inter your discount id");
        char discode[50];
        while(fread(&disco, sizeof (struct discount), 1, boosdis)==0) ///ok shod
        {

            if(strcmp(discode,disco.idcard)==0)
            {
                if((disco.year<time.wYear)||(disco.year==time.wYear&&disco.mounth<time.wMonth)||(disco.year==time.wYear&&disco.mounth==time.wMonth&&disco.day<time.wDay)||(disco.year==time.wYear&&disco.mounth==time.wMonth&&disco.day==time.wDay&&disco.hour<time.wHour)
            {
                price=(int)(price*((100-disco.percent)/100))
                }

            }
            id++;

        }
        printf("please inter your id card");
        gets(idcas);
        printf("please inter your internet password");
        gets(passs);
        int nums=0;
        while(fscanf(idcard,"%29s %29s %29s %d",idcards,passwords,users,&mojoody))!=EOF)
        {
            if(strcmp(idcas,idcards)==0&&strcmp(passs,password)==0)
            {
                if(price<mojoody)
                {
                    mojoody-=price;
                    fseek(idcard,(nums)*(strlen(idcards)+strlen(passwords)+strlen(users)+9),SEEK_SET);
                    fprintf(idcard,"\n%s %s %s %d\n",idcards,passwords,users,mojoody);
                    return 1;
                }

            }
            nums++;
        }
    }

    void specification(char name[])
    {
        FILE *ptr=fopen("membersp","r+b");
        memb member;///add name to debug
        int id=0;
        while(fread(&member, sizeof (struct member), 1, ptr)==0) ///ok shod
        {

            if(strcmp(name,member.name)==0&&strcmp(familyname,member.familyname)==0)
            {
                break;

            }
            id++;

        }
        printf("please inter your name");
        gets(member.name);
        printf("please inter family name");
        gets(member.familyname);
        puts("user name ");
        gets(member.username);
        puts("password");
        gets(member.password);
        puts("phone numer");
        gets(member.phonenumber);
        if(strcmp(member.type,"customer")==0)
        {
            printf("plese inter your home address ");
            gets(member.homeaddrese);
        }
        else
        {
            printf("plese inter work address");
            gets(member.workaddrese);
        }
        fseek(ptr,(id)*sizeof(member),SEEK_SET);
        fwrite(&member,sizeof(member),1,ptr);

    }



    void newgood(char nameseller[])
    {
        //print all of goods
        //add new good
        //sort good

        puts("if you want to add good inter addgood\n and sort the good inter sort\n to back num3\n and add to Inventory num 4 ");
        int a;

        good goods;
        do
        {
            scanf("%d",&a);
            char c[5];///alaki
            gets(c);///alaki

            if(a==1)
            {

                FILE *ptr=fopen("good.bin","a+b");
                printf("please inter name of good");
                gets(goods.name);
                printf("please price good");
                scanf("%d",goods.price);
                printf("inter explain for good");
                gets(goods.explanation);
                printf("please inter number of good(inventory)");
                scanf("%d",goods.num);
                printf("please inter type of good notice must be foodmarket or stationary or Digitalgoods ");
                gets(goods.type);
                printf("please inter your name (seller)");
                gets(goods.nameseller);
                int x=fwrite(&goods,sizeof(struct goodprofile),1,ptr);
                fclose(ptr);
            }



            if(a==2)
            {
                ssort("seller","");
            }


            if(a==3)
            {
                seller(nameseller);
            }
            if(a==4)
            {
                int id=0;
                FILE *ptr=fopen ("good.bin", "r+b");
                fseek (ptr,-sizeof (struct goodprofile), SEEK_SET);

                if (ptr)
                {
                    while(fread(&goods, sizeof (struct goodprofile), 1, ptr)) ///ok shod
                    {
                        printf ("%s ,%d ,",goods.name,goods.num);
                        printf("%d\n",id);
                        //fseek (ptr,-2*sizeof (struct goodprofile), SEEK_CUR);
                        id++;
                    }
                    printf("please inter number you wnat to add");
                    int nums;
                    scanf("%d",&nums);
                    goods.num+=nums;
                    printf("chose id");
                    scanf("%d",&id);
                    fseek(ptr,(id)*sizeof (struct goodprofile),SEEK_SET);
                    fwrite(&goods,sizeof (struct goodprofile), 1, ptr);
                    fseek (ptr,-sizeof (struct goodprofile), SEEK_SET);
                    fclose (ptr);
                }



            }


        }
        while(a!=-1);

    }

    void soldgood(char type[],char name[])
    {
        good goods;

        int c;
        scanf("%d",&c);
        char str[];///alaki
        gets(str);///alaki
        basket base;
        if (strcmp(type,"seller")==0)
        {
            printf("for see all sold goods and sort them inter 1  for see soldgood just for one good num 2");
            if(c==1)
            {

                FILE *pcc=fopen ("basknotpay.bin", "a+b");
                fseek (pcc,-sizeof (struct basket), SEEK_SET);

                while(fread(&base, sizeof (struct basket), 1, pcc)!=0) ///ok shod
                {
                    if(strcmp(base.nameseller,name)==0)
                    {
                        printf ("%s,%d,%d\n",base.name,base.numbergood,base.price);
                    }

                }
                fclose(pcc);
                ssort("seller1",name);

            }
            else if(c==2)
            {
                int id=0;

                FILE *poo=fopen ("basknotpay.bin", "a+b");
                fseek (poo,-sizeof (struct basket), SEEK_SET);
                printf("please inter name of your good");
                char namegood[50];
                while(fread(&base, sizeof (struct basket), 1, poo)!=0) ///ok shod
                {
                    if(strcmp(base.name,namegood)==0&&strcmp(base.nameseller,name)==0)
                    {
                        printf ("%s,%d,%d\n",base.name,base.numbergood,base.price);
                    }

                }


            }
        }


        else if(strcmp(type,"boss")==0)
        {

            printf("if you want to see your soldgoods num 1");
            int f;
            scanf("%d",&f);
            if(f==1)
            {
                FILE *plo=fopen ("basknotpay.bin", "a+b");
                fseek (plo,-sizeof (struct basket), SEEK_SET);

                while(fread(&base, sizeof (struct basket), 1, plo)!=0) ///ok shod
                {
                    if(strcmp(base.nameseller,name)==0)
                    {
                        printf ("%s,%d,%d\n",base.name,base.numbergood,base.price);
                    }

                }
                fclose(plo);
                ssort("seller1",name);
            }
            if(f==2)
            {
                FILE *puu=fopen ("basknotpay.bin", "a+b");
                fseek (puu,-sizeof (struct basket), SEEK_SET);

                while(fread(&base, sizeof (struct basket), 1, puu)!=0) ///ok shod
                {
                    printf ("%s,%d,%d\n",base.name,base.numbergood,base.price);
                }
                fclose(puu);
                ssort("bossall",name);

            }

        }



    }

    void transfer (char nameseller[])//send file or name of the file of seller
    {
        FILE *ptr=fopen("idcard.txt","r+");
        printf("please inter your idcard");
        gets(idcards);
        mojoody=0;
        printf("please inter net pass (not important)");
        gets(passwords);
        strcpy(users,nameseller);
        fprintf(ptr,"\n%s %s %s %d\n",idcards,passwords,users,mojoody);


    }






///format card bank  char idcard[30]--char password[30]--int mojoody


