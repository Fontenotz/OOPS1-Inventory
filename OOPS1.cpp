#include<iostream.h>
#include<string.h>
#include<stdlib.h>

double totalcost=0.0;
int totool[3];
int number_of_customers=0;

class tool
{
private:
	char name;
    double cost;
	int inventory;
	int purchases;
public:
    tool();
	void purchasetool(char choice);
	void bill();
	void listinventory();
}Hammer,Wrench,Screwdriver,Plane;

tool::tool()
{
	Hammer.name='H';
	Hammer.cost=24.95;
	Hammer.inventory=37;
	Hammer.purchases=0;
	Wrench.name='W';
	Wrench.cost=12.46;
	Wrench.inventory=234;
	Wrench.purchases=0;
	Screwdriver.name='S';
	Screwdriver.cost=8.55;
	Screwdriver.inventory=396;
	Screwdriver.purchases=0;
	Plane.name='P';
	Plane.cost=24.99;
	Plane.inventory=34;
	Plane.purchases=0;
}

void tool::purchasetool(char choice)
{
	if (Hammer.name==choice)
	{
		cout<<"You have purchased a Hammer for $"<<Hammer.cost<<endl;
		totool[0]++;
		Hammer.purchases++;
	}
	else if (Wrench.name==choice)
	{
		cout<<"You have purchased a Wrench for $"<<Wrench.cost<<endl;
		totool[1]++;
		Wrench.purchases++;
	}
	else if (Screwdriver.name==choice)
	{
		cout<<"You have purchased a Screwdriver for $"<<Screwdriver.cost<<endl;
		totool[2]++;
		Screwdriver.purchases++;
	}
	else if (Plane.name==choice)
	{
		cout<<"You have purchased a Plane for $"<<Plane.cost<<endl;
		totool[3]++;
		Plane.purchases++;
	}

	else
		cout<<"Item is not available."<<endl;
}

void tool::bill()
{
	cout<<"Hammers purchased:      "<<Hammer.purchases<<"  $"<<Hammer.purchases*Hammer.cost<<endl;
	cout<<"Wrenches purchased:     "<<Wrench.purchases<<"  $"<<Wrench.purchases*Wrench.cost<<endl;
	cout<<"Screwdrivers purchased: "<<Screwdriver.purchases<<"  $"<<Screwdriver.purchases*Screwdriver.cost<<endl;
	cout<<"Planes purchased:       "<<Plane.purchases<<"  $"<<Plane.purchases*Plane.cost<<endl;
	totalcost=Hammer.purchases*Hammer.cost+Wrench.purchases*Wrench.cost+Screwdriver.purchases*Screwdriver.cost+Plane.purchases*Plane.cost;
	cout<<"Total:                  "<<"   $"<<totalcost<<endl;
	totalcost=0.0;

	system("pause");

}

void tool::listinventory()
{
	cout<<"Hammers in inventory:      "<<Hammer.inventory-totool[0]<<endl;
	cout<<"Wrenches in inventory:     "<<Wrench.inventory-totool[1]<<endl;
	cout<<"Screwdrivers in inventory: "<<Screwdriver.inventory-totool[2]<<endl;
	cout<<"Planes in inventory:       "<<Plane.inventory-totool[3]<<endl;
}

int main()
{
	char user_choice;
	tool thistool;
	system("cls");
	if (number_of_customers%4==0)
	{
		thistool.listinventory();
		system("pause");
		number_of_customers++;
		main();
			}
	else
	{

		cout<<"Hello new customer "<<number_of_customers<<endl;
		cout<<"What tool would you like to purchase?"<<endl;
		cout<<"<H>ammer  <W>rench   <S>crewdriver    <P>lane "<<endl;
		cin>>user_choice;
		char response;
		response='y';
		while (response=='y' || response=='Y')
		{
			thistool.purchasetool(user_choice);
			cout<<"Do you want to buy another tool?"<<endl;
			cin>>response;
			if (response=='Y' || response=='y')
			{
		    	cout<<"What tool would you like to purchase?"<<endl;
    			cout<<"<H>ammer  <W>rench   <S>crewdriver    <P>lane "<<endl;
    			cin>>user_choice;
			 }
			thistool.bill();
		}
		number_of_customers++;
		main();
	}

	return 0;
}

// Use the following data to 'upgrade' this program
// A Wrench costs 12.46  and there are presently  234 in stock
// A Screwdriver costs 8.55  and there are presently 396 in stock
// A Plane costs 24.99 and there are presently 34 in stock

// Allow the customer to pick any of the 4 tools
// Allow the user to purchase multiple tools and print their 'bill'.
// Print out the inventory for each item after 4 customers have been serviced
// Print the inventory after 40 customers have been serviced by using FILES