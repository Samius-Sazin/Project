/*
**********PhoneBook Management System**********
            Name : Samius Sazin
            ID: 0242220005101236
            Batch_63
            Department of C.S.E
            Daffodil International University
            
            Starting Date   : 24.05.2023
            Completion Date : 29.05.2023
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
    char name[30];
    char number[20];
    char gmail[40];
    struct node *prev, *next;
};
struct node *HEAD = NULL;


char Add_Contact();

void View_List();
void Sort_Contact();
void swap(struct node *ptr, struct node *temp);

void Search_Contact();
void Edit_Contacts();
char Delete_contact();

int main()
{
    int choice;
    char Name[30], ANSWER;

    printf("\t\t.......... Phone Book ..........\n\n");
    fflush(stdin);
    printf("Enter Your Name : ");
    scanf("%[^\n]s", &Name);

    printf("\n\t\t.......... WELCOME  %s ..........\n\n", Name);
    printf("\t\tLET'S CREATE YOUR PHONEBOOK %s\n\n", Name);

    do
    {
        ANSWER = ' ';
        printf("\n\t\t.......... PHONEBOOK MENUE ..........\n\n");
        printf("\t\t1. Add new contact\n");
        printf("\t\t2. View Contact List\n");
        printf("\t\t3. Search Contact\n");
        printf("\t\t4. Update Details on Existing Contact\n");
        printf("\t\t5. Delete Contact\n");
        printf("\t\t6. Exit\n");
        printf("\t\t...Enter Your Choice : ");
        scanf("%d", &choice);
        printf("\n");

        if(choice == 1)
        {
            ANSWER = Add_Contact();
        }

        else if(choice == 2)
        {
            View_List();
        }

        else if(choice == 3)
        {
            Search_Contact();
        }

        else if(choice == 4)
        {
            Edit_Contacts();
            ANSWER = 'Y';
        }

        else if(choice == 5)
        {
            ANSWER = Delete_contact();
        }

        else if(choice == 6)
        {
            break;
        }

        else
        {
            printf("\t\t          Enter Valid Number");
            printf("\n\t\t\t...Returned to Menu...\n");
            ANSWER = 'Y';
        }

        if(ANSWER!='Y')
        {
            printf("\n\t\t    .....Return to Menu?.....");
            printf("\n\t\tEnter 'Y' for Return, 'N' for Exit : ");
            fflush(stdin);
            scanf("%c", &ANSWER);
        }
    }
    while(ANSWER=='y' || ANSWER=='Y');

    return 0;
}

//Function that add new contact
char Add_Contact()
{
    char ANSWER;
    do
    {
        printf("\n");
        struct node *info = (struct node*)malloc(sizeof(struct node));
        info->prev = NULL;
        info->next = NULL;

        fflush(stdin);
        printf("Enter Name   :: ");
        fgets(info->name, sizeof(info->name), stdin);
        info->name[strcspn(info->name, "\n")] = '\0';//This will remove the last new line from string

        fflush(stdin);
        printf("Enter Number :: ");
        fgets(info->number, sizeof(info->number), stdin);
        info->number[strcspn(info->number, "\n")] = '\0';//This will remove the last new line from string
        while(strlen(info->number) != 11)
        {
            fflush(stdin);
            printf("Enter Valid Number :: ");
            fgets(info->number, sizeof(info->number), stdin);
            info->number[strcspn(info->number, "\n")] = '\0';//This will remove the last new line from string
        }

        fflush(stdin);
        printf("Enter Gmail  :: ");
        fgets(info->gmail, sizeof(info->gmail), stdin);
        info->gmail[strcspn(info->gmail, "\n")] = '\0';//This will remove the last new line from string

        if(HEAD == NULL)
        {
            HEAD = info;
        }

        else
        {
            struct node *ptr = HEAD;

            while(ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = info;
            info->prev = ptr;
        }

        printf("\n\n\t\t..........Add Another Contact?..........\n\n");
        printf("\t\t    Enter 'Y' for YES, 'N' for No : ");
        fflush(stdin);
        scanf("%c", &ANSWER);

    }
    while(ANSWER=='Y' || ANSWER=='y');

    printf("\n\t\t\t   RETURNED TO MENU\n");

    return 'Y';
}

//funtion for print all contacts
void View_List()
{
    if(HEAD == NULL)
    {
        printf("\t\t     Contact List is Empty!!");
        return;
    }

    Sort_Contact(); //calling this function for sort all contacts

    struct node *ptr = HEAD;
    int i=1;

    printf("\n");
    while(ptr != NULL)
    {
        printf("Person %d Information : \n", i);
        printf("\t      Name   ::\t%s\n", ptr->name);
        printf("\t      Number ::\t+88%s\n", ptr->number);
        printf("\t      Gmail  ::\t%s\n",  ptr->gmail);
        i++;
        ptr = ptr -> next;
    }
    printf("\n");
}

//Function to sort contacts in ascending order alphabetically
void Sort_Contact()
{
    struct node *ptr;
    int count;

    do
    {
        ptr = HEAD;
        count = 0;

        while (ptr->next != NULL)
        {
            if (strcmp(ptr->name, ptr->next->name) > 0)
            {
                swap(ptr, ptr->next);
                count = 1;
            }
            ptr = ptr->next;
        }
    }
    while(count);

    return;
}
//Function that swap all data between 2 node
void swap(struct node *ptr, struct node *temp)
{
    char Name[30], Number[20], Gmail[40];

    strcpy(Name, ptr->name);
    strcpy(ptr->name, temp->name);
    strcpy(temp->name, Name);

    strcpy(Number, ptr->number);
    strcpy(ptr->number, temp->number);
    strcpy(temp->number, Number);

    strcpy(Gmail, ptr->gmail);
    strcpy(ptr->gmail, temp->gmail);
    strcpy(temp->gmail, Gmail);
}

//function for search a contact
void Search_Contact()
{
    struct node *ptr = HEAD;
    if(ptr == NULL)
    {
        printf("\n\t\t        Contact List is Empty!\n");
        return;
    }

    char Name[30];
    printf("\t\tEnter Name to search : ");
    fflush(stdin);
    scanf("%[^\n]s", &Name);

    int c=0;

    do
    {
        if(strcmp(ptr->name, Name) == 0)
        {
            if(c)
            {
                printf("\n\t\tAnother Contact Found \n");
            }
            else
            {
                printf("\n\t\tContact Found\n");
            }
            printf("\t\t     Name   ::\t%s\n", ptr->name);
            printf("\t\t     Number ::\t+88%s\n", ptr->number);
            printf("\t\t     Gmail  ::\t%s\n\n",  ptr->gmail);
            c = 1;
        }
        ptr = ptr->next;
    }
    while(ptr != NULL);

    if(c != 1)
    {
        printf("\n\t\tNot Found\n");
    }

    return;
}

//Function to Edit esisting Contact
void Edit_Contacts()
{
    struct node *ptr = HEAD;
    if(ptr == NULL)
    {
        printf("\n\t\t        Contact List is Empty!!\n");
        printf("\t\t           Returned to Menu\n");
        return;
    }

    char Name[30];
    printf("\t\tEnter Contact Name : ");
    fflush(stdin);
    scanf("%[^\n]s", &Name);

    char ch;
    int c=0;

    do
    {
        if(strcmp(ptr->name, Name) == 0)
        {
            if(c==1 || c==2)
            {
                printf("\n\t\tAnother Contact Found \n");
            }
            else
            {
                printf("\n\t\tContact Found\n");
            }
            printf("\t\t     Name   ::\t%s\n", ptr->name);
            printf("\t\t     Number ::\t+88%s\n", ptr->number);
            printf("\t\t     Gmail  ::\t%s\n\n",  ptr->gmail);

            printf("\n\t\t    .....Edit This Contact?.....\n");
            printf("\t\tEnter 'Y' for YES, 'N' for NO : ");
            fflush(stdin);
            scanf("%c", &ch);
            if(ch=='y' || ch=='Y')
            {
                int Choice;
                char CH, new_name[30], new_number[20], new_gmail[40];

                printf("\n\t\t1. Change Name\n\t\t2. Change Number\n\t\t3. Change Gmail");
                printf("\n\t\t...Enter Your Choice : ");
                fflush(stdin);
                scanf("%d", &Choice);
                if(Choice == 1)
                {
                    printf("\n\t\tEnter New Name : ");
                    fflush(stdin);
                    scanf("%[^\n]s", &new_name);
                    printf("\n\t\tAre you Sure?");
                    printf("\n\t\tEnter 'Y' for YES, 'N' for NO : ");
                    fflush(stdin);
                    scanf("%c", &CH);
                    if(CH=='Y' || CH=='y')
                    {
                        strcpy(ptr->name, new_name);
                        printf("\n\t\tEdit Successfull");
                    }
                }

                else if(Choice == 2)
                {
                    printf("\n\t\tEnter New Number : ");
                    fflush(stdin);
                    scanf("%[^\n]s", &new_number);
                    printf("\n\t\tAre you Sure?");
                    printf("\n\t\tEnter 'Y' for YES, 'N' for NO : ");
                    fflush(stdin);
                    scanf("%c", &CH);
                    if(CH=='Y' || CH=='y')
                    {
                        strcpy(ptr->number, new_number);
                        printf("\n\t\tEdit Successfull");
                    }
                }

                else if(Choice == 3)
                {
                    printf("\n\t\tEnter New Gmail : ");
                    fflush(stdin);
                    scanf("%[^\n]s", &new_gmail);
                    printf("\n\t\tAre you Sure?");
                    printf("\n\t\tEnter 'Y' for YES, 'N' for NO : ");
                    fflush(stdin);
                    scanf("%c", &CH);
                    if(CH=='Y' || CH=='y')
                    {
                        strcpy(ptr->gmail, new_gmail);
                        printf("\n\t\tEdit Successfull");
                    }
                }
            }

            else
            {
                c=2;
            }

            c = 1;
        }
        ptr = ptr->next;
    }
    while(ptr != NULL);

    if(c==1 || c==2)
    {
        printf("\n\t\tNo Further Contact Found\n");
        printf("\t\tReturned to Menu\n");
        return;
    }

    if(c==0)
    {
        printf("\n\t\tNot Found\n");
        printf("\t\tReturned to Menu\n");
        return;
    }

    return;
}

//Function for delete a contact
char Delete_contact()
{
    struct node *ptr = HEAD;
    if(ptr == NULL)
    {
        printf("\n\t\t        Contact List is Empty!\n");
        printf("\t\t           Returned to Menu\n");
        return 'Y';
    }

    char Name[30];
    printf("\n\t\tEnter Name to Delete the Contact : ");
    fflush(stdin);
    scanf("%[^\n]s",Name);

    char ch;
    int c=0;

    do
    {
        if(strcmp(ptr->name, Name) == 0)
        {
            if(c==1 || c==2)
            {
                printf("\n\t\t\tAnother Contact Found by This Name.\n");
            }
            else
            {
                printf("\n\t\t\tContact Found.\n");
            }

            printf("\t\t     Name   ::\t%s\n", ptr->name);
            printf("\t\t     Number ::\t+88%s\n", ptr->number);
            printf("\t\t     Gmail  ::\t%s\n",  ptr->gmail);

            printf("\n\t\t    .....Are you sure to Delete?.....\n");
            printf("\t\tEnter 'Y' for YES, 'N' for NO : ");
            fflush(stdin);
            scanf("%c", &ch);
            if(ch=='y' || ch=='Y')
            {
                struct node *temp;
                temp = ptr;

                if(temp == HEAD)
                {
                    ptr = ptr->next;
                    HEAD = HEAD->next;
                    free(temp);
                    temp = NULL;
                }


                else
                {
                    ptr = ptr->next;
                    if(temp->next != NULL)
                    {
                        temp->next->prev = temp->prev;
                    }
                    temp->prev->next = temp->next;
                    free(temp);
                    temp = NULL;
                }

                printf("\n\t\tDeleted Successfully\n");
            }
            else
            {
                c=2;
            }

            c=1;
        }
        if(ptr == NULL) break;

        ptr = ptr->next;
    }
    while(ptr != NULL);

    if(c==1 || c==2)
    {
        printf("\n\t\tNo Further Contact Found\n");
        printf("\t\tReturned to Menu\n");
        return 'Y';
    }

    if(c==0)
    {
        printf("\n\t\tNot Found\n");
        printf("\t\tReturned to Menu\n");
        return 'Y';
    }

}

/* How it works?

Enter Your Name : Samius Sazin

                .......... WELCOME  Samius Sazin ..........

                LET'S CREATE YOUR PHONEBOOK Samius Sazin


                .......... PHONEBOOK MENUE ..........

                1. Add new contact
                2. View Contact List
                3. Search Contact
                4. Update Details on Existing Contact
                5. Delete Contact
                6. Exit
                ...Enter Your Choice : 1


Enter Name   :: Rakibul Islam
Enter Number :: 01799999999
Enter Gmail  :: rakib@gmail.com


                ..........Add Another Contact?..........

                    Enter 'Y' for YES, 'N' for No : Y

Enter Name   :: Azharul Islam
Enter Number :: 01899999999
Enter Gmail  :: islam@gmail.com


                ..........Add Another Contact?..........

                    Enter 'Y' for YES, 'N' for No : Y

Enter Name   :: Muid Hasan
Enter Number :: 01611111111
Enter Gmail  :: muid@gmail.com


                ..........Add Another Contact?..........

                    Enter 'Y' for YES, 'N' for No : N

                           RETURNED TO MENU

                .......... PHONEBOOK MENUE ..........

                1. Add new contact
                2. View Contact List
                3. Search Contact
                4. Update Details on Existing Contact
                5. Delete Contact
                6. Exit
                ...Enter Your Choice : 2


//All printed in ascending order
Person 1 Information :
              Name   :: Azharul Islam
              Number :: +8801899999999
              Gmail  :: islam@gmail.com
Person 2 Information :
              Name   :: Muid Hasan
              Number :: +8801611111111
              Gmail  :: muid@gmail.com
Person 3 Information :
              Name   :: Rakibul Islam
              Number :: +8801799999999
              Gmail  :: rakib@gmail.com


                    .....Return to Menu?.....
                Enter 'Y' for Return, 'N' for Exit : Y

                .......... PHONEBOOK MENUE ..........

                1. Add new contact
                2. View Contact List
                3. Search Contact
                4. Update Details on Existing Contact
                5. Delete Contact
                6. Exit
                ...Enter Your Choice : 1


Enter Name   :: Adib Hosen
Enter Number :: 0192222222
Enter Valid Number :: 01922222222
Enter Gmail  :: adib@gmail.com


                ..........Add Another Contact?..........

                    Enter 'Y' for YES, 'N' for No : Y

Enter Name   :: Mehedi Hasan
Enter Number :: 01511113333
Enter Gmail  :: mehedi@gmail.com


                ..........Add Another Contact?..........

                    Enter 'Y' for YES, 'N' for No : N

                           RETURNED TO MENU

                .......... PHONEBOOK MENUE ..........

                1. Add new contact
                2. View Contact List
                3. Search Contact
                4. Update Details on Existing Contact
                5. Delete Contact
                6. Exit
                ...Enter Your Choice : 2


//All printed in ascending order
Person 1 Information :
              Name   :: Adib Hosen
              Number :: +8801922222222
              Gmail  :: adib@gmail.com
Person 2 Information :
              Name   :: Azharul Islam
              Number :: +8801899999999
              Gmail  :: islam@gmail.com
Person 3 Information :
              Name   :: Mehedi Hasan
              Number :: +8801511113333
              Gmail  :: mehedi@gmail.com
Person 4 Information :
              Name   :: Muid Hasan
              Number :: +8801611111111
              Gmail  :: muid@gmail.com
Person 5 Information :
              Name   :: Rakibul Islam
              Number :: +8801799999999
              Gmail  :: rakib@gmail.com


                    .....Return to Menu?.....
                Enter 'Y' for Return, 'N' for Exit : Y

                .......... PHONEBOOK MENUE ..........

                1. Add new contact
                2. View Contact List
                3. Search Contact
                4. Update Details on Existing Contact
                5. Delete Contact
                6. Exit
                ...Enter Your Choice : 1


Enter Name   :: Maliha Mahmud
Enter Number :: 01466666666
Enter Gmail  :: maha@gmail.com


                ..........Add Another Contact?..........

                    Enter 'Y' for YES, 'N' for No : N

                           RETURNED TO MENU

                .......... PHONEBOOK MENUE ..........

                1. Add new contact
                2. View Contact List
                3. Search Contact
                4. Update Details on Existing Contact
                5. Delete Contact
                6. Exit
                ...Enter Your Choice : 2


//All printed in ascending order
Person 1 Information :
              Name   :: Adib Hosen
              Number :: +8801922222222
              Gmail  :: adib@gmail.com
Person 2 Information :
              Name   :: Azharul Islam
              Number :: +8801899999999
              Gmail  :: islam@gmail.com
Person 3 Information :
              Name   :: Maliha Mahmud
              Number :: +8801466666666
              Gmail  :: maha@gmail.com
Person 4 Information :
              Name   :: Mehedi Hasan
              Number :: +8801511113333
              Gmail  :: mehedi@gmail.com
Person 5 Information :
              Name   :: Muid Hasan
              Number :: +8801611111111
              Gmail  :: muid@gmail.com
Person 6 Information :
              Name   :: Rakibul Islam
              Number :: +8801799999999
              Gmail  :: rakib@gmail.com


                    .....Return to Menu?.....
                Enter 'Y' for Return, 'N' for Exit : Y

                .......... PHONEBOOK MENUE ..........

                1. Add new contact
                2. View Contact List
                3. Search Contact
                4. Update Details on Existing Contact
                5. Delete Contact
                6. Exit
                ...Enter Your Choice : 3

                Enter Name to search : Maliha Mahmud

                Contact Found
                     Name   ::  Maliha Mahmud
                     Number ::  +8801466666666
                     Gmail  ::  maha@gmail.com


                    .....Return to Menu?.....
                Enter 'Y' for Return, 'N' for Exit : Y

                .......... PHONEBOOK MENUE ..........

                1. Add new contact
                2. View Contact List
                3. Search Contact
                4. Update Details on Existing Contact
                5. Delete Contact
                6. Exit
                ...Enter Your Choice : 4

                Enter Contact Name : Maliha Mahmud

                Contact Found
                     Name   ::  Maliha Mahmud
                     Number ::  +8801466666666
                     Gmail  ::  maha@gmail.com


                    .....Edit This Contact?.....
                Enter 'Y' for YES, 'N' for NO : Y

                1. Change Name
                2. Change Number
                3. Change Gmail
                ...Enter Your Choice : 3

                Enter New Gmail : maliha@gmail.com

                Are you Sure?
                Enter 'Y' for YES, 'N' for NO : Y

                Edit Successfull
                No Further Contact Found
                Returned to Menu

                .......... PHONEBOOK MENUE ..........

                1. Add new contact
                2. View Contact List
                3. Search Contact
                4. Update Details on Existing Contact
                5. Delete Contact
                6. Exit
                ...Enter Your Choice : 3

                Enter Name to search : Maliha Mahmud

                Contact Found
                     Name   ::  Maliha Mahmud
                     Number ::  +8801466666666
                     Gmail  ::  maliha@gmail.com


                    .....Return to Menu?.....
                Enter 'Y' for Return, 'N' for Exit : y

                .......... PHONEBOOK MENUE ..........

                1. Add new contact
                2. View Contact List
                3. Search Contact
                4. Update Details on Existing Contact
                5. Delete Contact
                6. Exit
                ...Enter Your Choice : 2


//All printed in ascending order
Person 1 Information :
              Name   :: Adib Hosen
              Number :: +8801922222222
              Gmail  :: adib@gmail.com
Person 2 Information :
              Name   :: Azharul Islam
              Number :: +8801899999999
              Gmail  :: islam@gmail.com
Person 3 Information :
              Name   :: Maliha Mahmud
              Number :: +8801466666666
              Gmail  :: maliha@gmail.com
Person 4 Information :
              Name   :: Mehedi Hasan
              Number :: +8801511113333
              Gmail  :: mehedi@gmail.com
Person 5 Information :
              Name   :: Muid Hasan
              Number :: +8801611111111
              Gmail  :: muid@gmail.com
Person 6 Information :
              Name   :: Rakibul Islam
              Number :: +8801799999999
              Gmail  :: rakib@gmail.com


                    .....Return to Menu?.....
                Enter 'Y' for Return, 'N' for Exit : Y

                .......... PHONEBOOK MENUE ..........

                1. Add new contact
                2. View Contact List
                3. Search Contact
                4. Update Details on Existing Contact
                5. Delete Contact
                6. Exit
                ...Enter Your Choice : 5


                Enter Name to Delete the Contact : Mehedi Hasan

                        Contact Found.
                     Name   ::  Mehedi Hasan
                     Number ::  +8801511113333
                     Gmail  ::  mehedi@gmail.com

                    .....Are you sure to Delete?.....
                Enter 'Y' for YES, 'N' for NO : Y

                Deleted Successfully

                No Further Contact Found
                Returned to Menu

                .......... PHONEBOOK MENUE ..........

                1. Add new contact
                2. View Contact List
                3. Search Contact
                4. Update Details on Existing Contact
                5. Delete Contact
                6. Exit
                ...Enter Your Choice : 1


Enter Name   :: Muid Hasan
Enter Number :: 09811111111
Enter Gmail  :: muid@gmail.com


                ..........Add Another Contact?..........

                    Enter 'Y' for YES, 'N' for No : N

                           RETURNED TO MENU

                .......... PHONEBOOK MENUE ..........

                1. Add new contact
                2. View Contact List
                3. Search Contact
                4. Update Details on Existing Contact
                5. Delete Contact
                6. Exit
                ...Enter Your Choice : 2


//All printed in ascending order
Person 1 Information :
              Name   :: Adib Hosen
              Number :: +8801922222222
              Gmail  :: adib@gmail.com
Person 2 Information :
              Name   :: Azharul Islam
              Number :: +8801899999999
              Gmail  :: islam@gmail.com
Person 3 Information :
              Name   :: Maliha Mahmud
              Number :: +8801466666666
              Gmail  :: maliha@gmail.com
Person 4 Information :
              Name   :: Muid Hasan
              Number :: +8801611111111
              Gmail  :: muid@gmail.com
Person 5 Information :
              Name   :: Muid Hasan
              Number :: +8809811111111
              Gmail  :: muid@gmail.com
Person 6 Information :
              Name   :: Rakibul Islam
              Number :: +8801799999999
              Gmail  :: rakib@gmail.com


                    .....Return to Menu?.....
                Enter 'Y' for Return, 'N' for Exit : Y

                .......... PHONEBOOK MENUE ..........

                1. Add new contact
                2. View Contact List
                3. Search Contact
                4. Update Details on Existing Contact
                5. Delete Contact
                6. Exit
                ...Enter Your Choice : 5


                Enter Name to Delete the Contact : Muid Hasan

                        Contact Found.
                     Name   ::  Muid Hasan
                     Number ::  +8801611111111
                     Gmail  ::  muid@gmail.com

                    .....Are you sure to Delete?.....
                Enter 'Y' for YES, 'N' for NO : N

                        Another Contact Found by This Name.
                     Name   ::  Muid Hasan
                     Number ::  +8809811111111
                     Gmail  ::  muid@gmail.com

                    .....Are you sure to Delete?.....
                Enter 'Y' for YES, 'N' for NO : Y

                Deleted Successfully

                No Further Contact Found
                Returned to Menu

                .......... PHONEBOOK MENUE ..........

                1. Add new contact
                2. View Contact List
                3. Search Contact
                4. Update Details on Existing Contact
                5. Delete Contact
                6. Exit
                ...Enter Your Choice : 2


//All printed in ascending order
Person 1 Information :
              Name   :: Adib Hosen
              Number :: +8801922222222
              Gmail  :: adib@gmail.com
Person 2 Information :
              Name   :: Azharul Islam
              Number :: +8801899999999
              Gmail  :: islam@gmail.com
Person 3 Information :
              Name   :: Maliha Mahmud
              Number :: +8801466666666
              Gmail  :: maliha@gmail.com
Person 4 Information :
              Name   :: Muid Hasan
              Number :: +8801611111111
              Gmail  :: muid@gmail.com
Person 5 Information :
              Name   :: Rakibul Islam
              Number :: +8801799999999
              Gmail  :: rakib@gmail.com


                    .....Return to Menu?.....
                Enter 'Y' for Return, 'N' for Exit : N

*/
