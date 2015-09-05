/*
 * Copyright (C) 2015 Dan Rulos
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdio.h>
#include <VGA.h>
#include <API/ProcessCtl.h>
#include <Error.h>
#include <Types.h>
#include <MemoryMessage.h>
#include <stdlib.h>
#include <API/PrivExec.h>
#include "wama/wamas.h"
//#include "pong/pong.cpp"
//#include "commander/commander.cpp"
#include "AmaCALC/AmaCALC.cpp"
#include "hangman/hangman.cpp"
#include <MemoryMessage.h>
#include <Config.h>

/* desktop version 0.2 */
int menu();
void memoria();

int main(int argc, char **argv)
{
  while (1) {
    char tecla;
    int i;
    u16 *vga;
    MemoryMessage mem;

    /* Request VGA memory. */
    mem.action    = CreatePrivate;
    mem.bytes     = PAGESIZE;
    mem.virtualAddress  = ZERO;
    mem.physicalAddress = VGA_PADDR;
    mem.protection      = PAGE_RW | PAGE_PINNED;
    mem.ipc(MEMSRV_PID, SendReceive, sizeof(mem));

    /* Point to the VGA mapping. */
    vga = (u16 *) mem.virtualAddress;

    for (i=0; i < 36; i++) {
      vga[i] = VGA_CHAR(' ', GREEN, GREEN);
    }
    vga[36] = VGA_CHAR('A', BLACK, GREEN);
    vga[37] = VGA_CHAR('m', BLACK, GREEN);
    vga[38] = VGA_CHAR('a', BLACK, GREEN);
    vga[39] = VGA_CHAR('y', BLACK, GREEN);
    vga[40] = VGA_CHAR('a', BLACK, GREEN);
    vga[41] = VGA_CHAR('O', BLACK, GREEN);
    vga[42] = VGA_CHAR('S', BLACK, GREEN);
    for (i=43; i < 80; i++) {
      vga[i] = VGA_CHAR(' ', GREEN, GREEN);
    }
    for (i=80; i < 1920; i++) {
      vga[i] = VGA_CHAR(' ', WHITE, WHITE);
    }
    vga[1920] = VGA_CHAR(' ', BROWN, BROWN);
    vga[1921] = VGA_CHAR('M', BLUE, BROWN);
    vga[1922] = VGA_CHAR('e', BLUE, BROWN);
    vga[1923] = VGA_CHAR('n', BLUE, BROWN);
    vga[1924] = VGA_CHAR('u', BLUE, BROWN);
    vga[1925] = VGA_CHAR('(', BLUE, BROWN);
    vga[1926] = VGA_CHAR('M', BLUE, BROWN);
    vga[1927] = VGA_CHAR(')', BLUE, BROWN);
    for (i=1928; i <= 2000; i++) {
      vga[i] = VGA_CHAR(' ', BROWN, BROWN);
    }
    memoria();
    do {
      tecla = getchar();
    } while (tecla != 'M'&& tecla != 'm');
    if (tecla == 'M'|| tecla == 'm') {
      if (menu() == -1) {
    	char clean[] = {0x1b, 0x5b, 0x48, 0x1b, 0x5b, 0x4a, '\0'};
    	printf("%s", clean);
	return 0;
      }
    }
  }
}

int menu()
{
    char tecla;
    int i;
    u16 *vga;
    MemoryMessage mem;

    /* Request VGA memory. */
    mem.action    = CreatePrivate;
    mem.bytes     = PAGESIZE;
    mem.virtualAddress  = ZERO;
    mem.physicalAddress = VGA_PADDR;
    mem.protection      = PAGE_RW | PAGE_PINNED;
    mem.ipc(MEMSRV_PID, SendReceive, sizeof(mem));

    /* Point to the VGA mapping. */
    vga = (u16 *) mem.virtualAddress;

    for (i=0; i < 36; i++) {
      vga[i] = VGA_CHAR(' ', GREEN, GREEN);
    }
    vga[36] = VGA_CHAR('A', BLACK, GREEN);
    vga[37] = VGA_CHAR('m', BLACK, GREEN);
    vga[38] = VGA_CHAR('a', BLACK, GREEN);
    vga[39] = VGA_CHAR('y', BLACK, GREEN);
    vga[40] = VGA_CHAR('a', BLACK, GREEN);
    vga[41] = VGA_CHAR('O', BLACK, GREEN);
    vga[42] = VGA_CHAR('S', BLACK, GREEN);
    for (i=43; i < 80; i++) {
      vga[i] = VGA_CHAR(' ', GREEN, GREEN);
    }
    for (i=80; i < 1680; i++) {
      vga[i] = VGA_CHAR(' ', WHITE, WHITE);
    }
    vga[1520] = VGA_CHAR('A', BLUE, BROWN);
    vga[1521] = VGA_CHAR('m', BLUE, BROWN);
    vga[1522] = VGA_CHAR('a', BLUE, BROWN);
    vga[1523] = VGA_CHAR('C', BLUE, BROWN);
    vga[1524] = VGA_CHAR('A', BLUE, BROWN);
    vga[1525] = VGA_CHAR('L', BLUE, BROWN);
    vga[1526] = VGA_CHAR('C', BLUE, BROWN);
    vga[1527] = VGA_CHAR(' ', BLUE, BROWN);
    vga[1528] = VGA_CHAR('(', BLUE, BROWN);
    vga[1529] = VGA_CHAR('A', BLUE, BROWN);
    vga[1530] = VGA_CHAR(')', BLUE, BROWN);
    vga[1531] = VGA_CHAR(' ', BLUE, BROWN);
    vga[1600] = VGA_CHAR('H', BLUE, BROWN);
    vga[1601] = VGA_CHAR('a', BLUE, BROWN);
    vga[1602] = VGA_CHAR('n', BLUE, BROWN);
    vga[1603] = VGA_CHAR('g', BLUE, BROWN);
    vga[1604] = VGA_CHAR('m', BLUE, BROWN);
    vga[1605] = VGA_CHAR('a', BLUE, BROWN);
    vga[1606] = VGA_CHAR('n', BLUE, BROWN);
    vga[1607] = VGA_CHAR(' ', BLUE, BROWN);
    vga[1608] = VGA_CHAR('(', BLUE, BROWN);
    vga[1609] = VGA_CHAR('H', BLUE, BROWN);
    vga[1610] = VGA_CHAR(')', BLUE, BROWN);
    vga[1611] = VGA_CHAR(' ', BLUE, BROWN);
    vga[1680] = VGA_CHAR('W', BLUE, BROWN);
    vga[1681] = VGA_CHAR('a', BLUE, BROWN);
    vga[1682] = VGA_CHAR('m', BLUE, BROWN);
    vga[1683] = VGA_CHAR('a', BLUE, BROWN);
    vga[1684] = VGA_CHAR('/', BLUE, BROWN);
    vga[1685] = VGA_CHAR('W', BLUE, BROWN);
    vga[1686] = VGA_CHAR('A', BLUE, BROWN);
    vga[1687] = VGA_CHAR('+', BLUE, BROWN);
    vga[1688] = VGA_CHAR('(', BLUE, BROWN);
    vga[1689] = VGA_CHAR('W', BLUE, BROWN);
    vga[1690] = VGA_CHAR(')', BLUE, BROWN);
    vga[1691] = VGA_CHAR(' ', BLUE, BROWN);
    for (i=1692; i < 1760; i++) {
      vga[i] = VGA_CHAR(' ', WHITE, WHITE);
    }
    vga[1760] = VGA_CHAR('R', BLUE, BROWN);
    vga[1761] = VGA_CHAR('e', BLUE, BROWN);
    vga[1762] = VGA_CHAR('i', BLUE, BROWN);
    vga[1763] = VGA_CHAR('n', BLUE, BROWN);
    vga[1764] = VGA_CHAR('i', BLUE, BROWN);
    vga[1765] = VGA_CHAR('c', BLUE, BROWN);
    vga[1766] = VGA_CHAR('i', BLUE, BROWN);
    vga[1767] = VGA_CHAR('a', BLUE, BROWN);
    vga[1768] = VGA_CHAR('r', BLUE, BROWN);
    vga[1769] = VGA_CHAR('(', BLUE, BROWN);
    vga[1770] = VGA_CHAR('R', BLUE, BROWN);
    vga[1771] = VGA_CHAR(')', BLUE, BROWN);
    for (i=1772; i < 1840; i++) {
      vga[i] = VGA_CHAR(' ', WHITE, WHITE);
    }
    vga[1840] = VGA_CHAR('S', BLUE, BROWN);
    vga[1841] = VGA_CHAR('h', BLUE, BROWN);
    vga[1842] = VGA_CHAR('e', BLUE, BROWN);
    vga[1843] = VGA_CHAR('l', BLUE, BROWN);
    vga[1844] = VGA_CHAR('l', BLUE, BROWN);
    vga[1845] = VGA_CHAR('(', BLUE, BROWN);
    vga[1846] = VGA_CHAR('S', BLUE, BROWN);
    vga[1847] = VGA_CHAR(')', BLUE, BROWN);
    vga[1848] = VGA_CHAR(' ', BLUE, BROWN);
    vga[1849] = VGA_CHAR(' ', BLUE, BROWN);
    vga[1850] = VGA_CHAR(' ', BLUE, BROWN);
    vga[1851] = VGA_CHAR(' ', BLUE, BROWN);
    memoria();
    do {
      tecla = getchar();
    } while (tecla != 'R'&& tecla != 'r'&& tecla != 'S'&& tecla != 's'&& 'M'&& tecla != 'm'&& tecla != 'W'&& tecla != 'w'
             &&tecla != 'H'&& tecla != 'h' &&tecla != 'A'&& tecla != 'a');
    if (tecla == 'M'|| tecla == 'm') {
      return 0;
    }
    if (tecla == 'R'|| tecla == 'r') {
      return PrivExec(Reboot);
    }
    if (tecla == 'S'|| tecla == 's') {
      return -1;
    }
    if (tecla == 'W'|| tecla == 'w') {
      wama();
    }
/*
    if (tecla == 'P'|| tecla == 'p') {
      game();
    }
*/
    if (tecla == 'H'|| tecla == 'h') {
      hangman();
    }
    if (tecla == 'A'|| tecla == 'a') {
      ama_calc();
    }

    return 0;
}

void memoria()
{
    int i;
    u16 *vga;
    MemoryMessage mem;

    /* Request VGA memory. */
    mem.action    = CreatePrivate;
    mem.bytes     = PAGESIZE;
    mem.virtualAddress  = ZERO;
    mem.physicalAddress = VGA_PADDR;
    mem.protection      = PAGE_RW | PAGE_PINNED;
    mem.ipc(MEMSRV_PID, SendReceive, sizeof(mem));

    /* Point to the VGA mapping. */
    vga = (u16 *) mem.virtualAddress;

    /* Obtenemos el uso de la memoria. */
    mem.action = SystemMemory;
    mem.ipc(MEMSRV_PID, SendReceive, sizeof(mem));
    for (i=209; i <= 238; i++) {
      vga[i] = VGA_CHAR(' ', GREEN, GREEN);
    }
    vga[214] = VGA_CHAR('E', BLACK, GREEN);
    vga[215] = VGA_CHAR('s', BLACK, GREEN);
    vga[216] = VGA_CHAR('t', BLACK, GREEN);
    vga[217] = VGA_CHAR('a', BLACK, GREEN);
    vga[218] = VGA_CHAR('d', BLACK, GREEN);
    vga[219] = VGA_CHAR('o', BLACK, GREEN);
    vga[220] = VGA_CHAR(' ', BLACK, GREEN);
    vga[221] = VGA_CHAR('d', BLACK, GREEN);
    vga[222] = VGA_CHAR('e', BLACK, GREEN);
    vga[223] = VGA_CHAR(' ', BLACK, GREEN);
    vga[224] = VGA_CHAR('l', BLACK, GREEN);
    vga[225] = VGA_CHAR('a', BLACK, GREEN);
    vga[226] = VGA_CHAR(' ', BLACK, GREEN);
    vga[227] = VGA_CHAR('m', BLACK, GREEN);
    vga[228] = VGA_CHAR('e', BLACK, GREEN);
    vga[229] = VGA_CHAR('m', BLACK, GREEN);
    vga[230] = VGA_CHAR('o', BLACK, GREEN);
    vga[231] = VGA_CHAR('r', BLACK, GREEN);
    vga[232] = VGA_CHAR('i', BLACK, GREEN);
    vga[233] = VGA_CHAR('a', BLACK, GREEN);
    vga[289] = VGA_CHAR(' ', GREEN, GREEN);
    vga[369] = VGA_CHAR(' ', GREEN, GREEN);
    vga[449] = VGA_CHAR(' ', GREEN, GREEN);
    vga[290] = VGA_CHAR('T', BLACK, GREEN);
    vga[291] = VGA_CHAR('o', BLACK, GREEN);
    vga[292] = VGA_CHAR('t', BLACK, GREEN);
    vga[293] = VGA_CHAR('a', BLACK, GREEN);
    vga[294] = VGA_CHAR('l', BLACK, GREEN);
    vga[295] = VGA_CHAR(':', BLACK, GREEN);
    vga[296] = VGA_CHAR(' ', GREEN, GREEN);
    int a=mem.bytes / 1024;
    char a2[25];
    itoa(a2, 10, a);
    for (int i=0; i+297 < 306; i++) {
	if (a2[i] == '0' ||a2[i] == '1' ||a2[i] == '2' ||a2[i] == '3' ||a2[i] == '4' ||a2[i] == '5' ||a2[i] == '6'
	    ||a2[i] == '7' ||a2[i] == '8' ||a2[i] == '9') {
    		vga[297+i] = VGA_CHAR(a2[i], BLACK, GREEN);
	}
	else {
		vga[297+i] = VGA_CHAR(' ', GREEN, GREEN);
	}
    }
    vga[306] = VGA_CHAR('K', BLACK, GREEN);
    vga[307] = VGA_CHAR('i', BLACK, GREEN);
    vga[308] = VGA_CHAR('B', BLACK, GREEN);
    for (i=309; i < 319; i++) {
	vga[i] = VGA_CHAR(' ', GREEN, GREEN);
    }
    vga[370] = VGA_CHAR('D', BLACK, GREEN);
    vga[371] = VGA_CHAR('i', BLACK, GREEN);
    vga[372] = VGA_CHAR('s', BLACK, GREEN);
    vga[373] = VGA_CHAR('p', BLACK, GREEN);
    vga[374] = VGA_CHAR('o', BLACK, GREEN);
    vga[375] = VGA_CHAR('n', BLACK, GREEN);
    vga[376] = VGA_CHAR('i', BLACK, GREEN);
    vga[377] = VGA_CHAR('b', BLACK, GREEN);
    vga[378] = VGA_CHAR('l', BLACK, GREEN);
    vga[379] = VGA_CHAR('e', BLACK, GREEN);
    vga[380] = VGA_CHAR(':', BLACK, GREEN);
    int b=mem.free / 1024;
    char b2[25];
    itoa(b2, 10, b);
    for (int i=0; i+381 < 390; i++) {
	if (b2[i] == '0' ||b2[i] == '1' ||b2[i] == '2' ||b2[i] == '3' ||b2[i] == '4' ||b2[i] == '5' ||b2[i] == '6'
	    ||b2[i] == '7' ||b2[i] == '8' ||b2[i] == '9') {
    		vga[381+i] = VGA_CHAR(b2[i], BLACK, GREEN);
	}
	else {
		vga[381+i] = VGA_CHAR(' ', GREEN, GREEN);
	}
    }
    vga[390] = VGA_CHAR('K', BLACK, GREEN);
    vga[391] = VGA_CHAR('i', BLACK, GREEN);
    vga[392] = VGA_CHAR('B', BLACK, GREEN);
    for (i=393; i < 399; i++) {
	vga[i] = VGA_CHAR(' ', GREEN, GREEN);
    }
    vga[450] = VGA_CHAR('E', BLACK, GREEN);
    vga[451] = VGA_CHAR('n', BLACK, GREEN);
    vga[452] = VGA_CHAR(' ', BLACK, GREEN);
    vga[453] = VGA_CHAR('U', BLACK, GREEN);
    vga[454] = VGA_CHAR('s', BLACK, GREEN);
    vga[455] = VGA_CHAR('o', BLACK, GREEN);
    vga[456] = VGA_CHAR(':', BLACK, GREEN);
    vga[457] = VGA_CHAR(' ', GREEN, GREEN);
    int c=(mem.bytes - mem.free) / 1024;
    char c2[25];
    itoa(c2, 10, c);
    for (int i=0; i+458 < 467; i++) {
	if (c2[i] == '0' ||c2[i] == '1' ||c2[i] == '2' ||c2[i] == '3' ||c2[i] == '4' ||c2[i] == '5' ||c2[i] == '6'
	    ||c2[i] == '7' ||c2[i] == '8' ||c2[i] == '9') {
    		vga[458+i] = VGA_CHAR(c2[i], BLACK, GREEN);
	}
	else {
		vga[458+i] = VGA_CHAR(' ', GREEN, GREEN);
	}
    }
    vga[467] = VGA_CHAR('K', BLACK, GREEN);
    vga[468] = VGA_CHAR('i', BLACK, GREEN);
    vga[469] = VGA_CHAR('B', BLACK, GREEN);
    for (i=470; i < 479; i++) {
	vga[i] = VGA_CHAR(' ', GREEN, GREEN);
    }
}
