#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
using namespace std;

auto add(string a, string b)
{
	string r;
	auto a_digit = a.rbegin();
	auto b_digit = b.rbegin();
	auto t = 0;
	while (a_digit != a.rend() || b_digit != b.rend())
	{
		auto s = t;
		if (a_digit != a.rend())
		{
			s = s + *a_digit - '0';
			++a_digit;
		}
		if (b_digit != b.rend())
		{
			s = s + *b_digit - '0';
			++b_digit;
		}
		r.insert(r.begin(), '0' + s % 10);
		t = s / 10;
	}
	if (t > 0)
	{
		r.insert(r.begin(), '0' + t);
	}
	return r;
}

int main()
{
	string operation;

	cout << "Introduceti operatia: ";
	cin >> operation;
	auto op_pos = operation.find_first_of("+-*:/");
	auto op = operation[op_pos];
	auto first_number = operation.substr(0u, op_pos);
	auto second_number = operation.substr(op_pos + 1u);
	auto result = add(first_number, second_number);
	vector<size_t> lengths{ first_number.size(), second_number.size(), result.size() };
	auto max_el = max_element(lengths.begin(), lengths.end());
	auto length = *max_el;
	cout << '\t' << setw(length) << first_number << op << endl;
	cout << '\t' << setw(length) << second_number << endl;
	cout << '\t' << string(length, static_cast<unsigned char>(196)) << endl;
	cout << '\t' << setw(length) << result << endl;
	return 0;
}
