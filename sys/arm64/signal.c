#define KL_LOG KL_SIGNAL
#include <sys/mimiker.h>
#include <sys/signal.h>
#include <sys/thread.h>
#include <sys/klog.h>
#include <arm64/exception.h>
#include <sys/errno.h>
#include <sys/proc.h>

int sig_send(signo_t sig, sigaction_t *sa) {
  panic("Not implemented!");
}

int sig_return(void) {
  panic("Not implemented!");
}
