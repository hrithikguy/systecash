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

#ifndef GNUCASH_SHEET_H
#define GNUCASH_SHEET_H


#include <gtk/gtk.h>
#include "split-register-model.h"
#include "table-allgui.h"
/** @ingroup Register
 * @addtogroup Gnome
 * @{
 */
/** @file systecash-sheet.h
 * @brief Public declarations of systecashSheet class.
 */

#define CELL_VPADDING 2
#define CELL_HPADDING 5


#define GNUCASH_TYPE_REGISTER     (systecash_register_get_type ())
#define GNUCASH_REGISTER(obj)     (G_TYPE_CHECK_INSTANCE_CAST((obj), GNUCASH_TYPE_REGISTER, systecashRegister))
#define GNUCASH_REGISTER_CLASS(k) (G_TYPE_CHECK_CLASS_CAST ((k), GNUCASH_TYPE_REGISTER))
#define GNUCASH_IS_REGISTER(o)    (G_TYPE_CHECK_INSTANCE_TYPE((o), GNUCASH_TYPE_REGISTER))


#define GNUCASH_TYPE_SHEET     (systecash_sheet_get_type ())
#define GNUCASH_SHEET(obj)     (G_TYPE_CHECK_INSTANCE_CAST((obj), GNUCASH_TYPE_SHEET, systecashSheet))
#define GNUCASH_SHEET_CLASS(k) (G_TYPE_CHECK_CLASS_CAST ((k), GNUCASH_TYPE_SHEET))
#define GNUCASH_IS_SHEET(o)    (G_TYPE_CHECK_INSTANCE_TYPE((o), GNUCASH_TYPE_SHEET))


typedef struct _SheetBlockStyle SheetBlockStyle;
typedef struct _systecashSheet systecashSheet;
typedef struct _systecashSheetClass systecashSheetClass;
typedef struct _systecashRegister systecashRegister;
typedef struct _systecashRegisterClass systecashRegisterClass;


typedef struct
{
    /** The style for this block */
    SheetBlockStyle *style;

    gint origin_x; /** x origin of block */
    gint origin_y; /** y origin of block */

    gboolean visible; /** is block visible */
} SheetBlock;


GType      systecash_sheet_get_type (void);
GtkWidget *systecash_sheet_new (Table *table);

void systecash_sheet_table_load (systecashSheet *sheet, gboolean do_scroll);

void systecash_sheet_recompute_block_offsets (systecashSheet *sheet);

GType systecash_register_get_type (void);

/** this already has scrollbars attached */
GtkWidget *systecash_register_new (Table *table);

SheetBlock *systecash_sheet_get_block (systecashSheet *sheet,
                                     VirtualCellLocation vcell_loc);

gint systecash_sheet_col_max_width (systecashSheet *sheet,
                                  gint virt_col, gint cell_col);

void systecash_sheet_redraw_all (systecashSheet *sheet);
void systecash_sheet_redraw_help (systecashSheet *sheet);

void systecash_sheet_redraw_block (systecashSheet *sheet,
                                 VirtualCellLocation vcell_loc);

void systecash_sheet_cursor_set (systecashSheet *gsheet, VirtualLocation virt_loc);

const char * systecash_sheet_modify_current_cell(systecashSheet *sheet,
        const gchar *new_text);

gboolean systecash_sheet_block_set_from_table (systecashSheet *sheet,
        VirtualCellLocation vcell_loc);

void systecash_sheet_set_scroll_region (systecashSheet *sheet);

void systecash_sheet_cursor_set_from_table (systecashSheet *sheet,
        gboolean do_scroll);

void systecash_sheet_compute_visible_range (systecashSheet *sheet);

void systecash_sheet_make_cell_visible (systecashSheet *sheet,
                                      VirtualLocation virt_loc);

void systecash_sheet_show_range (systecashSheet *sheet,
                               VirtualCellLocation start_loc,
                               VirtualCellLocation end_loc);

void systecash_sheet_update_adjustments (systecashSheet *sheet);

void systecash_sheet_set_window (systecashSheet *sheet, GtkWidget *window);

void systecash_register_goto_virt_cell (systecashRegister *reg,
                                      VirtualCellLocation vcell_loc);

void systecash_register_goto_virt_loc (systecashRegister *reg,
                                     VirtualLocation virt_loc);

void systecash_register_goto_next_virt_row (systecashRegister *reg);

typedef gboolean (*VirtualLocationMatchFunc) (VirtualLocation virt_loc,
        gpointer user_data);

void systecash_register_goto_next_matching_row (systecashRegister *reg,
        VirtualLocationMatchFunc match,
        gpointer user_data);

void systecash_register_attach_popup(systecashRegister *reg, GtkWidget *popup,
                                   gpointer data);

gboolean systecash_register_has_selection (systecashRegister *reg);
void systecash_register_cut_clipboard (systecashRegister *reg);
void systecash_register_copy_clipboard (systecashRegister *reg);
void systecash_register_paste_clipboard (systecashRegister *reg);
void systecash_register_refresh_from_prefs (systecashRegister *reg);
void systecash_register_set_moved_cb (systecashRegister *reg,
                                    GFunc cb, gpointer cb_data);

systecashSheet *systecash_register_get_sheet (systecashRegister *reg);

GdkColor *get_gtkrc_color (systecashSheet *sheet, RegisterColor field_type);
/** @} */
#endif
