#include "Edge.h"


std::string Edge::toString() const
{
	std::string result;
	result = Utilities::stringPadding(m_rSrc.getID(), 15)  + " -> " + Utilities::stringPadding(m_rDst.getID(), 15);
	return result;

	// return m_Src.getID() + " -> " + m_Dst.getID();
}