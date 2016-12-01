#ifndef __LOCK_H__
#define __LOCK_H__

#include <stdatomic.h>

#define LOCKED 1
#define UNLOCKED 0

struct spinlock
{
	atomic_int locked;
};

 typedef struct spinlock spinlock_t;

void lock(spinlock_t * lock);
void unlock(spinlock_t * lock);

#endif