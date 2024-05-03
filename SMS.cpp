#include <iostream>
#include <fstream>
#include <conio.h>
#include <string.h>
#include <unistd.h>
#include <iomanip>
#include <vector>
using namespace std;
////////////////////////////////////////////////////////////////////
class Student{
    private:
        string Name;
        int RollNo;
        int Marks;
        long PhoneNo;
    public:
        Student(string Name="",int RollNo=0 ,int Marks=0 ,long PhoneNo=0){
            this->Name = Name;
            this->RollNo = RollNo;
            this->Marks = Marks;
            this->PhoneNo = PhoneNo;
        }
        string getName(){return Name;}
        long getRollNo(){return RollNo;}
        int getMarks(){return Marks;}
        long getPhoneNo(){return PhoneNo;}
        void sortStudent();

        vector<Student> studentRecord; 
        void rawData(){
            for (int i = 0; i < 10; ++i) {
                string name = "Student" + to_string(i + 1);
                int rollno = 10 + i*33;
                int marks = 121 + i*2;
                long phoneNo = (i*7 + 1) * 8919;

                Student newStudent(name, rollno, marks, phoneNo);
                studentRecord.push_back(newStudent);
                sortStudent();
            }
        }
        void systemLogo();
        void thanksMSG();
        void welcomeMSG();

};
////////////////////////////////////////////////////////////////////
class AdminControl : public Student{
    public:
        void adminLogin();
        void AddNewStudent();
        void showAllStudent();
        void removeStudent();
        void showAdminWindow();
        void logOut();
};
////////////////////////////////////////////////////////////////////
void Student :: systemLogo(){
    ifstream in("welStudent.txt");
    if(!in){
        cout<< "Cannot open input file.\n";
    }
    char str[1000];
    while(in){
        in.getline(str,1000);
        if(in){
            cout<<str<<endl;
        }
    }
    in.close();
}
////////////////////////////////////////////////////////////////////
void Student :: sortStudent(){
    string temp;
    for(int i=0;i<studentRecord.size();i++){
        for(int j=i+1;j<studentRecord.size();j++){
            if((studentRecord[i].getName().compare(studentRecord[j].getName()) > 0)){
                // strcpy(temp,studentRecord[i].getStudentName());
                swap(studentRecord[i], studentRecord[j]);
                
            }
        }
    }
}

////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////

void AdminControl :: adminLogin(){
    system("cls");
    rawData();
    systemLogo();
    string name;
    int pass;
    cout<<"\n\n\n\n\n";
    cout<<"\t\t\t\t\t     Admin Authentication :) \n\n";
    cout<<"\t\t\t\t\t--------------------------------\n";
    cout<<"\t\t\t\t\t            LOGIN  \n";
    cout<<"\t\t\t\t\t--------------------------------\n\n";
    cout<<"\t\t\t\t\t Enter Your Name : ";
    cin>>name;
    cout<<"\t\t\t\t\t Enter Your Password : ";
    cin>>pass;
    if(name == "sachin" && pass == 123){
        sleep(1);
        cout<<"\n\t\t\t\t\t Access Granted :) \n";
        sleep(1);
        cout<<"\n\n\nProcessing ... ";
        sleep(2);
        showAdminWindow();
        
    }
    else{
        cout<<"\n\t\t\t\t\t Access Denied :) \n";
        sleep(1);
        adminLogin();
    }
}
////////////////////////////////////////////////////////////////////
void AdminControl :: logOut(){
    system("cls");
    cout<<"\n\n";
    thanksMSG();
}
////////////////////////////////////////////////////////////////////
void AdminControl :: showAdminWindow(){
    system("cls");
    char choice;
    systemLogo();
    cout<<"\n\n\n\n\n";
    cout<<"\t\t\t\t\t             STUDENT MANAGEMENT SYSTEM (*-*) \n";
    cout<<"\t\t\t\t\t|-------------------------------------------------------|\n"<<endl;
    cout<<"\t\t\t\t\t   1. Add New Student \n";
    cout<<"\t\t\t\t\t   2. Remove A Student \n";
    cout<<"\t\t\t\t\t   3. Show All Student Record \n";
    cout<<"\t\t\t\t\t   4. LogOut \n"<<endl;
    cout<<"\t\t\t\t\t|-------------------------------------------------------|\n"<<endl;
    cout<<"\nSelect Any Option : ";
    sleep(1);
    cin>>choice;
    if(choice == '1'){
        sleep(1);
        AddNewStudent();
    }
    if(choice == '2'){
        sleep(1);
        removeStudent();
    }
    if(choice == '3'){
        sleep(1);
        showAllStudent();
    }
    if(choice == '4'){
        sleep(1);
        logOut();
    }
    else{
        cout<<"Invalid Choice :)";
        sleep(1);
        showAdminWindow();
    }
    

}
////////////////////////////////////////////////////////////////////
void AdminControl :: AddNewStudent(){
    system("cls");
    sleep(1);
    systemLogo();
    string name;
    int rollno,marks;
    long phoneNo;
    int count;
    cout<<"\n\n\t\t\tHow Many Student Do You Want to Add : ";
    cin>>count;
    cout<<"\n\n";
    for(int i=1;i<=count;i++){
        
        cout<<"Entry No. : "<<i<<"\n";
        cout<<"\t\t\tEnter Student Name : ";
        cin>>name;
        cout<<"\t\t\tEnter Student Roll No : ";
        cin>>rollno;
        cout<<"\t\t\tEnter Student Marks : ";
        cin>>marks;
        cout<<"\t\t\tEnter Student Phone No : ";
        cin>>phoneNo;

        Student newStudent(name,rollno,marks,phoneNo);
        studentRecord.push_back(newStudent);
        cout<<"\n\t\t\tStudent Registerd Successfully .....\n\n"<<endl;
        sleep(1);
    }
    cout<<"\n\n\n\n Back To The Home Screen... ";
    sleep(2);
    showAdminWindow();

}
////////////////////////////////////////////////////////////////////
void AdminControl :: showAllStudent(){
    system("cls");
    systemLogo();
    string choice;
    cout<<"\n                     ---Students List---"<<endl;
    cout<<"------------------------------------------------------------------"<<endl;
    cout<<"S.No.\tStudentName\tRollNo\t\tMarks\t\tPhoneNo\n"<<endl;
    cout<<"------------------------------------------------------------------"<<endl;
    int serialNo = 1;
    sortStudent();
    for(int i=0;i<studentRecord.size();i++){
        cout<<serialNo<<setw(15)<<studentRecord[i].getName()<<setw(15)<<studentRecord[i].getRollNo()<<setw(15)<<studentRecord[i].getMarks()<<setw(15)<<studentRecord[i].getPhoneNo()<<"\n"<<endl;
        serialNo++;
    }
    sleep(2);
    cout<<"\nDo You Want To Go Back Home Screen  : ";
    cin>>choice;
    if(choice == "yes" || choice == "y"){
        sleep(1);
        showAdminWindow();
    }
    else{
        sleep(1);
        showAdminWindow();
    }
}
////////////////////////////////////////////////////////////////////
void AdminControl :: removeStudent(){
    system("cls");
    sleep(1);
    systemLogo();
    string studentName;
    cout<<"\n\n\n\n\n";
    cout<<"\t\t\t\t\t              STUDENT MANAGEMENT SYSTEM (*-*) \n";
    cout<<"\t\t\t\t\t|-------------------------------------------------------|\n"<<endl;
    cout<<"\n\t\t\t\t\t  Enter Student Name : ";
    cin>>studentName;
   	for(int i=0; i<studentRecord.size(); i++){
   		if(studentRecord[i].getName()==studentName){
   			studentRecord.erase(studentRecord.begin() + i);
            sleep(1);
            cout<<"\n\nProcessing....\n";
            sleep(1);
   			cout<<"Student Removed Successfully....\n"<<endl;
            sleep(1);
            cout<<"Back To The Home Screen..."<<endl;
            sleep(1);
            showAdminWindow();
		}
        else{
            cout<<"\nInvalid Student Name :)";
            sleep(1);
            removeStudent();
        }
	}
}
////////////////////////////////////////////////////////////////////
void Student :: welcomeMSG(){
    ifstream in("welStudent.txt");
    if(!in){
        cout<< "Cannot open input file.\n";
    }
    char str[1000];
    while(in){
        in.getline(str,1000);
        if(in){
            cout<<str<<endl;
        }
    }
    in.close();
    sleep(1);
    cout<<"\nStarting the program please wait....."<<endl;
    sleep(1);
    cout<<"\nloading up files......."<<endl;
    sleep(2);\
    
}
void Student :: thanksMSG(){
    ifstream in("Thanks.txt");
    if(!in){
        cout<< "Cannot open input file.\n";
    }
    char str[1000];
    while(in){
        in.getline(str,1000);
        if(in){
            cout<<str<<endl;
        }
    }
    in.close();
}
////////////////////////////////////////////////////////////////////
int main(){
    AdminControl admin;
    admin.welcomeMSG();
    admin.adminLogin();

}