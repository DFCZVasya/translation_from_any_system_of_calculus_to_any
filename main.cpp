#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <math.h>

using namespace std;

void getNumberParts(int *first_part, int *second_part, int first_part_lenth, int second_part_lenth, string input_number);
void getNumberInDecimal(int *first_part, int *second_part, int first_part_lenth, int second_part_lenth, 
	int input_s, int *first_num_in_decimal, float *second_num_in_decimal);
//nice size of name, and it's so because i can't return more than one value, but in python............................ 

void getNumberInWhatever(int first_num, float second_num, int output_s);

int main()
{
	string input_number, input_s, output_s;

	cin >> input_number;
	cin >> input_s;
	cin >> output_s;

	int inp_s = stoi(input_s), out_s = stoi(output_s);

	int *first_part, *second_part;

	int first_part_lenth, second_part_lenth;

	for (int i = 0; i < input_number.length(); i++)
	{
		if (input_number[i] == '.' || input_number[i] == input_number.length() - 1) first_part_lenth = i;
	}
	//TO DO: read numbers without '.' 
	if (input_number.length() == first_part_lenth + 1) second_part_lenth = 0;
	else second_part_lenth = input_number.length() - (first_part_lenth + 1);

	first_part = new int[first_part_lenth];
	if (second_part_lenth != 0) second_part = new int[second_part_lenth];
	else second_part = 0;
	
	getNumberParts(first_part, second_part, first_part_lenth, second_part_lenth, input_number); //so after this function i have two arrays whith numbers, 60 lines vs 0 in python bcs there i instantly translated the lines into decimal :)))))), but here...................................

	int first_num_in_decimal = 0; 
	float second_num_in_decimal = 0; //MORE VALUES, why not)

	getNumberInDecimal(first_part, second_part, first_part_lenth, second_part_lenth,
		inp_s, &first_num_in_decimal, &second_num_in_decimal); //so here i have decimal numbers :)


	getNumberInWhatever(first_num_in_decimal, second_num_in_decimal, out_s);


	system("pause");
	return 0;
}


void getNumberParts(int *first_part, int *second_part, int first_part_lenth, int second_part_lenth, string input_number)
{
	

	for (int i = 0; i < first_part_lenth; i++)
	{
		first_part[i] = (input_number[i] + '0') - 96; //don't work without this :(
		if (first_part[i] >= 17) first_part[i] = first_part[i] - 7; //and here too :(
	}

	if (second_part_lenth != 0)
	{
		for (int i = 0; i < second_part_lenth; i++)
		{
			second_part[i] = (input_number[i + first_part_lenth + 1] + '0') - 96; // and here ofc :(
			if (second_part[i] >= 17) second_part[i] = second_part[i] - 7; // and here :((((((
		}
	}
}

void getNumberInDecimal(int *first_part, int *second_part, int first_part_lenth, int second_part_lenth, 
	int input_s, int *first_num_in_decimal, float *second_num_in_decimal)
{
	int first_sum = 0; 
	float second_sum = 0.0;
	for (int i = 0; i < first_part_lenth; i++)
	{
		first_sum += first_part[i] * pow(input_s, first_part_lenth - i - 1);
	}

	if (second_part_lenth != 0)
	{
		for (int i = 0; i < second_part_lenth; i++)
		{
			second_sum += second_part[i] * pow(input_s, (i+1) * -1);
		}
	}
	*first_num_in_decimal = first_sum;
	*second_num_in_decimal = second_sum;
}

char findSymbol(int position)
{
	string symbol_list = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	return symbol_list[position];
}

void getNumberInWhatever(int first_num, float second_num, int output_s)
{
	string new_first_number(""), new_second_number("");

	int ost;

	while (first_num != 0)
	{
		ost = first_num % output_s;
		first_num = first_num / output_s;
		new_first_number += findSymbol(ost);
		
	}

	if (second_num == 0)
	{
		new_second_number = "0";
	}
	else
	{
		int i = 0;
		while (second_num != 0.0)
		{
			second_num = second_num * output_s;
			if ((int)second_num > 0)
			{
				new_second_number += findSymbol((int)second_num);
				second_num -= (int)second_num;
			}
			else
			{
				new_second_number += "0";
			}
			i++;
			if (i == 10) break;
		}
	}
	string new_first_num2 = new_first_number;

	for (int i = 0; i < new_first_number.length(); i++)
	{
		new_first_num2[i] = new_first_number[new_first_number.length() - 1 - i];
	} //how i did it in python: new_n = new_n[::-1] .............  very compact!!! :)

	cout << new_first_num2 << " . " << new_second_number << endl;
}

//148 vs 66 in Python, but in python i also have many prints, so..........................................