#include <iostream>
using namespace std;

class Person{
private:                             
    
    int AccountNo;      //here I have defined a class of person containing necessary details of the person
    int Balance;
    int PhoneNo;
public:           //different kinds of personal info are private to class using the concept of encapsulation
    
    string Name;
    void setbal(int bal){  //setter
        Balance=bal;
    }
    int getbal(){     //getter
        return Balance;
    }
    void setacc(int accno){
        AccountNo = accno;
    }
    int getacc(){
        return AccountNo;
    }
    void setph(int phno){
        PhoneNo=phno;
    }
    int getph(){
        return PhoneNo;
    }
    
    void PrintInfo(){                               //a funtion to print the details
        cout << "Name- " << Name <<endl;
        cout << "AccountNo- " << AccountNo <<endl;
        cout << "Balance- " << Balance <<endl;
        cout << "PhoneNo- " << PhoneNo <<endl;
        
    }
    
    
    Person(string name, int accno, int bal, int phno){    //this is a contructor used to initialise values
        Name = name;
        AccountNo = accno;
        Balance = bal;
        PhoneNo = phno;
    }
    
};


class lender : public Person{             //used the concept of inheritance from Person to lender
public:    
    int InterestRate;  
    int RepaymentPeriod;  
    lender(string name, int accno, int bal, int phno,  int interestRate, int repaymentPeriod)  //use of contructor in inheritance
        :Person(name, accno, bal, phno)
    {
        
        InterestRate=interestRate;
        RepaymentPeriod=repaymentPeriod;
    }
    void printrem(){                           //printing remaining details
        
        cout << "InterestRate(in %)- " << InterestRate <<endl;
        cout <<endl;
        cout <<endl;
    }
};

class borrower : public Person{        //used the concept of inheritance from Person to borrower
public:    
    string Bank;
    borrower(string name, int accno, int bal, int phno, string bank)
        :Person(name, accno, bal, phno)
        {
            Bank=bank;
        }
    void printrem(){
        cout << "Bank- " << Bank <<endl;
        cout <<endl;
        cout <<endl;
    }
};


int main() {
	lender lender1=lender("Jack",1,100000,987654321,7,5);       
	borrower borrower1=borrower("King",2,5000,977453827,"SBI");      //initialising values to objects
	int MoneyBorrowed;
	cout << "Lender's info:"<<endl;
	lender1.PrintInfo();                    //printing lender's info
	lender1.printrem();            
	cout << "How much money do you want to borrow from this lender? "<<endl;
	cin>>MoneyBorrowed;                          //basic input output
	if (MoneyBorrowed>100000){             
	    cout << "limit is 100000";
	    return 0;
	}
	int SimpleInterest,rate;
	int time;
	cout << "Enter repayment time in years:"<<endl;    
	cin>>time;                                          //basic input output
	string Collateral;
	cout << "Enter Collateral:"<<endl;
	cin>>Collateral;                                //basic input output
	cout <<endl;
	rate=lender1.InterestRate;
	
	SimpleInterest= (MoneyBorrowed*time*rate)/100;      
	int amounttopayback, monthlyemi;
	amounttopayback= MoneyBorrowed+SimpleInterest;         //calculating SimpleInterest
	monthlyemi=amounttopayback/12;
	cout << "Your monthly EMI is: "<<monthlyemi<<endl;
	cout << "And your info:"<<endl;
	borrower1.PrintInfo();
	borrower1.printrem();                           //printing details
	
	
    system("pause");
	return 0;
}
