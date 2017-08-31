
#pragma once

#include "Integer.hpp"

namespace Lpp{

class BasicInt final : public Integer {
public:
	BasicInt(int _int);

	IntegerExchangeFormat integerValue() const final override;

private:
	const int m_int;
};

}
