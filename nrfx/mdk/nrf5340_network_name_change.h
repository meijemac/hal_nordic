/*

Copyright (c) 2010 - 2025, Nordic Semiconductor ASA All rights reserved.

SPDX-License-Identifier: BSD-3-Clause

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this
   list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

3. Neither the name of Nordic Semiconductor ASA nor the names of its
   contributors may be used to endorse or promote products derived from this
   software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY, AND FITNESS FOR A PARTICULAR PURPOSE
ARE DISCLAIMED. IN NO EVENT SHALL NORDIC SEMICONDUCTOR ASA OR CONTRIBUTORS BE
LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
POSSIBILITY OF SUCH DAMAGE.

*/

#ifndef NRF5340_NETWORK_NAME_CHANGE_H
#define NRF5340_NETWORK_NAME_CHANGE_H

/*lint ++flb "Enter library region */

/* This file is given to prevent your SW from not compiling with the updates made to nrf5340_network.h and
 * nrf5340_network_bitfields.h. The macros defined in this file were available previously. Do not use these
 * macros on purpose. Use the ones defined in nrf5340_network.h and nrf5340_network_bitfields.h instead.
 */
 
/* The serial box interrupt ISRs were renamed. Adding old names as macros. */
#define SPIM0_SPIS0_TWIM0_TWIS0_UARTE0_IRQHandler          SERIAL0_IRQHandler
#define SPIM0_SPIS0_TWIM0_TWIS0_UARTE0_IRQn                SERIAL0_IRQn
 
 /* DPPI */
#define DPPI_PRESENT   DPPIC_PRESENT
#define DPPI_COUNT     DPPIC_COUNT
#define DPPI_CH_NUM    DPPIC_CH_NUM
#define DPPI_GROUP_NUM DPPIC_GROUP_NUM
 

#define CTI_CTIINTACK_UNUSED5_Pos            CTI_CTIINTACK_INTACK_7_Pos 
#define CTI_CTIINTACK_UNUSED5_Msk            CTI_CTIINTACK_INTACK_7_Msk 
#define CTI_CTIINTACK_UNUSED5_Acknowledge    CTI_CTIINTACK_INTACK_7_Acknowledge
#define CTI_CTIINTACK_UNUSED4_Pos            CTI_CTIINTACK_INTACK_6_Pos 
#define CTI_CTIINTACK_UNUSED4_Msk            CTI_CTIINTACK_INTACK_6_Msk 
#define CTI_CTIINTACK_UNUSED4_Acknowledge    CTI_CTIINTACK_INTACK_6_Acknowledge
#define CTI_CTIINTACK_UNUSED3_Pos            CTI_CTIINTACK_INTACK_5_Pos 
#define CTI_CTIINTACK_UNUSED3_Msk            CTI_CTIINTACK_INTACK_5_Msk 
#define CTI_CTIINTACK_UNUSED3_Acknowledge    CTI_CTIINTACK_INTACK_5_Acknowledge
#define CTI_CTIINTACK_UNUSED2_Pos            CTI_CTIINTACK_INTACK_4_Pos 
#define CTI_CTIINTACK_UNUSED2_Msk            CTI_CTIINTACK_INTACK_4_Msk 
#define CTI_CTIINTACK_UNUSED2_Acknowledge    CTI_CTIINTACK_INTACK_4_Acknowledge
#define CTI_CTIINTACK_UNUSED1_Pos            CTI_CTIINTACK_INTACK_3_Pos 
#define CTI_CTIINTACK_UNUSED1_Msk            CTI_CTIINTACK_INTACK_3_Msk 
#define CTI_CTIINTACK_UNUSED1_Acknowledge    CTI_CTIINTACK_INTACK_3_Acknowledge
#define CTI_CTIINTACK_UNUSED0_Pos            CTI_CTIINTACK_INTACK_2_Pos 
#define CTI_CTIINTACK_UNUSED0_Msk            CTI_CTIINTACK_INTACK_2_Msk 
#define CTI_CTIINTACK_UNUSED0_Acknowledge    CTI_CTIINTACK_INTACK_2_Acknowledge
#define CTI_CTIINTACK_CPURESTART_Pos         CTI_CTIINTACK_INTACK_1_Pos 
#define CTI_CTIINTACK_CPURESTART_Msk         CTI_CTIINTACK_INTACK_1_Msk 
#define CTI_CTIINTACK_CPURESTART_Acknowledge CTI_CTIINTACK_INTACK_1_Acknowledge
#define CTI_CTIINTACK_DEBUGREQ_Pos           CTI_CTIINTACK_INTACK_0_Pos 
#define CTI_CTIINTACK_DEBUGREQ_Msk           CTI_CTIINTACK_INTACK_0_Msk 
#define CTI_CTIINTACK_DEBUGREQ_Acknowledge   CTI_CTIINTACK_INTACK_0_Acknowledge


#define CTI_CTITRIGINSTATUS_UNUSED3_Pos                   CTI_CTITRIGINSTATUS_TRIGINSTATUS_7_Pos
#define CTI_CTITRIGINSTATUS_UNUSED3_Msk                   CTI_CTITRIGINSTATUS_TRIGINSTATUS_7_Msk
#define CTI_CTITRIGINSTATUS_UNUSED3_Inactive              CTI_CTITRIGINSTATUS_TRIGINSTATUS_7_Inactive
#define CTI_CTITRIGINSTATUS_UNUSED3_Active                CTI_CTITRIGINSTATUS_TRIGINSTATUS_7_Active
#define CTI_CTITRIGINSTATUS_UNUSED2_Pos                   CTI_CTITRIGINSTATUS_TRIGINSTATUS_6_Pos
#define CTI_CTITRIGINSTATUS_UNUSED2_Msk                   CTI_CTITRIGINSTATUS_TRIGINSTATUS_6_Msk
#define CTI_CTITRIGINSTATUS_UNUSED2_Inactive              CTI_CTITRIGINSTATUS_TRIGINSTATUS_6_Inactive
#define CTI_CTITRIGINSTATUS_UNUSED2_Active                CTI_CTITRIGINSTATUS_TRIGINSTATUS_6_Active
#define CTI_CTITRIGINSTATUS_UNUSED1_Pos                   CTI_CTITRIGINSTATUS_TRIGINSTATUS_5_Pos
#define CTI_CTITRIGINSTATUS_UNUSED1_Msk                   CTI_CTITRIGINSTATUS_TRIGINSTATUS_5_Msk
#define CTI_CTITRIGINSTATUS_UNUSED1_Inactive              CTI_CTITRIGINSTATUS_TRIGINSTATUS_5_Inactive
#define CTI_CTITRIGINSTATUS_UNUSED1_Active                CTI_CTITRIGINSTATUS_TRIGINSTATUS_5_Active
#define CTI_CTITRIGINSTATUS_UNUSED0_Pos                   CTI_CTITRIGINSTATUS_TRIGINSTATUS_4_Pos
#define CTI_CTITRIGINSTATUS_UNUSED0_Msk                   CTI_CTITRIGINSTATUS_TRIGINSTATUS_4_Msk
#define CTI_CTITRIGINSTATUS_UNUSED0_Inactive              CTI_CTITRIGINSTATUS_TRIGINSTATUS_4_Inactive
#define CTI_CTITRIGINSTATUS_UNUSED0_Active                CTI_CTITRIGINSTATUS_TRIGINSTATUS_4_Active
#define CTI_CTITRIGINSTATUS_DWTCOMPOUT2_Pos               CTI_CTITRIGINSTATUS_TRIGINSTATUS_3_Pos
#define CTI_CTITRIGINSTATUS_DWTCOMPOUT2_Msk               CTI_CTITRIGINSTATUS_TRIGINSTATUS_3_Msk
#define CTI_CTITRIGINSTATUS_DWTCOMPOUT2_Inactive          CTI_CTITRIGINSTATUS_TRIGINSTATUS_3_Inactive
#define CTI_CTITRIGINSTATUS_DWTCOMPOUT2_Active            CTI_CTITRIGINSTATUS_TRIGINSTATUS_3_Active
#define CTI_CTITRIGINSTATUS_DWTCOMPOUT1_Pos               CTI_CTITRIGINSTATUS_TRIGINSTATUS_2_Pos
#define CTI_CTITRIGINSTATUS_DWTCOMPOUT1_Msk               CTI_CTITRIGINSTATUS_TRIGINSTATUS_2_Msk
#define CTI_CTITRIGINSTATUS_DWTCOMPOUT1_Inactive          CTI_CTITRIGINSTATUS_TRIGINSTATUS_2_Inactive
#define CTI_CTITRIGINSTATUS_DWTCOMPOUT1_Active            CTI_CTITRIGINSTATUS_TRIGINSTATUS_2_Active
#define CTI_CTITRIGINSTATUS_DWTCOMPOUT0_Pos               CTI_CTITRIGINSTATUS_TRIGINSTATUS_1_Pos
#define CTI_CTITRIGINSTATUS_DWTCOMPOUT0_Msk               CTI_CTITRIGINSTATUS_TRIGINSTATUS_1_Msk
#define CTI_CTITRIGINSTATUS_DWTCOMPOUT0_Inactive          CTI_CTITRIGINSTATUS_TRIGINSTATUS_1_Inactive
#define CTI_CTITRIGINSTATUS_DWTCOMPOUT0_Active            CTI_CTITRIGINSTATUS_TRIGINSTATUS_1_Active
#define CTI_CTITRIGINSTATUS_CPUHALTED_Pos                 CTI_CTITRIGINSTATUS_TRIGINSTATUS_0_Pos
#define CTI_CTITRIGINSTATUS_CPUHALTED_Msk                 CTI_CTITRIGINSTATUS_TRIGINSTATUS_0_Msk
#define CTI_CTITRIGINSTATUS_CPUHALTED_Inactive            CTI_CTITRIGINSTATUS_TRIGINSTATUS_0_Inactive
#define CTI_CTITRIGINSTATUS_CPUHALTED_Active              CTI_CTITRIGINSTATUS_TRIGINSTATUS_0_Active


#define CTI_CTITRIGOUTSTATUS_UNUSED5_Pos                  CTI_CTITRIGOUTSTATUS_TRIGOUTSTATUS_7_Pos
#define CTI_CTITRIGOUTSTATUS_UNUSED5_Msk                  CTI_CTITRIGOUTSTATUS_TRIGOUTSTATUS_7_Msk
#define CTI_CTITRIGOUTSTATUS_UNUSED5_Inactive             CTI_CTITRIGOUTSTATUS_TRIGOUTSTATUS_7_Inactive
#define CTI_CTITRIGOUTSTATUS_UNUSED5_Active               CTI_CTITRIGOUTSTATUS_TRIGOUTSTATUS_7_Active
#define CTI_CTITRIGOUTSTATUS_UNUSED4_Pos                  CTI_CTITRIGOUTSTATUS_TRIGOUTSTATUS_6_Pos
#define CTI_CTITRIGOUTSTATUS_UNUSED4_Msk                  CTI_CTITRIGOUTSTATUS_TRIGOUTSTATUS_6_Msk
#define CTI_CTITRIGOUTSTATUS_UNUSED4_Inactive             CTI_CTITRIGOUTSTATUS_TRIGOUTSTATUS_6_Inactive
#define CTI_CTITRIGOUTSTATUS_UNUSED4_Active               CTI_CTITRIGOUTSTATUS_TRIGOUTSTATUS_6_Active
#define CTI_CTITRIGOUTSTATUS_UNUSED3_Pos                  CTI_CTITRIGOUTSTATUS_TRIGOUTSTATUS_5_Pos
#define CTI_CTITRIGOUTSTATUS_UNUSED3_Msk                  CTI_CTITRIGOUTSTATUS_TRIGOUTSTATUS_5_Msk
#define CTI_CTITRIGOUTSTATUS_UNUSED3_Inactive             CTI_CTITRIGOUTSTATUS_TRIGOUTSTATUS_5_Inactive
#define CTI_CTITRIGOUTSTATUS_UNUSED3_Active               CTI_CTITRIGOUTSTATUS_TRIGOUTSTATUS_5_Active
#define CTI_CTITRIGOUTSTATUS_UNUSED2_Pos                  CTI_CTITRIGOUTSTATUS_TRIGOUTSTATUS_4_Pos
#define CTI_CTITRIGOUTSTATUS_UNUSED2_Msk                  CTI_CTITRIGOUTSTATUS_TRIGOUTSTATUS_4_Msk
#define CTI_CTITRIGOUTSTATUS_UNUSED2_Inactive             CTI_CTITRIGOUTSTATUS_TRIGOUTSTATUS_4_Inactive
#define CTI_CTITRIGOUTSTATUS_UNUSED2_Active               CTI_CTITRIGOUTSTATUS_TRIGOUTSTATUS_4_Active
#define CTI_CTITRIGOUTSTATUS_UNUSED1_Pos                  CTI_CTITRIGOUTSTATUS_TRIGOUTSTATUS_3_Pos
#define CTI_CTITRIGOUTSTATUS_UNUSED1_Msk                  CTI_CTITRIGOUTSTATUS_TRIGOUTSTATUS_3_Msk
#define CTI_CTITRIGOUTSTATUS_UNUSED1_Inactive             CTI_CTITRIGOUTSTATUS_TRIGOUTSTATUS_3_Inactive
#define CTI_CTITRIGOUTSTATUS_UNUSED1_Active               CTI_CTITRIGOUTSTATUS_TRIGOUTSTATUS_3_Active
#define CTI_CTITRIGOUTSTATUS_UNUSED0_Pos                  CTI_CTITRIGOUTSTATUS_TRIGOUTSTATUS_2_Pos
#define CTI_CTITRIGOUTSTATUS_UNUSED0_Msk                  CTI_CTITRIGOUTSTATUS_TRIGOUTSTATUS_2_Msk
#define CTI_CTITRIGOUTSTATUS_UNUSED0_Inactive             CTI_CTITRIGOUTSTATUS_TRIGOUTSTATUS_2_Inactive
#define CTI_CTITRIGOUTSTATUS_UNUSED0_Active               CTI_CTITRIGOUTSTATUS_TRIGOUTSTATUS_2_Active
#define CTI_CTITRIGOUTSTATUS_CPURESTART_Pos               CTI_CTITRIGOUTSTATUS_TRIGOUTSTATUS_1_Pos
#define CTI_CTITRIGOUTSTATUS_CPURESTART_Msk               CTI_CTITRIGOUTSTATUS_TRIGOUTSTATUS_1_Msk
#define CTI_CTITRIGOUTSTATUS_CPURESTART_Inactive          CTI_CTITRIGOUTSTATUS_TRIGOUTSTATUS_1_Inactive
#define CTI_CTITRIGOUTSTATUS_CPURESTART_Active            CTI_CTITRIGOUTSTATUS_TRIGOUTSTATUS_1_Active
#define CTI_CTITRIGOUTSTATUS_DEBUGREQ_Pos                 CTI_CTITRIGOUTSTATUS_TRIGOUTSTATUS_0_Pos
#define CTI_CTITRIGOUTSTATUS_DEBUGREQ_Msk                 CTI_CTITRIGOUTSTATUS_TRIGOUTSTATUS_0_Msk
#define CTI_CTITRIGOUTSTATUS_DEBUGREQ_Inactive            CTI_CTITRIGOUTSTATUS_TRIGOUTSTATUS_0_Inactive
#define CTI_CTITRIGOUTSTATUS_DEBUGREQ_Active              CTI_CTITRIGOUTSTATUS_TRIGOUTSTATUS_0_Active

 /*lint --flb "Leave library region" */

#endif /* NRF5340_NETWORK_NAME_CHANGE_H */
