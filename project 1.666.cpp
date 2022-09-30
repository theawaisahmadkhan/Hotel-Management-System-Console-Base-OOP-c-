#include<iostream>
#include<fstream>
#include<string>
#include <sstream>
using namespace std;
class Room{    //base class 
	protected:
		char room_type[20];
		int Room_no;
		int time;
		int remaning_time;
	
	public://use pure virtual function for polymorphism
			virtual 	int input(int floor,int room_no,int t_date,int month,fstream &f6,fstream &file)=0;/*this take input from accountant and fstream f6 file is a global file
			     that save the customer record how many customer are reserve the room*/
			virtual 	int output(fstream &file)=0;                                                     //this function use for output for reserced room
			virtual int check(int floor,int room_no,fstream &file)=0;                             // this function check room availibility
			virtual 	int update(int t_hr,int t_min,int t_date,int d,fstream &f7,int f,int r,fstream &file)=0;            //this function update the room data if days are commplete
		
			
		
};
class standard:public Room{//first derived class 
char f_name[50];
	char l_name[50];
	int age;
	char gender[10];
	long long int id;//take iid card number
		int charge;
	int balance;
	int reserve_days_no;
	int Floor;
	int hr,min;
	int date;
	int Month;
	int count_days;
	public:
			standard()//constructor
		{
            char f_name[]="";
            char l_name[]="";
            char gender[]="";;
			age=0;
			id=0;
			balance=0;
			charge=300;             //rooom charges by default assign
			reserve_days_no=0;
			Floor=0;
		}
			int input(int floor,int room_no,int t_date,int month,fstream &f6,fstream &file)
		{
			if(id==0)//check room already reserved or not if id equal to 0 that means room is available
			{
			
			
	
		cout<<"ENTERR CUSTOMER FIRST NAME:"<<endl;
		cin>>f_name;

    	cout<<"ENTER CUSTOME LAST NAME:"<<endl;
    	cin>>l_name;
		cout<<"ENTER CUSTOMER AGE:"<<endl;
		cin>>age;
		cout<<"ENTER CUSTOMER GENDER:"<<endl;
		cin>>gender;
		cout<<"ENTER CUSTOMER ID:"<<endl;
		cin>>id;
	
		cout<<"ENTER RESERVE DAYS NO:"<<endl;
		cin>>reserve_days_no;
		balance=charge*reserve_days_no;
		Floor=floor;
		Room_no=room_no;
		cout<<"ENTER TIME IN HOUUR AND MINUTE:"<<endl;
		cin>>hr>>min;
		date=t_date;
		Month=month;
		cout<<"ENTER ROOM TYPE STANDARD:"<<endl;
		cin>>room_type;
		//binary writing in f6 file global and file within the class file
		//f6 store customer record
		f6.write((char*)&f_name,sizeof(f_name));
		f6.write((char*)&l_name,sizeof(l_name));
		f6.write((char*)&gender,sizeof(gender));
		f6.write((char*)&age,sizeof(age));
        f6.write((char*)&room_type,sizeof(room_type));
    	f6.write((char*)&id,sizeof(id));
		f6.write((char*)&balance,sizeof(balance));
		f6.write((char*)&reserve_days_no,sizeof(reserve_days_no));
		f6.write((char*)&Floor,sizeof(Floor));
		f6.write((char*)&Room_no,sizeof(Room_no));
		f6.write((char*)&hr,sizeof(hr));
		f6.write((char*)&min,sizeof(min));
		f6.write((char*)&Month,sizeof(Month));
		f6.write((char*)&date,sizeof(date));
		
		//file store the room record
		file.write((char*)&f_name,sizeof(f_name));
		file.write((char*)&l_name,sizeof(l_name));
		file.write((char*)&gender,sizeof(gender));
		file.write((char*)&age,sizeof(age));
        file.write((char*)&room_type,sizeof(room_type));
    	file.write((char*)&id,sizeof(id));
		file.write((char*)&balance,sizeof(balance));
		file.write((char*)&reserve_days_no,sizeof(reserve_days_no));
		file.write((char*)&Floor,sizeof(Floor));
		file.write((char*)&Room_no,sizeof(Room_no));
		file.write((char*)&hr,sizeof(hr));
		file.write((char*)&min,sizeof(min));
		file.write((char*)&Month,sizeof(Month));
		file.write((char*)&date,sizeof(date));
		bill();
	}
	else{
		cout<<"ROOM ALREADY RESERVE CHOOSE ANOTHER ROOM:"<<endl<<endl<<endl;//tell about room is not available
	    }
	    	file.close();
		
		}
		int output(fstream &file)//show the room data 
		{

		
		file.read((char*)&f_name,sizeof(f_name));
		file.read((char*)&l_name,sizeof(l_name));
		file.read((char*)&gender,sizeof(gender));
		file.read((char*)&age,sizeof(age));
        file.read((char*)&room_type,sizeof(room_type));
    	file.read((char*)&id,sizeof(id));
		file.read((char*)&balance,sizeof(balance));
		file.read((char*)&reserve_days_no,sizeof(reserve_days_no));
		file.read((char*)&Floor,sizeof(Floor));
		file.read((char*)&Room_no,sizeof(Room_no));
		file.read((char*)&hr,sizeof(hr));
		file.read((char*)&min,sizeof(min));
		file.read((char*)&Month,sizeof(Month));
		file.read((char*)&date,sizeof(date));
		
			if(age!=0)
			{
			
		
				cout<<"NAME:="<<f_name<<" "<<l_name<<endl;
				cout<<"GENDER:"<<gender<<endl;
				cout<<"AGE:"<<age<<endl;
				cout<<"ROOM_TYPE:"<<room_type<<endl;
				cout<<"CUSTOMER_ID_CARD:"<<id<<endl;
				cout<<"ROOM_BALANCE:"<<balance<<endl;
				cout<<"RESERVE_DAYS:"<<reserve_days_no<<endl;
				cout<<"FLOOR:"<<Floor<<endl;
				cout<<"ROOM_NO:"<<Room_no<<endl;
				cout<<"DATE:"<<date<<endl;
				cout<<"HOURE:MIN"<<hr<<":"<<min<<endl;
				cout<<endl<<endl;

		}
				
		file.close();
		}
		int check(int floor,int room_no,fstream &file)//check room availibility
		{
		
			string w1 = "seq";
string filename;
stringstream str;
str << w1 << floor << room_no << ".dat";
filename = str.str();
file.open( filename.c_str(),ios::out|ios::binary );
				
		file.read((char*)&f_name,sizeof(f_name));
		file.read((char*)&l_name,sizeof(l_name));
		file.read((char*)&gender,sizeof(gender));
		file.read((char*)&age,sizeof(age));
        file.read((char*)&room_type,sizeof(room_type));
    	file.read((char*)&id,sizeof(id));
		file.read((char*)&balance,sizeof(balance));
		file.read((char*)&reserve_days_no,sizeof(reserve_days_no));
		file.read((char*)&Floor,sizeof(Floor));
		file.read((char*)&Room_no,sizeof(Room_no));
		file.read((char*)&hr,sizeof(hr));
		file.read((char*)&min,sizeof(min));
		file.read((char*)&Month,sizeof(Month));
		file.read((char*)&date,sizeof(date));
			if(id==0)
			{
				cout<<"Floor="<<floor<<"\t"<<"Room="<<room_no<<"\t";
			}
			cout<<endl;
			
				file.close();
		}
		int bill()//this function create the customer bill
		{
			cout<<endl;
			cout<<"THANKYOU FOR CHOOSE OUR HOTEL SIR/MADAM"<<endl;
			cout<<"NAME:"<<f_name<<" "<<l_name<<endl;
			cout<<"ROOM TYPE:"<<room_type<<endl;
			cout<<"RESERVED DAYS:"<<reserve_days_no<<endl;
			cout<<"ROOM CHARGES FOR 24 HOURS:"<<charge<<endl;
			cout<<"YOUR BILL IS:"<<balance<<endl<<endl;
			cout<<"HAVE A NICE DAY SIR/MADAM:"<<endl;
			
		}
		int update(int t_hr,int t_min,int t_date,int d,fstream &f7,int f,int r,fstream &file)
		{
				string w1 = "seq";
string filename;
stringstream str;
str << w1 << f << r << ".dat";
filename = str.str();
file.open( filename.c_str(),ios::in|ios::out|ios::binary );
				fstream file_del;
				file_del.open("temp.dat",ios::out|ios::binary);
				
		file.read((char*)&f_name,sizeof(f_name));
		file.read((char*)&l_name,sizeof(l_name));
		file.read((char*)&gender,sizeof(gender));
		file.read((char*)&age,sizeof(age));
        file.read((char*)&room_type,sizeof(room_type));
    	file.read((char*)&id,sizeof(id));
		file.read((char*)&balance,sizeof(balance));
		file.read((char*)&reserve_days_no,sizeof(reserve_days_no));
		file.read((char*)&Floor,sizeof(Floor));
		file.read((char*)&Room_no,sizeof(Room_no));
		file.read((char*)&hr,sizeof(hr));
		file.read((char*)&min,sizeof(min));
		file.read((char*)&Month,sizeof(Month));
		file.read((char*)&date,sizeof(date));
	if(age!=0)
	{
					
			
	int days;int calculate,calculate1;
	int left_d;
	int time_h;
	int time_m;
	int h,m;
	days=t_date-date;
	//these line of code calculate the remaining time and calculate the day hour and minute
	//if reserved days no and count days number equal to then update the and remove the customer data from room file
 if(t_hr>hr)
 {
 	if(t_min>min)
 	{
 		t_hr=t_hr-hr;
 		t_min=t_min-min;
 		calculate=60*t_hr;
 		calculate+=t_min;
	 }
	 else{
	 		t_hr=t_hr-hr;
 		t_min=min-t_min;
 			calculate=60*t_hr;
 		calculate+=t_min;
	 	
	 }
 }
 else if(t_hr<hr)
 {
  if(t_min>min)
  {
  		t_hr=hr-t_hr;
  		t_min=min-t_min;
  			calculate=60*t_hr;
 		calculate+=t_min;
  		
  }
  else{
  		t_hr=hr-t_hr;
  		t_min=t_min-min;
  		calculate=60*t_hr;
 		calculate+=t_min;
  }
 }
 calculate1=days*24*60;
 calculate+=calculate1;
 
 left_d=calculate/(24*3600);
 time_h=calculate%(24*3600);
 
 h=time_h/3600;
 m=time_h%3600;
 time_m=m/60;
	left_d=reserve_days_no-days;
	if(d==1)
	{
	//if time is remaining
	if(days<reserve_days_no)
	{
			cout<<"NAME:"<<f_name<<endl;
			cout<<"FLOOR:"<<Floor<<endl;
			cout<<"ROOM:"<<Room_no<<endl;
			cout<<"RREMAINING TIME:"<<left_d<<"DAYS:"<<":"<<h<<"HOUR:"<<":"<<time_m<<"MIN:"<<endl;
			cout<<endl<<endl;	
	}
}
//if time complete then remove the data fromm file
		if(days>=reserve_days_no)
		{
			//when time coomplete 
	f7<<f_name<<"\t"<<l_name<<"\t"<<gender<<"\t"<<age<<"\t"<<room_type<<"\t"<<id<<"\t"<<balance<<"\t"<<reserve_days_no<<"\t"<<Floor<<"\t"<<Room_no<<"\t"<<hr<<"\t"<<min<<"\t"<<Month<<"\t"<<date<<endl ;

			
			age=0;
			char f_name[]="";
            char l_name[]="";
            char gender[]="";
			id=0;
			balance=0;
			reserve_days_no=0;
			Floor=0;
			count_days=0;
			remove(filename.c_str());//room file data remove
			rename("temp.dat",filename.c_str());//and again create new file
		}
			
		}
		file.close();
	
}
};
class moderate:public Room{//second derived class 
	char f_name[50];
	char l_name[50];
	int age;
	char gender[10];
	long long int id;
		int charge;
	int balance;
	int reserve_days_no;
	int Floor;
	int hr,min;
	int date;
	int Month;
	int count_days;
	public:
			moderate()//constructor
		{
			char f_name[]="";
			char l_name[]="";
			char gender[]="";
			age=0;
			
			id=0;
			balance=0;
			reserve_days_no=0;
			charge=500;//by default assignt the charges of 1 day
			Floor=0;
		}
			int input(int floor,int room_no,int t_date,int month,fstream &f6,fstream &file)//take input in room file and global file f6.
		{
		if(id==0)
		{
			
	
		cout<<"ENTERR CUSTOMER FIRST NAME:"<<endl;
		cin>>f_name;

    	cout<<"ENTER CUSTOME LAST NAME:"<<endl;
    	cin>>l_name;
		cout<<"ENTER CUSTOMER AGE:"<<endl;
		cin>>age;
		cout<<"ENTER CUSTOMER GENDER:"<<endl;
		cin>>gender;
		cout<<"ENTER CUSTOMER ID:"<<endl;
		cin>>id;
	
		cout<<"ENTER RESERVE DAYS NO:"<<endl;
		cin>>reserve_days_no;
		balance=charge*reserve_days_no;
		Floor=floor;
		Room_no=room_no;
		cout<<"ENTER TIME IN HOUUR AND MINUTE:"<<endl;
		cin>>hr>>min;
		date=t_date;
		Month=month;
		cout<<"ENTER ROOM TYPR MODERATE:"<<endl;
		cin>>room_type;
		//write global customer file
		f6.write((char*)&f_name,sizeof(f_name));
		f6.write((char*)&l_name,sizeof(l_name));
		f6.write((char*)&gender,sizeof(gender));
		f6.write((char*)&age,sizeof(age));
        f6.write((char*)&room_type,sizeof(room_type));
    	f6.write((char*)&id,sizeof(id));
		f6.write((char*)&balance,sizeof(balance));
		f6.write((char*)&reserve_days_no,sizeof(reserve_days_no));
		f6.write((char*)&Floor,sizeof(Floor));
		f6.write((char*)&Room_no,sizeof(Room_no));
		f6.write((char*)&hr,sizeof(hr));
		f6.write((char*)&min,sizeof(min));
		f6.write((char*)&Month,sizeof(Month));
		f6.write((char*)&date,sizeof(date));
		
		//write room file within the class
		file.write((char*)&f_name,sizeof(f_name));
		file.write((char*)&l_name,sizeof(l_name));
		file.write((char*)&gender,sizeof(gender));
		file.write((char*)&age,sizeof(age));
        file.write((char*)&room_type,sizeof(room_type));
    	file.write((char*)&id,sizeof(id));
		file.write((char*)&balance,sizeof(balance));
		file.write((char*)&reserve_days_no,sizeof(reserve_days_no));
		file.write((char*)&Floor,sizeof(Floor));
		file.write((char*)&Room_no,sizeof(Room_no));
		file.write((char*)&hr,sizeof(hr));
		file.write((char*)&min,sizeof(min));
		file.write((char*)&Month,sizeof(Month));
		file.write((char*)&date,sizeof(date));
		bill();
	}
	else{
			cout<<"ROOM ALREADY RESERVE CHOOSE ANOTHER ROOM:"<<endl<<endl<<endl;//tell about room is availiable while reserving
	    }
	    	file.close();
		}
		int output(fstream &file)//show data in a single room
		{
			
		file.read((char*)&f_name,sizeof(f_name));
		file.read((char*)&l_name,sizeof(l_name));
		file.read((char*)&gender,sizeof(gender));
		file.read((char*)&age,sizeof(age));
        file.read((char*)&room_type,sizeof(room_type));
    	file.read((char*)&id,sizeof(id));
		file.read((char*)&balance,sizeof(balance));
		file.read((char*)&reserve_days_no,sizeof(reserve_days_no));
		file.read((char*)&Floor,sizeof(Floor));
		file.read((char*)&Room_no,sizeof(Room_no));
		file.read((char*)&hr,sizeof(hr));
		file.read((char*)&min,sizeof(min));
		file.read((char*)&Month,sizeof(Month));
		file.read((char*)&date,sizeof(date));
		
		
		if(age!=0)
		{
				cout<<"NAME:="<<f_name<<" "<<l_name<<endl;
				cout<<"GENDER:"<<gender<<endl;
				cout<<"AGE:"<<age<<endl;
				cout<<"ROOM_TYPE:"<<room_type<<endl;
				cout<<"CUSTOMER_ID_CARD:"<<id<<endl;
				cout<<"ROOM_BALANCE:"<<balance<<endl;
				cout<<"RESERVE_DAYS:"<<reserve_days_no<<endl;
				cout<<"FLOOR:"<<Floor<<endl;
				cout<<"ROOM_NO:"<<Room_no<<endl;
				cout<<"DATE:"<<date<<endl;
				cout<<"HOURE:MIN"<<hr<<":"<<min<<endl;
				cout<<endl<<endl;
				
		}		
			file.close();
		}
		int check(int floor,int room_no,fstream &file)//check room availibility
		{
		
			string w1 = "seq";
string filename;
stringstream str;
str << w1 << floor << room_no << ".dat";
filename = str.str();
file.open( filename.c_str(),ios::out|ios::binary );
				
		file.read((char*)&f_name,sizeof(f_name));
		file.read((char*)&l_name,sizeof(l_name));
		file.read((char*)&gender,sizeof(gender));
		file.read((char*)&age,sizeof(age));
        file.read((char*)&room_type,sizeof(room_type));
    	file.read((char*)&id,sizeof(id));
		file.read((char*)&balance,sizeof(balance));
		file.read((char*)&reserve_days_no,sizeof(reserve_days_no));
		file.read((char*)&Floor,sizeof(Floor));
		file.read((char*)&Room_no,sizeof(Room_no));
		file.read((char*)&hr,sizeof(hr));
		file.read((char*)&min,sizeof(min));
		file.read((char*)&Month,sizeof(Month));
		file.read((char*)&date,sizeof(date));
			if(id==0)
			{
				cout<<"Floor="<<floor<<"\t"<<"Room="<<room_no<<"\t";
			}
			cout<<endl;
			
				file.close();
		}
			int bill()//this function create the customer bill
		{
			cout<<endl;
			cout<<"THANKYOU FOR CHOOSE OUR HOTEL SIR/MADAM"<<endl;
			cout<<"NAME:"<<f_name<<" "<<l_name<<endl;
			cout<<"ROOM TYPE:"<<room_type<<endl;
			cout<<"RESERVED DAYS:"<<reserve_days_no<<endl;
			cout<<"ROOM CHARGES FOR 24 HOURS:"<<charge<<endl;
			cout<<"YOUR BILL IS:"<<balance<<endl<<endl;
			cout<<"HAVE A NICE DAY SIR/MADAM:"<<endl;
			
		}
		int update(int t_hr,int t_min,int t_date,int d,fstream &f7,int f,int r,fstream &file)
		{
				string w1 = "seq";
string filename;
stringstream str;
str << w1 << f << r << ".dat";
filename = str.str();
file.open( filename.c_str(),ios::in|ios::out|ios::binary );
				fstream file_del;
				file_del.open("temp.dat",ios::out|ios::binary);
				
		file.read((char*)&f_name,sizeof(f_name));
		file.read((char*)&l_name,sizeof(l_name));
		file.read((char*)&gender,sizeof(gender));
		file.read((char*)&age,sizeof(age));
        file.read((char*)&room_type,sizeof(room_type));
    	file.read((char*)&id,sizeof(id));
		file.read((char*)&balance,sizeof(balance));
		file.read((char*)&reserve_days_no,sizeof(reserve_days_no));
		file.read((char*)&Floor,sizeof(Floor));
		file.read((char*)&Room_no,sizeof(Room_no));
		file.read((char*)&hr,sizeof(hr));
		file.read((char*)&min,sizeof(min));
		file.read((char*)&Month,sizeof(Month));
		file.read((char*)&date,sizeof(date));
if(age!=0)
{
					
			
	int days;int calculate,calculate1;
	int left_d;
	int time_h;
	int time_m;
	int h,m;
	days=t_date-date;
	//these line of code calculate the remaining time and calculate the day hour and minute
	//if reserved days no and count days number equal to then update the and remove the customer data from room file
 if(t_hr>hr)
 {
 	if(t_min>min)
 	{
 		t_hr=t_hr-hr;
 		t_min=t_min-min;
 		calculate=60*t_hr;
 		calculate+=t_min;
	 }
	 else{
	 		t_hr=t_hr-hr;
 		t_min=min-t_min;
 			calculate=60*t_hr;
 		calculate+=t_min;
	 	
	 }
 }
 else if(t_hr<hr)
 {
  if(t_min>min)
  {
  		t_hr=hr-t_hr;
  		t_min=min-t_min;
  			calculate=60*t_hr;
 		calculate+=t_min;
  		
  }
  else{
  		t_hr=hr-t_hr;
  		t_min=t_min-min;
  		calculate=60*t_hr;
 		calculate+=t_min;
  }
 }
 calculate1=days*24*60;
 calculate+=calculate1;
 
 left_d=calculate/(24*3600);
 time_h=calculate%(24*3600);
 
 h=time_h/3600;
 m=time_h%3600;
 time_m=m/60;
	left_d=reserve_days_no-days;
	if(d==1)
	{
	//if time is remaining
	if(days<reserve_days_no)
	{
			cout<<"NAME:"<<f_name<<endl;
			cout<<"FLOOR:"<<Floor<<endl;
			cout<<"ROOM:"<<Room_no<<endl;
			cout<<"RREMAINING TIME:"<<left_d<<"DAYS:"<<":"<<h<<"HOUR:"<<":"<<time_m<<"MIN:"<<endl;
			cout<<endl<<endl;	
	}
}
//if time complete then remove the data fromm file
		if(days>=reserve_days_no)
		{
			//when time coomplete 
	f7<<f_name<<"\t"<<l_name<<"\t"<<gender<<"\t"<<age<<"\t"<<room_type<<"\t"<<id<<"\t"<<balance<<"\t"<<reserve_days_no<<"\t"<<Floor<<"\t"<<Room_no<<"\t"<<hr<<"\t"<<min<<"\t"<<Month<<"\t"<<date<<endl ;

			age=0;
			char f_name[]="";
            char l_name[]="";
            char gender[]="";
			id=0;
			balance=0;
			reserve_days_no=0;
			Floor=0;
			count_days=0;
			remove(filename.c_str());//room file data remove
			rename("temp.dat",filename.c_str());//and again create new file
		}
		
		}
			file.close();

}
};

class superior:public Room{//third derived class
		char f_name[50];
	char l_name[50];
	int age;
	char gender[10];
	long long int id;
		int charge;
	int balance;
	int reserve_days_no;
	int Floor;
	int hr,min;
	int date;
	int Month;
	int count_days;
	
	public:
			superior()//constructor
		{
			char f_name[]="";
			char l_name[]="";
			char gender[]="";
			age=0;
			id=0;
			balance=0;
			reserve_days_no=0;
			charge=1000;
			Floor=0;
		}
			int input(int floor,int room_no,int t_date,int month,fstream &f6,fstream &file)
		{
			if(id==0)
			{

	
		cout<<"ENTERR CUSTOMER FIRST NAME:"<<endl;
		cin>>f_name;

    	cout<<"ENTER CUSTOME LAST NAME:"<<endl;
	    cin>>l_name;
		cout<<"ENTER CUSTOMER AGE:"<<endl;
		cin>>age;
		cout<<"ENTER CUSTOMER GENDER:"<<endl;
		cin>>gender;
		cout<<"ENTER CUSTOMER ID:"<<endl;
		cin>>id;
	
		cout<<"ENTER RESERVE DAYS NO:"<<endl;
		cin>>reserve_days_no;
		balance=charge*reserve_days_no;
		Floor=floor;
		Room_no=room_no;
		cout<<"ENTER TIME IN HOUUR AND MINUTE:"<<endl;
		cin>>hr>>min;
		date=t_date;
		Month=month;
		cout<<"ENTERR ROOM TYPE SUPERIOR:"<<endl;
		cin>>room_type;
		f6.write((char*)&f_name,sizeof(f_name));
		f6.write((char*)&l_name,sizeof(l_name));
		f6.write((char*)&gender,sizeof(gender));
		f6.write((char*)&age,sizeof(age));
        f6.write((char*)&room_type,sizeof(room_type));
    	f6.write((char*)&id,sizeof(id));
		f6.write((char*)&balance,sizeof(balance));
		f6.write((char*)&reserve_days_no,sizeof(reserve_days_no));
		f6.write((char*)&Floor,sizeof(Floor));
		f6.write((char*)&Room_no,sizeof(Room_no));
		f6.write((char*)&hr,sizeof(hr));
		f6.write((char*)&min,sizeof(min));
		f6.write((char*)&Month,sizeof(Month));
		f6.write((char*)&date,sizeof(date));
		
		
		file.write((char*)&f_name,sizeof(f_name));
		file.write((char*)&l_name,sizeof(l_name));
		file.write((char*)&gender,sizeof(gender));
		file.write((char*)&age,sizeof(age));
        file.write((char*)&room_type,sizeof(room_type));
    	file.write((char*)&id,sizeof(id));
		file.write((char*)&balance,sizeof(balance));
		file.write((char*)&reserve_days_no,sizeof(reserve_days_no));
		file.write((char*)&Floor,sizeof(Floor));
		file.write((char*)&Room_no,sizeof(Room_no));
		file.write((char*)&hr,sizeof(hr));
		file.write((char*)&min,sizeof(min));
		file.write((char*)&Month,sizeof(Month));
		file.write((char*)&date,sizeof(date));
		bill();
	}
	else{
			cout<<"ROOM ALREADY RESERVE CHOOSE ANOTHER ROOM:"<<endl<<endl<<endl;
	    }
			file.close();
		}
		int output(fstream &file)
		{
		file.read((char*)&f_name,sizeof(f_name));
		file.read((char*)&l_name,sizeof(l_name));
		file.read((char*)&gender,sizeof(gender));
		file.read((char*)&age,sizeof(age));
        file.read((char*)&room_type,sizeof(room_type));
    	file.read((char*)&id,sizeof(id));
		file.read((char*)&balance,sizeof(balance));
		file.read((char*)&reserve_days_no,sizeof(reserve_days_no));
		file.read((char*)&Floor,sizeof(Floor));
		file.read((char*)&Room_no,sizeof(Room_no));
		file.read((char*)&hr,sizeof(hr));
		file.read((char*)&min,sizeof(min));
		file.read((char*)&Month,sizeof(Month));
		file.read((char*)&date,sizeof(date));
		
		
		if(age!=0)
		{
				cout<<"NAME:="<<f_name<<" "<<l_name<<endl;
				cout<<"GENDER:"<<gender<<endl;
				cout<<"AGE:"<<age<<endl;
				cout<<"ROOM_TYPE:"<<room_type<<endl;
				cout<<"CUSTOMER_ID_CARD:"<<id<<endl;
				cout<<"ROOM_BALANCE:"<<balance<<endl;
				cout<<"RESERVE_DAYS:"<<reserve_days_no<<endl;
				cout<<"FLOOR:"<<Floor<<endl;
				cout<<"ROOM_NO:"<<Room_no<<endl;
				cout<<"DATE:"<<date<<endl;
				cout<<"HOURE:MIN"<<hr<<":"<<min<<endl;
				cout<<endl<<endl;
				
		}		
			file.close();
		}
		int check(int floor,int room_no,fstream &file)//check room availibility
		{
		
			string w1 = "seq";
string filename;
stringstream str;
str << w1 << floor << room_no << ".dat";
filename = str.str();
file.open( filename.c_str(),ios::out|ios::binary );
				
		file.read((char*)&f_name,sizeof(f_name));
		file.read((char*)&l_name,sizeof(l_name));
		file.read((char*)&gender,sizeof(gender));
		file.read((char*)&age,sizeof(age));
        file.read((char*)&room_type,sizeof(room_type));
    	file.read((char*)&id,sizeof(id));
		file.read((char*)&balance,sizeof(balance));
		file.read((char*)&reserve_days_no,sizeof(reserve_days_no));
		file.read((char*)&Floor,sizeof(Floor));
		file.read((char*)&Room_no,sizeof(Room_no));
		file.read((char*)&hr,sizeof(hr));
		file.read((char*)&min,sizeof(min));
		file.read((char*)&Month,sizeof(Month));
		file.read((char*)&date,sizeof(date));
			if(id==0)
			{
				cout<<"Floor="<<floor<<"\t"<<"Room="<<room_no<<"\t";
			}
			cout<<endl;
			
				file.close();
		}
			int bill()
		{
			cout<<endl;
			cout<<"THANKYOU FOR CHOOSE OUR HOTEL SIR/MADAM"<<endl;
			cout<<"NAME:"<<f_name<<" "<<l_name<<endl;
			cout<<"ROOM TYPE:"<<room_type<<endl;
			cout<<"RESERVED DAYS:"<<reserve_days_no<<endl;
			cout<<"ROOM CHARGES FOR 24 HOURS:"<<charge<<endl;
			cout<<"YOUR BILL IS:"<<balance<<endl<<endl;
			cout<<"HAVE A NICE DAY SIR/MADAM:"<<endl;
			
		}
		int update(int t_hr,int t_min,int t_date,int d,fstream &f7,int f,int r,fstream &file)
		{
				string w1 = "seq";
string filename;
stringstream str;
str << w1 << f << r << ".dat";
filename = str.str();
file.open( filename.c_str(),ios::in|ios::out|ios::binary );
				fstream file_del;
				file_del.open("temp.dat",ios::out|ios::binary);
				
		file.read((char*)&f_name,sizeof(f_name));
		file.read((char*)&l_name,sizeof(l_name));
		file.read((char*)&gender,sizeof(gender));
		file.read((char*)&age,sizeof(age));
        file.read((char*)&room_type,sizeof(room_type));
    	file.read((char*)&id,sizeof(id));
		file.read((char*)&balance,sizeof(balance));
		file.read((char*)&reserve_days_no,sizeof(reserve_days_no));
		file.read((char*)&Floor,sizeof(Floor));
		file.read((char*)&Room_no,sizeof(Room_no));
		file.read((char*)&hr,sizeof(hr));
		file.read((char*)&min,sizeof(min));
		file.read((char*)&Month,sizeof(Month));
		file.read((char*)&date,sizeof(date));
			
if(age!=0)
{
						
	int days;int calculate,calculate1;
	int left_d;
	int time_h;
	int time_m;
	int h,m;
	days=t_date-date;
	//these line of code calculate the remaining time and calculate the day hour and minute
	//if reserved days no and count days number equal to then update the and remove the customer data from room file
 if(t_hr>hr)
 {
 	if(t_min>min)
 	{
 		t_hr=t_hr-hr;
 		t_min=t_min-min;
 		calculate=60*t_hr;
 		calculate+=t_min;
	 }
	 else{
	 		t_hr=t_hr-hr;
 		t_min=min-t_min;
 			calculate=60*t_hr;
 		calculate+=t_min;
	 	
	 }
 }
 else if(t_hr<hr)
 {
  if(t_min>min)
  {
  		t_hr=hr-t_hr;
  		t_min=min-t_min;
  			calculate=60*t_hr;
 		calculate+=t_min;
  		
  }
  else{
  		t_hr=hr-t_hr;
  		t_min=t_min-min;
  		calculate=60*t_hr;
 		calculate+=t_min;
  }
 }
 calculate1=days*24*60;
 calculate+=calculate1;
 
 left_d=calculate/(24*3600);
 time_h=calculate%(24*3600);
 
 h=time_h/3600;
 m=time_h%3600;
 time_m=m/60;
	left_d=reserve_days_no-days;
	if(d==1)
	{
	//if time is remaining
	if(days<reserve_days_no)
	{
			cout<<"NAME:"<<f_name<<endl;
			cout<<"FLOOR:"<<Floor<<endl;
			cout<<"ROOM:"<<Room_no<<endl;
			cout<<"RREMAINING TIME:"<<left_d<<"DAYS:"<<":"<<h<<"HOUR:"<<":"<<time_m<<"MIN:"<<endl;
			cout<<endl<<endl;	
	}
}
//if time complete then remove the data fromm file
		if(days>=reserve_days_no)
		{
			//when time coomplete 
	f7<<f_name<<"\t"<<l_name<<"\t"<<gender<<"\t"<<age<<"\t"<<room_type<<"\t"<<id<<"\t"<<balance<<"\t"<<reserve_days_no<<"\t"<<Floor<<"\t"<<Room_no<<"\t"<<hr<<"\t"<<min<<"\t"<<Month<<"\t"<<date<<endl ;

			
			age=0;
			char f_name[]="";
            char l_name[]="";
            char gender[]="";
			id=0;
			balance=0;
			reserve_days_no=0;
			Floor=0;
			count_days=0;
			remove(filename.c_str());//room file data remove
			rename("temp.dat",filename.c_str());//and again create new file
		}
		
		}
			file.close();

}
};
class junior_suite:public Room{//fourth derived class
	char f_name[50];
	char l_name[50];
	int age;
	char gender[10];
	long long int id;
	int charge;
	int balance;
	int reserve_days_no;
	int Floor;
	int hr,min;
	int date;
	int Month;
	int count_days;
	public:
			junior_suite()//connstructor
		{
			char f_name[]="";
			char l_name[]="";
			char gender[]="";
			age=0;
			id=0;
			balance=0;
			reserve_days_no=0;
			charge=2000;
			Floor=0;
		}
			int input(int floor,int room_no,int t_date,int month,fstream &f6,fstream &file)
		{
			if(id==0)
			{

	
		cout<<"ENTER CUSTOMER FIRST NAME:"<<endl;
		cin>>f_name;

	    cout<<"ENTER CUSTOMER LAST NAME:"<<endl;
	    cin>>l_name;
		cout<<"ENTER CUSTOMER AGE:"<<endl;
		cin>>age;
		cout<<"ENTER CUSTOMER GENDER:"<<endl;
		cin>>gender;
		cout<<"ENTER CUSTOMER ID:"<<endl;
		cin>>id;
	
		cout<<"ENTER RRESERVE DAYS NO:"<<endl;
		cin>>reserve_days_no;
		balance=charge*reserve_days_no;
		Floor=floor;
		Room_no=room_no;
		cout<<"ENTER TIME IN HOUR AND MIN:"<<endl;
		cin>>hr>>min;
		date=t_date;
		Month=month;
		cout<<"ENTER ROOM TYPE JUNIOR:"<<endl;
		cin>>room_type;
		f6.write((char*)&f_name,sizeof(f_name));
		f6.write((char*)&l_name,sizeof(l_name));
		f6.write((char*)&gender,sizeof(gender));
		f6.write((char*)&age,sizeof(age));
        f6.write((char*)&room_type,sizeof(room_type));
    	f6.write((char*)&id,sizeof(id));
		f6.write((char*)&balance,sizeof(balance));
		f6.write((char*)&reserve_days_no,sizeof(reserve_days_no));
		f6.write((char*)&Floor,sizeof(Floor));
		f6.write((char*)&Room_no,sizeof(Room_no));
		f6.write((char*)&hr,sizeof(hr));
		f6.write((char*)&min,sizeof(min));
		f6.write((char*)&Month,sizeof(Month));
		f6.write((char*)&date,sizeof(date));
		
		
		file.write((char*)&f_name,sizeof(f_name));
		file.write((char*)&l_name,sizeof(l_name));
		file.write((char*)&gender,sizeof(gender));
		file.write((char*)&age,sizeof(age));
        file.write((char*)&room_type,sizeof(room_type));
    	file.write((char*)&id,sizeof(id));
		file.write((char*)&balance,sizeof(balance));
		file.write((char*)&reserve_days_no,sizeof(reserve_days_no));
		file.write((char*)&Floor,sizeof(Floor));
		file.write((char*)&Room_no,sizeof(Room_no));
		file.write((char*)&hr,sizeof(hr));
		file.write((char*)&min,sizeof(min));
		file.write((char*)&Month,sizeof(Month));
		file.write((char*)&date,sizeof(date));
		bill();
	}
	else{
			cout<<"ROOM ALREADY RESERVE CHOOSE ANOTHER ROOM:"<<endl<<endl<<endl;
	    }
		file.close();
		}
		int output(fstream &file)
		{
			
		file.read((char*)&f_name,sizeof(f_name));
		file.read((char*)&l_name,sizeof(l_name));
		file.read((char*)&gender,sizeof(gender));
		file.read((char*)&age,sizeof(age));
        file.read((char*)&room_type,sizeof(room_type));
    	file.read((char*)&id,sizeof(id));
		file.read((char*)&balance,sizeof(balance));
		file.read((char*)&reserve_days_no,sizeof(reserve_days_no));
		file.read((char*)&Floor,sizeof(Floor));
		file.read((char*)&Room_no,sizeof(Room_no));
		file.read((char*)&hr,sizeof(hr));
		file.read((char*)&min,sizeof(min));
		file.read((char*)&Month,sizeof(Month));
		file.read((char*)&date,sizeof(date));
		
		
		if(age!=0)
		{
				cout<<"NAME:="<<f_name<<" "<<l_name<<endl;
				cout<<"GENDER:"<<gender<<endl;
				cout<<"AGE:"<<age<<endl;
				cout<<"ROOM_TYPE:"<<room_type<<endl;
				cout<<"CUSTOMER_ID_CARD:"<<id<<endl;
				cout<<"ROOM_BALANCE:"<<balance<<endl;
				cout<<"RESERVE_DAYS:"<<reserve_days_no<<endl;
				cout<<"FLOOR:"<<Floor<<endl;
				cout<<"ROOM_NO:"<<Room_no<<endl;
				cout<<"DATE:"<<date<<endl;
				cout<<"HOURE:MIN"<<hr<<":"<<min<<endl;
				cout<<endl<<endl;
				
		}
		file.close();
		}
			int check(int floor,int room_no,fstream &file)//check room availibility
		{
		
			string w1 = "seq";
string filename;
stringstream str;
str << w1 << floor << room_no << ".dat";
filename = str.str();
file.open( filename.c_str(),ios::out|ios::binary );
				
		file.read((char*)&f_name,sizeof(f_name));
		file.read((char*)&l_name,sizeof(l_name));
		file.read((char*)&gender,sizeof(gender));
		file.read((char*)&age,sizeof(age));
        file.read((char*)&room_type,sizeof(room_type));
    	file.read((char*)&id,sizeof(id));
		file.read((char*)&balance,sizeof(balance));
		file.read((char*)&reserve_days_no,sizeof(reserve_days_no));
		file.read((char*)&Floor,sizeof(Floor));
		file.read((char*)&Room_no,sizeof(Room_no));
		file.read((char*)&hr,sizeof(hr));
		file.read((char*)&min,sizeof(min));
		file.read((char*)&Month,sizeof(Month));
		file.read((char*)&date,sizeof(date));
			if(id==0)
			{
				cout<<"Floor="<<floor<<"\t"<<"Room="<<room_no<<"\t";
			}
			cout<<endl;
			
			file.close();
		}
			int bill()
		{
			cout<<endl;
			cout<<"THANKYOU FOR CHOOSE OUR HOTEL SIR/MADAM"<<endl;
			cout<<"NAME:"<<f_name<<" "<<l_name<<endl;
			cout<<"ROOM TYPE:"<<room_type<<endl;
			cout<<"RESERVED DAYS:"<<reserve_days_no<<endl;
			cout<<"ROOM CHARGES FOR 24 HOURS:"<<charge<<endl;
			cout<<"YOUR BILL IS:"<<balance<<endl<<endl;
			cout<<"HAVE A NICE DAY SIR/MADAM:"<<endl;
			
		}
		int update(int t_hr,int t_min,int t_date,int d,fstream &f7,int f,int r,fstream &file)
		{
				string w1 = "seq";
string filename;
stringstream str;
str << w1 << f << r << ".dat";
filename = str.str();
file.open( filename.c_str(),ios::in|ios::out|ios::binary );
				fstream file_del;
				file_del.open("temp.dat",ios::out|ios::binary);
				
		file.read((char*)&f_name,sizeof(f_name));
		file.read((char*)&l_name,sizeof(l_name));
		file.read((char*)&gender,sizeof(gender));
		file.read((char*)&age,sizeof(age));
        file.read((char*)&room_type,sizeof(room_type));
    	file.read((char*)&id,sizeof(id));
		file.read((char*)&balance,sizeof(balance));
		file.read((char*)&reserve_days_no,sizeof(reserve_days_no));
		file.read((char*)&Floor,sizeof(Floor));
		file.read((char*)&Room_no,sizeof(Room_no));
		file.read((char*)&hr,sizeof(hr));
		file.read((char*)&min,sizeof(min));
		file.read((char*)&Month,sizeof(Month));
		file.read((char*)&date,sizeof(date));
			
if(age!=0)
{
					
	int days;int calculate,calculate1;
	int left_d;
	int time_h;
	int time_m;
	int h,m;
	days=t_date-date;
	//these line of code calculate the remaining time and calculate the day hour and minute
	//if reserved days no and count days number equal to then update the and remove the customer data from room file
 if(t_hr>hr)
 {
 	if(t_min>min)
 	{
 		t_hr=t_hr-hr;
 		t_min=t_min-min;
 		calculate=60*t_hr;
 		calculate+=t_min;
	 }
	 else{
	 		t_hr=t_hr-hr;
 		t_min=min-t_min;
 			calculate=60*t_hr;
 		calculate+=t_min;
	 	
	 }
 }
 else if(t_hr<hr)
 {
  if(t_min>min)
  {
  		t_hr=hr-t_hr;
  		t_min=min-t_min;
  			calculate=60*t_hr;
 		calculate+=t_min;
  		
  }
  else{
  		t_hr=hr-t_hr;
  		t_min=t_min-min;
  		calculate=60*t_hr;
 		calculate+=t_min;
  }
 }
 calculate1=days*24*60;
 calculate+=calculate1;
 
 left_d=calculate/(24*3600);
 time_h=calculate%(24*3600);
 
 h=time_h/3600;
 m=time_h%3600;
 time_m=m/60;
	left_d=reserve_days_no-days;
	if(d==1)
	{
	//if time is remaining
	if(days<reserve_days_no)
	{
			cout<<"NAME:"<<f_name<<endl;
			cout<<"FLOOR:"<<Floor<<endl;
			cout<<"ROOM:"<<Room_no<<endl;
			cout<<"RREMAINING TIME:"<<left_d<<"DAYS:"<<":"<<h<<"HOUR:"<<":"<<time_m<<"MIN:"<<endl;
			cout<<endl<<endl;	
	}
}
//if time complete then remove the data fromm file
		if(days>=reserve_days_no)
		{
			//when time coomplete 
	f7<<f_name<<"\t"<<l_name<<"\t"<<gender<<"\t"<<age<<"\t"<<room_type<<"\t"<<id<<"\t"<<balance<<"\t"<<reserve_days_no<<"\t"<<Floor<<"\t"<<Room_no<<"\t"<<hr<<"\t"<<min<<"\t"<<Month<<"\t"<<date<<endl ;

			
			age=0;
			char f_name[]="";
            char l_name[]="";
            char gender[]="";
			id=0;
			balance=0;
			reserve_days_no=0;
			Floor=0;
			count_days=0;
			remove(filename.c_str());//room file data remove
			rename("temp.dat",filename.c_str());//and again create new file
		}
	
		}
			file.close();

}
};
class suite:public Room{//fifth derived class
	char f_name[50];
	char l_name[50];
	int age;
	char gender[10];
	long long int id;
		int charge;
	int balance;
	int reserve_days_no;
	int Floor;
	int hr,min;
	int date;
	int Month;
	int count_days;



	public:
		suite()
		{
			char f_name[]="";
			char l_name[]="";
			char gender[]="";
			age=0;
			
			id=0;
			balance=0;
			reserve_days_no=0;
			charge=5000;
			Floor=0;
		}
		

		int input(int floor,int room_no,int t_date,int month,fstream &f6,fstream &file)
		{
		if(id==0)
		{

	
		cout<<"ENTER CUSTOMER FIRST NAME:"<<endl;
		cin>>f_name;

     	cout<<"ENTER CUSTOMER LAST NAME:"<<endl;
    	cin>>l_name;
		cout<<"ENTER CUSTOMER AGE:"<<endl;
		cin>>age;
		cout<<"ENTER CUSTOMER GENDER:"<<endl;
		cin>>gender;
		cout<<"ENTER CUSTOMER ID:"<<endl;
		cin>>id;
	
		cout<<"ENTER RESERVE DAYS NO:"<<endl;
		cin>>reserve_days_no;
		balance=charge*reserve_days_no;
		Floor=floor;
		Room_no=room_no;
		cout<<"ENTER TIME IN HOUR AND MIN:"<<endl;
		cin>>hr>>min;
		date=t_date;
		Month=month;
		cout<<"ENTER ROOM TYPE SUITE:"<<endl;
		cin>>room_type;;
		f6.write((char*)&f_name,sizeof(f_name));
		f6.write((char*)&l_name,sizeof(l_name));
		f6.write((char*)&gender,sizeof(gender));
		f6.write((char*)&age,sizeof(age));
        f6.write((char*)&room_type,sizeof(room_type));
    	f6.write((char*)&id,sizeof(id));
		f6.write((char*)&balance,sizeof(balance));
		f6.write((char*)&reserve_days_no,sizeof(reserve_days_no));
		f6.write((char*)&Floor,sizeof(Floor));
		f6.write((char*)&Room_no,sizeof(Room_no));
		f6.write((char*)&hr,sizeof(hr));
		f6.write((char*)&min,sizeof(min));
		f6.write((char*)&Month,sizeof(Month));
		f6.write((char*)&date,sizeof(date));
		
		
		file.write((char*)&f_name,sizeof(f_name));
		file.write((char*)&l_name,sizeof(l_name));
		file.write((char*)&gender,sizeof(gender));
		file.write((char*)&age,sizeof(age));
        file.write((char*)&room_type,sizeof(room_type));
    	file.write((char*)&id,sizeof(id));
		file.write((char*)&balance,sizeof(balance));
		file.write((char*)&reserve_days_no,sizeof(reserve_days_no));
		file.write((char*)&Floor,sizeof(Floor));
		file.write((char*)&Room_no,sizeof(Room_no));
		file.write((char*)&hr,sizeof(hr));
		file.write((char*)&min,sizeof(min));
		file.write((char*)&Month,sizeof(Month));
		file.write((char*)&date,sizeof(date));
		bill();
	}
	else{
			cout<<"ROOM ALREADY RESERVE CHOOSE ANOTHER ROOM:"<<endl<<endl<<endl;
	    }
		file.close();
		}
		int output(fstream &file)
		{
		
		file.read((char*)&f_name,sizeof(f_name));
		file.read((char*)&l_name,sizeof(l_name));
		file.read((char*)&gender,sizeof(gender));
		file.read((char*)&age,sizeof(age));
        file.read((char*)&room_type,sizeof(room_type));
    	file.read((char*)&id,sizeof(id));
		file.read((char*)&balance,sizeof(balance));
		file.read((char*)&reserve_days_no,sizeof(reserve_days_no));
		file.read((char*)&Floor,sizeof(Floor));
		file.read((char*)&Room_no,sizeof(Room_no));
		file.read((char*)&hr,sizeof(hr));
		file.read((char*)&min,sizeof(min));
		file.read((char*)&Month,sizeof(Month));
		file.read((char*)&date,sizeof(date));
		
		
		if(age!=0)
		{
				cout<<"NAME:="<<f_name<<" "<<l_name<<endl;
				cout<<"GENDER:"<<gender<<endl;
				cout<<"AGE:"<<age<<endl;
				cout<<"ROOM_TYPE:"<<room_type<<endl;
				cout<<"CUSTOMER_ID_CARD:"<<id<<endl;
				cout<<"ROOM_BALANCE:"<<balance<<endl;
				cout<<"RESERVE_DAYS:"<<reserve_days_no<<endl;
				cout<<"FLOOR:"<<Floor<<endl;
				cout<<"ROOM_NO:"<<Room_no<<endl;
				cout<<"DATE:"<<date<<endl;
				cout<<"HOURE:MIN"<<hr<<":"<<min<<endl;
				cout<<endl<<endl;
				
		}
		file.close();
		}
		int check(int floor,int room_no,fstream &file)//check room availibility
		{
		
			string w1 = "seq";
string filename;
stringstream str;
str << w1 << floor << room_no << ".dat";
filename = str.str();
file.open( filename.c_str(),ios::out|ios::binary );
				
		file.read((char*)&f_name,sizeof(f_name));
		file.read((char*)&l_name,sizeof(l_name));
		file.read((char*)&gender,sizeof(gender));
		file.read((char*)&age,sizeof(age));
        file.read((char*)&room_type,sizeof(room_type));
    	file.read((char*)&id,sizeof(id));
		file.read((char*)&balance,sizeof(balance));
		file.read((char*)&reserve_days_no,sizeof(reserve_days_no));
		file.read((char*)&Floor,sizeof(Floor));
		file.read((char*)&Room_no,sizeof(Room_no));
		file.read((char*)&hr,sizeof(hr));
		file.read((char*)&min,sizeof(min));
		file.read((char*)&Month,sizeof(Month));
		file.read((char*)&date,sizeof(date));
			if(id==0)
			{
				cout<<"Floor="<<floor<<"\t"<<"Room="<<room_no<<"\t";
			}
			cout<<endl;
			
			file.close();
		}
			int bill()
		{
			cout<<endl;
			cout<<"THANKYOU FOR CHOOSE OUR HOTEL SIR/MADAM"<<endl;
			cout<<"NAME:"<<f_name<<" "<<l_name<<endl;
			cout<<"ROOM TYPE:"<<room_type<<endl;
			cout<<"RESERVED DAYS:"<<reserve_days_no<<endl;
			cout<<"ROOM CHARGES FOR 24 HOURS:"<<charge<<endl;
			cout<<"YOUR BILL IS:"<<balance<<endl<<endl;
			cout<<"HAVE A NICE DAY SIR/MADAM:"<<endl;
			
		}
		int update(int t_hr,int t_min,int t_date,int d,fstream &f7,int f,int r,fstream &file)
		{
				string w1 = "seq";
string filename;
stringstream str;
str << w1 << f << r << ".dat";
filename = str.str();
file.open( filename.c_str(),ios::in|ios::out|ios::binary );
				fstream file_del;
				file_del.open("temp.dat",ios::out|ios::binary);
				
		file.read((char*)&f_name,sizeof(f_name));
		file.read((char*)&l_name,sizeof(l_name));
		file.read((char*)&gender,sizeof(gender));
		file.read((char*)&age,sizeof(age));
        file.read((char*)&room_type,sizeof(room_type));
    	file.read((char*)&id,sizeof(id));
		file.read((char*)&balance,sizeof(balance));
		file.read((char*)&reserve_days_no,sizeof(reserve_days_no));
		file.read((char*)&Floor,sizeof(Floor));
		file.read((char*)&Room_no,sizeof(Room_no));
		file.read((char*)&hr,sizeof(hr));
		file.read((char*)&min,sizeof(min));
		file.read((char*)&Month,sizeof(Month));
		file.read((char*)&date,sizeof(date));
			
if(age!=0)
{
			
	int days;int calculate,calculate1;
	int left_d;
	int time_h;
	int time_m;
	int h,m;
	days=t_date-date;
	//these line of code calculate the remaining time and calculate the day hour and minute
	//if reserved days no and count days number equal to then update the and remove the customer data from room file
 if(t_hr>hr)
 {
 	if(t_min>min)
 	{
 		t_hr=t_hr-hr;
 		t_min=t_min-min;
 		calculate=60*t_hr;
 		calculate+=t_min;
	 }
	 else{
	 		t_hr=t_hr-hr;
 		t_min=min-t_min;
 			calculate=60*t_hr;
 		calculate+=t_min;
	 	
	 }
 }
 else if(t_hr<hr)
 {
  if(t_min>min)
  {
  		t_hr=hr-t_hr;
  		t_min=min-t_min;
  			calculate=60*t_hr;
 		calculate+=t_min;
  		
  }
  else{
  		t_hr=hr-t_hr;
  		t_min=t_min-min;
  		calculate=60*t_hr;
 		calculate+=t_min;
  }
 }
 calculate1=days*24*60;
 calculate+=calculate1;
 
 left_d=calculate/(24*3600);
 time_h=calculate%(24*3600);
 
 h=time_h/3600;
 m=time_h%3600;
 time_m=m/60;
	left_d=reserve_days_no-days;
	if(d==1)
	{
	//if time is remaining
	if(days<reserve_days_no)
	{
			cout<<"NAME:"<<f_name<<endl;
			cout<<"FLOOR:"<<Floor<<endl;
			cout<<"ROOM:"<<Room_no<<endl;
			cout<<"RREMAINING TIME:"<<left_d<<"DAYS:"<<":"<<h<<"HOUR:"<<":"<<time_m<<"MIN:"<<endl;
			cout<<endl<<endl;	
	}
}
//if time complete then remove the data fromm file
		if(days>=reserve_days_no)
		{
			//when time coomplete
	f7<<f_name<<"\t"<<l_name<<"\t"<<gender<<"\t"<<age<<"\t"<<room_type<<"\t"<<id<<"\t"<<balance<<"\t"<<reserve_days_no<<"\t"<<Floor<<"\t"<<Room_no<<"\t"<<hr<<"\t"<<min<<"\t"<<Month<<"\t"<<date<<endl ;

			
			age=0;
			char f_name[]="";
            char l_name[]="";
            char gender[]="";
			id=0;
			balance=0;
			reserve_days_no=0;
			Floor=0;
			count_days=0;
			remove(filename.c_str());//room file data remove
			rename("temp.dat",filename.c_str());//and again create new file
		}
	}
	file.close();
		}

	
};

int Report()//its a global function that tell about the report date,weekly and monthly wise record show if manager want to  check
{
	char f_name[50];
	char l_name[50];
	char room_type[20];
	int age;
	char gender[10];
	long long int id;
	int balance;
	int reserve_days_no;
	int Floor;
	int hr,min;
	int date;
	int Month;
	int count_days;
    int  found=0;
	int Room_no;
	int time;
	int remaning_time;
	int daily,weekly,month,yearly;
	int choice,e;
		fstream f6;
		f6.open("customers.dat",ios::in|ios::binary);
	
        f6.read((char*)&f_name,sizeof(f_name));
        f6.read((char*)&l_name,sizeof(l_name));
        f6.read((char*)&gender,sizeof(gender));
        f6.read((char*)&age,sizeof(age));
        f6.read((char*)&room_type,sizeof(room_type));
         
		f6.read((char*)&id,sizeof(id));
		f6.read((char*)&balance,sizeof(balance));
		f6.read((char*)&reserve_days_no,sizeof(reserve_days_no));
		f6.read((char*)&Floor,sizeof(Floor));
		f6.read((char*)&Room_no,sizeof(Room_no));
		f6.read((char*)&hr,sizeof(hr));
		f6.read((char*)&min,sizeof(min));
		f6.read((char*)&Month,sizeof(Month));
		f6.read((char*)&date,sizeof(date));
	
	cout<<"PRESS 1 FOR DAILY BASE OR DATE WISE RECORD SHOW:"<<endl;
	cout<<"PRESS 2 FOR WEEKLY BASE RECORD SHOW:"<<endl;
	cout<<"PRESS 3  FOR MONTHLY BASE RECORD SHOW:"<<endl;
	cout<<"ENTER YOUR CHOICE:"<<endl;
	cin>>e;
	
	if(e==1)//date wise record show check specific date record
	{
		cout<<"ENTER TODAY DATE FOR CHECK HOW MANY CUSTOMER VISIT TODAY"<<endl;
		cin>>daily;
		
		while(!f6.eof())
		{
			if(daily==date)
			{
				cout<<"NAME:="<<f_name<<" "<<l_name<<endl;
				cout<<"GENDER:"<<gender<<endl;
				cout<<"AGE:"<<age<<endl;
				cout<<"ROOM_TYPE:"<<room_type<<endl;
				cout<<"CUSTOMER_ID_CARD:"<<id<<endl;
				cout<<"ROOM_BALANCE:"<<balance<<endl;
				cout<<"RESERVE_DAYS:"<<reserve_days_no<<endl;
				cout<<"FLOOR:"<<Floor<<endl;
				cout<<"ROOM_NO:"<<Room_no<<endl;
				cout<<"DATE:"<<date<<endl;
				cout<<"MONTH:"<<Month<<endl;
				cout<<"HOURE:MIN"<<hr<<":"<<min<<endl;
             	cout<<endl<<endl;
             	found=1;
			}
			
        f6.read((char*)&f_name,sizeof(f_name));
        f6.read((char*)&l_name,sizeof(l_name));
        f6.read((char*)&gender,sizeof(gender));
        f6.read((char*)&age,sizeof(age));
        f6.read((char*)&room_type,sizeof(room_type));
         
		f6.read((char*)&id,sizeof(id));
		f6.read((char*)&balance,sizeof(balance));
		f6.read((char*)&reserve_days_no,sizeof(reserve_days_no));
		f6.read((char*)&Floor,sizeof(Floor));
		f6.read((char*)&Room_no,sizeof(Room_no));
		f6.read((char*)&hr,sizeof(hr));
		f6.read((char*)&min,sizeof(min));
		f6.read((char*)&Month,sizeof(Month));
		f6.read((char*)&date,sizeof(date));
	}
	if(found==0)
	{
		cout<<"RECORD NOT FOUND:"<<endl;
	}
	}
	else if(e==2)//weekly record check
	{
		cout<<"ENTER DATE WHEN YOU WANT TO CHECK RECORD FOR A WEEK HOW MANY CUSTOMERS VISIT HOTEL:"<<endl;
		cin>>daily;
		cout<<"ENTER MONTH WHICH WEEK ARE YOU WANT TO CHECK"<<endl;
		cin>>month;
		weekly=1;
		while(!f6.eof())
		{
			if(daily==date&&month==Month&&weekly<=7)
			{
				cout<<"NAME:="<<f_name<<" "<<l_name<<endl;
				cout<<"GENDER:"<<gender<<endl;
				cout<<"AGE:"<<age<<endl;
				cout<<"ROOM_TYPE:"<<room_type<<endl;
				cout<<"CUSTOMER_ID_CARD:"<<id<<endl;
				cout<<"ROOM_BALANCE:"<<balance<<endl;
				cout<<"RESERVE_DAYS:"<<reserve_days_no<<endl;
				cout<<"FLOOR:"<<Floor<<endl;
				cout<<"ROOM_NO:"<<Room_no<<endl;
				cout<<"DATE:"<<date<<endl;
				cout<<"MONTH:"<<Month<<endl;
				cout<<"HOURE:MIN"<<hr<<":"<<min<<endl;
				daily++;
				weekly++;
			   	cout<<endl<<endl;
			    found=1;
			}
			
        f6.read((char*)&f_name,sizeof(f_name));
        f6.read((char*)&l_name,sizeof(l_name));
        f6.read((char*)&gender,sizeof(gender));
        f6.read((char*)&age,sizeof(age));
        f6.read((char*)&room_type,sizeof(room_type));
         
		f6.read((char*)&id,sizeof(id));
		f6.read((char*)&balance,sizeof(balance));
		f6.read((char*)&reserve_days_no,sizeof(reserve_days_no));
		f6.read((char*)&Floor,sizeof(Floor));
		f6.read((char*)&Room_no,sizeof(Room_no));
		f6.read((char*)&hr,sizeof(hr));
		f6.read((char*)&min,sizeof(min));
		f6.read((char*)&Month,sizeof(Month));
		f6.read((char*)&date,sizeof(date));
			
			
			
		}
			if(found==0)
	{
		cout<<"RECORD NOT FOUND:"<<endl;
	}
	}
	
	else if(e==3)//monthly report generate for a specific month
	{
		cout<<"ENTER MONTH NUMBER FOR CHECKING THE WHOLE RECORD OF THIS MONTH:"<<endl;
		cin>>month;
		
			while(!f6.eof())
		{
			if(month==Month)
			{
				cout<<"NAME:="<<f_name<<" "<<l_name<<endl;
				cout<<"GENDER:"<<gender<<endl;
				cout<<"AGE:"<<age<<endl;
				cout<<"ROOM_TYPE:"<<room_type<<endl;
				cout<<"CUSTOMER_ID_CARD:"<<id<<endl;
				cout<<"ROOM_BALANCE:"<<balance<<endl;
				cout<<"RESERVE_DAYS:"<<reserve_days_no<<endl;
				cout<<"FLOOR:"<<Floor<<endl;
				cout<<"ROOM_NO:"<<Room_no<<endl;
				cout<<"DATE:"<<date<<endl;
				cout<<"MONTH:"<<Month<<endl;
				cout<<"HOURE:MIN"<<hr<<":"<<min<<endl;
				cout<<endl<<endl;
				found=1;
			}
			
        f6.read((char*)&f_name,sizeof(f_name));
        f6.read((char*)&l_name,sizeof(l_name));
        f6.read((char*)&gender,sizeof(gender));
        f6.read((char*)&age,sizeof(age));
        f6.read((char*)&room_type,sizeof(room_type));
         
		f6.read((char*)&id,sizeof(id));
		f6.read((char*)&balance,sizeof(balance));
		f6.read((char*)&reserve_days_no,sizeof(reserve_days_no));
		f6.read((char*)&Floor,sizeof(Floor));
		f6.read((char*)&Room_no,sizeof(Room_no));
		f6.read((char*)&hr,sizeof(hr));
		f6.read((char*)&min,sizeof(min));
		f6.read((char*)&Month,sizeof(Month));
		f6.read((char*)&date,sizeof(date));
			
		
		}
			if(found==0)
	{
		cout<<"RECORD NOT FOUND:"<<endl;
	}
	}
	f6.close();
			
}
int read_complete_file()//read complete file record if manager check whole record from start to now.
{
	char f_name[50];
	char l_name[50];
	char room_type[20];
	int age;
	char gender[10];
	long long int id;
	int balance;
	int reserve_days_no;
	int Floor;
	int hr,min;
	int Room_no;
	int date;
	int Month;
	fstream f6;
		f6.open("customers.dat",ios::in|ios::binary);
	

         f6.read((char*)&f_name,sizeof(f_name));
         f6.read((char*)&l_name,sizeof(l_name));
         f6.read((char*)&gender,sizeof(gender));
         f6.read((char*)&age,sizeof(age));
         f6.read((char*)&room_type,sizeof(room_type));
         
		f6.read((char*)&id,sizeof(id));
		f6.read((char*)&balance,sizeof(balance));
		f6.read((char*)&reserve_days_no,sizeof(reserve_days_no));
		f6.read((char*)&Floor,sizeof(Floor));
		f6.read((char*)&Room_no,sizeof(Room_no));
		f6.read((char*)&hr,sizeof(hr));
		f6.read((char*)&min,sizeof(min));
		f6.read((char*)&Month,sizeof(Month));
		f6.read((char*)&date,sizeof(date));

	while(!f6.eof())
	{
		        cout<<"NAME:="<<f_name<<" "<<l_name<<endl;
				cout<<"GENDER:"<<gender<<endl;
				cout<<"AGE:"<<age<<endl;
				cout<<"ROOM_TYPE:"<<room_type<<endl;
				cout<<"CUSTOMER_ID_CARD:"<<id<<endl;
				cout<<"ROOM_BALANCE:"<<balance<<endl;
				cout<<"RESERVE_DAYS:"<<reserve_days_no<<endl;
				cout<<"FLOOR:"<<Floor<<endl;
				cout<<"ROOM_NO:"<<Room_no<<endl;
				cout<<"DATE:"<<date<<endl;
				cout<<"MONTH:"<<Month<<endl;
				cout<<"HOURE:MIN"<<hr<<":"<<min<<endl;
	            cout<<endl<<endl;
         
        f6.read((char*)&f_name,sizeof(f_name));
        f6.read((char*)&l_name,sizeof(l_name));
        f6.read((char*)&gender,sizeof(gender));
        f6.read((char*)&age,sizeof(age));
        f6.read((char*)&room_type,sizeof(room_type));
         
		f6.read((char*)&id,sizeof(id));
		f6.read((char*)&balance,sizeof(balance));
		f6.read((char*)&reserve_days_no,sizeof(reserve_days_no));
		f6.read((char*)&Floor,sizeof(Floor));
		f6.read((char*)&Room_no,sizeof(Room_no));
		f6.read((char*)&hr,sizeof(hr));
		f6.read((char*)&min,sizeof(min));
		f6.read((char*)&Month,sizeof(Month));
		f6.read((char*)&date,sizeof(date));
	
	}
	f6.close();

}
int search()//this function search a specific person record ,room record,
{
	char f_name[50];
	char l_name[50];
	char room_type[20];
	int age;
	char gender[10];
	long long int id;
	int balance;
	int reserve_days_no;
	int Floor;
	int hr,min;
	int Room_no;
	int date;
	int Month;
    string name;
    int id_card;
    int floor;
   string room;
   int found=0;
    int e;
    do{
    		fstream f6;
		f6.open("customers.dat",ios::in|ios::binary);
    cout<<"ENTER 1 FOR NAME SEARCH:"<<endl;
    cout<<"ENTER 2 FOR ID_CARD SEARCH:"<<endl;
    cout<<"ENTER 3 FOR FLOOR SEARCH:"<<endl;
    cout<<"ENTER 4 FOR ROOM_TYPE SEARCH:"<<endl;
    cout<<"PRESS 0 FOR EXIT:"<<endl;
	cout<<"ENTER CHOICE:"<<endl;
	cin>>e;
        f6.read((char*)&f_name,sizeof(f_name));
        f6.read((char*)&l_name,sizeof(l_name));
        f6.read((char*)&gender,sizeof(gender));
        f6.read((char*)&age,sizeof(age));
        f6.read((char*)&room_type,sizeof(room_type));
         
		f6.read((char*)&id,sizeof(id));
		f6.read((char*)&balance,sizeof(balance));
		f6.read((char*)&reserve_days_no,sizeof(reserve_days_no));
		f6.read((char*)&Floor,sizeof(Floor));
		f6.read((char*)&Room_no,sizeof(Room_no));
		f6.read((char*)&hr,sizeof(hr));
		f6.read((char*)&min,sizeof(min));
		f6.read((char*)&Month,sizeof(Month));
		f6.read((char*)&date,sizeof(date));

		

if(e==1)//specific record find with name
{
cout<<"ENTER CUSTOMER NAME:"<<endl;
cin>>name;	
	while(!f6.eof())
	{
	if(name==f_name)
	{
		cout<<endl;
		cout<<"YOUR SEARCH NAME DATA IS:"<<endl<<endl;
		
	
	            cout<<"NAME:="<<f_name<<" "<<l_name<<endl;
				cout<<"GENDER:"<<gender<<endl;
				cout<<"AGE:"<<age<<endl;
				cout<<"ROOM_TYPE:"<<room_type<<endl;
				cout<<"CUSTOMER_ID_CARD:"<<id<<endl;
				cout<<"ROOM_BALANCE:"<<balance<<endl;
				cout<<"RESERVE_DAYS:"<<reserve_days_no<<endl;
				cout<<"FLOOR:"<<Floor<<endl;
				cout<<"ROOM_NO:"<<Room_no<<endl;
				cout<<"DATE:"<<date<<endl;
				cout<<"MONTH:"<<Month<<endl;
				cout<<"HOURE:MIN"<<hr<<":"<<min<<endl;
	          	cout<<endl<<endl;
	          	found=1;
}
		       
         
        f6.read((char*)&f_name,sizeof(f_name));
        f6.read((char*)&l_name,sizeof(l_name));
        f6.read((char*)&gender,sizeof(gender));
        f6.read((char*)&age,sizeof(age));
        f6.read((char*)&room_type,sizeof(room_type));
         
		f6.read((char*)&id,sizeof(id));
		f6.read((char*)&balance,sizeof(balance));
		f6.read((char*)&reserve_days_no,sizeof(reserve_days_no));
		f6.read((char*)&Floor,sizeof(Floor));
		f6.read((char*)&Room_no,sizeof(Room_no));
		f6.read((char*)&hr,sizeof(hr));
		f6.read((char*)&min,sizeof(min));
		f6.read((char*)&Month,sizeof(Month));
		f6.read((char*)&date,sizeof(date));

		
	}
		if(found==0)
	{
		cout<<"RECORD NOT FOUND:"<<endl;
	}
}
else if(e==2)//specific record find with customer id card
{
	cout<<"ENTERR CUSTOMER ID_CARD NUMBER YOU WANTT TO FIND IN RECORD:"<<endl;
	cin>>id_card;
		while(!f6.eof())
	{
	if(id_card==id)
	{
			cout<<endl;
		cout<<"YOUR SEARCH ID DATA IS:"<<endl<<endl;
		
	            cout<<"NAME:="<<f_name<<" "<<l_name<<endl;
				cout<<"GENDER:"<<gender<<endl;
				cout<<"AGE:"<<age<<endl;
				cout<<"ROOM_TYPE:"<<room_type<<endl;
				cout<<"CUSTOMER_ID_CARD:"<<id<<endl;
				cout<<"ROOM_BALANCE:"<<balance<<endl;
				cout<<"RESERVE_DAYS:"<<reserve_days_no<<endl;
				cout<<"FLOOR:"<<Floor<<endl;
				cout<<"ROOM_NO:"<<Room_no<<endl;
				cout<<"DATE:"<<date<<endl;
				cout<<"MONTH:"<<Month<<endl;
				cout<<"HOURE:MIN"<<hr<<":"<<min<<endl;
	           	cout<<endl<<endl;
	           	found=1;
	}
		       
         
        f6.read((char*)&f_name,sizeof(f_name));
        f6.read((char*)&l_name,sizeof(l_name));
        f6.read((char*)&gender,sizeof(gender));
        f6.read((char*)&age,sizeof(age));
        f6.read((char*)&room_type,sizeof(room_type));
         
		f6.read((char*)&id,sizeof(id));
		f6.read((char*)&balance,sizeof(balance));
		f6.read((char*)&reserve_days_no,sizeof(reserve_days_no));
		f6.read((char*)&Floor,sizeof(Floor));
		f6.read((char*)&Room_no,sizeof(Room_no));
		f6.read((char*)&hr,sizeof(hr));
		f6.read((char*)&min,sizeof(min));
		f6.read((char*)&Month,sizeof(Month));
		f6.read((char*)&date,sizeof(date));

		
	}
		if(found==0)
	{
		cout<<"RECORD NOT FOUND:"<<endl;
	}
	
}
else if(e==3)//specific floor record
{
	cout<<"ENTER FLOOR NUMBER YOU WANT TO FIND RECORD :"<<endl;
	cin>>floor;
		while(!f6.eof())
	{
	if(floor==Floor)
	{
			cout<<endl;
		cout<<"YOUR SEARCH FLOOR DATA IS:"<<endl<<endl;
		
	            cout<<"NAME:="<<f_name<<" "<<l_name<<endl;
				cout<<"GENDER:"<<gender<<endl;
				cout<<"AGE:"<<age<<endl;
				cout<<"ROOM_TYPE:"<<room_type<<endl;
				cout<<"CUSTOMER_ID_CARD:"<<id<<endl;
				cout<<"ROOM_BALANCE:"<<balance<<endl;
				cout<<"RESERVE_DAYS:"<<reserve_days_no<<endl;
				cout<<"FLOOR:"<<Floor<<endl;
				cout<<"ROOM_NO:"<<Room_no<<endl;
				cout<<"DATE:"<<date<<endl;
				cout<<"MONTH:"<<Month<<endl;
				cout<<"HOURE:MIN"<<hr<<":"<<min<<endl;
		        cout<<endl<<endl;
		        found=1;
	}
		       
         
        f6.read((char*)&f_name,sizeof(f_name));
        f6.read((char*)&l_name,sizeof(l_name));
        f6.read((char*)&gender,sizeof(gender));
        f6.read((char*)&age,sizeof(age));
        f6.read((char*)&room_type,sizeof(room_type));
         
		f6.read((char*)&id,sizeof(id));
		f6.read((char*)&balance,sizeof(balance));
		f6.read((char*)&reserve_days_no,sizeof(reserve_days_no));
		f6.read((char*)&Floor,sizeof(Floor));
		f6.read((char*)&Room_no,sizeof(Room_no));
		f6.read((char*)&hr,sizeof(hr));
		f6.read((char*)&min,sizeof(min));
		f6.read((char*)&Month,sizeof(Month));
		f6.read((char*)&date,sizeof(date));

		
	}
		if(found==0)
	{
		cout<<"RECORD NOT FOUND:"<<endl;
	}
}
else if(e==4)//specific room record
{
	cout<<"ENTER ROOM NAME:SUITE:STANDARD:MODERATE:SUPERIOR:JUNIOR:"<<endl;
	cin>>room;
		while(!f6.eof())
	{
	if(room==room_type)
	{
			cout<<endl;
		cout<<"YOUR SEARCH ROOM TYPE DATA IS:"<<endl<<endl;
		
	            cout<<"NAME:="<<f_name<<" "<<l_name<<endl;
				cout<<"GENDER:"<<gender<<endl;
				cout<<"AGE:"<<age<<endl;
				cout<<"ROOM_TYPE:"<<room_type<<endl;
				cout<<"CUSTOMER_ID_CARD:"<<id<<endl;
				cout<<"ROOM_BALANCE:"<<balance<<endl;
				cout<<"RESERVE_DAYS:"<<reserve_days_no<<endl;
				cout<<"FLOOR:"<<Floor<<endl;
				cout<<"ROOM_NO:"<<Room_no<<endl;
				cout<<"DATE:"<<date<<endl;
				cout<<"MONTH:"<<Month<<endl;
				cout<<"HOURE:MIN"<<hr<<":"<<min<<endl;
	            cout<<endl<<endl;
	            found=1;
	}
		       
         
        f6.read((char*)&f_name,sizeof(f_name));
        f6.read((char*)&l_name,sizeof(l_name));
        f6.read((char*)&gender,sizeof(gender));
        f6.read((char*)&age,sizeof(age));
        f6.read((char*)&room_type,sizeof(room_type));
         
		f6.read((char*)&id,sizeof(id));
		f6.read((char*)&balance,sizeof(balance));
		f6.read((char*)&reserve_days_no,sizeof(reserve_days_no));
		f6.read((char*)&Floor,sizeof(Floor));
		f6.read((char*)&Room_no,sizeof(Room_no));
		f6.read((char*)&hr,sizeof(hr));
		f6.read((char*)&min,sizeof(min));
		f6.read((char*)&Month,sizeof(Month));
		f6.read((char*)&date,sizeof(date));

		
	}
		if(found==0)
	{
		cout<<"RECORD NOT FOUND:"<<endl;
	}
}



f6.close();	
}while(e!=0);
	
}
int skip_room_data()//global function when customer leave the hotel the user leaving date and other data store in this file
{
	char f_name[50];
	char l_name[50];
	char room_type[20];
	int age;
	char gender[10];
	long long int id;
	int balance;
	int reserve_days_no;
	int Floor;
	int hr,min;
	int Room_no;
	int date;
	int Month;
    int t_date;
    	fstream f7;
		f7.open("skipping.txt",ios::in);
    
    	f7>>f_name>>l_name>>gender>>age>>room_type>>id>>balance>>reserve_days_no>>Floor>>Room_no>>hr>>min>>Month>>date; 

		while(!f7.eof())
		{
			if(age!=0)
			{
			
			    cout<<"NAME:="<<f_name<<" "<<l_name<<endl;
				cout<<"GENDER:"<<gender<<endl;
				cout<<"AGE:"<<age<<endl;
				cout<<"ROOM_TYPE:"<<room_type<<endl;
				cout<<"CUSTOMER_ID_CARD:"<<id<<endl;
				cout<<"ROOM_BALANCE:"<<balance<<endl;
				cout<<"RESERVE_DAYS:"<<reserve_days_no<<endl;
				cout<<"FLOOR:"<<Floor<<endl;
				cout<<"ROOM_NO:"<<Room_no<<endl;
				cout<<"DATE WHEN ROOM RESERVED:"<<date<<endl;
				cout<<"DATE WHEN CUSTOMER SKIP HOTEL:"<<t_date<<endl;
				cout<<"MONTH:"<<Month<<endl;
				cout<<"HOURE:MIN"<<hr<<":"<<min<<endl;
	            cout<<endl<<endl;
	        }
	        f7>>f_name>>l_name>>gender>>age>>room_type>>id>>balance>>reserve_days_no>>Floor>>Room_no>>hr>>min>>Month>>date; 

		}
	
}

int main()//main body
{

int t_hr,t_min;//by default passing t_hr and t_min to check room availibility
int c,d,e;
int t_date;//by default passing today date 
int month;//by dfefault passing month
int choice;
fstream file,file1,file2;//files
/*each derived a same floor and same room number of array i use room pointer that point a speific number */
Room* hotel[5][50];//array of pointer of a base class use 2_D array for 5 floor and each floor have 50 rooms
standard b[5][10];/*its a derived class array of objject*/
moderate b1[5][10];
superior b2[5][10];
junior_suite b3[5][10];
suite b4[10][20];
int b5;//that is use for room  number because every floor
 	file1.open("customers.dat",ios::in|ios::out|ios::app|ios::binary);//customer file
 file2.open("skipping.txt",ios::in|ios::out|ios::app);
 

//use do while for repeating because the hotel use multiple time in one day and switch first day and start second day 
do{ 


cout<<"ENTER 0 IN DATE IF YOU WANT TO CLOSE MANAGEMENT:"<<endl;
cout<<"ENTER TODAY DATE:"<<endl;
cin>>t_date;
cout<<"ENTER MONTH:"<<endl;
cin>>month;

	
if((month>0&&month<=12)&&(t_date>0&&t_date<=31))//checking date and month
{
//again use do while for repeating for furture data because the hotel enter data mmany time in one day
do{
	
	cout<<"WELCOME TO THE HOTEL MANAGEMENT:"<<endl;
	cout<<"ENTER 1 FOR STANDARD ROOM RESERVE:"<<endl;
	cout<<"ENTER 2 FOR MODERATE ROOM RESERVE:"<<endl;
	cout<<"ENTER 3 FOR SUPERIOR ROOM RESERVE:"<<endl;
	cout<<"ENTER 4 FOR JUNIOR_SUITE ROOM RESERVE:"<<endl;
	cout<<"ENTER 5 FOR SUITE ROOM RESERVE:"<<endl;
	cout<<"ENTER 7 FOR REPORT CUSTOMER:"<<endl;
	cout<<"ENTER 8 FOR COMPLETE FILE VIEW:"<<endl;
	cout<<"ENTER 9 FOR SEAARCH DATA FROM FILE:"<<endl;
	cout<<"ENTER 10 FOR CHECK RECORD WHEN CUSTTOMER LEAVE HOTEL:"<<endl;
	
	cout<<"ENTTER CHHOICE:"<<endl;
	cin>>choice;
	
	
switch(choice)//use switch for room reserved and room data checking
{
case 1://operate standard room
		for(int i=1;i<=5;i++)
		{
			for(int j=1;j<=10;j++)
			{
				hotel[i][j]= &b[i][j];//assigning standard array of ojecct to array of pointer room or base class
			}
		}
		do{
		//again use do while for each room 
		cout<<"PRESS 1 FOR ROOM AVAILBILITY:"<<endl;
		cout<<"PRESS 2 FOR RESERVE ROOM:"<<endl;
		cout<<"PRESS 3 RESERVE ROOM DATA:"<<endl;
		cout<<"PRESS 4 FOR REMANING TIME OF RESERVED ROOM:"<<endl;
		cout<<"PRESS 0 FOR EXIT SUITE TYPE ROOM:"<<endl;
		cin>>e;
		if(e==1)//checking room availibility
		{
			cout<<"ENTER TIME IN HOUR AND IN MIN:"<<endl;
			cin>>t_hr>>t_min;
			for(int i=1;i<=5;i++)
			{
				for(int j=1;j<=10;j++)
				{
				
					hotel[i][j]->update(t_hr,t_min,t_date,1,file2,i,j,file);	//update room data before checking
					hotel[i][j]->check(i,j,file);//checking room vailibility
				}
			}
		}
		else if(e==2)//for reserving room
		{
					int a,b;//we use for room and floor nuumber select
					cout<<"ENTER FLOOR NO:"<<endl;
					cin>>a;
					cout<<"ENTER ROOM NO:"<<endl;
					cin>>b;
string w1 = "seq";
string filename;
stringstream str;
str << w1 << a << b << ".dat";
filename = str.str();
file.open( filename.c_str(),ios::out|ios::binary );
					hotel[a][b]->input(a,b,t_date,month,file1,file);
					
		}
		else if(e==3)///show output
		{
			for(int i=1;i<=5;i++)
			{
				
				for(int j=1;j<=10;j++)
				{
					string w1 = "seq";
string filename;
stringstream str;
str << w1 << i << j << ".dat";
filename = str.str();
file.open( filename.c_str(),ios::in|ios::binary );
					hotel[i][j]->output(file);					
				}
			}
		}
		else if(e==4)//use for to check time remainign oof customer that are stay in hotel
		{
				cout<<"ENTER TIME IN HOUR AND IN MIN:"<<endl;
			cin>>t_hr>>t_min;
			for(int i=1;i<=5;i++)
			{
				for(int j=1;j<=10;j++)
				{
					
					hotel[i][j]->update(t_hr,t_min,t_date,1,file2,i,j,file);					
				}
			}
		}
	}while(e!=0);

		break;
	case 2://use for a moderate type room
		
			for(int i=1;i<=5;i++)
		{    b5=1;
			for(int j=11;j<=20;j++)
			{
				hotel[i][j]= &b1[i][b5];//references the array of moderate into pointer of room array
				b5++;
			}
		}
		do{
		
		cout<<"PRESS 1 FOR ROOM AVAILBILITY:"<<endl;
		cout<<"PRESS 2 FOR RESERVE ROOM:"<<endl;
		cout<<"PRESS 3 RESERVE ROOM DATA:"<<endl;
		cout<<"PRESS 4 FOR REMANING TIME OF RESERVED ROOM:"<<endl;
		cout<<"PRESS 0 FOR EXIT SUITE TYPE ROOM:"<<endl;
		cin>>e;
		if(e==1)
		{
			cout<<"ENTER TIME IN HOUR AND IN MIN:"<<endl;
			cin>>t_hr>>t_min;
			for(int i=1;i<=5;i++)
			{
				for(int j=11;j<=20;j++)
				{
					
					hotel[i][j]->update(t_hr,t_min,t_date,1,file2,i,j,file);	
					hotel[i][j]->check(i,j,file);
				}
			}
		}
		else if(e==2)
		{
					int a,b;
					cout<<"ENTER FLOOR NO:"<<endl;
					cin>>a;
					cout<<"ENTER ROOM NO:"<<endl;
					cin>>b;
					string w1 = "seq";
string filename;
stringstream str;
str << w1 << a << b << ".dat";
filename = str.str();
file.open( filename.c_str(),ios::out|ios::binary );
					hotel[a][b]->input(a,b,t_date,month,file1,file);
					
		}
		else if(e==3)
		{
			for(int i=1;i<=5;i++)
			{
				for(int j=11;j<=20;j++)
				{
					string w1 = "seq";
string filename;
stringstream str;
str << w1 << i << j << ".dat";
filename = str.str();
file.open( filename.c_str(),ios::in|ios::binary );
					hotel[i][j]->output(file);					
				}
			}
		}
			else if(e==4)
		{
				cout<<"ENTER TIME IN HOUR AND IN MIN:"<<endl;
			cin>>t_hr>>t_min;
			for(int i=1;i<=5;i++)
			{
				for(int j=1;j<=10;j++)
				{
					
					hotel[i][j]->update(t_hr,t_min,t_date,1,file2,i,j,file);						
				}
			}
		}
	}while(e!=0);
		
		break;
	case 3:
			for(int i=1;i<=5;i++)
		{ b5=1;
			for(int j=21;j<=30;j++)
			{
				hotel[i][j]= &b2[i][b5];
				b5++;
			}
		}
		do{
		
		cout<<"PRESS 1 FOR ROOM AVAILBILITY:"<<endl;
		cout<<"PRESS 2 FOR RESERVE ROOM:"<<endl;
		cout<<"PRESS 3 RESERVE ROOM DATA:"<<endl;
		cout<<"PRESS 4 FOR REMANING TIME OF RESERVED ROOM:"<<endl;
		cout<<"PRESS 0 FOR EXIT SUITE TYPE ROOM:"<<endl;
		cin>>e;
		if(e==1)
		{
			cout<<"ENTER TIME IN HOUR AND IN MIN:"<<endl;
			cin>>t_hr>>t_min;
			for(int i=1;i<=5;i++)
			{
				for(int j=21;j<=30;j++)
				{
					
				hotel[i][j]->update(t_hr,t_min,t_date,1,file2,i,j,file);	
					hotel[i][j]->check(i,j,file);
				}
			}
		}
		else if(e==2)
		{
					int a,b;
					cout<<"ENTER FLOOR NO:"<<endl;
					cin>>a;
					cout<<"ENTER ROOM NO:"<<endl;
					cin>>b;
					string w1 = "seq";
string filename;
stringstream str;
str << w1 << a << b << ".dat";
filename = str.str();
file.open( filename.c_str(),ios::out|ios::binary );
					hotel[a][b]->input(a,b,t_date,month,file1,file);
					
		}
		else if(e==3)
		{
			for(int i=1;i<=5;i++)
			{
				for(int j=21;j<=30;j++)
				{
					string w1 = "seq";
string filename;
stringstream str;
str << w1 << i << j << ".dat";
filename = str.str();
file.open( filename.c_str(),ios::in|ios::binary );
					hotel[i][j]->output(file);					
				}
			}
		}
			else if(e==4)
		{
				cout<<"ENTER TIME IN HOUR AND IN MIN:"<<endl;
			cin>>t_hr>>t_min;
			for(int i=1;i<=5;i++)
			{
				for(int j=1;j<=10;j++)
				{
					
				hotel[i][j]->update(t_hr,t_min,t_date,1,file2,i,j,file);					
				}
			}
		}
	}while(e!=0);
		
		break;
	case 4:
				for(int i=1;i<=5;i++)
		{b5=1;
			for(int j=31;j<=40;j++)
			{
				hotel[i][j]= &b3[i][b5];
				b5++;
			}
		}
		do{
		
		cout<<"PRESS 1 FOR ROOM AVAILBILITY:"<<endl;
		cout<<"PRESS 2 FOR RESERVE ROOM:"<<endl;
		cout<<"PRESS 3 RESERVE ROOM DATA:"<<endl;
		cout<<"PRESS 4 FOR REMANING TIME OF RESERVED ROOM:"<<endl;
		cout<<"PRESS 0 FOR EXIT SUITE TYPE ROOM:"<<endl;
		cin>>e;
		if(e==1)
		{
			cout<<"ENTER TIME IN HOUR AND IN MIN:"<<endl;
			cin>>t_hr>>t_min;
			for(int i=1;i<=5;i++)
			{
				for(int j=31;j<=40;j++)
				{
					
				hotel[i][j]->update(t_hr,t_min,t_date,1,file2,i,j,file);	
					hotel[i][j]->check(i,j,file);
				}
			}
		}
		else if(e==2)
		{
					int a,b;
					cout<<"ENTER FLOOR NO:"<<endl;
					cin>>a;
					cout<<"ENTER ROOM NO:"<<endl;
					cin>>b;
					string w1 = "seq";
string filename;
stringstream str;
str << w1 << a << b << ".dat";
filename = str.str();
file.open( filename.c_str(),ios::out|ios::binary );
					hotel[a][b]->input(a,b,t_date,month,file1,file);
					
		}
		else if(e==3)
		{
			for(int i=1;i<=5;i++)
			{
				for(int j=31;j<=40;j++)
				{
					string w1 = "seq";
string filename;
stringstream str;
str << w1 << i << j << ".dat";
filename = str.str();
file.open( filename.c_str(),ios::in|ios::binary );
					hotel[i][j]->output(file);					
				}
			}
		}
			else if(e==4)
		{
				cout<<"ENTER TIME IN HOUR AND IN MIN:"<<endl;
			cin>>t_hr>>t_min;
			for(int i=1;i<=5;i++)
			{
				for(int j=1;j<=10;j++)
				{
					
					hotel[i][j]->update(t_hr,t_min,t_date,1,file2,i,j,file);					
				}
			}
		}
	}while(e!=0);
		break;
	case 5:
		for(int i=1;i<=5;i++)
		{b5=1;
			for(int j=41;j<=50;j++)
			{
				hotel[i][j]= &b4[i][b5];
				b5++;
			}
		}
		do{
		
		cout<<"PRESS 1 FOR ROOM AVAILBILITY:"<<endl;
		cout<<"PRESS 2 FOR RESERVE ROOM:"<<endl;
		cout<<"PRESS 3 RESERVE ROOM DATA:"<<endl;
		cout<<"PRESS 4 FOR REMANING TIME OF RESERVED ROOM:"<<endl;
		cout<<"PRESS 0 FOR EXIT SUITE TYPE ROOM:"<<endl;
		cin>>e;
		if(e==1)
		{
			cout<<"ENTER TIME IN HOUR AND IN MIN:"<<endl;
			cin>>t_hr>>t_min;
			for(int i=1;i<=5;i++)
			{
				for(int j=41;j<=50;j++)
				{
					
				hotel[i][j]->update(t_hr,t_min,t_date,1,file2,i,j,file);	
					hotel[i][j]->check(i,j,file);
				}
			}
		}
		else if(e==2)
		{
					int a,b;
					cout<<"ENTER FLOOR NO:"<<endl;
					cin>>a;
					cout<<"ENTER ROOM NO:"<<endl;
					cin>>b;
					string w1 = "seq";
string filename;
stringstream str;
str << w1 << a << b << ".dat";
filename = str.str();
file.open( filename.c_str(),ios::out|ios::binary );
					hotel[a][b]->input(a,b,t_date,month,file1,file);
					
		}
		else if(e==3)
		{
			for(int i=1;i<=5;i++)
			{
				for(int j=41;j<=50;j++)
				{
					string w1 = "seq";
string filename;
stringstream str;
str << w1 << i << j << ".dat";
filename = str.str();
file.open( filename.c_str(),ios::in|ios::binary );
					hotel[i][j]->output(file);					
				}
			}
		}
			else if(e==4)
		{
				cout<<"ENTER TIME IN HOUR AND IN MIN:"<<endl;
			cin>>t_hr>>t_min;
			for(int i=1;i<=5;i++)
			{
				for(int j=1;j<=10;j++)
				{
					
					hotel[i][j]->update(t_hr,t_min,t_date,1,file2,i,j,file);						
				}
			}
		}
	}while(e!=0);
		break;
	case 6:
		break;
	case 7:
	Report();//calling of report function
		break;
	case 8:
		read_complete_file();//calling function of read complete file
		break;
	case 9:
		search();//calling the function for to search record of a specific 
		break;
	case 10:
		skip_room_data();//calling after time complete customer record is save in this file
		break;
}



}while(choice!=0);

}
}while(t_date!=0);
}

