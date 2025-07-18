/*
** $Source: /dcs/90/cheesey/etc/src/X11/eliteism/RCS/particle.h,v $
** $Author: cheesey $
** $Date: 1992/06/07 00:37:27 $
** $Revision: 1.6 $
** $State: Exp $
**
** All source code Written by Daniel Stephens (cheesey@dcs.warwick.ac.uk)
** anyone wishing to use any of this code may do so, provided that they include
** some acknowledgement of the source (ie me!) 8-)
*/

#ifndef My_PARTICLE_H
#define My_PARTICLE_H

#include "player.h"

#define PARTICLES 10000

struct particle {
	double x,y;
	int rot;
	int life;
	int dam;
	int mass;
	double vel;
	struct particle *next;
	struct player *owner;
};

extern struct particle *parts[MAXDEPTH];

struct explosion {
	int x,y;
	int r,d,s,a;
	struct explosion *next;
};

extern struct explosion *firstbang, *freebang;

void fire_particle(struct player *pl,int l,int x,int y,int a,double v,int d,int r,int m);
void explode(int l,int x, int y,int s,int f,int d,struct player *who);
void move_particles();
struct particle *alloc_particle();
void free_particle(struct particle *p);
struct explosion *alloc_bang();
void move_explosions();

#endif
