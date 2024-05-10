#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


char temp1[20][50]={"Vijay","Rajnikanth","Ajith","Kamal Hassan","Suriya","Dhanush","Vikram","Karthi","Vijay Sethupathi","Shivakarthikeyan"};
char temp2[20][50]={"Anushka Shetty","Samantha","Pooja Hegde","Nayanthara","Rahsmika Mandanna","Kajal Agarwal","Trisha","Tamannah Bhatiya","Keerthy Suresh","Shruthi Hassan"};
char temp3[20][50]={"Rajamouli","Shamhal","AR Murugadas","Trivikram Srinivas","KS Ravikumar","Lingusamy","Atlee Kumar","Sukumar","Mani Ratnam","Gantham Menon"};
char temp4[20][10]={"10.0","9.95","9.90","9.85","9.80","9.75","9.70","9.65","9.60","9.55"};
char temp5[5][20]={"Karnan","Don","Doctor","Sultan","Master"};
void create_display()
{
    FILE *file_display=NULL;
    file_display=fopen("display.txt","w");

    if (file_display==NULL)
    {
        printf("error!!!\n");
        exit(1);
    }
    int i;
    for (i=0;i<5;i++){
        fputs(temp5[i],file_display);
            if (i!=4)
                fputs(",",file_display);
    }
    fclose(file_display);
}

void create_file()
{
    FILE *file_heroes=NULL ;
    FILE *file_heroines=NULL;
    FILE *file_directors=NULL;
    FILE *file_scores=NULL;


    file_heroes=fopen("heroes.txt","w+");
    file_heroines=fopen("heroines.txt","w+");
    file_directors=fopen("directors.txt","w+");
    file_scores=fopen("scores.txt","w+");

    if (file_heroes==NULL)
    {
        printf("error!!!\n");
        exit(1);
    }

    if (file_heroines==NULL)
    {
        printf("error!!!\n");
        exit(1);
    }

    if (file_directors==NULL)
    {
        printf("error!!!\n");
        exit(1);
    }

    if (file_scores==NULL)
    {
        printf("error!!!\n");
        exit(1);
    }


    for(int i=0;i<10;i++)
    {
        fputs(temp1[i],file_heroes); //creating file heroes
        fputs(temp2[i],file_heroines);   //creating file heroines
        fputs(temp3[i],file_directors);  //creating file directors
        fputs(temp4[i],file_scores);   //creating file for scores
        if(i!=9)
        {
            fputs(",",file_heroes);
            fputs(",",file_heroines);
            fputs(",",file_directors);
            fputs(",",file_scores);
        }

    }
    fclose(file_heroes);
    fclose(file_heroines);
    fclose(file_directors);
    fclose(file_scores);

}


// main function
void main()
{
    //MODULE 1
    int chi;
    printf("If this is the first time running the program, enter 0. Else, enter 1 :");
    scanf("%d",&chi);
    if (chi==0){
        create_display();
        create_file();
    }
    FILE *fp=NULL;
    char h1[100][50];
    fp=fopen("heroes.txt","r");
    if(fp==NULL)
    {
        printf("error in opening file!!\n");
        exit(1);
    }
    int i=0;
    while(1)
    {
        char read=(char)fgetc(fp);
        int k=0;
        while(read!=',' && !feof(fp))
        {
            h1[i][k++]=read;
            read=(char)fgetc(fp);
        }
        h1[i][k]=0;
        if(feof(fp))
        {
            break;
        }
        i++;

    }
    int l;

    FILE *dr;
    dr = fopen("directors.txt","r");		//filename of your data file
    char h3[100][50];			//max word length 50
    int o=0;
    while(1){
        char y = (char)fgetc(dr);
        int m = 0,n=0;
        while(y!=',' && !feof(dr)){	//read till , or EOF
             h3[o][m++] = y;			//store in array
            y = (char)fgetc(dr);

        }
        h3[o][m]=0;		//make last character of string null
        if(feof(dr)){		//check again for EOF
            break;
        }
        o++;
    }

    FILE* inpu;
    inpu = fopen("heroines.txt","r");		//filename of your data file
    char h2[100][50];			//max word length 50
    int j = 0;
    while(1){
        char s = (char)fgetc(inpu);
        int t = 0,u=0;
        while(s!=',' && !feof(inpu)){	//read till , or EOF
             h2[j][t++] = s;			//store in array
            s = (char)fgetc(inpu);

        }
        h2[j][t]=0;		//make last character of string null
        if(feof(inpu)){		//check again for EOF
            break;
        }
        j++;
    }
    int z=0;

    FILE* sc;
    sc = fopen("scores.txt","r");		//filename of your data file
    char h4[100][50];			//max word length 50
    int a = 0;
    while(1){
        char b = (char)fgetc(sc);
        int c = 0;
        while(b!=',' && !feof(sc)){	//read till , or EOF
             h4[a][c++] = b;			//store in array
            b = (char)fgetc(sc);

        }
        h4[a][c]=0;		//make last character of string null
        if(feof(sc)){		//check again for EOF
            break;
        }
        a++;
    }

    FILE* dp;
    dp = fopen("display.txt","r");		//filename of your data file
    char h5[100][50];			//max word length 50
    int ab = 0;
    while(1){
        char cd = (char)fgetc(dp);
        int d=0;
        while(cd!=',' && !feof(dp)){	//read till , or EOF
             h5[ab][d++] = cd;			//store in array
            cd = (char)fgetc(dp);

        }
        h5[ab][d]=0;		//make last character of string null
        if(feof(dp)){		//check again for EOF
            break;
        }
        ab++;
    }
    fclose(dp);


    char heroes[20][2][50];
    char heroines[20][2][50];
    char directors[20][2][50];
    int e;
    for (e=0;e<10;e++){
        strcpy(heroes[e][0],h1[e]);
        strcpy(heroes[e][1],h4[e]);
        strcpy(heroines[e][0],h2[e]);
        strcpy(heroines[e][1],h4[e]);
        strcpy(directors[e][0],h3[e]);
        strcpy(directors[e][1],h4[e]);
    }
    e=9;
    int x=9,y=9;


    //MODULE 2

    FILE *file_heroes=NULL ;
    FILE *file_heroines=NULL;
    FILE *file_directors=NULL;
    FILE *file_scores=NULL;
    file_heroes=fopen("heroes.txt","a");
    file_heroines=fopen("heroines.txt","a");
    file_directors=fopen("directors.txt","a");
    file_scores=fopen("scores.txt","a");
    int n,k;
    i=0,j=0,k=0;
    float op,op1,op2,op3;

    char movie[25],hero[25],heroine[25],dir[25],dummy[25],w[20],p[100],q[100];
        char movie_list[10][50];
        float movie_rate[10];
        printf("Newly released movies: ");
        scanf("%d",&n);
        float ds[n][2];
        char movienames[n][50];
        for (k=0;k<n;k++){
            ds[k][0]=k+1;
            ds[k][1]=0;
        }

        printf("Already Running movies: 5");
        int temp_ind=0; //temporary index
        for (i=0;i<n;i++)
        {
            op2=0.0,op3=0.0,op=0.0,op1=0.0; //variable for demand score of movie
            if (i==0)
            {gets(dummy);} //This is needed as the first variable in gets() is by default a null value no matter what we can't correct it.
            printf("\nEnter moviename :");
            gets(movie);
            strcpy(movienames[i],movie);
            printf("%s",movie);

            printf("\nEnter hero :");
            gets(hero);

            printf("Enter heroine :");
            gets(heroine);
            printf("Enter director :");
            gets(dir);
            char f[25],g[25],h[25];
            for (j=0;j<=10;j++)
            {
                strcpy(f,heroes[j][0]);
                if (strcmp(f,hero)==0)
                {
                    op1+=atof(heroes[j][1]);
                    break;
                }
                else{
                    if (j==10){
                        op1+=atof(heroes[e][1])-0.05;
                        strcpy(heroes[e+1][0],hero);
                        fputs(",",file_heroes);
                        fputs(hero,file_heroes);
                        fputs(",",file_scores);

                        gcvt(op1,6,w);
                        fputs(w,file_scores);
                        strcpy(heroes[e+1][1],w);
                        e=e+1;
                    }
                }
            }
            for (j=0;j<=10;j++){
                strcpy(g,heroines[j][0]);
                if (strcmp(g,heroine)==0)
                {
                    op2+=atof(heroines[j][1]);
                    break;
                }
                else{
                    if (j==10){
                        op2+=atof(heroines[x][1])-0.05;
                        strcpy(heroines[x+1][0],heroine);
                        fputs(",",file_heroines);
                        fputs(heroine,file_heroines);
                        gcvt(op2,6,p);
                        strcpy(heroines[x+1][1],p);
                        x=x+1;
                    }
                }
            }
            for (j=0;j<=10;j++){
                strcpy(h,directors[j][0]);
                if (strcmp(h,dir)==0)
                {
                    op3+=atof(directors[j][1]);
                    break;
                }
                else{
                    if (j==10){
                        op3+=atof(directors[y][1])-0.05;
                        strcpy(directors[y+1][0],dir);
                        fputs(",",file_directors);
                        fputs(dir,file_directors);
                        gcvt(op3,6,q);
                        strcpy(directors[y+1][1],q);
                        y=y+1;
                    }
                }

            }
            op=op1+op2+op3;
            printf("Demandscore of %s = %f\n",movie,(op/3));
            strcpy(movie_list[temp_ind],movie);
            ds[i][1]=op/3;
            temp_ind++;

        }
        fclose(file_heroes);
        fclose(file_heroines);
        fclose(file_directors);
        fclose(file_scores);

        int t,r=0;
        char v[50];                              //Temporary variable for bubble sort
        for (i=0;i<n;i++){                  //Code for bubble sort.
            for (j=0;j<i;j++){
                if (ds[j][1]<ds[i][1]){
                    t=ds[j][1];
                    ds[j][1]=ds[i][1];
                    ds[i][1]=t;
                    r=ds[j][0];
                    ds[j][0]=ds[i][0];
                    ds[i][0]=r;
                    strcpy(v,movienames[j]);
                    strcpy(movienames[j],movienames[i]);
                    strcpy(movienames[i],v);



                }
            }
        }

    //Module 3

        int seats=0;
        int success;
        int screens;
        int ub;
        int already[5][3]={{0,6,0},{0,4,0},{0,3,0},{0,2,0},{0,1,0}};
        //char al1[5][50]={"Karnan","Master","Doctor","Don","Sulthan"};
        for(seats=0;seats<5;seats++){
            success=0.0;
            printf("\nEnter no of seats unbooked for movie %d - %s :",seats+1,h5[seats]);
            scanf("%d",&ub);
            already[seats][0]=ub;
            screens=(already[seats][1]);
            success=100-(ub*100/(2500*screens));
            printf("Success Rate=%d",success);
            already[seats][2]=success;
        }

        t=0;
        r=0;
        char u[50];
        int s=0;                     // Temporary Variable for bubble sort.
        for (i=0;i<5;i++){          // Code for bubble sort.
            for (j=0;j<i;j++){
                if (already[j][2]<already[i][2]){

                    strcpy(u,h5[j]);
                    strcpy(h5[j],h5[i]);
                    strcpy(h5[i],u);
                    t=already[j][2];
                    already[j][2]=already[i][2];
                    already[i][2]=t;
                    r=already[j][1];
                    already[j][1]=already[i][1];
                    already[i][1]=r;
                    s=already[j][0];
                    already[j][0]=already[i][0];
                    already[i][0]=s;
                }
            }
        }
        for(i=0;i<5;i++)
        {

              printf("\nMovie Name= %s \t Seats=%d\tScreens=%d\tSR=%d\n",h5[i],already[i][0],already[i][1],already[i][2]);

        }
        printf("\n");
        char display[50];
        char final[5][50];
        for (i=0;i<n;i++){
                strcpy(final[i],movienames[i]);
        }
        for (j=0;j<5-n;j++){
            strcpy(final[j+n],h5[j]);
        }
        int dis=1;
        int sce[5]={6,4,3,2,1};
        printf("\nFor weekdays\n");
        for (i=0;i<5;i++){
            strcpy(display,final[i]);
            for(j=1;j<=sce[i];j++)
            {
                printf("screen %d\t%s\t\t9:00am\t2:00pm\t6:00pm\n",dis,display);
                dis++;
            }
        }
        dis=1;
        printf("\nFor weekends\n");
        for (i=0;i<5;i++){
            strcpy(display,final[i]);
            for(j=1;j<=sce[i];j++)
            {
                printf("screen %d\t%s\t\t7:00am\t10:30am\t2:00pm\t5:30pm\t9:00pm\n",dis,display);
                dis++;
            }
        }
        for (i=0;i<5;i++){
            strcpy(temp5[i],final[i]);
        }
        create_display();

}
