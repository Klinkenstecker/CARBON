/*
 * CARBON Sequencer Panel Utils
 *
 * Written by: Andrew Kilpatrick
 * Copyright 2015: Kilpatrick Audio
 *
 * This file is part of CARBON.
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
#include "panel_utils.h"
#include "seq_utils.h"
#include "../seq/song.h"
#include "../config.h"
#include <stdio.h>
#include <string.h>

// make a yes/no string
void panel_utils_yesno_str(char *tempstr, int val) {
    if(val) {
        sprintf(tempstr, "YES");
    }
    else {
        sprintf(tempstr, "NO");
    }
}

// make an on/off string
void panel_utils_onoff_str(char *tempstr, int val) {
    if(val) {
        sprintf(tempstr, "ON");
    }
    else {
        sprintf(tempstr, "OFF");
    }
}

// make a port name
void panel_utils_port_str(char *tempstr, int port) {
    switch(port) {
        case MIDI_PORT_DIN1_IN:
        case MIDI_PORT_DIN1_OUT:
            sprintf(tempstr, "DIN1 mio4");
            break;
        case MIDI_PORT_DIN2_OUT:
            sprintf(tempstr, "DIN2 FX");
            break;
        case MIDI_PORT_USB_DEV_IN1:
        case MIDI_PORT_USB_DEV_OUT1:
            sprintf(tempstr, "Surface");
            break;
        case MIDI_PORT_CV_OUT:
            sprintf(tempstr, "CV/GATE");
            break;
        case MIDI_PORT_USB_HOST_IN:
        case MIDI_PORT_USB_HOST_OUT:
            sprintf(tempstr, "MIDI USB HOST");
            break;
        default:
            panel_utils_get_blank_str(tempstr);
            break;
    }    
}

// make a channel name
void panel_utils_channel_str(char *tempstr, int port, int channel) {
    switch(port) {
        case MIDI_PORT_DIN1_IN:
        case MIDI_PORT_DIN1_OUT:
        case MIDI_PORT_USB_DEV_IN1:
        case MIDI_PORT_USB_DEV_OUT1:
        case MIDI_PORT_USB_HOST_IN:
        case MIDI_PORT_USB_HOST_OUT:
            sprintf(tempstr, "CH %d", (channel + 1));
            break;
        case MIDI_PORT_DIN2_OUT:
            switch(channel) {
                case 0:
                    sprintf(tempstr, "1: Dark World");
                    break;
                case 1:
                    sprintf(tempstr, "2: Thermae");
                    break;
                case 2:
                    sprintf(tempstr, "3: Heat");
                    break;
                case 3:
                    sprintf(tempstr, "4: Big Sky");
                    break;
                case 4:
                    sprintf(tempstr, "5: Ottobit");
                    break;
                case 5:
                    sprintf(tempstr, "6: Polymoon");
                    break;
                default:
                    sprintf(tempstr, "CH %d", (channel + 1));
                    break;
            }
            break;
        case MIDI_PORT_CV_OUT:
            switch(channel) {
                case 0:  // A
                    sprintf(tempstr, "CV A");
                    break;
                case 1:  // B
                    sprintf(tempstr, "CV B");
                    break;
                case 2:  // C
                    sprintf(tempstr, "CV C");
                    break;
                case 3:  // D
                    sprintf(tempstr, "CV D");
                    break;
                default:
                    panel_utils_get_blank_str(tempstr);
                    break;
            }
            break;
        default:
            panel_utils_get_blank_str(tempstr);
            break;
    }
}


void panel_utils_cc_names_upper(char *tempstr, int track, int cc) {
    int8_t port = song_get_midi_port_map(track, 0);
    int8_t channel = song_get_midi_channel_map(track, 0);
    if (port == MIDI_PORT_DIN2_OUT) {
        if (channel == 0) { //{ Dark World 
            switch(cc) {
                case 14:
                    sprintf(tempstr, "Dec");
                    break;
                case 15:
                    sprintf(tempstr, "Mix");
                    break;
                case 16:
                    sprintf(tempstr, "Dwe");
                    break;
                case 17:
                    sprintf(tempstr, "Mod");
                    break;
                case 18:
                    sprintf(tempstr, "Ton");
                    break;
                case 19:
                    sprintf(tempstr, "Pre");
                    break;
                case 21:
                    sprintf(tempstr, "Dar");
                    break;
                case 22:
                    sprintf(tempstr, "Rou");
                    break;
                case 23:
                    sprintf(tempstr, "Wor");
                    break;
                case 100:
                    sprintf(tempstr, "Exp");
                    break;
                case 102:
                    sprintf(tempstr, "Byp");
                    break;
            } 
        } //}
        if (channel == 1) { //{ Thermae 
            switch(cc) {
                case 14:
                    sprintf(tempstr, "Mix");
                    break;
                case 15:
                    sprintf(tempstr, "LPF");
                    break;
                case 16:
                    sprintf(tempstr, "Reg");
                    break;
                case 17:
                    sprintf(tempstr, "Gli");
                    break;
                case 18:
                    sprintf(tempstr, "1Sp");
                    break;
                case 19:
                    sprintf(tempstr, "2De");
                    break;
                case 20:
                    sprintf(tempstr, "Ram");
                    break;
                case 21:
                case 22:
                case 23:
                    sprintf(tempstr, "Tog");
                    break;
                case 24:
                    sprintf(tempstr, "Run");
                    break;
                case 25:
                    sprintf(tempstr, "Slw");
                    break;
                case 93:
                    sprintf(tempstr, "Tap");
                    break;
                case 100:
                    sprintf(tempstr, "Exp");
                    break;
                case 102:
                    sprintf(tempstr, "Byp");
                    break;
            } 
        } //}
        if (channel == 3) { //{ Big Sky 
            switch(cc) {
                case 14:
                    sprintf(tempstr, "Mod");
                    break;
                case 15:
                    sprintf(tempstr, "Mix");
                    break;
                case 9:
                case 16:
                    sprintf(tempstr, "Par");
                    break;
                case 17:
                    sprintf(tempstr, "Dec");
                    break;
                case 18:
                    sprintf(tempstr, "Pre");
                    break;
                case 19:
                    sprintf(tempstr, "Typ");
                    break;
                case 22:
                    sprintf(tempstr, "Per");
                    break;
                case 54:
                    sprintf(tempstr, "Mag");
                    break;
                case 70:
                    sprintf(tempstr, "Fre");
                    break;
                case 100:
                    sprintf(tempstr, "Exp");
                    break;
                case 102:
                    sprintf(tempstr, "Byp");
                    break;
            } 
        } //}
        if (channel == 4) { //{ Ottobit
            switch(cc) {
                case 4:
                    sprintf(tempstr, "Exp");
                    break;
                case 14:
                    sprintf(tempstr, "Byp");
                    break;
                case 15:
                    sprintf(tempstr, "Tem");
                    break;
                case 16:
                    sprintf(tempstr, "Smp");
                    break;
                case 17:
                    sprintf(tempstr, "Fil");
                    break;
                case 18:
                    sprintf(tempstr, "Bit");
                    break;
                case 19:
                    sprintf(tempstr, "Stu");
                    break;
                case 20:
                case 21:
                    sprintf(tempstr, "Seq");
                    break;
                case 22:
                case 23:
                case 24:
                case 25:
                case 26:
                case 27:
                    sprintf(tempstr, "Ste");
                    break;
                case 29:
                    sprintf(tempstr, "Seq");
                    break;
                case 31:
                    sprintf(tempstr, "Stu");
                    break;
            }
        } //}
        if (channel == 5) { //{ Polymoon
            switch(cc) {
                case 4:
                    sprintf(tempstr, "Exp");
                    break;
                case 9:
                    sprintf(tempstr, "Dot");
                    break;
                case 14:
                    sprintf(tempstr, "Byp");
                    break;
                case 15:
                    sprintf(tempstr, "Tem");
                    break;
                case 16:
                    sprintf(tempstr, "Tim");
                    break;
                case 17:
                    sprintf(tempstr, "Fee");
                    break;
                case 18:
                    sprintf(tempstr, "Mix");
                    break;
                case 19:
                    sprintf(tempstr, "Mul");
                    break;
                case 20:
                    sprintf(tempstr, "Dim");
                    break;
                case 21:
                    sprintf(tempstr, "Dyn");
                    break;
                case 22:
                    sprintf(tempstr, "Ear");
                    break;
                case 23:
                    sprintf(tempstr, "Fbk");
                    break;
                case 24:
                    sprintf(tempstr, "Del");
                    break;
                case 25:
                    sprintf(tempstr, "Lat");
                    break;
                case 26:
                case 27:
                    sprintf(tempstr, "Fla");
                    break;
                case 28:
                    sprintf(tempstr, "Tap");
                    break;
                case 29:
                    sprintf(tempstr, "Pha");
                    break;
                case 30:
                    sprintf(tempstr, "Fla");
                    break;
                case 31:
                    sprintf(tempstr, "1/2");
                    break;
            }
        } //}
    }
}

void panel_utils_cc_names_lower(char *tempstr, int track, int cc) {
    int8_t port = song_get_midi_port_map(track, 0);
    int8_t channel = song_get_midi_channel_map(track, 0);
    if (port == MIDI_PORT_DIN2_OUT) {
        if (channel == 0) { //{ Dark World 
            switch(cc) {
                case 14:
                    sprintf(tempstr, "ay ");
                    break;
                case 15:
                    sprintf(tempstr, "   ");
                    break;
                case 16:
                    sprintf(tempstr, "ll ");
                    break;
                case 17:
                    sprintf(tempstr, "ify");
                    break;
                case 18:
                    sprintf(tempstr, "e  ");
                    break;
                case 19:
                    sprintf(tempstr, "Del");
                    break;
                case 21:
                    sprintf(tempstr, "Alg");
                    break;
                case 22:
                    sprintf(tempstr, "te ");
                    break;
                case 23:
                    sprintf(tempstr, "Alg");
                    break;
                case 100:
                    sprintf(tempstr, "res");
                    break;
                case 102:
                    sprintf(tempstr, "ass");
                    break;
            } 
        } //}
        if (channel == 1) { //{ Thermae 
            switch(cc) {
                case 14:
                    sprintf(tempstr, "   ");
                    break;
                case 15:
                    sprintf(tempstr, "   ");
                    break;
                case 16:
                    sprintf(tempstr, "en ");
                    break;
                case 17:
                    sprintf(tempstr, "de ");
                    break;
                case 18:
                    sprintf(tempstr, "eed");
                    break;
                case 19:
                    sprintf(tempstr, "pth");
                    break;
                case 20:
                    sprintf(tempstr, "p");
                    break;
                case 21:
                case 22:
                case 23:
                    sprintf(tempstr, "le%d", cc - 20);
                    break;
                case 24:
                    sprintf(tempstr, "awy");
                    break;
                case 25:
                    sprintf(tempstr, "NwT");
                    break;
                case 93:
                    sprintf(tempstr, "Swi");
                    break;
                case 100:
                    sprintf(tempstr, "res");
                    break;
                case 102:
                    sprintf(tempstr, "ass");
                    break;
            } 
        } //}
        if (channel == 3) { //{ Big Sky 
            switch(cc) {
                case 9:
                    sprintf(tempstr, "am1");
                    break;
                case 14:
                    sprintf(tempstr, "   ");
                    break;
                case 15:
                    sprintf(tempstr, "   ");
                    break;
                case 16:
                    sprintf(tempstr, "am2");
                    break;
                case 17:
                    sprintf(tempstr, "ay");
                    break;
                case 18:
                    sprintf(tempstr, "Del");
                    break;
                case 19:
                    sprintf(tempstr, "e  ");
                    break;
                case 22:
                    sprintf(tempstr, "sis");
                    break;
                case 54:
                    sprintf(tempstr, "Spa");
                    break;
                case 70:
                    sprintf(tempstr, "eze");
                    break;
                case 100:
                    sprintf(tempstr, "res");
                    break;
                case 102:
                    sprintf(tempstr, "ass");
                    break;
            } 
        } //}
        if (channel == 4) { //{ Ottobit
            switch(cc) {
                case 04:
                    sprintf(tempstr, "res");
                    break;
                case 14:
                    sprintf(tempstr, "ass");
                    break;
                case 15:
                    sprintf(tempstr, "po ");
                    break;
                case 16:
                    sprintf(tempstr, "Rat");
                    break;
                case 17:
                    sprintf(tempstr, "ter");
                    break;
                case 18:
                    sprintf(tempstr, "s  ");
                    break;
                case 19:
                    sprintf(tempstr, "ter");
                    break;
                case 20:
                    sprintf(tempstr, "uen");
                    break;
                case 21:
                    sprintf(tempstr, "Mul");
                    break;
                case 22:
                case 23:
                case 24:
                case 25:
                case 26:
                case 27:
                    sprintf(tempstr, "p %d", cc - 21);
                    break;
                case 29:
                    sprintf(tempstr, "Typ");
                    break;
                case 31:
                    sprintf(tempstr, "Hld");
                    break;
            }
        } //}
        if (channel == 5) { //{ Polymoon
            switch(cc) {
                case 4:
                    sprintf(tempstr, "res");
                    break;
                case 9:
                    sprintf(tempstr, "8th");
                    break;
                case 14:
                    sprintf(tempstr, "ass");
                    break;
                case 15:
                    sprintf(tempstr, "po");
                    break;
                case 16:
                    sprintf(tempstr, "e");
                    break;
                case 17:
                    sprintf(tempstr, "dbk");
                    break;
                case 18:
                    sprintf(tempstr, "   ");
                    break;
                case 19:
                    sprintf(tempstr, "ply");
                    break;
                case 20:
                    sprintf(tempstr, "ens");
                    break;
                case 21:
                    sprintf(tempstr, "ics");
                    break;
                case 22:
                    sprintf(tempstr, "Mod");
                    break;
                case 23:
                    sprintf(tempstr, "Fil");
                    break;
                case 24:
                    sprintf(tempstr, "Lvl");
                    break;
                case 25:
                    sprintf(tempstr, "Mod");
                    break;
                case 26:
                    sprintf(tempstr, "Mde");
                    break;
                case 27:
                    sprintf(tempstr, "Spd");
                    break;
                case 28:
                    sprintf(tempstr, "   ");
                    break;
                case 29:
                    sprintf(tempstr, "Mde");
                    break;
                case 30:
                    sprintf(tempstr, "Fbk");
                    break;
                case 31:
                    sprintf(tempstr, "Spd");
                    break;
            }
        } //}
    }
}

void panel_utils_cc_names_value(char *tempstr, int track, int cc, int value) {
    int8_t port = song_get_midi_port_map(track, 0);
    int8_t channel = song_get_midi_channel_map(track, 0);
    if (port == MIDI_PORT_DIN2_OUT) {
        if (channel == 0) { //{ Dark World 
            switch(cc) {
                case 21:
                    switch(value) {
                        case 0:
                            sprintf(tempstr, "-->");
                            break;
                        case 1:
                            sprintf(tempstr, "MOD");
                            break;
                        case 2:
                            sprintf(tempstr, "SHI");
                            break;
                        case 3:
                            sprintf(tempstr, "BLA");
                            break;
                        default:
                            sprintf(tempstr, "<--");
                            break;
                    }
                    break;
                case 22:
                    switch(value) {
                        case 0:
                            sprintf(tempstr, "-->");
                            break;
                        case 1:
                            sprintf(tempstr, "PAR");
                            break;
                        case 2:
                            sprintf(tempstr, "D>W");
                            break;
                        case 3:
                            sprintf(tempstr, "W>D");
                            break;
                        default:
                            sprintf(tempstr, "<--");
                            break;
                    }
                    break;
                case 23:
                    switch(value) {
                        case 0:
                            sprintf(tempstr, "-->");
                            break;
                        case 1:
                            sprintf(tempstr, "HAL");
                            break;
                        case 2:
                            sprintf(tempstr, "PLA");
                            break;
                        case 3:
                            sprintf(tempstr, "SPR");
                            break;
                        default:
                            sprintf(tempstr, "<--");
                            break;
                    }
                    break;
                case 102:
                    switch(value) {
                        case 0:
                            sprintf(tempstr, "On");
                            break;
                        case 127:
                            sprintf(tempstr, "Sav");
                            break;
                        default:
                            sprintf(tempstr, "<->");
                            break;
                    }
                    break;
            } 
        } //}
        if (channel == 1) { //{ Thermae 
            switch(cc) {
                case 21:
                case 22:
                case 23:
                    switch(value) {
                        case 0:
                            sprintf(tempstr, "-->");
                            break;
                        case 1:
                            sprintf(tempstr, " R "); // this is adjusted to my view
                            break;
                        case 2:
                            sprintf(tempstr, " M ");
                            break;
                        case 3:
                            sprintf(tempstr, " L ");
                            break;
                        default:
                            sprintf(tempstr, "<--");
                            break;
                    }
                    break;
                case 24:
                case 25:
                    switch(value) {
                        case 0:
                            sprintf(tempstr, "On");
                            break;
                        case 127:
                            sprintf(tempstr, "Off");
                            break;
                        default:
                            sprintf(tempstr, "<->");
                            break;
                    }
                    break;
                case 102:
                    switch(value) {
                        case 0:
                            sprintf(tempstr, "On");
                            break;
                        case 127:
                            sprintf(tempstr, "Sav");
                            break;
                        default:
                            sprintf(tempstr, "<->");
                            break;
                    }
                    break;
            } 
        } //}
        if (channel == 3) { //{ Big Sky 
            switch(cc) {
                case 22:
                case 54:
                case 70:
                    switch(value) {
                        case 0:
                            sprintf(tempstr, "On");
                            break;
                        case 1:
                            sprintf(tempstr, "Off");
                            break;
                        default:
                            sprintf(tempstr, "<--");
                            break;
                    }
                    break;
                case 102:
                    switch(value) {
                        case 0:
                            sprintf(tempstr, "On");
                            break;
                        case 127:
                            sprintf(tempstr, "Off");
                            break;
                        default:
                            sprintf(tempstr, "<->");
                            break;
                    }
                    break;
            } 
        } //}
        if (channel == 4) { //{ Ottobit
            switch(cc) {
                case 14:
                    if (value < 64)
                        sprintf(tempstr, "on ");
                    else
                        sprintf(tempstr, "off");
                    break;
                case 29:
                    if (value < 63)
                        sprintf(tempstr, "Pit");
                    else if (value == 63)
                        sprintf(tempstr, "Rat");
                    else
                        sprintf(tempstr, "Fil");
                    break;
                case 31:
                    if (value < 64)
                        sprintf(tempstr, "off");
                    else
                        sprintf(tempstr, "on ");
                    break;
            }
        } //}
        if (channel == 5) { //{ Polymoon
            switch(cc) {
                case 9:
                case 14:
                case 30:
                case 31:
                    if (value < 64)
                        sprintf(tempstr, "off");
                    else
                        sprintf(tempstr, "on");
                    break;
            }
        } //}
    }
}


// make a clock source name
void panel_utils_clock_source_str(char *tempstr, int source) {
        switch(source) {
        case SONG_MIDI_CLOCK_SOURCE_INT:
            sprintf(tempstr, "INT");
            break;
        case SONG_MIDI_CLOCK_SOURCE_DIN1_IN:
            sprintf(tempstr, "DIN IN");
            break;
        case SONG_MIDI_CLOCK_SOURCE_USB_HOST_IN:
            sprintf(tempstr, "USB HOST");
            break;
        case SONG_MIDI_CLOCK_SOURCE_USB_DEV_IN:
            sprintf(tempstr, "USB DEV");
            break;
        default:
            sprintf(tempstr, "---");
            break;
    }
}

// convert a MIDI note number to a name
void panel_utils_note_to_name(char *tempstr, int note, 
        int octdisp, int padding) {
    int oct, degree;
    if(note < 0 || note > 0x7f) {
        sprintf(tempstr, "--");
    }
    oct = (note / 12) - 1;
    degree = note % 12;
    if(octdisp) {
        switch(degree) {
            case 0:
                sprintf(tempstr, "C%d", oct);
                if(padding) {
                    strcat(tempstr, " ");
                }
                break;
            case 1:
                sprintf(tempstr, "C#%d", oct);
                break;
            case 2:
                sprintf(tempstr, "D%d", oct);
                if(padding) {
                    strcat(tempstr, " ");
                }
                break;
            case 3:
                sprintf(tempstr, "D#%d", oct);
                break;
            case 4:
                sprintf(tempstr, "E%d", oct);
                if(padding) {
                    strcat(tempstr, " ");
                }
                break;
            case 5:
                sprintf(tempstr, "F%d", oct);
                if(padding) {
                    strcat(tempstr, " ");
                }
                break;
            case 6:
                sprintf(tempstr, "F#%d", oct);
                break;
            case 7:
                sprintf(tempstr, "G%d", oct);
                if(padding) {
                    strcat(tempstr, " ");
                }
                break;
            case 8:
                sprintf(tempstr, "G#%d", oct);
                break;
            case 9:
                sprintf(tempstr, "A%d", oct);
                if(padding) {
                    strcat(tempstr, " ");
                }
                break;
            case 10:
                sprintf(tempstr, "A#%d", oct);
                break;
            case 11:
                sprintf(tempstr, "B%d", oct);
                if(padding) {
                    strcat(tempstr, " ");
                }
                break;
        }    
    }
    else {
        switch(degree) {
            case 0:
                sprintf(tempstr, "C");
                if(padding) {
                    strcat(tempstr, " ");
                }
                break;
            case 1:
                sprintf(tempstr, "C#");
                break;
            case 2:
                sprintf(tempstr, "D");
                if(padding) {
                    strcat(tempstr, " ");
                }
                break;
            case 3:
                sprintf(tempstr, "D#");
                break;
            case 4:
                sprintf(tempstr, "E");
                if(padding) {
                    strcat(tempstr, " ");
                }
                break;
            case 5:
                sprintf(tempstr, "F");
                if(padding) {
                    strcat(tempstr, " ");
                }
                break;
            case 6:
                sprintf(tempstr, "F#");
                break;
            case 7:
                sprintf(tempstr, "G");
                if(padding) {
                    strcat(tempstr, " ");
                }
                break;
            case 8:
                sprintf(tempstr, "G#");
                break;
            case 9:
                sprintf(tempstr, "A");
                if(padding) {
                    strcat(tempstr, " ");
                }
                break;
            case 10:
                sprintf(tempstr, "A#");
                break;
            case 11:
                sprintf(tempstr, "B");
                if(padding) {
                    strcat(tempstr, " ");
                }
                break;
        }     
    }
}

// convert a key split setting to a string
void panel_utils_key_split_str(char *tempstr, int key_split) {
    switch(key_split) {
        case SONG_KEY_SPLIT_LEFT:
            sprintf(tempstr, "Left Hand");
            break;
        case SONG_KEY_SPLIT_RIGHT:
            sprintf(tempstr, "Right Hand");
            break;
        case SONG_KEY_SPLIT_OFF:
        default:
            sprintf(tempstr, "OFF");
            break;
    }
}

// convert a step length to a string
void panel_utils_step_len_to_str(char *tempstr, int speed) {
    switch(speed) {
        case SEQ_UTILS_STEP_32ND_T:
            sprintf(tempstr, "1/32T");
            break;
        case SEQ_UTILS_STEP_32ND:
            sprintf(tempstr, "1/32");
            break;
        case SEQ_UTILS_STEP_16TH_T:
            sprintf(tempstr, "1/16T");        
            break;            
        case SEQ_UTILS_STEP_DOT_32ND:
            sprintf(tempstr, "1/32.");
            break;
        case SEQ_UTILS_STEP_16TH:
            sprintf(tempstr, "1/16");
            break;
        case SEQ_UTILS_STEP_8TH_T:
            sprintf(tempstr, "1/8T");
            break;
        case SEQ_UTILS_STEP_DOT_16TH:
            sprintf(tempstr, "1/16.");
            break;
        case SEQ_UTILS_STEP_8TH:
            sprintf(tempstr, "1/8");
            break;
        case SEQ_UTILS_STEP_QUARTER_T:
            sprintf(tempstr, "1/4T");
            break;
        case SEQ_UTILS_STEP_DOT_8TH:
            sprintf(tempstr, "1/8.");
            break;
        case SEQ_UTILS_STEP_QUARTER:
            sprintf(tempstr, "1/4");
            break;
        case SEQ_UTILS_STEP_HALF_T:
            sprintf(tempstr, "1/2T");        
            break;
        case SEQ_UTILS_STEP_DOT_QUARTER:
            sprintf(tempstr, "1/4.");
            break;
        case SEQ_UTILS_STEP_HALF:
            sprintf(tempstr, "1/2");
            break;
        case SEQ_UTILS_STEP_WHOLE_T:
            sprintf(tempstr, "1/1T");        
            break;
        case SEQ_UTILS_STEP_DOT_HALF:
            sprintf(tempstr, "1/2.");
            break;
        case SEQ_UTILS_STEP_WHOLE:
            sprintf(tempstr, "1/1");
            break;
    }
}

// convert a clock PPQ to a string
void panel_utils_clock_ppq_to_str(char *tempstr, int ppq) {
        switch(ppq) {
        case SEQ_UTILS_CLOCK_1PPQ:
            sprintf(tempstr, "1 PPQ");
            break;
        case SEQ_UTILS_CLOCK_2PPQ:
            sprintf(tempstr, "2 PPQ");
            break;
        case SEQ_UTILS_CLOCK_3PPQ:
            sprintf(tempstr, "3 PPQ");
            break;
        case SEQ_UTILS_CLOCK_4PPQ:
            sprintf(tempstr, "4 PPQ");
            break;
        case SEQ_UTILS_CLOCK_6PPQ:
            sprintf(tempstr, "6 PPQ");
            break;
        case SEQ_UTILS_CLOCK_8PPQ:
            sprintf(tempstr, "8 PPQ");
            break;
        case SEQ_UTILS_CLOCK_12PPQ:
            sprintf(tempstr, "12 PPQ");
            break;
        case SEQ_UTILS_CLOCK_24PPQ:
            sprintf(tempstr, "24 PPQ");
            break;
        default:
            sprintf(tempstr, "OFF");
            break;
    }
}

// convert a gate length to a string by rounding down
void panel_utils_gate_time_to_str(char *tempstr, int time) {
    int tm = time / MIDI_CLOCK_UPSAMPLE;  // normalize to 24ppq
    if(tm >= 192) {
        sprintf(tempstr, "w+");
        return;    
    }
    else if(tm >= 96) {
        sprintf(tempstr, "w");
        return;
    }
    else if(tm >= 72) {
        sprintf(tempstr, "h.");    
        return;
    }
    else if(tm >= 48) {
        sprintf(tempstr, "h");    
        return;
    }
    else if(tm >= 32) {
        sprintf(tempstr, "q.");    
        return;
    }
    else if(tm >= 24) {
        sprintf(tempstr, "q");    
        return;
    }
    else if(tm >= 18) {
        sprintf(tempstr, "8."); 
        return;
    }
    else if(tm >= 12) {
        sprintf(tempstr, "8");    
        return;
    }
    else if(tm >= 9) {
        sprintf(tempstr, "16.");    
        return;
    }
    else if(tm >= 6) {
        sprintf(tempstr, "16");    
        return;
    }
    else if(tm >= 4) {
        sprintf(tempstr, "32.");    
        return;
    }
    else if(tm >= 3) {
        sprintf(tempstr, "32");    
        return;
    }
    else if(tm >= 2) {
        sprintf(tempstr, "64.");    
        return;
    }
    sprintf(tempstr, "64");  // shortest note
}

// convert a transposition to a string
void panel_utils_transpose_to_str(char *tempstr, int trans) {
    if(trans < 0) {
        sprintf(tempstr, "%-2d", trans);
    }
    else {
        sprintf(tempstr, "+%-2d", trans);
    }
}

// handle the scrolling of lists by managing the display and edit positions
// if the edit slot equals the returned list position it should be editable
void panel_utils_scroll_list(int numslots, int edit_pos, int *display_pos) {
    // make sure display pos and edit pos are both on screen
    // edit pos went off the top - make it the top
    if(*display_pos > edit_pos) {
        *display_pos = edit_pos;
    }
    // edit pos went off the bottom
    else if(edit_pos > (*display_pos + (numslots - 1))) {
        *display_pos = edit_pos - (numslots - 1);
    }
}

// convert a CV/gate pair to a string
void panel_utils_cvgate_pair_to_str(char *tempstr, int pair) {
    if(pair < 0 || pair >= CVPROC_NUM_PAIRS) {
        sprintf(tempstr, "X");
    }
    else {
        sprintf(tempstr, "Pair %c", (pair + 65));
    }
}

// convert a CV/gate output mode to a string
void panel_utils_cvgate_pair_mode_to_str(char *tempstr, int mode) {
    if(mode == SONG_CVGATE_MODE_VELO) {
        sprintf(tempstr, "VELOCITY");
    }
    else if(mode == SONG_CVGATE_MODE_NOTE) {
        sprintf(tempstr, "NOTE");
    }
    else if(mode >= 0) {
        sprintf(tempstr, "CC %d", mode);
    }
    else {
        sprintf(tempstr, "NONE");
    }
}

// convert a CV output scaling mode to a string
void panel_utills_cv_output_scaling_to_str(char *tempstr, int mode) {
    if(mode == SONG_CV_SCALING_1P2VOCT) {
        sprintf(tempstr, "1.2V/oct");
    }
    else if(mode == SONG_CV_SCALING_HZ_V) {
        sprintf(tempstr, "Hz/volt");    
    }
    else {
        sprintf(tempstr, "1V/oct");
    }
}

// get a "blank" string to use for an undefined value
void panel_utils_get_blank_str(char *tempstr) {
    sprintf(tempstr, "----");
}

