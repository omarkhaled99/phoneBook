void sort()
{

    int pass,j;
    contact temp;
    for(pass=0; pass<lines-1; pass++)
    {
        for(j=0; j<lines-pass-1; j++)
        {
            if(strcasecmp(Contacts_array[j].lname,Contacts_array[j+1].lname)>0)
            {
                swap(&Contacts_array[j],&Contacts_array[j+1]);
            }
            else if(strcasecmp(Contacts_array[j].lname,Contacts_array[j+1].lname)==0)
            {
                if(strcasecmp(Contacts_array[j].fname,Contacts_array[j+1].fname)>0)
                {
                    swap(&Contacts_array[j],&Contacts_array[j+1]);
                }
                else if(strcasecmp(Contacts_array[j].fname,Contacts_array[j+1].fname)==0)
                {
                    if(strcasecmp(Contacts_array[j].Nphone,Contacts_array[j+1].Nphone)>0)
                    {
                        swap(&Contacts_array[j],&Contacts_array[j+1]);
                    }
                }
            }
        }
    }

}

void mainmenu()
{
    char choice[2];
    int i=0,j=0;
    printf("\n\t\t\t\t\t   ~~~~~~THE PHONEBOOK~~~~~~\n");
    printf("1)QUERY\n2)ADD\n3)DELETE\n4)MODIFY\n5)DISPLAY YOUR PHONEBOOK\n6)SAVE\n7)QUIT\n\n");
   do{
        printf("Enter your choice between 1-7\n");
    scanf("\n%[^\n]",choice);
    }while(!(choice[0]>='1'&&choice[0]<='7'&&strlen(choice)==1));
    switch(choice[0])
    {
    case '1':
    printf("would you like to display the contacts sorted by Date Of Birth or normally sorted \n choose 1 for DOB or 2 for normal sorting \n ");
        do{printf("Enter your choice\n");
        scanf("%d",&i);
        fflush(stdin);
        }while(i<1||i>2);
        if(i==1)
        DOB_Sort();
        if(i==2)
        sort();
        printf("Would you like to search by lastname or by using multisearch\nif by lastname choose 1\nif by multisearch choose 2\n");
        do{printf("Enter your choice\n");
        scanf("%d",&j);
        fflush(stdin);
        }while(j<1||j>2);
        if(j==1)
        {printf("Enter The lastname to search for\n");
         search();printc(2);
         }
         if(j==2)
         {
             query();

         }
          break;
    case '2':ADD(); break;
    case '3':Delete(); break;
    case '4':modify(); break;
    case '5':

        printf("would you like to display the contacts sorted by Date Of Birth or normally sorted \n choose 1 for DOB or 2 for normal sorting \n");
        do{printf("Enter your choice\n");
        scanf("%d",&i);
        fflush(stdin);
        }while(i<1||i>2);
        if(i==1)
            DOB_Sort();
        if(i==2)
        sort();
        printc(1); break;
    case '6':save(); break;
    case '7':Exit(); break;
    }
    mainmenu();

}

void swap(contact* a,contact* b)
{
    contact temp = *a;
    *a=*b;
    *b=temp;
}

int validation(int p,char toValid[MAX_SIZE])
{int i,flag;
     if(p==1)
    {
        for(i=0;i<strlen(toValid);i++)
            {
                if(isdigit(toValid[i])==0)
                    {
                        printf("invalid input\n");
                        return 0;
                    }
            }
            return 1;
    }

    if(p==2)
    {
        for(i=0;i<strlen(toValid);i++)
            {
                if(isalpha(toValid[i])==0)
                    {
                        printf("invalid input\n");
                        return 0;
                    }
            }
       return 1;
    }

}
int Date_Validation(int day,int month,int year)
{
    int flag=1;
    int leap;
 if(year>=1900&&year<=2019)
 {
     if(year%4 == 0)
    {
        if( year%100 == 0)
        {
            if ( year%400 == 0)
                leap=1;
            else
                leap=0;
        }
        else
            leap=1;
    }
    else
       leap=0;
       if(month>=1&&month<=12){
        {
            if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)
            {
                if(day>=1&&day<=31)
                    flag=0;
            }else if(month==4||month==6||month==9||month==11)
            {
                if(day>=1&&day<=30)
                    flag=0;
                else
                    flag =1;
            }else if(month==2)
                 {
                     if((leap==1&&day>=1&&day<=29)||(leap==0&&day>=1&&day<=28))
                        flag=0;
                 }
        }
 }
 }
 if(flag==1)
    {
    printf("invalid input!!\n");
    return 0;
    }else
    return 1;
}

void DOB_Sort(){
int  pass,j;
for (pass=0;pass<lines-1;pass++)
     {
        for(j=0; j<lines-pass-1; j++)
        {
            if(Contacts_array[j].date.year>Contacts_array[j+1].date.year)
            {
                swap(&Contacts_array[j],&Contacts_array[j+1]);
            }
            else if(Contacts_array[j].date.year==Contacts_array[j+1].date.year)
            {
                if(Contacts_array[j].date.month>Contacts_array[j+1].date.month)
                {
                    swap(&Contacts_array[j],&Contacts_array[j+1]);
                }
                else if(Contacts_array[j].date.month==Contacts_array[j+1].date.month)
                {
                    if(Contacts_array[j].date.day>Contacts_array[j+1].date.day)
                    {
                        swap(&Contacts_array[j],&Contacts_array[j+1]);
                    }
                }
            }
        }
    }
}

int Mail_Validation(char mail[MAX_SIZE])
{
    int i;
    int countat,flag=0;
    int index= -1;
    int j,k=0;
    countat=0;
    if(mail[0]=='@'||mail[0]=='.')
       {
         return 0;
       }
    for(i=0;i<strlen(mail);i++)
    {

        if(mail[i]=='.')
        {   k++;
            if(mail[i+1]=='.')
                {
                  return 0;
                }
        }
        if(mail[i]=='@')
          {
            countat++;
            index=i;
          }
    }
    for (j = index+1 ; j < index+4 ; j++ ){
        if (mail[j] == '.'){
            return 0 ;
        }
    }

    if(countat!=1||k==0)
        {
          return 0;
        }



    return 1;
}

void getKeyContact ()
{   fflush(stdin);
    printf("Enter the first name: ");
    gets(keyContact.fname);

    printf("Enter the last name: ");
    gets(keyContact.lname);

    printf("Enter the address: ");
    gets(keyContact.address);

    printf("Enter the E-mail Address: ");
    gets(keyContact.mail);

    printf("Enter the phone number: ");
    gets(keyContact.Nphone);

    printf("\n");
}

int contactCmp(contact* x)
{

    if (strcmp(keyContact.fname,"")!=0)
    {
        if (strcasecmp(keyContact.fname,x->fname)!=0)
        {
          return 0;
        }
    }


    if (strcmp(keyContact.lname,"")!=0)
    {
        if (strcasecmp(keyContact.lname,x->lname)!=0)
        {
           return 0;
        }
    }



    if (strcmp(keyContact.address,"")!=0)
    {
        if (strcasecmp(keyContact.address,x->address)!=0)
        {
            return 0;
        }
    }


    if (strcmp(keyContact.mail,"")!=0)
    {
        if (strcasecmp(keyContact.mail,x->mail)!=0)
        {
            return 0;
        }
    }


    if (strcmp(keyContact.Nphone,"")!=0)
    {
        if (strcasecmp(keyContact.Nphone,x->Nphone)!=0)
        {
           return 0;
        }
    }




    return 1;

}

void fillSearchResults ()
{

    int i ;
    searchResultsSize = 0 ;

    for (i = 0 ; i<lines ; i++)
    {
        contact* x = &Contacts_array[i];

        if (contactCmp(x)==1)
        {
            multisearchResults[searchResultsSize] = x;
            searchResultsSize++;
        }

    }
}

void query ()
{
    getKeyContact();
    fillSearchResults();
    printc(3);
}
