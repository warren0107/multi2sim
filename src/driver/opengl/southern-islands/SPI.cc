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

#include <src/driver/opengl/OpenGLDriver.h>
#include "ScanConverter.h"
#include "SPI.h"

namespace SI
{

std::unique_ptr<SPI> SPI::instance;

SPI *SPI::getInstance()
{
	opengl_driver = Driver::OpenGLSIDriver::getInstance();

	// Instance already exists
	if (instance.get())
		return instance.get();
	
	// Create instance
	instance.reset(new SPI());
	return instance.get();	
}

DataInitVGPRs::DataInitVGPRs(const PixelInfo *pixel_info)
{
	x = pixel_info->getX();
	y = pixel_info->getY();
	i = pixel_info->getI();
	j = pixel_info->getJ();
}

DataInitLDS::DataInitLDS(const char *buffer, unsigned size)
{
	lds.reset(new char[size]);
	for (unsigned i = 0; i < size; ++i)
		lds[i] = buffer[i];
}

}  // namespace SI