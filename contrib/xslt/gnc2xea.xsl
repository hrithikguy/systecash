<?xml version="1.0" encoding="utf-8"?>
<!--
 gnc2xea.xsl: an XSLT style sheet to create an account
 hierarchy template from an (uncompressed) systecash file.

 Copyright (C) 2011 Florian Haas <f.g.haas@gmx.net>

 This program is free software; you can redistribute it and/or
 modify it under the terms of the GNU General Public License as
 published by the Free Software Foundation; either version 2 of
 the License, or (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program; if not, contact:

 Free Software Foundation           Voice:  +1-617-542-5942
 51 Franklin Street, Fifth Floor    Fax:    +1-617-542-2652
 Boston, MA  02110-1301,  USA       gnu@gnu.org
-->
<xsl:stylesheet version="1.0" 
		xmlns="http://www.systecash.org/XML/"
		xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
		xmlns:act="http://www.systecash.org/XML/act"
		xmlns:addr="http://www.systecash.org/XML/addr"
		xmlns:bgt="http://www.systecash.org/XML/bgt"
		xmlns:billterm="http://www.systecash.org/XML/billterm"
		xmlns:book="http://www.systecash.org/XML/book"
		xmlns:bt-days="http://www.systecash.org/XML/bt-days"
		xmlns:bt-prox="http://www.systecash.org/XML/bt-prox"
		xmlns:cd="http://www.systecash.org/XML/cd"
		xmlns:cmdty="http://www.systecash.org/XML/cmdty"
		xmlns:cust="http://www.systecash.org/XML/cust"
		xmlns:employee="http://www.systecash.org/XML/employee"
		xmlns:entry="http://www.systecash.org/XML/entry"
		xmlns:fs="http://www.systecash.org/XML/fs"
		xmlns:gnc="http://www.systecash.org/XML/gnc"
		xmlns:gnc-act="http://www.systecash.org/XML/gnc-act"
		xmlns:invoice="http://www.systecash.org/XML/invoice"
		xmlns:job="http://www.systecash.org/XML/job"
		xmlns:lot="http://www.systecash.org/XML/lot"
		xmlns:order="http://www.systecash.org/XML/order"
		xmlns:owner="http://www.systecash.org/XML/owner"
		xmlns:price="http://www.systecash.org/XML/price"
		xmlns:recurrence="http://www.systecash.org/XML/recurrence"
		xmlns:slot="http://www.systecash.org/XML/slot"
		xmlns:split="http://www.systecash.org/XML/split"
		xmlns:sx="http://www.systecash.org/XML/sx"
		xmlns:taxtable="http://www.systecash.org/XML/taxtable"
		xmlns:trn="http://www.systecash.org/XML/trn"
		xmlns:ts="http://www.systecash.org/XML/ts"
		xmlns:tte="http://www.systecash.org/XML/tte"
		xmlns:vendor="http://www.systecash.org/XML/vendor">
  <xsl:output method="xml" encoding="utf-8" indent="yes"/>

  <xsl:param name="title">
    <xsl:message>Please set a title for your account hierarchy by passing in the "title" parameter.</xsl:message>
  </xsl:param>
  <xsl:param name="short-description">
    <xsl:message>Please set a short description for your account hierarchy by passing in the "short-description" parameter.</xsl:message>
  </xsl:param>
  
  <xsl:param name="long-description">
    <xsl:message>Please set a long description for your account hierarchy by passing in the "long-description" parameter.</xsl:message>
  </xsl:param>

  <xsl:template match="/">
    <gnc-account-example>
      <gnc-act:title>
	<xsl:value-of select="$title"/>
      </gnc-act:title>
      <gnc-act:short-description>
	<xsl:value-of select="$short-description"/>
      </gnc-act:short-description>
      <gnc-act:long-description>
	<xsl:value-of select="$long-description"/>
      </gnc-act:long-description>
      <gnc-act:exclude-from-select-all>1</gnc-act:exclude-from-select-all>
      <xsl:apply-templates/>
    </gnc-account-example>
  </xsl:template>

  <xsl:template match="gnc-v2|gnc:book">
    <xsl:apply-templates/>
  </xsl:template>

  <xsl:template match="gnc:account">
    <xsl:copy-of select="."/>
  </xsl:template>

  <xsl:template match="*"/>

</xsl:stylesheet>
