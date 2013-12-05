// Sources: www.cplusplus.com/doc/tutorials/files

#include <iostream>                                                              //Used for cout and cin.
#include <iomanip>                                                              //Used for precision setting for cout.
#include <fstream>                                                               //Used to put output data into text file.
using namespace std;

int main() {
	double purchasePrice, salePrice, dividends, brokersPurchaseFee,
		brokersSaleFee, totalCost, stockCost, stockSaleValue, netSaleValue,
		totalRevenue, tax, profit, returnPercentage;
	int shares;                                                                           //All of the variables needed are called at the beginning of the function.

	cout << "Number of Shares?" << endl;                            //Get the user input for Shares, Purchase Price, Sale price and value of dividends.
	cin >> shares;
	cout << "Purchase Price?" << endl;
	cin >> purchasePrice;
	cout << "Sale Price?" << endl;
	cin >> salePrice;
	cout << "Value of Dividends" << endl;
	cin >> dividends;

	stockCost = purchasePrice * shares;                                 //Computes all the values needed to output pertinent data.
	brokersPurchaseFee = stockCost * 0.012;
	totalCost = brokersPurchaseFee + stockCost;
	stockSaleValue = salePrice * shares;
	brokersSaleFee = stockSaleValue * 0.012;
	netSaleValue = stockSaleValue - brokersSaleFee;
	profit = (netSaleValue + dividends)  - totalCost;
	returnPercentage = (((netSaleValue + dividends) / totalCost) - 1 ) * 100;
	tax = profit * 0.14;
	totalRevenue = profit - tax;

    cout << fixed << showpoint << setprecision(2);                  // Sets the precision level to two decimal places.
	cout << "Cost of stock: $" << stockCost << endl;                //Start of output.
	cout << "Broker's fee: $" << brokersPurchaseFee << endl;
	cout << "Total Cost: $" << totalCost << endl;
	cout << "Sale Value: $" << stockSaleValue << endl;
	cout << "Brokers Sale Fee: $" << brokersSaleFee << endl;
	cout << "Net Sale Value: $" << netSaleValue << endl;
	cout << "Profit: $" << profit << endl;
	cout << "Return on Investment: " << returnPercentage << "%" << endl;
	cout << "Tax on profit: $" << tax << endl;
	cout << "Total Revenue on stock: $" << totalRevenue << endl;

	ofstream testTextDoc;                                                           // This section sets up and outputs the data to a text file.
	testTextDoc.open("testTextdoc.txt", std::ios_base::app);    //Opens the textfile - and sets the write mode to append, this way a user could
                                                                                                    //run multiple tests and not worry about overwriting previous data.
	if (testTextDoc.is_open())                                                      // Checks to ensure the file is open.
	{
        testTextDoc << "PP: " << purchasePrice << "\n";            //Writes the various values to the test document.
        testTextDoc << "SP: " << salePrice << "\n";
        testTextDoc << "S: " << shares << "\n";
        testTextDoc << "D: " << dividends << "\n";
        testTextDoc << "BFP: " << brokersPurchaseFee << "\n";
        testTextDoc << "BFS: " << brokersSaleFee << "\n";
        testTextDoc << "CS: " << stockCost << "\n";
        testTextDoc << "TC: " << totalCost << "\n";
        testTextDoc << "SV: " << stockSaleValue << "\n";
        testTextDoc << "NV: " << netSaleValue << "\n";
        testTextDoc << "TR: " << totalRevenue << "\n";
        testTextDoc << "T: " << tax << "\n";
        testTextDoc << "P: " << profit <<  "\n";
        testTextDoc << "RP: " << returnPercentage << "\n";
        testTextDoc << "\n" << "\n";
        testTextDoc.close();
	}
	else cout << "Unable to open file";                                     //If the test document fails to open for some reason - informs user with this error message.
	return 0;
}
