/***************************************************************************
 *            test-gnc-uri-utils.c
 *
 *  Thu Sep 29 22:48:57 2005
 *  Copyright  2005  systecash team
 ****************************************************************************/
/*
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
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 *  02110-1301, USA.
 */

#include "config.h"
#include <stdlib.h>
#include <string.h>

#include <glib.h>
#include "qof.h"
#include "test-stuff.h"
#include "gnc-uri-utils.h"

struct test_strings_struct
{
    gchar *uri;
    gboolean want_password;
    gchar *protocol;
    gchar *hostname;
    gchar *username;
    gchar *password;
    gchar *path;
    gint32 port;
    gchar *created_uri;
    gchar *normalized_uri;
    gboolean is_file_protocol;
};

typedef struct test_strings_struct test_strings;

test_strings strs[] =
{
#ifndef G_OS_WIN32
    /* basic file tests in posix like environment */
    {
        "/test/path/file.systecash", FALSE,
        "file", NULL, NULL, NULL, "/test/path/file.systecash", 0,
        "file:///test/path/file.systecash",
        "file:///test/path/file.systecash", TRUE
    },
    {
        "file:///test/path/file.systecash", FALSE,
        "file", NULL, NULL, NULL, "/test/path/file.systecash", 0,
        "file:///test/path/file.systecash",
        "file:///test/path/file.systecash", TRUE
    },
    {
        "xml:///test/path/file.systecash", FALSE,
        "xml", NULL, NULL, NULL, "/test/path/file.systecash", 0,
        "xml:///test/path/file.systecash",
        "xml:///test/path/file.systecash", TRUE
    },
    {
        "sqlite3:///test/path/file.systecash", FALSE,
        "sqlite3", NULL, NULL, NULL, "/test/path/file.systecash", 0,
        "sqlite3:///test/path/file.systecash",
        "sqlite3:///test/path/file.systecash", TRUE
    },
#else
    /* basic file tests in windows environment */
    {
        "c:\\test\\path\\file.systecash", FALSE,
        "file", NULL, NULL, NULL, "c:\\test\\path\\file.systecash", 0,
        "file://c:\\test\\path\\file.systecash",
        "file://c:\\test\\path\\file.systecash", TRUE
    },
    {
        "file://c:\\test\\path\\file.systecash", FALSE,
        "file", NULL, NULL, NULL, "c:\\test\\path\\file.systecash", 0,
        "file://c:\\test\\path\\file.systecash",
        "file://c:\\test\\path\\file.systecash", TRUE
    },
    {
        "xml://c:\\test\\path\\file.systecash", FALSE,
        "xml", NULL, NULL, NULL, "c:\\test\\path\\file.systecash", 0,
        "xml://c:\\test\\path\\file.systecash",
        "xml://c:\\test\\path\\file.systecash", TRUE
    },
    {
        "sqlite3://c:\\test\\path\\file.systecash", FALSE,
        "sqlite3", NULL, NULL, NULL, "c:\\test\\path\\file.systecash", 0,
        "sqlite3://c:\\test\\path\\file.systecash",
        "sqlite3://c:\\test\\path\\file.systecash", TRUE
    },
#endif
    /* basic database tests */
    {
        "mysql://www.systecash.org/systecash", FALSE,
        "mysql", "www.systecash.org", NULL, NULL, "systecash", 0,
        "mysql://www.systecash.org/systecash",
        "mysql://www.systecash.org/systecash", FALSE
    },
    {
        "mysql://www.systecash.org/systecash", TRUE,
        "mysql", "www.systecash.org", NULL, NULL, "systecash", 0,
        "mysql://www.systecash.org/systecash",
        "mysql://www.systecash.org/systecash", FALSE
    },
    {
        "mysql://dbuser@www.systecash.org/systecash", FALSE,
        "mysql", "www.systecash.org", "dbuser", NULL, "systecash", 0,
        "mysql://dbuser@www.systecash.org/systecash",
        "mysql://dbuser@www.systecash.org/systecash", FALSE
    },
    {
        "mysql://dbuser@www.systecash.org/systecash", TRUE,
        "mysql", "www.systecash.org", "dbuser", NULL, "systecash", 0,
        "mysql://dbuser@www.systecash.org/systecash",
        "mysql://dbuser@www.systecash.org/systecash", FALSE
    },
    {
        "mysql://dbuser:dbpass@www.systecash.org/systecash", FALSE,
        "mysql", "www.systecash.org", "dbuser", "dbpass", "systecash", 0,
        "mysql://dbuser:dbpass@www.systecash.org/systecash",
        "mysql://dbuser@www.systecash.org/systecash", FALSE
    },
    {
        "mysql://dbuser:dbpass@www.systecash.org/systecash", TRUE,
        "mysql", "www.systecash.org", "dbuser", "dbpass", "systecash", 0,
        "mysql://dbuser:dbpass@www.systecash.org/systecash",
        "mysql://dbuser:dbpass@www.systecash.org/systecash", FALSE
    },
    {
        "postgres://www.systecash.org/systecash", FALSE,
        "postgres", "www.systecash.org", NULL, NULL, "systecash", 0,
        "postgres://www.systecash.org/systecash",
        "postgres://www.systecash.org/systecash", FALSE
    },
    {
        "postgres://www.systecash.org/systecash", TRUE,
        "postgres", "www.systecash.org", NULL, NULL, "systecash", 0,
        "postgres://www.systecash.org/systecash",
        "postgres://www.systecash.org/systecash", FALSE
    },
    {
        "postgres://dbuser@www.systecash.org/systecash", FALSE,
        "postgres", "www.systecash.org", "dbuser", NULL, "systecash", 0,
        "postgres://dbuser@www.systecash.org/systecash",
        "postgres://dbuser@www.systecash.org/systecash", FALSE
    },
    {
        "postgres://dbuser@www.systecash.org/systecash", TRUE,
        "postgres", "www.systecash.org", "dbuser", NULL, "systecash", 0,
        "postgres://dbuser@www.systecash.org/systecash",
        "postgres://dbuser@www.systecash.org/systecash", FALSE
    },
    {
        "postgres://dbuser:dbpass@www.systecash.org/systecash", FALSE,
        "postgres", "www.systecash.org", "dbuser", "dbpass", "systecash", 0,
        "postgres://dbuser:dbpass@www.systecash.org/systecash",
        "postgres://dbuser@www.systecash.org/systecash", FALSE
    },
    {
        "postgres://dbuser:dbpass@www.systecash.org/systecash", TRUE,
        "postgres", "www.systecash.org", "dbuser", "dbpass", "systecash", 0,
        "postgres://dbuser:dbpass@www.systecash.org/systecash",
        "postgres://dbuser:dbpass@www.systecash.org/systecash", FALSE
    },
    /* password with lots of ugly characters in it (potentially conflicting with uri syntax) */
    {
        "postgres://dbuser:*#bad35:@xx@www.systecash.org/systecash", TRUE,
        "postgres", "www.systecash.org", "dbuser", "*#bad35:@xx", "systecash", 0,
        "postgres://dbuser:*#bad35:@xx@www.systecash.org/systecash",
        "postgres://dbuser:*#bad35:@xx@www.systecash.org/systecash", FALSE
    },
    /* uri with custom port number, and hide password in normalized uri */
    {
        "postgres://dbuser:dbpass@www.systecash.org:744/systecash", FALSE,
        "postgres", "www.systecash.org", "dbuser", "dbpass", "systecash", 744,
        "postgres://dbuser:dbpass@www.systecash.org:744/systecash",
        "postgres://dbuser@www.systecash.org:744/systecash", FALSE
    },
    /* TODO Figure out how to write tests that actually verify the relative
     * pathname resolution. The above tests only test absolute pathnames */
    { NULL, FALSE, NULL, NULL, NULL, NULL, NULL, 0, NULL, FALSE },
};

int
main(int argc, char **argv)
{
    int i;

    qof_init();

    /* TEST: gnc_uri_get_components */
    for (i = 0; strs[i].uri != NULL; i++)
    {
        gchar *tprotocol = NULL;
        gchar *thostname = NULL;
        gchar *tusername = NULL;
        gchar *tpassword = NULL;
        gchar *tpath     = NULL;
        gint32 tport     = 0;
        gboolean testresult;

        gnc_uri_get_components( strs[i].uri, &tprotocol, &thostname,
                                &tport, &tusername, &tpassword, &tpath );
        testresult = ( g_strcmp0 ( tprotocol, strs[i].protocol ) == 0 ) &
                     ( g_strcmp0 ( thostname, strs[i].hostname ) == 0 ) &
                     ( g_strcmp0 ( tusername, strs[i].username ) == 0 ) &
                     ( g_strcmp0 ( tpassword, strs[i].password ) == 0 ) &
                     ( g_strcmp0 ( tpath, strs[i].path ) == 0 ) &
                     ( tport == strs[i].port );
        do_test_args(testresult,
                     "gnc_uri_get_components",
                     __FILE__, __LINE__,
                     "\n  %s:\n"
                     "    Expected: %s, %s, %s, %s, %s, %d\n"
                     "    Got     : %s, %s, %s, %s, %s, %d\n",
                     strs[i].uri, strs[i].protocol, strs[i].hostname,
                     strs[i].username, strs[i].password, strs[i].path, strs[i].port,
                     tprotocol, thostname, tusername, tpassword, tpath, tport);
        g_free(tprotocol);
        g_free(thostname);
        g_free(tusername);
        g_free(tpassword);
        g_free(tpath);
    }

    /* TEST: gnc_uri_get_protocol */
    for (i = 0; strs[i].uri != NULL; i++)
    {
        gchar *tprotocol = NULL;
        gboolean testresult;

        tprotocol = gnc_uri_get_protocol( strs[i].uri );
        testresult = ( g_strcmp0 ( tprotocol, strs[i].protocol ) == 0 );
        do_test_args(testresult,
                     "gnc_uri_get_protocol",
                     __FILE__, __LINE__,
                     "\n  %s:\n"
                     "    Expected: %s\n"
                     "    Got     : %s\n",
                     strs[i].uri, strs[i].protocol, tprotocol );
        g_free(tprotocol);
    }

    /* TEST: gnc_uri_get_path */
    for (i = 0; strs[i].uri != NULL; i++)
    {
        gchar *tpath = NULL;
        gboolean testresult;

        tpath = gnc_uri_get_path( strs[i].uri );
        testresult = ( g_strcmp0 ( tpath, strs[i].path ) == 0 );
        do_test_args(testresult,
                     "gnc_uri_get_path",
                     __FILE__, __LINE__,
                     "\n  %s:\n"
                     "    Expected: %s\n"
                     "    Got     : %s\n",
                     strs[i].uri, strs[i].path, tpath );
        g_free(tpath);
    }

    /* TEST: gnc_uri_create_uri */
    for (i = 0; strs[i].uri != NULL; i++)
    {
        gchar *turi = NULL;
        gboolean testresult;

        turi = gnc_uri_create_uri( strs[i].protocol, strs[i].hostname, strs[i].port,
                                   strs[i].username, strs[i].password, strs[i].path );
        testresult = ( g_strcmp0 ( turi, strs[i].created_uri ) == 0 );
        do_test_args(testresult,
                     "gnc_uri_create_uri",
                     __FILE__, __LINE__,
                     "\n  %s, %s, %s, %s, %s, %d:\n"
                     "    Expected: %s\n"
                     "    Got     : %s\n",
                     strs[i].protocol, strs[i].hostname,
                     strs[i].username, strs[i].password, strs[i].path, strs[i].port,
                     strs[i].created_uri, turi);
        g_free(turi);
    }

    /* TEST: gnc_uri_normalize_uri */
    for (i = 0; strs[i].uri != NULL; i++)
    {
        gchar *turi = NULL;
        gboolean testresult;

        turi = gnc_uri_normalize_uri( strs[i].uri, strs[i].want_password );
        testresult = ( g_strcmp0 ( turi, strs[i].normalized_uri ) == 0 );
        do_test_args(testresult,
                     "gnc_uri_normalize_uri",
                     __FILE__, __LINE__,
                     "\n  %s:\n"
                     "    Expected: %s\n"
                     "    Got     : %s\n",
                     strs[i].uri, strs[i].normalized_uri, turi );
        g_free(turi);
    }

    /* TEST: gnc_uri_is_file_protocol */
    for (i = 0; strs[i].uri != NULL; i++)
    {
        gboolean tis_file_protocol;
        gboolean testresult;

        tis_file_protocol = gnc_uri_is_file_protocol( strs[i].protocol );
        testresult = ( tis_file_protocol == strs[i].is_file_protocol );
        do_test_args(testresult,
                     "gnc_uri_is_file_protocol",
                     __FILE__, __LINE__,
                     "\n  %s:\n"
                     "    Expected: %s\n"
                     "    Got     : %s\n",
                     strs[i].uri, strs[i].is_file_protocol, tis_file_protocol );
    }

    /* TEST: gnc_uri_is_file_uri */
    for (i = 0; strs[i].uri != NULL; i++)
    {
        gboolean tis_file_uri;
        gboolean testresult;

        tis_file_uri = gnc_uri_is_file_uri( strs[i].uri );
        testresult = ( tis_file_uri == strs[i].is_file_protocol );
        do_test_args(testresult,
                     "gnc_uri_is_file_uri",
                     __FILE__, __LINE__,
                     "\n  %s:\n"
                     "    Expected: %s\n"
                     "    Got     : %s\n",
                     strs[i].uri, strs[i].is_file_protocol, tis_file_uri );
    }

    print_test_results();
    return get_rv();
}
