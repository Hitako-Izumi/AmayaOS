/*
 * Copyright (C) 2015, 2017 Daniel Martín [amaya@amayaos.com]
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
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include "find.h"

int find(char *path, struct find_params params)
{
	DIR *d;
	struct dirent *dent;
	char path_[128];
	/* copy path to path_ */
	strcpy(path_, path);
	/* open path */
	if (!(d = opendir(path))) {
		printf("find: error al abrir '%s': %s\r\n",
		path, strerror(errno));
		return EXIT_FAILURE;
	}
	while ((dent = readdir(d))) {
		switch (dent->d_type) {
			case DT_DIR:
				if (dent->d_name[0] != '.') {
					if ((strcmp("/", path) != 0)) {
						strcat(path_, "/");
					}
					strcat(path_, dent->d_name);
					find(path_, params);
				}
				break;
			default:
				int check = 1;
				if (params.fname && (strcmp(dent->d_name, params.name)) != 0) check = 0;
				if (check) printf("%s/%s\n", path, dent->d_name);				
		}
		for (int i = 0; i < 128; i++) {
			path_[i] = '\0';
		}
		strcpy(path_, path);
	}
	/* close path */
	closedir(d);
	return EXIT_SUCCESS;
}
