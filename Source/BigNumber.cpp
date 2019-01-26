#include <algorithm>

#include "BigNumber.hpp"

BigNumber operator+(BigNumber const& lhs, BigNumber const& rhs)
{
	BigNumber ret(lhs);
	ret += rhs;
	return ret;
}

std::ostream& operator<<(std::ostream& os, BigNumber const& bg)
{
	if(bg.m_signed)
		os << "-";
	unsigned i = bg.m_data.size();
	while (i--)
		os << bg.m_data[i];
	return os;
}

BigNumber::BigNumber() :
	m_signed(false)
{
}

BigNumber::BigNumber(std::string const& numbers) : 
	m_signed(numbers.size() ? numbers[0]=='-': false),
	m_data(m_signed ? numbers.size()-1:numbers.size())
{
	unsigned i = m_data.size();
	bool skip = m_signed;
	for(auto const& number : numbers)
	{
		if (skip)
		{
			skip = false; 
			continue;
		}
		m_data[--i] = number-'0';
	}
}

BigNumber & BigNumber::operator=(BigNumber const & rhs)
{
	// TODO: insert return statement here
	m_data = rhs.m_data;
	m_signed = rhs.m_signed;
	return *this;
}

BigNumber & BigNumber::operator=(std::string const & numbers)
{
	// TODO: insert return statement here
	m_signed = (numbers.size() ? numbers[0] == '-' : false);
	m_data.resize(m_signed ? numbers.size() - 1 : numbers.size());
	unsigned i = m_data.size();
	bool skip = m_signed;
	for (auto const& number : numbers)
	{
		if (skip)
		{
			skip = false;
			continue;
		}
		m_data[--i] = number - '0';
	}
	return *this;
}

BigNumber& BigNumber::operator+=(BigNumber const& rhs)
{
	unsigned carry = 0;
	/**
	* Get the larger one
	*/
	bool rhsLarger = (m_data.size() < rhs.m_data.size());
	unsigned larger = m_data.size(), smaller = rhs.m_data.size();
	if (rhsLarger)
	{
		std::swap(larger, smaller);
		m_data.resize(larger,0);
	}

	for (unsigned i = 0; larger > i; ++i)
	{
		unsigned rhsValue = (rhs.m_data.size() > i) ? rhs.m_data[i] : 0;

		m_data[i] += rhsValue + carry;
		if (m_data[i] > 9)
		{
			m_data[i] -= 10;
			carry = 1; //there a carry
		}
		else
		{
			carry = 0;
		}

		if (larger - 1 == i && carry)
		{
			m_data.push_back(carry);
		}
	}
	return *this;
}