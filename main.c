#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
int survey(char type[]);
int submit();
void login();
void seller(char nameseller[]);
void sell(int price);
void transfer (int price);
void admin(void);
void ssort(char thing[],char nameseller[]);
///void search (file,char c[]);
///void basket(file);
void Purchasedgoods(void);
void specification(void);//send file of customer or name
void showbuy(char c[]);
void newgood();//send file the seller
void soldgood(void);//send file of customer or boss
void comment(char c[]);//send name of boss or customer
void bossmangerin(char c[]);///send name of file of boss too
void usres(char c[]);//send file of boss


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
} good;
typedef struct member//submit
{
    char name[100];
    char familyname[100];
    char username[1000];
    char password[1000];
    char phonenumber[15];
    char type[100];
    char homeaddrese[10000];
    char workaddrese[10000];

} memb;


int main()
{
    FILE *ptr=fopen("good.bin","a+b");
    FILE *ptt=fopen("memberspe.bin","a+b");
    FILE *Ptc=fopen("comment.bin","a+b");
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
        survey("guest");
        if(survey("guest")==0)
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
    printf("welcome to the submit section\nplease inter your name");
    gets(mem.name);
    printf("please inter family name");
    gets(mem.familyname);
    puts("user name ");
    gets(mem.username);
    puts("password");
    gets(mem.password);
    puts("phone numer");
    gets(mem.phonenumber);
    printf("are you customer or seller .if you are customer inter 0,if seller 1");

    int d;
    scanf("%d",&d);
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
                    survey("customer");
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

void customer()
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
        ///survey(file or name of file);
        break;
    case 2:
        ///Purchasedgoods(file or name of file);//sent file or name of file
//must create a time and array for dont recived item ;when the time passed item go to the recived array
        break;
    case 3:
        ///specification(file or name of file);
        //send the file or name of customer to open the file
        //change address ,username and...with structure send to function
        break;
    case 4:
        ///basket(file or name of file);
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
    puts("for add goods and sorting num1\nsee what you sold num2\n see opnions num3\nchange Specifications num 3\n surving num4\nTransfer to account num5 ");
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
        specification();//send file of seller
        break;
    case 4:
        survey("seller");
        break;
    case 5:
        //must have sellprice and use the transfer function
        //transfer();//send file or name of the file
        break;
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

    case 3:
        //comment();//send name of boss
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
                //get discountcode and save in file
                break;
            case 2:
                //get time;
                break;
            case 3:
                //get wage
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
    //print all customers and sellers i dont know how??
    printf("for seller num 1\nfor custmer num 2");
    int a;
    scanf("%d",&a);
    if(a==1)
    {
        printf("if you want to see basket of custmer print name of his");
        ///Purchasedgoods();
        //send name of the file
        ///or can open file of customer and print


    }
    if(a==2)
    {
        printf("if you want to see basket of custmer print name of his");
        //get name and open file of custmer
        printf("for decrease of see of sell num 1\n for delete num 2\n for delete seller num 3\n for back num 4  ");
        int a;
        do
        {


            scanf("%d",&a);
            switch(a)
            {
            case 1:
                //gets id of good and decrease it with search link list
                break;
            case 2:
                //gets id of good and delete it with search link list
                break;
            case 3:
                //delete file
                break;
            case 4:
                ///bossmangerin();//send name of boss or file
                break;

            }
        }
        while(a!=-1);


    }
}
int  survey(char type[])
{
    good goods;
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
            while(fread(&goods, sizeof (struct goodprofile), 1, ptr)) ///ok shod
            {
                printf ("%s  ,%d  ,%s  ,%d   ,%s   %s\n",goods.name,goods.price,goods.explanation,goods.num,goods.type);
                //fseek (ptr,-2*sizeof (struct goodprofile), SEEK_CUR);
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
                while(fread(&goods, sizeof (struct goodprofile), 1, ptr)) ///ok shod
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
                while(fread(&goods, sizeof (struct goodprofile), 1, ptt)) ///ok shod
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
                while(fread(&goods, sizeof (struct goodprofile), 1, ptt)) ///ok shod
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
                while(fread(&goods, sizeof (struct goodprofile), 1, pty)) ///ok shod
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
                while(fread(&goods, sizeof (struct goodprofile), 1, ptu)) ///ok shod
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
            basket();
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
                while(fread(&goods, sizeof (struct goodprofile), 1, ptr)) ///ok shod
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

        }}

    else if(strcmp(thing,"seller")==0)
    {
        printf("what kind of sort do you want 1-on price num 1\n on history num 2");
        int a;
        scanf("%d",&a);
        if(a==1)
        {
            //print structure on price

        }
        else
        {
            //print structure on score
        }
    }
    else if(strcmp(thing,"seller"))
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

void Purchasedgoods(void)//send file customer
{

    system("color b2");
    system("cls");

    //open link list customer goods
    printf("if you want to see recived goods num 0\nnon recived goods num1");
    int c;
    scanf("%c",&c);
    if(c==0)
    {
        //divide goods to recived and non recived with time and prin them
        printf("if you want to sort num 1\nand if you want to see the item information num 2 \n add comment num 3\nand back to the last menu num 4");
        int a;
        do
        {
            scanf("%d",&a);
            switch(a)
            {
            case 1:
                ///ssort(link list of goods struct);
                //send strucure
                break;
            case 2:
                printf("please inter the number of item ");
                //saved number of basket in every struct and divide with it
                break;
            case 3:
                printf("please inter the id of item ");

            ///showbuy();

            case 4:
                return customer();
                break;
            }

        }
        while(a!=-1);
        return customer();
    }
    if(c==1)
    {
        //print unrecived goods
        //check the goods non recived with time
        //next check if time out send massage to boss
        //to send massage open file boss and saved a massage in it
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


void basket()//send file or name of file customer
{
    int sumprice;
    int c;
    puts("if you want to add number1\nto remove num2 \n if you want to finish -1\n");
    do
    {

        scanf("%d",&c);
        switch(c)
        {
        case 1:
            //add to file link list basket
            ///sumprice+=price;
            break;
        case 2:
            //remove from file link list basket
            break;

        }
    }
    while(c!=-1);
    // save in file (link list of all buys with the sign recived or non recived structure),save name of custom
    ///sell(sumprice);
    //if sell return 1 ;save link list basket in the sold good link list and clean basket
    //if return 0;print eror;ask to save basket or clean it
}


void sell(int price)
{
    system("color a1");
    system("cls");
    //open the file of customer ,the file of password and id card
    int a,b;
    printf("pleae inter account number and internet password");
    scanf("%d",&a);
    scanf("%d",&b);
    int c=0,n;
    printf("if you have discount code please inter num 1\nif you dont have num 0");
    scanf("%d",&n);
    if(n==1)
    {
        //open the file boss struct discount
        //give percent discount save in int c
        //check the time that discount is ok

    }


    ///price=price-c*price/100;
    //check the all item if every thing is ok return 1 else return 0

}

void specification()
{
    //send file from custmer or seller
    //check the subtitle and chose the section
    ///if(type=="customer")
    printf("what section do you want to change");
    puts("for change username num1\nchange password num2\nchange addres num3\nchange phone number num 4\nand get out num -1");
    int a;
    do
    {
        scanf("%d",&a);
        switch(a)
        {
        case 1:
            //change username
            break;
        case 2:
            //change password
            break;
        case 3:
            //change addres
            break;
        case 4:
            //chnage phone number
            break;
        }
    }
    while(a!=-1);

    ///if(type=="seller");
    printf("what section do you want to change");
    puts("for change username num1\nchange password num2\nchange addres num3\nchange phone number num 4\nand get out num -1");
    int b;
    do
    {
        scanf("%d",&b);
        switch(b)
        {
        case 1:
            //change username
            break;
        case 2:
            //change password
            break;
        case 3:
            //change addres
            break;
        case 4:
            //chnage phone number
            break;
        }
    }
    while(b!=-1);

}



void newgood(char nameseller[])
{
    //print all of goods
    //add new good
    //sort good

    puts("if you want to add good num 1\n and sort the good num2\n to back num3");
    int a;


    do
    {
        scanf("%d",&a);
        if(a==1)
        {
            good goods;
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


    }
    while(a!=-1);

}

void soldgood()
{
    //maby need to create a file just for sold goods and then divide it with name of every seller and for boss show all of them
    //check the specifiaction of file if is customer show menu else menu 2
    ///if (spe=="customer")
    printf("if you wnat to sort inter 1 else 0");
    int a;
    scanf("%d",&a);
    if(a==1)
    {
        //ssort();//send file and how to sort
        //do in the future

    }
    ///if(spf=="boss")
    printf("if you wnat to sort inter 1 else 0");
    int b;
    scanf("%d",&b);
    if(b==1)
    {
        //ssort();//send file and how to sort
        //do in the future

    }

}


void comment(char c[])
{
    //open file of comment and sort them base history //use sort function
    //check the comment for divide comment for based on name send to function
    //add comment with name that sent to function
    ///if(c===name of boss)




    ///else
    printf("if you want to add comment num 1\n");
    //add comment with name of file

}


void transfer (int price)//send file or name of the file of seller
{
    system("color b3");
    system("cls");
    //opne file of id card \\transfer to it
    printf("please inter your account ID");

}







