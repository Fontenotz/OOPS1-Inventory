#include<iostream.h>
#include<string.h>

double totalcost=0.0;              // A GLOBAL VARIABLE

class tool
{
private:
	char name;
    double cost;
	int inventory;
public:
    tool();
	void purchasetool(char choice);
}Hammer,Wrench,Screwdriver,Plane;

tool::tool()
{
	Hammer.name='H';
	Hammer.cost=24.95;
	Hammer.inventory=37;
	Wrench.name='W';
	Wrench.cost=12.46;
	Wrench.inventory=234;
	Screwdriver.name='S';
	Screwdriver.cost=8.55;
	Screwdriver.inventory=396;
	Plane.name='P';
	Plane.cost=24.99;
	Plane.inventory=34;
}

void tool::purchasetool(char choice)
{
	if (Hammer.name==choice)
	{
		cout<<"You have purchased a Hammer for $"<<Hammer.cost<<endl;
		totalcost=totalcost+Hammer.cost;
		Hammer.inventory--;
	}
	else if (Wrench.name==choice)
	{
		cout<<"You have purchased a Wrench for $"<<Wrench.cost<<endl;
		totalcost=totalcost+Wrench.cost;
		Wrench.inventory--;
	}
	else if (Screwdriver.name==choice)
	{
		cout<<"You have purchased a Screwdriver for $"<<Screwdriver.cost<<endl;
        totalcost=totalcost+Screwdriver.cost;
		Screwdriver.inventory--;
	}
	else if (Plane.name==choice)
	{
		cout<<"You have purchased a Plane for $"<<Plane.cost<<endl;
		totalcost=totalcost+Plane.cost;
		Plane.inventory--;
	}

	else
		cout<<"Item is not available."<<endl;
}


int main()
{
	char user_choice;
	cout<<"What tool would you like to purchase?"<<endl;
	cout<<"<H>ammer  <W>rench   <S>crewdriver    <P>lane "<<endl;
	cin>>user_choice;
	tool thistool;
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
	}

	cout<<"Your final bill is: $"<<totalcost<<endl;

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