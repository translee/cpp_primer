#include <iostream>
#include <string>
#include "Sales_data.h"
using namespace std;

Sales_data::Sales_data(istream& is)
{
	read(is, *this);
}

double Sales_data::avg_price() const
{
	if (units_sold)
		return revenue / units_sold;
	else
		return 0.0;
}

Sales_data& Sales_data::combine(const Sales_data& rhs)
{
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}

istream& read(istream& is, Sales_data& item)
{
	double price = 0.0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price * item.units_sold;
	return is;
}

ostream& print(ostream& os, const Sales_data& item)
{
	os << item.isbn() << " " << item.units_sold << " "
		<< item.revenue << " " << item.avg_price();
	return os;
}

Sales_data add(const Sales_data& lhs, const Sales_data& rhs)
{
	Sales_data sum = lhs;
	sum.combine(rhs);
	return sum;
}

//int main()
//{
//	Sales_data data1, data2;
//	double price = 0;
//	cin >> data1.bookNo >> data1.units_sold >> price;
//	data1.revenue = data1.units_sold * price;
//
//	cin >> data2.bookNo >> data2.units_sold >> price;
//	data2.revenue = data2.units_sold * price;
//
//	if (data1.bookNo == data2.bookNo)
//	{
//		unsigned totalCnt = data1.units_sold + data2.units_sold;
//		double totalRevenue = data1.revenue + data2.revenue;
//
//		cout << data1.bookNo << " " << totalCnt
//			<< " " << totalRevenue << " ";
//		if (totalCnt != 0)
//			cout << totalRevenue / totalCnt << endl;
//		else
//			cout << "(no sales)" << endl;
//	}
//	else
//	{
//		cerr << "Data must refer to the same ISBN" << endl;
//		return -1;
//	}
//}