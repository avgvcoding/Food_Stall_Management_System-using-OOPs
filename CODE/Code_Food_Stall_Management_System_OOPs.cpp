#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<fstream>
#include<conio.h>
using namespace std;
void clrscr(){
	system("cls");
}
char un [20]; 
char sid [20];
char ft [20];
class Admin{

			private:
			int totitem, price[10];
			char name[20];
			char fmenu[10][10], retype[20];
			char passwd[20],rpasswd[20];
			protected:
			char mobile[15], mail[50], stallid[20];
			public:
			char restid[15];
			public:
			//this function authenticates the login of both admin and food stall portal users
			int login(){int i;
			
				if ((strcmp(::un, restid))==0){
				cout<<"\nEnter the Login Password : ";
				int len=0;
				len=strlen(passwd);
				char inputpasswd [20];
				for (i=0;i<len;i++){
				inputpasswd [i] =getch();
				cout<<"#";
				}
				inputpasswd[i]='\0';
				if ((strcmp(::un, restid) ==0) && (strcmp (passwd, inputpasswd) ==0))
				return 1;
				else
				return 0;}
				else
				return 0;}
			//This function helps in password recovery with the help of unique keyword provided by admin
			int recover ()
			{
			
			//cout<<"\nThe Input Username is "<<::un;
				char key [20];
				if (strcmp(::un, restid)==0)
				{
				cout<<"\nEnter the Unique Keyword Provided by Admin ) : ";
				cin>>key;
				if((strcmp (key,rpasswd)==0))
				{
				cout<<"\nYou are a Valid user." ;
				cout<<"\nYour Password is "<<passwd;
				cout<<"\nPlease Exit To Login Again ";
				return 1;
				}
				else
				return 0;
				}
				else
				return 0;
			}
			void getredata() {
    int i;
    cout << "Enter the Food Stall Name: ";
    cin.ignore();
    cin.getline(name, sizeof(name));

    cout << "Enter the Food Stall ID: ";
    cin >> restid;

    cout << "Enter the Mobile Number: ";
    cin.ignore();
    cin.getline(mobile, sizeof(mobile));

    cout << "Enter the E-Mail ID: ";
    cin.ignore();
    cin.getline(mail, sizeof(mail));

    cout << "Enter the Stall Unique ID: ";
    cin.ignore();
    cin.getline(stallid, sizeof(stallid));

    cout << "Food Stall Food Options Possible are:\n";
    cout << "1. South-Indian\n2. Continental\n3. Chinese\n4. Thailand\n5. Multiple" << endl;
    
    int foodtype;
    cout << "Enter the Food Stall Food Options Type (Unique Number): ";
    cin >> foodtype;

    switch (foodtype) {
        case 1:
            strcpy(retype, "South Indian");
            break;
        case 2:
            strcpy(retype, "Continental");
            break;
        case 3:
            strcpy(retype, "Chinese");
            break;
        case 4:
            strcpy(retype, "Thailand");
            break;
        default:
            strcpy(retype, "Multiple");
            break;
    }

    cout << "Enter the Total Food menu Items: ";
    cin >> totitem;

    for (i = 0; i < totitem; i++) {
        cout << "Enter the Food Item " << i + 1 << " Name: ";
        cin.ignore();
        cin.getline(fmenu[i], sizeof(fmenu[i]));

        cout << "Enter the Price of Food " << i + 1 << " INR: ";
        cin >> price[i];
    }

    cout << "Create Your Login Password: ";
    cin.ignore();
    cin.getline(passwd, sizeof(passwd));

    cout << "Enter the Unique Keyword to Recover Password: ";
    cin.ignore();
    cin.getline(rpasswd, sizeof(rpasswd));

    cout << "\nPlease note your UserName is ID, i.e. " << restid << "\n";
}
			void redisplay (){
			int i;
				cout<<"\nFood Stall Name                                                :"<<name;
				cout<<"\nFood Stall ID                                                  :"<<restid;
				cout<<"\nFood Stall Mobile No.                                          :"<<mobile;
				cout<<"\nFood Stall E-Mail ID                                           :"<<mail;
				cout<<"\nFood Stall Food Menu Total Items                               :"<<totitem;
				for (i=0;i<totitem; i++)  
				{
				
				cout<<"\n\tFood Item: "<<i+1<<": "<<fmenu [i] <<" :: Price :"<<price [i];}
				if (totitem==0)
				cout<<"( None Food Items Specified...)";}
			int reprofile()
			{
			
				if((strcmp(::un, restid)==0)){
				
				cout<<"\nFood Stall Name:"<<name;
				cout<<"\nFood Stall Mobile: "<<mobile;
				cout<<"\nFood Stall Food Items Type :"<<retype;
				return 1;}
				else
				return 0;
			}
			int knowremenu (){
			
				if((strcmp(::un, restid)==0))
				{
				
				cout<<"\nFood Stall Food Items Type: "<<retype;
				cout<<"\nFood Stall Total fmenus:- "<<totitem;
				for (int i=0;i<totitem;i++){
				cout<<"\n\t Food Item: "<<i+1<<": "<<fmenu [i] <<" ::Price: "<<price[i];}
				return 1;}
				else
				return 0;}
			void addremenu (){
			
			if ((strcmp(::un, restid)==0))
			{
			
				cout<<"\nEnter the New Food Item: ";
				cin>>fmenu [totitem];
				cout<<"\nEnter the Price of new Food Item: ";
				cin>>price [totitem];
				totitem++;
				cout<<"\n\nNew fmenu Added Successfully..." ;}}
			
			//this function helps a food stall portal user to delete a menu
			void delremenu (){
			    knowremenu ();
				int de=0;
				if((strcmp(::un, restid)==0))
				{
				
				if (totitem==0||totitem<0)
				{
				totitem=0;
				cout<<"\nNone fmenus Exist...";
				getch();
				exit(0);}
				
				cout<<"\nEnter the fmenu No. to be Deleted: ";
				cin>>de;
				if (de==totitem)
				{
				totitem--;
				strcpy (fmenu [totitem], " ");
				price [totitem] =0;}
				else if (totitem==1)
				{totitem=0;
				strcpy (fmenu [totitem], ""); 
				price [0]=0;
				}
				else
				{
				de--;
				strcpy (fmenu [totitem], " ");
				for (int p=de; p<totitem; p++){
				
				strcpy (fmenu [p], fmenu [p+1]);
				price [p]=price [p+1];}
				totitem--;
				}
				cout<<"\n Records Updated Successfully...";}}
			//this function helps a food stall portal user to modify the personal profile
			void modreprofile(){
			
				if((strcmp(::un, restid)==0)){
				cout<<"\nThe Profile Details are: ";
				cout<<"\n 1. Food Stall E-Mail: "<<mail;
				cout<<"\n 2. Food Stall Mobile: "<<mobile;
				cout<<"\n 3. Food Stall Type:"<<retype;
				int g=-1;
				cout<<"\n\nEnter the Detail No. to be Modified: ";
				cin>>g;
				if (g==1)
				{
				
				char nmail [50];
				cout<<"\nEnter the New Mail Address: ";
				cin.ignore();
				gets(nmail);
				strcpy (mail,nmail);
				cout<<"\nRecords Updated Successfully....";}
				else if (g==2){
				
				char nmobile [15];
				cout<<"\nEnter the New Mobile No. : ";
				cin.ignore();
				gets(nmobile);
				strcpy(mobile, nmobile);
				cout<<"\nRecords Updated Successfully...";}
				else if (g==3)
				{
				char nretype [20];
				cout<<"\nFood Stall Food Options Possible are \n1.South-Indian\n2. Continental\n3. Chinese \n4. Thailand \n5. Multiple";
				int foodtype;
				cout<<"\nEnter the Food Stall Food Options Type (Unique Number)";
				cin>>foodtype;
				


if (foodtype == 1) {
    strcpy(nretype, "South Indian");
} else if (foodtype == 2) {
    strcpy(nretype, "Continental");
} else if (foodtype == 3) {
    strcpy(nretype, "Chinese");
} else if (foodtype == 4) {
    strcpy(nretype, "Thailand");
} else {
    strcpy(nretype, "Multiple");
}
				cout<<"\nRecords Updated Successfully...";}
				else
				cout<<"\nInvalid Input Provided...";}}
			int knowremenutocustomer()
			{
				if (strcmp(::sid, stallid) == 0) {
    cout << "\nFood Stall Name: " << name;
    cout << "\nFood Stall unique ID: " << stallid;
    cout << "\nFood Stall Food Menu Type: " << retype;
    cout << "\nFood Stall Total Food Menu Items: " << totitem;
    for (int i = 0; i < totitem; i++) {
        cout << "\n\tFood Item " << i + 1 << ": " << fmenu[i] << " Price: " << price[i];
    }
				return 1;}
				else
				return 0;
			}
			
			void redisplaytocustomer(){
			    int i;
				cout<<"\nFood Stall Name: "<<name;
				cout<<"Food Stall unique ID: "<<stallid;
				cout<<"Food Stall Food Menu Total Items:-"<<totitem; 
				for (i=0;i<totitem; i++){
				cout<<"\n\t Food Item: "<<i+1<<": "<<fmenu [i]<<" :: Price:"<<price [i];}
				if (totitem==0)
				cout<<"( None Food Items Specified... )";}
			
			int searchrebyfoodtype(){int i;
				if((strcmp(::ft, retype)==0)){
				
				cout<<"\nFood Stall Name:: "<<name;
				cout<<"\nFood Stall Unique ID:: "<<stallid;
				cout<<"\nFood Stall Total Food Items :- "<<totitem;
				for (i=0;i<totitem; i++){
				cout<<"\n\t Food Item: "<<i+1<<": "<<fmenu [i] <<"Price: "<<price[i];}
				return 1;}
				else
				return 0;}
				void invalid_input(){
				
				cout<<"\nInvalid Input Provided !!! ";
				getch();
				clrscr();
				cout<<"\n\n\n\t\t\t Thank You";}
}a, f;

class MainMenu : public Admin{

			public:
			void admin_call(){int k;
			
			char adminuser [20], adminpass [20];
			cout<<"\n\t\t\tWelcome To Admin Login Portal ";
			cout<<"\n\nEnter the UserName : ";
			cin>>adminuser;
			cout<<"\nEnter the Password: ";
			for (k=0;k<8; k++){
			adminpass [k] =getch();
			cout<<"*";}
			getch();
			adminpass [k]='\0';
			if ((strcmp (adminuser, "admin")==0) && (strcmp (adminpass, "password")==0))
			clrscr();
			else{
			cout<<"\n\n\t\t\t Invalid Access to Portal ";
			cout<<"\n\n\t\t\t\tThank You !!!";
			getch();
			exit(0);}
			int tmp;
			char opera='y';
			do{
			clrscr();	
			cout<<"\n\t\t\t\tWelcome To Admin Panel";
			cout<<"\n\nPress 1 to Add Single Food Stall with record ";
			// cout<<"\nPress 2 to Add Multiple Food Stalls with record";
			cout<<"\nPress 2 to View All Food Stalls with records ";
			cout<<"\nPress 3 to Delete a Food Stall with Record ";
			cout<<"\n\tEnter Your Choice: ";
			cin>> tmp;
			clrscr();
			if (tmp==1)//for inserting a single Food Stall record
			{
			cout<<"\nEnter the Details:- ";
			fstream fs;
			fs.open("rainfo.txt", ios::in|ios::out|ios::ate);
			a.getredata();
			fs.write((char *)&a,sizeof(Admin));
			fs.close();
			cout<<"\nRecord Entered Successfully...";}
			//for inserting the single Food Stall records
			else if(tmp == 4) {
        int m = 0;
         // Create an instance of the Admin class to store stall details

        fstream fs("rainfo.txt",ios::in | ios::out |ios::ate);

        if (!fs) {
            cout<< "Error opening file." << endl;
            
        }

        do {
            cout << "\nEnter the Details: ";
            a.getredata(); // Input details for the Admin object, you should implement this method
            fs.write((char *)&a, sizeof (Admin));
            cout << "Press 0 if you want to Enter More Records: ";
            cin >> m;
        } while (m == 0);

        fs.close();
        cout << "\nRecord(s) Entered Successfully..." <<endl;
    }//for inserting multiple food stall records 
		else if (tmp == 2) {
    // View all Food Stall records
    fstream fs("rainfo.txt", ios::in); // Open the file in binary mode

    if (!fs.is_open()) {
        cout << "Failed to open file for viewing records.\n";
    } else {
        fs.seekg(0);
while (fs.read((char *)&a, sizeof(Admin))) {
            // Call a function to display 'a' (e.g., a.redisplay() or a.display())
            a.redisplay();
        }

        fs.close();
    }
}

			
			//to view all food stall records
			if (tmp == 3) {
        char tmpfaid[15];
        int de = 0;
        int result = -1;

        cout << "Enter the Food Stall ID: ";
        cin >> tmpfaid;

        fstream fs("rainfo.txt", ios::in);
        fstream fs1("fanewinfo.txt", ios::out |ios::ate);

        if (!fs || !fs1) {
            cout<< "Error opening files." <<endl;
            
        }
       while (fs.read((char *)&a, sizeof (Admin))) {
            result = strcmp(tmpfaid, a.restid);
            if (result == 0) {
                de = 1; // Mark the record for deletion
            } else {
                fs1.write((char *)&a, sizeof (Admin)); // Write non-deleted records to the new file
            }
        }

        fs.close();
        fs1.close();

        if (de == 1) {
            cout << "Record Deleted Successfully." << endl;
        } else {
        cout << "Record not found." << endl;
        }

        if (remove("rainfo.txt") != 0) {
            cout << "Error removing the original file." << endl;
            
        }

        if (rename("fanewinfo.txt", "rainfo.txt") != 0) {
            cout<< "Error renaming the temporary file." <<endl;
           
        }
    }
			//for deleting a food stall record
			getch();
			cout<<"\n\nPress y; For More Operations otherwise n: ";
			cin>>opera;
			if (opera!='y'){
			getch();
			clrscr();
			cout<<"\n\n\n\n\n\t\t\t\t\t Thank You !!!";
			getch();}
			//closing of thank you
			}while(opera=='Y'||opera=='y');
			}
			void r_call(){
			clrscr();
			char un [20];
			int val,s=0;
			cout<<"\n\t\t\tWelcome to Food Stall Login Page";
			cout<<"\n\nEnter the UserName:";
			cin>>::un;
			fstream fs;
			fs.open("rainfo.txt", ios::in);
			fs.seekg(0);
			while (!fs.eof())
			{
			val=-1;
			fs.read((char *)&f, sizeof (Admin));
			val=f.login();
			if (val==1){
			s=1;
			break;}}
			fs.close();
			if (s==1)
			{
			clrscr();}
			//if first login is valid
			if(s!=1)//if first login is invalid
			{
			clrscr();
			int ho=0;
			cout<<"\n\n\t\tYour Login Credentials are In-Correct";
			cout<<"\nThe UserName is Your ID/restid.";
			cout<<"\nThe Password is Case-Sensitive.";
			cout<<"\nPress 1 to Re-Cover Password & 2 to Re-Attempt Login";
			cout<<"\nEnter the Choice: ";
			cin>>ho;
			if (ho==1) //recover password
			{
			cout<<"Enter the UserName :- ";
			cin>>::un;
			fstream fs;
			fs.open("rainfo.txt", ios::in | ios::binary);
			fs.seekg(0);
			int re,su=-1;
			while (!fs.eof())
			{
			re=-1;
			fs.read((char *)&f, sizeof (Admin));
			re=f.recover();
			if (re==1)
			{
			su=1;
			break;}}
			fs.close();
			if (su=-1){
				getch();
			clrscr();
			cout<<"\n\n\n\n\t\t\tThank You !!! ";
			getch(),
			exit (0);
			}}
		else {
    cout << "You are an Invalid User.";
    getch();
    exit(0);
}
			//recover password
			if (ho==2)// attempt login again
			{
			cout<<"\n\nEnter the UserName : ";
			cin>>::un;
			fstream fs;
			fs.open("rainfo.txt", ios::in|ios::binary);
			fs.seekg(0);
			int suc=-1, valu;
			
			while (!fs.eof())
			{
			valu= -1;
			//value for storing login () returned
			fs.read((char *)&f, sizeof (Admin));
			valu-f.login();
			if (valu==1)
			{
			suc=1;
			break;
			}}
			fs.close();
			if (suc==1){
				clrscr();
			}
			else{
				getch();
			cout<<"\nYou are an Invalid User...";
			cout<<"\nThank You !!!";
			getch();
			exit (0);
			exit (0);}}
			if (ho!=1&&ho!=2)
			{
			cout<<"\n\nInvalid Input Provided. ";
			cout<<"\n\n\t\t\tThank You !!!";
			getch();
			exit (0);
			}}
			//Beginning of Food Stall main menu
			char con='y' ;
			do
			{
			clrscr();
	        cout<<"\n\n\t\t\tWelcome to Food Stall Panel ";
			cout<<"\n\n\t\t\t\t\t\tYour UserId is: "<<::un;
			cout<<"\n\nPress 1 to View Your Profile.";
			cout<<"\nPress 2 to Know Your Menu (with Price)";
			cout<<"\nPress 3 to Add a Food Item.";
			cout<<"\nPress 4 to Delete a Food Item.";
			cout<<"\nPress 5 to Modify Your Profile.";
			int choice;
			cout<<"\n\nEnter Your Choice: ";
			cin>>choice;
			if (choice ==1)//View a Food Stall record
			{
			fstream fs;
			fs.open("rainfo.txt", ios::in);
			fs.seekg (0);
			int x;
			while (!fs.eof())
			{
			x=0;
			fs.read((char *)&f, sizeof (Admin));
			x=f.reprofile();
			if (x==1)
			{
			break;
			}}
			fs.close();}
			//View a food stall record
			if (choice==2){
			fstream fs;
			fs.open("rainfo.txt", ios::in);
			fs.seekg(0);
			int y;
			while (!fs.eof())
			{
			y=0;
			fs.read((char *)&f, sizeof (Admin));
			int y=f.knowremenu ();
			if (y==1)
			{
			
			break;}
			}
			fs.close();}
			if (choice == 3) {
        fstream fs("rainfo.txt",ios::in|ios::out|ios::binary);
      if (!fs) {
            cout<< "Error opening file." <<endl;
            
        }
fstream fs1("tmprainfo.txt",ios::out|ios::binary);

        if (!fs1) {
            cout<< "Error opening temporary file." <<endl;
        }
        fs.seekg(0);
        while (fs.read((char *)&f, sizeof (Admin))) {
            f.addremenu ();
            fs1.write((char *)&f, sizeof (Admin));
        }
        fs.close();
        fs1.close();

        
        if (remove("rainfo.txt") != 0) {
           cout << "Error removing the original file." <<endl;
        }

        if (rename("tmprainfo.txt", "rainfo.txt") != 0) {
           cout<< "Error renaming the temporary file." <<endl;
        }
    }//Add item in food stall menu
			if (choice == 4) {
        fstream fs("rainfo.txt", ios::in|ios::binary);

        if (!fs) {
            cout << "Error opening file." <<endl;
            
        }

        // Create a temporary file to store menu data without the deleted item
        fstream fs1("delrainfo.txt",ios::out |ios::binary);

        if (!fs1) {
            cout<< "Error opening temporary file." <<endl;
           
        }

        // Read and delete menu items
        

        while (fs.read((char *)&f, sizeof (Admin))) {
            f.delremenu ();

            // Write the non-deleted item to the temporary file
            fs1.write((char *)&f, sizeof (Admin));
        }

        // Close both files
        fs.close();
        fs1.close();

        // Replace the original file with the updated one
        if (remove("rainfo.txt") != 0) {
            cout<< "Error removing the original file." <<endl;
            
        }

        if (rename("delrainfo.txt", "rainfo.txt") != 0) {
            cout << "Error renaming the temporary file." <<endl;
        }
    }
			if (choice == 5) {
        fstream fs("rainfo.txt", ios::in |ios::binary);

        if (!fs) {
            cout<< "Error opening file." <<endl;
            
        }
        fs.seekg(0);
        // Create a temporary file to store the modified stall profile
        fstream fs1("modrainfo.txt",ios::out | ios::binary);

        if (!fs1) {
            cout << "Error opening temporary file." <<endl;
            
        }

        // Read and modify stall profiles
       
        cout << "Enter the unique ID of the Food Stall: ";
        cin >> un;

        while (fs.read((char *)&f, sizeof (Admin) )) {
            f.modreprofile();
            fs1.write((char *)&f, sizeof (Admin));
        }

        // Close both files
        fs.close();
        fs1.close();

        // Replace the original file with the updated one
        if (remove("rainfo.txt") != 0) {
           cout << "Error removing the original file." <<endl;
           
        }

        if (rename("modrainfo.txt", "rainfo.txt") != 0) {
            cout<< "Error renaming the temporary file." <<endl;
            
        }
    }//Modify the food stall profile
			if(choice<1|| choice>5)
			cout<<"\nInvalid Input Provided !!! ";
			cout<<"\n\n\t\t\t\tEnter To Continue";
			getch();
			cout<<"\n\nPress y to Continue; otherwise n: ";
			cin>>con;
			if (con!= 'y' && con!='Y')
			{
			clrscr();
			cout<<"\n\n\n\n\n\t\t\t\t Thank You !!! ";
			getch();
			exit (0);}
			}while (con=='y' || con=='Y');}
			void customer_call ()
			{
			char moreop;
			clrscr();
			do
			{
			clrscr();
			cout<<"\n\n\t\t\tWelcome to Customer Panel";
			cout<< "\n\n\t\t\t\t\t\t Guest Login";
			cout<<"\n\nPress 1 to View All Food Stall/Food Stall Details."; 
			cout<<"\nPress 2 to Search a Stall by Stall unique ID.";
			cout<<"\nPress 3 to Search a Food Stall (Depending on Taste)";
			int inchoice;
			cout<<"\n\nEnter Your Choice: ";
			cin>>inchoice;
			if (inchoice==1)//to view all food stall records
			{fstream fs;
			fs.open("rainfo.txt", ios::in);
			fs.seekg (0);
			while (fs.read((char *)&a, sizeof (Admin)))
			{
			a.redisplaytocustomer();}
			fs.close();}
			//to view all food stall records
			if (inchoice ==2)//to search a food stall by unique stallid
			{
			int result=-1;
			cout<<"\nEnter the Food Stall Unique ID. :-";
			cin>>::sid;
			fstream fs;
			fs.open("rainfo.txt", ios:: in);
			while (fs.read((char *)&a, sizeof (Admin)))
			{
			result=a.knowremenutocustomer();
			if (result==1)
			break;}
			if (result!=1)
			{
			cout<<"\nRecord not found....";}
			}//to search a Food Stall by stallid
			if (inchoice==3)//to search a food stall by food type
			{
			int result;
			cout<<"\nFood Stall Food Options Possibilities are \n1.South-Indian\n2. Continental\n3. Chinese\n4. Thailand \n5. Multiple";
			cout<<"\nEnter the Food Stall Food Options Type (Unique Number)";
			cin>>result;
			if (result == 1) {
    strcpy(ft, "South Indian");
} else if (result == 2) {
    strcpy(ft, "Continental");
} else if (result == 3) {
    strcpy(ft, "Chinese");
} else if (result == 4) {
    strcpy(ft, "Thailand");
} else {
    strcpy(ft, "Multiple");
}
			fstream fs;
			fs.open("rainfo.txt", ios:: in);
			while (fs.read((char *)&a, sizeof (Admin)))
			{
			
			result=a.searchrebyfoodtype();
			if (result==1)
			{
			break;
			}}
			if (result!=1)
			{
			cout<<"\nNo Such Food Stall found....";}
			}//to search a food stall by food type
			if (inchoice<1||inchoice>3)
			cout<<"\nInvalid Input Provided...";
			cout<<"\n\n\t\t\tEnter to Continue ";
			getch();
			cout<<"\n\nPress y, otherwise n to Perform More Operations : ";
			cin>>moreop;
			if (moreop!='Y' &&moreop!= 'y')
			{
			clrscr();
			cout<<"\n\n\n\t\t\tThank You !!!";
			getch();
			exit (0);}
			}while (moreop=='y' || moreop=='Y');
			getch();}
			void invalid_user_input(){
				a. invalid_input();
				}
}m;
int main(){
int ch, tmp;
clrscr();
cout<<"\n\n\n\t\t\tWelcome to Food Court Management System ";
cout<<"\n\n\n\t\t\t\tEnter to Continue ";
getch();
clrscr();
cout<<"\n\n\n\t\t\t Press 1 for Admin Portal";
cout<<"\n\t\t\t Press 2 for Food Stall Portal";
cout<<"\n\t\t\t Press 3 for Customer Portal";
cout<<"\n\n\t\t\tEnter Your Choice: ";
cin>>ch;
clrscr();
if (ch==1){
m.admin_call();
}//closing of admin login
if (ch==2)//beginning of food Stall view portal
{
m.r_call();
}//End of food stall view portal
if (ch==3)//begin of Customer view
{
m.customer_call();
}//closing of Customer panel ch=3
if (ch<1||ch>3)
{
m.invalid_user_input();}
return 0;}