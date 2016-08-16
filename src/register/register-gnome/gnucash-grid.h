/********************************************************************\
 * This program is free software; you can redistribute it and/or    *
 * modify it under the terms of the GNU General Public License as   *
 * published by the Free Software Foundation; either version 2 of   *
 * the License, or (at your option) any later version.              *
 *                                                                  *
 * This program is distributed in the hope that it will be useful,  *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of   *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    *
 * GNU General Public License for more details.                     *
 *                                                                  *
 * You should have received a copy of the GNU General Public License*
 * along with this program; if not, contact:                        *
 *                                                                  *
 * Free Software Foundation           Voice:  +1-617-542-5942       *
 * 51 Franklin Street, Fifth Floor    Fax:    +1-617-542-2652       *
 * Boston, MA  02110-1301,  USA       gnu@gnu.org                   *
 *                                                                  *
\********************************************************************/

#ifndef GNUCASH_GRID_H
#define GNUCASH_GRID_H

#include "table-allgui.h"
#include "systecash-sheet.h"

/** @ingroup Register
 * @addtogroup Gnome
 * @{
 */
/** @file systecash-grid.h
 * @brief systecashGrid declarations
 */

#define GNUCASH_TYPE_GRID     (systecash_grid_get_type ())
#define GNUCASH_GRID(obj)     (G_TYPE_CHECK_INSTANCE_CAST((obj), GNUCASH_TYPE_GRID, systecashGrid))
#define GNUCASH_GRID_CLASS(k) (G_TYPE_CHECK_CLASS_CAST ((k), GNUCASH_TYPE_GRID, systecashGridClass))
#define GNUCASH_IS_GRID(o)    (G_TYPE_CHECK_INSTANCE_TYPE((o), GNUCASH_TYPE_GRID))

typedef struct _systecashGrid systecashGrid;
typedef struct _systecashGridClass systecashGridClass;


GType      systecash_grid_get_type (void);
GtkWidget *systecash_grid_new 	 (systecashSheet *sheet);

gboolean   systecash_grid_find_loc_by_pixel (systecashGrid *grid, gint x, gint y,
        VirtualLocation *vcell_loc);

void       systecash_draw_hatching (GdkDrawable *drawable, GdkGC *gc,
                                  int x, int y, int width, int height);
/** @} */
#endif /* GNUCASH_GRID_H */
