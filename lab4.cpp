#include <iostream>
using namespace std;

class SavingsAccount{
    private:
    double savingsBalance;
    static double annualInterestRate;

    public:
    SavingsAccount(){
        savingsBalance = 0;
        annualInterestRate = 0;
    }
    SavingsAccount (double saving, double interest){
        set_savings(saving);
        set_interest(interest);
    }
    void set_savings(double saving){
        savingsBalance = saving;
    }
    static void set_interest(double interest){
        annualInterestRate = interest;
    }
    double get_savings(){
        return savingsBalance;
    }
    static double get_interest(){
        return annualInterestRate;
    }
    double calculateMonthlyInterest(){
        savingsBalance+=(savingsBalance*annualInterestRate/12.0);
        return savingsBalance;
    }
    static double modifyInterestRate(double new_interest){       //modifyInterestRate and set_interest both have same function
        annualInterestRate = new_interest;
    }
    const void printBalance(){
        cout<<savingsBalance<<endl;
    }
    ~SavingsAccount(){
        cout<<"Destructor called"<<endl;
    }
};
double SavingsAccount::annualInterestRate = 0;
int main(){
    SavingsAccount::set_interest(0.03);
    //object1
    SavingsAccount saver1(2000.00, SavingsAccount::get_interest());
    saver1.set_savings(saver1.calculateMonthlyInterest());
    cout<<"New Balance of saver1 is ";
    saver1.printBalance();
    cout<<endl;
    //object2
    SavingsAccount saver2(3000.00, SavingsAccount::get_interest());
    saver2.set_savings(saver2.calculateMonthlyInterest());
    cout<<"New Balance of saver2 is ";
    saver2.printBalance();
    cout<<endl;
    //object3
    SavingsAccount saver3(saver1);
    cout<<"New Balance of saver3 is ";
    saver3.printBalance();
    cout<<endl;

    // Set the annualInterestRate to 7%
    SavingsAccount::modifyInterestRate(0.07); 
    // object1
    saver1.set_savings(saver1.calculateMonthlyInterest());
    cout << "New Balance of saver1 is ";
    saver1.printBalance();
    cout << endl;
    //object2
    saver2.set_savings(saver2.calculateMonthlyInterest());
    cout << "New Balance of saver2 is ";
    saver2.printBalance();
    cout << endl;
    //object3
    saver3.set_savings(saver3.calculateMonthlyInterest());
    cout << "New Balance of saver3 is ";
    saver3.printBalance();
    cout << endl;

    return 0;
}