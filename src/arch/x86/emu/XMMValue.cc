/*
 *  Multi2Sim
 *  Copyright (C) 2012  Rafael Ubal (ubal@ece.neu.edu)
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include <lib/cpp/String.h>

#include "XMMValue.h"


using namespace misc;

namespace x86
{


void XMMValue::DumpAsChar(std::ostream &os) const
{
	std::string comma;
	os << "{ ";
	for (int i = 0; i < 16; i++)
	{
		os << comma << StringFmt("%02x", as_uchar[i]);
		comma = ", ";
	}
	os << " }";
}


void XMMValue::DumpAsShort(std::ostream &os) const
{
	std::string comma;
	os << "{ ";
	for (int i = 0; i < 8; i++)
	{
		os << comma << StringFmt("%04x", as_ushort[i]);
		comma = ", ";
	}
	os << " }";
}


void XMMValue::DumpAsInt(std::ostream &os) const
{
	os << StringFmt("{ %08x, %08x, %08x, %08x }",
			as_uint[0], as_uint[1], as_uint[2], as_uint[3]);
}


void XMMValue::DumpAsInt64(std::ostream &os) const
{
	os << StringFmt("{ %016llx, %016llx }",
			as_uint64[0], as_uint64[1]);
}


void XMMValue::DumpAsFloat(std::ostream &os) const
{
	os << StringFmt("{ %g, %g, %g, %g }",
			as_float[0], as_float[1], as_float[2], as_float[3]);
}


void XMMValue::DumpAsDouble(std::ostream &os) const
{
	os << StringFmt("{ %g, %g }",
			as_double[0], as_double[1]);
}


}  // namespace x86

