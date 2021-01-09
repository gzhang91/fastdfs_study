/*
 * Copyright (c) 2020 YuQing <384681@qq.com>
 *
 * This program is free software: you can use, redistribute, and/or modify
 * it under the terms of the Lesser GNU General Public License, version 3
 * or later ("LGPL"), as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.
 *
 * You should have received a copy of the Lesser GNU General Public License
 * along with this program. If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef _FC_ATOMIC_H
#define _FC_ATOMIC_H

#ifdef __cplusplus
extern "C" {
#endif

#define FC_ATOMIC_CAS(var, old_value, new_value) \
    do {  \
        if (__sync_bool_compare_and_swap(&var, old_value, new_value)) { \
            break;  \
        }   \
        old_value = __sync_add_and_fetch(&var, 0); \
    } while (new_value != old_value)

#ifdef __cplusplus
}
#endif

#endif
