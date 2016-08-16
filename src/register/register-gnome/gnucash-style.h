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

#ifndef GNUCASH_STYLE_H
#define GNUCASH_STYLE_H

#include "systecash-sheet.h"
/** @ingroup Register
 * @addtogroup Gnome
 * @{
 */
/** @file systecash-style.h
 * @brief Styling functions for RegisterGnome.
 */
typedef struct
{
    gint pixel_height;
    gint pixel_width;

    gint origin_x;
    gint origin_y;

    gboolean can_span_over;
} CellDimensions;

typedef struct
{
    gint nrows;
    gint ncols;

    /* totals, in pixels */
    gint height;
    gint width;

    /* per cell parameters */
    GTable *cell_dimensions;

    gint refcount;
} BlockDimensions;

struct _SheetBlockStyle
{
    CellBlock * cursor;

    gint nrows;
    gint ncols;

    BlockDimensions *dimensions;

    gint refcount;
};


gboolean systecash_style_init (void);

void systecash_sheet_style_init(void);

gint systecash_style_col_is_resizable (SheetBlockStyle *style, int col);

CellDimensions * systecash_style_get_cell_dimensions (SheetBlockStyle *style,
        int row, int col);

void systecash_sheet_set_col_width (systecashSheet *sheet, int col, int width);

gint systecash_style_row_width(SheetBlockStyle *style, int row);

void systecash_sheet_styles_set_dimensions (systecashSheet *sheet, int width);

void systecash_sheet_style_destroy (systecashSheet *sheet, SheetBlockStyle *style);

void systecash_sheet_clear_styles (systecashSheet *sheet);
void systecash_sheet_create_styles (systecashSheet *sheet);

void systecash_sheet_compile_styles (systecashSheet *sheet);

void systecash_sheet_styles_recompile (systecashSheet *sheet);

SheetBlockStyle *systecash_sheet_get_style (systecashSheet *sheet,
        VirtualCellLocation vcell_loc);

SheetBlockStyle *
systecash_sheet_get_style_from_table (systecashSheet *sheet,
                                    VirtualCellLocation vcell_loc);

SheetBlockStyle *
systecash_sheet_get_style_from_cursor (systecashSheet *sheet,
                                     const char *cursor_name);

void systecash_sheet_style_get_cell_pixel_rel_coords (SheetBlockStyle *style,
        gint cell_row,
        gint cell_col,
        gint *x, gint *y,
        gint *w, gint *h);

void systecash_style_ref   (SheetBlockStyle *style);
void systecash_style_unref (SheetBlockStyle *style);

void systecash_sheet_get_borders (systecashSheet *sheet, VirtualLocation virt_loc,
                                PhysicalCellBorders *borders);

typedef GHashTable *GNCHeaderWidths;

GNCHeaderWidths gnc_header_widths_new (void);
void gnc_header_widths_destroy (GNCHeaderWidths widths);
void gnc_header_widths_set_width (GNCHeaderWidths widths,
                                  const char *cell_name,
                                  int width);
int gnc_header_widths_get_width (GNCHeaderWidths widths,
                                 const char *cell_name);

void systecash_sheet_get_header_widths (systecashSheet *sheet,
                                      GNCHeaderWidths widths);
void systecash_sheet_set_header_widths (systecashSheet *sheet,
                                      GNCHeaderWidths widths);
/** @} */
#endif
