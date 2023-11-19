#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
using namespace std;
class login{
    private:
    string password = "helloworld";
    string username = "@gmail.com";
    bool accessgranted;
    public:
    string usernameAttempt,passwordAttempt;
    login(){
        accessgranted =0;
    }
    void log_in(){
        cout<<"enter username"<<endl;
        cin>>usernameAttempt;
        if(usernameAttempt == username){
            cout<<"password: "<<endl;
            cin>>passwordAttempt;
            if(passwordAttempt == password){
                cout<<"login successful"<<endl;
            }
            else{
                cout<<"login failed"<<endl;
            }
        }
        else{
            cout<<"wrong username"<<endl;
        }
    }
};
class pointfees{
    private:
    string point_no, stu_name;// stu_name refers to student name.
    public:
    void getinfo(){
        p:
        system("cls");
        int choice;
        cout<<"\n\t\t_______UNIVERSITY POINT DETAILS________";
        cout<<"\n\n1. Add record";
        cout<<"\n\n2. View point fees";
        cout<<"\n\n3. Point routes";
        cout<<"\n\n4. Exit";
        cout<<"\n\n Enter your choice : ";
        cin>>choice;
        switch(choice){
            case 1:
                point_num();
                break;
            case 2:
                view_fees();
                break;
            case 3:
                point_route();
                break;
            case 4:
                exit(0);
                break;
            default:
                cout<<"\n\nINVALID CHOICE .......PLEASE TRY AGAIN";
        }
        getch();
        goto p;
    }
        void point_num()
        {
            p:
            system("cls");
            fstream file;
            string tpoint_no,tstu_name; //t refers to test
            int found;
            cout<<"Point number : "<<endl;
            cin>>point_no;
            cout<<"Student name : "<<endl;
            cin>>stu_name;
            file.open("point.txt",ios::in);
            if(!file){
                file.open("bus.txt",ios::app|ios::out);
                file<<point_no<<" "<<stu_name<<endl;
                file.close();
            }
            else{
                file>>tpoint_no>>tstu_name;
                while(!file.eof()){
                    if(point_no == tpoint_no){
                        found++;
                    }
                    file>>tpoint_no>>tstu_name;
                }
                file.close();
                if(found ==0){
                    file.open("bus.txt",ios::app|ios::out);
                    file<<point_no<<" "<<stu_name<<endl;
                    file.close();
                }
                else{
                    cout<<"\n\nDUPLICATE RECORD FOUND....";
                    getch();
                    goto p;
                }
            }
            cout<<"RECORD SUCCESSFULLY ENTERED";
        }
        void view_fees(){
            p:
            system("cls");
            int choice;
            cout<<"\n\n______POINT FEES_______";
            cout<<"\n\n1. UNDERGRADUATE STUDENT FEES";
            cout<<"\n\n2. POSTGRADUATE STUDENT FEES";
            cout<<"\n\n3. INTERNEES";
            cout<<"\n\n4. EXIT";
            cout<<"\n\n ENTER CHOICE"<<endl;
            cin>>choice;
            switch(choice){
                case 1:
                cout<<"Fees for undergraduate student is 1,200"<<endl;
                break;
            case 2:
                cout<<"Fees for postgraduate student is 3,300"<<endl;
                break;
            case 3:
                 cout<<"Fees for internees is 1,200"<<endl;
                break;
            case 4:
                getinfo();
                break;
            default:
                cout<<"\n\nINVALID CHOICE .......PLEASE TRY AGAIN";
            }
            getch();
            goto p;
        }
        void point_route(){
            p:
            system("cls");
            int choice;
            cout<<"\n\n______POINT ROUTE_______";
            cout<<"\n\n1. FIRST ROUTE DETAIL";
            cout<<"\n\n2. SECOND ROUTE DETAIL";
            cout<<"\n\n3. THIRD ROUTE DETAIL";
            cout<<"\n\n4. EXIT";
            cout<<"\n\n ENTER CHOICE"<<endl;
            cin>>choice;
            switch(choice){
                case 1:
                cout<<"FROM CITY CAMPUS TO NEDUET";
                cout<<"\n\nTIMINGS.......7:40 am";
                break;
            case 2:
                cout<<"FROM 4K CHOWRANGI TO NEDUET (MAIN CAMPUS)";
                cout<<"\n\nTIMINGS.......7:45 am";
                break;
            case 3:
                cout<<"FROM E-COMPLEX TO NEDUET (MAIN CAMPUS)";
                cout<<"\n\nTIMINGS......7:00 am";
                break;
            case 4:
                getinfo();
                break;
            default:
                cout<<"\n\nINVALID CHOICE .......PLEASE TRY AGAIN";
            }
            getch();
            goto p;
        }
};
class totalAmount : {
    private:
    pointfees pf;
    int s_fees,h_fees,p_fees,payment;
    public:
    void payment_method(){
        // pf.getinfo();
        // pf.point_num();
        // pf.view_fees();
        // pf.point_route();
        p:
        system("cls");
        int choice;
        cout<<"\n\n**************************************"<<endl;
        cout<<"\n\t\t_______TOTAL AMOUNT DETAILS________";
        cout<<"\n\n1. TOTAL HOSTEL FEES";
        cout<<"\n\n2. TOTAL POINT FEES";
        cout<<"\n\n3. SEMESTER FEES";
        cout<<"\n\n4. Exit";
        cout<<"\n\n Enter your choice : ";
        cin>>choice;
        cout<<"\n\n**************************************"<<endl;
        switch(choice){
            case 1:
                cout<<"\n\nhostel fees per semester : "<<endl;
                cin>>h_fees;
                break;
            case 2:
                cout<<"\n\npoint fees per month : "<<endl;
                cin>>p_fees;
                break;
            case 3:
                cout<<"\n\nsemester fees : "<<endl;
                cin>>s_fees;
                break;
            case 4:
                exit(0);
                break;
            default:
                cout<<"\n\nINVALID CHOICE .......PLEASE TRY AGAIN";
        }
        getch();
        goto p;
    }
    void calculate_total_amount(){
        payment= h_fees + p_fees +s_fees;
        cout<<"THE TOTAL AMOUNT IS : "<<payment<<endl;
    }
};
int main(){
    // login log;
    // log.log_in();
    pointfees pf;
    pf.getinfo();
    totalAmount t1;
    t1.payment_method();
    t1.calculate_total_amount();
    return 0;
}