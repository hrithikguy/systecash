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

#ifndef GNUCASH_CURSOR_H
#define GNUCASH_CURSOR_H

#include "systecash-grid.h"
#include "systecash-sheet.h"
#include <libgnomecanvas/libgnomecanvas.h>

/** @ingroup Register
 * @addtogroup Gnome
 * @{
 */
/** @file systecash-cursor.h
 * @brief Public declarations for systecashCursor class
 */
#define GNUCASH_TYPE_CURSOR     (systecash_cursor_get_type ())
#define GNUCASH_CURSOR(obj)     (G_TYPE_CHECK_INSTANCE_CAST ((obj), GNUCASH_TYPE_CURSOR, systecashCursor))
#define GNUCASH_CURSOR_CLASS(k) (G_TYPE_CHECK_CLASS_CAST ((k), GNUCASH_TYPE_CURSOR, systecashCursorClass))
#define GNUCASH_IS_CURSOR(obj)  (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GNUCASH_TYPE_CURSOR))

#define GNUCASH_TYPE_ITEM_CURSOR     (systecash_item_cursor_get_type ())
#define GNUCASH_ITEM_CURSOR(obj)     (G_TYPE_CHECK_INSTANCE_CAST ((obj), GNUCASH_TYPE_ITEM_CURSOR, systecashItemCursor))
#define GNUCASH_ITEM_CURSOR_CLASS(k) (G_TYPE_CHECK_CLASS_CAST ((k), GNUCASH_TYPE_ITEM_CURSOR, systecashItemCursorClass))
#define GNUCASH_IS_ITEM_CURSOR(o)    (G_TYPE_CHECK_INSTANCE_TYPE ((o), GNUCASH_TYPE_ITEM_CURSOR))


GType    systecash_item_cursor_get_type (void);
GType    systecash_cursor_get_type (void);


enum
{
    GNUCASH_CURSOR_CELL,
    GNUCASH_CURSOR_BLOCK,
    GNUCASH_CURSOR_NUM
};


typedef struct
{
    GnomeCanvasItem canvas_item;

    gint type;

    gint row;
    gint col;

    /* precomputed pixel coords for the item cursor*/
    gint x, y, w, h;
} systecashItemCursor;


typedef struct
{
    GnomeCanvasGroup canvas_group;

    GnomeCanvasItem *cursor[GNUCASH_CURSOR_NUM];

    systecashSheet *sheet;
    systecashGrid *grid;

    /* precomputed pixel coords for the block cursor*/
    gint x, y, w, h;

    GdkGC *gc;
    SheetBlockStyle *style;
} systecashCursor;


typedef struct
{
    GnomeCanvasItemClass parent_class;
} systecashItemCursorClass;


typedef struct
{
    GnomeCanvasGroupClass parent_class;
} systecashCursorClass;


GnomeCanvasItem *systecash_cursor_new (GnomeCanvasGroup *parent);

void systecash_cursor_get_virt (systecashCursor *cursor,
                              VirtualLocation *virt_loc);

void systecash_cursor_set (systecashCursor *cursor, VirtualLocation virt_loc);

void systecash_cursor_set_style (systecashCursor  *cursor, SheetBlockStyle *style);

void systecash_cursor_configure (systecashCursor *cursor);

/** @} */
#endif /* GNUCASH_CURSOR_H */
