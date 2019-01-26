#ifndef BIGNUMBER_HPP
#define BIGNUMBER_HPP

#include <iostream>
#include <string>
#include "container.hpp"

class BigNumber
{
	using Numbers = std::vector<unsigned>;
public:
	BigNumber();
	BigNumber(std::string const&);
	/**
	* Operations
	*/
	BigNumber& operator=(BigNumber const& );
	BigNumber& operator=(std::string const& );
	BigNumber& operator+=(BigNumber const& );
  
	friend BigNumber operator+(BigNumber const& , BigNumber const& );
	friend std::ostream& operator<<(std::ostream& , BigNumber const& );
private:
  /**
  * Data
  */
	bool m_signed;
	Numbers m_data;
};

#endif /* #ifndef BIGNUMBER_HPP */

