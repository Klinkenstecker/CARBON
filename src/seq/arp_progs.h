/*
 * CARBON Arpeggiator Programs
 *
 * Copyright 2015: Kilpatrick Audio
 * Written by: Andrew Kilpatrick
 *
 * CARBON is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * CARBON is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with CARBON.  If not, see <http://www.gnu.org/licenses/>.
 *
 */
#ifndef ARP_PROGS_H
#define ARP_PROGS_H

#include <inttypes.h>

// setting
#define ARP_MAX_LOOP_COUNT 100  // max loop count so we don't get into endless loops
#define ARP_PROG_MAX_PROGS 16  // number of programs that can be stored
#define ARP_PROG_MAX_PROG_LEN 64  // number of instructions for a program
#define ARP_PROG_INST_LEN 2  // size of instruction (elements)
#define ARP_PROG_INST 0  // instruction index
#define ARP_PROG_ARG 1  // arg index
#define ARP_PROG_NUM_REGS 16  // register file size

// arp program store
struct arp_prog {
    int8_t prog[ARP_PROG_MAX_PROG_LEN][ARP_PROG_INST_LEN];
    int inst_count;
};

// internal registers
#define ARP_REG_NOTE_OFFSET 0x70  // note offset

// arp types
#define ARP_NUM_TYPES 16
#define ARP_TYPE_UP1 0
#define ARP_TYPE_UP2 1
#define ARP_TYPE_UP3 2
#define ARP_TYPE_UP4 3
#define ARP_TYPE_DOWN1 4
#define ARP_TYPE_DOWN2 5
#define ARP_TYPE_DOWN3 6
#define ARP_TYPE_DOWN4 7
#define ARP_TYPE_UPDOWN1 8
#define ARP_TYPE_UPDOWN2 9
#define ARP_TYPE_UPDOWN3 10
#define ARP_TYPE_UPDOWN4 11
#define ARP_TYPE_RANDOM1 12
#define ARP_TYPE_RANDOM2 13
#define ARP_TYPE_RANDOM3 14
#define ARP_TYPE_RANDOM4 15

// program instructions
enum {
    AP_NOP,                     // no operation - arg = none
    AP_SNAPSHOT,                // take a snapshot of the held keys (to be used for arp)
    AP_FIND_LOWEST_NOTE,        // find the lowest note or jump to arg = label
    AP_FIND_HIGHEST_NOTE,       // find the highest note or jump to arg = label
    AP_FIND_LOWER_NOTE,         // find the next lower note or jump to arg = label
    AP_FIND_HIGHER_NOTE,        // find the next higher note or jump to arg = label
    AP_FIND_RANDOM_NOTE,        // find a random note or jump to arg = label
    AP_PLAY_NOTE_AND_WAIT,      // play the current note and wait for step - arg = none
    AP_LABEL,                   // mark a label for jumping - arg = label number
    AP_JUMP,                    // jump to a label - arg = label to jump to
    AP_LOADL,                   // load a literal into the X register - arg = liternal
    AP_LOADF,                   // load a file register to X - arg = file register
    AP_STOREF,                  // store X to a file register - arg = file register
    AP_ADDL,                    // add literal to X - arg = literal
    AP_SUBL,                    // subtract literal from X - arg = literal
    AP_MULL,                    // multiply literal with X - arh = literal
    AP_ADDF,                    // add file register to X - arg = file register
    AP_SUBF,                    // subtract file register from X - arg = file register
    AP_MULF,                    // multiple file register with X - arg = file register
    AP_JZ,                      // jump if X is zero - arg = label to jump
    AP_RAND                     // get a random number from 0 to arg - 1
};

// init the arp programs
void arp_progs_init(void);

// load a program
void arp_progs_load(int track, int prog);

#endif
