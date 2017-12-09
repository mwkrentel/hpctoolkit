// -*-Mode: C++;-*- // technically C99

// * BeginRiceCopyright *****************************************************
//
// $HeadURL$
// $Id$
//
// --------------------------------------------------------------------------
// Part of HPCToolkit (hpctoolkit.org)
//
// Information about sources of support for research and development of
// HPCToolkit is at 'hpctoolkit.org' and in 'README.Acknowledgments'.
// --------------------------------------------------------------------------
//
// Copyright ((c)) 2002-2017, Rice University
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
// * Redistributions of source code must retain the above copyright
//   notice, this list of conditions and the following disclaimer.
//
// * Redistributions in binary form must reproduce the above copyright
//   notice, this list of conditions and the following disclaimer in the
//   documentation and/or other materials provided with the distribution.
//
// * Neither the name of Rice University (RICE) nor the names of its
//   contributors may be used to endorse or promote products derived from
//   this software without specific prior written permission.
//
// This software is provided by RICE and contributors "as is" and any
// express or implied warranties, including, but not limited to, the
// implied warranties of merchantability and fitness for a particular
// purpose are disclaimed. In no event shall RICE or contributors be
// liable for any direct, indirect, incidental, special, exemplary, or
// consequential damages (including, but not limited to, procurement of
// substitute goods or services; loss of use, data, or profits; or
// business interruption) however caused and on any theory of liability,
// whether in contract, strict liability, or tort (including negligence
// or otherwise) arising in any way out of the use of this software, even
// if advised of the possibility of such damage.
//
// ******************************************************* EndRiceCopyright *

#ifndef __DATACENTRIC_DATA_TREE_H__
#define __DATACENTRIC_DATA_TREE_H__

#include "cct.h"


/******************************************************************************
 * macros
 *****************************************************************************/

#define DATA_STATIC_MAGIC 0xFEA12B0B


/******************************************************************************
 * type definitions
 *****************************************************************************/

typedef struct datainfo_s {
  long        magic;
  cct_node_t *context;
  size_t      bytes;
  void       *memblock;
  void       *rmemblock;	// additional information to record remote memory

  struct datainfo_s *left;
  struct datainfo_s *right;
} datainfo_t;


/* * Insert a node */ 
void splay_insert(struct datainfo_s *node);

/* find a cct node for a given key and range */
cct_node_t * splay_lookup(void *key, void **start, void **end);

/* remove a node containing a memory block */
struct datainfo_s * splay_delete(void *memblock);

#endif //__DATACENTRIC_DATA_TREE_H__
