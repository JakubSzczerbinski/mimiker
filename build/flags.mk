ASFLAGS  +=
WFLAGS   += -Wall -Wextra -Wno-unused-parameter -Wstrict-prototypes -Werror
CFLAGS   += -std=gnu11 -Og -ggdb3 $(WFLAGS)
CPPFLAGS += -Wall -Werror -DDEBUG
