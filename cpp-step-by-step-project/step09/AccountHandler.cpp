/*
    * File Name : AccountHandler.cpp
    * Version : 0.8
    * Update Date : 2019.01.27
*/

#include <BankingCommonDecl.h>
#include <AccountHandler.h>
#include <Account.h>
#include <NormalAccount.h>
#include <HighCreditAccount.h>

AccountHandler::AccountHandler()
	: num(0) {}

void AccountHandler::makeAccount()
{
    ACCOUNT_PTR pAccount;
    int kindOfAcc = 0;
	int address;
	char name[15];
	double balance;
    double intRatio;
    char grade;

    cout << "[계좌종류선택]" << endl;
    cout << "1. 보통예금계좌 2. 신용신뢰계좌" << endl;
    cout << "선택 : ";
    cin >> kindOfAcc;

    switch(kindOfAcc) {
        case 1:
            cout << "[보통예금계좌 개설]" << endl;
            break;
        case 2:
            cout << "[신용신뢰계좌 개설]" << endl;
            break;
        default:
            cout << "1, 2중에서 선택해 주세요." << endl;
            return;
    }

	cout << "계좌주소 : ";
	cin >> address;
	cout << "성함 : ";
	cin >> name;
	cout << "입금액 : ";
	cin >> balance;
    cout << "이자율 : ";
    cin >> intRatio;

    if(kindOfAcc == 2) {
        cout << "고객등급 : ";
        cin >> grade;
    }

    switch(kindOfAcc) {
        case 1:
            pAccount = new NormalAccount(address, name,
                balance, intRatio);
            break;
        case 2:
            pAccount = new HighCreditAccount(address, name,
                balance, intRatio, grade);
            break;
        default:
            break;
    }

    this->arr[this->num++] = pAccount;

}

void AccountHandler::deposit() const
{
	int address;
	double balance;

	cout << "입금계좌주소 : ";
	cin >> address;

	int i;
	for(i = 0; i < this->num &&
		!(this->arr[i]->getAddress() 
		== address); i++);
	if(i == this->num) {
		cout << "찾으시는 계좌가 없습니다. 다시 시도해 주세요." << endl;
		return;
	}

	cout << "입금금액 : ";
	cin >> balance;

	if(this->arr[i]->addBalance(balance))
		cout << this->arr[i]->getName() << " 에게 " 
		<< balance << " 원 입금 완료 !" << endl;
}

void AccountHandler::withdrawal() const
{
	int address;
	double balance;

	cout << "출금계좌주소 : ";
	cin >> address;

	int i;
	for(i = 0; i < this->num &&
		!(this->arr[i]->getAddress()
		== address); i++);

	if(i == this->num) {
		cout << "찾으시는 계좌가 없습니다. 다시 시도해 주세요." << endl;
		return;
	}

	cout << "출금금액 : ";
	cin >> balance;

	if(this->arr[i]->addBalance(-balance))
		cout << this->arr[i]->getName() << " 계좌에서 " 
		<< balance << " 원 출금 완료 !" << endl;
}

void AccountHandler::allPrint() const {
	cout << "**전체 계좌정보 출력**" << endl;
	for(int i=0; i < this->num; i++) {
		cout << "-" << i+1 << "번째 고객정보" << endl;
		this->arr[i]->showInfo();
	}
}

void AccountHandler::showMenu()
{
	cout << "\n";
	cout << "**MENU**" << endl;
	cout << "1. 계좌 개설" << endl;
	cout << "2. 입금" << endl;
	cout << "3. 출금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
}
