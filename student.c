
#include<stdio.h>
#include<stdlib.h>
#define p printf
#define s scanf 
struct node
{
   char usn[30],name[30],branch[10];
   long int ph;
   int sem;
   struct node *add;
};
typedef struct node *NODE;
NODE start=NULL,temp;

NODE getnode()
{
   NODE x;
   x = (NODE) malloc(sizeof(struct node));
   x->add = NULL;
   return x; 
}

void read()
{
temp = getnode();
p("\nusn:");
s("%s",temp->usn);
p("name:");
s("%s",temp->name);
p("branch:");
s("%s",temp->branch);
p("phone Number:");
s("%ld",&temp->ph);
p("semester:");
s("%d",&temp->sem);
}

void create_sll()
{
   int n;
   p("Enter the number of students:");
   s("%d",&n);
   for(int i=1;i<n;i++) 
   {
     p("\nEnter the details of %d student",i);
     read();
     if(start==NULL)
     start = temp;
     else
     { 
       temp->add=start;
       start=temp;
     void  front_insert();
      }
 }
}

void display_count()
{
   int count = 1;
   temp =start;
   p("\ndetails of student:");
   if(start==NULL)
   p("\n//----------EMPTY-----------------------------------------------------------------------empty");
   else
   {
      printf("\nusn\tname\tbranch\tph-number\tsemester:\n");
      while(temp->add != NULL)
      {
         count++;
         p("%s\t%s\t%s\t%ld\t%d\n",temp->usn,temp->name,temp->branch,temp->ph,temp->sem);
         temp=temp->add;
      }
           p("%s\t%s\t%s\t%ld\t%d",temp->usn,temp->name,temp->branch,temp->ph,temp->sem);
           p("\nstudent count is %d \n",count);
   }
   return;
}

void front_insert()
{
   p("\ntudent details:\n");
   read();
   if(start==NULL)
   start = temp;
   else
   { 
       temp->add=start;
       start=temp;
  }
}

    NODE end_insert()
    {
      
      NODE last = start;
      p("\nDetails:\n");
      read();
     if(start==NULL)
     start = temp;
     else
     { 
       while(last->add!=NULL)
       {
         last = last->add;
         last->add = temp;
         }
     }
       return start;
    }
    

    void front_delete()
    {
   p("details of student:");
   if(start==NULL)
   p("empty");
   else
   {
      p("\ndeleted elements %s are:",temp->usn);
      start = start->add;
      free(temp);
   }
   return ;
    }



void main()
{
   int choice;
      while(1)
      {
      p("\n-----menu--------------------");
      p("\n1.create_sll()\n2.display_count()\n3.front_insert()\n4.end_insert()\n5.front_delete()\n6.exit()\n");
      p("Enter choice:");
      s("%d",&choice);
      switch(choice)
      {
         case 1:create_sll();break;
         case 2:display_count();break;
         case 3:front_insert();break;
         case 4:end_insert();break;
         case 5:front_delete();break;
         case 6:return;break;
         default:p("invalid choice");
      }
      }
}