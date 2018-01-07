CFLAGS=-Wall
all: Makefile clean test
Makefile: *.c *.h ; makedepend *.c *.h
test: prs ; ./prs<tst/p.c
clean: ; rm -fr *.o prs *~ *.bak
# DO NOT DELETE

prs.o: prog.h crules.h pio.h /usr/include/ctype.h /usr/include/sys/cdefs.h
prs.o: /usr/include/sys/_symbol_aliasing.h
prs.o: /usr/include/sys/_posix_availability.h /usr/include/runetype.h
prs.o: /usr/include/_types.h /usr/include/sys/_types.h
prs.o: /usr/include/machine/_types.h /usr/include/i386/_types.h
prs.o: /usr/include/sys/_pthread/_pthread_types.h
prs.o: /usr/include/sys/_types/_size_t.h /usr/include/sys/_types/_ct_rune_t.h
prs.o: /usr/include/sys/_types/_rune_t.h /usr/include/sys/_types/_wchar_t.h
prs.o: /usr/include/sys/_types/_wint_t.h /usr/include/unistd.h
prs.o: /usr/include/sys/unistd.h /usr/include/sys/_types/_posix_vdisable.h
prs.o: /usr/include/sys/_types/_seek_set.h /usr/include/_types/_uint64_t.h
prs.o: /usr/include/Availability.h /usr/include/AvailabilityInternal.h
prs.o: /usr/include/sys/_types/_ssize_t.h /usr/include/sys/_types/_uid_t.h
prs.o: /usr/include/sys/_types/_gid_t.h /usr/include/sys/_types/_intptr_t.h
prs.o: /usr/include/sys/_types/_off_t.h /usr/include/sys/_types/_pid_t.h
prs.o: /usr/include/sys/_types/_useconds_t.h /usr/include/sys/_types/_null.h
prs.o: /usr/include/sys/select.h /usr/include/sys/appleapiopts.h
prs.o: /usr/include/sys/_types/_fd_def.h /usr/include/sys/_types/_timespec.h
prs.o: /usr/include/sys/_types/_timeval.h /usr/include/sys/_types/_time_t.h
prs.o: /usr/include/sys/_types/_suseconds_t.h
prs.o: /usr/include/sys/_types/_sigset_t.h
prs.o: /usr/include/sys/_types/_fd_setsize.h
prs.o: /usr/include/sys/_types/_fd_set.h /usr/include/sys/_types/_fd_clr.h
prs.o: /usr/include/sys/_types/_fd_isset.h /usr/include/sys/_types/_fd_zero.h
prs.o: /usr/include/sys/_types/_fd_copy.h /usr/include/sys/_select.h
prs.o: /usr/include/sys/_types/_dev_t.h /usr/include/sys/_types/_mode_t.h
prs.o: /usr/include/sys/_types/_uuid_t.h /usr/include/gethostuuid.h
prs.o: /usr/include/stdlib.h /usr/include/sys/wait.h
prs.o: /usr/include/sys/_types/_id_t.h /usr/include/sys/signal.h
prs.o: /usr/include/machine/signal.h /usr/include/i386/signal.h
prs.o: /usr/include/machine/_mcontext.h /usr/include/i386/_mcontext.h
prs.o: /usr/include/mach/i386/_structs.h
prs.o: /usr/include/sys/_pthread/_pthread_attr_t.h
prs.o: /usr/include/sys/_types/_sigaltstack.h
prs.o: /usr/include/sys/_types/_ucontext.h /usr/include/sys/resource.h
prs.o: /usr/include/stdint.h /usr/include/sys/_types/_int8_t.h
prs.o: /usr/include/sys/_types/_int16_t.h /usr/include/sys/_types/_int32_t.h
prs.o: /usr/include/sys/_types/_int64_t.h /usr/include/_types/_uint8_t.h
prs.o: /usr/include/_types/_uint16_t.h /usr/include/_types/_uint32_t.h
prs.o: /usr/include/sys/_types/_uintptr_t.h /usr/include/_types/_intmax_t.h
prs.o: /usr/include/_types/_uintmax_t.h /usr/include/machine/endian.h
prs.o: /usr/include/i386/endian.h /usr/include/sys/_endian.h
prs.o: /usr/include/libkern/_OSByteOrder.h
prs.o: /usr/include/libkern/i386/_OSByteOrder.h /usr/include/alloca.h
prs.o: /usr/include/machine/types.h /usr/include/i386/types.h
prs.o: /usr/include/sys/_types/_u_int8_t.h
prs.o: /usr/include/sys/_types/_u_int16_t.h
prs.o: /usr/include/sys/_types/_u_int32_t.h
prs.o: /usr/include/sys/_types/_u_int64_t.h /usr/include/stdio.h
prs.o: /usr/include/sys/_types/_va_list.h /usr/include/sys/stdio.h
prs.o: /usr/include/secure/_stdio.h /usr/include/secure/_common.h
prs.o: /usr/include/strings.h /usr/include/string.h
prs.o: /usr/include/sys/_types/_rsize_t.h /usr/include/sys/_types/_errno_t.h
prs.o: /usr/include/secure/_string.h arr.h
arr.o: /usr/include/stdio.h /usr/include/sys/cdefs.h
arr.o: /usr/include/sys/_symbol_aliasing.h
arr.o: /usr/include/sys/_posix_availability.h /usr/include/Availability.h
arr.o: /usr/include/AvailabilityInternal.h /usr/include/_types.h
arr.o: /usr/include/sys/_types.h /usr/include/machine/_types.h
arr.o: /usr/include/i386/_types.h /usr/include/sys/_pthread/_pthread_types.h
arr.o: /usr/include/sys/_types/_va_list.h /usr/include/sys/_types/_size_t.h
arr.o: /usr/include/sys/_types/_null.h /usr/include/sys/stdio.h
arr.o: /usr/include/sys/_types/_off_t.h /usr/include/sys/_types/_ssize_t.h
arr.o: /usr/include/secure/_stdio.h /usr/include/secure/_common.h
arr.o: /usr/include/stdlib.h /usr/include/sys/wait.h
arr.o: /usr/include/sys/_types/_pid_t.h /usr/include/sys/_types/_id_t.h
arr.o: /usr/include/sys/signal.h /usr/include/sys/appleapiopts.h
arr.o: /usr/include/machine/signal.h /usr/include/i386/signal.h
arr.o: /usr/include/machine/_mcontext.h /usr/include/i386/_mcontext.h
arr.o: /usr/include/mach/i386/_structs.h
arr.o: /usr/include/sys/_pthread/_pthread_attr_t.h
arr.o: /usr/include/sys/_types/_sigaltstack.h
arr.o: /usr/include/sys/_types/_ucontext.h
arr.o: /usr/include/sys/_types/_sigset_t.h /usr/include/sys/_types/_uid_t.h
arr.o: /usr/include/sys/resource.h /usr/include/stdint.h
arr.o: /usr/include/sys/_types/_int8_t.h /usr/include/sys/_types/_int16_t.h
arr.o: /usr/include/sys/_types/_int32_t.h /usr/include/sys/_types/_int64_t.h
arr.o: /usr/include/_types/_uint8_t.h /usr/include/_types/_uint16_t.h
arr.o: /usr/include/_types/_uint32_t.h /usr/include/_types/_uint64_t.h
arr.o: /usr/include/sys/_types/_intptr_t.h
arr.o: /usr/include/sys/_types/_uintptr_t.h /usr/include/_types/_intmax_t.h
arr.o: /usr/include/_types/_uintmax_t.h /usr/include/sys/_types/_timeval.h
arr.o: /usr/include/machine/endian.h /usr/include/i386/endian.h
arr.o: /usr/include/sys/_endian.h /usr/include/libkern/_OSByteOrder.h
arr.o: /usr/include/libkern/i386/_OSByteOrder.h /usr/include/alloca.h
arr.o: /usr/include/sys/_types/_ct_rune_t.h /usr/include/sys/_types/_rune_t.h
arr.o: /usr/include/sys/_types/_wchar_t.h /usr/include/machine/types.h
arr.o: /usr/include/i386/types.h /usr/include/sys/_types/_u_int8_t.h
arr.o: /usr/include/sys/_types/_u_int16_t.h
arr.o: /usr/include/sys/_types/_u_int32_t.h
arr.o: /usr/include/sys/_types/_u_int64_t.h /usr/include/sys/_types/_dev_t.h
arr.o: /usr/include/sys/_types/_mode_t.h /usr/include/string.h
arr.o: /usr/include/sys/_types/_rsize_t.h /usr/include/sys/_types/_errno_t.h
arr.o: /usr/include/strings.h /usr/include/secure/_string.h
crules.o: pio.h /usr/include/ctype.h /usr/include/sys/cdefs.h
crules.o: /usr/include/sys/_symbol_aliasing.h
crules.o: /usr/include/sys/_posix_availability.h /usr/include/runetype.h
crules.o: /usr/include/_types.h /usr/include/sys/_types.h
crules.o: /usr/include/machine/_types.h /usr/include/i386/_types.h
crules.o: /usr/include/sys/_pthread/_pthread_types.h
crules.o: /usr/include/sys/_types/_size_t.h
crules.o: /usr/include/sys/_types/_ct_rune_t.h
crules.o: /usr/include/sys/_types/_rune_t.h
crules.o: /usr/include/sys/_types/_wchar_t.h
crules.o: /usr/include/sys/_types/_wint_t.h /usr/include/unistd.h
crules.o: /usr/include/sys/unistd.h /usr/include/sys/_types/_posix_vdisable.h
crules.o: /usr/include/sys/_types/_seek_set.h /usr/include/_types/_uint64_t.h
crules.o: /usr/include/Availability.h /usr/include/AvailabilityInternal.h
crules.o: /usr/include/sys/_types/_ssize_t.h /usr/include/sys/_types/_uid_t.h
crules.o: /usr/include/sys/_types/_gid_t.h
crules.o: /usr/include/sys/_types/_intptr_t.h
crules.o: /usr/include/sys/_types/_off_t.h /usr/include/sys/_types/_pid_t.h
crules.o: /usr/include/sys/_types/_useconds_t.h
crules.o: /usr/include/sys/_types/_null.h /usr/include/sys/select.h
crules.o: /usr/include/sys/appleapiopts.h /usr/include/sys/_types/_fd_def.h
crules.o: /usr/include/sys/_types/_timespec.h
crules.o: /usr/include/sys/_types/_timeval.h
crules.o: /usr/include/sys/_types/_time_t.h
crules.o: /usr/include/sys/_types/_suseconds_t.h
crules.o: /usr/include/sys/_types/_sigset_t.h
crules.o: /usr/include/sys/_types/_fd_setsize.h
crules.o: /usr/include/sys/_types/_fd_set.h /usr/include/sys/_types/_fd_clr.h
crules.o: /usr/include/sys/_types/_fd_isset.h
crules.o: /usr/include/sys/_types/_fd_zero.h
crules.o: /usr/include/sys/_types/_fd_copy.h /usr/include/sys/_select.h
crules.o: /usr/include/sys/_types/_dev_t.h /usr/include/sys/_types/_mode_t.h
crules.o: /usr/include/sys/_types/_uuid_t.h /usr/include/gethostuuid.h
crules.o: /usr/include/stdlib.h /usr/include/sys/wait.h
crules.o: /usr/include/sys/_types/_id_t.h /usr/include/sys/signal.h
crules.o: /usr/include/machine/signal.h /usr/include/i386/signal.h
crules.o: /usr/include/machine/_mcontext.h /usr/include/i386/_mcontext.h
crules.o: /usr/include/mach/i386/_structs.h
crules.o: /usr/include/sys/_pthread/_pthread_attr_t.h
crules.o: /usr/include/sys/_types/_sigaltstack.h
crules.o: /usr/include/sys/_types/_ucontext.h /usr/include/sys/resource.h
crules.o: /usr/include/stdint.h /usr/include/sys/_types/_int8_t.h
crules.o: /usr/include/sys/_types/_int16_t.h
crules.o: /usr/include/sys/_types/_int32_t.h
crules.o: /usr/include/sys/_types/_int64_t.h /usr/include/_types/_uint8_t.h
crules.o: /usr/include/_types/_uint16_t.h /usr/include/_types/_uint32_t.h
crules.o: /usr/include/sys/_types/_uintptr_t.h
crules.o: /usr/include/_types/_intmax_t.h /usr/include/_types/_uintmax_t.h
crules.o: /usr/include/machine/endian.h /usr/include/i386/endian.h
crules.o: /usr/include/sys/_endian.h /usr/include/libkern/_OSByteOrder.h
crules.o: /usr/include/libkern/i386/_OSByteOrder.h /usr/include/alloca.h
crules.o: /usr/include/machine/types.h /usr/include/i386/types.h
crules.o: /usr/include/sys/_types/_u_int8_t.h
crules.o: /usr/include/sys/_types/_u_int16_t.h
crules.o: /usr/include/sys/_types/_u_int32_t.h
crules.o: /usr/include/sys/_types/_u_int64_t.h /usr/include/stdio.h
crules.o: /usr/include/sys/_types/_va_list.h /usr/include/sys/stdio.h
crules.o: /usr/include/secure/_stdio.h /usr/include/secure/_common.h
crules.o: /usr/include/strings.h /usr/include/string.h
crules.o: /usr/include/sys/_types/_rsize_t.h
crules.o: /usr/include/sys/_types/_errno_t.h /usr/include/secure/_string.h
crules.o: arr.h
pio.o: /usr/include/ctype.h /usr/include/sys/cdefs.h
pio.o: /usr/include/sys/_symbol_aliasing.h
pio.o: /usr/include/sys/_posix_availability.h /usr/include/runetype.h
pio.o: /usr/include/_types.h /usr/include/sys/_types.h
pio.o: /usr/include/machine/_types.h /usr/include/i386/_types.h
pio.o: /usr/include/sys/_pthread/_pthread_types.h
pio.o: /usr/include/sys/_types/_size_t.h /usr/include/sys/_types/_ct_rune_t.h
pio.o: /usr/include/sys/_types/_rune_t.h /usr/include/sys/_types/_wchar_t.h
pio.o: /usr/include/sys/_types/_wint_t.h /usr/include/unistd.h
pio.o: /usr/include/sys/unistd.h /usr/include/sys/_types/_posix_vdisable.h
pio.o: /usr/include/sys/_types/_seek_set.h /usr/include/_types/_uint64_t.h
pio.o: /usr/include/Availability.h /usr/include/AvailabilityInternal.h
pio.o: /usr/include/sys/_types/_ssize_t.h /usr/include/sys/_types/_uid_t.h
pio.o: /usr/include/sys/_types/_gid_t.h /usr/include/sys/_types/_intptr_t.h
pio.o: /usr/include/sys/_types/_off_t.h /usr/include/sys/_types/_pid_t.h
pio.o: /usr/include/sys/_types/_useconds_t.h /usr/include/sys/_types/_null.h
pio.o: /usr/include/sys/select.h /usr/include/sys/appleapiopts.h
pio.o: /usr/include/sys/_types/_fd_def.h /usr/include/sys/_types/_timespec.h
pio.o: /usr/include/sys/_types/_timeval.h /usr/include/sys/_types/_time_t.h
pio.o: /usr/include/sys/_types/_suseconds_t.h
pio.o: /usr/include/sys/_types/_sigset_t.h
pio.o: /usr/include/sys/_types/_fd_setsize.h
pio.o: /usr/include/sys/_types/_fd_set.h /usr/include/sys/_types/_fd_clr.h
pio.o: /usr/include/sys/_types/_fd_isset.h /usr/include/sys/_types/_fd_zero.h
pio.o: /usr/include/sys/_types/_fd_copy.h /usr/include/sys/_select.h
pio.o: /usr/include/sys/_types/_dev_t.h /usr/include/sys/_types/_mode_t.h
pio.o: /usr/include/sys/_types/_uuid_t.h /usr/include/gethostuuid.h
pio.o: /usr/include/stdlib.h /usr/include/sys/wait.h
pio.o: /usr/include/sys/_types/_id_t.h /usr/include/sys/signal.h
pio.o: /usr/include/machine/signal.h /usr/include/i386/signal.h
pio.o: /usr/include/machine/_mcontext.h /usr/include/i386/_mcontext.h
pio.o: /usr/include/mach/i386/_structs.h
pio.o: /usr/include/sys/_pthread/_pthread_attr_t.h
pio.o: /usr/include/sys/_types/_sigaltstack.h
pio.o: /usr/include/sys/_types/_ucontext.h /usr/include/sys/resource.h
pio.o: /usr/include/stdint.h /usr/include/sys/_types/_int8_t.h
pio.o: /usr/include/sys/_types/_int16_t.h /usr/include/sys/_types/_int32_t.h
pio.o: /usr/include/sys/_types/_int64_t.h /usr/include/_types/_uint8_t.h
pio.o: /usr/include/_types/_uint16_t.h /usr/include/_types/_uint32_t.h
pio.o: /usr/include/sys/_types/_uintptr_t.h /usr/include/_types/_intmax_t.h
pio.o: /usr/include/_types/_uintmax_t.h /usr/include/machine/endian.h
pio.o: /usr/include/i386/endian.h /usr/include/sys/_endian.h
pio.o: /usr/include/libkern/_OSByteOrder.h
pio.o: /usr/include/libkern/i386/_OSByteOrder.h /usr/include/alloca.h
pio.o: /usr/include/machine/types.h /usr/include/i386/types.h
pio.o: /usr/include/sys/_types/_u_int8_t.h
pio.o: /usr/include/sys/_types/_u_int16_t.h
pio.o: /usr/include/sys/_types/_u_int32_t.h
pio.o: /usr/include/sys/_types/_u_int64_t.h /usr/include/stdio.h
pio.o: /usr/include/sys/_types/_va_list.h /usr/include/sys/stdio.h
pio.o: /usr/include/secure/_stdio.h /usr/include/secure/_common.h
pio.o: /usr/include/strings.h /usr/include/string.h
pio.o: /usr/include/sys/_types/_rsize_t.h /usr/include/sys/_types/_errno_t.h
pio.o: /usr/include/secure/_string.h
pprog.o: crules.h pio.h /usr/include/ctype.h /usr/include/sys/cdefs.h
pprog.o: /usr/include/sys/_symbol_aliasing.h
pprog.o: /usr/include/sys/_posix_availability.h /usr/include/runetype.h
pprog.o: /usr/include/_types.h /usr/include/sys/_types.h
pprog.o: /usr/include/machine/_types.h /usr/include/i386/_types.h
pprog.o: /usr/include/sys/_pthread/_pthread_types.h
pprog.o: /usr/include/sys/_types/_size_t.h
pprog.o: /usr/include/sys/_types/_ct_rune_t.h
pprog.o: /usr/include/sys/_types/_rune_t.h /usr/include/sys/_types/_wchar_t.h
pprog.o: /usr/include/sys/_types/_wint_t.h /usr/include/unistd.h
pprog.o: /usr/include/sys/unistd.h /usr/include/sys/_types/_posix_vdisable.h
pprog.o: /usr/include/sys/_types/_seek_set.h /usr/include/_types/_uint64_t.h
pprog.o: /usr/include/Availability.h /usr/include/AvailabilityInternal.h
pprog.o: /usr/include/sys/_types/_ssize_t.h /usr/include/sys/_types/_uid_t.h
pprog.o: /usr/include/sys/_types/_gid_t.h /usr/include/sys/_types/_intptr_t.h
pprog.o: /usr/include/sys/_types/_off_t.h /usr/include/sys/_types/_pid_t.h
pprog.o: /usr/include/sys/_types/_useconds_t.h
pprog.o: /usr/include/sys/_types/_null.h /usr/include/sys/select.h
pprog.o: /usr/include/sys/appleapiopts.h /usr/include/sys/_types/_fd_def.h
pprog.o: /usr/include/sys/_types/_timespec.h
pprog.o: /usr/include/sys/_types/_timeval.h /usr/include/sys/_types/_time_t.h
pprog.o: /usr/include/sys/_types/_suseconds_t.h
pprog.o: /usr/include/sys/_types/_sigset_t.h
pprog.o: /usr/include/sys/_types/_fd_setsize.h
pprog.o: /usr/include/sys/_types/_fd_set.h /usr/include/sys/_types/_fd_clr.h
pprog.o: /usr/include/sys/_types/_fd_isset.h
pprog.o: /usr/include/sys/_types/_fd_zero.h
pprog.o: /usr/include/sys/_types/_fd_copy.h /usr/include/sys/_select.h
pprog.o: /usr/include/sys/_types/_dev_t.h /usr/include/sys/_types/_mode_t.h
pprog.o: /usr/include/sys/_types/_uuid_t.h /usr/include/gethostuuid.h
pprog.o: /usr/include/stdlib.h /usr/include/sys/wait.h
pprog.o: /usr/include/sys/_types/_id_t.h /usr/include/sys/signal.h
pprog.o: /usr/include/machine/signal.h /usr/include/i386/signal.h
pprog.o: /usr/include/machine/_mcontext.h /usr/include/i386/_mcontext.h
pprog.o: /usr/include/mach/i386/_structs.h
pprog.o: /usr/include/sys/_pthread/_pthread_attr_t.h
pprog.o: /usr/include/sys/_types/_sigaltstack.h
pprog.o: /usr/include/sys/_types/_ucontext.h /usr/include/sys/resource.h
pprog.o: /usr/include/stdint.h /usr/include/sys/_types/_int8_t.h
pprog.o: /usr/include/sys/_types/_int16_t.h
pprog.o: /usr/include/sys/_types/_int32_t.h
pprog.o: /usr/include/sys/_types/_int64_t.h /usr/include/_types/_uint8_t.h
pprog.o: /usr/include/_types/_uint16_t.h /usr/include/_types/_uint32_t.h
pprog.o: /usr/include/sys/_types/_uintptr_t.h /usr/include/_types/_intmax_t.h
pprog.o: /usr/include/_types/_uintmax_t.h /usr/include/machine/endian.h
pprog.o: /usr/include/i386/endian.h /usr/include/sys/_endian.h
pprog.o: /usr/include/libkern/_OSByteOrder.h
pprog.o: /usr/include/libkern/i386/_OSByteOrder.h /usr/include/alloca.h
pprog.o: /usr/include/machine/types.h /usr/include/i386/types.h
pprog.o: /usr/include/sys/_types/_u_int8_t.h
pprog.o: /usr/include/sys/_types/_u_int16_t.h
pprog.o: /usr/include/sys/_types/_u_int32_t.h
pprog.o: /usr/include/sys/_types/_u_int64_t.h /usr/include/stdio.h
pprog.o: /usr/include/sys/_types/_va_list.h /usr/include/sys/stdio.h
pprog.o: /usr/include/secure/_stdio.h /usr/include/secure/_common.h
pprog.o: /usr/include/strings.h /usr/include/string.h
pprog.o: /usr/include/sys/_types/_rsize_t.h
pprog.o: /usr/include/sys/_types/_errno_t.h /usr/include/secure/_string.h
pprog.o: arr.h
prog.o: crules.h pio.h /usr/include/ctype.h /usr/include/sys/cdefs.h
prog.o: /usr/include/sys/_symbol_aliasing.h
prog.o: /usr/include/sys/_posix_availability.h /usr/include/runetype.h
prog.o: /usr/include/_types.h /usr/include/sys/_types.h
prog.o: /usr/include/machine/_types.h /usr/include/i386/_types.h
prog.o: /usr/include/sys/_pthread/_pthread_types.h
prog.o: /usr/include/sys/_types/_size_t.h
prog.o: /usr/include/sys/_types/_ct_rune_t.h
prog.o: /usr/include/sys/_types/_rune_t.h /usr/include/sys/_types/_wchar_t.h
prog.o: /usr/include/sys/_types/_wint_t.h /usr/include/unistd.h
prog.o: /usr/include/sys/unistd.h /usr/include/sys/_types/_posix_vdisable.h
prog.o: /usr/include/sys/_types/_seek_set.h /usr/include/_types/_uint64_t.h
prog.o: /usr/include/Availability.h /usr/include/AvailabilityInternal.h
prog.o: /usr/include/sys/_types/_ssize_t.h /usr/include/sys/_types/_uid_t.h
prog.o: /usr/include/sys/_types/_gid_t.h /usr/include/sys/_types/_intptr_t.h
prog.o: /usr/include/sys/_types/_off_t.h /usr/include/sys/_types/_pid_t.h
prog.o: /usr/include/sys/_types/_useconds_t.h /usr/include/sys/_types/_null.h
prog.o: /usr/include/sys/select.h /usr/include/sys/appleapiopts.h
prog.o: /usr/include/sys/_types/_fd_def.h /usr/include/sys/_types/_timespec.h
prog.o: /usr/include/sys/_types/_timeval.h /usr/include/sys/_types/_time_t.h
prog.o: /usr/include/sys/_types/_suseconds_t.h
prog.o: /usr/include/sys/_types/_sigset_t.h
prog.o: /usr/include/sys/_types/_fd_setsize.h
prog.o: /usr/include/sys/_types/_fd_set.h /usr/include/sys/_types/_fd_clr.h
prog.o: /usr/include/sys/_types/_fd_isset.h
prog.o: /usr/include/sys/_types/_fd_zero.h /usr/include/sys/_types/_fd_copy.h
prog.o: /usr/include/sys/_select.h /usr/include/sys/_types/_dev_t.h
prog.o: /usr/include/sys/_types/_mode_t.h /usr/include/sys/_types/_uuid_t.h
prog.o: /usr/include/gethostuuid.h /usr/include/stdlib.h
prog.o: /usr/include/sys/wait.h /usr/include/sys/_types/_id_t.h
prog.o: /usr/include/sys/signal.h /usr/include/machine/signal.h
prog.o: /usr/include/i386/signal.h /usr/include/machine/_mcontext.h
prog.o: /usr/include/i386/_mcontext.h /usr/include/mach/i386/_structs.h
prog.o: /usr/include/sys/_pthread/_pthread_attr_t.h
prog.o: /usr/include/sys/_types/_sigaltstack.h
prog.o: /usr/include/sys/_types/_ucontext.h /usr/include/sys/resource.h
prog.o: /usr/include/stdint.h /usr/include/sys/_types/_int8_t.h
prog.o: /usr/include/sys/_types/_int16_t.h /usr/include/sys/_types/_int32_t.h
prog.o: /usr/include/sys/_types/_int64_t.h /usr/include/_types/_uint8_t.h
prog.o: /usr/include/_types/_uint16_t.h /usr/include/_types/_uint32_t.h
prog.o: /usr/include/sys/_types/_uintptr_t.h /usr/include/_types/_intmax_t.h
prog.o: /usr/include/_types/_uintmax_t.h /usr/include/machine/endian.h
prog.o: /usr/include/i386/endian.h /usr/include/sys/_endian.h
prog.o: /usr/include/libkern/_OSByteOrder.h
prog.o: /usr/include/libkern/i386/_OSByteOrder.h /usr/include/alloca.h
prog.o: /usr/include/machine/types.h /usr/include/i386/types.h
prog.o: /usr/include/sys/_types/_u_int8_t.h
prog.o: /usr/include/sys/_types/_u_int16_t.h
prog.o: /usr/include/sys/_types/_u_int32_t.h
prog.o: /usr/include/sys/_types/_u_int64_t.h /usr/include/stdio.h
prog.o: /usr/include/sys/_types/_va_list.h /usr/include/sys/stdio.h
prog.o: /usr/include/secure/_stdio.h /usr/include/secure/_common.h
prog.o: /usr/include/strings.h /usr/include/string.h
prog.o: /usr/include/sys/_types/_rsize_t.h /usr/include/sys/_types/_errno_t.h
prog.o: /usr/include/secure/_string.h arr.h
