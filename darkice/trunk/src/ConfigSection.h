/*------------------------------------------------------------------------------

   Copyright (c) 2000 Tyrell Corporation. All rights reserved.

   Tyrell ConfigSection

   File     : ConfigSection.h
   Version  : $Revision$
   Author   : $Author$
   Location : $Source$
   
   Abstract : 

     A configuration file representation. The file is of the syntax:

     # this is a whole line comment
     key = value
     an ugly key name = long value    # this end is a comment too

     also empty lines are ignored and all white space is removed
     from the front and end of keys / values

   Copyright notice:

     This program is free software; you can redistribute it and/or
     modify it under the terms of the GNU General Public License  
     as published by the Free Software Foundation; either version 2
     of the License, or (at your option) any later version.
    
     This program is distributed in the hope that it will be useful,
     but WITHOUT ANY WARRANTY; without even the implied warranty of 
     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
     GNU General Public License for more details.
    
     You should have received a copy of the GNU General Public License
     along with this program; if not, write to the Free Software
     Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307,
     USA.

------------------------------------------------------------------------------*/
#ifndef CONFIG_SECTION_H
#define CONFIG_SECTION_H

#ifndef __cplusplus
#error This is a C++ include file
#endif


/* ============================================================ include files */

#include <hash_map>
#include <string>

#include "Referable.h"


/* ================================================================ constants */


/* =================================================================== macros */


/* =============================================================== data types */

/*------------------------------------------------------------------------------
 *  
 *----------------------------------------------------------------------------*/
class ConfigSection : public virtual Referable
{
    private:

        typedef hash_map<string, string>        TableType;
        TableType                               table;


        void
        init ( void )                               throw ( Exception );


    protected:


    public:

        inline
        ConfigSection ( void )                            throw ( Exception )
        {
        }


        inline virtual
        ~ConfigSection ( void )                           throw ( Exception )
        {
        }


/*

        inline
        ConfigSection ( const ConfigSection   & di )            throw ( Exception )
        {
        }


        inline ConfigSection &
        operator= ( const ConfigSection   * di )          throw ( Exception )
        {
        }
*/

        virtual bool
        add (   const char    * key,
                const char    * value )                 throw ( Exception );


        virtual const char *
        get (   const char    * key ) const             throw ( Exception );


        virtual bool
        addLine (   const char    * line )              throw ( Exception );
};


/* ================================================= external data structures */


/* ====================================================== function prototypes */



#endif  /* CONFIG_SECTION_H */


/*------------------------------------------------------------------------------
 
  $Source$

  $Log$
  Revision 1.1  2000/11/08 17:29:50  darkeye
  added configuration file reader

  Revision 1.1.1.1  2000/11/05 10:05:50  darkeye
  initial version

  
------------------------------------------------------------------------------*/

