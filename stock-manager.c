#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include<ctype.h>
#include <time.h>
typedef struct{
char name[25];
char company[30];
long id;
float price;
} product;
product pr;


int search_id(long id)
{
   FILE*f ;
   FILE*h ;
   product p;
   f=fopen("stock.csv","r");
     while(!feof(f)){
       fscanf(f,"%s, %s, %li, %f", p.name, p.company,&p.id, &p.price) ;
       fflush(stdin);
       if (p.id==id)
       {
           fclose(f);
           return 1;
       }
       }

   fclose(f);
   return 0 ;
}




void add_product(){
FILE *f;
FILE *h;
long id;
int y,m,d;
char c,k;
do{
    fflush(stdin);
    system("cls");
    printf("************PRODUCT ID: **************\n");
    do{
    fflush(stdin);

    scanf("%li",&pr.id);
    }while((pr.id<=0)||(search_id(pr.id)==1));
    printf("************PRODUCT NAME: **************\n");
    scanf("%s",pr.name);
    printf("************COMPANY NAME: **************\n");
    scanf("%s",pr.company);
    printf("************PRODUCT PRICE: **************\n");
    do{
    scanf("%f",&pr.price);

    }while(pr.price<=0.0);
    printf("please check the data you entered\n");
    printf("if you are sure press ''ENTER'' else press 'ANY OTHER BUTTON'");
    c = getch();
    if(c=='\r'){
        time_t timestamp = time( NULL );
        struct tm * now = localtime( & timestamp );
        y=now->tm_year+1900;
        m=now->tm_mon+1;
        d=now->tm_mday;
        f=fopen("stock.csv","a");
        fprintf(f,"%s, %s, %i, %f\n", pr.name, pr.company,pr.id, pr.price);
        fclose(f);
        h=fopen("historique.txt","a");
        fprintf(h," this product ''' %s, %s, %i, %f ''', was added on %i/%i/%i\n", pr.name, pr.company,pr.id, pr.price,d, m,  y);
        fclose(h);
    }
    printf("\nif you made a mistake or  want to add another product please press 'ENTER'and press another button to return to principal menu");
    k = getch();
    if (k!='\r'){
       goto al;

    }
}	while(k =='\r');

   al:
    menu();
}
void display_stock(){
    FILE *f;
    product p;
    f=fopen("stock.csv","r");
    printf(" product name   | companyname |     id     |     price          \n");
    printf("****************|*************|************|********************\n");
    char line[500];

while (fgets(line, sizeof(line), f)) {
printf("%s", line);
}
fclose(f);
printf("press 'ENTER' to go to menu ");
getch();
menu();
}


void search_display_product()
{
    long id ;
    printf("***************ID*****************\n");
    scanf("%li",&id);
    product p;
    int i=0;
    FILE *f ;
    f=fopen("stock.csv","r");
    while(!feof(f))
    {
        fscanf(f,"%s, %s, %li, %f\n", pr.name, pr.company,&pr.id, &pr.price) ;
        if (id==pr.id)
        {
            i+=1;
            printf("display product\n");
            printf("ID     %li\n",pr.id);
            printf("product name %s\n",pr.name);
            printf("product price %f\n",pr.price);
            printf("company name%s\n",pr.company);
        }
    }
    fclose(f);
    if (i==0) printf ("le produit n'existe pas dans le stock\n");
    printf("press 'ENTER' to go to menu ");
    getch();
    menu();
}
void delete_pr()
{   int y,m,d ;
    long id;

    printf("*******ID ******* ");
    scanf("%li",&id);
    fflush(stdin);
if (search_id(id)==1)
{
    FILE *aux ,*f, *h ;
    f=fopen("stock.csv","r");
    aux=fopen("aux.txt","w");
    h=fopen("historique.txt","a");
    do
       {
       fscanf(f,"%s, %s, %li, %f\n", pr.name, pr.company,&pr.id, &pr.price) ;
       if (id!=pr.id)
       {
        fprintf(aux,"%s, %s, %li, %f\n",pr.name, pr.company,pr.id, pr.price) ;
       }
       else {
        time_t timestamp = time( NULL );
        struct tm * now = localtime( & timestamp );
        y=now->tm_year+1900;
        m=now->tm_mon+1;
        d=now->tm_mday;
        fprintf(h," this product ''' %s, %s, %i, %f ''', was deleted on %i/%i/%i\n", pr.name, pr.company,pr.id, pr.price,d, m,  y);
       }
      }
    while(!feof(f));
    fclose(aux);
    fclose(f);
    fclose(h);
    remove("stock.csv");
    rename("aux.csv","stock.csv");
    printf("valid operation");
    }
else {
    printf("invalid operation \n");
}
    printf("press 'ENTER' to go to menu ");
    getch();
    menu();
}

void display_transactions(){
    FILE *f;
    char line[500];
    f=fopen("Historique.txt","r");
    if(feof(f)){
        printf("empty file \n");
    }
    else {
        while (1){
            fgets(line,500,f);
            printf("%s \n",line);
            if (feof(f)){
                break;
                }

        }
    }

    fclose(f);
    printf("press 'ENTER' to go to menu ");
    getch();
    menu();
}
void menu(){
    int j;
	system("cls");
	main:
	printf("\n======================== STOCK MANAGER ========================");
	printf("                                                                                          ");
	printf("                                                                                          ");
	printf("\n\t\tPress choose a number ");
	printf("\n\t\tPress <1> add a product");
	printf("\n\t\tPress <2> modify product");
	printf("\n\t\tPress <3> delete product");
	printf("\n\t\tPress <4> display a product");
	printf("\n\t\tPress <5> display all the stock ");
	printf("\n\t\tPress <6> display transactions ");
	printf("\n\t\tPress <7> log out ");

	printf("\n\n\t\tEnter your choice[1-7] : ");
	scanf("%i", &j);

	system("cls");

		switch(j)
	{
		case 1:
			add_product();
			break;
		case 2:
			modif();
			break;
		case 3:
            delete_pr();
			break;
		case 4:
            search_display_product();
			break;
		case 5:
			display_stock();
			break;
        case 6:
            display_transactions();
        case 7:
            break;
		default:
		printf("Invalid Choice! System Exit\n");
			getch();
	}
}

void modif(){
    long id;
    int m,y,d;
    FILE *aux ,*f, *h ;
    printf("******ID*******\n");
    scanf("%li",&id);
    fflush(stdin);
    if (search_id(id)==1){
        fflush(stdin);
        f=fopen("stock.csv","r");
        aux=fopen("aux.csv","a");
        h=fopen("historique.txt","a");
        while (1){
            fscanf(f,"%s, %s, %li, %f\n", pr.name, pr.company,&pr.id, &pr.price) ;
            if (feof(f)){break;}
            if (id==pr.id){
                    time_t timestamp = time( NULL );
                    struct tm * now = localtime( & timestamp );
                    y=now->tm_year+1900;
                    m=now->tm_mon+1;
                    d=now->tm_mday;
                fprintf(h," this product ''' %s, %s, %i, %f ''', was added on %i/%i/%i\n", pr.name, pr.company,pr.id, pr.price,d, m,  y);
                pr.id=id;
                printf("\n new product name : ");
                gets(pr.name);
                printf("\n new company name ");
                gets(pr.company);
                printf("\new price: ");
                scanf("%f",&pr.price);
                }
            fprintf(aux,"%s, %s, %i, %f\n", pr.name, pr.company,pr.id, pr.price);
            }
        fclose(f);
        fclose(aux);
        fclose(h);
        remove("stock.csv");
        rename("aux.csv","stock.csv");
        printf("valid operation\n");
        }
        else {
        printf("failed operation\n");
        }

    printf("press 'ENTER' to go to menu ");
    getch();
    menu();
}

int main(){

           printf("    ######  ### ####### #     # #     # ####### #     # ### ######  #######\n");
           printf("    #     #  #  #       ##    # #     # #       ##    #  #  #     # #     # \n");
           printf("    #     #  #  #       # #   # #     # #       # #   #  #  #     # #     # \n");
           printf("    ######   #  #####   #  #  # #     # #####   #  #  #  #  #     # #     # \n");
           printf("    #     #  #  #       #   # #  #   #  #       #   # #  #  #     # #     # \n");
           printf("    #     #  #  #       #    ##   # #   #       #    ##  #  #     # #     # \n");
           printf("    ######  ### ####### #     #    #    ####### #     # ### ######  ####### \n");
           printf("\n   PRESS ENTER PLEASE");
           getchar();
menu();
}
