#ifndef _SYS_TURNSTILE_H_
#define _SYS_TURNSTILE_H_

#include <sys/cdefs.h>
#include <sys/priority.h>

typedef struct turnstile turnstile_t;

/*! \brief Allocates turnstile entry. */
turnstile_t *turnstile_alloc(void);

/*! \brief Deallocates turnstile entry. */
void turnstile_destroy(turnstile_t *ts);

/* Scheduler should call this after changing priority of a thread that is
 * blocked on some turnstile.
 *
 * It will re-sort list of blocked threads, on which `td` is and possibly
 * propagate `td`'s priority if it was increased.
 *
 * If `td` was lending priority and it was decreased, we don't change lent
 * priorities. Unlending would be problematic and the borrowing threads should
 * finish soon anyway.
 *
 * \note Requires td_spin acquired. */
void turnstile_adjust(thread_t *td, prio_t oldprio);

/* Block the current thread on given waiting channel. This function will
 * context switch. */
void turnstile_wait(void *wchan, thread_t *owner, const void *waitpt);

/* Wakeup all threads waiting on given channel and adjust the priority of the
 * current thread appropriately. */
void turnstile_broadcast(void *wchan);

#endif /* !_SYS_TURNSTILE_H_ */
