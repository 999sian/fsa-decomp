.include "macros.inc"
# MetroTRK monitor-call traps, adapted from zeldaret/tww (CC0); see NOTICE.

.text
.balign 16

.fn TRKAccessFile, global
	twi 31, r0, 0
	blr
.endfn TRKAccessFile

.fn TRKOpenFile, global
	twi 31, r0, 0
	blr
.endfn TRKOpenFile

.fn TRKCloseFile, global
	twi 31, r0, 0
	blr
.endfn TRKCloseFile

.fn TRKPositionFile, global
	twi 31, r0, 0
	blr
.endfn TRKPositionFile

