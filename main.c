#include<stdio.h>
#include <stdlib.h>
int survey(char c[]);
int submit();
void login();
void seller();
void sell(int price);
void transfer (int price);
void admin(void);
///void ssort(file);
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
typedef struct goodprofile//seller
{
    char name[100];
    float  price;
    char explanation[200];
    int num;
    char type;

} good;
typedef struct member//submit
{
    char name[100];
    char familyname[100];
    char username[1000];
    char password[10000];
    char phonenumber[15];
    char type[100];
    char homeaddrese[10000];
    char workaddrese[10000];
} memb;

int main()
{
    FILE *ptr=fopen("good.bin","a+b");
    FILE *ptt=fopen("memberspe","a+b");
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

    char a[20];
    printf("plese inter your username");
    scanf("%s",&a);
    printf("plese inter your password");
    //check information with these
    //return file or name of the file for seller or customer back to the survey
    int c;
    scanf("%d",&c);
    ///customer(file or name of the file)||seller(file or name of file)

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

void seller(void)
{
    system("color a1");
    system("cls");
    printf("welcome to the customer page");
    puts("for add goods num1\nsee what you sold num2\n see opnions num3\nchange Specifications num 3\n surving num4\nTransfer to account num5 ");
    //open file seller have link list for selles
    //open comment file
    int a;
    scanf("%d",&a);
    switch(a)
    {
    case 1:

        newgood();//send file to add good
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
int  survey(char c[])
{
    do
    {

        system("color e1");
        system("cls");
        printf("welcome to the item list\n");
        puts("we have 3itemes now\nif you want to add a filter please inter number1");
        puts("if you want to searching item number2\ for see  item number 3\nand if you want to go to the main page inter -1 ");
        puts("Foodstuff  \t   Stationery  \t   Digital goods");
        puts("if you want to see just \n1 super market num4\nstationary num5\ndigital goods num6");
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
            ///ssort(file);
            break;

        case 2:
            //send goods file & name that we need to search
            ///search(file ,char c[]);
            break;
        case 3:
            printf("please inter the code of the item\n");
            ///search (file,char c[])
            printf("if you want to see proposal of item num 1\n");
            //print propasol
            break;


        case 4:
            //print link list of food in file
            printf("food market");

            int d;
            scanf("%d",&d);
            printf("if you want to see the sort inter num 1\n");
            if(d==1)
            {
                ssort('s');
                //get structure
            }
            break;


        case 5:
            printf("Stationery");
            //print link list of good in file
            int n;
            scanf("%d",&n);
            printf("if you want to see the sort inter num 1\n");
            if(n==1)
            {
                ssort('s');
                //get structure
            }
            break;


        case 6:
            printf("Digital goods");
            //print link list of good in file
            int k;
            scanf("%d",&k);
            printf("if you want to see the sort inter num 1\n");
            if(k==1)
            {
                // ssort();
                //get structure
            }
            break ;



        case 7:

//open file text comment and save comment

            puts("please inter the number of item you want to add comment");
            int g1;
            scanf("%d",&g1);

            break;

        case 8:
            if(c!="guest")
            {
                basket();
            }
            break;



        case -1:
            return main();
            break;

        }
    }
    while(1);
}



void ssort(char c)
{
    if(c=='s')
    {


        //strucure
        printf("what kind of sort do you want 1-on price num 1\n 2-on score num 2");
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
    else if(c=='c')
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



void newgood(void)
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
            scanf("%s",goods.explanation);
            printf("please inter number of good(inventory)");
            scanf("%d",goods.num);
            printf("please inter tupe of good");
            scanf("%s",goods.type);
            int x=fwrite(&goods,sizeof(struct goodprofile),1,ptr);
            fclose(ptr);
        }



        if(a==2)
        {
            //ssort();//send file or name file to it and use the link list
        }


        if(a==3)
        {
            seller();
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







