void LOAD()
{
    printf("Enter the path for your file\n");
    scanf("%s",path);
    FILE*contr=fopen(path,"r");
    while(contr == NULL)
    {
        printf("Error!\n");
        printf("Enter the path for your file\n");
        scanf("%s",path);
        contr=fopen(path,"r");
    }
    int j=0;
    while(!feof(contr))
    {
        fscanf(contr,"%[^,],%[^,],%d-%d-%d,%[^,],%[^,],%s\n",Contacts_array[j].fname,Contacts_array[j].lname,&Contacts_array[j].date.day,&Contacts_array[j].date.month,&Contacts_array[j].date.year,Contacts_array[j].address,Contacts_array[j].mail,Contacts_array[j].Nphone);
        j++;
        lines++;
    }

    fclose(contr);
    // printf("%d",lines);

}
void search()
{
    char lastname[NSIZE];
    do{
    scanf("%s",lastname);
    }while(!validation(2,lastname));
    int i, m=0;
    counter=0;
    for(i=0; i<lines; i++)
    {
        if(strcasecmp(Contacts_array[i].lname,lastname)==0)
        {
            results[m++]=&Contacts_array[i];
            counter++;

        }
    }
    if(i==lines&&counter==0)
    {
        printf("Name not found!");
    }


}
void ADD()
{
    int i,flag;
    int k=lines;
        printf("Enter the data of the contact \n");
        printf("Enter the last name of contact\n");
        do{scanf("\n%[^\n]",Contacts_array[k].lname);
        }while(!validation(2,Contacts_array[k].lname));
        printf("Enter the first name of contact\n");
        do{scanf("\n%[^\n]",Contacts_array[k].fname);
        }while(!validation(2,Contacts_array[k].fname));
        printf("Enter the address\n");
        scanf("\n%[^\n]",Contacts_array[k].address);
        do{printf("Enter the mail\n");
        scanf("%s",Contacts_array[k].mail);
        }while(!(Mail_Validation(Contacts_array[k].mail)));
        printf("Enter the phone number of the contact\n");
        do{scanf("\n%[^\n]",Contacts_array[k].Nphone);
        }while(!validation(1,Contacts_array[k].Nphone));
        do{printf("Enter date of birth of contact *The day*\n");
        scanf("%d",&Contacts_array[k].date.day);
        fflush(stdin);
        printf("Enter date of birth of contact *The month*\n");
        scanf("%d",&Contacts_array[k].date.month);
        fflush(stdin);
        printf("Enter date of birth of contact *The year*\n");
        scanf("%d",&Contacts_array[k].date.year);
        fflush(stdin);
        }while(!Date_Validation(Contacts_array[k].date.day,Contacts_array[k].date.month,Contacts_array[k].date.year));
        system("cls");

    lines++;
}
void Delete()
{
    char NFirst[20],NSecond[20];
    contact *del[300];
    int j;
    int i,counter=0,x,m=0,choice,index;
    printf("enter the contact you want to delete\n ");
    printf("Enter the first  name\n");
    do{scanf("\n%[^\n]",NFirst);
    }while(!validation(2,NFirst));
    printf("Enter the last  name\n");
    do{scanf("\n%[^\n]",NSecond);
    }while(!validation(2,NSecond));
    for(i=0; i<lines; i++)
    {
        if(strcasecmp(Contacts_array[i].fname,NFirst)==0&&strcasecmp(Contacts_array[i].lname,NSecond)==0)
        {
            del[m++]=&Contacts_array[i];
            counter++;
        }
    }
     if(counter==0)
    {    int mo=0;
         printf("Name not found!\n");
         printf("\nwould you like to enter another contact to delete \nif yes choose 1\nif no choose 2 \n");
        scanf("%d",&mo);
        if(mo==1)
       {
        Delete();
        }
        else if(mo==2)
        {
             mainmenu();
        }
    }
    for(m=0; m<counter; m++)
    {
        printf("\nchoice:%d %s %s %d-%d-%d %s %s %s",m+1,del[m]->fname,del[m]->lname,del[m]->date.day,del[m]->date.month,del[m]->date.year,del[m]->address,del[m]->mail,del[m]->Nphone);
    }
    do{printf("\n enter your choice\n");
    scanf("\n%d",&choice);
    fflush(stdin);
    }while(choice>counter||choice<1);
    index =del[choice-1]-Contacts_array;
    for(j=index; j<lines; j++)
        Contacts_array[j]=Contacts_array[j+1];
    lines--;
   }
void modify()
{
    int i,x,m=0,choice,newDay,newMonth,newYear,newNAddress;
    char answer[2];
    char modif[20],newPhone[20],newFirst[20],newLast[20],newStreet[20],newMail[20];
    printf("enter the last name of the contact to be modified\n");
    search();
    if(counter==0)
    {    int mo;
         printf("\nwould you like to enter another lastname to modify \nif yes choose 1\nif no choose 2 \n");
        scanf("%d",&mo);
        if(mo==1)
       {
        modify();
        }else if(mo==2)
        { mainmenu();
    }}
    else{
    for(m=0; m<counter; m++)
    printf("\nchoice:%d %s %s %d-%d-%d %s %s %s",m+1,results[m]->fname,results[m]->lname,results[m]->date.day,results[m]->date.month,results[m]->date.year,results[m]->address,results[m]->mail,results[m]->Nphone,results[m]->date.day,results[m]->date.month,results[m]->date.year);
    do{printf("\nenter your choice\n");
    scanf("%d",&choice);
      fflush(stdin);
    }while(choice>counter||choice<1);
    printf("\nwhat do you want to modify?");
    printf("\n1)The phone number\n2)Date of birth\n3)First name\n4)Address\n5)Mail\n6)Last name\n");

     do{
        printf("Enter your choice between 1-6\n");
        scanf("\n%[^\n]",answer);
    }while(!(answer[0]>='1'&&answer[0]<='6'&&strlen(answer)==1));
    switch(answer[0])
    {
    case '1':
        printf("insert new number:");
        do{scanf("%s",newPhone);
        }while(!validation(1,newPhone));
        strcpy(results[choice-1]->Nphone,newPhone);

        break;
    case '2':
        do{printf("\ninsert new day:\n");
        scanf("%d",&newDay);
        printf("\ninsert new month:\n");
        scanf("%d",&newMonth);
        printf("\ninsert new year:\n");
        scanf("%d",&newYear);
        }while(!Date_Validation(newDay,newMonth,newYear));
        results[choice-1]->date.day=newDay;
        results[choice-1]->date.month=newMonth;
        results[choice-1]->date.year=newYear;
        break;
    case '3':
        printf("\ninsert new first name:");
        do{scanf("%s",newFirst);
        }while(!validation(2,newFirst));
        strcpy(results[choice-1]->fname,newFirst);
        break;

    case '4':
        printf("\nenter the new address:");
        scanf("\n%[^\n]",newStreet);
        strcpy(results[choice-1]->address,newStreet);
        break;
    case '5':
        do{printf("\nenter the new mail:");
        scanf("%s",newMail);
        }while(!(Mail_Validation(newMail)));
        strcpy(results[choice-1]->mail,newMail);
        break;
    case '6':
        printf("\ninsert the last name:");
         do{scanf("%s",newLast);
        }while(!validation(2,newLast));
        strcpy(results[choice-1]->lname,newLast);
        break;
    }
    printf("Your contact after being modified:");
    printf("\n %s %s %d-%d-%d %s %s %s",results[choice-1]->fname,results[choice-1]->lname,results[choice-1]->date.day,results[choice-1]->date.month,results[choice-1]->date.year,results[choice-1]->address,results[choice-1]->mail,results[choice-1]->Nphone);
    }
}
void printc(int j)
{   int i;
    if(j==1)
    {
    for(i=0; i<lines; i++)
    {
        printf("\n%s %s\n%d-%d-%d\n%s\n%s\n%s\n",Contacts_array[i].fname,Contacts_array[i].lname,Contacts_array[i].date.day,Contacts_array[i].date.month,Contacts_array[i].date.year,Contacts_array[i].address,Contacts_array[i].mail,Contacts_array[i].Nphone);
    }
    }
    if(j==2)
    {
        for(i=0; i<counter; i++)
    {
        printf("\n%s %s\n%d-%d-%d\n%s\n%s\n%s\n",results[i]->fname,results[i]->lname,results[i]->date.day,results[i]->date.month,results[i]->date.year,results[i]->address,results[i]->mail,results[i]->Nphone);
    }
    }
    if(j==3)
    {
        for(i=0;i<searchResultsSize;i++)
            printf("\n%s %s\n%d-%d-%d\n%s\n%s\n%s\n",multisearchResults[i]->fname,multisearchResults[i]->lname,multisearchResults[i]->date.day,multisearchResults[i]->date.month,multisearchResults[i]->date.year,multisearchResults[i]->address,multisearchResults[i]->mail,multisearchResults[i]->Nphone);
    }
    }



void save()
{
    int i;
    FILE*contwrite=fopen(path,"w");
    for(i=0; i<lines; i++)
    fprintf(contwrite,"%s,%s,%d-%d-%d,%s,%s,%s\n",Contacts_array[i].fname,Contacts_array[i].lname,Contacts_array[i].date.day,Contacts_array[i].date.month,Contacts_array[i].date.year,Contacts_array[i].address,Contacts_array[i].mail,Contacts_array[i].Nphone);
    fclose(contwrite);
}

void Exit()
{
    exit(0);
}


