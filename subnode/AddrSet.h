/* vim: set expandtab ts=4 sw=4: */
/*
 * You may redistribute this program and/or modify it under the terms of
 * the GNU General Public License as published by the Free Software Foundation,
 * either version 3 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */
#ifndef AddrSet_H
#define AddrSet_H

#include "memory/Allocator.h"
#include "dht/Address.h"
#include "util/Linker.h"
Linker_require("subnode/AddrSet.c")

struct AddrSet
{
    int length;
};

enum AddrSet_Match {
    AddrSet_Match_ADDRESS_ONLY = 0,
    AddrSet_Match_LABEL_ONLY = 1,
    AddrSet_Match_BOTH = 2,
};

int AddrSet_indexOf(struct AddrSet* as, struct Address* addr, enum AddrSet_Match m);

void AddrSet_add(struct AddrSet* as, struct Address* addr, enum AddrSet_Match m);

void AddrSet_remove(struct AddrSet* as, struct Address* addr, enum AddrSet_Match m);

struct Address* AddrSet_get(struct AddrSet* as, int i);

struct AddrSet* AddrSet_new(struct Allocator* alloc);

void AddrSet_flush(struct AddrSet* as);

#endif
