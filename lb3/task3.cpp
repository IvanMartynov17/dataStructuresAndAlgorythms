#include <iostream>
#include <cstdlib>
using namespace std;

enum paymentType
{
	cash,
	card,
	bankTransfer
};

union PaymentData
{
	int cashAmount;

	struct
	{
		int cardNumber;
		int price;
	} card;

	struct
	{
		int accountNumber;
		int price;
	} transfer;
};

struct Payment 
{
	int number;
	paymentType type;
	PaymentData data;
};




int main()
{
	Payment p[5];
	int i, cashCount = 0, cardCount = 0, transferCount = 0, payType;
	for (i = 0; i < 5; i++)
	{ 
		cout << "\tPayment number: " << i + 1 << endl;

		cout << "Choose payment type (0-cash, 1-card, 2-bank transfer): ";
		cin >> payType;

		p[i].type = (paymentType)payType;

		if (p[i].type == cash)
		{
			cout << "Enter cash amount: ";
			cin >> p[i].data.cashAmount;
			cashCount++;
		}

		 if (p[i].type == card)
		{
			cout << "Enter card number: ";
			cin >> p[i].data.card.cardNumber;

			cout << "Enter price: ";
			cin >> p[i].data.card.price;
			cardCount++;
		}

		 if (p[i].type == bankTransfer)
		{
			cout << "Enter account number: ";
			cin >> p[i].data.transfer.accountNumber;

			cout << "Enter price: ";
			cin >> p[i].data.transfer.price;
			transferCount++;
		}
	}
	cout << "\t Payment information \t" << endl;

	for (i = 0; i < 5; i++)
	{
		cout << "Payment number: " << p[i].number << endl;

		if (p[i].type == cash)
		{
			cout << "Type: Cash" << endl;
			cout << "Amount: " << p[i].data.cashAmount << endl;
		}

		else if (p[i].type == card)
		{
			cout << "Type: Card" << endl;
			cout << "Card number: " << p[i].data.card.cardNumber << endl;
			cout << "Price: " << p[i].data.card.price << endl;
		}

		else if (p[i].type == bankTransfer)
		{
			cout << "Type: Bank Transfer" << endl;
			cout << "Account number: " << p[i].data.transfer.accountNumber << endl;
			cout << "Price: " << p[i].data.transfer.price << endl;
		}
	}
	cout << "\t Payment statistics \t" << endl;
	cout << "Cash payments: " << cashCount << endl;
	cout << "Card payments: " << cardCount << endl;
	cout << "Bank transfers: " << transferCount << endl;


	return 0;
}