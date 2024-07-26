#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <random>
#include <algorithm>
using namespace std;
vector<long long> accounts;
class BankAccount;
vector<BankAccount*> obj;
class BankAccount{
    public: 
            string name, gender, address,password,username;
            int age;
            long long account_number;
            vector<int> amount;
            vector<time_t> date;
            time_t accdate;
    public:
            void initial(){
                cout << "Enter Your Name: " << endl;
                getline(cin, name);
                cout<<"Enter Your Gender: "<<endl;
                cin>>gender;
                cout<<"Enter Your Age: "<<endl;
                cin>>age;
                cout<<"Enter Your Address: "<<endl;
                cin.ignore();
                getline(cin,address);
                cout<<"Enter Your UserName: "<<endl;
                cin.ignore();
                getline(cin,username);
                cout<<"Enter Your Password: "<<endl;
                cin.ignore();
                getline(cin,password);
                accdate=time(0);
                account_number=this->generateAccountNumber();
            }
            void myInfo(){
                cout<<"\n\nHere are Your Details Below:- "<<endl;
                cout<<"Name: "<<name<<endl;
                cout<<"Account Number: "<<account_number<<endl;
                cout<<"Age: "<<age<<endl;
                cout<<"Gender: "<<gender<<endl;
                cout<<"Address: "<<address<<endl;
                cout<<"Account Creation Date: "<<ctime(&accdate)<<endl;
                this->checkBalance();
            }
            void addBalance(){
                int x,y;
                cout<<"Enter the amount you want to add: ";
                cin>>x;
                amount.push_back(x);
                y=amount.back();
                cout<<y<<" Rupees Added Successfully\n\n";
                date.push_back(time(0));
            }
            void checkBalance(){
                int sum=0;
                for(int i:amount){
                    sum+=i;
                }
                cout<<"Your total amount is: "<<sum<<"\n\n";
            }
            void checkTransactions(){
                cout<<"Enter No. of last transaction you want to check: ";
                int x;
                cin>>x;
                if(x<=amount.size()){
                    cout<<"*********Transactions*********"<<endl;
                    cout<<"     Amount            Time"<<endl;
                    for(int i=0;i<x;i++){
                        cout<<"       "<<amount[i]<<"          "<<ctime(&date[i])<<endl;
                    }
                }else{
                    cout<<"Your Transactions are less than entered value"<<endl;
                }
                
            }
            void interestCal(){
                int rate=8/100;
                time_t time1=0;
                double amt=0;
                double amt1=0;
                for(int i=0;i<amount.size();i++){
                    double sec=0,dy=0;
                    time_t time2=time(0);
                    sec=difftime(time2,date[i]);
                    dy=sec/(60*60*24);
                    amt1+=amount[i];
                    amt+=(amount[i]*rate*(dy/360))/100;
                    
                }cout<<"Your total Amount( "<<amt1<<" + "<<amt<<" ) "<<"is: "<<(amt1+amt)<<" @8 p.a"<<"\n\n";
            }
            long long generateAccountNumber() {
                random_device rd;
                mt19937 gen(rd());
                uniform_int_distribution<long long> dis(100000000000LL, 999999999999LL);
                long long newAccountNumber;
                do {
                    newAccountNumber = dis(gen);
                } while (find(accounts.begin(), accounts.end(), newAccountNumber) != accounts.end());
        
                accounts.push_back(newAccountNumber);
            return newAccountNumber;
    }
            
};
int main(){
    int choice;
    int ch2;
    do{
        cout<<"*******.....Welcome To PC's Asset Management Firm.....******"<<endl;
        cout<<"\t\t\tSelect One Below:"<<endl;
        cout<<"\t\t\t1. Login\n\t\t\t2. SignUp\n\t\t\t3. Exit"<<endl;
        cin>>choice;
        cin.ignore();
    switch(choice){
        case 1:{
            cout<<"Enter Details Below to Login:"<<endl;
            string urnm,pass;
            cout<<"Enter UserName: "<<endl;
            cin.ignore();
            getline(cin,urnm);
            cout<<"Enter Password: "<<endl;
            cin.ignore();
            getline(cin,pass);
            //logic
            bool loggedIn = false;
            for(BankAccount* i:obj){
                if(urnm==i->username && pass==i->password){
                    cout<<"Login SuccessFul"<<endl;
                    loggedIn = true;
                    do{
                    cout<<"\t\t\tSelect One Below:"<<endl;
                    cout<<"\t\t\t1. Check Info"<<endl;
                    cout<<"\t\t\t2. Add Balance"<<endl;
                    cout<<"\t\t\t3. Check last Transactions "<<endl;
                    cout<<"\t\t\t4. Check Amount"<<endl;
                    cout<<"\t\t\t5. Check Amount with Interest"<<endl;
                    cout<<"\t\t\t6. Exit"<<endl;
                    cin>>ch2;
                    switch(ch2){
                        case 1:{
                            i->myInfo();
                            break;
                        }case 2:{
                            i->addBalance();
                            break;
                        }case 3:{
                            i->checkTransactions();
                            break;
                        }case 4:{
                            i->checkBalance();
                            break;
                        }case 5:{
                            i->interestCal();
                            break;
                        }case 6:{
                            break;
                        }
                        default:{
                            cout<<"Enter Correct Value"<<endl;
                            break;
                        }
                    }}while(ch2!=6);
                    break;
                }
            }if(!loggedIn){
                cout<<"Login Failed. Please Try Again"<<endl;
            }
            break;
        }
        case 2:{
            BankAccount* b=new BankAccount();
            obj.push_back(b);
            b->initial();
            cout<<"\nCongrats! You're now part of PC's Firm Family"<<endl;
            b->myInfo();
            do{
            cout<<"\t\t\tSelect One Below:"<<endl;
            cout<<"\t\t\t1. Check Info"<<endl;
            cout<<"\t\t\t2. Add Balance"<<endl;
            cout<<"\t\t\t3. Check last Transactions "<<endl;
            cout<<"\t\t\t4. Check Amount"<<endl;
            cout<<"\t\t\t5. Check Amount with Interest"<<endl;
            cout<<"\t\t\t6. Exit"<<endl;
            cin>>ch2;
            switch(ch2){
                case 1:{
                    b->myInfo();
                    break;
                }case 2:{
                    b->addBalance();
                    break;
                }case 3:{
                    b->checkTransactions();
                    break;
                }case 4:{
                    b->checkBalance();
                    break;
                }case 5:{
                    b->interestCal();
                    break;
                }case 6:{
                    break;
                }
                default:{
                cout<<"Enter Correct Value"<<endl;
                break;
                }
            }}while(ch2!=6);
            break;
        }case 3:{
            cout<<"Program Ended Successfully\nPlease Visit Again";
            exit(0);
        }
        default:{
            cout<<"Enter Correct Value"<<endl;
            break;
        }
    }}while(choice!=3);
}
