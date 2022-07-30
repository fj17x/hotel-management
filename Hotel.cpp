#include <iostream.h>
#include <fstream.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>

void menu();                                 // MENU
void view();                                 // TO VIEW EXISTING RECORDS
void searchbyid();                           // TO SEARCH RECORD BY ID
void intro();                                // INTRO TO THE PROGRAM
void searchname();                           // TO SEARCH RECORD BY NAME
void c_id();                                 // TO CHANGE RECORD'S ID
void c_name();                               // TO CHANGE RECORD'S NAME
void c_phoneno();                            // TO CHANGE RECORD'S PHONE NO.
void del();                                  // TO DELETE RECORD
void about();                                // ABOUT THE PROGRAM
void add();                                  // TO ADD A NEW RECORD



void main()                                                          // MAIN FUNCTION
{
   intro();
    menu();

}




void box(int a,int b,int c,int d)            //FOR THE BOX
{
    for(int i=a;i<c;i++)
    {    gotoxy(i,b);cprintf("\xcd");            // FOR THE HORIZONTAL LINES
        gotoxy(i,d);cprintf("\xcd");
   }
    for(int j=b;j<d;j++)
    {    gotoxy(a,j);cprintf("\xba");           // FOR THE VERTICAL LINES
        gotoxy(c,j);cprintf("\xba");
   }

    gotoxy(a,b);cprintf("\xc9");
    gotoxy(c,b);cprintf("\xbb");
    gotoxy(a,d);cprintf("\xc8");
    gotoxy(c,d);cprintf("\xbc");
}


class visitor                               // CLASS VISITOR
{
   public:
     char prefix[4];
    char id[5];
    char name[26];
    char nation[16];
   char phoneno[8];
    char days[3];
   char fammembers[2];

   void input();                             // OUTLINE FUNCTION

}e;


void visitor :: input()                      //FUNCTION TO INPUT


{
       clrscr();
       char cj,x[40];
       int j=0;
       box(5,2,110,30);
       gotoxy(8,5);
       cout<<"Enter ID= ";
       int i=0;
       int t=0;
        char ch;
        do
        {
            ch=getch();

            if( (ch>='0' && ch<='9') && (i<4) )
            {

                 id[i]=ch;
                 i++;
                 cout<<ch;

            }
            else
            if(ch==8 && i>0)
            {
                cout<<"\b"<<" "<<"\b";
                i--;

            }

        }
      while(ch!=13 || i<5-1);
      gotoxy(8,7);
       cout<<"Enter Prefix(Mr/Mrs)=";
        j=0;
        char g;
       do
        {

            g=getch();

            if(((g>='a' && g<='z')||(g>='A' && g<='Z')||(g==' ')) && (j<3))
            {
             prefix[j]=g;
                j++;

                printf("%c",g);
            }

            else

            if(g==8 && j>0)
            {
             cout<<"\b"<<" "<<"\b";
                j--;
            }

        }
      while(g!=13);
        prefix[j]='\0';
       cout<<".";
       gotoxy(8,9);
        j=0;
       cout<<"Enter Name= ";
       do
        {

        cj=getch();

        if(((cj>='a' && cj<='z')||(cj>='A' && cj<='Z')||(cj==' ')) && (j<25))
        {
         name[j]=cj;
            j++;
            printf("%c",cj);
        }

        else

        if(cj==8 && j>0)
        {
         cout<<"\b"<<" "<<"\b";
            j--;
        }

    }while(cj!=13);
    name[j]='\0';
   gotoxy(8,11);
   cout<<"Enter Nationality= ";
   char l;
   j=0;
   do
    {

        l=getch();
        if(((l>='a' && l<='z')||(l>='A' && l<='Z')||(l==' ')) && (j<14))
        {
         nation[j]=l;
            j++;
            printf("%c",l);
        }

        else

        if(l==8 && j>0)
        {
         cout<<"\b"<<" "<<"\b";
            j--;
        }

    }while(l!=13);
    nation[j]='\0';
   gotoxy(8,13);
   cout<<"Enter Phone Number= ";
   char c;
   i=0;
   do
    {
        c=getch();

        if( (c>='0' && c<='9') && (i<7) )
        {
             phoneno[i]=c;
             i++;
             cout<<c;
        }
        else
        if(c==8 && i>0)
        {
            cout<<"\b"<<" "<<"\b";
            i--;

        }

    }while(c!=13 || i<7);
    phoneno[i]='\0';


   gotoxy(8,15);
   cout<<"Enter Days staying= ";
   char xx;
   i=0;

   do
    {
        xx=getch();

        if( (xx>='0' && xx<='9') && (i<3) )
        {

             days[i]=xx;
             i++;
             cout<<xx;

        }
        else

    if(xx==8 && i>0)
   {
       cout<<"\b"<<" "<<"\b";
       i--;

   }

    }
   while(xx!=13 || i<3-1);
   days[i]='\0';

   gotoxy(8,17);
   cout<<"Enter No of Members= ";
   char xxx;

   i=0;
      do
    {
   xxx=getch();

   if( (xxx>='0' && xxx<='9') && (i<1) )
   {

       fammembers[i]=xxx;
       i++;
       cout<<xxx;

   }
   else

    if(xxx==8 && i>0)
   {
       cout<<"\b"<<" "<<"\b";
       i--;

   }

    }   while(xxx!=13 || i<2-1);
   fammembers[i]='\0';
}


void add()
{
    fstream fin("hotell.dat", ios::binary|ios::out|ios::app);
   gotoxy(12,2);
   e.input();
   fin.write((char*)&e,sizeof(e));
   fin.close();
    clrscr();
    menu();
}





void view()
{
    fstream fin("hotell.dat", ios:: binary|ios::in);
    clrscr();
   int count =1;
   while( fin.read((char *)&e, sizeof(e)))
   if(strcmp(e.id," ")!=0)
       {

          clrscr();
              textcolor(14);
          box(5,2,75,15);
          gotoxy(20,2);
          textcolor(7);

          gotoxy(8,5);
          cout<<" ID : "<<e.id;

          gotoxy(8,7);
          cout<<" Name : "<<e.prefix<<"."<<e.name;

          gotoxy(8,9);
          cout<<" Nationality : "<<e.nation;

          gotoxy(8,11);
          cout<<" Phone Number :"<<e.phoneno;

          gotoxy(8,13);
          cout<<" Members : "<<e.fammembers;

          gotoxy(34,16);
          cout<<"NEXT====>";
          gotoxy(38,2);
          cout<<count;
          count++;
          gotoxy(44,16);
          getch();
      }

   fin.close();
   menu();
}


void about ()
{
    clrscr();
    puts("");
    puts("                          db         88888888ba     ,ad8888ba,    88        88  888888888888 ");
    puts("                         d88b        88       8b   d8'      '8b   88        88       88      ");
    puts("                        d8''8b       88       8P  d8'        '8b  88        88       88      ");
    puts("                       d8'  '8b      88aaaaaa8P   88          88  88        88       88      ");
    puts("                      d8YaaaaY8b     88aaaaaaa8b  88          88  88        88       88      ");
    puts("                     d8aaaaaaaa8b    88       8b  Y8          8P  88        88       88      ");
    puts("                    d8'        '8b   88      a8P   Y8a      a8P   Y8a.     .8P       88      ");
    puts("                   d8'          '8b  888888888P      'Y8888Y'       'Y8888Y'         88      ");
    box(16,1,96,10);
   system("color 1F");
   textcolor(RED);
   textbackground(RED);
   gotoxy(6,14);
   puts("                                          # MADE BY- Firas Javid                             ");
   puts("                                                                                             ");
   puts("                                                                                             ");
   puts("                                                                                             ");
   puts("                                                                                             ");
   puts("                                                                                             ");
   puts("     \t  _  _    ___    _____   ___   _        ___    ___     ___    __ __   ___    _  _    ___         ");
   puts("    \t | || |  / _ \\  |_   _| | __| | |      | _ )  / _ \\   / _ \\  | |/ /  |_ _|  | \\| |  / __|    ");
   puts("    \t | __ | | (_) |   | |   | _|  | |__    | _ \\ | (_) | | (_) | | ' <    | |   | .` | | (_ |       ");
   puts("    \t |_||_|  \\___/    |_|   |___| |____|   |___/  \\___/   \\___/  |_|\\_\\  |___|  |_|\\_|  \\___| ");
    system("color 1F");
    box(5,12,108,29);
    getch();
    clrscr();
   menu();

}

void intro()
{

   clrscr();
    puts("");
    system("color 1F");
    puts("                     ______     _____________     ________                 ");
    puts("     ||      ||    ||      ||        ||          ||            ||          ");
    puts("     ||      ||    ||      ||        ||          ||            ||          ");
    puts("     ||      ||    ||      ||        ||          ||            ||          ");
    puts("     ||      ||    ||      ||        ||          ||            ||          ");
    puts("     ||      ||    ||      ||        ||          ||________    ||          ");
    puts("     ||======||    ||      ||        ||          ||            ||          ");
    puts("     ||      ||    ||      ||        ||          ||            ||          ");
    puts("     ||      ||    ||      ||        ||          ||            ||          ");
    puts("     ||      ||    ||      ||        ||          ||            ||          ");
    puts("     ||      ||    ||      ||        ||          ||            ||          ");
    puts("     ||      ||    ||______||        ||          ||________    ||________  ");
    puts("                                                                           ");
    puts("        ______        _______                       ______________                        ");
    puts("      ||      ||    ||           ||\\          ||         ||                              ");
    puts("      ||      ||    ||           || \\         ||         ||                              ");
    puts("      ||      ||    ||           ||  \\        ||         ||                              ");
    puts("      ||______||    ||           ||   \\       ||         ||                              ");
    puts("      ||\\\\          ||           ||    \\      ||         ||                            ");
    puts("      || \\\\         ||_______    ||     \\     ||         ||                            ");
    puts("      ||  \\\\        ||           ||      \\    ||         ||                            ");
    puts("      ||   \\\\       ||           ||       \\   ||         ||                            ");
    puts("      ||    \\\\      ||           ||        \\  ||         ||                            ");
    puts("      ||     \\\\     ||           ||         \\ ||         ||        BY-FIRAS JAVID      ");
    puts("      ||      \\\\    ||_______    ||          \\||         ||                            ");
    textcolor(4);
   textcolor(RED);
   textbackground(RED);
    box(3,1,90,28);
   getch();
   menu();
}



void menu()
{
   int ch;
   clrscr();
   textcolor(2);
   textbackground(1);
   gotoxy(1,1);
   system("color 1F");
   puts("");
     puts("\n\t   #    #   ####   #####  ######  #           #####    ####    ####   #    #  #  #    #   ####   ");
   puts("\t   #    #  #    #    #    #       #           #    #  #    #  #    #  #   #   #  ##   #  #    #  ");
     puts("\t   ######  #    #    #    #####   #           #####   #    #  #    #  ####    #  # #  #  #       ");
      puts("\t   #    #  #    #    #    #       #           #    #  #    #  #    #  #  #    #  #  # #  #  ###  ");
   puts("\t   #    #  #    #    #    #       #           #    #  #    #  #    #  #   #   #  #   ##  #    #  ");
     puts("\t   #    #   ####     #    ######  ######      #####    ####    ####   #    #  #  #    #   ####   ");

   box(9,2,105,9);
   textcolor(7);
   textbackground(7);
   box(24,10,93,23);
   textbackground(1);

   gotoxy(26,12);
   textcolor(4);
   cprintf(" (");
   textcolor(WHITE);
   cprintf("1");
   textcolor(4);
   cprintf(")");
   cout<<" Enter A New Record";

   gotoxy(26,14);
   textcolor(4);
   cprintf(" (");
   textcolor(WHITE);
   cprintf("2");
   textcolor(4);
   cprintf(")");
   cout<<" View All Records";

   gotoxy(26,16);
   textcolor(4);cprintf(" (");
   textcolor(WHITE);cprintf("3");
   textcolor(4);cprintf(")");
   cout<<" About the Program";

   gotoxy(26,18);
   textcolor(4);        cprintf(" (");
   textcolor(WHITE);    cprintf("4");
   textcolor(4);        cprintf(")");
   cout<<" Search By ID";

   gotoxy(26,20);
   textcolor(4);        cprintf(" (");
   textcolor(WHITE);    cprintf("5");
   textcolor(4);        cprintf(")");
   cout<<" Search By Name";

   gotoxy(65,12);
   textcolor(4);        cprintf("(");
   textcolor(WHITE);    cprintf("6");
   textcolor(4);        cprintf(")");
   cout<<" Change ID Number";

   gotoxy(65,14);
   textcolor(4);        cprintf("(");
   textcolor(WHITE);    cprintf("7");
   textcolor(4);        cprintf(")");
   cout<<" Change Name";

   gotoxy(65,16);
   textcolor(4);        cprintf("(");
   textcolor(WHITE);    cprintf("8");
   textcolor(4);        cprintf(")");
   cout<<" Change Phone number";

   gotoxy(65,18);
   textcolor(4);        cprintf("(");
   textcolor(WHITE);    cprintf("9");
   textcolor(4);        cprintf(")");
   cout<<" Delete a Record";

   gotoxy(65,20);
   textcolor(4);        cprintf("(");
   textcolor(WHITE);    cprintf("10");
   textcolor(4);        cprintf(")");
   cout<<" Quit the Program";

   gotoxy(60,22);
   textcolor(6);
   box(18,25,99,27);
   textcolor(7);
   gotoxy(45,26);
   textcolor(WHITE);
   cprintf("Enter Your Choice [1-10]         ");
   box(53,29,59,29);
   gotoxy(56,28);
   cin>>ch;
   gotoxy(56,28);

   switch(ch)
    {

    case 1:
     add();
     break;

    case 2:
    view();
    break;

    case 3:
    about();
    break;

    case 4:
    searchbyid();
    break;

    case 5:
    searchname();
    break;

    case 6:
    c_id();
    break;


    case 7:
    c_name();
    break;

    case 8:
    c_phoneno();
    break;

    case 9:
    del();
    break;
    case 10:
   break;

    default:
    {
        clrscr();
      gotoxy(42,24);
      puts("! PLEASE ENTER A VALID OPTION !");
      gotoxy(57,25);
      system("color 4F");
      getch();
      clrscr();
      menu();
    }    }
}



void searchbyid()
{


   long int p,n,m;
   int flag=0;

    clrscr();
   fstream fin("hotell.dat" , ios::in | ios::binary);
   fin.seekg(0,ios::end);
   p=fin.tellg();
   n=p/sizeof(e);
   p=sizeof(e);
    gotoxy(20,13);
    cprintf("Please enter desired ID :  ");
   char cv;
   char did[5];
   int i=0;
    do
    {
        cv=getch();
        if( (cv>='0' && cv<='9') && (i<4) )
        {
             did[i]=cv;
             i++;
             cout<<cv;
        }
        else
        if(cv==8 && i>0)
        {
            cout<<"\b"<<" "<<"\b";
            i--;
        }
    }
   while(cv!=13 || i<5-1);
   did[i]='\0';
   system("color 1F");
   for (int i = 1; i<=n;i++)
   {
    m=p*i;
    fin.seekg (-m, ios::end);
    fin.read((char *) &e, sizeof(e));
    if(strcmpi(did,e.id)==0)
      {
          clrscr();
          box(5,2,75,15);
          gotoxy(20,2);
          gotoxy(8,5);
              cout<<" ID : "<<e.id;
          gotoxy(8,7);
          cout<<" Name : "<<e.prefix<<"."<<e.name;
         gotoxy(8,9);
          cout<<" Nationality : "<<e.nation;
          gotoxy(8,11);
          cout<<" Phone Number :"<<e.phoneno<<"\b\b";
          gotoxy(8,13);
          cout<<" Family Members : "<<e.fammembers;
          gotoxy(8,15);
          flag=1;
          getch();
      }                            }
    if (flag==0)
    {
        gotoxy(45,13);
        cprintf(" NO RECORD FOUND ! ");
        getch();
    }
fin.close();
clrscr();
menu();
}


void searchname()
{
   fstream fin ("hotell.dat" , ios::in | ios::binary);
   long p,n,m;
   int flag=0;
    clrscr();
   fin.seekg(0,ios::end);
   p=fin.tellg();
   n=p/sizeof(e);
   p=sizeof(e);

    gotoxy(20,13);
   cprintf("Please enter the name : ");
   char dname[26];
   char ax;
   int j=0;
    do
    {
        ax=getch();
        if(((ax>='a' && ax<='z')||(ax>='A' && ax<='Z')||(ax==' ')) && (j<25))
        {
         dname[j]=ax;
            j++;
            printf("%c",ax);
        }
        else
        if(ax==8 && j>0)
        {
         cout<<"\b"<<" "<<"\b";
            j--;
        }

    }while(ax!=13);
    dname[j]='\0';



   for (int i = 1; i<=n;i++)
   {
       m=p*i;
       fin.seekg (-m, ios::end);
       fin.read((char *) &e, sizeof(e));
      if(strcmp(dname,e.name)==0)
            {


             clrscr();
             box(5,2,75,15);
             gotoxy(20,2);
             gotoxy(8,5);
             cout<<" ID : "<<e.id;
             gotoxy(8,7);
             cout<<" Name : "<<e.prefix<<"."<<e.name;
             gotoxy(8,9);
             cout<<" Nationality : "<<e.nation;
             gotoxy(8,11);
             cout<<" Phone Number :"<<e.phoneno;
             gotoxy(8,13);
             cout<<" Family Members : "<<e.fammembers;
             gotoxy(8,15);
             flag=1;
             getch();
      }
    }

    if (flag==0)
         {
             clrscr();
             gotoxy(45,13);
          cprintf(" NO RECORD FOUND ! ");
             getch();
        }
    fin.close();
    clrscr();
    menu();

}



void c_id()
{
   fstream fin ("hotell.dat", ios::in | ios::out | ios:: binary);
    int p,c=1,flag=0;
    clrscr();
    gotoxy(20,13);
    cprintf("Please enter the Member ID :  ");
   char cv;
   int i=0;
   char didd[5];
        do
    {
        cv=getch();

        if( (cv>='0' && cv<='9') && (i<4) )
        {
             didd[i]=cv;
             i++;
             cout<<cv;
        }
        else
            if(cv==8 && i>0)
        {
            cout<<"\b"<<" "<<"\b";
            i--;
        }
    }
   while(cv!=13 || i<5-1);
     didd[i]='\0';


   fin.seekg(0);
   while ( fin.read ((char*) &e, sizeof(e)))
   if (strcmp(didd,e.id)==0)
   {
       flag = 1;
       break;
   }
   else c++;

   if (flag == 1)
   {

    p= (c-1) * sizeof(e);
   fin.seekg (p, ios::beg);
   fin.read((char *) &e, sizeof (e));

   clrscr();
   system("color 1F");
   box(5,2,75,15);
   gotoxy(28,2);

   gotoxy(8,5);
   cout<<" ID : "<<e.id;

   gotoxy(8,7);
   cout<<" Name : "<<e.prefix<<"."<<e.name;

   gotoxy(8,10);
   cout<<" Enter New Room Number : ";
   char cbb;
   char nid[5];
   int i=0;
          {
          do
          {
        cbb=getch();
        if( (cbb>='0' && cbb<='9') && (i<4) )
        {
             nid[i]=cbb;
             i++;
             cout<<cbb;
        }
        else
      if(cbb==8 && i>0)
        {
            cout<<"\b"<<" "<<"\b";
            i--;
        }
    }
    while(cbb!=13 || i<4);
       nid[i]='\0';
       strcpy(e.id,nid);
       fin.seekg (-sizeof(e), ios::cur);
       fin.write((char *) &e, sizeof (e));
       }
       gotoxy(28,24);
       cprintf(" RECORD UPDATED");
       getch();
       clrscr();
       }
     else
     {
            clrscr();
            gotoxy(28,13);
            cprintf(" RECORD DOESNT EXIST ");
            getch();
            clrscr();
     }

fin.close();
clrscr();
menu();
}


void c_name()
{
   fstream fin ("hotell.dat", ios::in | ios::out | ios:: binary);
    clrscr();
   int p,c=1,flag=0;
    gotoxy(20,13);
    cprintf("Please enter the Member ID :  ");
   char cv;
   int i=0;
   char diddl[5];
        do
    {
        cv=getch();
        if( (cv>='0' && cv<='9') && (i<4) )
        {
             diddl[i]=cv;
             i++;
             cout<<cv;
        }
        else
            if(cv==8 && i>0)
        {
            cout<<"\b"<<" "<<"\b";
            i--;
        }
    }
   while(cv!=13 || i<5-1);
   diddl[i]='\0';
   fin.seekg(0);
   while ( fin.read ((char*) &e, sizeof(e)))
   if (strcmp(diddl,e.id)==0)
   {
       flag = 1;
       break;
   }
   else c++;
   if (flag == 1)
   {
       p=(c-1) * sizeof(e);
       fin.seekg (p, ios::beg);
       fin.read((char *) &e, sizeof (e));

       clrscr();
       system("color 1F");
       box(5,2,75,15);
       gotoxy(28,2);

       gotoxy(8,5);
       cout<<" ID : "<<e.id;

       gotoxy(8,7);
       cout<<" Name : "<<e.prefix<<"."<<e.name;

       gotoxy(8,10);
       char jj;
       int j=0;
       char dname[26];
       cout<<"Enter the New Name : ";
       do
       {
        jj=getch();
        if(((jj>='a' && jj<='z')||(jj>='A' && jj<='Z')||(jj==' ')) && (j<25))
            {
             dname[j]=jj;
                j++;
                printf("%c",jj);
            }
            else
            if(jj==8 && j>0)
            {
             cout<<"\b"<<" "<<"\b";
                j--;
            }
            }
         while(jj!=13);

         dname[j]='\0';
         strcpy(e.name,dname);
         fin.seekg (p, ios::beg);
         fin.write((char *) &e, sizeof (e));
         gotoxy(28,24);
         cprintf("RECORD UPDATED ");
         getch();
     }
     else
     {
             clrscr();
          gotoxy(28,13);
          cprintf(" RECORD DOESNT EXIST ");
         getch();
     }

fin.close();
clrscr();
menu();
}


void c_phoneno()
{
   fstream fin ("hotell.dat", ios::in | ios::out | ios:: binary);
    int pp,cc=1,flagg=0;
    clrscr();
    gotoxy(20,13);
    cprintf("Please enter the ID:  ");
   char cv;
   int i=0;
   char ddidd[5];
        do
    {
        cv=getch();
        if( (cv>='0' && cv<='9') && (i<4) )
        {
             ddidd[i]=cv;
             i++;
             cout<<cv;
        }
        else
            if(cv==8 && i>0)
        {
            cout<<"\b"<<" "<<"\b";
            i--;
        }

    }
   while(cv!=13 || i<4);
     ddidd[i]='\0';
   fin.seekg(0);
   while ( fin.read ((char*) &e, sizeof(e)))
   if (strcmp(ddidd,e.id)==0)
   { flagg = 1;
   break;
   }
   else cc++;
   if (flagg == 1)
   {
        pp= (cc-1) * sizeof(e);
       fin.seekg (pp, ios::beg);
       fin.read((char *) &e, sizeof (e));

      clrscr();
      system("color 1F");
      box(5,2,75,15);
      gotoxy(28,2);
      gotoxy(8,5);
      cout<<" Phone no: "<<e.phoneno;

      gotoxy(8,7);
      cout<<" Name : "<<e.prefix<<"."<<e.name;

      gotoxy(8,10);
      cout<<" Enter New Phone no : ";
      char cbb;
      char nid[8];
      int i=0;
      {
      do
          {
        cbb=getch();
        if( (cbb>='0' && cbb<='9') && (i<8) )
        {
             nid[i]=cbb;
             i++;
             cout<<cbb;
        }
        else
            if(cbb==8 && i>0)
        {
            cout<<"\b"<<" "<<"\b";
            i--;
        }
    }
   while(cbb!=13 || i<8);
   nid[i]='\0';
   strcpy(e.phoneno,nid);
   fin.seekg (-sizeof(e), ios::cur);
   fin.write((char *) &e, sizeof (e));
   }

   gotoxy(28,24);
   cprintf(" RECORD UPDATED");
   getch();
   clrscr();
   }
   else
   {
   clrscr();

   gotoxy(28,13);
   cprintf(" RECORD DOESNT EXIST ");
   getch();
   clrscr();
   }

fin.close();
clrscr();
menu();
}


void del()
{

   fstream fin ("hotell.dat", ios::in | ios::out | ios:: binary);
   fstream del ("temp.dat", ios::in | ios::out | ios:: binary);
    int ch,p,c=1,flag=0;
    clrscr();
   char cv;
    gotoxy(20,13);
    cprintf("Please enter the Member ID :  ");
   char didd[5];
   int i=0;
   do
    {
        cv=getch();
        if( (cv>='0' && cv<='9') && (i<4) )
        {
             didd[i]=cv;
             i++;
             cout<<cv;
        }
        else
      if(cv==8 && i>0)
        {
            cout<<"\b"<<" "<<"\b";
            i--;
        }    }
   while(cv!=13 || i<5-1);
   didd[i]='\0';
   fin.seekg(0);
   while ( fin.read ((char*) &e, sizeof(e)))
   if (strcmp(didd,e.id)==0)
   {
       flag = 1;
      break;  }
       else
   {
       del.write ((char*) &e, sizeof(e));
       c++;
   }
   if (flag == 1)
   {
       p=(c-1) * sizeof(e);
       fin.seekg (p, ios::beg);
      fin.read((char *) &e, sizeof (e));
      system("color 1F");
      clrscr();
      textcolor(14);
      box(5,2,75,15);
      gotoxy(20,2);
      textcolor(7);

      gotoxy(8,5);
      cout<<" ID : "<<e.id;

      gotoxy(8,7);
      cout<<" Name : "<<e.prefix<<"."<<e.name;

      gotoxy(8,9);
      cout<<" Nationality : "<<e.nation;

      gotoxy(8,11);
      cout<<" Phone Number :"<<e.phoneno;

      gotoxy(8,13);
      cout<<" Family Members : "<<e.fammembers;

      gotoxy(20,24);
      cprintf("Do you want to Delete this Record? ");
      cout<<"Y";    cprintf("/");    cout<<"N";    cprintf(":");
      textcolor(7);

      ch=getch();
      if (ch=='Y' || ch=='y')
      {
          while ( fin.read ((char*) &e, sizeof(e)))
          del.write ((char*) &e, sizeof(e));
          clrscr();
          gotoxy(28,24);
          cprintf(" RECORD ERASED ");
         getch();
      }
      else
      {
          del.write ((char*) &e, sizeof(e));
          while ( fin.read ((char*) &e, sizeof(e)))
          del.write ((char*) &e, sizeof(e));
      }
   }
     else
     {
            clrscr(); cout<<"\a";

         gotoxy(28,13);
         cprintf(" RECORD DOESNT EXIST");

         getch();
     }
fin.close();
del.close();
remove("hotell.dat");
rename("temp.dat","hotell.dat");
clrscr();
menu();
}