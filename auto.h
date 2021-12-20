#pragma once
#include "pch.h"
namespace backup
{
	template<typename T>
	class __declspec(dllexport) AUTO {
	private:
		T m_keep{};
	public:
		AUTO<T> inline operator= (const AUTO& copy) {
			m_keep = copy.m_keep;
			return *this;
		}
		AUTO multi(AUTO& copy, int multi) {
			copy.m_keep *= multi;
			return copy;
		}
		//Default constructer
		AUTO() {}
		//constructer
		AUTO(T var)
			: m_keep(var)
		{

		}
		//copy constructer
		AUTO(const AUTO& p2) { m_keep = p2.m_keep; }
		//move constructer
		AUTO(AUTO&& p_AUTO) {
			AUTO* newAUTO = new AUTO;

			delete newAUTO;
		}
		friend class backup;
		friend __declspec(dllexport) std::ostream& operator<<(std::ostream& os, const AUTO<T>& dt) {
			os << dt.m_keep;
			return os;
		}
	};
}