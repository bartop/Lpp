
#include "BasicBoolean.hpp"

namespace Lpp{

namespace {

class BasicBoolean final : public Boolean{
public:
  BasicBoolean(bool _value);

  bool value() const final override;

private:
  const bool m_value;
};

BasicBoolean::BasicBoolean(bool _value)
	: m_value(_value)
{}

bool BasicBoolean::value() const {
	return m_value;
}

}

Unique<const Boolean> boolean(bool _value) {
	return makeUnique<BasicBoolean>(_value);
}

}
