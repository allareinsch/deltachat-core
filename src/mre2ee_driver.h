/*******************************************************************************
 *
 *                              Delta Chat Core
 *                      Copyright (C) 2017 Björn Petersen
 *                   Contact: r10s@b44t.com, http://b44t.com
 *
 * This program is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free Software
 * Foundation, either version 3 of the License, or (at your option) any later
 * version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program.  If not, see http://www.gnu.org/licenses/ .
 *
 *******************************************************************************
 *
 * File:    mre2ee_driver.h
 * Purpose: Function that should be implemented for a specific
 *          end-to-end-encryption-library
 *
 ******************************************************************************/



#ifndef __MRE2EE_DRIVER_H__
#define __MRE2EE_DRIVER_H__
#ifdef __cplusplus
extern "C" {
#endif


/*** library-private **********************************************************/

typedef struct mrkey_t mrkey_t;
typedef struct mrkeyring_t mrkeyring_t;

void mre2ee_driver_init          (mrmailbox_t*);
void mre2ee_driver_exit          (mrmailbox_t*);
void mre2ee_driver_rand_seed     (mrmailbox_t*, const void* buf, size_t bytes);
int  mre2ee_driver_create_keypair(mrmailbox_t*, const char* addr, mrkey_t* public_key, mrkey_t* private_key);
int  mre2ee_driver_is_valid_key  (mrmailbox_t*, const mrkey_t*);
int  mre2ee_driver_split_key     (mrmailbox_t*, const mrkey_t* private_in, mrkey_t* public_out);
int  mre2ee_driver_encrypt       (mrmailbox_t*, const void* plain, size_t plain_bytes, const mrkeyring_t*, int use_armor, void** ret_ctext, size_t* ret_ctext_bytes);
int  mre2ee_driver_decrypt       (mrmailbox_t*, const void* ctext, size_t ctext_bytes, const mrkeyring_t*, int use_armor, void** plain, size_t* plain_bytes);


#ifdef __cplusplus
} /* /extern "C" */
#endif
#endif /* __MRE2EE_DRIVER_H__ */
