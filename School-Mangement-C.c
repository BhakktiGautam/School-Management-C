/* ===========================================================
 		SCHOOL MANAGEMENT SYSTEM   
 Language : C
 Description : This program is a simple console based School Management System that allows the user to manage:
 
 1. Student Records
 2. Teacher Records
 3. Class Management
 4. Result Processing

 The system allows adding, removing, updating, searching, and displaying records.

 Author: Bhakkti Gautam
 =========================================================== */
#include<stdio.h>
#include<string.h>
/*----------------------------------------------------------
		 STRUCTURE DEFINITIONS 
----------------------------------------------------------*/
// Structure to store student details
struct Student{
	int rollNo;			// Unique roll number
	char firstname[50];		// Student first name
	char lastname[50];		// Student last name
	int class;			// Class of student
	int age;			// Student age
	int marks[5];			// Marks of 5 subjects
	float attendance;		// Attendance percentage
};
// Structure to store teacher details
struct teacher{
	int teacherId;			// Unique teacher ID
	char firstname[50];		// Teacher first name
	char lastname[50];		// Teacher last name
	char subject[50];		// Subject taught
	int assignedclass;		// Class assigned
	float salary;			// Teacher salary
};
// Structure to store class information
struct classes{
	int classID;			// Unique class ID
	int classteacherID;		// Teacher assigned to class
};
/*----------------------------------------------------------
			 GLOBAL ARRAYS 
----------------------------------------------------------*/

// Arrays to store records
struct Student students[500];
struct teacher teachers[100];
struct classes class[20];

// Counters to track total records
int total_students=0;
int total_teachers=0;
int total_classes=0;


/*-----------------------------------------------------------
			STUDENT FUNCTIONS
 ----------------------------------------------------------*/

// Function to add a new student
void addStudent(){
	if(total_students>=500)
{
    printf("Student database full\n");
    return;
}
	printf("Enter student details:\n");

	printf("Enter the roll no. of student:\n");
	scanf("%d",&students[total_students].rollNo);

	printf("Enter the first name of student:\n");
	scanf("%s",students[total_students].firstname);

	printf("Enter the last name of student:\n");
	scanf("%s",students[total_students].lastname);

	printf("Enter the class of student:\n");
	scanf("%d",&students[total_students].class);

	printf("Enter the age of student:");
	scanf("%d",&students[total_students].age);

	printf("Enter the marks of student:\n");

	// Loop to input marks for 5 subjects
	for(int i=0;i<5;i++)
	{
		 printf("Enter marks of subject %d: ", i+1);
		scanf("%d",&students[total_students].marks[i]);
	}

	printf("Enter the attendance percentage of student:\n");
	scanf("%f",&students[total_students].attendance);

	total_students++;

	printf("Record added successfully\n");
}

// Function to remove student using roll number
void removeStudent(){
	int a,found=0;
	printf("Enter roll no. of student whose record you want to remove:\n");
	scanf("%d",&a);
	for(int j=0;j<total_students;j++)
	{
		if(a==students[j].rollNo)
		{	
			// Shift remaining records left to delete student
			for(int i=j;i<total_students-1;i++)
			{
    				students[i]=students[i+1];
			}
			total_students=total_students-1;
			found=1;
			break;
		}	
	}
	if(found==0)
	{
		printf("Student record not found\n");
	}
	
}
// Function to update student information
void updateStudent(){
	int b,found=0;
	printf("Enter the roll no. of student:\n");
	scanf("%d",&b);
	for(int l=0;l<total_students;l++)
	{
		if(b==students[l].rollNo)
		{
			int  h;
			printf("Enter the detail you want to update:\n1.Roll No.\n2.First Name\n3.Last Name\n4.Class\n5.Age\n6.Marks\n7.Attendance\n");
			scanf("%d",&h);
			if(h==1)
			{
				int rollno;
				printf("Enter the new roll number\n");
				scanf("%d",&rollno);
				students[l].rollNo=rollno;
			}
			else if(h==2)
			{
				char Firstname[50];
				printf("Enter the new first name of student:\n");
				scanf("%s",Firstname);
				strcpy(students[l].firstname,Firstname);
			}
			else if(h==3)
			{
				char Lastname[50];
				printf("Enter the new last name of student:\n");
				scanf("%s",Lastname);
				strcpy(students[l].lastname,Lastname);
			}
			else if(h==4)
			{
				int c;
				printf("Enter the new class of student:\n");
				scanf("%d",&c);
				students[l].class=c;
			}
			else if(h==5)
			{
				int a;
				printf("Enter the new age:\n");
				scanf("%d",&a);
				students[l].age=a;
			}
			else if(h==6)
			{
				int mark[5];
				printf("Enter marks:\n");
				for(int d=0;d<5;d++)
				{
					scanf("%d",&mark[d]);
				}
				for(int w=0;w<5;w++)
				{
					students[l].marks[w]=mark[w];
				}
				
			}
			else if(h==7)
			{
				float attend;
				printf("Enter the new attendance percentage\n");
				scanf("%f",&attend);
				students[l].attendance=attend;
			}
			found=1;
			break;
		}
	}
if(found==0)
{	
	printf("Record not found\n");
}

}
// Function to search student by roll number
void searchStudent(){
			int rollno,found=0;
			printf("Enter the roll no of student whose record to be searched:\n");
			scanf("%d",&rollno);
			for(int o=0;o<total_students;o++)
			{
				if(rollno==students[o].rollNo)
				{
					printf("Record founded\n");
				
					printf("\n------ Student Details ------\n");						printf("ROLL NO.=%d\n",students[o].rollNo);
					printf("FIRST NAME=%s\n",students[o].firstname);
					printf("LAST NAME=%s\n",students[o].lastname);
					printf("CLASS =%d\n",students[o].class);
					printf("AGE=%d\n",students[o].age);
					printf("MARKS: ");
					for (int g=0;g<5;g++)
					{
						
						printf("%d",students[o].marks[g]);
					}
					printf("ATTENDANCE=%.2f\n",students[o].attendance);
					found=1;
					break;
				}
			}
if(found==0)
{
	printf("Record not found");
}

			
}
// Function to display all students
void displayAll(){
		printf("%-10s %-15s %-15s %-10s %-10s %-20s %-10s\n",
"RollNo","FirstName","LastName","Class","Age","Marks","Attendance");
		for(int h=0;h<total_students;h++)
	{			printf("%d\t\t",students[h].rollNo);
		printf("%s\t\t",students[h].firstname);
		printf("%s\t\t",students[h].lastname);
		printf("%d\t\t",students[h].class);
		printf("%d\t\t",students[h].age);
		for(int s=0;s<5;s++)
		{
			printf("%d  ",students[h].marks[s]);
		}
		printf("%f",students[h].attendance);
	}
}	
void studentmanagement(){
	int k;
	do{
	printf("1.Add Student\n2.Remove Student\n3.Update Student\n4.Search Student\n5.Display All\n6.Back\n");
	printf("Enter your choice:");
	scanf("%d",&k);
	if(k==1)
	{
		addStudent();
	}
	else if(k==2)
	{
		removeStudent();
	}
	else if(k==3)
	{		
		updateStudent();
	}
	else if(k==4)
	{
		searchStudent();
	}
	else if(k==5)
	{
		displayAll();
	}
	else if(k==6)
	{
		printf("Back from student management\n");
	}
	else
	{
		printf("Invalid choice");
	}
	}while(k!=6);
}
/*---------------------------------------------------------- 
		TEACHER FUNCTIONS
 ----------------------------------------------------------*/
		
// Function to add a teacher
	void addteacher()
{
	if(total_teachers>=100)
{
    printf("Teacher database full\n");
    return;
}
	printf("Enter teacher details:\n");
	printf("Enter teacher ID\n");
	scanf("%d",&teachers[total_teachers].teacherId);
	printf("Enter the first name of teacher:\n");
	scanf("%s",teachers[total_teachers].firstname);
	printf("Enter the last name of teacher:\n");
	scanf("%s",teachers[total_teachers].lastname);
	printf("Enter the subject assigned to teacher:\n");
	scanf("%s",teachers[total_teachers].subject);
	printf("Enter the assigned class to teacher:\n");
	scanf("%d",&teachers[total_teachers].assignedclass);
	printf("Enter the salary of that teacher:\n");
	scanf("%f",&teachers[total_teachers].salary);
	total_teachers++;
	printf("Record added successfully\n");
}

//Function to remove teacher using teacher ID
void removeteacher()
{
	int teacherID,found=0;
	printf("Enter the teacher ID you want to remove:\n");
	scanf("%d",&teacherID);
	for(int g=0;g<total_teachers;g++)
	{
		if(teacherID==teachers[g].teacherId)
		{
			for(int i=g;i<total_teachers-1;i++)
			{
  			  teachers[i]=teachers[i+1];
			}
			total_teachers--;
			found=1;
			break;
		}
	}
if(found==0)
{
	printf("Record not found\n");
}
}

//Function to update teacher information
void updateteacher()
{
	int g,found=0;
	printf("Enter the teacher ID:\n");
	scanf("%d",&g);
	for(int l=0;l<total_teachers;l++)
	{
		if(g==teachers[l].teacherId)
		{
			int  h;
			printf("Enter the detail you want to update:\n1.Teacher ID.\n2.First Name\n3.Last Name\n4.Subject\n5.Assigned Class\n6.Salary\n");
			scanf("%d",&h);
			if(h==1)
			{
				int teacherid;
				printf("Enter the new Teacher ID:\n");
				scanf("%d",&teacherid);
				teachers[l].teacherId=teacherid;
			}
			else if(h==2)
			{
				char Firstname[50];
				printf("Enter the new first name of teacher:\n");
				scanf("%s",Firstname);
				strcpy(teachers[l].firstname,Firstname);
			}
			else if(h==3)
			{
				char Lastname[50];
				printf("Enter the new last name of teacher:\n");
				scanf("%s",Lastname);
				strcpy(teachers[l].lastname,Lastname);
			}
			else if(h==4)
			{
				char c[50];
				printf("Enter the new subject of teacher:\n");
				scanf("%s",&c);
				strcpy(teachers[l].subject,c);
			}
			else if(h==5)
			{
				int a;
				printf("Enter the new assigned class:\n");
				scanf("%d",&a);
				teachers[l].assignedclass=a;
			}
			else if(h==6)
			{
				float salry;
				printf("Enter the new salary:\n");
				scanf("%f",&salry);
				teachers[l].salary=salry;
			}
			found=1;
			break;
		}
	}
if(found==0)
{	
	printf("Record not found\n");
}
	
}

//Function to search teacher by teacher id
void searchteacher()
{
			int teacherID,found=0;
			printf("Enter the Techer ID of teacher whose record to be searched:\n");
			scanf("%d",&teacherID);
			for(int e=0;e<total_teachers;e++)
			{
				if(teacherID==teachers[e].teacherId)
				{
					printf("Record founded\n");
					printf("The details of student are:\n");
					printf("Teacher ID=%d\n",teachers[e].teacherId);
					printf("FIRST NAME=%s\n",teachers[e].firstname);
					printf("LAST NAME=%s\n",teachers[e].lastname);
					printf("Subject =%s\n",teachers[e].subject);
					printf("Assigned Class=%d\n",teachers[e].assignedclass);
					found=1;
					break;
				}
			}
if(found==0)
{
	printf("Record not found");
}

	}

//Function to display all students 
void displayteacher()
{	printf("Teacher ID\t\t\t\t\tFirst Name\t\t\t\t\tLast Name\t\t\t\t\tSubject\t\t\t\t\tAssigned Class\t\t\t\t\tSalary\n");
	for(int v=0;v<total_teachers;v++)
	{
				printf("%d\t",teachers[v].teacherId);
		printf("%s\t",teachers[v].firstname);
		printf("%s\t",teachers[v].lastname);
		printf("%s\t",teachers[v].subject);
		printf("%d\t",teachers[v].assignedclass);
		printf("%f\t",teachers[v].salary);
	}
}
void teachermanagement(){
	int n;
	do{
	printf("1.Add teacher\n2. Remove teacher\n3. Update teacher\n4.Search teacher\n5.Display teachers\n6.Back\n");
	printf("Enter your choice:\n");
	scanf("%d",&n);
	if(n==1)
	{
		addteacher();
	}
	else if(n==2)
	{
		removeteacher();
	}
	else if(n==3)
	{
		updateteacher();
	}
	else if(n==4)
	{
		searchteacher();
	}
	else if(n==5)
	{
		displayteacher();
	}
	else if(n==6)
	{
		printf("Exit done from teacher management\n");
		break;
	}
	else
		printf("Invalid choice\n");
	}while(n!=6);
}
/*----------------------------------------------------------
		 CLASS FUNCTIONS 
----------------------------------------------------------*/

// Function to create a new class
void createclass()
{
	
	
		printf("Enter the class details:\n");
		printf("Enter the class ID:\n");
		scanf("%d",&class[total_classes].classID);
		class[total_classes].classteacherID=-1;
		total_classes++;
	
}

// Function to assign teacher to class
void assignclassteacher(){
	int classid,teacherid,found=0;
	printf("Enter the  class ID:\n");
	scanf("%d",&classid);
	printf("Enter the teacher ID:\n");
	scanf("%d",&teacherid);;
	for(int u=0;u<total_classes;u++)
	{
		if(classid==class[u].classID)
		{
			
			for(int k=0;k<total_teachers;k++)
			{
				if(teacherid==teachers[k].teacherId)
				{
					class[u].classteacherID = teacherid;
					printf("Teacher assigned successfully!\n");
				found=1;
				break;
				}
			}
		}
	}
if(found==0)
{
	printf("Either teacher id or class id not found");
}
}

//Function to display students of a particular class				
void dispalystudentofclass(){
	int classid;
	printf("Enter the class id of class for which you want to dispaly all students:\n");
	scanf("%d",&classid);
	for(int x=0;x<total_students;x++)
	{
		if(classid==students[x].class)
		{		
			printf("%d\t",students[x].rollNo);
			printf("%s\t",students[x].firstname);
			printf("%s\t",students[x].lastname);
			printf("%d\t",students[x].class);
			printf("%d\t",students[x].age);
			for(int c=0;c<5;c++)
			{
				printf("%d\t",students[x].marks[c]);
			}
			printf("%f\n",students[x].attendance);
		}
	}
}

//Function to calculate average marks of a class
void averagemarks(){
		int classid,totals=0,count=0,sum=0;
		float average;
		printf("Enter the class for which you want to calculate average\n");
		scanf("%d",&classid);
		for(int v=0; v<total_students; v++)
		{
   			 if(students[v].class == classid)
  	        {
       			 for(int t=0; t<5; t++)
        		{
          			  sum = sum + students[v].marks[t];
				  
      			}
       				 count++;
   		 }
		}		
			
		average=sum/(count*5.0);
		if(count==0)
		{
			printf("Nostudents in this class\n");
		}
		else
		{
		printf("The average of this class is:%f\n",average);
		}
}
void classmanagement()
{
	int h;
do{
	printf("1.Create Class\n2.Assign Class Teacher\n3.Display Students of class\n4.Calculate class average marks\n5.Back\n");
	printf("Enter your choice:");
	scanf("%d",&h);
	if(h==1)
	{
		createclass();
	}
	else if(h==2)
	{
		assignclassteacher();
	}
	else if(h==3)
	{
		dispalystudentofclass();
	}
	else if(h==4)
	{
		averagemarks();
	}
	else if(h==5)
	{
		printf("Exited from class management\n");
		break;
	}
	else
		printf("Invalid input\n");
	}while(h!=5);
}
/*----------------------------------------------------------
			RESULT SECTION
 ----------------------------------------------------------*/
			
//Function to assign grades to students
void assigngrade()
{
	int mark[5];
	float percent;
	printf("Roll No.\t\t\t\t\t Marks \t\t\t\t\t\t\t\t\t\t Total Marks\t\t\t\t\t Percentage\t\t\t\t\t Grade");
	for(int f=0;f<total_students;f++)
	{
		int sum=0;
		printf("%d\t",students[f].rollNo);
		for(int t=0;t<5;t++)
		{
			printf("%d\t",students[f].marks[t]);
			sum=sum+students[f].marks[t];
		}
		printf("%d\t\t\t\t\t",sum);
		percent=(sum/500.0)*100;
		printf("%f\t\t\t\t\t",percent);
		if(percent>=90)
		{
			printf("A\n");
		}
		else if(percent>=75)
		{
			printf("B\n");
		}
		else if(percent>=60)
		{
			printf("C\n");
		}
		else if(percent>=40)
		{
			printf("D\n");
		}
		else 
		{
			printf("F\n");
		}
	}
}
		
//Function to display the topper details
void displaytopper()
	{
		int max=0;
		int topperindex=-1;
		for(int f=0;f<total_students;f++)
		{
		int sum=0;
		for(int t=0;t<5;t++)
		{
			sum=sum+students[f].marks[t];
		}
		
		if(sum>max)
		{
			max=sum;
			topperindex=f;
		}
		}
	if(topperindex==-1)
	{
		printf("No topper exits\n");
	}
	else
	{
	printf("Topper of school\n");
	printf("Roll no.:%d\n",students[topperindex].rollNo);
	printf("Name:%s%s\n",students[topperindex].firstname,students[topperindex].lastname);
	printf("Class=%d\n",students[topperindex].class);
	printf("Age=%d\n",students[topperindex].age);
	printf("Marks: \t");
	for(int g=0;g<5;g++)
	{
		printf("%d\t",students[topperindex].marks[g]);
	}
	printf("\nAttendance:%f\n",students[topperindex].attendance);
}
}
//Function to calculate percentage
void calculatepercentage(){


	int mark[5];
	float percent;
	printf("Roll No.\t\t\t\t\t Marks \t\t\t\t\t\t\t\t\t\t Total Marks\t\t\t\t\t Percentage");
	for(int f=0;f<total_students;f++)
	{	
		int sum=0;
		printf("%d\t",students[f].rollNo);
		for(int t=0;t<5;t++)
		{
			printf("%d\t",students[f].marks[t]);
			sum=sum+students[f].marks[t];
		}
		printf("%d",sum);
		percent=(sum/500.0)*100;
		printf("%f",percent);
	}
}

//Function to calculate the total marks 			
void calculatetotalmarks()
{
	int mark[5];
	printf("Roll No.\t\t\t\t\t Marks \t\t\t\t\t\t\t\t\t\t Total Marks");
	for(int f=0;f<total_students;f++)
	{
		int sum=0;
		printf("%d\t",students[f].rollNo);
		for(int t=0;t<5;t++)
		{
			printf("%d\t",students[f].marks[t]);
			sum=sum+students[f].marks[t];
		}
		printf("%d",sum);
	}
}
		

void resultsection()
{
	int y;
do{
	printf("1.Calculate total marks\n2.Calculate percentage\n3.Assign grade\n4.Display topper\n5.Back\n");
	printf("Enter your choice:");
	scanf("%d",&y);
	if(y==1)
	{
		calculatetotalmarks();
	}
	else if(y==2){
		calculatepercentage();
	}
	else if(y==3)
	{
		assigngrade();
	}
	else if(y==4){
		displaytopper();
	}
	else if(y==5){
		printf("Exited the result section\n");
		break;
	}
	else
	{
		printf("Invalid input entered\n");
	}
	}while(y!=5);
}


			
int main()
{
	int choice;
	do{
	printf("1.Student Management\n2.Teacher Management\n3.Class Management\n4.Result Section\n5.Exit\n");
	printf("Enter your choice:\n");
	scanf("%d",&choice);
	if(choice==1)
	{
		studentmanagement();
	}
	else if(choice==2)
	{
		teachermanagement();
	}
	else if(choice==3)
	{
		classmanagement();
	}
	else if(choice==4)
	{
		resultsection();
	}
	else if(choice==5)
	{
		printf("Exit done\n");
		break;
	}
	else
	{
		printf("Invalid choice\n");
	}
	}while(choice!=5);
return 0;
}