/******************************************************************************
 *
 * Copyright(c) 2007 - 2017 Realtek Corporation.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of version 2 of the GNU General Public License as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 *****************************************************************************/

/* ************************************************************
 * include files
 * ************************************************************ */

#include "mp_precomp.h"
#include "../phydm_precomp.h"

#if (RTL8188F_SUPPORT == 1)

s8
odm_CCKRSSI_8188F(
	u8	LNA_idx,
	u8	VGA_idx
)
{
	s8	rx_pwr_all = 0x00;
	switch (LNA_idx) {
	case 7:
		if (VGA_idx <= 27)
			rx_pwr_all = -100 + 2 * (27 - VGA_idx);
		else
			rx_pwr_all = -100;
		break;

	case 5:
		rx_pwr_all = -74 + 2 * (21 - VGA_idx);
		break;

	case 3:
		rx_pwr_all = -60 + 2 * (20 - VGA_idx);
		break;

	case 1:
		rx_pwr_all = -44 + 2 * (19 - VGA_idx);
		break;

	default:
		break;
	}
	return	rx_pwr_all;
}
#endif
