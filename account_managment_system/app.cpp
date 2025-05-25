
#include<iostream>
#include<vector>
#include<memory>
#include<string>
#include<unordered_map>
#include<stdexcept>

using namespace std;

enum class AccountType{SAVINGS,CURRENT};

class Account{
     protected:
      int accountNumber;
      double balance;
    public:
      Account(int accnum,double initBal):accountNumber(accnum),balance(initBal){}

      virtual void withdraw(double amount){
         if(amount> balance )throw runtime_error("Insufficent funds");
         balance -=amount;
      }

      virtual void display() const =0;
       virtual ~Account(){}

};


//derived class

class SavingsAccount:public Account{
    public :
      SavingsAccount(int accnum,double initBal): Account(accnum,initBal){}
      
      void display() const override{
          cout<<"savings account["<<accountNumber<<"] Balance :Rs"<<balance<<"\n";
      }
};



class CurrentAccount:public Account{ 
      public: 
        CurrentAccount(int accNum,double initBal):Account(accNum,initBal){}
         void display() const override{
             cout<<"Current Account["<<accountNumber<<"[ Balance : Rs"<<balance<<"\n";
         }
};

class AccountManager{
      private:
       unordered_map<int,shared_ptr<Account>>accounts;
       int nextAccountNumber =1001;
    
       public:
        int createAccount(AccountType type,double initialBalance){
              shared_ptr<Account>acc;
              if(type == AccountType::SAVINGS){
                     acc = make_shared<SavingsAccount>(nextAccountNumber,initialBalance);

              }else{
                   acc = make_shared<CurrentAccount>(nextAccountNumber,initialBalance);
              }

              accounts[nextAccountNumber]= acc;
              return nextAccountNumber++;
        }



        void deposit(int accNum,double amount){
               getAccount(accNum)->deposit(amount);
        }

};