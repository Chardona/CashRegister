#include <iostream>
#include <iomanip>
using std::cout;
using std::endl;
using std::cin;
using std::string;

class CashRegister {
public:
	CashRegister() = default;
	
	void choice() {
		char ans{};
		cout << "-------------------------------------------------------------" << endl;
		cout << "Do you want to open the cash register? y/n" << endl;
		cin >> ans;
		if (ans == 'y') {
			cout << "Welcome!" << endl;
			isOpen = true;
		}
		else if (ans == 'n') {
			cout << "Good bye!" << endl;
			return;
		}
		else {
			cout << "Incorrect input. Program termination." << endl;
			return;
		}
	};
	void printInfo() {
			choice();
		while (isOpen) {
			
			int ans{};
			cout << "-------------------------------------------------------------" << endl;
			cout << "   Choose operation you want to execute:" << endl;
			cout << "1. Check total balance." << endl;
			cout << "2. Check amount of coins and banknotes." << endl;
			cout << "3. Deposit coins or banknotes." << endl;
			cout << "4. Withdraw coins or banknotes." << endl;
			cout << "5. Close cash register." << endl;
			cout << "-------------------------------------------------------------" << endl;
			cout << "Your option: ";
			cin >> ans;
			cout << "-------------------------------------------------------------" << endl;
			if (ans == 1) {
				cout << "Your total balance is: " << totalBalance << endl;
			}
			if (ans == 2) {
				printBanknotes();
			}
			if (ans == 3) {
				deposit();
			}
			if (ans == 4) {
				withdraw();
			}
			if (ans == 5) {
				isOpen = false;
			}
			
		};
	}
	void printBanknotes() {
		
		cout << "Your current banknotes and coins: " << endl;
		cout << std::setw(10) << "zl200: " << zl200 << endl;
		cout << std::setw(10) << "zl100: " << zl100 << endl;
		cout << std::setw(10) << "zl50: " << zl50 << endl;
		cout << std::setw(10) << "zl20: " << zl20 << endl;
		cout << std::setw(10) << "zl10: " << zl10 << endl;
		cout << std::setw(10) << "zl5: " << zl5 << endl;
		cout << std::setw(10) << "zl2: " << zl2 << endl;
		cout << std::setw(10) << "zl1: " << zl1 << endl;
		cout << std::setw(10) << "gr50: " << gr50 << endl;
		cout << std::setw(10) << "gr20: " << gr20 << endl;
		cout << std::setw(10) << "gr10: " << gr10 << endl;
		cout << std::setw(10) << "gr5: " << gr5 << endl;
		cout << std::setw(10) << "gr2: " << gr2 << endl;
		cout << std::setw(10) << "gr1: " << gr1 << endl;
		
	}
	void deposit() {
		string ansBanknote{};
		char ansEnd{};
		int  ansNominal{}, ansAmount{};
		do {
			cout << "What do you want to deposit: zl or gr?" << endl;
			cout << "Banknote: ";
			cin >> ansBanknote;	
			cout << "What nominal do  you want to deposit?" << endl;
			cout << "Nominal: ";
			cin >> ansNominal;
			cout << "How many banknotes/coins do  you want to deposit?" << endl;
			cout << "Amount: ";
			cin >> ansAmount;
			if (ansBanknote == "zl" && ansNominal == 200) {
				zl200 += ansAmount;
			}
			else if (ansBanknote == "zl" && ansNominal == 100) {
				zl100 += ansAmount;
			}
			else if (ansBanknote == "zl" && ansNominal == 50) {
				zl50 += ansAmount;
			}
			else if (ansBanknote == "zl" && ansNominal == 20) {
				zl20 += ansAmount;
			}
			else if (ansBanknote == "zl" && ansNominal == 10) {
				zl10 += ansAmount;
			}
			else if (ansBanknote == "zl" && ansNominal == 5) {
				zl5 += ansAmount;
			}
			else if (ansBanknote == "zl" && ansNominal == 2) {
				zl2 += ansAmount;
			}
			else if (ansBanknote == "zl" && ansNominal == 1) {
				zl1 += ansAmount;
			}
			else if (ansBanknote == "gr" && ansNominal == 50) {
				gr50 += ansAmount;
			}
			else if (ansBanknote == "gr" && ansNominal == 20) {
				gr20 += ansAmount;
			}
			else if (ansBanknote == "gr" && ansNominal == 10) {
				gr10 += ansAmount;
			}
			else if (ansBanknote == "gr" && ansNominal == 5) {
				gr5 += ansAmount;
			}
			else if (ansBanknote == "gr" && ansNominal == 2) {
				gr2 += ansAmount;
			}
			else if (ansBanknote == "gr" && ansNominal == 1) {
				gr1 += ansAmount;
			}
			else {
				cout << "Incorrect input. Try again." << endl;
			}
			totalBalance = 200 * zl200 + 100 * zl100 + 50 * zl50 + 20 * zl20 + 10 * zl10 + 5 * zl5 + 2 * zl2 + 2 * zl1 +
				0.5 * gr50 + 0.2 * gr20 + 0.1 * gr10 + 0.05 * gr5 + 0.02 * gr2 + 0.01 * gr1;
			cout << "Do you want to repeat? y/n" << endl;
			cin >> ansEnd;
		} while (ansEnd == 'y');
	}
	void withdraw(){
		string ansBanknote{};
		char ansEnd{};
		int  ansNominal{}, ansAmount{};
		
		do {
			cout << "What do you want to withdraw: zl or gr?" << endl;
			cout << "Banknote: ";
			cin >> ansBanknote;
			cout << "What nominal do  you want to withdraw?" << endl;
			cout << "Nominal: ";
			cin >> ansNominal;
			cout << "How many banknotes/coins do  you want to withdraw?" << endl;
			cout << "Amount: ";
			cin >> ansAmount;
			if (ansBanknote == "zl" && ansNominal == 200) {
				if (zl200 >= ansAmount)
					zl200 -= ansAmount;
				else
					cout << "Insufficient amount. You lack " << abs(ansAmount - zl200) << " zl200." << endl;
			}
			else if (ansBanknote == "zl" && ansNominal == 100) {
				if (zl100 >= ansAmount)
					zl100 -= ansAmount;
				else
					cout << "Insufficient amount. You lack " << abs(ansAmount - zl100) << " zl100." << endl;
			}
			else if (ansBanknote == "zl" && ansNominal == 50) {
				if (zl50 >= ansAmount)
					zl50 -= ansAmount;
				else
					cout << "Insufficient amount. You lack " << abs(ansAmount - zl50) << " zl50." << endl;
			}
			else if (ansBanknote == "zl" && ansNominal == 20) {
				if (zl20 >= ansAmount)
					zl20 -= ansAmount;
				else
					cout << "Insufficient amount. You lack " << abs(ansAmount - zl20) << " zl20." << endl;
			}
			else if (ansBanknote == "zl" && ansNominal == 10) {
				if (zl10 >= ansAmount)
					zl10 -= ansAmount;
				else
					cout << "Insufficient amount. You lack " << abs(ansAmount - zl10) << " zl10." << endl;
			}
			else if (ansBanknote == "zl" && ansNominal == 5) {
				if (zl5 >= ansAmount)
					zl5 -= ansAmount;
				else
					cout << "Insufficient amount. You lack " << abs(ansAmount - zl5) << " zl5." << endl;
			}
			else if (ansBanknote == "zl" && ansNominal == 2) {
				if (zl2 >= ansAmount)
					zl2 -= ansAmount;
				else
					cout << "Insufficient amount. You lack " << abs(ansAmount - zl2) << " zl2." << endl;
			}
			else if (ansBanknote == "zl" && ansNominal == 1) {
				if (zl1 >= ansAmount)
					zl1 -= ansAmount;
				else
					cout << "Insufficient amount. You lack " << abs(ansAmount - zl1) << " zl1." << endl;
			}
			else if (ansBanknote == "gr" && ansNominal == 50) {
				if (gr50 >= ansAmount)
					gr50 -= ansAmount;
				else
					cout << "Insufficient amount. You lack " << abs(ansAmount - gr50) << " gr50." << endl;
			}
			else if (ansBanknote == "gr" && ansNominal == 20) {
				if (gr20 >= ansAmount)
					gr20 -= ansAmount;
				else
					cout << "Insufficient amount. You lack " << abs(ansAmount - gr20) << " gr20." << endl;
			}
			else if (ansBanknote == "gr" && ansNominal == 10) {
				if (gr10 >= ansAmount)
					gr10 -= ansAmount;
				else
					cout << "Insufficient amount. You lack " << abs(ansAmount - gr10) << " gr10." << endl;
			}
			else if (ansBanknote == "gr" && ansNominal == 5) {
				if (gr5 >= ansAmount)
					gr5 -= ansAmount;
				else
					cout << "Insufficient amount. You lack " << abs(ansAmount - gr5) << " gr5." << endl;
			}
			else if (ansBanknote == "gr" && ansNominal == 2) {
				if (gr2 >= ansAmount)
					gr2 -= ansAmount;
				else
					cout << "Insufficient amount. You lack " << abs(ansAmount - gr2) << " gr2." << endl;
			}
			else if (ansBanknote == "gr" && ansNominal == 1) {
				if (gr1 >= ansAmount)
					gr1 -= ansAmount;
				else
					cout << "Insufficient amount. You lack " << abs(ansAmount - gr1) << " gr1." << endl;
			}
			else {
				cout << "Incorrect input. Try again." << endl;
			}
			totalBalance = 200 * zl200 + 100 * zl100 + 50 * zl50 + 20 * zl20 + 10 * zl10 + 5 * zl5 + 2 * zl2 + 2 * zl1 +
				0.5 * gr50 + 0.2 * gr20 + 0.1 * gr10 + 0.05 * gr5 + 0.02 * gr2 + 0.01 * gr1;
			cout << "Do you want to repeat? y/n" << endl;
			cin >> ansEnd;
		} while (ansEnd == 'y');
	}
private:
	bool isOpen = false;
	double totalBalance{};
	int zl200{};
	int zl100{};
	int zl50{};
	int zl20{};
	int zl10{};
	int zl5{};
	int zl2{};
	int zl1{};
	int gr50{};
	int gr20{};
	int gr10{};
	int gr5{};
	int gr2{};
	int gr1{};
};

int main() {
	CashRegister cr1;
	cr1.printInfo();
	cout << "Good bye! Come again!" << endl;
}