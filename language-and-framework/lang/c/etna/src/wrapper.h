/***************************************************************************
 *   Copyright (C) 2006 by Francesco Saverio Ferrara                       *
 *   saverix83@tiscali.it                                                  *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
/***************************************************************************
 *
 * File:          name
 *
 * P.N.:          no number assigned
 *
 * Product:       etna (easy text network application)
 *
 * Creation date: 3 august 2006
 *
 * Description:   Enter a description here
 *
 ***************************************************************************/

#ifndef _WRAPPER_H_
#define _WRAPPER_H_


#include "trasmissione.h"
#include "etna.h"


void netscan(threadinfo_t *arg, char *buffer, int maxlen);
void netprint(threadinfo_t *arg, char *buffer, int len);

#endif
